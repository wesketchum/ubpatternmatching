/**
 * \file WireMergeAlg.h
 *
 * 
 * \brief Little sample program for establishing a user analysis space.
 *
 * @author wketchum
*/

#ifndef TEST_USERANALYSIS_H
#define TEST_USERANALYSIS_H

#include <string>

#include "TTree.h"

namespace patmat{
  class WireMergeAlg;
}

class patmat::WireMergeAlg{
  
public:
  
  /// Default constructor
  WireMergeAlg();

  /// Default destructor
  virtual ~WireMergeAlg(){};

  void RunAnalysis();
  void SetupOutputTree(TTree*);
  
 private:

  std::string fAlgName;
  TTree*      fTree;
  
  void PrintInfo();

  
};

#endif
