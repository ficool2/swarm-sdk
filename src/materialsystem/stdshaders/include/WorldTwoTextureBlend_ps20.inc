// ALL SKIP STATEMENTS THAT AFFECT THIS SHADER!!!
// $DETAILTEXTURE && ( $BUMPMAP && !$DETAIL_ALPHA_MASK_BASE_TEXTURE )
// !$BUMPMAP && $DIFFUSEBUMPMAP
// $VERTEXCOLOR && $BUMPMAP
// $FLASHLIGHT && $SELFILLUM
// $FLASHLIGHT && $DETAIL_ALPHA_MASK_BASE_TEXTURE
// $FLASHLIGHT && ($BUMPMAP || $DIFFUSEBUMPMAP)
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
// defined $PIXELFOGTYPE && defined $WRITEWATERFOGTODESTALPHA && ( $PIXELFOGTYPE != 1 ) && $WRITEWATERFOGTODESTALPHA
// defined $LIGHTING_PREVIEW && defined $FASTPATHENVMAPTINT && $LIGHTING_PREVIEW && $FASTPATHENVMAPTINT
// defined $LIGHTING_PREVIEW && defined $FASTPATHENVMAPCONTRAST && $LIGHTING_PREVIEW && $FASTPATHENVMAPCONTRAST
// defined $LIGHTING_PREVIEW && defined $FASTPATH && $LIGHTING_PREVIEW && $FASTPATH
// ($FLASHLIGHT || $FLASHLIGHTSHADOWS) && $LIGHTING_PREVIEW

#pragma once
#include "shaderlib/cshader.h"
class worldtwotextureblend_ps20_Static_Index
{
	unsigned int m_nDETAILTEXTURE : 2;
	unsigned int m_nBUMPMAP : 2;
	unsigned int m_nVERTEXCOLOR : 2;
	unsigned int m_nSELFILLUM : 2;
	unsigned int m_nDIFFUSEBUMPMAP : 2;
	unsigned int m_nDETAIL_ALPHA_MASK_BASE_TEXTURE : 2;
	unsigned int m_nFLASHLIGHT : 2;
	unsigned int m_nSEAMLESS : 2;
	unsigned int m_nSHADER_SRGB_READ : 1;
#ifdef _DEBUG
	bool m_bDETAILTEXTURE : 1;
	bool m_bBUMPMAP : 1;
	bool m_bVERTEXCOLOR : 1;
	bool m_bSELFILLUM : 1;
	bool m_bDIFFUSEBUMPMAP : 1;
	bool m_bDETAIL_ALPHA_MASK_BASE_TEXTURE : 1;
	bool m_bFLASHLIGHT : 1;
	bool m_bSEAMLESS : 1;
	bool m_bSHADER_SRGB_READ : 1;
#endif	// _DEBUG
public:
	void SetDETAILTEXTURE( int i )
	{
		Assert( i >= 0 && i <= 1 );
		m_nDETAILTEXTURE = i;
#ifdef _DEBUG
		m_bDETAILTEXTURE = true;
#endif	// _DEBUG
	}

	void SetBUMPMAP( int i )
	{
		Assert( i >= 0 && i <= 1 );
		m_nBUMPMAP = i;
#ifdef _DEBUG
		m_bBUMPMAP = true;
#endif	// _DEBUG
	}

