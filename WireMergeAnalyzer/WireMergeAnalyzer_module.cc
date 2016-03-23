////////////////////////////////////////////////////////////////////////
// Class:       WireMergeAnalyzer
// Module Type: analyzer
// File:        WireMergeAnalyzer_module.cc
//
// Generated at Tue Nov 10 13:06:09 2015 by Wesley Ketchum using artmod
// from cetpkgsupport v1_08_07.
////////////////////////////////////////////////////////////////////////

#include "art/Framework/Core/EDAnalyzer.h"
#include "art/Framework/Core/ModuleMacros.h"
#include "art/Framework/Principal/Event.h"
#include "art/Framework/Principal/Handle.h"
#include "art/Framework/Principal/Run.h"
#include "art/Framework/Principal/SubRun.h"
#include "art/Utilities/InputTag.h"
#include "fhiclcpp/ParameterSet.h"
#include "messagefacility/MessageLogger/MessageLogger.h"

#include "art/Framework/Services/Optional/TFileService.h"

#include "TTree.h"

#include "WireMergeAlg/WireMergeAlg.hh"

namespace patmat {
  class WireMergeAnalyzer;
}

class patmat::WireMergeAnalyzer : public art::EDAnalyzer {
public:
  explicit WireMergeAnalyzer(fhicl::ParameterSet const & p);
  // The destructor generated by the compiler is fine for classes
  // without bare pointers or other resource use.

  // Plugins should not be copied or assigned.
  WireMergeAnalyzer(WireMergeAnalyzer const &) = delete;
  WireMergeAnalyzer(WireMergeAnalyzer &&) = delete;
  WireMergeAnalyzer & operator = (WireMergeAnalyzer const &) = delete;
  WireMergeAnalyzer & operator = (WireMergeAnalyzer &&) = delete;

  // Required functions.
  void analyze(art::Event const & e) override;

  // Selected optional functions.
  void reconfigure(fhicl::ParameterSet const & p) override;

private:

  // Declare member data here.
  patmat::WireMergeAlg fMyAnalysisObj;
  
};


patmat::WireMergeAnalyzer::WireMergeAnalyzer(fhicl::ParameterSet const & p)
  :
  EDAnalyzer(p)  // ,
 // More initializers here.
{
  art::ServiceHandle<art::TFileService> tfs;
  fMyAnalysisObj.SetupOutputTree(tfs->make<TTree>("myanatree","MyAnalysis Tree"));
}

void patmat::WireMergeAnalyzer::analyze(art::Event const & e)
{
  fMyAnalysisObj.RunAnalysis();
}

void patmat::WireMergeAnalyzer::reconfigure(fhicl::ParameterSet const & p)
{
  // Implementation of optional member function here.
}

DEFINE_ART_MODULE(patmat::WireMergeAnalyzer)