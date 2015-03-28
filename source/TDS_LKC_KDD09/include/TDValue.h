// TDValue.h: interface for the CTDValue class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(TDVALUE_H)
#define TDVALUE_H

#if !defined(TDATTRIBUTE_H)
    #include "TDAttribute.h"
#endif

#if !defined(TDCONCEPT_H)
    #include "TDConcept.h"
#endif


class CTDValue
{
public:
    CTDValue();
    virtual ~CTDValue();

// operations
    bool initConceptToRoot(CTDAttrib* pAttrib);
    bool initConceptToLevel1(CTDAttrib* pAttrib);
    bool lowerCurrentConcept();

    virtual CString toString(bool bRawValue) = 0;
    virtual CString toSVMString(bool bRawValue) = 0;
    virtual CString toSVMClassString() = 0;

    virtual bool buildBitValue(const CString& rawVal, CTDAttrib* pAttrib) = 0;
    virtual CTDConcept* getLowerConcept() = 0;

    int getCurrentConceptFlattenIdx() { return m_pCurrConcept->m_flattenIdx; };
    CTDConcept* getCurrentConcept() { return m_pCurrConcept; };  

protected:
// attributes
    CTDConcept* m_pCurrConcept;     // Pointer to the current concept.
};


class CTDStringValue : public CTDValue
{
public:
    CTDStringValue() : m_bitValue(0), m_pRawConcept(NULL) {};
    virtual ~CTDStringValue() {};
    
    virtual CString toString(bool bRawValue);
    virtual CString toSVMString(bool bRawValue);
    virtual CString toSVMClassString();

    virtual bool buildBitValue(const CString& rawVal, CTDAttrib* pAttrib);
    virtual CTDConcept* getLowerConcept();    
    CTDConcept* getRawConcept();

// static functions
    static bool buildConceptPath(const CString& rawVal, CTDConcepts* pFlatten, CTDConcepts& conceptPath);

protected:
    CTDConcept* getLowerConceptGenMode(CTDConcept* pThisConcept);
    CTDConcept* getLowerConceptSupMode();

// attributes
    UINT m_bitValue;                    // UINT to make sure shift in 0 in case cross-platform.
    CTDConcept* m_pRawConcept;          // Pointer to the raw concept.
};


class CTDNumericValue : public CTDValue
{
public:
    CTDNumericValue(float val) : m_numValue(val) {};
    virtual ~CTDNumericValue() {};

    float getRawValue() { return m_numValue; };
    bool insertConcept(CTDContConcept* pConcept);

    virtual CString toString(bool bRawValue);
    virtual CString toSVMString(bool bRawValue) { return toString(bRawValue); };
    virtual CString toSVMClassString() { ASSERT(false); return _T(""); };    

    virtual bool buildBitValue(const CString& rawVal, CTDAttrib* pAttrib) { return true; };
    virtual CTDConcept* getLowerConcept();

protected:
// attributes
    float m_numValue; 
};


typedef CTypedPtrArray<CPtrArray, CTDValue*> CTDValueArray;
class CTDValues : public CTDValueArray
{
public:
    CTDValues();
    virtual ~CTDValues();
    void cleanup();
};

#endif
