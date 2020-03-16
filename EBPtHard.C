void EBPtHard(int EB = 0)
{
  TFile* f = new TFile("mLJetPerfResults_011320.root");
  TH2D* h = (TH2D*)f->Get("mLResidualPlot");
  int min = 0;
  int max = 24;
  TH1D* p = (TH1D*)h->ProjectionX("p", min, max);
  
  TCanvas* c = new TCanvas("c", "c", 1000, 800);
  //gPad->SetLogy();
  gStyle->SetOptStat(0);
  TLegend* leg2 = new TLegend(0.45, 0.76, 0.6, 0.89);
  leg2->SetFillColor(0);
  leg2->SetBorderSize(0);
  leg2->SetTextFont(42);
  leg2->SetTextSize(0.045);
  leg2->AddEntry(p, "Total");
  
  TLegend* leg3 = new TLegend(0.62, 0.35, 0.72, 0.89);
  leg3->SetFillColor(0);
  leg3->SetBorderSize(0);
  leg3->SetTextFont(42);
  leg3->SetTextSize(0.045);
  TLegend* leg4 = new TLegend(0.76, 0.35, 0.86, 0.89);
  leg4->SetFillColor(0);
  leg4->SetBorderSize(0);
  leg4->SetTextFont(42);
  leg4->SetTextSize(0.045);

  p->SetMarkerStyle(20);
  p->SetMarkerSize(1);
  p->SetLineColor(kBlack);
  p->SetMarkerColor(kBlack);
  //p->RebinX(2);
  //  p->GetXaxis()->SetRangeUser(0, 300);
  p->GetXaxis()->SetTitle("Probability");
  //  p->SetMaximum(p->GetMaximum()*1000);a
  p->SetTitle("Residuals");
  p->Scale(1./p->Integral(), "width");
  p->Draw();
  
  int colors[20] = {kRed+2, kRed-4, kOrange+7, kOrange, kYellow-4, kSpring+10, kSpring, kGreen-3, kGreen+3, kTeal-7, kTeal, kAzure+10, kAzure-4, kBlue+2, kViolet+8, kViolet-1, kMagenta+1, kMagenta-4, kPink+7, kPink-4};

  std::stringstream ss;
  for (int i = 1; i <=20; i++)
    {
      if (i==3) continue;
      ss.str("");
      ss << "mLJetPerfResults_011320_" << i << ".root";
      TFile *f2 = new TFile(ss.str().c_str());
      f2->ls();
      ss.str("");
      ss << "h2_extractionBin" << EB;
      cout << ss.str() << endl;
      TH2D* h2 = (TH2D*)f2->Get(ss.str().c_str());
      ss << "pthard" << i;
      h2->SetName(ss.str().c_str());
      cout << h2->Integral() << endl;
      ss << "_proj";
      TH1D* h1 = (TH1D*)h2->ProjectionX(ss.str().c_str(), min, max);
      if (h1->Integral() == 0) continue;
      cout << i << "  :  "<< h1->Integral() << endl;
      //h1->RebinX(2);

      ss.str("");
      h1->SetMarkerStyle(20);
      h1->SetMarkerSize(1);
      h1->SetLineColor(colors[i-1]);
      h1->SetMarkerColor(colors[i-1]);
      //h1->Scale(1./h1->Integral(), "width");
      //      if (i%2 == 0) 
      h1->Draw("same");
      ss << "#it{p}_{T}^{hard} " << i;
      if (i <= 10) leg3->AddEntry(h1, ss.str().c_str());
      else leg4->AddEntry(h1, ss.str().c_str());
      ss.str("");
    }
  leg2->Draw("same");
  leg3->Draw("same");
  leg4->Draw("same");

  TLatex* lat = new TLatex();
  lat->SetTextFont(42);
  lat->SetNDC(true);
  lat->SetTextSize(0.04);
  lat->SetTextAlign(33);
  ss << "Extractor Bin: " << EB;
  lat->DrawLatex(0.8, 0.8, ss.str().c_str());
  ss.str("");

  ss << "OverlayPtHardRiduals_EB" << EB << ".pdf";
  c->SaveAs(ss.str().c_str());
  ss.str("");
}
      
  
