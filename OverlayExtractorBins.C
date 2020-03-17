/*                                                                                                                                                                        
OverlayPtHard.C - Plot spectra from individual pT Hard Bins and combined spectra                                             
Hannah Bossi, <hannah.bossi@yale.edu>                                                                                                                                     
adapted from Laura Havener                                                                                                                                                
10/7/2019                                                                                                                                                                  
*/

void OverlayExtractorBins()
{
  // get the combined spectra                                                                                                                                              
  TFile* f = new TFile("withExtractorScaling.root");
  TH2D* totResid = (TH2D*)f->Get("mLResidualPlot");
  TH1D* totResidProj = (TH1D*)totResid->ProjectionX("px",9,24);
  totResidProj->Scale(1./totResidProj->Integral());
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
  leg2->AddEntry(totResidProj, "Combined");

  totResidProj->SetMarkerStyle(20);
  totResidProj->SetMarkerSize(1);
  totResidProj->SetLineColor(kBlack);
  totResidProj->SetMarkerColor(kBlack);
  //totSpectra->GetXaxis()->SetTitle("#it{p}_{T}^{hyb} [GeV/c]");
  totResidProj->Draw();

  int colors[20] = {kRed+2, kRed-4, kOrange+7, kOrange, kYellow-4, kSpring+10, kSpring, kGreen-3, kGreen+3, kTeal-7, kTeal, kAzure+10, kAzure-4, kBlue+2, kViolet+8, kViolet-1, kMagenta+1, kMagenta-4, kPink+7, kPink-4};

   std::stringstream ss;
  for (int i = 1; i <=20; i++)
    {
      ss << "mLJetPerfResults_WithScaling_" << i << ".root";
      TFile *f2 = new TFile(ss.str().c_str());
      ss.str("");
      TH2D* indExtractorBinsNoProj = (TH2D*)f2->Get("h2_extractionBin0"); // get the individual pT Hard bin spectra
      ss << "extractorBin" << i;
      TH1D* indExtractorBins = (TH1D*)indExtractorBinsNoProj->ProjectionX(ss.str().c_str(),9,24);
      indExtractorBins->Scale(1./indExtractorBins->Integral());
      ss.str("");
      indExtractorBins->SetMarkerStyle(20);
      indExtractorBins->SetMarkerSize(1);
      indExtractorBins->SetLineColor(colors[i-1]);
      indExtractorBins->SetMarkerColor(colors[i-1]);
      indExtractorBins->Draw("same");
      ss << "pT Hard: " << i;
      leg2->AddEntry(indExtractorBins, ss.str().c_str());
      ss.str("");
    }
  leg2->Draw("same");
  c->SaveAs("pThard_Combined_ExtractorBins_100419.pdf");
}


