#define neuralNetPredictions_cxx
#include "neuralNetPredictions.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>

void neuralNetPredictions::Loop()
{
//   In a ROOT session, you can do:
//      root> .L neuralNetPredictions.C
//      root> neuralNetPredictions t
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
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      // if (Cut(ientry) < 0) continue;
      if (Cut(ientry) < 0) continue;
      if (nb == 0) continue;
       // ====================================== Hard Coded Parameters =======================================                                                    \


      // Edit these to make easy edits to vary the configuration for running this~                                                                               \
                                                                                                                                                                  
      Double_t jetRadius            = 0.4;
      Bool_t useDerivedScaling      = kFALSE; // by default, use James's scaling.                                                                                 
      Bool_t jamesCuts              = kFALSE; // LTC, area cut, max track pT cut                                                                                  
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
      Double_t detLevelPt         = Jet_MC_MatchedDetLevelJet_Pt;
      Double_t partLevelPt        = Jet_MC_MatchedPartLevelJet_Pt;
      Double_t detLevelDistance   = Jet_MC_MatchedDetLevelJet_Distance;
      Double_t partLevelDistance  = Jet_MC_MatchedPartLevelJet_Distance;
      Double_t hybridPt           = Jet_Pt;
      Double_t ptRec              = Predicted_Jet_Pt; 
      Double_t jetPhi             = Jet_Phi;
      Double_t bkg                = Event_BackgroundDensity;
      Double_t cent               = Event_Centrality;
      Double_t relMatchDist       = abs(detLevelDistance - partLevelDistance);
      Double_t tagDetPt           = 0;
      Double_t tagPartPt          = 0;
      Long64_t pTHardBin          = PtHardBin;

      Double_t scalingFactors[20] = {0.492069, 0.418282, 0.405473, 0.265289, 0.133235, 0.0642945, 0.0229219, 0.008419, 0.00360539, 0.00122459, 0.000494578, 0.000177912, 8.83422e-05, 4.28423e-05, 2.03583e-05, 1.03874e-05, 5.68744e-06, 2.99194e-06, 1.59651e-06, 2.09335e-06};
      Double_t rk[20] = {1., 1., 1., 1., 1., 1., 1., 1., 1., 1., 1., 1., 1., 1., 1., 1., 1., 1., 1., 1.};
      Double_t pTHardBins[21]     = {5,7,9,12,16,21,28,36,45,57,70,85,99,115,132,150,169,190,212,235,1000};
      Double_t extractorBins[10]  = {-20,0,10,20,40,60,80,100,150,200};
      Double_t scalingPercents[9] = {200,142.87, 125,20,12.5, 6.66, 3.33,2.5,2};
      Double_t scale = 0;


      if(partLevelPt < 10) continue;

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

      // ========================================== Fill the plots ===================================================                                                               
      if(detLevelPt != 0 && detLevelDistance < (jetRadius*jetMatchingRMult) && partLevelDistance < (jetRadius*jetMatchingRMult) && partLevelPt != 0){
        linCorrelation->Fill(detLevelPt,partLevelPt,scalingFactors[pTHardBin-1]*scale*rk[pTHardBin-1]);
      }

      if(mLTrue != 0 && hybridPt != 0){
	mLTrueHybridResp->Fill(ptRec,mLTrue,scalingFactors[pTHardBin-1]*scale*rk[pTHardBin-1]);
      }


      if(partLevelPt != 0 && partLevelDistance < (jetRadius*jetMatchingRMult) && detLevelDistance < (jetRadius*jetMatchingRMult) && hybridPt != 0){
	linCorrelationPartLevel->Fill(ptRec, partLevelPt, scalingFactors[pTHardBin-1]*scale*rk[pTHardBin-1] );
      }
       if(detLevelPt !=0 && detLevelDistance < (jetRadius*jetMatchingRMult) && hybridPt != 0){
	 hybridDetResp->Fill(ptRec,detLevelPt, scalingFactors[pTHardBin-1]*scale*rk[pTHardBin-1]);
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
      if(partLevelPt != 0 && partLevelDistance < (jetRadius*jetMatchingRMult) && ptRec != 0){
        h2_resid_hybrid_part_v_part->Fill(partLevelPt, (ptRec - partLevelPt)/partLevelPt, scalingFactors[pTHardBin-1]*scale*rk[pTHardBin-1]);
	h2_resid_hybrid_part_v_part_RAW->Fill(partLevelPt, (ptRec - partLevelPt), scalingFactors[pTHardBin-1]*scale*rk[pTHar\
dBin-1]);
      }


      if(detLevelPt != 0 && detLevelDistance < (jetRadius*jetMatchingRMult)){
        h2_resid_hybrid_det_v_det->Fill(detLevelPt, (ptRec - detLevelPt)/detLevelPt, scalingFactors[pTHardBin-1]*scale*rk[pTHardBin-1]);
      }
      if(detLevelPt != 0 && detLevelDistance < (jetRadius*jetMatchingRMult) && partLevelDistance < (jetRadius*jetMatchingRMult)){
        h2_resid_hybrid_det_v_part->Fill(partLevelPt, (ptRec - detLevelPt)/detLevelPt, scalingFactors[pTHardBin-1]*scale*rk[pTHardBin-1]);
      }

      if(detLevelPt != 0 && detLevelDistance < (jetRadius*jetMatchingRMult)){
        h2_resid_hybrid_det_v_det_RAW->Fill(detLevelPt, (ptRec - detLevelPt), scalingFactors[pTHardBin-1]*scale*rk[pTHardBin-1]);
      }

      if(mLTrue != 0){
        h2_resid_hybrid_mLTrue_v_mLTrue->Fill(mLTrue, (ptRec - mLTrue)/mLTrue, scalingFactors[pTHardBin -1]*scale*rk[pTHardBin-1]);
      }

      if(mLTrue != 0 && detLevelPt != 0 && detLevelDistance < (jetRadius*jetMatchingRMult)){
        h2_resid_det_mLTrue_v_mLTrue->Fill(mLTrue, (detLevelPt-mLTrue)/mLTrue, scalingFactors[pTHardBin-1]*scale*rk[pTHardBin-1]);
      }
        h2_event_bkg_density->Fill(bkg, scalingFactors[pTHardBin-1]*scale*rk[pTHardBin-1]);
     
      if(detLevelPt != 0 && partLevelPt>10){
        mlResidualPlot->Fill((ptRec - detLevelPt), detLevelPt, scalingFactors[pTHardBin -1]*scale);
        float pthis[6] = {-20, 20, 40, 60, 100, 500};
        for (Int_t i = 0; i < extractorBinHists.size(); i++){
           if ((hybridPt < pthis[i]) || (hybridPt > pthis[i+1])) continue;
           extractorBinHists.at(i)->Fill((ptRec - detLevelPt), detLevelPt);
        }
        for (Int_t k = 0; k < extractorBinHists3D.size(); k++){
           if ((hybridPt < pthis[k]) || (hybridPt > pthis[k+1])) continue;
           extractorBinHists3D.at(k)->Fill((ptRec - detLevelPt), detLevelPt, partLevelPt);
        }
      }

      hybridSpectra->Fill(hybridPt,scale*scalingFactors[pTHardBin -1]*rk[pTHardBin-1]);
      detSpectra->Fill(detLevelPt,scale*scalingFactors[pTHardBin -1]*rk[pTHardBin-1]);
      partSpectra->Fill(partLevelPt,scale*scalingFactors[pTHardBin -1]*rk[pTHardBin-1]);



   }
}
