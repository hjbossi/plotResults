//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Tue May 14 09:23:51 2019 by ROOT version 6.16/00
// from TTree JetTree_AliAnalysisTaskJetExtractor_hybridLevelJets_AKTFullR020_tracks_pT0150_caloClustersCombined_E0300_pt_scheme_Rho_ScaledR020_hybridLevelJets/
// found on file: highstatstest_2.root
//////////////////////////////////////////////////////////

#ifndef mLJetPerf_h
#define mLJetPerf_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TH2D.h>
#include <TH1.h>
#include <TH3D.h>
#include <sstream>
#include <iostream>

// Header file for the classes stored in the TTree if any.

class mLJetPerf {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
   Float_t         Jet_Pt;
   Float_t         Jet_Phi;
   Float_t         Jet_Eta;
   Float_t         Jet_Area;
   Int_t           Jet_NumTracks;
   Int_t           Jet_NumClusters;
   Float_t         Event_BackgroundDensity;
   Float_t         Event_BackgroundDensityMass;
   Float_t         Event_Vertex_X;
   Float_t         Event_Vertex_Y;
   Float_t         Event_Vertex_Z;
   Float_t         Event_Centrality;
   Int_t           Event_Multiplicity;
   Long64_t        Event_ID;
   Float_t         Event_MagneticField;
   Float_t         Event_PtHard;
   Float_t         Event_Weight;
   Float_t         Event_ImpactParameter;
   Float_t         Jet_Track_Pt[200];   //[Jet_NumTracks]
   Float_t         Jet_Track_Phi[200];   //[Jet_NumTracks]
   Float_t         Jet_Track_Eta[200];   //[Jet_NumTracks]
   Float_t         Jet_Track_Charge[200];   //[Jet_NumTracks]
   Int_t           Jet_Track_Label[200];   //[Jet_NumTracks]
   Float_t         Jet_Cluster_Pt[200];   //[Jet_NumClusters]
   Float_t         Jet_Cluster_E[200];   //[Jet_NumClusters]
   Float_t         Jet_Cluster_Phi[200];   //[Jet_NumClusters]
   Float_t         Jet_Cluster_Eta[200];   //[Jet_NumClusters]
   Float_t         Jet_Cluster_M02[200];   //[Jet_NumClusters]
   Float_t         Jet_Cluster_Time[200];   //[Jet_NumClusters]
   Int_t           Jet_Cluster_Label[200];   //[Jet_NumClusters]
   Int_t           Jet_MC_MotherParton;
   Int_t           Jet_MC_MotherHadron;
   Int_t           Jet_MC_MotherIC;
   Float_t         Jet_MC_MatchedDetLevelJet_Distance;
   Float_t         Jet_MC_MatchedDetLevelJet_Pt;
   Float_t         Jet_MC_MatchedDetLevelJet_Mass;
   Float_t         Jet_MC_MatchedPartLevelJet_Distance;
   Float_t         Jet_MC_MatchedPartLevelJet_Pt;
   Float_t         Jet_MC_MatchedPartLevelJet_Mass;
   Float_t         Jet_MC_TruePtFraction;
   Float_t         Jet_MC_TruePtFraction_PartLevel;
   Float_t         Jet_MC_TruePtFraction_tracks;
   Float_t         Jet_MC_TruePtFraction_clusters;
   
