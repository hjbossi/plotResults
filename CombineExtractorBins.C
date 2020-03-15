void CombineExtractorBins(Int_t pTHard = 0){
  gStyle->SetOptStat(0);
  std::cout << "Analyzing pT Hard Bin : " << pTHard << std::endl;
  TFile* totalFile = TFile::Open("mLJetPerfResults_021420_ScaledAndTrimmed3D_Feb20th_Total.root");
  TFile* _file0    = TFile::Open(Form("mLJetPerfResults_021420_ScaledAndTrimmed3D_Feb20th_%d.root", pTHard));

  TH2D* extractorBin0 = (TH2D*)_file0->Get("h2_extractionBin0");
  TH2D* extractorBin1 = (TH2D*)_file0->Get("h2_extractionBin1");
  TH2D* extractorBin2 = (TH2D*)_file0->Get("h2_extractionBin2");
  TH2D* extractorBin3 = (TH2D*)_file0->Get("h2_extractionBin3");
  TH2D* extractorBin4 = (TH2D*)_file0->Get("h2_extractionBin4");

  TH2D* extractorBin0_Total = (TH2D*)totalFile->Get("h2_extractionBin0");
  TH2D* extractorBin1_Total = (TH2D*)totalFile->Get("h2_extractionBin1");
  TH2D* extractorBin2_Total = (TH2D*)totalFile->Get("h2_extractionBin2");
  TH2D* extractorBin3_Total = (TH2D*)totalFile->Get("h2_extractionBin3");
  TH2D* extractorBin4_Total = (TH2D*)totalFile->Get("h2_extractionBin4");

  
  // perform the scaling
  extractorBin0->Scale(10);
  extractorBin1->Scale(2.5);
  extractorBin2->Scale(1.25);
  extractorBin3->Scale(1.111);
  extractorBin4->Scale(1.0);

  extractorBin0_Total->Scale(10);
  extractorBin1_Total->Scale(2.5);
  extractorBin2_Total->Scale(1.25);
  extractorBin3_Total->Scale(1.111);
  extractorBin4_Total->Scale(1.0);


  TH2D* clone = (TH2D*)extractorBin0->Clone();
  clone->Add(extractorBin1);
  clone->Add(extractorBin2);
  clone->Add(extractorBin3);
  clone->Add(extractorBin4);

  TH2D* clone_Total = (TH2D*)extractorBin0_Total->Clone();
  clone_Total->SetNameTitle(Form("pT Hard Bin %d", pTHard), Form("pT Hard Bin %d", pTHard));
  clone_Total->GetXaxis()->SetTitle("#delta p_{T}");
  clone_Total->Add(extractorBin1_Total);
  clone_Total->Add(extractorBin2_Total);
  clone_Total->Add(extractorBin3_Total);
  clone_Total->Add(extractorBin4_Total);
 
  TH1D* pxTot = (TH1D*) clone_Total->ProjectionX("pxTot", 9, 12);
  pxTot->GetXaxis()->SetRangeUser(-60,60);
  pxTot->SetMarkerStyle(20);
  pxTot->SetMarkerColor(kBlack);
  pxTot->SetLineColor(kBlack);
  pxTot->Draw();

  TH1D* px = (TH1D*) clone->ProjectionX("px", 9, 12);
  px->SetMarkerStyle(20);
  px->SetMarkerColor(kOrange+7);
  px->SetLineColor(kOrange+7);
  px->Draw("same");

  TH1D* px_0 = extractorBin0->ProjectionX("px_0", 9, 12);
  TH1D* px_1 = extractorBin1->ProjectionX("px_1", 9, 12);
  TH1D* px_2 = extractorBin2->ProjectionX("px_2", 9, 12);
  TH1D* px_3 = extractorBin3->ProjectionX("px_3", 9, 12);
  TH1D* px_4 = extractorBin4->ProjectionX("px_4", 9, 12);

  px_0->SetMarkerStyle(20);
  px_0->SetMarkerColor(kBlue);
  px_0->SetLineColor(kBlue);

  px_1->SetMarkerStyle(20);
  px_1->SetMarkerColor(kRed);	
  px_1->SetLineColor(kRed);

  px_2->SetMarkerStyle(20);
  px_2->SetMarkerColor(kGreen);	
  px_2->SetLineColor(kGreen);

  px_3->SetMarkerStyle(20);
  px_3->SetMarkerColor(kCyan);	
  px_3->SetLineColor(kCyan);

  px_4->SetMarkerStyle(20);
  px_4->SetMarkerColor(kOrange);	
  px_4->SetLineColor(kOrange);

  TLegend* leg = new TLegend(0.7, 0.6, 0.9, 0.9);
  leg->AddEntry(px_0, "Extractor Bin 0");
  leg->AddEntry(px_1, "Extractor Bin 1");
  leg->AddEntry(px_2, "Extractor Bin 2");
  leg->AddEntry(px_3, "Extractor Bin 3");
  leg->AddEntry(px_4, "Extractor Bin 4");
  leg->AddEntry(px, Form("Total for pTHard Bin %d", pTHard));
  leg->AddEntry(pxTot, "Total for All pT Hard Bins");

  leg->Draw("same");

  px_0->Draw("same");
  px_1->Draw("same");
  px_2->Draw("same");
  px_3->Draw("same");
  px_4->Draw("same");

}
