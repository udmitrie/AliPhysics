#ifndef ALIRDHFCUTSXICTOELEXIFROMAODTRACKS_H
#define ALIRDHFCUTSXICTOELEXIFROMAODTRACKS_H
/* Copyright(c) 1998-2010, ALICE Experiment at CERN, All rights reserved. *
 * See cxx source for full Copyright notice                               */

/* $Id$ */

//***********************************************************
// Class AliRDHFCutsXictoeleXifromAODtracks
// class for cuts on AOD reconstructed Xic-> ele + Xi
//***********************************************************

#include "AliRDHFCuts.h"

class AliRDHFCutsXictoeleXifromAODtracks : public AliRDHFCuts
{
 public:

  enum EPIDStrategy{
    kNSigmaCuts,
    kNSigmaCustomizedCuts,
    kCombinedCuts
  };

  AliRDHFCutsXictoeleXifromAODtracks(const char* name="CutsXictoeleXi");
  virtual ~AliRDHFCutsXictoeleXifromAODtracks();
  AliRDHFCutsXictoeleXifromAODtracks(const AliRDHFCutsXictoeleXifromAODtracks& source);
  AliRDHFCutsXictoeleXifromAODtracks& operator=(const AliRDHFCutsXictoeleXifromAODtracks& source);

  using AliRDHFCuts::GetCutVarsForOpt;
  virtual void GetCutVarsForOpt(AliAODRecoDecayHF *d,Float_t *vars,Int_t nvars,Int_t *pdgdaughters);

  using AliRDHFCuts::IsSelected;
  virtual Int_t IsSelected(TObject* obj,Int_t selectionLevel);
  using AliRDHFCuts::IsSelectedPID;
  virtual Int_t IsSelectedPID(AliAODRecoDecayHF* obj);
  Int_t IsSelectedCombinedPID(AliAODRecoDecayHF* obj);
  Bool_t IsSelectedeID(AliAODTrack* trk);
  Bool_t IsSelectedCustomizedeID(AliAODTrack* trk);
  Bool_t IsSelectedCombinedeID(AliAODTrack* trk);

  void SetPIDStrategy(EPIDStrategy pidStrategy){fPIDStrategy=pidStrategy;}
  EPIDStrategy GetPIDStrategy() const {return fPIDStrategy;}
  void SetCombinedPIDThreshold(Double_t a){fCombinedPIDThreshold=a;}
  Double_t GetCombinedPIDThreshold(){return fCombinedPIDThreshold;}


  Bool_t SingleTrkCuts(AliAODTrack *trk, AliAODVertex *primvert);
  Bool_t SingleCascadeCuts(AliAODcascade *casc, Double_t *vert);
  Bool_t SelectWithRoughCuts(AliAODcascade *casc, AliAODTrack *trk1);

  void SetProdTrackTPCNclsPIDMin(Int_t a){fProdTrackTPCNclsPIDMin=a;}
  void SetProdTrackTPCNclsRatioMin(Double_t a){fProdTrackTPCNclsRatioMin=a;}
  void SetProdUseAODFilterBit(Bool_t a){fProdUseAODFilterBit=a;}
  void SetProdMassTolLambda(Double_t a){fProdMassTolLambda=a;}
  void SetProdMassTolXi(Double_t a){fProdMassTolXi=a;}
  void SetProdMassRejOmega(Double_t a){fProdMassRejOmega=a;}
  void SetProdRfidMinV0(Double_t a){fProdRfidMinV0=a;}
  void SetProdRfidMaxV0(Double_t a){fProdRfidMaxV0=a;}
  void SetProdRfidMinXi(Double_t a){fProdRfidMinXi=a;}
  void SetProdRfidMaxXi(Double_t a){fProdRfidMaxXi=a;}
  void SetProdCascProperDecayLengthMax(Double_t a){fProdCascProperDecayLengthMax=a;}
  void SetProdDcaXiDaughtersMax(Double_t a){fProdDcaXiDaughtersMax=a;}
  void SetProdDcaV0DaughtersMax(Double_t a){fProdDcaV0DaughtersMax=a;}
  void SetProdDcaBachToPrimVertexMin(Double_t a){fProdDcaBachToPrimVertexMin=a;}
  void SetProdDcaV0ToPrimVertexMin(Double_t a){fProdDcaV0ToPrimVertexMin=a;}
  void SetProdDcaV0PrToPrimVertexMin(Double_t a){fProdDcaV0PrToPrimVertexMin=a;}
  void SetProdDcaV0PiToPrimVertexMin(Double_t a){fProdDcaV0PiToPrimVertexMin=a;}
  void SetProdXiCosineOfPoiningAngleMin(Double_t a){fProdXiCosineOfPoiningAngleMin=a;}
  void SetProdV0CosineOfPoiningAngleXiMin(Double_t a){fProdV0CosineOfPoiningAngleXiMin=a;}
  void SetProdCascNTPCClustersMin(Double_t a){fProdCascNTPCClustersMin=a;}
  void SetProdCascEtaRange(Double_t a, Double_t b){fProdCascEtaMin=a;fProdCascEtaMax=b;}
  void SetProdCascRapRange(Double_t a, Double_t b){fProdCascRapMin=a;fProdCascRapMax=b;}
  void SetProdRoughMassTol(Double_t a){fProdRoughMassTol=a;}
  void SetProdRoughPtMin(Double_t a){fProdRoughPtMin=a;}
  