   // declaration of histograms
   TH2D*           linCorrelation; // (pT det) vs. (frac * hybrid)
   TH2D*           linCorrelationPartLevel; 
   TH2D*           hybridDetResp;
   TH2D*           mLTruePartResp;
   TH2D*           mLTrueDetResp;
   TH2D*           mLTrueHybridResp;
   TH2D*           tagHybridResp;
   TH2D*           partTagResp;
   TH2D*           h2_det_mLTrue_v_mLTrue; // (pT det)/(frac * hybrid) vs. (frac*hybrid)
   TH2D*           h2_mLTrue_det_v_det; // (frac * hybrid)/(pT det) vs. (pT det)
   TH2D*           h2_resid_mLTrue_part_v_part; // (frac * hybrid - pT part)/(pT part) vs. (pT part)
   TH2D*           h2_resid_mLTrue_det_v_det; // (frac * hybrid - pT det)/(pT det) vs. (pT det)
   TH2D*           h2_resid_det_part_v_part; // (det - part)/part vs. part
   TH2D*           h2_resid_hybrid_part_v_part; // (hybrid - part)/part vs. part
   TH2D*           h2_resid_hybrid_det_v_det; // (hybrid - det)/det vs. det
   TH2D*           h2_resid_hybrid_det_v_part;
   TH2D*           h2_resid_hybrid_det_v_det_RAW; //(hybrid - det) vs det.
   TH2D*           h2_resid_hybrid_tag_v_tag; //(hybrid - det) vs det.
   TH2D*           h2_resid_hybrid_tag_v_tag_RAW; //(hybrid - det) vs det.
   TH2D*           h2_resid_hybrid_mLTrue_v_mLTrue; // (hybrid - mLTrue)/mLTrue vs. mLTrue
   TH2D*           h2_resid_det_mLTrue_v_mLTrue; // (det - mLTrue)/ mLTrue
   TH1D*           h2_event_bkg_density; 
   TH1D*           hybridSpectra;
   TH1D*           detSpectra;
   TH1D*           partSpectra;
   TH2D*           mlResidualPlot;
   TH2D*           mlResidualPlotNaive; // use sum of 8 highest pT tracks instead of ML
   TH2D*           leadingTrackCuts;
   TH2D*           bkgScaleFactorEMCAL;
   TH2D*           bkgScaleFactorEMCALFid;
   TH2D*           diffScaleFactorEMCAL;
   TH2D*           diffScaleFactorEMCALFid; 
   TH2D*           jamesScaleFactor; 
   TH1D*           numJets; 
   std::vector<TH2D*> extractorBinHists;
   std::vector<TH3D*> extractorBinHists3D;


   // List of branches
   TBranch        *b_Jet_Pt;   //!
   TBranch        *b_Jet_Phi;   //!
   TBranch        *b_Jet_Eta;   //!
   TBranch        *b_Jet_Area;   //!
   TBranch        *b_Jet_NumTracks;   //!
   TBranch        *b_Jet_NumClusters;   //!
   TBranch        *b_Event_BackgroundDensity;   //!
   TBranch        *b_Event_BackgroundDensityMass;   //!
   TBranch        *b_Event_Vertex_X;   //!
   TBranch        *b_Event_Vertex_Y;   //!
   TBranch        *b_Event_Vertex_Z;   //!
   TBranch        *b_Event_Centrality;   //!
   TBranch        *b_Event_Multiplicity;   //!
   TBranch        *b_Event_ID;   //!
   TBranch        *b_Event_MagneticField;   //!
   TBranch        *b_Event_PtHard;   //!
   TBranch        *b_Event_Weight;   //!
   TBranch        *b_Event_ImpactParameter;   //!
   TBranch        *b_Jet_Track_Pt;   //!
   TBranch        *b_Jet_Track_Phi;   //!
   TBranch        *b_Jet_Track_Eta;   //!
   TBranch        *b_Jet_Track_Charge;   //!
   TBranch        *b_Jet_Track_Label;   //!
   TBranch        *b_Jet_Cluster_Pt;   //!
   TBranch        *b_Jet_Cluster_E;   //!
   TBranch        *b_Jet_Cluster_Phi;   //!
   TBranch        *b_Jet_Cluster_Eta;   //!
   TBranch        *b_Jet_Cluster_M02;   //!
   TBranch        *b_Jet_Cluster_Time;   //!
   TBranch        *b_Jet_Cluster_Label;   //!
   TBranch        *b_Jet_MC_MotherParton;   //!
   TBranch        *b_Jet_MC_MotherHadron;   //!
   TBranch        *b_Jet_MC_MotherIC;   //!
   TBranch        *b_Jet_MC_MatchedDetLevelJet_Distance;   //!
   TBranch        *b_Jet_MC_MatchedDetLevelJet_Pt;   //!
   TBranch        *b_Jet_MC_MatchedDetLevelJet_Mass;   //!
   TBranch        *b_Jet_MC_MatchedPartLevelJet_Distance;   //!
   TBranch        *b_Jet_MC_MatchedPartLevelJet_Pt;   //!
   TBranch        *b_Jet_MC_MatchedPartLevelJet_Mass;   //!
   TBranch        *b_Jet_MC_TruePtFraction;   //!
   TBranch        *b_Jet_MC_TruePtFraction_PartLevel;   //!
   TBranch        *b_Jet_MC_TruePtFraction_tracks;   //!
   TBranch        *b_Jet_MC_TruePtFraction_clusters;   //!
   TBranch        *b_Tag_DetLevelJet_Pt; //!
   TBranch        *b_Tag_PartLevelJet_Pt; //!


   mLJetPerf(TTree *tree=0);
   virtual ~mLJetPerf();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop(Int_t pTHardBin);
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
   virtual void     Write(TFile* fout);
};

#endif

