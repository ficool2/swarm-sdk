// ALL SKIP STATEMENTS THAT AFFECT THIS SHADER!!!
// (! $DETAILTEXTURE) && ( $DETAIL_BLEND_MODE != 0 )
// ( $FLASHLIGHT == 0 ) && ( $FLASHLIGHTSHADOWS == 1 )
// ( $SELFILLUM == 0 ) && ( $SELFILLUMFRESNEL == 1 )
// ( $FLASHLIGHT == 1 ) && ( $SELFILLUMFRESNEL == 1 )
// ( $FLASHLIGHT == 1 ) && ( $SELFILLUM == 1 )
// ( $WORLD_NORMAL == 1 ) && ( $FLASHLIGHTSHADOWS == 1 ) && ( $NUM_LIGHTS != 0 ) && ( $WRITEWATERFOGTODESTALPHA == 1 )
// defined $PIXELFOGTYPE && defined $WRITEWATERFOGTODESTALPHA && ( $PIXELFOGTYPE != 1 ) && $WRITEWATERFOGTODESTALPHA
// defined $LIGHTING_PREVIEW && defined $FASTPATHENVMAPTINT && $LIGHTING_PREVIEW && $FASTPATHENVMAPTINT
// defined $LIGHTING_PREVIEW && defined $FASTPATHENVMAPCONTRAST && $LIGHTING_PREVIEW && $FASTPATHENVMAPCONTRAST
// defined $LIGHTING_PREVIEW && defined $FASTPATH && $LIGHTING_PREVIEW && $FASTPATH
// ($FLASHLIGHT || $FLASHLIGHTSHADOWS) && $LIGHTING_PREVIEW
// defined $PIXELFOGTYPE && defined $WRITEWATERFOGTODESTALPHA && ( $PIXELFOGTYPE != 1 ) && $WRITEWATERFOGTODESTALPHA
// defined $LIGHTING_PREVIEW && defined $FASTPATHENVMAPTINT && $LIGHTING_PREVIEW && $FASTPATHENVMAPTINT
// defined $LIGHTING_PREVIEW && defined $FASTPATHENVMAPCONTRAST && $LIGHTING_PREVIEW && $FASTPATHENVMAPCONTRAST
// defined $LIGHTING_PREVIEW && defined $FASTPATH && $LIGHTING_PREVIEW && $FASTPATH
// ($FLASHLIGHT || $FLASHLIGHTSHADOWS) && $LIGHTING_PREVIEW

#pragma once
#include "shaderlib/cshader.h"
class phong_ps20_Static_Index
{
	unsigned int m_nCUBEMAP : 2;
	unsigned int m_nSELFILLUM : 2;
	unsigned int m_nSELFILLUMFRESNEL : 2;
	unsigned int m_nFLASHLIGHT : 2;
	unsigned int m_nLIGHTWARPTEXTURE : 2;
	unsigned int m_nPHONGWARPTEXTURE : 2;
	unsigned int m_nWRINKLEMAP : 2;
	unsigned int m_nDETAIL_BLEND_MODE : 3;
	unsigned int m_nDETAILTEXTURE : 2;
	unsigned int m_nRIMLIGHT : 2;
	unsigned int m_nSHADER_SRGB_READ : 1;
	unsigned int m_nPHONG_HALFLAMBERT : 2;
#ifdef _DEBUG
	bool m_bCUBEMAP : 1;
	bool m_bSELFILLUM : 1;
	bool m_bSELFILLUMFRESNEL : 1;
	bool m_bFLASHLIGHT : 1;
	bool m_bLIGHTWARPTEXTURE : 1;
	bool m_bPHONGWARPTEXTURE : 1;
	bool m_bWRINKLEMAP : 1;
	bool m_bDETAIL_BLEND_MODE : 1;
	bool m_bDETAILTEXTURE : 1;
	bool m_bRIMLIGHT : 1;
	bool m_bSHADER_SRGB_READ : 1;
	bool m_bPHONG_HALFLAMBERT : 1;
#endif	// _DEBUG
public:
	void SetCUBEMAP( int i )
	{
		Assert( i >= 0 && i <= 1 );
		m_nCUBEMAP = i;
#ifdef _DEBUG
		m_bCUBEMAP = true;
#endif	// _DEBUG
	}

	void SetSELFILLUM( int i )
	{
		Assert( i >= 0 && i <= 1 );
		m_nSELFILLUM = i;
#ifdef _DEBUG
		m_bSELFILLUM = true;
#endif	// _DEBUG
	}

	void SetSELFILLUMFRESNEL( int i )
	{
		Assert( i >= 0 && i <= 1 );
		m_nSELFILLUMFRESNEL = i;
#ifdef _DEBUG
		m_bSELFILLUMFRESNEL = true;
#endif	// _DEBUG
	}

