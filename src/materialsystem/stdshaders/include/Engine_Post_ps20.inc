// ALL SKIP STATEMENTS THAT AFFECT THIS SHADER!!!
// ( $CONVERT_FROM_LINEAR == 0 ) && ( $CONVERT_TO_LINEAR == 1 )
// ( $TOOL_MODE == 0 ) && ( $CONVERT_TO_LINEAR == 1 )
// ( $LOCAL_CONTRAST_ENABLE == 0 ) && ( $BLURRED_VIGNETTE_ENABLE == 1 )
// ( $TOOL_MODE == 0 ) && $TV_GAMMA
// ( $TOOL_MODE == 0 ) && $DESATURATEENABLE
// defined $PIXELFOGTYPE && defined $WRITEWATERFOGTODESTALPHA && ( $PIXELFOGTYPE != 1 ) && $WRITEWATERFOGTODESTALPHA
// defined $LIGHTING_PREVIEW && defined $FASTPATHENVMAPTINT && $LIGHTING_PREVIEW && $FASTPATHENVMAPTINT
// defined $LIGHTING_PREVIEW && defined $FASTPATHENVMAPCONTRAST && $LIGHTING_PREVIEW && $FASTPATHENVMAPCONTRAST
// defined $LIGHTING_PREVIEW && defined $FASTPATH && $LIGHTING_PREVIEW && $FASTPATH
// ($FLASHLIGHT || $FLASHLIGHTSHADOWS) && $LIGHTING_PREVIEW

#pragma once
#include "shaderlib/cshader.h"
class engine_post_ps20_Static_Index
{
	unsigned int m_nTOOL_MODE : 2;
	unsigned int m_nDEPTH_BLUR_ENABLE : 2;
#ifdef _DEBUG
	bool m_bTOOL_MODE : 1;
	bool m_bDEPTH_BLUR_ENABLE : 1;
#endif	// _DEBUG
public:
	void SetTOOL_MODE( int i )
	{
		Assert( i >= 0 && i <= 1 );
		m_nTOOL_MODE = i;
#ifdef _DEBUG
		m_bTOOL_MODE = true;
#endif	// _DEBUG
	}

	void SetDEPTH_BLUR_ENABLE( int i )
	{
		Assert( i >= 0 && i <= 1 );
		m_nDEPTH_BLUR_ENABLE = i;
#ifdef _DEBUG
		m_bDEPTH_BLUR_ENABLE = true;
#endif	// _DEBUG
	}

	engine_post_ps20_Static_Index( IShaderShadow* pShaderShadow, IMaterialVar** params )
	{
		m_nTOOL_MODE = 0;
		m_nDEPTH_BLUR_ENABLE = 0;
#ifdef _DEBUG
		m_bTOOL_MODE = false;
		m_bDEPTH_BLUR_ENABLE = false;
#endif	// _DEBUG
	}

	int GetIndex() const
	{
		Assert( m_bTOOL_MODE && m_bDEPTH_BLUR_ENABLE );
		return ( 8 * m_nTOOL_MODE ) + ( 16 * m_nDEPTH_BLUR_ENABLE ) + 0;
	}
};

#define shaderStaticTest_engine_post_ps20 psh_forgot_to_set_static_TOOL_MODE + psh_forgot_to_set_static_DEPTH_BLUR_ENABLE


class engine_post_ps20_Dynamic_Index
{
	unsigned int m_nAA_ENABLE : 1;
	unsigned int m_nCOL_CORRECT_NUM_LOOKUPS : 3;
	unsigned int m_nVOMIT_ENABLE : 2;
#ifdef _DEBUG
	bool m_bAA_ENABLE : 1;
	bool m_bCOL_CORRECT_NUM_LOOKUPS : 1;
	bool m_bVOMIT_ENABLE : 1;
#endif	// _DEBUG
public:
	void SetAA_ENABLE( int i )
	{
		Assert( i >= 0 && i <= 0 );
		m_nAA_ENABLE = i;
#ifdef _DEBUG
		m_bAA_ENABLE = true;
#endif	// _DEBUG
	}

	void SetCOL_CORRECT_NUM_LOOKUPS( int i )
	{
		Assert( i >= 0 && i <= 3 );
		m_nCOL_CORRECT_NUM_LOOKUPS = i;
#ifdef _DEBUG
		m_bCOL_CORRECT_NUM_LOOKUPS = true;
#endif	// _DEBUG
	}

	void SetVOMIT_ENABLE( int i )
	{
		Assert( i >= 0 && i <= 1 );
		m_nVOMIT_ENABLE = i;
#ifdef _DEBUG
		m_bVOMIT_ENABLE = true;
#endif	// _DEBUG
	}

	engine_post_ps20_Dynamic_Index( IShaderDynamicAPI* pShaderAPI )
	{
		m_nAA_ENABLE = 0;
		m_nCOL_CORRECT_NUM_LOOKUPS = 0;
		m_nVOMIT_ENABLE = 0;
#ifdef _DEBUG
		m_bAA_ENABLE = false;
		m_bCOL_CORRECT_NUM_LOOKUPS = false;
		m_bVOMIT_ENABLE = false;
#endif	// _DEBUG
	}

	int GetIndex() const
	{
		Assert( m_bAA_ENABLE && m_bCOL_CORRECT_NUM_LOOKUPS && m_bVOMIT_ENABLE );
		return ( 1 * m_nAA_ENABLE ) + ( 1 * m_nCOL_CORRECT_NUM_LOOKUPS ) + ( 4 * m_nVOMIT_ENABLE ) + 0;
	}
};

#define shaderDynamicTest_engine_post_ps20 psh_forgot_to_set_dynamic_AA_ENABLE + psh_forgot_to_set_dynamic_COL_CORRECT_NUM_LOOKUPS + psh_forgot_to_set_dynamic_VOMIT_ENABLE

