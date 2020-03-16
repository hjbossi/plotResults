/*
Hannah Bossi <hannah.bossi@yale.edu>
plotScalingRatio.C - Plots ratio of histograms of the same name from two different files. Can either be a 1D or a 2D Hist
9/9/2019
 */


void plotScalingRatio(){
  // ========================== Hard Coded Parameters ========================================
  // Get input files
  TFile *_file0 = TFile::Open("withExtractorCuts.root");
  TFile *_file1 = TFile::Open("withExtractorCutsDiff.root");

  // histogram info
  TString histname = "linCorrelationPartLevel";
  TString histD = "2D";
  // ==========================================================================================

  // create 3 TCanvas's that will later be used for plotting.
  TCanvas* c  = new TCanvas("c", "c", 500, 400); // canvas for first hist
  TCanvas* c1 = new TCanvas("c1", "c1", 500, 400); // canvas for second hist
  TCanvas* c2 = new TCanvas("c2", "c2", 500, 400); // canvas for ratio of hists one and two
  
  if(histD == "1D"){
    TH1D* jamesSpec = (TH1D*) _file0->Get(histname);
    jamesSpec->SetName("jamesSpec");
    c->cd();
    jamesSpec->Draw();

    TH1D* diffSpec = (TH1D*) _file1->Get(histname);
    diffSpec->SetName("diffSpec");
    diffSpec->SetLineColor(kRed);
    diffSpec->SetMarkerColor(kRed);
    // for the case of a 1D histogram we want to overlay these
    diffSpec->Draw("same");
    
    
    TH1D* ratioClone = (TH1D*)jamesSpec->Clone("ratioClone");
    ratioClone->Divide(diffSpec);
    c2->cd();
    ratioClone->Draw();
    
  }
  else if (histD == "2D"){
    TH2D* jamesSpec = (TH2D*) _file0->Get(histname);
    jamesSpec->SetName("jamesSpec");
    c->cd();
    jamesSpec->Draw("colz");

    TH2D* diffSpec = (TH2D*) _file1->Get(histname);
    diffSpec->SetName("diffSpec");
    c1->cd();
    diffSpec->Draw("colz");
    
    TH2D* ratioClone = (TH2D*)jamesSpec->Clone("ratioClone");
    ratioClone->Divide(diffSpec);
    c2->cd();
    ratioClone->Draw("COLZ");
  }
  else{
    std::cout << "Error: Dimensionality of the histogram not recognized." << std::endl; 
  }

  // update all of the canvases
  c->Update();
  c1->Update();
  c2->Update();
  
}
