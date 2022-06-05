// The following ifdef block is the standard way of creating macros which make exporting
// from a DLL simpler. All files within this DLL are compiled with the CURVESLIB_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see
// CURVESLIB_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef CURVESLIB_EXPORTS
#define CURVESLIB_API __declspec(dllexport)
#else
#define CURVESLIB_API __declspec(dllimport)
#endif

// This class is exported from the dll
class CURVESLIB_API CCurvesLib {
public:
	CCurvesLib(void);
	// TODO: add your methods here.
};

extern CURVESLIB_API int nCurvesLib;

CURVESLIB_API int fnCurvesLib(void);
