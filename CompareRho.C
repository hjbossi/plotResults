void CompareRho(){
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
  
  // get the rho scaled hists
  TH1D* train5405 = (TH1D*)_file0->Get("event_bkg");
  TH1D* train5406 = (TH1D*)_file1->Get("event_bkg");
  TH1D* train5407 = (TH1D*)_file2->Get("event_bkg");
  TH1D* train5408 = (TH1D*)_file3->Get("event_bkg");
  TH1D* train5409 = (TH1D*)_file4->Get("event_bkg");
  TH1D* train5415 = (TH1D*)_file5->Get("event_bkg");
  TH1D* train5416 = (TH1D*)_file6->Get("event_bkg");
  TH1D* train5442 = (TH1D*)_file7->Get("event_bkg");
  TH1D* refHist   = (TH1D*)trainRef->Get("event_bkg");
  TH1D* refHist2  = (TH1D*)trainRef2->Get("event_bkg");
  TH1D* jamesRef  = (TH1D*)james->Get("rhoCent");

  train5405->SetName("train5405");
  train5406->SetName("train5406");
  train5407->SetName("train5407");
  train5408->SetName("train5408");
  train5409->SetName("train5409");
  train5415->SetName("train5415");
  train5416->SetName("train5416");
  train5442->SetName("train5442");
  refHist->SetName("refHist");
  refHist2->SetName("refHist2");
  jamesRef->SetName("jamesRef");

  int colors[20] = {kRed+2, kRed-4, kOrange+7, kOrange, kYellow-4, kSpring+10, kSpring, kGreen-3, kGreen+3, kTeal-7, kTeal, kAzure+10, kAzure-4, kBlue+2, kViolet+8, kViolet-1, kMagenta+1, kMagenta-4, kPink+7, kPink-4};
  
  train5405->SetMarkerColor(colors[0]);
  train5405->SetLineColor(colors[0]);
  train5405->SetMarkerStyle(33);

  train5406->SetMarkerColor(colors[15]);
  train5406->SetLineColor(colors[15]);
  train5406->SetMarkerStyle(20);

  train5407->SetMarkerColor(colors[2]);
  train5407->SetLineColor(colors[2]);
  train5407->SetMarkerStyle(20);

  train5408->SetMarkerColor(colors[3]);
  train5408->SetLineColor(colors[3]);
  train5408->SetMarkerStyle(33);

  train5409->SetMarkerColor(colors[13]);
  train5409->SetLineColor(colors[13]);
  train5409->SetMarkerStyle(20);

  train5415->SetMarkerColor(colors[5]);
  train5415->SetLineColor(colors[5]);
  train5415->SetMarkerStyle(20);

  train5416->SetMarkerColor(colors[6]);
  train5416->SetLineColor(colors[6]);
  train5416->SetMarkerStyle(20);

  train5442->SetMarkerColor(colors[7]);
  train5442->SetLineColor(colors[7]);
  train5442->SetMarkerStyle(20);
  
  refHist->SetMarkerColor(colors[19]);
  refHist->SetLineColor(colors[19]);
  refHist->SetMarkerStyle(20);

  refHist2->SetMarkerColor(colors[9]);
  refHist2->SetLineColor(colors[9]);
  refHist2->SetMarkerStyle(33);

  jamesRef->SetMarkerColor(colors[10]);
  jamesRef->SetLineColor(colors[10]);
  jamesRef->SetMarkerStyle(28);


  train5405->Rebin(10);
  train5406->Rebin(10);
  train5407->Rebin(10);
  train5408->Rebin(10);
  train5409->Rebin(10);
  train5415->Rebin(10);
  train5416->Rebin(10);
  train5442->Rebin(10);
  refHist->Rebin(10);
  refHist2->Rebin(10);
  
  train5405->Scale(1./train5405->Integral());
  train5406->Scale(1./train5406->Integral());
  train5407->Scale(1./train5407->Integral());
  train5408->Scale(1./train5408->Integral());
  train5409->Scale(1./train5409->Integral());
  train5415->Scale(1./train5415->Integral());
  train5416->Scale(1./train5416->Integral());
  train5442->Scale(1./train5416->Integral());
  refHist->Scale(1./refHist->Integral());
  refHist2->Scale(1./refHist2->Integral());
  jamesRef->Scale(1./jamesRef->Integral());

  train5409->GetXaxis()->SetRangeUser(120,300);
  train5409->GetXaxis()->SetTitle("#rho_{scaled} [GeV/#it{c}]");
  //train5405->Draw();	
  //train5406->Draw("same");	
  //train5407->Draw("same");
  //train5408->Draw("same");	
  train5409->Draw("same");	
  //train5415->Draw("same");
  train5416->Draw("same");
  //refHist->Draw("same");
  //refHist2->Draw("same");
  //jamesRef->Draw("same");

  TLegend* leg = new TLegend(0.45, 0.6, 0.9, 0.9);
  leg->SetTextSize(0.04);
  //leg->AddEntry(train5405, Form("Hybrid Tracks, Excluding 4, #mu = %.2f", train5405->GetMean()));
  //leg->AddEntry(train5406, Form("Background Tracks, Excluding 4, #mu = %.2f", train5406->GetMean()));
  //leg->AddEntry(train5407, Form("Background Tracks, Excluding 3, #mu = %.2f", train5407->GetMean()));
  //leg->AddEntry(train5408, Form("Hybrid Tracks, Excluding 3, #mu = %.2f", train5408->GetMean()));
  leg->AddEntry(train5409, Form("#rho with p_{T} scheme, #mu = %.2f", train5409->GetMean()));
  //leg->AddEntry(train5415, Form("#rho with #it{R} = 0.2, #mu = %.2f", train5415->GetMean()));
  leg->AddEntry(train5416, Form("#rho with E scheme, #mu = %.2f", train5416->GetMean()));
  //leg->AddEntry(train5442, Form("#rho with E scheme, jets with E scheme, #mu = %.2f", train5442->GetMean()));
  //leg->AddEntry(refHist, Form("Background Tracks, Excluding 2, #mu = %.2f", refHist->GetMean()));
  //leg->AddEntry(refHist2, Form("Hybrid Tracks, Excluding 2, #mu = %.2f", refHist2->GetMean()));
  //leg->AddEntry(jamesRef, Form("James Actual, Background Tracks, Excluding 2, #mu = %.2f", jamesRef->GetMean()));
  leg->Draw("same"); 
}