	void SetFLASHLIGHT( int i )
	{
		Assert( i >= 0 && i <= 1 );
		m_nFLASHLIGHT = i;
#ifdef _DEBUG
		m_bFLASHLIGHT = true;
#endif	// _DEBUG
	}

	void SetLIGHTWARPTEXTURE( int i )
	{
		Assert( i >= 0 && i <= 1 );
		m_nLIGHTWARPTEXTURE = i;
#ifdef _DEBUG
		m_bLIGHTWARPTEXTURE = true;
#endif	// _DEBUG
	}

	void SetPHONGWARPTEXTURE( int i )
	{
		Assert( i >= 0 && i <= 1 );
		m_nPHONGWARPTEXTURE = i;
#ifdef _DEBUG
		m_bPHONGWARPTEXTURE = true;
#endif	// _DEBUG
	}

	void SetWRINKLEMAP( int i )
	{
		Assert( i >= 0 && i <= 1 );
		m_nWRINKLEMAP = i;
#ifdef _DEBUG
		m_bWRINKLEMAP = true;
#endif	// _DEBUG
	}

	void SetDETAIL_BLEND_MODE( int i )
	{
		Assert( i >= 0 && i <= 6 );
		m_nDETAIL_BLEND_MODE = i;
#ifdef _DEBUG
		m_bDETAIL_BLEND_MODE = true;
#endif	// _DEBUG
	}

	void SetDETAILTEXTURE( int i )
	{
		Assert( i >= 0 && i <= 1 );
		m_nDETAILTEXTURE = i;
#ifdef _DEBUG
		m_bDETAILTEXTURE = true;
#endif	// _DEBUG
	}

	void SetRIMLIGHT( int i )
	{
		Assert( i >= 0 && i <= 1 );
		m_nRIMLIGHT = i;
#ifdef _DEBUG
		m_bRIMLIGHT = true;
#endif	// _DEBUG
	}

	void SetSHADER_SRGB_READ( int i )
	{
		Assert( i >= 0 && i <= 0 );
		m_nSHADER_SRGB_READ = i;
#ifdef _DEBUG
		m_bSHADER_SRGB_READ = true;
#endif	// _DEBUG
	}

	void SetPHONG_HALFLAMBERT( int i )
	{
		Assert( i >= 0 && i <= 1 );
		m_nPHONG_HALFLAMBERT = i;
#ifdef _DEBUG
		m_bPHONG_HALFLAMBERT = true;
#endif	// _DEBUG
	}

	phong_ps20_Static_Index( IShaderShadow* pShaderShadow, IMaterialVar** params )
	{
		m_nCUBEMAP = 0;
		m_nSELFILLUM = 0;
		m_nSELFILLUMFRESNEL = 0;
		m_nFLASHLIGHT = 0;
		m_nLIGHTWARPTEXTURE = 0;
		m_nPHONGWARPTEXTURE = 0;
		m_nWRINKLEMAP = 0;
		m_nDETAIL_BLEND_MODE = 0;
		m_nDETAILTEXTURE = 0;
		m_nRIMLIGHT = 0;
		m_nSHADER_SRGB_READ = 0;
		m_nPHONG_HALFLAMBERT = 0;
#ifdef _DEBUG
		m_bCUBEMAP = false;
		m_bSELFILLUM = false;
		m_bSELFILLUMFRESNEL = false;
		m_bFLASHLIGHT = false;
		m_bLIGHTWARPTEXTURE = false;
		m_bPHONGWARPTEXTURE = false;
		m_bWRINKLEMAP = false;
		m_bDETAIL_BLEND_MODE = false;
		m_bDETAILTEXTURE = false;
		m_bRIMLIGHT = false;
		m_bSHADER_SRGB_READ = false;
		m_bPHONG_HALFLAMBERT = false;
#endif	// _DEBUG
	}

	int GetIndex() const
	{
		Assert( m_bCUBEMAP && m_bSELFILLUM && m_bSELFILLUMFRESNEL && m_bFLASHLIGHT && m_bLIGHTWARPTEXTURE && m_bPHONGWARPTEXTURE && m_bWRINKLEMAP && m_bDETAIL_BLEND_MODE && m_bDETAILTEXTURE && m_bRIMLIGHT && m_bSHADER_SRGB_READ && m_bPHONG_HALFLAMBERT );
		AssertMsg( !( !m_nDETAILTEXTURE && ( m_nDETAIL_BLEND_MODE != 0 ) ), "Invalid combo combination ( !DETAILTEXTURE && ( DETAIL_BLEND_MODE != 0 ) )" );
		AssertMsg( !( ( m_nSELFILLUM == 0 ) && ( m_nSELFILLUMFRESNEL == 1 ) ), "Invalid combo combination ( ( SELFILLUM == 0 ) && ( SELFILLUMFRESNEL == 1 ) )" );
		AssertMsg( !( ( m_nFLASHLIGHT == 1 ) && ( m_nSELFILLUMFRESNEL == 1 ) ), "Invalid combo combination ( ( FLASHLIGHT == 1 ) && ( SELFILLUMFRESNEL == 1 ) )" );
		AssertMsg( !( ( m_nFLASHLIGHT == 1 ) && ( m_nSELFILLUM == 1 ) ), "Invalid combo combination ( ( FLASHLIGHT == 1 ) && ( SELFILLUM == 1 ) )" );
		return ( 20 * m_nCUBEMAP ) + ( 40 * m_nSELFILLUM ) + ( 80 * m_nSELFILLUMFRESNEL ) + ( 160 * m_nFLASHLIGHT ) + ( 320 * m_nLIGHTWARPTEXTURE ) + ( 640 * m_nPHONGWARPTEXTURE ) + ( 1280 * m_nWRINKLEMAP ) + ( 2560 * m_nDETAIL_BLEND_MODE ) + ( 17920 * m_nDETAILTEXTURE ) + ( 35840 * m_nRIMLIGHT ) + ( 71680 * m_nSHADER_SRGB_READ ) + ( 71680 * m_nPHONG_HALFLAMBERT ) + 0;
	}
};

