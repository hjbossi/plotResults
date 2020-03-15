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
    //TString filename = "/home/hbossi/alidock/data/Embedding_020420/train5442.root";
    TString filename = Form("/home/hbossi/alidock/data/Embedding_021420/AnalysisResults_PtHardBin%d.root", pTHard);
    TFile* f = new TFile(filename);
    TTree* tr = (TTree*)f->Get("JetTree_AliAnalysisTaskJetExtractor_hybridLevelJets_AKTFullR040_tracks_pT0150_caloClustersCombined_E0300_pt_scheme_Rho_Scaled_hybridLevelJets");
    j = new mLJetPerf(tr);
    j->Init(tr);
    j->Loop(pTHard);
    //    TString outputFilename = "mLJetPerfResults_train5442.root";
    TString outputFilename = Form("mLJetPerfResults_021420_R040_Mar10th_%d.root", pTHard);
    fout = new TFile(outputFilename, "RECREATE");
    j->Write(fout);
  }
}
