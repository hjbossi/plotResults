//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Sun Mar  8 21:56:29 2020 by ROOT version 6.14/04
// from TTree predictionTree_NeuralNetwork_LHC16j5_Embedded_R040/predictionTree_NeuralNetwork_LHC16j5_Embedded_R040
// found on file: predictionTree_NeuralNetwork_For_LHC16j5_Embedded_R040.root
//////////////////////////////////////////////////////////

#ifndef neuralNetPredictions_h
#define neuralNetPredictions_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TH2D.h>
#include <TH1.h>
#include <TH3D.h>
#include <sstream>
#include <iostream>


// Header file for the classes stored in the TTree if any.

class neuralNetPredictions {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.
   static constexpr Int_t kMax__index_ = 1;

   // Declaration of leaf types
   Float_t         Jet_Pt;
   Float_t         Jet_MC_TruePtFraction;
   Float_t         Jet_MC_MatchedDetLevelJet_Pt;
   Float_t         Jet_MC_MatchedDetLevelJet_Distance;
   Int_t           Jet_NumTracks;
   Int_t           Jet_NumClusters;
   Float_t         Event_BackgroundDensity;
   Float_t         Event_Vertex_Z;
   Float_t         Jet_Pt_Raw;
   Float_t         Jet_Area;
   Long64_t        PtHardBin;
   Float_t         Jet_Phi;
   Float_t         Event_Centrality;
   Float_t         Jet_Shape_Angularity;
   Float_t         Jet_Shape_LeSub_NoCorr;
   Float_t         Jet_Shape_MomentumDispersion;
   Float_t         Jet_Shape_TrackPtMean;
   Float_t         Jet_Shape_TrackPtMedian;
   Float_t         Jet_MC_MatchedPartLevelJet_Pt;
   Float_t         Jet_MC_MatchedPartLevelJet_Distance;
   Int_t           Jet_MC_MotherParton;
   Double_t        Jet_TrackPt0;
   Double_t        Jet_TrackPt1;
   Double_t        Jet_TrackPt2;
   Double_t        Jet_TrackPt3;
   Double_t        Jet_TrackPt4;
   Double_t        Jet_TrackPt5;
   Double_t        Jet_TrackPt6;
   Double_t        Jet_TrackPt7;
   Double_t        Jet_TrackPt8;
   Double_t        Jet_TrackPt9;
   Double_t        Jet_TrackPt10;
   Double_t        Jet_TrackPt11;
   Double_t        Jet_TrackPt12;
   Double_t        Jet_TrackPt13;
   Double_t        Jet_TrackPt14;
   Double_t        Jet_TrackPt15;
   Double_t        Jet_TrackPt16;
   Double_t        Jet_TrackPt17;
   Double_t        Jet_TrackPt18;
   Double_t        Jet_TrackPt19;
   Double_t        Jet_ClusterPt0;
   Double_t        Jet_ClusterPt1;
   Double_t        Jet_ClusterPt2;
   Double_t        Jet_ClusterPt3;
   Double_t        Jet_ClusterPt4;
   Double_t        Jet_ClusterPt5;
   Double_t        Jet_ClusterPt6;
   Double_t        Jet_ClusterPt7;
   Double_t        Jet_ClusterPt8;
   Double_t        Jet_ClusterPt9;
   Double_t        Jet_ClusterPt10;
   Double_t        Jet_ClusterPt11;
   Double_t        Jet_ClusterPt12;
   Double_t        Jet_ClusterPt13;
   Double_t        Jet_ClusterPt14;
   Double_t        Jet_ClusterPt15;
   Double_t        Jet_ClusterPt16;
   Double_t        Jet_ClusterPt17;
   Double_t        Jet_ClusterPt18;
   Double_t        Jet_ClusterPt19;
   Double_t        Jet_ConstPt0;
   Double_t        Jet_ConstPt1;
   Double_t        Jet_ConstPt2;
   Double_t        Jet_ConstPt3;
   Double_t        Jet_ConstPt4;
   Double_t        Jet_ConstPt5;
   Double_t        Jet_ConstPt6;
   Double_t        Jet_ConstPt7;
   Double_t        Jet_ConstPt8;
   Double_t        Jet_ConstPt9;
   Double_t        Jet_ConstPt10;
   Double_t        Jet_ConstPt11;
   Double_t        Jet_ConstPt12;
   Double_t        Jet_ConstPt13;
   Double_t        Jet_ConstPt14;
   Double_t        Jet_ConstPt15;
   Double_t        Jet_ConstPt16;
   Double_t        Jet_ConstPt17;
   Double_t        Jet_ConstPt18;
   Double_t        Jet_ConstPt19;
   Double_t        Predicted_Jet_Pt;
   Long64_t        __index__;

