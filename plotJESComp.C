void plotJESComp(){
  gStyle->SetOptStat(0); 
  gStyle->SetOptTitle(0); 
  TFile *_file0 = TFile::Open("resultsAB.root");
  TFile *_file1 = TFile::Open("predicitonResults_NN_Mar12th.root");

  TString histname = "h2_resid_hybrid_det_v_det"; 
  
  TH2D* ab = (TH2D*)_file0->Get(histname);
  ab->SetName("ab");
  TH2D* nn = (TH2D*)_file1->Get(histname);
  nn->SetName("nn");
  TH1D* ab_JER =ab->ProjectionX("ab_JER");
  ab_JER->Reset();

  Int_t nBinsAB = ab->GetXaxis()->GetNbins();
  for(Int_t i=1; i <= nBinsAB ; i++){
    TString proj = Form("px_%d", i);
    TH1D* ab_px = ab->ProjectionY(proj, i, i);                     
    ab_JER->SetBinContent(i,  ab_px->GetStdDev());
    ab_JER->SetBinError(i,  ab_px->GetStdDevError());
  }

  TH1D* nn_JER =nn->ProjectionX("nn_JER");
  nn_JER->Reset();

  Int_t nBinsNN = nn->GetXaxis()->GetNbins();
  for(Int_t i=1; i <= nBinsNN ; i++){
    TString proj = Form("px_%d", i);
    TH1D* nn_px = nn->ProjectionY(proj, i, i);
    nn_JER->SetBinContent(i,  nn_px->GetStdDev());
    nn_JER->SetBinError(i,  nn_px->GetStdDevError());
  }

  ab_JER->SetMarkerStyle(20); 
  ab_JER->GetXaxis()->SetTitle("p_{T, det} [GeV/#it{c}]");
  ab_JER->GetYaxis()->SetTitle("Det JER");
  ab_JER->Draw();
  nn_JER->SetMarkerStyle(20);
  nn_JER->SetMarkerColor(kRed);
  nn_JER->Draw("same");
  

  /*
  TProfile* ab_px = ab->ProfileX("ab_px");
  TProfile* nn_px = nn->ProfileX("nn_px");
  ab_px->SetMarkerStyle(20);
  nn_px->GetXaxis()->SetTitle("p_{T, det} [GeV/#it{c}]");                                                                         
  nn_px->GetYaxis()->SetTitle("Det JES"); 
  nn_px->SetMarkerStyle(20);
  nn_px->SetMarkerColor(kRed);

  nn_px->Draw();
  ab_px->Draw("same");
  */
}
