#pragma once

#include "UnBitArrayBase.h"

namespace APE
{

class IAPEDecompress;

#pragma pack(push, 1)

// decodes 0000 up to and including 3890
class CUnBitArrayOld : public CUnBitArrayBase
{
public:
    // construction/destruction
    CUnBitArrayOld(IAPEDecompress * pAPEDecompress, intn nVersion, int64 nFurthestReadByte);
    ~CUnBitArrayOld();

    // functions
    void GenerateArray(int * pOutputArray, int nElements, intn nBytesRequired = -1) APE_OVERRIDE;
    uint32 DecodeValue(DECODE_VALUE_METHOD DecodeMethod, int nParam1 = 0, int nParam2 = 0) APE_OVERRIDE;

private:
    // helpers
    void GenerateArrayOld(int * pOutputArray, uint32 nNumberOfElements, int nMinimumBitArrayBytes);
    void GenerateArrayRice(int * pOutputArray, uint32 nNumberOfElements);
    uint32 DecodeValueRiceUnsigned(uint32 kl);

    // data
    uint32 m_nK;
    uint32 m_nKSum;
    uint32 m_nRefillBitThreshold;

    // functions
    __forceinline int DecodeValueNew(bool bCapOverflow);
    uint32 GetBitsRemaining();
    __forceinline uint32 Get_K(uint32 x);
};

#pragma pack(pop)

}