   // declare hists
   TH2D*           linCorrelation; // (pT det) vs. (frac * hybrid)                                                                                                
   TH2D*           linCorrelationPartLevel;
   TH2D*           hybridDetResp;
   TH2D*           mLTruePartResp;
   TH2D*           mLTrueDetResp;
   TH2D*           mLTrueHybridResp;
   TH2D*           h2_det_mLTrue_v_mLTrue; // (pT det)/(frac * hybrid) vs. (frac*hybrid)                                                                          
   TH2D*           h2_mLTrue_det_v_det; // (frac * hybrid)/(pT det) vs. (pT det)                                                                                  
   TH2D*           h2_resid_mLTrue_part_v_part; // (frac * hybrid - pT part)/(pT part) vs. (pT part)                                                              
   TH2D*           h2_resid_mLTrue_det_v_det; // (frac * hybrid - pT det)/(pT det) vs. (pT det)                                                                   
   TH2D*           h2_resid_det_part_v_part; // (det - part)/part vs. part                                                                                        
   TH2D*           h2_resid_hybrid_part_v_part; // (hybrid - part)/part vs. part
   TH2D*           h2_resid_hybrid_part_v_part_RAW;
   TH2D*           h2_resid_hybrid_det_v_det; // (hybrid - det)/det vs. det                                                                                       
   TH2D*           h2_resid_hybrid_det_v_part;
   TH2D*           h2_resid_hybrid_det_v_det_RAW; //(hybrid - det) vs det.                                                                                        
   TH2D*           h2_resid_hybrid_mLTrue_v_mLTrue; // (hybrid - mLTrue)/mLTrue vs. mLTrue                                                                        
   TH2D*           h2_resid_det_mLTrue_v_mLTrue; // (det - mLTrue)/ mLTrue                                                                                        
   TH1D*           h2_event_bkg_density;
   TH1D*           hybridSpectra;
   TH1D*           detSpectra;
   TH1D*           partSpectra;
   TH2D*           mlResidualPlot;
   TH2D*           mlResidualPlotNaive; // use sum of 8 highest pT tracks instead of ML                                                                           
   std::vector<TH2D*> extractorBinHists;
   std::vector<TH3D*> extractorBinHists3D;

   
   
   
   // List of branches
   TBranch        *b_Jet_Pt;   //!
   TBranch        *b_Jet_MC_TruePtFraction;   //!
   TBranch        *b_Jet_MC_MatchedDetLevelJet_Pt;   //!
   TBranch        *b_Jet_MC_MatchedDetLevelJet_Distance;   //!
   TBranch        *b_Jet_NumTracks;   //!
   TBranch        *b_Jet_NumClusters;   //!
   TBranch        *b_Event_BackgroundDensity;   //!
   TBranch        *b_Event_Vertex_Z;   //!
   TBranch        *b_Jet_Pt_Raw;   //!
   TBranch        *b_Jet_Area;   //!
   TBranch        *b_PtHardBin;   //!
   TBranch        *b_Jet_Phi;   //!
   TBranch        *b_Event_Centrality;   //!
   TBranch        *b_Jet_Shape_Angularity;   //!
   TBranch        *b_Jet_Shape_LeSub_NoCorr;   //!
   TBranch        *b_Jet_Shape_MomentumDispersion;   //!
   TBranch        *b_Jet_Shape_TrackPtMean;   //!
   TBranch        *b_Jet_Shape_TrackPtMedian;   //!
   TBranch        *b_Jet_MC_MatchedPartLevelJet_Pt;   //!
   TBranch        *b_Jet_MC_MatchedPartLevelJet_Distance;   //!
   TBranch        *b_Jet_MC_MotherParton;   //!
   TBranch        *b_Jet_TrackPt0;   //!
   TBranch        *b_Jet_TrackPt1;   //!
   TBranch        *b_Jet_TrackPt2;   //!
   TBranch        *b_Jet_TrackPt3;   //!
   TBranch        *b_Jet_TrackPt4;   //!
   TBranch        *b_Jet_TrackPt5;   //!
   TBranch        *b_Jet_TrackPt6;   //!
   TBranch        *b_Jet_TrackPt7;   //!
   TBranch        *b_Jet_TrackPt8;   //!
   TBranch        *b_Jet_TrackPt9;   //!
   TBranch        *b_Jet_TrackPt10;   //!
   TBranch        *b_Jet_TrackPt11;   //!
   TBranch        *b_Jet_TrackPt12;   //!
   TBranch        *b_Jet_TrackPt13;   //!
   TBranch        *b_Jet_TrackPt14;   //!
   TBranch        *b_Jet_TrackPt15;   //!
   TBranch        *b_Jet_TrackPt16;   //!
   TBranch        *b_Jet_TrackPt17;   //!
   TBranch        *b_Jet_TrackPt18;   //!
   TBranch        *b_Jet_TrackPt19;   //!
   TBranch        *b_Jet_ClusterPt0;   //!
   TBranch        *b_Jet_ClusterPt1;   //!
   TBranch        *b_Jet_ClusterPt2;   //!
   TBranch        *b_Jet_ClusterPt3;   //!
   TBranch        *b_Jet_ClusterPt4;   //!
   TBranch        *b_Jet_ClusterPt5;   //!
   TBranch        *b_Jet_ClusterPt6;   //!
   TBranch        *b_Jet_ClusterPt7;   //!
   TBranch        *b_Jet_ClusterPt8;   //!
   TBranch        *b_Jet_ClusterPt9;   //!
   TBranch        *b_Jet_ClusterPt10;   //!
   TBranch        *b_Jet_ClusterPt11;   //!
   TBranch        *b_Jet_ClusterPt12;   //!
   TBranch        *b_Jet_ClusterPt13;   //!
   TBranch        *b_Jet_ClusterPt14;   //!
   TBranch        *b_Jet_ClusterPt15;   //!
   TBranch        *b_Jet_ClusterPt16;   //!
   TBranch        *b_Jet_ClusterPt17;   //!
   TBranch        *b_Jet_ClusterPt18;   //!
   TBranch        *b_Jet_ClusterPt19;   //!
   TBranch        *b_Jet_ConstPt0;   //!
   TBranch        *b_Jet_ConstPt1;   //!
   TBranch        *b_Jet_ConstPt2;   //!
   TBranch        *b_Jet_ConstPt3;   //!
   TBranch        *b_Jet_ConstPt4;   //!
   TBranch        *b_Jet_ConstPt5;   //!
   TBranch        *b_Jet_ConstPt6;   //!
   TBranch        *b_Jet_ConstPt7;   //!
   TBranch        *b_Jet_ConstPt8;   //!
   TBranch        *b_Jet_ConstPt9;   //!
   TBranch        *b_Jet_ConstPt10;   //!
   TBranch        *b_Jet_ConstPt11;   //!
   TBranch        *b_Jet_ConstPt12;   //!
   TBranch        *b_Jet_ConstPt13;   //!
   TBranch        *b_Jet_ConstPt14;   //!
   TBranch        *b_Jet_ConstPt15;   //!
   TBranch        *b_Jet_ConstPt16;   //!
   TBranch        *b_Jet_ConstPt17;   //!
   TBranch        *b_Jet_ConstPt18;   //!
   TBranch        *b_Jet_ConstPt19;   //!
   TBranch        *b_Predicted_Jet_Pt;   //!
   TBranch        *b___index__;   //!

