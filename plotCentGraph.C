void plotCentGraph() {
   // gStyle Settings
   gStyle->SetOptStat(0);
   gStyle->SetOptTitle(0);
   gStyle->SetLineWidth(2);
   gStyle->SetCanvasBorderMode(0);
   gStyle->SetPadBottomMargin(0.15);
   gStyle->SetPadLeftMargin(0.15);
   gStyle->SetHistLineWidth(1);
   gStyle->SetPadColor(10);
   gStyle->SetTitleSize(0.035, "xyz");
   gStyle->SetTitleOffset(1.2, "x");
   gStyle->SetTitleOffset(1.25, "y");
   
   TCanvas *c = new TCanvas("c","c",200,10,500,500);

   c->SetTickx();
   c->SetTicky();
   c->SetFillColor(0);

   const Int_t n = 2;
   Double_t x[n], areaBased[n], mLBased[n], areaBasedSemiCentral[n], mLBasedSemiCentral[n];
   x[0] = 0.2;
   x[1] = 0.4;
   areaBased[0]  = 6.44;
   areaBased[1]  = 13.72;
   mLBased[0] = 4.16;
   mLBased[1] = 6.42; 
   areaBasedSemiCentral[0]  = 3.28;
   areaBasedSemiCentral[1]  = 7.51;
   mLBasedSemiCentral[0] = 2.73;
   mLBasedSemiCentral[1] = 4.94; 

   TGraph *gr = new TGraph(n,x,areaBased);
   gr->SetLineColor(kRed+2);
   gr->SetLineWidth(10);
   gr->SetLineStyle(1);
   //gr->Draw("ACP");

   TGraph *gr2 = new TGraph(n,x,mLBased);
   gr2->SetLineColor(kGreen+2);
   gr2->SetLineWidth(10);
   gr2->SetLineStyle(1);

   TGraph *gr3 = new TGraph(n,x,areaBasedSemiCentral);
   gr3->SetLineColor(kRed+2);
   gr3->SetLineWidth(10);
   gr3->SetLineStyle(2);
   //gr->Draw("ACP");

   TGraph *gr4 = new TGraph(n,x,mLBasedSemiCentral);
   gr4->SetLineColor(kGreen+2);
   gr4->SetLineWidth(10);
   gr4->SetLineStyle(2);
  


   TMultiGraph *mg = new TMultiGraph();
   mg->Add(gr,"lp");
   mg->Add(gr2,"cp");
   mg->Add(gr3,"lp");
   mg->Add(gr4,"cp");
   mg->Draw("a");
   mg->GetXaxis()->SetTitle("Jet Resolution Parameter #it{R}");
   mg->GetYaxis()->SetTitle("Standard Deviation (GeV/#it{c})");
   mg->GetXaxis()->SetNdivisions(100502);
   mg->GetYaxis()->SetRangeUser(0,25);


   TLatex * texTop = new TLatex(0.19,0.85, "#bf{ALICE Performance}");
   texTop->SetNDC();
   texTop->SetTextFont(42);
   texTop->SetTextSize(0.04);
   texTop->Draw("same");
   
   TLatex * tex = new TLatex(0.19,0.8, "PYTHIA + Pb-Pb #sqrt{#it{s}_{NN}} = 5.02 TeV");
   tex->SetNDC();
   tex->SetTextFont(42);
   tex->SetTextSize(0.04);
   tex->Draw("same");

   TLatex * tex2 = new TLatex(0.19,0.7, "#splitline{Full jets, anti-#it{k}_{T}, #left|#it{#eta}_{jet}#right|< 0.3}{40 < #it{p}_{T, det} < 120 GeV/#it{c}}");
   tex2->SetNDC();
   tex2->SetTextFont(42);
   tex2->SetTextSize(0.04);
   tex2->Draw("same");

   TLegend* leg = new TLegend(0.2, 0.48, 0.3, 0.63);
   leg->SetFillColor(0);
   leg->SetBorderSize(0);
   leg->SetTextFont(42);
   leg->SetTextSize(0.04);
   leg->Draw("SAME");
   leg->AddEntry(gr, "Area Based, 0-10%");
   leg->AddEntry(gr2, "ML Based, 0-10%");
   leg->AddEntry(gr3, "Area Based, 30-50%");
   leg->AddEntry(gr4, "ML Based, 30-50%");
  
   // TCanvas::Update() draws the frame, after which one can change it
   c->Update();
}


