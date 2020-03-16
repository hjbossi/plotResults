//#include "neuralNetPredictions.h"                                                                                                                                                              
#include <sstream>
#include <iostream>


//class mLJetPerf;                                                                                                                                                                    

void Run_NNPredictions()
{
  gROOT->ProcessLine(".L neuralNetPredictions_C.so");
  neuralNetPredictions* j;
  TFile* fout;

  TString filename = "/home/hbossi/alidock/ml-background/PredictionTrees/predictionTree_NeuralNetwork_For_LHC16j5_Embedded_R040.root";
  TFile* f = new TFile(filename);
  TTree* tr = (TTree*)f->Get("predictionTree_NeuralNetwork_LHC16j5_Embedded_R040");
  j = new neuralNetPredictions(tr);
  j->Init(tr);
  j->Loop();
  TString outputFilename = "predicitonResults_NN_Mar13th.root";
  fout = new TFile(outputFilename, "RECREATE");
  j->Write(fout);
}
