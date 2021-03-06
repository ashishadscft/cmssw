{
#include <string>
#include <sstream>

#include "TFile.h"
#include "TList.h"
#include "TNtuple.h"
#include "TTree.h"
  
  //gStyle->SetOptStat(000000000);
  //gStyle->SetPadBorderSize(0.0);
  //gStyle->SetPadBottomMargin(0.15);
  gStyle->SetPadLeftMargin(0.15);
  gStyle->SetPadTopMargin(0.20);
  gStyle->SetTitleFontSize(0.08);
  
  //TFile fin("zijinData/compareMis1.root");
  //TFile fin("compareHIPtoSurvey_globalshift.root");
  //TFile fin("compareHIP.root");
  //TFile fin("Compare13Xto14X_pos.root");
  //TFile fin("UCSBCompare.root");
  //TFile fin("testCompare.root");
  TFile fin("stripCompare2.root");
  //TFile fin("fullsurveyCompare_19_18_13_11_8_5_1.root");
  fin.cd();
  TTree* data = alignTree;


  TCut levelCut1 = "(level == 1) && (sublevel > 0) && (sublevel < 7)";
  TCut zCut = "(z < 40)&&(z>-40)";
  TCut pXCut = "(phi < 1.5707) && (phi > -1.5707)";
  TCut mXCut = "(phi > 1.5707) && (phi < -1.5707)";
  TCut levelCut = levelCut1;//+ zCut;// + pXCut;


  TCanvas* c = new TCanvas("c", "c", 200, 10, 800, 800);
  c->SetFillColor(0);
  data->SetMarkerStyle(0);
  c->Divide(3,3);
  c->cd(1);
  data->Draw("dr:r", levelCut);
  TH1F* htemp = (TH1F*)gPad->GetPrimitive("htemp");
  htemp->SetTitle("#Delta r (cm) vs. r (cm)");
  TAxis *xaxis = htemp->GetXaxis();
  TAxis *yaxis = htemp->GetYaxis();
  xaxis->SetTitle("");
  yaxis->SetTitle("");
  xaxis->CenterTitle(true);
  yaxis->CenterTitle(true);
  xaxis->SetTitleSize(0.06);
  yaxis->SetTitleSize(0.06);
  yaxis->SetTitleOffset(-0.25);
  yaxis->SetLabelSize(.06);
  xaxis->SetLabelSize(.06);
  //yaxis->SetRangeUser(-.1,.2);
  //yaxis->SetRangeUser(-.005,0.02);
  c->Update();
  c->cd(2);
  data->Draw("dz:r", levelCut);
  TH1F* htemp = (TH1F*)gPad->GetPrimitive("htemp");
  htemp->SetTitle("#Delta z (cm) vs. r (cm)");
  TAxis *xaxis = htemp->GetXaxis();
  TAxis *yaxis = htemp->GetYaxis();
  xaxis->SetTitle("r (cm)");
  yaxis->SetTitle("#Delta z (cm)");
  xaxis->SetTitle("");
  yaxis->SetTitle("");
  xaxis->CenterTitle(true);
  yaxis->CenterTitle(true);
  xaxis->SetTitleSize(0.06);
  yaxis->SetTitleSize(0.06);
  yaxis->SetTitleOffset(-0.3);
  yaxis->SetLabelSize(.06);
  xaxis->SetLabelSize(.06);
  //yaxis->SetRangeUser(-.1,.175);
  //yaxis->SetRangeUser(-.5,1.5);
  c->Update();
  c->cd(3);
  data->Draw("r*dphi:r", levelCut);
   TH1F* htemp = (TH1F*)gPad->GetPrimitive("htemp");
  htemp->SetTitle("r*#Delta #phi (cm) vs. r (cm)");
  TAxis *xaxis = htemp->GetXaxis();
  TAxis *yaxis = htemp->GetYaxis();
  xaxis->SetTitle("r (cm)");
  yaxis->SetTitle("r*#Delta #phi (cm)");
  xaxis->SetTitle("");
  yaxis->SetTitle("");
  xaxis->CenterTitle(true);
  yaxis->CenterTitle(true);
  xaxis->SetTitleSize(0.06);
  yaxis->SetTitleSize(0.06);
  yaxis->SetTitleOffset(-0.3);
  yaxis->SetLabelSize(.06);
  xaxis->SetLabelSize(.06);
  //yaxis->SetRangeUser(-.22,.55);
  //yaxis->SetRangeUser(-.3,.32);
  c->Update();
  c->cd(4);
  data->Draw("dr:z", levelCut);
  TH1F* htemp = (TH1F*)gPad->GetPrimitive("htemp");
  htemp->SetTitle("#Delta r (cm) vs. z (cm)");
  TAxis *xaxis = htemp->GetXaxis();
  TAxis *yaxis = htemp->GetYaxis();
  xaxis->SetTitle("z (cm)");
  yaxis->SetTitle("#Delta r (cm)");
  xaxis->SetTitle("");
  yaxis->SetTitle("");
  xaxis->CenterTitle(true);
  yaxis->CenterTitle(true);
  xaxis->SetTitleSize(0.06);
  yaxis->SetTitleSize(0.06);
  yaxis->SetTitleOffset(-0.3);
  xaxis->SetLabelSize(.06);
  yaxis->SetLabelSize(.06);
  //yaxis->SetRangeUser(-.1,.2); 
  //yaxis->SetRangeUser(-.3,1.0);
  //yaxis->SetRangeUser(-.005,0.02);
  c->Update();
  c->cd(5);
  data->Draw("dz:z", levelCut);
  TH1F* htemp = (TH1F*)gPad->GetPrimitive("htemp");
  htemp->SetTitle("#Delta z (cm) vs. z (cm)");
  TAxis *xaxis = htemp->GetXaxis();
  TAxis *yaxis = htemp->GetYaxis();
  xaxis->SetTitle("z (cm)");
  yaxis->SetTitle("#Delta z (cm)");
  xaxis->SetTitle("");
  yaxis->SetTitle("");
  xaxis->CenterTitle(true);
  yaxis->CenterTitle(true);
  xaxis->SetTitleSize(0.06);
  yaxis->SetTitleSize(0.06);
  yaxis->SetTitleOffset(-0.3);
  yaxis->SetLabelSize(.06);
  xaxis->SetLabelSize(.06);
  //yaxis->SetRangeUser(-.1,.175);
  //yaxis->SetRangeUser(-.5,1.5);
  c->Update();
  c->cd(6);
  data->Draw("r*dphi:z", levelCut);
  TH1F* htemp = (TH1F*)gPad->GetPrimitive("htemp");
  htemp->SetTitle("r*#Delta #phi (cm) vs. z (cm)");
  TAxis *xaxis = htemp->GetXaxis();
  TAxis *yaxis = htemp->GetYaxis();
  xaxis->SetTitle("z (cm)");
  yaxis->SetTitle("r*#Delta #phi (cm)");
  xaxis->SetTitle("");
  yaxis->SetTitle("");
  xaxis->CenterTitle(true);
  yaxis->CenterTitle(true);
  xaxis->SetTitleSize(0.06);
  yaxis->SetTitleSize(0.06);
  yaxis->SetTitleOffset(-0.3);
  yaxis->SetLabelSize(.06);
  xaxis->SetLabelSize(.06);
  //yaxis->SetRangeUser(-.22,.55);
  //yaxis->SetRangeUser(-.3,.32);
  c->Update();
  c->cd(7);
  data->Draw("dr:phi", levelCut);
  TH1F* htemp = (TH1F*)gPad->GetPrimitive("htemp");
  htemp->SetTitle("#Delta r  (cm)vs. #phi");
  TAxis *xaxis = htemp->GetXaxis();
  TAxis *yaxis = htemp->GetYaxis();
  xaxis->SetTitle("#phi");
  yaxis->SetTitle("#Delta r (cm)");
  xaxis->SetTitle("");
  yaxis->SetTitle("");
  xaxis->CenterTitle(true);
  yaxis->CenterTitle(true);
  xaxis->SetTitleSize(0.06);
  yaxis->SetTitleSize(0.06);
  yaxis->SetTitleOffset(-0.3);
  yaxis->SetLabelSize(.06);
  xaxis->SetLabelSize(.06);
  //yaxis->SetRangeUser(-.1,.2);
  //yaxis->SetRangeUser(-.3,1.0);
  //yaxis->SetRangeUser(-.005,0.02);
  c->Update();
  c->cd(8);
  data->Draw("dz:phi", levelCut);
  TH1F* htemp = (TH1F*)gPad->GetPrimitive("htemp");
  htemp->SetTitle("#Delta z  (cm)vs. #phi");
  TAxis *xaxis = htemp->GetXaxis();
  TAxis *yaxis = htemp->GetYaxis();
  xaxis->SetTitle("#phi");
  yaxis->SetTitle("#Delta z (cm)");
  xaxis->SetTitle("");
  yaxis->SetTitle("");
  xaxis->CenterTitle(true);
  yaxis->CenterTitle(true);
  xaxis->SetTitleSize(0.06);
  yaxis->SetTitleSize(0.06);
  yaxis->SetTitleOffset(-0.3);
  yaxis->SetLabelSize(.06);
  xaxis->SetLabelSize(.06);
  //yaxis->SetRangeUser(-.1,.175);
  //yaxis->SetRangeUser(-.5,1.5);
  c->Update();
  c->cd(9);
  data->Draw("r*dphi:phi", levelCut);
  TH1F* htemp = (TH1F*)gPad->GetPrimitive("htemp");
  htemp->SetTitle("r*#Delta #phi (cm) vs. #phi");
  TAxis *xaxis = htemp->GetXaxis();
  TAxis *yaxis = htemp->GetYaxis();
  xaxis->SetTitle("#phi");
  yaxis->SetTitle("r*#Delta #phi (cm)");
  xaxis->SetTitle("");
  yaxis->SetTitle("");
  xaxis->CenterTitle(true);
  yaxis->CenterTitle(true);
  xaxis->SetTitleSize(0.06);
  yaxis->SetTitleSize(0.06);
  yaxis->SetTitleOffset(-0.3);
  yaxis->SetLabelSize(.06);
  xaxis->SetLabelSize(.06);
  //yaxis->SetRangeUser(-.22,.55);
  //yaxis->SetRangeUser(-.4,.75);
  c->Update();
  

}
