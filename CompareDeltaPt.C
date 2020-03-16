void CompareDeltaPt(){
  gStyle->SetOptStat(0);
  gStyle->SetOptTitle(0);
  TFile *_file0    = TFile::Open("mLJetPerfResults_train5405.root");
  TFile *_file1    = TFile::Open("mLJetPerfResults_train5406.root");
  TFile *_file2    = TFile::Open("mLJetPerfResults_train5407.root");
  TFile *_file3    = TFile::Open("mLJetPerfResults_train5408.root");
  TFile *_file4    = TFile::Open("mLJetPerfResults_train5409.root");
  TFile *_file5    = TFile::Open("mLJetPerfResults_train5415.root");
  TFile *_file6    = TFile::Open("mLJetPerfResults_train5416.root");
  TFile *_file7    = TFile::Open("mLJetPerfResults_train5442.root");
  TFile *trainRef  = TFile::Open("mLJetPerfResults_trainRef.root");
  TFile *trainRef2 = TFile::Open("mLJetPerfResults_trainRefFirst.root");
  TFile *james     = TFile::Open("~/alidock/data/JamesEmbedding/TrainOutput/mLJetPerfResults_011320_UnscaledExtractionHists_8.root");
  
  // get the mlresidual plot hists
  TH2D* train5405_2D = (TH2D*)_file0->Get("mLResidualPlot");
  TH2D* train5406_2D = (TH2D*)_file1->Get("mLResidualPlot");
  TH2D* train5407_2D = (TH2D*)_file2->Get("mLResidualPlot");
  TH2D* train5408_2D = (TH2D*)_file3->Get("mLResidualPlot");
  TH2D* train5409_2D = (TH2D*)_file4->Get("mLResidualPlot");
  TH2D* train5415_2D = (TH2D*)_file5->Get("mLResidualPlot");
  TH2D* train5416_2D = (TH2D*)_file6->Get("mLResidualPlot");
  TH2D* train5442_2D = (TH2D*)_file7->Get("mLResidualPlot");
  TH2D* refHist_2D   = (TH2D*)trainRef->Get("mLResidualPlot");
  TH2D* refHist2_2D  = (TH2D*)trainRef2->Get("mLResidualPlot");
  //TH2D* jamesRef_2D  = (TH2D*)james->Get("rhoCent");

  train5405_2D->SetName("train5405_2D");
  train5406_2D->SetName("train5406_2D");
  train5407_2D->SetName("train5407_2D");
  train5408_2D->SetName("train5408_2D");
  train5409_2D->SetName("train5409_2D");
  train5415_2D->SetName("train5415_2D");
  train5416_2D->SetName("train5416_2D");
  train5442_2D->SetName("train5442_2D");
  refHist_2D->SetName("refHist_2D");
  refHist2_2D->SetName("refHist2_2D");
  //jamesRef_2D->SetName("jamesRef_2D");

  // Make the projections
  Int_t binStart = 9;
  Int_t binEnd = 12;
  TH1D* train5405 = train5405_2D->ProjectionX("train5405", binStart, binEnd);
  TH1D* train5406 = train5406_2D->ProjectionX("train5406", binStart, binEnd);
  TH1D* train5407 = train5407_2D->ProjectionX("train5407", binStart, binEnd);
  TH1D* train5408 = train5408_2D->ProjectionX("train5408", binStart, binEnd);
  TH1D* train5409 = train5409_2D->ProjectionX("train5409", binStart, binEnd);
  TH1D* train5415 = train5415_2D->ProjectionX("train5415", binStart, binEnd);
  TH1D* train5416 = train5416_2D->ProjectionX("train5416", binStart, binEnd);
  TH1D* train5442 = train5442_2D->ProjectionX("train5442", binStart, binEnd);
  TH1D* refHist   = refHist_2D->ProjectionX("refHist", binStart, binEnd);
  TH1D* refHist2  = refHist2_2D->ProjectionX("refHist2", binStart, binEnd);
  //TH1D* jamesRef  = jamesRef_2D->ProjectionX("jamesRef", binStart, binEnd);
  

  train5405->SetMarkerColor(kBlue);
  train5405->SetLineColor(kBlue);
  train5405->SetMarkerStyle(33);

  train5406->SetMarkerColor(kRed);
  train5406->SetLineColor(kRed);
  train5406->SetMarkerStyle(20);

  train5407->SetMarkerColor(kGreen);
  train5407->SetLineColor(kGreen);
  train5407->SetMarkerStyle(20);

  train5408->SetMarkerColor(kCyan);
  train5408->SetLineColor(kCyan);
  train5408->SetMarkerStyle(33);

  train5409->SetMarkerColor(kOrange);
  train5409->SetLineColor(kOrange);
  train5409->SetMarkerStyle(20);

  train5415->SetMarkerColor(kViolet);
  train5415->SetLineColor(kViolet);
  train5415->SetMarkerStyle(20);

  train5416->SetMarkerColor(kMagenta);
  train5416->SetLineColor(kMagenta);
  train5416->SetMarkerStyle(20);

  train5442->SetMarkerColor(kTeal+3);
  train5442->SetLineColor(kTeal+3);
  train5442->SetMarkerStyle(20);
  
  refHist->SetMarkerColor(kBlack);
  refHist->SetLineColor(kBlack);
  refHist->SetMarkerStyle(20);

  refHist2->SetMarkerColor(kGray);
  refHist2->SetLineColor(kGray);
  refHist2->SetMarkerStyle(33);

  /*
  jamesRef->SetMarkerColor(kOrange+7);
  jamesRef->SetLineColor(kOrange+7);
  jamesRef->SetMarkerStyle(28);
  */

  
  train5405->Rebin(2);
  train5406->Rebin(2);
  train5407->Rebin(2);
  train5408->Rebin(2);
  train5409->Rebin(2);
  train5415->Rebin(2);
  train5416->Rebin(2);
  train5442->Rebin(2); 
  refHist->Rebin(2);
  refHist2->Rebin(2);
  

  train5405->Scale(1./train5405->Integral());
  train5406->Scale(1./train5406->Integral());
  train5407->Scale(1./train5407->Integral());
  train5408->Scale(1./train5408->Integral());
  train5409->Scale(1./train5409->Integral());
  train5415->Scale(1./train5415->Integral());
  train5416->Scale(1./train5416->Integral());
  train5442->Scale(1./train5442->Integral());
  refHist->Scale(1./refHist->Integral());
  refHist2->Scale(1./refHist2->Integral());
  //jamesRef->Scale(1./jamesRef->Integral());

  train5409->GetXaxis()->SetTitle("#delta p_{T} [GeV/#it{c}]");
  //train5405->Draw();	
  //train5406->Draw("same");	
  //train5407->Draw("same");
  //train5408->Draw("same");	
  train5409->Draw("same");	
  //train5415->Draw("same");
  train5416->Draw("same");
  train5442->Draw("same");
  //refHist->Draw("same");
  //  refHist2->Draw("same");
  //jamesRef->Draw("same");

  TLegend* leg = new TLegend(0.45, 0.6, 0.9, 0.9);
  leg->SetTextSize(0.04);
  //leg->AddEntry(train5405, Form("Hybrid Tracks, Excluding 4, #mu = %.2f", train5405->GetMean()));
  //leg->AddEntry(train5406, Form("Background Tracks, Excluding 4, #mu = %.2f", train5406->GetMean()));
  //leg->AddEntry(train5407, Form("Background Tracks, Excluding 3, #mu = %.2f", train5407->GetMean()));
  //leg->AddEntry(train5408, Form("Hybrid Tracks, Excluding 3, #mu = %.2f", train5408->GetMean()));
  leg->AddEntry(train5409, Form("#rho with p_{t} scheme,jets with p_{T} scheme  #mu = %.2f", train5409->GetMean()));
  //leg->AddEntry(train5415, Form("James Replica, Bakground Tracks, Excluding 2, #rho with #it{R} = 0.2, #mu = %.2f", train5415->GetMean()));
  leg->AddEntry(train5416, Form("#rho with E scheme, jets with p_{T} scheme #mu = %.2f", train5416->GetMean()));
  leg->AddEntry(train5442, Form("#rho with E scheme, jets with E scheme, #mu = %.2f", train5442->GetMean()));
  //leg->AddEntry(refHist, Form("Background Tracks, Excluding 2, #rho with #it{R} = 0.2, #mu = %.2f", refHist->GetMean()));
  //leg->AddEntry(refHist2, Form("Hybrid Tracks, Excluding 2, #mu = %.2f", refHist2->GetMean()));
  //leg->AddEntry(jamesRef, Form("James Actual, Background Tracks, Excluding 2, #mu = %.2f", jamesRef->GetMean()));
  leg->Draw("same"); 
}
