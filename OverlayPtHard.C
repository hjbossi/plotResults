/*
OverlayPtHard.C - Plot spectra from individual pT Hard Bins and combined spectra
Hannah Bossi, <hannah.bossi@yale.edu>
adapted from Laura Havener
9/5/2019
 */

void OverlayPtHard()
{
  // get the combined spectra
  TFile* f = new TFile("onlyPartCut.root");
  TH1D* totSpectra = (TH1D*)f->Get("hybridSpectra");

  // create canvas and start plotting
  TCanvas* c = new TCanvas("c", "c", 1000, 800);
  gPad->SetLogy();
  gStyle->SetOptStat(0);
  gStyle->SetOptTitle(0);
  TLegend* leg2 = new TLegend(0.75, 0.35, 0.9, 0.88);
  leg2->SetFillColor(0);
  leg2->SetBorderSize(0);
  leg2->SetTextFont(42);
  leg2->SetTextSize(0.025);
  leg2->AddEntry(totSpectra, "Combined");
  
  totSpectra->SetMarkerStyle(20);
  totSpectra->SetMarkerSize(1);
  totSpectra->SetLineColor(kBlack);
  totSpectra->SetMarkerColor(kBlack);
  totSpectra->Scale(1., "width");
  //totSpectra->RebinX(2);
  totSpectra->GetXaxis()->SetRangeUser(0, 250);
  totSpectra->GetXaxis()->SetTitle("#it{p}_{T}^{hybrid} [GeV/c]");
  totSpectra->Draw();

  int colors[20] = {kRed+2, kRed-4, kOrange+7, kOrange, kYellow-4, kSpring+10, kSpring, kGreen-3, kGreen+3, kTeal-7, kTeal, kAzure+10, kAzure-4, kBlue+2, kViolet+8, kViolet-1, kMagenta+1, kMagenta-4, kPink+7, kPink-4};

  std::stringstream ss;
  for (int i = 1; i <=20; i++)
    {
      ss << "mLJetPerfResults_021420_PartCut_Feb24th_" << i << ".root";
      TFile *f2 = new TFile(ss.str().c_str());
      ss.str("");
      TH1D* indPtHardSpectra = (TH1D*)f2->Get("hybridSpectra"); // get the individual pT Hard bin spectra
      ss << "detPT" << i;
      indPtHardSpectra->SetName(ss.str().c_str());
      //indPtHardSpectra->RebinX(2);
      ss.str("");
      indPtHardSpectra->SetMarkerStyle(20);
      indPtHardSpectra->SetMarkerSize(1);
      indPtHardSpectra->SetLineColor(colors[i-1]);
      indPtHardSpectra->SetMarkerColor(colors[i-1]);
      indPtHardSpectra->Scale(1. , "width");
      indPtHardSpectra->Draw("same");
      ss << "pT Hard: " << i;
      leg2->AddEntry(indPtHardSpectra, ss.str().c_str());
      ss.str("");
    }
  leg2->Draw("same");
}
      
  
