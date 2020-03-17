// plotJetSpectra.C - plots James's hybrid jet spectra
void plotJetSpectra(){
  //Only use this for James's Jet Performance
  /*
  TFile *_file0 = TFile::Open("../data/jetPerf4240_11212018/AnalysisResults.root");
  AliEmcalList* listTemp = (AliEmcalList*)_file0->Get("AliAnalysisTaskEmcalJetPerformance_tracks_caloClusters_04_7GeV_histos");
  THashList* listTemp2 = (THashList*)listTemp->FindObject("Jet_AKTFullR040_tracks_pT0150_caloClusters_E0300_pt_scheme");
  THashList* jetList = (THashList*)listTemp2->FindObject("JetHistograms");
  TH3D* jetPtArea = (TH3D*)jetList->FindObject("hAreaVsPt");
  TH1D* jetPt = (TH1D*)jetPtArea->ProjectionY("jetPt");
  jetPt->Draw();
  */
  
  TFile *_file1 = TFile::Open("../data/jetPerf5219_112219/AnalysisResults.root");
  AliEmcalList* listTemp3 = (AliEmcalList*)_file1->Get("AliAnalysisTaskEmcalJetPerformance_tracks_caloClusters_04_0GeV_histos");
  THashList* listTemp4 = (THashList*)listTemp3->FindObject("Jet_AKTFullR040_tracks_pT0150_caloClusters_E0300_pt_scheme");
  THashList* jetList2 = (THashList*)listTemp4->FindObject("JetHistograms");
  TH3D* jetPtArea2 = (TH3D*)jetList2->FindObject("hAreaVsPt");
  std::cout << jetPtArea2->GetXaxis()->GetNbins() << std::endl;
  TH1D* jetPt2 = (TH1D*)jetPtArea2->ProjectionY("jetPt2", 1, 1);
  std::cout << jetPt2->GetXaxis()->GetNbins() << std::endl; 
  std::cout << jetPt2->Integral(61,175) << std::endl;
  jetPt2->Scale(1. /jetPt2->Integral());
  jetPt2->SetLineColor(kRed);
  //jetPt2->Draw("same");

  TFile *_file2 = TFile::Open("../data/Data_030820/AnalysisResults.root");
  TTree* jetTree = (TTree*)_file2->Get("JetTree_AliAnalysisTaskJetExtractor_Jets_AKTFullR040_tracks_pT0150_caloClusters_E0300_pt_scheme_Rho_Scaled_Jets");
  jetTree->Draw("Jet_Pt >> h(175, -100, 250)", "Event_Centrality < 10", "");
  TH1D* hDraw = (TH1D*)gDirectory->Get("h");
  hDraw->Scale(1./hDraw->Integral());
  hDraw->Draw("HIST");
  jetPt2->Draw(" HIST same");
}
