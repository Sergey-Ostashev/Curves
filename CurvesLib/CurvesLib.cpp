// CurvesLib.cpp : Defines the exported functions for the DLL.
//

#include "pch.h"
#include "framework.h"
#include "CurvesLib.h"


// This is an example of an exported variable
CURVESLIB_API int nCurvesLib=0;

// This is an example of an exported function.
CURVESLIB_API int fnCurvesLib(void)
{
    return 0;
}

// This is the constructor of a class that has been exported.
CCurvesLib::CCurvesLib()
{
    return;
}
