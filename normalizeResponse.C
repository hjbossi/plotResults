/* 
======== noramlizeResponse.C =======
Normalizes the response matrix in bins of pT True. 
Note: Assumes standard file pattern of mLJetPerf.C -> May need to edit!!

To Run, in root do: 

.x normalizeResponse.C

September 19th , 2019
Hannah Bossi <hannah.bossi@yale.edu> 
 */

void normalizeResponse()
{
  // ========================================== Hard Coded Parameters =============================================
  TFile* f = new TFile("particleLevelCut_021420.root");
  char* histname = "hybridDetResp";
  Bool_t debugNorm = kFALSE;// if we want to check that the normalization is one.
  
  // gStyle Settings
  gStyle->SetOptStat(0);
  gStyle->SetOptTitle(0);
  gStyle->SetLineWidth(2);
  gStyle->SetCanvasBorderMode(0);
  gStyle->SetPadBottomMargin(0.15);
  gStyle->SetPadLeftMargin(0.15);
  gStyle->SetHistLineWidth(1);
  gStyle->SetPadColor(10);
  gStyle->SetTitleSize(0.045, "xyz");
  gStyle->SetTitleOffset(1.2, "x");
  gStyle->SetTitleOffset(2, "y");

  // create the canvas
  TCanvas* c = new TCanvas("c", "c", 800, 600);
  c->SetTickx();
  c->SetTicky();
  c->SetFillColor(0);

  // ========================================= end configuration ===========================================================

  // Get the response hist
  TH2D* response = (TH2D*)f->Get(histname);
  
  //response->Rebin2D(8);
  if(histname == "hybridDetResp" || histname == "linCorrelationPartLevel") response->Rebin2D();
  
  // normalize the response in terms of pT True (y axis slices)
  Int_t numBinsY = response->GetNbinsY();
  Int_t numBinsX = response->GetNbinsX();

  // ----------------------- General Strategy ----------------------- 
  // loop over the bins in y and get the number of entries in each bin from the projection along X of that bin
  // for that y bin, loop over all the x bins and scale by 1/norm
  for(Int_t i = 1; i < numBinsY+1; i++){
    Double_t numEntriesY = response->ProjectionX(Form("px_%d", i), i,i )->Integral();
    for(Int_t j = 1; j < numBinsX+1; j++){
      Double_t binContent = response->GetBinContent(j,i);
      response->SetBinContent(j, i, (binContent/numEntriesY));
    }
  }

  if(debugNorm){
    // check that the response is normalized properly, print an error message if not.
    for(Int_t k= 1; k < numBinsY+1; k++){
      Double_t probability = response->ProjectionX(Form("px_%d", k), k,k)->Integral();
      std::cout << probability << std::endl;
    }
  }


  // now add axis labels and aesthetics
  // create a case for each type of plot
  if(histname == "linCorrelationPartLevel"){
    response->GetXaxis()->SetTitle("p_{T, hybrid} [GeV/c]");
    response->GetYaxis()->SetTitle("p_{T, part} [GeV/c]");
  }
  else if(histname == "linCorrelation"){
    response->GetXaxis()->SetTitle("p_{T, det} [GeV/c]");
    response->GetYaxis()->SetTitle("p_{T, part} [GeV/c]");
  }
  else if(histname == "hybridDetResp"){
    response->GetXaxis()->SetTitle("p_{T, hybrid} [GeV/c]");
    response->GetYaxis()->SetTitle("p_{T, det} [GeV/c]");
  }
  else{
    std::cout << "Did not recognize histname. No axis labels applied." << std::endl;
  }
  
  // set the range properly
  response->GetXaxis()->SetRangeUser(0,200);
  response->GetYaxis()->SetRangeUser(0,200);

  // draw the response
  response->Draw("colz");
 
  //c->SaveAs("normalizedResponse.pdf");
}
