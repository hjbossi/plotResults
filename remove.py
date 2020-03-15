
#!/usr/bin/env python

""" Tests for the outliers removal module.
.. codeauthor:: Raymond Ehlers <raymond.ehlers@cern.ch>, Yale University
"""

import ctypes
import logging
import math
import ROOT
import os
import sys
import argparse

import numpy as np
from pachyderm import projectors, remove_outliers
from ROOT import gROOT, TCanvas, TF1, gPad, TH3


# Prevent ROOT from stealing focus when plotting                                                                                             
ROOT.gROOT.SetBatch(True)

def remove(inputFile, pThard):
    #from James thesis
    scale =[0.3471,0.2978,0.2888,0.1894,0.9596e-02,4.613e-02,1.619e-02,5.920e-03,2.547e-03,8.795e-04,3.517e-04,1.272e-04,6.276e-05,2.956e-05,1.452e-05,7.395e-06,3.955e-06,2.111e-06,1.141e-06,1.472e-06]
    rescale = [1.02099, 0.991484, 1.01843, 0.997068, 1.01032, 0.990521, 1.02399, 1.00626, 0.99989, 1.0202, 1.01447, 1.00438,  0.976335, 0.97953, 0.980443, 0.990976, 1.02589, 0.989609, 0.976523, 0.987922]
    scale_val = scale[pThard-1]*rescale[pThard-1]
    print (scale_val)
    # Open input file and get relevant lists                                                                                              
    f = ROOT.TFile(inputFile, "Update")
    f.cd()
    vec = []
    for h in f.GetListOfKeys():
        h=h.ReadObj()
        print (h.GetName())
        print (h.Integral())
        if h.Integral() == 0 : continue
        if pThard < 6 and h.Integral() < 20 : h.Reset()
        #h2=h.Clone("h2")
        outliers_manager = remove_outliers.OutliersRemovalManager()
        if h.Integral() != 0: outliers_start_index = outliers_manager.run(outliers_removal_axis = projectors.TH1AxisType.y_axis, hist = h, mean_fractional_difference_limit = 0.5, median_fractional_difference_limit = 0.5)
        print (h.Integral())
        #vec.append(h)
        h.Sumw2()
        h.Scale(scale_val)
        h.Write()
        '''
        if (h.GetName() == "h2_pT"):
            c = TCanvas("c", "c", 500, 400)
            gPad.SetLogy()
            c.cd()
            h2.ProjectionY("p1").Draw()
            h.SetLineColor(2)
            h.SetMarkerColor(2)
            h.ProjectionY("p2").Draw("same")
            c.SaveAs("test.pdf")
        '''
    f.Close()


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description="Python sucks")
    parser.add_argument("-f", "--inputFile", action="store",
                        type=str, metavar="inputFile",
                        default="AnalysisResults.root",
                        help="Path of AnalysisResults.root file")
    parser.add_argument("-p", "--pThard", action="store",
                        type=int, metavar="pThard",
                        default=10,
                        help="pt hard index")
     
    args = parser.parse_args()

    print("Configuring...")
    print("inputFile: \"{0}\"".format(args.inputFile))

    if not os.path.exists(args.inputFile):
        print("File \"{0}\" does not exist! Exiting!".format(args.inputFile))
        sys.exit(0)

    remove(inputFile = args.inputFile, pThard = args.pThard)
