// ALL SKIP STATEMENTS THAT AFFECT THIS SHADER!!!
// defined $PIXELFOGTYPE && defined $WRITEWATERFOGTODESTALPHA && ( $PIXELFOGTYPE != 1 ) && $WRITEWATERFOGTODESTALPHA
// defined $LIGHTING_PREVIEW && defined $FASTPATHENVMAPTINT && $LIGHTING_PREVIEW && $FASTPATHENVMAPTINT
// defined $LIGHTING_PREVIEW && defined $FASTPATHENVMAPCONTRAST && $LIGHTING_PREVIEW && $FASTPATHENVMAPCONTRAST
// defined $LIGHTING_PREVIEW && defined $FASTPATH && $LIGHTING_PREVIEW && $FASTPATH
// ($FLASHLIGHT || $FLASHLIGHTSHADOWS) && $LIGHTING_PREVIEW

#pragma once
#include "shaderlib/cshader.h"
class downsample_nohdr_ps20_Static_Index
{
	unsigned int m_nBLOOMTYPE : 2;
#ifdef _DEBUG
	bool m_bBLOOMTYPE : 1;
#endif	// _DEBUG
public:
	void SetBLOOMTYPE( int i )
	{
		Assert( i >= 0 && i <= 1 );
		m_nBLOOMTYPE = i;
#ifdef _DEBUG
		m_bBLOOMTYPE = true;
#endif	// _DEBUG
	}

	downsample_nohdr_ps20_Static_Index( IShaderShadow* pShaderShadow, IMaterialVar** params )
	{
		m_nBLOOMTYPE = 0;
#ifdef _DEBUG
		m_bBLOOMTYPE = false;
#endif	// _DEBUG
	}

	int GetIndex() const
	{
		Assert( m_bBLOOMTYPE );
		return ( 1 * m_nBLOOMTYPE ) + 0;
	}
};

#define shaderStaticTest_downsample_nohdr_ps20 psh_forgot_to_set_static_BLOOMTYPE


class downsample_nohdr_ps20_Dynamic_Index
{
public:
	downsample_nohdr_ps20_Dynamic_Index( IShaderDynamicAPI* pShaderAPI )
	{
	}

	int GetIndex() const
	{
		return 0;
	}
};

#define shaderDynamicTest_downsample_nohdr_ps20 1

