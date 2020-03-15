
/*
Hannah Bossi <hannah.bossi@yale.edu>
mLJetPerf.C - Plot relevant jet performance quantities from the tree.
5/8/2019
 */


#define mLJetPerf_cxx
#include "mLJetPerf.h"
#include <TH2.h>
#include <TH2D.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <sstream>
#include <iostream>
#include <math.h>

void mLJetPerf::Loop(Int_t pTHardBin)
{
//   In a ROOT session, you can do:
//      root> .L mLJetPerf.C
//      root> mLJetPerf t
//      root> t.GetEntry(12); // Fill t data members with entry number 12
//      root> t.Show();       // Show values of entry 12
//      root> t.Show(16);     // Read and show values of entry 16
//      root> t.Loop();       // Loop on all entries
//

//     This is the loop skeleton where:
//    jentry is the global entry number in the chain
//    ientry is the entry number in the current Tree
//  Note that the argument to GetEntry must be:
//    jentry for TChain::GetEntry
//    ientry for TTree::GetEntry and TBranch::GetEntry
//
//       To read only selected branches, Insert statements like:
// METHOD1:
//    fChain->SetBranchStatus("*",0);  // disable all branches
//    fChain->SetBranchStatus("branchname",1);  // activate branchname
// METHOD2: replace line
//    fChain->GetEntry(jentry);       //read all branches
//by  b_branchname->GetEntry(ientry); //read only this branch
   if (fChain == 0) return;

   Long64_t nentries = fChain->GetEntriesFast();
   Long64_t nbytes = 0, nb = 0;
   Double_t pTHardOutlierCount = 0;
   Int_t event = 0;
   Int_t numJetsInEvent = 0; 
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      if (Cut(ientry) < 0) continue;
      if (nb == 0) continue;

      // ====================================== Hard Coded Parameters =======================================                                                        
      // Edit these to make easy edits to vary the configuration for running this~                                                                                   
      Double_t jetRadius            = 0.4;
      Bool_t useDerivedScaling      = kFALSE; // by default, use James's scaling.
      Bool_t jamesCuts              = kTRUE; // LTC, area cut, max track pT cut
      Bool_t outlierRemoval         = kFALSE; // use Nico's cut, can edit
      Double_t jetMatchingRMult     = 0.75; // multiplying factor to specify the matching radius (markus uses 0.6, James uses 1.5)
      Bool_t doCentral              = kTRUE; // if we want to look at central collisions only
      Bool_t doSemiCentral          = kFALSE; // if we are looking at semi central collisions only
      Bool_t doPtFracCuts           = kFALSE; // do a cut on the pT fraction
      Bool_t doCutThreshold         = kTRUE;
      Double_t cutThreshold         = 10; 
      // =====================================================================================================
      // helper variables
      Double_t jetPtRaw           = Jet_Pt + (Jet_Area*Event_BackgroundDensity);
      Double_t mLTrue             = jetPtRaw*Jet_MC_TruePtFraction;
      Double_t mLTruePart         = jetPtRaw*Jet_MC_TruePtFraction_PartLevel;
      Double_t detLevelPt         = Jet_MC_MatchedDetLevelJet_Pt;
      Double_t partLevelPt        = Jet_MC_MatchedPartLevelJet_Pt;
      Double_t detLevelDistance   = Jet_MC_MatchedDetLevelJet_Distance;
      Double_t partLevelDistance  = Jet_MC_MatchedPartLevelJet_Distance;
      Double_t hybridPt           = Jet_Pt;
      Double_t jetPhi             = Jet_Phi;
      Double_t bkg                = Event_BackgroundDensity;
      Double_t cent               = Event_Centrality;
      Double_t relMatchDist       = abs(detLevelDistance - partLevelDistance);
      Double_t tagDetPt           = 0;
      Double_t tagPartPt          = 0;
      Int_t eventID               = Event_ID;

      // if we are not on the current event, change it to be a new one
      if (event != eventID){
	// before we change to a new event, fill histogram with number of events
	numJets->Fill(numJetsInEvent);
	// reset variables for new event

	// reset number of jets
	if(jetPtRaw > 40){
	  numJetsInEvent = 1;
	}
	else{
	  numJetsInEvent = 0; 
	}
	//reset the event ID
	event = eventID; 
      }
      // handle the case where we got the same event
      else{
	if(jetPtRaw > 40)numJetsInEvent++; 
      }
      
      // Hard Coded Parameters, will change with dataset or train run. 
      // Scaling Factors from James's Thesis - version1
      //Double_t scalingFactors[20] = {0.3471,0.2978,0.2888,0.1894,0.9596e-02,4.613e-02,1.619e-02,5.920e-03,2.547e-03,8.795e-04,3.517e-04,1.272e-04,6.276e-05,2.956e-05,1.452e-05,7.395e-06,3.955e-06,2.111e-06,1.141e-06,1.472e-06};
      
      //Double_t scalingFactors[20] = {0.49823, 0.419338, 0.406802, 0.26736, 0.135491, 0.0648489, 0.0227926, 0.00833077, 0.00357103, 0.00123511, 0.000493196, 0.000178082, 8.83187e-05, 4.14842e-05, 2.03896e-05, 1.04089e-05, 5.67134e-06, 2.97871e-06, 1.60231e-06,  2.09544e-06};
      // 01/13/20 ->> Double_t scalingFactors[20] = {0.461937, 0.3833, 0.37015, 0.240879, 0.123483, 0.0598, 0.0213369, 0.00785, 0.0033, 0.0015, 0.000640, 0.00100258, 8.47e-05, 3.962e-05, 1.89e-05, 9.511e-06, 5.295e-06, 2.707e-06, 1.706e-6,1.90218e-06};

      //for 02/14/20
      Double_t scalingFactors[20] = {0.492069, 0.418282, 0.405473, 0.265289, 0.133235, 0.0642945, 0.0229219, 0.008419, 0.00360539, 0.00122459, 0.000494578, 0.000177912, 8.83422e-05, 4.28423e-05, 2.03583e-05, 1.03874e-05, 5.68744e-06, 2.99194e-06, 1.59651e-06, 2.09335e-06};
      if(doPtFracCuts){
	std::cout << "SharedPtFractionProxy: " <<  (mLTrue/detLevelPt) << std::endl;
	if((mLTrue/detLevelPt) < 0.5) continue;
      }
      
      //if(partLevelDistance > jetMatchingRMult*jetRadius) continue;
      //if(detLevelDistance > jetMatchingRMult*jetRadius) continue;
      //Double_t rk[20] = {0.927, 0.914726, 0.909407, 0.91052, 0.91174, 0.923953, 0.935913, 0.942202, 0.936318, 1.21868, 1.2974, 5.62968, 0.959218, 0.955226, 0.927182, 0.913661, 0.933941, 0.908, 1.065, 0.908}; 
      Double_t rk[20] = {1., 1., 1., 1., 1., 1., 1., 1., 1., 1., 1., 1., 1., 1., 1., 1., 1., 1., 1., 1.}; 
      Double_t pTHardBins[21]     = {5,7,9,12,16,21,28,36,45,57,70,85,99,115,132,150,169,190,212,235,1000};
      Double_t extractorBins[10]  = {-20,0,10,20,40,60,80,100,150,200};
      Double_t scalingPercents[9] = {200,142.87, 125,20,12.5, 6.66, 3.33,2.5,2};    
      Double_t scale = 0;

      //if(partLevelPt < 10) continue;
      //if(detLevelPt > 120) continue;
      
      if(jamesCuts){
	// ================================ Area Cut ==========================================================
	if( Jet_Area < 0.3016){
	  continue;
	}
      
	//  ================================= Implement track cuts  =======================================
	Int_t    numTracks           = Jet_NumTracks;
	Bool_t   passedMaxPtCut      = true;  // assume it has no tracks above 100 GeV
	Bool_t   debugLTC            = false;
	Double_t minTrackPt          = 0;
	if(jetRadius == 0.2){
	  minTrackPt = 5; 
	}
	else if(jetRadius == 0.4){
	  minTrackPt = 7; 
	}
	else{
	  std::cout << "Error: Did not recognize jet radius, leading track cut not being applied!" << std::endl;
	}
	Double_t maxPt = 0;
	for(Int_t index = 0; index < numTracks; index++){
	  if(Jet_Track_Pt[index] > maxPt){
	    maxPt = Jet_Track_Pt[index]; 
	  }
	  
	  if(Jet_Track_Pt[index] > 100){
	    passedMaxPtCut = false;
	    break;
	  }
	  
	}
	if(maxPt < minTrackPt){
	  //std::cout << "Jet with pT of: " << hybridPt << "rejected with a max pT of" << maxPt <<std::endl;
	  continue;
	}
      }// end jamesCuts

      
      // ======================================== Extractor Bin Scaling=============================================================
      // scale factor explicitly defined as 1/ExtracPercentage -> Can be different for different running configurations.
      
      // ======================================= 02/14/2020 Train Run Scalings   ===================================================
      if(jetRadius == 0.2){
	if(hybridPt >= -20 && hybridPt < 0)        scale = 200;
	else if(hybridPt >=0 && hybridPt < 10)     scale = 125;
	else if(hybridPt >= 10 && hybridPt < 20)   scale = 100;
	else if(hybridPt >= 20 && hybridPt < 40)   scale = 2.857;
	else if(hybridPt >= 40 && hybridPt < 60)   scale = 2.5;
	else if(hybridPt >= 60 && hybridPt < 80)   scale = 2;
	else if(hybridPt >= 80 && hybridPt < 100)  scale = 1.429;
	else if(hybridPt >= 100 && hybridPt < 150) scale = 1.25;
	else if(hybridPt >= 150 && hybridPt < 500) scale = 1.111; 
	else{
	  std::cout << "Jet found outside desired pT range, scale factor not being applied." << std::endl;
	}
      }
      else if(jetRadius == 0.4){
	if(hybridPt >= -20 && hybridPt < 10)       scale = 10;
	else if(hybridPt >= 10 && hybridPt < 20)   scale = 10;
	else if(hybridPt >= 20 && hybridPt < 40)   scale = 2.5;
	else if(hybridPt >= 40 && hybridPt < 60)   scale = 1.25;
	else if(hybridPt >= 60 && hybridPt < 80)   scale = 1.111;
	else if(hybridPt >= 80 && hybridPt < 100)  scale = 1.111;
	else if(hybridPt >= 100 && hybridPt < 500) scale = 1.0;
	else{
	  std::cout << "Jet found outside desired pT range, scale factor not being applied." << std::endl;
	}
      }
      else{
	std::cout<< "Did not recognize jet radius, scaling factors not being applied" <<std::endl;
      }      
      
      // Make Centrality Selection if Needed
      if(doCentral){
	if(!(cent < 10)) continue; 
      }
      if(doSemiCentral){
	if(cent < 30) continue;
      }

      if(outlierRemoval){
	// nico cuts, not standard
	if ( partLevelPt < 0.25*pTHardBins[pTHardBin]){
	  continue;
	}
      }
     
      


      // ========================================== Fill the plots ===================================================
      if(detLevelPt != 0 && detLevelDistance < (jetRadius*jetMatchingRMult) && partLevelDistance < (jetRadius*jetMatchingRMult) && partLevelPt != 0){
	linCorrelation->Fill(detLevelPt,partLevelPt,scalingFactors[pTHardBin-1]*scale*rk[pTHardBin-1]);
      }

      if(mLTruePart != 0){
	mLTruePartResp->Fill(hybridPt,mLTruePart,scalingFactors[pTHardBin-1]*scale*rk[pTHardBin-1]);
      }

      if(mLTrue != 0 && mLTruePart != 0){
	mLTrueDetResp->Fill(mLTrue,mLTruePart,scalingFactors[pTHardBin-1]*scale*rk[pTHardBin-1]);
      }

      if(mLTrue != 0 && hybridPt != 0){
        mLTrueHybridResp->Fill(hybridPt,mLTrue,scalingFactors[pTHardBin-1]*scale*rk[pTHardBin-1]);
      }

      
      if(partLevelPt != 0 && partLevelDistance < (jetRadius*jetMatchingRMult) && detLevelDistance < (jetRadius*jetMatchingRMult) && hybridPt != 0){
	linCorrelationPartLevel->Fill(hybridPt, partLevelPt, scalingFactors[pTHardBin-1]*scale*rk[pTHardBin-1] );
      }
     
      if(detLevelPt !=0 && detLevelDistance < (jetRadius*jetMatchingRMult) && hybridPt != 0){
	hybridDetResp->Fill(hybridPt,detLevelPt, scalingFactors[pTHardBin-1]*scale*rk[pTHardBin-1]);
      }      
      // fractional residual
      if(detLevelPt != 0 && detLevelDistance < (jetRadius*jetMatchingRMult) && mLTrue != 0){
        h2_det_mLTrue_v_mLTrue->Fill(mLTrue, (detLevelPt/mLTrue), scalingFactors[pTHardBin-1]*scale*rk[pTHardBin-1]);
      }
      
      // reciporical fractional distribution
      if(detLevelPt != 0 && detLevelDistance < (jetRadius*jetMatchingRMult) && mLTrue != 0){
        h2_mLTrue_det_v_det->Fill( detLevelPt, (mLTrue/detLevelPt),scalingFactors[pTHardBin-1]*scale*rk[pTHardBin-1]);
      }

      // truth detector residual
      if(detLevelPt != 0 && detLevelDistance < (jetRadius*jetMatchingRMult) && mLTrue != 0){
        h2_resid_mLTrue_det_v_det->Fill( detLevelPt, (mLTrue-detLevelPt)/detLevelPt,scalingFactors[pTHardBin-1]*scale*rk[pTHardBin-1]);
      }

      // true part residual
      if(partLevelPt != 0 && partLevelDistance < (jetRadius*jetMatchingRMult) && mLTrue != 0){
        h2_resid_mLTrue_part_v_part->Fill( partLevelPt,(mLTrue-partLevelPt)/partLevelPt, scalingFactors[pTHardBin-1]*scale*rk[pTHardBin-1]);
      }

      // det part resid
      if(partLevelPt != 0 && detLevelPt != 0 && partLevelDistance < (jetRadius*jetMatchingRMult) && detLevelDistance < (jetRadius*jetMatchingRMult)){
        h2_resid_det_part_v_part->Fill( partLevelPt,(detLevelPt - partLevelPt)/partLevelPt, scalingFactors[pTHardBin-1]*scale*rk[pTHardBin-1]);
      }
     
      // require that we find a particle level match
      if(partLevelPt != 0 && partLevelDistance < (jetRadius*jetMatchingRMult) && hybridPt != 0){
        h2_resid_hybrid_part_v_part->Fill(partLevelPt, (hybridPt - partLevelPt)/partLevelPt, scalingFactors[pTHardBin-1]*scale*rk[pTHardBin-1]);
      }


      if(detLevelPt != 0 && detLevelDistance < (jetRadius*jetMatchingRMult)){
        h2_resid_hybrid_det_v_det->Fill(detLevelPt, (hybridPt - detLevelPt)/detLevelPt, scalingFactors[pTHardBin-1]*scale*rk[pTHardBin-1]);
      }
      if(detLevelPt != 0 && detLevelDistance < (jetRadius*jetMatchingRMult) && partLevelDistance < (jetRadius*jetMatchingRMult)){
        h2_resid_hybrid_det_v_part->Fill(partLevelPt, (hybridPt - detLevelPt)/detLevelPt, scalingFactors[pTHardBin-1]*scale*rk[pTHardBin-1]);
      }

       if(detLevelPt != 0 && detLevelDistance < (jetRadius*jetMatchingRMult)){
        h2_resid_hybrid_det_v_det_RAW->Fill(detLevelPt, (hybridPt - detLevelPt), scalingFactors[pTHardBin-1]*scale*rk[pTHardBin-1]);
      }

      if(mLTrue != 0){
        h2_resid_hybrid_mLTrue_v_mLTrue->Fill(mLTrue, (hybridPt - mLTrue)/mLTrue, scalingFactors[pTHardBin -1]*scale*rk[pTHardBin-1]);
      }

      if(mLTrue != 0 && detLevelPt != 0 && detLevelDistance < (jetRadius*jetMatchingRMult)){
        h2_resid_det_mLTrue_v_mLTrue->Fill(mLTrue, (detLevelPt-mLTrue)/mLTrue, scalingFactors[pTHardBin-1]*scale*rk[pTHardBin-1]);
      }

      h2_event_bkg_density->Fill(bkg, scalingFactors[pTHardBin-1]*scale*rk[pTHardBin-1]);
      // get the naive ML
      int n = sizeof(Jet_Track_Pt)/sizeof(Jet_Track_Pt[0]);
      Double_t pTSum = 0; 
      std::sort(Jet_Track_Pt, Jet_Track_Pt+n, greater<int>());
      for(Int_t index = 0; index < 8; index++){
	pTSum += Jet_Track_Pt[index];
      }
      mlResidualPlotNaive->Fill((pTSum - detLevelPt), detLevelPt, scalingFactors[pTHardBin -1]*scale*rk[pTHardBin-1]);
      
      if(detLevelPt != 0 && partLevelPt>10){
	mlResidualPlot->Fill((hybridPt - detLevelPt), detLevelPt, scalingFactors[pTHardBin -1]*scale);
	float pthis[6] = {-20, 20, 40, 60, 100, 500};
	for (Int_t i = 0; i < extractorBinHists.size(); i++){
	   if ((hybridPt < pthis[i]) || (hybridPt > pthis[i+1])) continue;
	   extractorBinHists.at(i)->Fill((hybridPt - detLevelPt), detLevelPt);
	}
	for (Int_t k = 0; k < extractorBinHists3D.size(); k++){
           if ((hybridPt < pthis[k]) || (hybridPt > pthis[k+1])) continue;
           extractorBinHists3D.at(k)->Fill((hybridPt - detLevelPt), detLevelPt, partLevelPt);
        }
      }

      // don't scale by extractor bins
      hybridSpectra->Fill(hybridPt,scale*scalingFactors[pTHardBin -1]*rk[pTHardBin-1]);      
      detSpectra->Fill(detLevelPt,scale*scalingFactors[pTHardBin -1]*rk[pTHardBin-1]);
      partSpectra->Fill(partLevelPt,scale*scalingFactors[pTHardBin -1]*rk[pTHardBin-1]);



      // ==================== Fill Tagging Histograms ====================================
      if(tagDetPt != 0 && hybridPt >30){
	tagHybridResp->Fill(hybridPt,tagDetPt, scalingFactors[pTHardBin-1]*scale*rk[pTHardBin-1]);
	partTagResp->Fill(tagDetPt, tagPartPt, scalingFactors[pTHardBin-1]*scale*rk[pTHardBin-1]);
	h2_resid_hybrid_tag_v_tag->Fill(tagDetPt, (hybridPt - tagDetPt)/tagDetPt, scalingFactors[pTHardBin-1]*scale);
	h2_resid_hybrid_tag_v_tag_RAW->Fill(tagDetPt, (hybridPt - tagDetPt), scalingFactors[pTHardBin-1]*scale);
      }

      // ========================  Fill Scaling Factor histograms ===========================
      // The purpose of this section is to compare two different scaling factors
      // (1) The scaling factor calculated using James's function
      // (2) The scaling factor directly calculated from out data.

      // First define acceptance boundaries
      Double_t etaTPC      = 0.9;
      Double_t etaEMCAL    = 0.7;
      Double_t phiMinEMCAL = 1.396;
      Double_t phiMaxEMCAL = 3.28122;

      // define the acceptances
      Double_t accTPC      = 2 * etaTPC * 2 * 3.1415926535;
      Double_t accEMCAL    = 2 * etaEMCAL * (phiMaxEMCAL - phiMinEMCAL); 

      // now define the fiducial acceptance boundaries
      Double_t etaEMCALFid       = 0.7 - jetRadius;
      Double_t phiMinEMCALFid    = phiMinEMCAL + jetRadius;
      Double_t phiMaxEMCALFid    = phiMaxEMCAL - jetRadius;

      // define the fiducial acceptance of the EMCAL
      Double_t accEMCALFid = 2 * etaEMCALFid * (phiMaxEMCALFid - phiMinEMCALFid);

      // initialize variables to get the sum
      Double_t trackPtSumTPC        = 0;
      Double_t trackPtSumEMCAL      = 0;
      Double_t trackPtSumEMCALFid   = 0;
      Double_t clusPtSumTPC         = 0;
      Double_t clusPtSumEMCAL       = 0;
      Double_t clusPtSumEMCALFid    = 0;

      // perform the track loop
      Int_t    numTracks           = Jet_NumTracks;
      for(Int_t i = 0; i < numTracks; i++){
	Double_t trackEta = TMath::Abs(Jet_Track_Eta[i]);
	Double_t trackPhi = Jet_Track_Phi[i];
	Double_t trackPt = Jet_Track_Pt[i];
	if(trackEta < etaTPC ){
	  trackPtSumTPC += trackPt;
	}
	if (trackEta < etaEMCALFid && (trackPhi > phiMinEMCALFid) && (trackPhi < phiMaxEMCALFid)){
	  trackPtSumEMCALFid += trackPt;
	}
        if(trackEta < etaEMCAL && trackPhi > phiMinEMCAL && trackPhi < phiMaxEMCAL){
	  trackPtSumEMCAL += trackPt;
	}
      }

      // perform the cluster loop
      Int_t numClusters = Jet_NumClusters;
      for(Int_t i = 0; i < numClusters; i++){
	Double_t clusEta = TMath::Abs(Jet_Cluster_Eta[i]);
	Double_t clusPhi = Jet_Cluster_Phi[i];
	Double_t clusPt  = Jet_Cluster_Pt[i]; 
        if(clusEta < etaTPC ){
	  clusPtSumTPC += clusPt;
	}
	if((clusEta < etaEMCALFid) && (clusPhi > phiMinEMCALFid) && (clusPhi < phiMaxEMCALFid)){
	  clusPtSumEMCALFid += clusPt;
	}
	if((clusEta < etaEMCAL) && (clusPhi > phiMinEMCAL) && (clusPhi < phiMaxEMCAL)){
	  clusPtSumEMCAL += clusPt;
	}
      }

      /*
      std::cout << "trackPtSumTPC: " << trackPtSumTPC << std::endl;
      std::cout << "trackPtSumEMCAL: " << trackPtSumEMCAL << std::endl;
      std::cout << "trackPtSumEMCALFid: " << trackPtSumEMCALFid << std::endl;
      std::cout << "clusPtSumEMCAL: " << clusPtSumEMCAL << std::endl;
      std::cout << "clusPtSumEMCALFid: " << clusPtSumEMCALFid << std:: endl;
      */
      // std::cout << "EMCAL acceptance: " << accEMCAL << std::endl;
      //std::cout << "EMCAL acceptance Fid: " << accEMCALFid << std::endl;
      // calculate the scale factor for each of the three cases
      Double_t scaleFactorEMCAL         = (trackPtSumEMCAL + clusPtSumEMCAL)/ (trackPtSumTPC);
      Double_t scaleFactorEMCALFid	= (trackPtSumEMCALFid + clusPtSumEMCALFid)/ (trackPtSumTPC);

      

      // calculate james's scale factor as a function of centrality
      Double_t jamesScaleFactorNum = 1.36908 - (0.003274*cent) + (0.000049*cent*cent); 
      jamesScaleFactor->Fill(cent, jamesScaleFactorNum, scalingFactors[pTHardBin -1]*scale*rk[pTHardBin-1]); 

      // fill the histograms
      bkgScaleFactorEMCAL->Fill( cent,scaleFactorEMCAL,  scalingFactors[pTHardBin -1]*scale*rk[pTHardBin-1]);
      bkgScaleFactorEMCALFid->Fill(cent, scaleFactorEMCALFid,scalingFactors[pTHardBin -1]*scale*rk[pTHardBin-1] );
      diffScaleFactorEMCAL->Fill(tagDetPt, (scaleFactorEMCAL- jamesScaleFactorNum)*bkg*Jet_Area, scalingFactors[pTHardBin -1]*scale*rk[pTHardBin-1]);
      diffScaleFactorEMCALFid->Fill(tagDetPt, (scaleFactorEMCALFid- jamesScaleFactorNum)*bkg*Jet_Area, scalingFactors[pTHardBin -1]*scale*rk[pTHardBin-1]);

      
      // Perform the cuts on the extraction histograms if that is applicalble
      /*
      if(doCutThreshold && (jentry == (nentries -1))){
        for(Int_t i = 0; i < extractorBinHists.size(); i++){
          for(Int_t x = 0; x <  extractorBinHists.at(i)->GetNbinsX(); x++ ){
	    for(Int_t y = 0; y < extractorBinHists.at(i)->GetNbinsY(); y++){
	      if (extractorBinHists.at(i)->GetBinContent(x,y) != 0)std::cout << "bin content: " << extractorBinHists.at(i)->GetBinContent(x,y) << std::endl; 
	      if(extractorBinHists.at(i)->GetBinContent(x,y) < (cutThreshold*scalingFactors[pTHardBin-1])){
		if (extractorBinHists.at(i)->GetBinContent(x,y) != 0)std::cout << "rejecting" << std::endl; 
		extractorBinHists.at(i)->SetBinContent(x,y, 0.0);
	      }
	    }
	  }// end loop over bins                                                                                                   
	}// end loop over extractor bin hists                                                                                      
      }// end doCutThreshold
      */
   }
}