   neuralNetPredictions(TTree *tree=0);
   virtual ~neuralNetPredictions();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Write(TFile* fout);
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef neuralNetPredictions_cxx
neuralNetPredictions::neuralNetPredictions(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("predictionTree_NeuralNetwork_For_LHC16j5_Embedded_R040.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("predictionTree_NeuralNetwork_For_LHC16j5_Embedded_R040.root");
      }
      f->GetObject("predictionTree_NeuralNetwork_LHC16j5_Embedded_R040",tree);

   }
   Init(tree);
}

neuralNetPredictions::~neuralNetPredictions()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t neuralNetPredictions::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t neuralNetPredictions::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void neuralNetPredictions::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("Jet_Pt", &Jet_Pt, &b_Jet_Pt);
   fChain->SetBranchAddress("Jet_MC_TruePtFraction", &Jet_MC_TruePtFraction, &b_Jet_MC_TruePtFraction);
   fChain->SetBranchAddress("Jet_MC_MatchedDetLevelJet_Pt", &Jet_MC_MatchedDetLevelJet_Pt, &b_Jet_MC_MatchedDetLevelJet_Pt);
   fChain->SetBranchAddress("Jet_MC_MatchedDetLevelJet_Distance", &Jet_MC_MatchedDetLevelJet_Distance, &b_Jet_MC_MatchedDetLevelJet_Distance);
   fChain->SetBranchAddress("Jet_NumTracks", &Jet_NumTracks, &b_Jet_NumTracks);
   fChain->SetBranchAddress("Jet_NumClusters", &Jet_NumClusters, &b_Jet_NumClusters);
   fChain->SetBranchAddress("Event_BackgroundDensity", &Event_BackgroundDensity, &b_Event_BackgroundDensity);
   fChain->SetBranchAddress("Event_Vertex_Z", &Event_Vertex_Z, &b_Event_Vertex_Z);
   fChain->SetBranchAddress("Jet_Pt_Raw", &Jet_Pt_Raw, &b_Jet_Pt_Raw);
   fChain->SetBranchAddress("Jet_Area", &Jet_Area, &b_Jet_Area);
   fChain->SetBranchAddress("PtHardBin", &PtHardBin, &b_PtHardBin);
   fChain->SetBranchAddress("Jet_Phi", &Jet_Phi, &b_Jet_Phi);
   fChain->SetBranchAddress("Event_Centrality", &Event_Centrality, &b_Event_Centrality);
   fChain->SetBranchAddress("Jet_Shape_Angularity", &Jet_Shape_Angularity, &b_Jet_Shape_Angularity);
   fChain->SetBranchAddress("Jet_Shape_LeSub_NoCorr", &Jet_Shape_LeSub_NoCorr, &b_Jet_Shape_LeSub_NoCorr);
   fChain->SetBranchAddress("Jet_Shape_MomentumDispersion", &Jet_Shape_MomentumDispersion, &b_Jet_Shape_MomentumDispersion);
   fChain->SetBranchAddress("Jet_Shape_TrackPtMean", &Jet_Shape_TrackPtMean, &b_Jet_Shape_TrackPtMean);
   fChain->SetBranchAddress("Jet_Shape_TrackPtMedian", &Jet_Shape_TrackPtMedian, &b_Jet_Shape_TrackPtMedian);
   fChain->SetBranchAddress("Jet_MC_MatchedPartLevelJet_Pt", &Jet_MC_MatchedPartLevelJet_Pt, &b_Jet_MC_MatchedPartLevelJet_Pt);
   fChain->SetBranchAddress("Jet_MC_MatchedPartLevelJet_Distance", &Jet_MC_MatchedPartLevelJet_Distance, &b_Jet_MC_MatchedPartLevelJet_Distance);
   fChain->SetBranchAddress("Jet_MC_MotherParton", &Jet_MC_MotherParton, &b_Jet_MC_MotherParton);
   fChain->SetBranchAddress("Jet_TrackPt0", &Jet_TrackPt0, &b_Jet_TrackPt0);
   fChain->SetBranchAddress("Jet_TrackPt1", &Jet_TrackPt1, &b_Jet_TrackPt1);
   fChain->SetBranchAddress("Jet_TrackPt2", &Jet_TrackPt2, &b_Jet_TrackPt2);
   fChain->SetBranchAddress("Jet_TrackPt3", &Jet_TrackPt3, &b_Jet_TrackPt3);
   fChain->SetBranchAddress("Jet_TrackPt4", &Jet_TrackPt4, &b_Jet_TrackPt4);
   fChain->SetBranchAddress("Jet_TrackPt5", &Jet_TrackPt5, &b_Jet_TrackPt5);
   fChain->SetBranchAddress("Jet_TrackPt6", &Jet_TrackPt6, &b_Jet_TrackPt6);
   fChain->SetBranchAddress("Jet_TrackPt7", &Jet_TrackPt7, &b_Jet_TrackPt7);
   fChain->SetBranchAddress("Jet_TrackPt8", &Jet_TrackPt8, &b_Jet_TrackPt8);
   fChain->SetBranchAddress("Jet_TrackPt9", &Jet_TrackPt9, &b_Jet_TrackPt9);
   fChain->SetBranchAddress("Jet_TrackPt10", &Jet_TrackPt10, &b_Jet_TrackPt10);
   fChain->SetBranchAddress("Jet_TrackPt11", &Jet_TrackPt11, &b_Jet_TrackPt11);
   fChain->SetBranchAddress("Jet_TrackPt12", &Jet_TrackPt12, &b_Jet_TrackPt12);
   fChain->SetBranchAddress("Jet_TrackPt13", &Jet_TrackPt13, &b_Jet_TrackPt13);
   fChain->SetBranchAddress("Jet_TrackPt14", &Jet_TrackPt14, &b_Jet_TrackPt14);
   fChain->SetBranchAddress("Jet_TrackPt15", &Jet_TrackPt15, &b_Jet_TrackPt15);
   fChain->SetBranchAddress("Jet_TrackPt16", &Jet_TrackPt16, &b_Jet_TrackPt16);
   fChain->SetBranchAddress("Jet_TrackPt17", &Jet_TrackPt17, &b_Jet_TrackPt17);
   fChain->SetBranchAddress("Jet_TrackPt18", &Jet_TrackPt18, &b_Jet_TrackPt18);
   fChain->SetBranchAddress("Jet_TrackPt19", &Jet_TrackPt19, &b_Jet_TrackPt19);
   fChain->SetBranchAddress("Jet_ClusterPt0", &Jet_ClusterPt0, &b_Jet_ClusterPt0);
   fChain->SetBranchAddress("Jet_ClusterPt1", &Jet_ClusterPt1, &b_Jet_ClusterPt1);
   fChain->SetBranchAddress("Jet_ClusterPt2", &Jet_ClusterPt2, &b_Jet_ClusterPt2);
   fChain->SetBranchAddress("Jet_ClusterPt3", &Jet_ClusterPt3, &b_Jet_ClusterPt3);
   fChain->SetBranchAddress("Jet_ClusterPt4", &Jet_ClusterPt4, &b_Jet_ClusterPt4);
   fChain->SetBranchAddress("Jet_ClusterPt5", &Jet_ClusterPt5, &b_Jet_ClusterPt5);
   fChain->SetBranchAddress("Jet_ClusterPt6", &Jet_ClusterPt6, &b_Jet_ClusterPt6);
   fChain->SetBranchAddress("Jet_ClusterPt7", &Jet_ClusterPt7, &b_Jet_ClusterPt7);
   fChain->SetBranchAddress("Jet_ClusterPt8", &Jet_ClusterPt8, &b_Jet_ClusterPt8);
   fChain->SetBranchAddress("Jet_ClusterPt9", &Jet_ClusterPt9, &b_Jet_ClusterPt9);
   fChain->SetBranchAddress("Jet_ClusterPt10", &Jet_ClusterPt10, &b_Jet_ClusterPt10);
   fChain->SetBranchAddress("Jet_ClusterPt11", &Jet_ClusterPt11, &b_Jet_ClusterPt11);
   fChain->SetBranchAddress("Jet_ClusterPt12", &Jet_ClusterPt12, &b_Jet_ClusterPt12);
   fChain->SetBranchAddress("Jet_ClusterPt13", &Jet_ClusterPt13, &b_Jet_ClusterPt13);
   fChain->SetBranchAddress("Jet_ClusterPt14", &Jet_ClusterPt14, &b_Jet_ClusterPt14);
   fChain->SetBranchAddress("Jet_ClusterPt15", &Jet_ClusterPt15, &b_Jet_ClusterPt15);
   fChain->SetBranchAddress("Jet_ClusterPt16", &Jet_ClusterPt16, &b_Jet_ClusterPt16);
   fChain->SetBranchAddress("Jet_ClusterPt17", &Jet_ClusterPt17, &b_Jet_ClusterPt17);
   fChain->SetBranchAddress("Jet_ClusterPt18", &Jet_ClusterPt18, &b_Jet_ClusterPt18);
   fChain->SetBranchAddress("Jet_ClusterPt19", &Jet_ClusterPt19, &b_Jet_ClusterPt19);
   fChain->SetBranchAddress("Jet_ConstPt0", &Jet_ConstPt0, &b_Jet_ConstPt0);
   fChain->SetBranchAddress("Jet_ConstPt1", &Jet_ConstPt1, &b_Jet_ConstPt1);
   fChain->SetBranchAddress("Jet_ConstPt2", &Jet_ConstPt2, &b_Jet_ConstPt2);
   fChain->SetBranchAddress("Jet_ConstPt3", &Jet_ConstPt3, &b_Jet_ConstPt3);
   fChain->SetBranchAddress("Jet_ConstPt4", &Jet_ConstPt4, &b_Jet_ConstPt4);
   fChain->SetBranchAddress("Jet_ConstPt5", &Jet_ConstPt5, &b_Jet_ConstPt5);
   fChain->SetBranchAddress("Jet_ConstPt6", &Jet_ConstPt6, &b_Jet_ConstPt6);
   fChain->SetBranchAddress("Jet_ConstPt7", &Jet_ConstPt7, &b_Jet_ConstPt7);
   fChain->SetBranchAddress("Jet_ConstPt8", &Jet_ConstPt8, &b_Jet_ConstPt8);
   fChain->SetBranchAddress("Jet_ConstPt9", &Jet_ConstPt9, &b_Jet_ConstPt9);
   fChain->SetBranchAddress("Jet_ConstPt10", &Jet_ConstPt10, &b_Jet_ConstPt10);
   fChain->SetBranchAddress("Jet_ConstPt11", &Jet_ConstPt11, &b_Jet_ConstPt11);
   fChain->SetBranchAddress("Jet_ConstPt12", &Jet_ConstPt12, &b_Jet_ConstPt12);
   fChain->SetBranchAddress("Jet_ConstPt13", &Jet_ConstPt13, &b_Jet_ConstPt13);
   fChain->SetBranchAddress("Jet_ConstPt14", &Jet_ConstPt14, &b_Jet_ConstPt14);
   fChain->SetBranchAddress("Jet_ConstPt15", &Jet_ConstPt15, &b_Jet_ConstPt15);
   fChain->SetBranchAddress("Jet_ConstPt16", &Jet_ConstPt16, &b_Jet_ConstPt16);
   fChain->SetBranchAddress("Jet_ConstPt17", &Jet_ConstPt17, &b_Jet_ConstPt17);
   fChain->SetBranchAddress("Jet_ConstPt18", &Jet_ConstPt18, &b_Jet_ConstPt18);
   fChain->SetBranchAddress("Jet_ConstPt19", &Jet_ConstPt19, &b_Jet_ConstPt19);
   fChain->SetBranchAddress("Predicted_Jet_Pt", &Predicted_Jet_Pt, &b_Predicted_Jet_Pt);
   fChain->SetBranchAddress("__index__", &__index__, &b___index__);

   Double_t xbins[14];
   xbins[0]=5;
   xbins[1]=10;
   xbins[2]=20;
   xbins[3]=30;
   xbins[4]=40;
   xbins[5]=50;
   xbins[6]=60;
   xbins[7]=70;
   xbins[8]=80;
   xbins[9]=100;
   xbins[10]=120;
   xbins[11]=140;
   xbins[12]=190;
   xbins[13]=250;

   TH1::SetDefaultSumw2();
   linCorrelation                   = new TH2D("linCorrelation", "Detector Level p_{T} vs. ML True p_{T}", 400,0,400,400,0,400);
   linCorrelationPartLevel          = new TH2D("linCorrelationPartLevel", "",19,35,120,13, xbins);
   hybridDetResp                    = new TH2D("hybridDetResp", "",1000,0,400,1000,0,400);
   mLTruePartResp                   = new TH2D("mLTruePartResp", "",1000,0,400,1000,0,400);
   mLTrueDetResp                    = new TH2D("mLTrueDetResp", "",1000,0,400,1000,0,400);
   mLTrueHybridResp                 = new TH2D("mLTrueHybridResp" ,"", 1000, 0, 400, 1000, 0, 400);
   h2_det_mLTrue_v_mLTrue           = new TH2D("h2_det_mLTrue_v_mLTrue", "#frac{Detector Level p_{T}}{ML True p_{T}} vs. ML True p_{T}", 100,0,100,1000,-40,40);
   h2_mLTrue_det_v_det              = new TH2D("h2_mLTrue_det_v_det","#frac{ML True p_{T}}{Detector Level p_{T}} vs. Detector Level p_{T}",100,0,100,1000,-40,40)\