  Int_t GetProdTrackTPCNclsPIDMin(){return fProdTrackTPCNclsPIDMin;}
  Double_t GetProdTrackTPCNclsRatioMin(){return fProdTrackTPCNclsRatioMin;}
  Bool_t   GetProdUseAODFilterBit(){return fProdUseAODFilterBit;}
  Double_t GetProdMassTolLambda(){return fProdMassTolLambda;}
  Double_t GetProdMassTolXi(){return fProdMassTolXi;}
  Double_t GetProdMassRejOmega(){return fProdMassRejOmega;}
  Double_t GetProdRfidMinV0(){return fProdRfidMinV0;}
  Double_t GetProdRfidMaxV0(){return fProdRfidMaxV0;}
  Double_t GetProdRfidMinXi(){return fProdRfidMinXi;}
  Double_t GetProdRfidMaxXi(){return fProdRfidMaxXi;}
  Double_t GetProdCascProperDecayLengthMax(){return fProdCascProperDecayLengthMax;}
  Double_t GetProdDcaXiDaughtersMax(){return fProdDcaXiDaughtersMax;}
  Double_t GetProdDcaV0DaughtersMax(){return fProdDcaV0DaughtersMax;}
  Double_t GetProdDcaBachToPrimVertexMin(){return fProdDcaBachToPrimVertexMin;}
  Double_t GetProdDcaV0ToPrimVertexMin(){return fProdDcaV0ToPrimVertexMin;}
  Double_t GetProdDcaV0PrToPrimVertexMin(){return fProdDcaV0PrToPrimVertexMin;}
  Double_t GetProdDcaV0PiToPrimVertexMin(){return fProdDcaV0PiToPrimVertexMin;}
  Double_t GetProdXiCosineOfPoiningAngleMin(){return fProdXiCosineOfPoiningAngleMin;}
  Double_t GetProdV0CosineOfPoiningAngleXiMin(){return fProdV0CosineOfPoiningAngleXiMin;}
  Double_t GetProdRoughMassTol(){return fProdRoughMassTol;}
  Double_t GetProdRoughPtMin(){return fProdRoughPtMin;}
  Double_t GetProdCascNTPCClustersMin(){return fProdCascNTPCClustersMin;}
  void GetProdCascEtaRange(Double_t &a, Double_t &b){a=fProdCascEtaMin;b=fProdCascEtaMax;}
  void GetProdCascRapRange(Double_t &a, Double_t &b){a=fProdCascRapMin;b=fProdCascRapMax;}

  Bool_t GetUseCascadePID(){return fUseCascadePID;}
  void SetUseCascadePID(Bool_t a){fUseCascadePID=a;}
  void SetPidCascPi(AliAODPidHF* pidPion) { 
      if(fPidObjCascPi) delete fPidObjCascPi;
      fPidObjCascPi=new AliAODPidHF(*pidPion);
      }
  AliAODPidHF* GetPidCascPi() const {return fPidObjCascPi;}
  void SetPidCascPr(AliAODPidHF* pidProton) { 
      if(fPidObjCascPr) delete fPidObjCascPr;
      fPidObjCascPr=new AliAODPidHF(*pidProton);
      }
  AliAODPidHF* GetPidCascPr() const {return fPidObjCascPr;}

