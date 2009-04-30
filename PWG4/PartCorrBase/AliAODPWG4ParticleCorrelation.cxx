/**************************************************************************
 * Copyright(c) 1998-2007, ALICE Experiment at CERN, All rights reserved. *
 *                                                                        *
 * Author: The ALICE Off-line Project.                                    *
 * Contributors are mentioned in the code where appropriate.              *
 *                                                                        *
 * Permission to use, copy, modify and distribute this software and its   *
 * documentation strictly for non-commercial purposes is hereby granted   *
 * without fee, provided that the above copyright notice appears in all   *
 * copies and that both the copyright notice and this permission notice   *
 * appear in the supporting documentation. The authors make no claims     *
 * about the suitability of this software for any purpose. It is          *
 * provided "as is" without express or implied warranty.                  *
 **************************************************************************/

/* $Id:   AliAODPWG4ParticleCorrelation.h $ */

//-------------------------------------------------------------------------
//     AOD class for photon and other particles storage and 
//     correlation studies
//     Author: Yves Schutz, CERN, Gustavo Conesa, INFN
//-------------------------------------------------------------------------

//-- ROOT system --

//-- Analysis system
#include "AliAODPWG4ParticleCorrelation.h"

ClassImp(AliAODPWG4ParticleCorrelation)


//______________________________________________________________________________
 AliAODPWG4ParticleCorrelation::AliAODPWG4ParticleCorrelation() :
   AliAODPWG4Particle(), fIsolated(kFALSE),
   fLeadingDetector(""), fLeading(), fCorrJet(),  fCorrBkg(), fRefJet(0),
   fListOfRefArrays(new TList)
{
  // constructor
}

//______________________________________________________________________________
AliAODPWG4ParticleCorrelation::AliAODPWG4ParticleCorrelation(Double_t px, Double_t py, Double_t pz, Double_t e):
  AliAODPWG4Particle(), fIsolated(kFALSE),
  fLeadingDetector(""),  fLeading(), fCorrJet(),
  fCorrBkg(), fRefJet(0),  fListOfRefArrays(new TList)
{
  // constructor
  SetMomentum(new TLorentzVector(px, py, pz, e));
}

//______________________________________________________________________________
AliAODPWG4ParticleCorrelation::AliAODPWG4ParticleCorrelation(TLorentzVector & p):
  AliAODPWG4Particle(p), fIsolated(kFALSE),
  fLeadingDetector(""),  fLeading(), fCorrJet(), fCorrBkg(), fRefJet(0),  fListOfRefArrays(new TList)
{
  // constructor
}

//______________________________________________________________________________
AliAODPWG4ParticleCorrelation::AliAODPWG4ParticleCorrelation(AliAODPWG4Particle & p):
  AliAODPWG4Particle(p), fIsolated(kFALSE),
  fLeadingDetector(""),  fLeading(), fCorrJet(), fCorrBkg(),fRefJet(0),   fListOfRefArrays(new TList)
{
  // constructor
  
}

//______________________________________________________________________________
AliAODPWG4ParticleCorrelation::~AliAODPWG4ParticleCorrelation() 
{
  // destructor
  if(fListOfRefArrays){
    fListOfRefArrays->Clear();
    delete   fListOfRefArrays ;
  }
}

//______________________________________________________________________________
AliAODPWG4ParticleCorrelation::AliAODPWG4ParticleCorrelation(const AliAODPWG4ParticleCorrelation& part) :
  AliAODPWG4Particle(part), fIsolated(part.fIsolated),
  fLeadingDetector(part.fLeadingDetector), fLeading(part.fLeading),  
  fCorrJet(part.fCorrJet), fCorrBkg(part.fCorrBkg), fRefJet(part.fRefJet),   
  fListOfRefArrays(part.fListOfRefArrays)
{
  // Copy constructor

}

//______________________________________________________________________________
AliAODPWG4ParticleCorrelation& AliAODPWG4ParticleCorrelation::operator=(const AliAODPWG4ParticleCorrelation& part)
{
  // Assignment operator
  if(this!=&part) {
  
    fIsolated = part.fIsolated;
    fRefJet   = part.fRefJet ;
    fLeadingDetector =part.fLeadingDetector;
    fLeading  = part.fLeading;
    fCorrJet  = part.fCorrJet ;
    fCorrBkg  = part.fCorrBkg; 
    fListOfRefArrays = fListOfRefArrays;

  }
  
  return *this;
}

//______________________________________________________________________________
void AliAODPWG4ParticleCorrelation::Print(Option_t* /*option*/) const 
{
  // Print information of all data members
  AliAODPWG4Particle::Print("");

  if(fIsolated) printf("Isolated! \n");

  if(GetJet()) GetJet()->Print("");

  printf("Leading Detector : %s\n",fLeadingDetector.Data());
  printf("Leading Particle 4-vector:\n");
  printf("     E  = %13.3f",   fLeading.E() );
  printf("     Px = %13.3f",   fLeading.Px());
  printf("     Py = %13.3f",   fLeading.Py());
  printf("     Pz = %13.3f\n", fLeading.Pz());

  if( fListOfRefArrays)   fListOfRefArrays->Print("");
}