	void SetVERTEXCOLOR( int i )
	{
		Assert( i >= 0 && i <= 1 );
		m_nVERTEXCOLOR = i;
#ifdef _DEBUG
		m_bVERTEXCOLOR = true;
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

	void SetDIFFUSEBUMPMAP( int i )
	{
		Assert( i >= 0 && i <= 1 );
		m_nDIFFUSEBUMPMAP = i;
#ifdef _DEBUG
		m_bDIFFUSEBUMPMAP = true;
#endif	// _DEBUG
	}

	void SetDETAIL_ALPHA_MASK_BASE_TEXTURE( int i )
	{
		Assert( i >= 0 && i <= 1 );
		m_nDETAIL_ALPHA_MASK_BASE_TEXTURE = i;
#ifdef _DEBUG
		m_bDETAIL_ALPHA_MASK_BASE_TEXTURE = true;
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

	void SetSEAMLESS( int i )
	{
		Assert( i >= 0 && i <= 1 );
		m_nSEAMLESS = i;
#ifdef _DEBUG
		m_bSEAMLESS = true;
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

	worldtwotextureblend_ps20_Static_Index( IShaderShadow* pShaderShadow, IMaterialVar** params )
	{
		m_nDETAILTEXTURE = 0;
		m_nBUMPMAP = 0;
		m_nVERTEXCOLOR = 0;
		m_nSELFILLUM = 0;
		m_nDIFFUSEBUMPMAP = 0;
		m_nDETAIL_ALPHA_MASK_BASE_TEXTURE = 0;
		m_nFLASHLIGHT = 0;
		m_nSEAMLESS = 0;
		m_nSHADER_SRGB_READ = 0;
#ifdef _DEBUG
		m_bDETAILTEXTURE = false;
		m_bBUMPMAP = false;
		m_bVERTEXCOLOR = false;
		m_bSELFILLUM = false;
		m_bDIFFUSEBUMPMAP = false;
		m_bDETAIL_ALPHA_MASK_BASE_TEXTURE = false;
		m_bFLASHLIGHT = false;
		m_bSEAMLESS = false;
		m_bSHADER_SRGB_READ = false;
#endif	// _DEBUG
	}

	int GetIndex() const
	{
		Assert( m_bDETAILTEXTURE && m_bBUMPMAP && m_bVERTEXCOLOR && m_bSELFILLUM && m_bDIFFUSEBUMPMAP && m_bDETAIL_ALPHA_MASK_BASE_TEXTURE && m_bFLASHLIGHT && m_bSEAMLESS && m_bSHADER_SRGB_READ );
		AssertMsg( !( m_nDETAILTEXTURE && ( m_nBUMPMAP && !m_nDETAIL_ALPHA_MASK_BASE_TEXTURE ) ), "Invalid combo combination ( DETAILTEXTURE && ( BUMPMAP && !DETAIL_ALPHA_MASK_BASE_TEXTURE ) )" );
		AssertMsg( !( !m_nBUMPMAP && m_nDIFFUSEBUMPMAP ), "Invalid combo combination ( !BUMPMAP && DIFFUSEBUMPMAP )" );
		AssertMsg( !( m_nVERTEXCOLOR && m_nBUMPMAP ), "Invalid combo combination ( VERTEXCOLOR && BUMPMAP )" );
		AssertMsg( !( m_nFLASHLIGHT && m_nSELFILLUM ), "Invalid combo combination ( FLASHLIGHT && SELFILLUM )" );
		AssertMsg( !( m_nFLASHLIGHT && m_nDETAIL_ALPHA_MASK_BASE_TEXTURE ), "Invalid combo combination ( FLASHLIGHT && DETAIL_ALPHA_MASK_BASE_TEXTURE )" );
		AssertMsg( !( m_nFLASHLIGHT && ( m_nBUMPMAP || m_nDIFFUSEBUMPMAP ) ), "Invalid combo combination ( FLASHLIGHT && ( BUMPMAP || DIFFUSEBUMPMAP ) )" );
		return ( 4 * m_nDETAILTEXTURE ) + ( 8 * m_nBUMPMAP ) + ( 16 * m_nVERTEXCOLOR ) + ( 32 * m_nSELFILLUM ) + ( 64 * m_nDIFFUSEBUMPMAP ) + ( 128 * m_nDETAIL_ALPHA_MASK_BASE_TEXTURE ) + ( 256 * m_nFLASHLIGHT ) + ( 512 * m_nSEAMLESS ) + ( 1024 * m_nSHADER_SRGB_READ ) + 0;
	}
};

#define shaderStaticTest_worldtwotextureblend_ps20 psh_forgot_to_set_static_DETAILTEXTURE + psh_forgot_to_set_static_BUMPMAP + psh_forgot_to_set_static_VERTEXCOLOR + psh_forgot_to_set_static_SELFILLUM + psh_forgot_to_set_static_DIFFUSEBUMPMAP + psh_forgot_to_set_static_DETAIL_ALPHA_MASK_BASE_TEXTURE + psh_forgot_to_set_static_FLASHLIGHT + psh_forgot_to_set_static_SEAMLESS + psh_forgot_to_set_static_SHADER_SRGB_READ


class worldtwotextureblend_ps20_Dynamic_Index
{
	unsigned int m_nWRITEWATERFOGTODESTALPHA : 2;
	unsigned int m_nPIXELFOGTYPE : 2;
#ifdef _DEBUG
	bool m_bWRITEWATERFOGTODESTALPHA : 1;
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

	worldtwotextureblend_ps20_Dynamic_Index( IShaderDynamicAPI* pShaderAPI )
	{
		m_nWRITEWATERFOGTODESTALPHA = 0;
		m_nPIXELFOGTYPE = ( pShaderAPI->GetSceneFogMode() == MATERIAL_FOG_LINEAR_BELOW_FOG_Z ) ;
#ifdef _DEBUG
		m_bWRITEWATERFOGTODESTALPHA = false;
#endif	// _DEBUG
	}

	int GetIndex() const
	{
		Assert( m_bWRITEWATERFOGTODESTALPHA );
		AssertMsg( !( 1 && ( 1 && ( ( m_nPIXELFOGTYPE != 1 ) && m_nWRITEWATERFOGTODESTALPHA ) ) ), "Invalid combo combination ( 1 && ( 1 && ( ( PIXELFOGTYPE != 1 ) && WRITEWATERFOGTODESTALPHA ) ) )" );
		AssertMsg( !( 1 && ( 1 && ( ( m_nPIXELFOGTYPE != 1 ) && m_nWRITEWATERFOGTODESTALPHA ) ) ), "Invalid combo combination ( 1 && ( 1 && ( ( PIXELFOGTYPE != 1 ) && WRITEWATERFOGTODESTALPHA ) ) )" );
		AssertMsg( !( 1 && ( 1 && ( ( m_nPIXELFOGTYPE != 1 ) && m_nWRITEWATERFOGTODESTALPHA ) ) ), "Invalid combo combination ( 1 && ( 1 && ( ( PIXELFOGTYPE != 1 ) && WRITEWATERFOGTODESTALPHA ) ) )" );
		return ( 1 * m_nWRITEWATERFOGTODESTALPHA ) + ( 2 * m_nPIXELFOGTYPE ) + 0;
	}
};

#define shaderDynamicTest_worldtwotextureblend_ps20 psh_forgot_to_set_dynamic_WRITEWATERFOGTODESTALPHA