#ifdef mLJetPerf_cxx
mLJetPerf::mLJetPerf(TTree *tree) : fChain(0)
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("highstatstest_2.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("highstatstest_2.root");
      }
      f->GetObject("JetTree_AliAnalysisTaskJetExtractor_hybridLevelJets_AKTFullR040_tracks_pT0150_caloClustersCombined_E0300_pt_scheme_Rho_Scaled_hybridLevelJets",tree);

   }
   //Init(tree);
}

mLJetPerf::~mLJetPerf()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t mLJetPerf::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t mLJetPerf::LoadTree(Long64_t entry)
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

void mLJetPerf::Init(TTree *tree)
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
   fChain->SetBranchAddress("Jet_Phi", &Jet_Phi, &b_Jet_Phi);
   fChain->SetBranchAddress("Jet_Eta", &Jet_Eta, &b_Jet_Eta);
   fChain->SetBranchAddress("Jet_Area", &Jet_Area, &b_Jet_Area);
   fChain->SetBranchAddress("Jet_NumTracks", &Jet_NumTracks, &b_Jet_NumTracks);
   fChain->SetBranchAddress("Jet_NumClusters", &Jet_NumClusters, &b_Jet_NumClusters);
   fChain->SetBranchAddress("Event_BackgroundDensity", &Event_BackgroundDensity, &b_Event_BackgroundDensity);
   fChain->SetBranchAddress("Event_BackgroundDensityMass", &Event_BackgroundDensityMass, &b_Event_BackgroundDensityMass);
   fChain->SetBranchAddress("Event_Vertex_X", &Event_Vertex_X, &b_Event_Vertex_X);
   fChain->SetBranchAddress("Event_Vertex_Y", &Event_Vertex_Y, &b_Event_Vertex_Y);
   fChain->SetBranchAddress("Event_Vertex_Z", &Event_Vertex_Z, &b_Event_Vertex_Z);
   fChain->SetBranchAddress("Event_Centrality", &Event_Centrality, &b_Event_Centrality);
   fChain->SetBranchAddress("Event_Multiplicity", &Event_Multiplicity, &b_Event_Multiplicity);
   fChain->SetBranchAddress("Event_ID", &Event_ID, &b_Event_ID);
   fChain->SetBranchAddress("Event_MagneticField", &Event_MagneticField, &b_Event_MagneticField);
   fChain->SetBranchAddress("Event_PtHard", &Event_PtHard, &b_Event_PtHard);
   fChain->SetBranchAddress("Event_Weight", &Event_Weight, &b_Event_Weight);
   fChain->SetBranchAddress("Event_ImpactParameter", &Event_ImpactParameter, &b_Event_ImpactParameter);
   fChain->SetBranchAddress("Jet_Track_Pt", Jet_Track_Pt, &b_Jet_Track_Pt);
   fChain->SetBranchAddress("Jet_Track_Phi", Jet_Track_Phi, &b_Jet_Track_Phi);
   fChain->SetBranchAddress("Jet_Track_Eta", Jet_Track_Eta, &b_Jet_Track_Eta);
   fChain->SetBranchAddress("Jet_Track_Charge", Jet_Track_Charge, &b_Jet_Track_Charge);
   fChain->SetBranchAddress("Jet_Track_Label", Jet_Track_Label, &b_Jet_Track_Label);
   fChain->SetBranchAddress("Jet_Cluster_Pt", Jet_Cluster_Pt, &b_Jet_Cluster_Pt);
   fChain->SetBranchAddress("Jet_Cluster_E", Jet_Cluster_E, &b_Jet_Cluster_E);
   fChain->SetBranchAddress("Jet_Cluster_Phi", Jet_Cluster_Phi, &b_Jet_Cluster_Phi);
   fChain->SetBranchAddress("Jet_Cluster_Eta", Jet_Cluster_Eta, &b_Jet_Cluster_Eta);
   fChain->SetBranchAddress("Jet_Cluster_M02", Jet_Cluster_M02, &b_Jet_Cluster_M02);
   fChain->SetBranchAddress("Jet_Cluster_Time", Jet_Cluster_Time, &b_Jet_Cluster_Time);
   fChain->SetBranchAddress("Jet_Cluster_Label", Jet_Cluster_Label, &b_Jet_Cluster_Label);
   fChain->SetBranchAddress("Jet_MC_MotherParton", &Jet_MC_MotherParton, &b_Jet_MC_MotherParton);
   fChain->SetBranchAddress("Jet_MC_MotherHadron", &Jet_MC_MotherHadron, &b_Jet_MC_MotherHadron);
   fChain->SetBranchAddress("Jet_MC_MotherIC", &Jet_MC_MotherIC, &b_Jet_MC_MotherIC);
   fChain->SetBranchAddress("Jet_MC_MatchedDetLevelJet_Distance", &Jet_MC_MatchedDetLevelJet_Distance, &b_Jet_MC_MatchedDetLevelJet_Distance);
   fChain->SetBranchAddress("Jet_MC_MatchedDetLevelJet_Pt", &Jet_MC_MatchedDetLevelJet_Pt, &b_Jet_MC_MatchedDetLevelJet_Pt);
   fChain->SetBranchAddress("Jet_MC_MatchedDetLevelJet_Mass", &Jet_MC_MatchedDetLevelJet_Mass, &b_Jet_MC_MatchedDetLevelJet_Mass);
   fChain->SetBranchAddress("Jet_MC_MatchedPartLevelJet_Distance", &Jet_MC_MatchedPartLevelJet_Distance, &b_Jet_MC_MatchedPartLevelJet_Distance);
   fChain->SetBranchAddress("Jet_MC_MatchedPartLevelJet_Pt", &Jet_MC_MatchedPartLevelJet_Pt, &b_Jet_MC_MatchedPartLevelJet_Pt);
   fChain->SetBranchAddress("Jet_MC_MatchedPartLevelJet_Mass", &Jet_MC_MatchedPartLevelJet_Mass, &b_Jet_MC_MatchedPartLevelJet_Mass);
   fChain->SetBranchAddress("Jet_MC_TruePtFraction", &Jet_MC_TruePtFraction, &b_Jet_MC_TruePtFraction);
   fChain->SetBranchAddress("Jet_MC_TruePtFraction_PartLevel", &Jet_MC_TruePtFraction_PartLevel, &b_Jet_MC_TruePtFraction_PartLevel);
   
   // set sumw2 for the weightings
   TH1::SetDefaultSumw2();
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

   linCorrelation                   = new TH2D("linCorrelation", "Detector Level p_{T} vs. ML True p_{T}", 400,0,400,400,0,400);
   linCorrelationPartLevel          = new TH2D("linCorrelationPartLevel", "Particle Level p_{T} vs. ML True p_{T}",17,35,120,13,xbins);
   hybridDetResp                    = new TH2D("hybridDetResp", "",1000,0,400,1000,0,400);
   mLTruePartResp                   = new TH2D("mLTruePartResp", "",1000,0,400,1000,0,400);
   mLTrueDetResp                    = new TH2D("mLTrueDetResp", "",1000,0,400,1000,0,400);
   mLTrueHybridResp                 = new TH2D("mLTrueHybridResp" ,"", 1000, 0, 400, 1000, 0, 400);
   tagHybridResp                    = new TH2D("tagHybridResp" ,"", 1000, 0, 400, 1000, 0, 400);
   partTagResp                      = new TH2D("partTagResp", "",1000,0,400,1000,0,400);
   h2_det_mLTrue_v_mLTrue           = new TH2D("h2_det_mLTrue_v_mLTrue", "#frac{Detector Level p_{T}}{ML True p_{T}} vs. ML True p_{T}", 100,0,100,1000,-40,40);
   h2_mLTrue_det_v_det              = new TH2D("h2_mLTrue_det_v_det","#frac{ML True p_{T}}{Detector Level p_{T}} vs. Detector Level p_{T}",100,0,100,1000,-40,40);
   h2_resid_mLTrue_part_v_part      = new TH2D("h2_resid_mLTrue_part_v_part","#frac{ML True p_{T} - Particle Level p_{T}}{Particle Level p{T}} vs. Particle Level p{T}",100,0,500,1000,-40,40);
   h2_resid_mLTrue_det_v_det        = new TH2D("h2_resid_mLTrue_det_v_det","#frac{ML True p_{T} - Detector Level p_{T}}{DetectorLevel p{T}} vs. Detector Level p{T}",100,0,500,1000,-40,40);
   h2_resid_det_part_v_part         = new TH2D("h2_resid_det_part_v_part", "#frac{Detector Level p_{T} - Particle Level p_{T}}{Particle Level p{T}} vs. Particle Level p{T}", 100, 0,500, 1000, -10,10);
   h2_resid_hybrid_part_v_part      = new TH2D("h2_resid_hybrid_part_v_part", "#frac{Hybrid p_{T} - Particle Level p_{T}}{Particle Level p{T}} vs. Particle Level p{T}", 100, 0,500, 1000, -10,10);
   h2_resid_hybrid_det_v_det        = new TH2D("h2_resid_hybrid_det_v_det", "#frac{Hybrid p_{T} - Detector Level p_{T}}{Detector Level p_{T}} vs. Detector Level p_{T}", 100, 0,500, 1000, -10,10);
   h2_resid_hybrid_det_v_part       = new TH2D("h2_resid_hybrid_det_v_part", "", 100, 0,500, 1000, -10,10);

   h2_resid_hybrid_det_v_det_RAW    = new TH2D("h2_resid_hybrid_det_v_det_RAW", "Hybrid p_{T} - Detector Level p_{T} vs. Detector Level p_{T}", 100, 0,500, 1000, -60,60);
   h2_resid_hybrid_tag_v_tag        = new TH2D("h2_resid_hybrid_tag_v_tag", "", 100, 0,500, 1000, -10,10);
   h2_resid_hybrid_tag_v_tag_RAW    = new TH2D("h2_resid_hybrid_tag_v_tag_RAW", "", 100, 0,500, 1000, -60,60);
   h2_resid_hybrid_mLTrue_v_mLTrue  = new TH2D("h2_resid_hybrid_mLTrue_v_mLTrue", "", 100, 0,200, 1000, -10,10);
   h2_resid_det_mLTrue_v_mLTrue     = new TH2D("h2_resid_det_mLTrue_v_mLTrue", "", 100, 0,200, 1000, -10,10);
   h2_event_bkg_density             = new TH1D("event_bkg", "event_bkg",1000, 0, 500);
   mlResidualPlot                   = new TH2D("mLResidualPlot", "ml Resiudal Plot", 201, -60, 140, 25, 0, 125);
   mlResidualPlotNaive              = new TH2D("mLResidualPlotNaive", "Naive Residual", 120, -60, 61, 25, 0, 120);
   leadingTrackCuts                 = new TH2D("leadingTrackCuts", "Jets Rejected by 5 GeV Leading Track Cut", 100, 0,200, 1000, -10,10);
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
   bkgScaleFactorEMCAL         = new TH2D("bkgScaleFactorEMCAL", "", 50,0,50,100,0,5);
   bkgScaleFactorEMCALFid      = new TH2D("bkgScaleFactorEMCALFid", "", 50,0,50,100,0,5);
   diffScaleFactorEMCAL        = new TH2D("diffScaleFactorEMCAL", "", 100,0,500,1000, -40,40);
   diffScaleFactorEMCALFid     = new TH2D("diffScaleFactorEMCALFid", "", 100,0,500,1000, -40,40);
   jamesScaleFactor            = new TH2D("jamesScaleFactor", "", 100,0,50, 100, 0, 10); 
   numJets                     = new TH1D("numJets", "Number of Jets in Event", 10,0,10); 
   Notify();
}


