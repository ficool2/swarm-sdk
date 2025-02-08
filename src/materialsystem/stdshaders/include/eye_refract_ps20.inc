// ALL SKIP STATEMENTS THAT AFFECT THIS SHADER!!!
// ( $FLASHLIGHT != 0 ) && ( $NUM_LIGHTS > 0 )
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
class eye_refract_ps20_Static_Index
{
	unsigned int m_nFLASHLIGHT : 2;
	unsigned int m_nLIGHTWARPTEXTURE : 2;
	unsigned int m_nWORLD_NORMAL : 1;
#ifdef _DEBUG
	bool m_bFLASHLIGHT : 1;
	bool m_bLIGHTWARPTEXTURE : 1;
	bool m_bWORLD_NORMAL : 1;
#endif	// _DEBUG
public:
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

	void SetWORLD_NORMAL( int i )
	{
		Assert( i >= 0 && i <= 0 );
		m_nWORLD_NORMAL = i;
#ifdef _DEBUG
		m_bWORLD_NORMAL = true;
#endif	// _DEBUG
	}

	eye_refract_ps20_Static_Index( IShaderShadow* pShaderShadow, IMaterialVar** params )
	{
		m_nFLASHLIGHT = 0;
		m_nLIGHTWARPTEXTURE = 0;
		m_nWORLD_NORMAL = 0;
#ifdef _DEBUG
		m_bFLASHLIGHT = false;
		m_bLIGHTWARPTEXTURE = false;
		m_bWORLD_NORMAL = false;
#endif	// _DEBUG
	}

	int GetIndex() const
	{
		Assert( m_bFLASHLIGHT && m_bLIGHTWARPTEXTURE && m_bWORLD_NORMAL );
		return ( 6 * m_nFLASHLIGHT ) + ( 12 * m_nLIGHTWARPTEXTURE ) + ( 24 * m_nWORLD_NORMAL ) + 0;
	}
};

#define shaderStaticTest_eye_refract_ps20 psh_forgot_to_set_static_FLASHLIGHT + psh_forgot_to_set_static_LIGHTWARPTEXTURE + psh_forgot_to_set_static_WORLD_NORMAL


class eye_refract_ps20_Dynamic_Index
{
	unsigned int m_nPIXELFOGTYPE : 2;
	unsigned int m_nNUM_LIGHTS : 2;
#ifdef _DEBUG
	bool m_bNUM_LIGHTS : 1;
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

	eye_refract_ps20_Dynamic_Index( IShaderDynamicAPI* pShaderAPI )
	{
		m_nPIXELFOGTYPE = ( pShaderAPI->GetSceneFogMode() == MATERIAL_FOG_LINEAR_BELOW_FOG_Z ) ;
		m_nNUM_LIGHTS = 0;
#ifdef _DEBUG
		m_bNUM_LIGHTS = false;
#endif	// _DEBUG
	}

	int GetIndex() const
	{
		Assert( m_bNUM_LIGHTS );
		return ( 1 * m_nPIXELFOGTYPE ) + ( 2 * m_nNUM_LIGHTS ) + 0;
	}
};

#define shaderDynamicTest_eye_refract_ps20 psh_forgot_to_set_dynamic_NUM_LIGHTS

