import FWCore.ParameterSet.Config as cms

process = cms.Process("TEST")

process.source = cms.Source("EmptySource")

process.maxEvents.input = 3

process.a = cms.EDProducer("NonEventIntProducer", ivalue = cms.int32(1))
process.b = cms.EDProducer("NonEventIntProducer", ivalue = cms.int32(2),
                           consumesBeginRun = cms.InputTag("c","beginRun"),
                           expectBeginRun = cms.untracked.int32(3) )
process.c = cms.EDProducer("NonEventIntProducer", ivalue = cms.int32(3),
                           consumesBeginRun = cms.InputTag("a", "beginRun"),
                           expectBeginRun = cms.untracked.int32(1))

process.schedule = cms.Schedule(tasks=cms.Task(process.a,process.b,process.c))