Bool_t mLJetPerf::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void mLJetPerf::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
//additional write class to write the histograms to a file
void mLJetPerf::Write(TFile* fout)
{
  linCorrelation->Write();
  linCorrelationPartLevel->Write();
  hybridDetResp->Write();
  mLTruePartResp->Write();
  mLTrueDetResp->Write();
  mLTrueHybridResp->Write();
  tagHybridResp->Write();
  partTagResp->Write();
  h2_det_mLTrue_v_mLTrue->Write();
  h2_mLTrue_det_v_det->Write();
  h2_resid_mLTrue_part_v_part->Write();
  h2_resid_mLTrue_det_v_det->Write();
  h2_resid_det_part_v_part->Write();
  h2_resid_hybrid_part_v_part->Write();
  h2_resid_hybrid_det_v_det->Write();
  h2_resid_hybrid_det_v_part->Write();
  h2_resid_hybrid_det_v_det_RAW->Write();
  h2_resid_hybrid_tag_v_tag->Write();
  h2_resid_hybrid_tag_v_tag_RAW->Write();
  h2_resid_hybrid_mLTrue_v_mLTrue->Write();
  h2_resid_det_mLTrue_v_mLTrue->Write();
  h2_event_bkg_density->Write();
  mlResidualPlot->Write();
  mlResidualPlotNaive->Write();
  leadingTrackCuts->Write();
  hybridSpectra->Write();
  detSpectra->Write();
  partSpectra->Write();
  bkgScaleFactorEMCAL->Write();
  bkgScaleFactorEMCALFid->Write();
  diffScaleFactorEMCAL->Write();
  diffScaleFactorEMCALFid->Write();
  jamesScaleFactor->Write();
  for (Int_t i = 0; i< extractorBinHists.size(); i++) extractorBinHists.at(i)->Write();
  for (Int_t k = 0; k< extractorBinHists3D.size(); k++) extractorBinHists3D.at(k)->Write();
  numJets->Write(); 
  fout->Close(); 
}

Int_t mLJetPerf::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}

#endif // #ifdef mLJetPerf_cxx
