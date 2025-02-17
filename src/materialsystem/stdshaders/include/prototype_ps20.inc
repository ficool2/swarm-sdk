// ALL SKIP STATEMENTS THAT AFFECT THIS SHADER!!!
// defined $PIXELFOGTYPE && defined $WRITEWATERFOGTODESTALPHA && ( $PIXELFOGTYPE != 1 ) && $WRITEWATERFOGTODESTALPHA
// defined $LIGHTING_PREVIEW && defined $FASTPATHENVMAPTINT && $LIGHTING_PREVIEW && $FASTPATHENVMAPTINT
// defined $LIGHTING_PREVIEW && defined $FASTPATHENVMAPCONTRAST && $LIGHTING_PREVIEW && $FASTPATHENVMAPCONTRAST
// defined $LIGHTING_PREVIEW && defined $FASTPATH && $LIGHTING_PREVIEW && $FASTPATH
// ($FLASHLIGHT || $FLASHLIGHTSHADOWS) && $LIGHTING_PREVIEW

#pragma once
#include "shaderlib/cshader.h"
class prototype_ps20_Static_Index
{
	unsigned int m_nVERTEXCOLOR : 2;
#ifdef _DEBUG
	bool m_bVERTEXCOLOR : 1;
#endif	// _DEBUG
public:
	void SetVERTEXCOLOR( int i )
	{
		Assert( i >= 0 && i <= 1 );
		m_nVERTEXCOLOR = i;
#ifdef _DEBUG
		m_bVERTEXCOLOR = true;
#endif	// _DEBUG
	}

	prototype_ps20_Static_Index( IShaderShadow* pShaderShadow, IMaterialVar** params )
	{
		m_nVERTEXCOLOR = 0;
#ifdef _DEBUG
		m_bVERTEXCOLOR = false;
#endif	// _DEBUG
	}

	int GetIndex() const
	{
		Assert( m_bVERTEXCOLOR );
		return ( 2 * m_nVERTEXCOLOR ) + 0;
	}
};

#define shaderStaticTest_prototype_ps20 psh_forgot_to_set_static_VERTEXCOLOR


class prototype_ps20_Dynamic_Index
{
	unsigned int m_nAMBIENT_LIGHT : 2;
#ifdef _DEBUG
	bool m_bAMBIENT_LIGHT : 1;
#endif	// _DEBUG
public:
	void SetAMBIENT_LIGHT( int i )
	{
		Assert( i >= 0 && i <= 1 );
		m_nAMBIENT_LIGHT = i;
#ifdef _DEBUG
		m_bAMBIENT_LIGHT = true;
#endif	// _DEBUG
	}

	prototype_ps20_Dynamic_Index( IShaderDynamicAPI* pShaderAPI )
	{
		m_nAMBIENT_LIGHT = 0;
#ifdef _DEBUG
		m_bAMBIENT_LIGHT = false;
#endif	// _DEBUG
	}

	int GetIndex() const
	{
		Assert( m_bAMBIENT_LIGHT );
		return ( 1 * m_nAMBIENT_LIGHT ) + 0;
	}
};

#define shaderDynamicTest_prototype_ps20 psh_forgot_to_set_dynamic_AMBIENT_LIGHT

