#ifndef TEST_USERANALYSIS_CXX
#define TEST_USERANALYSIS_CXX

#include "WireMergeAlg.hh"
#include <iostream>

patmat::WireMergeAlg::WireMergeAlg()
  : fAlgName("WireMergeAlg")
{}

void patmat::WireMergeAlg::SetupOutputTree(TTree* tfs_tree){
  fTree = tfs_tree;

  std::string title = fAlgName + " Tree";
  fTree->SetObject(fTree->GetName(),title.c_str());
}

void patmat::WireMergeAlg::RunAnalysis(){
  PrintInfo();
}

void patmat::WireMergeAlg::PrintInfo(){
  std::cout << "\n================================== WireMergeAlg ==========================" << std::endl;
  std::cout << "This is a ub_WireMergeAlg class called " << fAlgName << std::endl;
  std::cout << "\tThere is an output tree called "
	    << fTree->GetName() << " (" << fTree->GetTitle() << ")" << std::endl;
  std::cout << "==========================================================================\n" << std::endl;
}

#endif