;
   h2_resid_mLTrue_part_v_part      = new TH2D("h2_resid_mLTrue_part_v_part","#frac{ML True p_{T} - Particle Level p_{T}}{Particle Level p{T}} vs. Particle Level\
 p{T}",100,0,500,1000,-40,40);
   h2_resid_mLTrue_det_v_det        = new TH2D("h2_resid_mLTrue_det_v_det","#frac{ML True p_{T} - Detector Level p_{T}}{DetectorLevel p{T}} vs. Detector Level p{\
T}",100,0,500,1000,-40,40);
   h2_resid_det_part_v_part         = new TH2D("h2_resid_det_part_v_part", "#frac{Detector Level p_{T} - Particle Level p_{T}}{Particle Level p{T}} vs. Particle \
Level p{T}", 100, 0,500, 1000, -10,10);
   h2_resid_hybrid_part_v_part      = new TH2D("h2_resid_hybrid_part_v_part", "#frac{Hybrid p_{T} - Particle Level p_{T}}{Particle Level p{T}} vs. Particle Level p{T}", 100, 0,500, \
1000, -10,10);
   h2_resid_hybrid_part_v_part_RAW    = new TH2D("h2_resid_hybrid_part_v_part_RAW", "Hybrid p_{T} - Detector Level p_{T} vs. Detector Level p_{T}", 100, 0,500, 1000, -60,60);

   h2_resid_hybrid_det_v_det        = new TH2D("h2_resid_hybrid_det_v_det", "#frac{Hybrid p_{T} - Detector Level p_{T}}{Detector Level p_{T}} vs. Detector Level p_{T}", 100, 0,500, \
1000, -10,10);
   h2_resid_hybrid_det_v_part       = new TH2D("h2_resid_hybrid_det_v_part", "", 100, 0,500, 1000, -10,10);

   h2_resid_hybrid_det_v_det_RAW    = new TH2D("h2_resid_hybrid_det_v_det_RAW", "Hybrid p_{T} - Detector Level p_{T} vs. Detector Level p_{T}", 100, 0,500, 1000, \
 -60,60);
   h2_resid_hybrid_mLTrue_v_mLTrue  = new TH2D("h2_resid_hybrid_mLTrue_v_mLTrue", "", 100, 0,200, 1000, -10,10);
   h2_resid_det_mLTrue_v_mLTrue     = new TH2D("h2_resid_det_mLTrue_v_mLTrue", "", 100, 0,200, 1000, -10,10);
   h2_event_bkg_density             = new TH1D("event_bkg", "event_bkg",1000, 0, 500);
   mlResidualPlot                   = new TH2D("mLResidualPlot", "ml Resiudal Plot", 201, -60, 140, 25, 0, 125);
   mlResidualPlotNaive              = new TH2D("mLResidualPlotNaive", "Naive Residual", 120, -60, 61, 25, 0, 120);
    hybridSpectra                    = new TH1D("hybridSpectra", "hybridSpectra", 500, -20,1000);
   detSpectra                       = new TH1D("detSpectra", "detSpectra",500, -20, 1000);
   partSpectra                       = new TH1D("partSpectra", "partSpectra", 500, -20, 1000);
   std::stringstream ss;
   for(Int_t i = 0; i < 6; i++){
     ss << "h2_extractionBin" << i;
     TH2D* h2 = new TH2D(ss.str().c_str(), ss.str().c_str(), 201, -60, 140, 25, 0, 125);
     extractorBinHists.push_back(h2);
     ss.str("");
   }
   for(Int_t k = 0; k < 6; k++){
     ss << "h3_extractionBin" << k;
     TH3D* h3 = new TH3D(ss.str().c_str(), ss.str().c_str(), 120, -60, 61, 25, 0, 125,25, 0,1000);
     extractorBinHists3D.push_back(h3);
     ss.str("");
   }

   
   Notify();
}

