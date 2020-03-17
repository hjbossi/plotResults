/* 
 * plotJESComp.C: Plots jet performance comparison and just the jet performance.
 * Hannah Bossi <hannah.bossi@yale.edu>
 * 3/17/2020
 */

void plotJESComp(){
  // style settings
  gStyle->SetOptStat(0); 
  gStyle->SetOptTitle(0);
  // macro settings
  /* We essentially have four  plots we want to make
   * (1) JES
   * (2) JER
   * (3) Detector-Level JES
   * (4) Detector-Level JER
   */
  Bool_t doMLMethods = kTRUE; 
  Bool_t doJES = kFALSE; 
  Bool_t doPartLevel = kFALSE;

   // Get the files
  TFile *_file0 = TFile::Open("mLJetPerfResults_021420_R040_Mar16th_Central.root");
  TFile *_file1;
  TFile *_file2; 
  TFile *_file3;
  if(doMLMethods){
    _file1 = TFile::Open("predicitonResults_NN_Mar17th.root");
    _file2 = TFile::Open("predicitonResults_RF_Mar17th.root");
    _file3 = TFile::Open("predicitonResults_LR_Mar17th.root");
  }
  // Select what histogram to plot
  TString histname; 
  if(doPartLevel){
    histname = "h2_resid_hybrid_part_v_part";
  }
  else{
    histname = "h2_resid_hybrid_det_v_det";   
  }
  
  // get histogram
  TH2D* ab = (TH2D*)_file0->Get(histname);
  ab->SetName("ab");
  TH2D* nn;
  TH2D* rf; 
  TH2D* lr; 
  if(doMLMethods){
    nn = (TH2D*)_file1->Get(histname);
    nn->SetName("nn");
    rf = (TH2D*)_file2->Get(histname);
    rf->SetName("rf");
    lr = (TH2D*)_file3->Get(histname);
    lr->SetName("lr");
  }
  // ================================ JER =============================================
  
  if(!doJES){
    TH1D* ab_JER = ab->ProjectionX("ab_JER");
    ab_JER->Reset();

    Int_t nBinsAB = ab->GetXaxis()->GetNbins();
    for(Int_t i=1; i <= nBinsAB ; i++){
      TString proj = Form("px_%d", i);
      TH1D* ab_px = ab->ProjectionY(proj, i, i);                     
      ab_JER->SetBinContent(i,  ab_px->GetStdDev());
      ab_JER->SetBinError(i,  ab_px->GetStdDevError());
    }
    TH1D* nn_JER;
    TH1D* rf_JER;
    TH1D* lr_JER;
    if(doMLMethods){
      nn_JER = nn->ProjectionX("nn_JER");
      nn_JER->Reset();
      rf_JER = rf->ProjectionX("rf_JER");
      rf_JER->Reset();
      lr_JER = lr->ProjectionX("lr_JER");
      lr_JER->Reset();
      Int_t nBinsNN = nn->GetXaxis()->GetNbins();
      for(Int_t i=1; i <= nBinsNN ; i++){
	TString proj = Form("px_%d", i);
	TString projRF = Form("pxRF_%d", i);
	TString projLR = Form("pxLR_%d", i);
	TH1D* nn_px = nn->ProjectionY(proj, i, i);
	TH1D* rf_px = rf->ProjectionY(projRF, i, i);
	TH1D* lr_px = lr->ProjectionY(projLR, i, i);
	nn_JER->SetBinContent(i,  nn_px->GetStdDev());
	nn_JER->SetBinError(i,  nn_px->GetStdDevError());
	rf_JER->SetBinContent(i,  rf_px->GetStdDev());
        rf_JER->SetBinError(i,  rf_px->GetStdDevError());
	lr_JER->SetBinContent(i,  lr_px->GetStdDev());
        lr_JER->SetBinError(i,  lr_px->GetStdDevError());
      }
    }
    ab_JER->SetMarkerStyle(20); 
    ab_JER->SetMarkerColor(kRed);
    ab_JER->SetLineColor(kRed);
    if(!doPartLevel){
      ab_JER->GetXaxis()->SetTitle("p_{T, det} [GeV/#it{c}]");
      ab_JER->GetYaxis()->SetTitle("Detector Level JER");
    }
    else{
      ab_JER->GetXaxis()->SetTitle("p_{T, part} [GeV/#it{c}]");
      ab_JER->GetYaxis()->SetTitle("JER"); 
    }
    ab_JER->GetYaxis()->SetRangeUser(0,2.5);
    ab_JER->Draw();
    if(doMLMethods){
      nn_JER->SetMarkerStyle(20);
      nn_JER->SetLineColor(kBlack);
      nn_JER->SetMarkerColor(kBlack);
      nn_JER->Draw("same");
      rf_JER->SetMarkerStyle(20);
      rf_JER->SetLineColor(kGreen+2);
      rf_JER->SetMarkerColor(kGreen+2);
      rf_JER->Draw("same");
      lr_JER->SetMarkerStyle(20);
      lr_JER->SetLineColor(kAzure-2);
      lr_JER->SetMarkerColor(kAzure-2);
      lr_JER->Draw("same");
    }
  }

  if(doJES){
    TProfile* ab_px = ab->ProfileX("ab_px");
    TProfile* nn_px;
    TProfile* rf_px;
    TProfile* lr_px;
    if(doMLMethods){
      nn_px = nn->ProfileX("nn_px");
      rf_px = rf->ProfileX("rf_px");
      lr_px = lr->ProfileX("lr_px");
    }
    ab_px->SetMarkerStyle(20);
    ab_px->SetMarkerColor(kRed);
    ab_px->SetLineColor(kRed);
    if(doPartLevel){
      ab_px->GetXaxis()->SetTitle("p_{T, part} [GeV/#it{c}]");
      ab_px->GetYaxis()->SetTitle("JES");
    }
    if(!doPartLevel){
      ab_px->GetXaxis()->SetTitle("p_{T, det} [GeV/#it{c}]");
      ab_px->GetYaxis()->SetTitle("Detector Level JES");
    }
    ab_px->GetYaxis()->SetRangeUser(-0.7,0.5);
    ab_px->Draw();
    if(doMLMethods && !doPartLevel)nn_px->GetXaxis()->SetTitle("p_{T, det} [GeV/#it{c}]");
    if(doMLMethods && doPartLevel)nn_px->GetXaxis()->SetTitle("p_{T, part} [GeV/#it{c}]");
    if(doMLMethods){ 
      nn_px->SetMarkerStyle(20);
      nn_px->SetMarkerColor(kBlack);
      nn_px->SetLineColor(kBlack);
      nn_px->Draw("same");
      rf_px->SetMarkerStyle(20);
      rf_px->SetLineColor(kGreen+2);
      rf_px->SetMarkerColor(kGreen+2);
      rf_px->Draw("same");
      lr_px->SetMarkerStyle(20);
      lr_px->SetLineColor(kAzure-2);
      lr_px->SetMarkerColor(kAzure-2);
      lr_px->Draw("same");
    }
  }
}
