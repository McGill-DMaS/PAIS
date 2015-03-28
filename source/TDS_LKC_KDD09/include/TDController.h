// TDController.h: interface for the CTDController class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(TDCONTROLLER_H)
#define TDCONTROLLER_H

#if !defined(TDATTRIBMGR_H)
    #include "TDAttribMgr.h"
#endif

#if !defined(TDDATAMGR_H)
    #include "TDDataMgr.h"
#endif

#if !defined(TDVIRTUALMGR_H)
    #include "TDVirtualMgr.h"
#endif

#if !defined(TDPARTITIONER_H)
    #include "TDPartitioner.h"
#endif

#if !defined(TDEVALMGR_H)
    #include "TDEvalMgr.h"
#endif

class CTDController  
{
public:
	CTDController(LPCTSTR rawDataFile, 
                  LPCTSTR attributesFile,
                  LPCTSTR nameFile, 
                  LPCTSTR supFile,
                  LPCTSTR transformedDataFile, 
                  LPCTSTR transformedTestFile, 
                  LPCTSTR transformedSVMDataFile, 
                  LPCTSTR transformedSVMTestFile,
                  bool  bIncludeNonVA, 
                  int   defaultL,
                  int   defaultK,
                  float defaultC,
                  int   nInputRecs,
                  int   nTraining);
    virtual ~CTDController();

// operations
    bool runTopDown();
    bool removeUnknowns();
    
protected:
// attributes
    CTDAttribMgr   m_attribMgr;
    CTDVirtualMgr  m_virtualMgr;
    CTDDataMgr     m_dataMgr;
    CTDPartitioner m_partitioner;
    CTDEvalMgr     m_evalMgr;
};

#endif
