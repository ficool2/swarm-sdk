// ALL SKIP STATEMENTS THAT AFFECT THIS SHADER!!!
// defined $PIXELFOGTYPE && defined $WRITEWATERFOGTODESTALPHA && ( $PIXELFOGTYPE != 1 ) && $WRITEWATERFOGTODESTALPHA
// defined $LIGHTING_PREVIEW && defined $FASTPATHENVMAPTINT && $LIGHTING_PREVIEW && $FASTPATHENVMAPTINT
// defined $LIGHTING_PREVIEW && defined $FASTPATHENVMAPCONTRAST && $LIGHTING_PREVIEW && $FASTPATHENVMAPCONTRAST
// defined $LIGHTING_PREVIEW && defined $FASTPATH && $LIGHTING_PREVIEW && $FASTPATH
// ($FLASHLIGHT || $FLASHLIGHTSHADOWS) && $LIGHTING_PREVIEW

#pragma once
#include "shaderlib/cshader.h"
class teeth_bump_ps20_Static_Index
{
public:
	teeth_bump_ps20_Static_Index( IShaderShadow* pShaderShadow, IMaterialVar** params )
	{
	}

	int GetIndex() const
	{
		return 0;
	}
};

#define shaderStaticTest_teeth_bump_ps20 1


class teeth_bump_ps20_Dynamic_Index
{
	unsigned int m_nPIXELFOGTYPE : 2;
	unsigned int m_nNUM_LIGHTS : 2;
	unsigned int m_nAMBIENT_LIGHT : 2;
#ifdef _DEBUG
	bool m_bNUM_LIGHTS : 1;
	bool m_bAMBIENT_LIGHT : 1;
#endif	// _DEBUG
public:
	void SetPIXELFOGTYPE( int i )
	{
		Assert( i >= 0 && i <= 1 );
		m_nPIXELFOGTYPE = i;
	}

	void SetNUM_LIGHTS( int i )
	{
		Assert( i >= 0 && i <= 2 );
		m_nNUM_LIGHTS = i;
#ifdef _DEBUG
		m_bNUM_LIGHTS = true;
#endif	// _DEBUG
	}

	void SetAMBIENT_LIGHT( int i )
	{
		Assert( i >= 0 && i <= 1 );
		m_nAMBIENT_LIGHT = i;
#ifdef _DEBUG
		m_bAMBIENT_LIGHT = true;
#endif	// _DEBUG
	}

	teeth_bump_ps20_Dynamic_Index( IShaderDynamicAPI* pShaderAPI )
	{
		m_nPIXELFOGTYPE = ( pShaderAPI->GetSceneFogMode() == MATERIAL_FOG_LINEAR_BELOW_FOG_Z ) ;
		m_nNUM_LIGHTS = 0;
		m_nAMBIENT_LIGHT = 0;
#ifdef _DEBUG
		m_bNUM_LIGHTS = false;
		m_bAMBIENT_LIGHT = false;
#endif	// _DEBUG
	}

	int GetIndex() const
	{
		Assert( m_bNUM_LIGHTS && m_bAMBIENT_LIGHT );
		return ( 1 * m_nPIXELFOGTYPE ) + ( 2 * m_nNUM_LIGHTS ) + ( 6 * m_nAMBIENT_LIGHT ) + 0;
	}
};

#define shaderDynamicTest_teeth_bump_ps20 psh_forgot_to_set_dynamic_NUM_LIGHTS + psh_forgot_to_set_dynamic_AMBIENT_LIGHT

