void CombineExtractorBins3D(){
  TFile *_file0 = TFile::Open("mLJetPerfResults_011320_ScaledAndTrimmed3D_ZCoarseBinsV2_Total.root");
  TH3D* extractorBin0 = (TH3D*)_file0->Get("h3_extractionBin0");
  TH3D* extractorBin1 = (TH3D*)_file0->Get("h3_extractionBin1");
  TH3D* extractorBin2 = (TH3D*)_file0->Get("h3_extractionBin2");
  TH3D* extractorBin3 = (TH3D*)_file0->Get("h3_extractionBin3");
  TH3D* extractorBin4 = (TH3D*)_file0->Get("h3_extractionBin4");


  // perform the scaling
  extractorBin0->Scale(10);
  extractorBin1->Scale(2.5);
  extractorBin2->Scale(1.25);
  extractorBin3->Scale(1.111);
  extractorBin4->Scale(1.0);

  TH3D* clone = (TH3D*)extractorBin0->Clone();
  clone->Add(extractorBin1);
  clone->Add(extractorBin2);
  clone->Add(extractorBin3);
  clone->Add(extractorBin4);

  TH1D* px = (TH1D*) clone->ProjectionX("px", 9, 12);
  px->SetMarkerStyle(20);
  px->SetMarkerColor(kBlack);
  px->SetLineColor(kBlack);
  px->Draw(); 

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

  px_0->Draw("same");
  px_1->Draw("same");
  px_2->Draw("same");
  px_3->Draw("same");
  px_4->Draw("same");
}
