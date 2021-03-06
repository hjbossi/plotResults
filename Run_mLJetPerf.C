//#include "mLJetPerf.h"
#include <sstream>
#include <iostream>


//class mLJetPerf;

void Run_mLJetPerf(int pTHard = 0)
{
  gROOT->ProcessLine(".L mLJetPerf_C.so");
  mLJetPerf* j;
  TFile* fout;
  for(Int_t pTHard = 1 ; pTHard < 21 ; pTHard++){
    std::cout << "Processing pT Hard Bin: " << pTHard << std::endl;
    // MODIFIED, CHANGE THIS
    TString filename = Form("/home/alidock/data/Embedding_021420/AnalysisResults_PtHardBin%d.root", pTHard);
    TFile* f = new TFile(filename);
    TTree* tr = (TTree*)f->Get("JetTree_AliAnalysisTaskJetExtractor_hybridLevelJets_AKTFullR020_tracks_pT0150_caloClustersCombined_E0300_pt_scheme_Rho_Scaled_hybridLevelJets");
    j = new mLJetPerf(tr);
    j->Init(tr);
    j->Loop(pTHard);
    TString outputFilename = Form("mLJetPerfResults_021420_R020_Mar17th_%d.root", pTHard);
    fout = new TFile(outputFilename, "RECREATE");
    j->Write(fout);
  }
}