Bool_t neuralNetPredictions::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

//additional write class to write the histograms to a file                                                                                                        
void neuralNetPredictions::Write(TFile* fout)
{
  linCorrelation->Write();
  linCorrelationPartLevel->Write();
  hybridDetResp->Write();
  mLTruePartResp->Write();
  mLTrueDetResp->Write();
  mLTrueHybridResp->Write();
  h2_det_mLTrue_v_mLTrue->Write();
  h2_mLTrue_det_v_det->Write();
  h2_resid_mLTrue_part_v_part->Write();
  h2_resid_mLTrue_det_v_det->Write();
  h2_resid_det_part_v_part->Write();
  h2_resid_hybrid_part_v_part->Write();
  h2_resid_hybrid_part_v_part_RAW->Write();
  h2_resid_hybrid_det_v_det->Write();
  h2_resid_hybrid_det_v_part->Write();
  h2_resid_hybrid_det_v_det_RAW->Write();
  h2_resid_hybrid_mLTrue_v_mLTrue->Write();
  h2_resid_det_mLTrue_v_mLTrue->Write();
  h2_event_bkg_density->Write();
  mlResidualPlot->Write();
  mlResidualPlotNaive->Write();
  hybridSpectra->Write();
  detSpectra->Write();
  partSpectra->Write();
  for (Int_t i = 0; i< extractorBinHists.size(); i++) extractorBinHists.at(i)->Write();
  for (Int_t k = 0; k< extractorBinHists3D.size(); k++) extractorBinHists3D.at(k)->Write();
  fout->Close(); 
}

void neuralNetPredictions::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t neuralNetPredictions::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef neuralNetPredictions_cxx
