#include "CondCore/PluginSystem/interface/registration_macros.h"
DEFINE_SEAL_MODULE();

#include "JetMETCorrections/Objects/interface/JetCorrector.h"
#include "JetMETCorrections/Objects/interface/JetCorrectionsRecord.h"
REGISTER_PLUGIN (JetCorrectionsRecord, JetCorrector);

#include "FWCore/PluginManager/interface/ModuleDef.h"
#include "FWCore/Framework/interface/MakerMacros.h"
#include "FWCore/Framework/interface/SourceFactory.h"

using namespace cms;

#include "JetCorrectionProducer.h"
DEFINE_ANOTHER_FWK_MODULE(JetCorrectionProducer);
#include "PlotJetCorrections.h"
DEFINE_ANOTHER_FWK_MODULE(PlotJetCorrections);

#include "JetCorrectionService.icc"
#include "JetMETCorrections/Objects/interface/SimpleJetCorrector.h"
DEFINE_JET_CORRECTION_SERVICE (SimpleJetCorrector, SimpleJetCorrectionService);
#include "JetMETCorrections/MCJet/interface/MCJetCorrector.h"
DEFINE_JET_CORRECTION_SERVICE (MCJetCorrector, MCJetCorrectionService);
#include "JetMETCorrections/MCJet/interface/MCJetCorrector3D.h"
DEFINE_JET_CORRECTION_SERVICE (MCJetCorrector3D, MCJetCorrectionService3D);
#include "JetMETCorrections/MCJet/interface/ZSPJetCorrector.h"
DEFINE_JET_CORRECTION_SERVICE (ZSPJetCorrector, ZSPJetCorrectionService);
#include "JetMETCorrections/MCJet/interface/L2RelativeCorrector.h"
DEFINE_JET_CORRECTION_SERVICE (L2RelativeCorrector, L2RelativeCorrectionService);
#include "JetMETCorrections/MCJet/interface/L3AbsoluteCorrector.h"
DEFINE_JET_CORRECTION_SERVICE (L3AbsoluteCorrector, L3AbsoluteCorrectionService);
#include "JetMETCorrections/MCJet/interface/L4EMFCorrector.h"
DEFINE_JET_CORRECTION_SERVICE (L4EMFCorrector, L4EMFCorrectionService);
#include "JetMETCorrections/MCJet/interface/L5FlavorCorrector.h"
DEFINE_JET_CORRECTION_SERVICE (L5FlavorCorrector, L5FlavorCorrectionService);
#include "JetMETCorrections/JetPlusTrack/interface/JetPlusTrackCorrector.h"
DEFINE_JET_CORRECTION_SERVICE (JetPlusTrackCorrector, JetPlusTrackCorrectionService);