#define shaderStaticTest_phong_ps20 psh_forgot_to_set_static_CUBEMAP + psh_forgot_to_set_static_SELFILLUM + psh_forgot_to_set_static_SELFILLUMFRESNEL + psh_forgot_to_set_static_FLASHLIGHT + psh_forgot_to_set_static_LIGHTWARPTEXTURE + psh_forgot_to_set_static_PHONGWARPTEXTURE + psh_forgot_to_set_static_WRINKLEMAP + psh_forgot_to_set_static_DETAIL_BLEND_MODE + psh_forgot_to_set_static_DETAILTEXTURE + psh_forgot_to_set_static_RIMLIGHT + psh_forgot_to_set_static_SHADER_SRGB_READ + psh_forgot_to_set_static_PHONG_HALFLAMBERT


class phong_ps20_Dynamic_Index
{
	unsigned int m_nWRITEWATERFOGTODESTALPHA : 2;
	unsigned int m_nPIXELFOGTYPE : 2;
	unsigned int m_nNUM_LIGHTS : 3;
#ifdef _DEBUG
	bool m_bWRITEWATERFOGTODESTALPHA : 1;
	bool m_bNUM_LIGHTS : 1;
#endif	// _DEBUG
public:
	void SetWRITEWATERFOGTODESTALPHA( int i )
	{
		Assert( i >= 0 && i <= 1 );
		m_nWRITEWATERFOGTODESTALPHA = i;
#ifdef _DEBUG
		m_bWRITEWATERFOGTODESTALPHA = true;
#endif	// _DEBUG
	}

	void SetPIXELFOGTYPE( int i )
	{
		Assert( i >= 0 && i <= 1 );
		m_nPIXELFOGTYPE = i;
	}

	void SetNUM_LIGHTS( int i )
	{
		Assert( i >= 0 && i <= 4 );
		m_nNUM_LIGHTS = i;
#ifdef _DEBUG
		m_bNUM_LIGHTS = true;
#endif	// _DEBUG
	}

	phong_ps20_Dynamic_Index( IShaderDynamicAPI* pShaderAPI )
	{
		m_nWRITEWATERFOGTODESTALPHA = 0;
		m_nPIXELFOGTYPE = ( pShaderAPI->GetSceneFogMode() == MATERIAL_FOG_LINEAR_BELOW_FOG_Z ) ;
		m_nNUM_LIGHTS = 0;
#ifdef _DEBUG
		m_bWRITEWATERFOGTODESTALPHA = false;
		m_bNUM_LIGHTS = false;
#endif	// _DEBUG
	}

	int GetIndex() const
	{
		Assert( m_bWRITEWATERFOGTODESTALPHA && m_bNUM_LIGHTS );
		AssertMsg( !( 1 && ( 1 && ( ( m_nPIXELFOGTYPE != 1 ) && m_nWRITEWATERFOGTODESTALPHA ) ) ), "Invalid combo combination ( 1 && ( 1 && ( ( PIXELFOGTYPE != 1 ) && WRITEWATERFOGTODESTALPHA ) ) )" );
		AssertMsg( !( 1 && ( 1 && ( ( m_nPIXELFOGTYPE != 1 ) && m_nWRITEWATERFOGTODESTALPHA ) ) ), "Invalid combo combination ( 1 && ( 1 && ( ( PIXELFOGTYPE != 1 ) && WRITEWATERFOGTODESTALPHA ) ) )" );
		return ( 1 * m_nWRITEWATERFOGTODESTALPHA ) + ( 2 * m_nPIXELFOGTYPE ) + ( 4 * m_nNUM_LIGHTS ) + 0;
	}
};

#define shaderDynamicTest_phong_ps20 psh_forgot_to_set_dynamic_WRITEWATERFOGTODESTALPHA + psh_forgot_to_set_dynamic_NUM_LIGHTS

