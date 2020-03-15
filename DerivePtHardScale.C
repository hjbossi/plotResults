

void DerivePtHardScale()
{

  std::stringstream ss;
  float scale[20] = {0};
  float evt[20] = {0};
  float evt_tot = 0;
  std::vector<TH1D*> hPtHardtot;
  float SCALE20 = 2.0619281e-06;
  for (int i = 1; i <= 20; i++)
    {
      ss << "~/alidock/data/Embedding_021420/AnalysisResults_PtHardBin" << i << ".root";
      TFile* f = new TFile(ss.str().c_str());
      //f->ls();
      ss.str("");
      TList* l = (TList*)f->Get("AliAnalysisTaskEmcalEmbeddingHelper_histos");
      //l->ls();
      TH1D* hxsec = (TH1D*)l->FindObject("fHistXsection");
      TH1D* htrial = (TH1D*)l->FindObject("fHistTrials");
      TH1D* hpthard= (TH1D*)l->FindObject("fHistPtHard");

      TH1D* hevt = (TH1D*)l->FindObject("fHistEventCount");
      float evt_acc = hevt->GetBinContent(1);
      float events_total = hevt->Integral(1,2);
      float xsec = hxsec->GetBinContent(i+1)*hxsec->GetEntries();
      float trials = 1.*htrial->GetBinContent(i+1); ///events_total;

      std::cout <<" =========== pT Hard Bin: " << i << " ================== " << std::endl;
      std::cout << "Total Entries: " << hpthard->Integral() << std::endl;
      std::cout << "Zero Bin Entries: " << hpthard->Integral(0,2) << std::endl;
      float tempxsec = hxsec->GetBinContent(i+1)*(hxsec->GetEntries() -  hpthard->Integral(0,2));
      std::cout << "xsec: " << xsec << std::endl;
      std::cout << "temp_xsec: " << tempxsec << std::endl;
      std::cout << "scale factor: " << xsec/trials << std::endl;
      std::cout << "temp scale factor: " << tempxsec/trials << std::endl;
      std::cout << " ==================================" << std::endl;
      scale[i-1] = xsec/trials;
      //if (i == 20) scale[i-1] = SCALE20;
      evt[i-1] = evt_acc;
      evt_tot+=evt_acc;
      hPtHardtot.push_back(hpthard);
    }

  TCanvas* c = new TCanvas("c", "c", 700, 400);
  c->cd();
  c->SetLogy();

  TH1D* h1 = (TH1D*)hPtHardtot.at(0)->Clone("h1");
  h1->Reset();
  float avg_evts = evt_tot/20.;
  for (int i = 0; i < 20; i++)
    {
      std::cout << "R_{k} for pTHard Bin " << i+1 << " = " << (avg_evts/ evt[i]) << std::endl;
      scale[i] = scale[i]*(avg_evts/ evt[i]);//*(1.*avg_evts);
      cout << "pt hard " << i+1 << ": " << scale[i] << endl;
      hPtHardtot.at(i)->Scale(scale[i]);
      h1->Add(hPtHardtot.at(i));
    }
  h1->Draw();
}
     