	void SetExcludePionTPC(Bool_t a){fExcludePionTPC=a;}
	void SetExcludeProtonTPC(Bool_t a){fExcludeProtonTPC=a;}
	void SetExcludeKaonTPC(Bool_t a){fExcludeKaonTPC=a;}
	void SetExcludenSigmaPionTPC(Double_t a){fExcludenSigmaPionTPC=a;}
	void SetExcludenSigmaProtonTPC(Double_t a){fExcludenSigmaProtonTPC=a;}
	void SetExcludenSigmaKaonTPC(Double_t a){fExcludenSigmaKaonTPC=a;}
	void SetSigmaElectronTPCRange(Double_t a,Double_t b){fSigmaElectronTPCMin=a;fSigmaElectronTPCMax=b;}
	void SetSigmaElectronTOFRange(Double_t a,Double_t b){fSigmaElectronTOFMin=a;fSigmaElectronTOFMax=b;}
  

 protected:
	
 private:

  EPIDStrategy fPIDStrategy;        //PID strategy
  Double_t fCombinedPIDThreshold;   //Threshold used in  IsSelectedCombinedPID 
  Bool_t fUseCascadePID;            //Use PID for cascade or not
  AliAODPidHF *fPidObjCascPi;         //PID object for cascade-pion
  AliAODPidHF *fPidObjCascPr;         //PID object for cascade-proton
//  Bool_t   fUseOnTheFlyV0;          //Flag to check if we use on-the-fly v0
  
  Int_t fProdTrackTPCNclsPIDMin;      //Min. Number of TPC PID cluster
  Double_t fProdTrackTPCNclsRatioMin;      //Min. Number of TPC PID cluster
  Bool_t   fProdUseAODFilterBit;    //Flag for AOD filter Bit used before object creation
  Double_t fProdMassTolLambda;      //Tolerance of Lambda mass from PDG value
  Double_t fProdMassTolXi;          //Tolerance of Xi mass from PDG value
  Double_t fProdMassRejOmega;          //Rejection range of Omega mass from PDG value
  Double_t fProdRfidMinV0;          //Minimum Decay vertex of V0
  Double_t fProdRfidMaxV0;          //Max Decay vertex of V0
  Double_t fProdRfidMinXi;          //Minimum Decay vertex of Xi
  Double_t fProdRfidMaxXi;          //Max Decay vertex of Xi
  Double_t fProdCascProperDecayLengthMax;        //mL/p of cascade
  Double_t fProdDcaXiDaughtersMax;  //Max Dca between Xi daughters
  Double_t fProdDcaV0DaughtersMax;  //Max Dca between V0 daughters
  Double_t fProdDcaBachToPrimVertexMin;  //Min Dca between Bachelor and PV 
  Double_t fProdDcaV0ToPrimVertexMin;  //Min Dca between v0 and PV 
  Double_t fProdDcaV0PrToPrimVertexMin;  //Min Dca between v0-proton and PV 
  Double_t fProdDcaV0PiToPrimVertexMin;  //Min Dca between v0-pion and PV 
  Double_t fProdXiCosineOfPoiningAngleMin;  //Min Xi cos pointing angle  to PV
  Double_t fProdV0CosineOfPoiningAngleXiMin;  //Min V0 cos pointing angle  to Xi vertex
  Double_t fProdCascNTPCClustersMin;         //Minimum number of TPC clusters
	Double_t fProdCascEtaMin; //Minimum eta of cascade
	Double_t fProdCascEtaMax; //Maximum eta of cascade
	Double_t fProdCascRapMin; //Minimum rapidity of cascade
	Double_t fProdCascRapMax; //Maximum rapidity of cascade
  Double_t fProdRoughMassTol;       //Mass cut for Lc used before object creation
  Double_t fProdRoughPtMin;         //pT cut for Lc used before object creation

	Bool_t fExcludePionTPC;//Flag wheter to exlude pion band
	Bool_t fExcludeProtonTPC;//Flag wheter to exlude proton band
	Bool_t fExcludeKaonTPC;//Flag wheter to exlude proton band
	Double_t fExcludenSigmaPionTPC;//nSigma to exclude for pion band
	Double_t fExcludenSigmaProtonTPC;//nSigma to exclude for proton band
	Double_t fExcludenSigmaKaonTPC;//nSigma to exclude for Kaon band
	Double_t fSigmaElectronTPCMin;//nSigma to exclude for Kaon band
	Double_t fSigmaElectronTPCMax;//nSigma to exclude for Kaon band
	Double_t fSigmaElectronTOFMin;//nSigma to exclude for Kaon band
	Double_t fSigmaElectronTOFMax;//nSigma to exclude for Kaon band
  

  ClassDef(AliRDHFCutsXictoeleXifromAODtracks,2);
};

#endif
