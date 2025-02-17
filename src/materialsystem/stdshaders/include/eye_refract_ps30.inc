// ALL SKIP STATEMENTS THAT AFFECT THIS SHADER!!!
// ( $FLASHLIGHT != 0 ) && ( $NUM_LIGHTS > 0 )
// ( $FLASHLIGHT == 0 ) && ( $FLASHLIGHTSHADOWS == 1 )
// ( $RAYTRACESPHERE == 0 ) && ( $SPHERETEXKILLCOMBO == 1 )
// ( $WORLD_NORMAL ) && ( $FLASHLIGHTSHADOWS != 0 ) && ( $NUM_LIGHTS != 0 )
// ( $FLASHLIGHT == 0 ) && ( $UBERLIGHT == 1 )
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
class eye_refract_ps30_Static_Index
{
	unsigned int m_nFLASHLIGHT : 2;
	unsigned int m_nLIGHTWARPTEXTURE : 2;
	unsigned int m_nSPHERETEXKILLCOMBO : 2;
	unsigned int m_nRAYTRACESPHERE : 2;
	unsigned int m_nFLASHLIGHTDEPTHFILTERMODE : 2;
	unsigned int m_nWORLD_NORMAL : 2;
#ifdef _DEBUG
	bool m_bFLASHLIGHT : 1;
	bool m_bLIGHTWARPTEXTURE : 1;
	bool m_bSPHERETEXKILLCOMBO : 1;
	bool m_bRAYTRACESPHERE : 1;
	bool m_bFLASHLIGHTDEPTHFILTERMODE : 1;
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

	void SetSPHERETEXKILLCOMBO( int i )
	{
		Assert( i >= 0 && i <= 1 );
		m_nSPHERETEXKILLCOMBO = i;
#ifdef _DEBUG
		m_bSPHERETEXKILLCOMBO = true;
#endif	// _DEBUG
	}

	void SetRAYTRACESPHERE( int i )
	{
		Assert( i >= 0 && i <= 1 );
		m_nRAYTRACESPHERE = i;
#ifdef _DEBUG
		m_bRAYTRACESPHERE = true;
#endif	// _DEBUG
	}

	void SetFLASHLIGHTDEPTHFILTERMODE( int i )
	{
		Assert( i >= 0 && i <= 2 );
		m_nFLASHLIGHTDEPTHFILTERMODE = i;
#ifdef _DEBUG
		m_bFLASHLIGHTDEPTHFILTERMODE = true;
#endif	// _DEBUG
	}

	void SetWORLD_NORMAL( int i )
	{
		Assert( i >= 0 && i <= 1 );
		m_nWORLD_NORMAL = i;
#ifdef _DEBUG
		m_bWORLD_NORMAL = true;
#endif	// _DEBUG
	}

	eye_refract_ps30_Static_Index( IShaderShadow* pShaderShadow, IMaterialVar** params )
	{
		m_nFLASHLIGHT = 0;
		m_nLIGHTWARPTEXTURE = 0;
		m_nSPHERETEXKILLCOMBO = 0;
		m_nRAYTRACESPHERE = 0;
		m_nFLASHLIGHTDEPTHFILTERMODE = 0;
		m_nWORLD_NORMAL = 0;
#ifdef _DEBUG
		m_bFLASHLIGHT = false;
		m_bLIGHTWARPTEXTURE = false;
		m_bSPHERETEXKILLCOMBO = false;
		m_bRAYTRACESPHERE = false;
		m_bFLASHLIGHTDEPTHFILTERMODE = false;
		m_bWORLD_NORMAL = false;
#endif	// _DEBUG
	}

	int GetIndex() const
	{
		Assert( m_bFLASHLIGHT && m_bLIGHTWARPTEXTURE && m_bSPHERETEXKILLCOMBO && m_bRAYTRACESPHERE && m_bFLASHLIGHTDEPTHFILTERMODE && m_bWORLD_NORMAL );
		AssertMsg( !( ( m_nRAYTRACESPHERE == 0 ) && ( m_nSPHERETEXKILLCOMBO == 1 ) ), "Invalid combo combination ( ( RAYTRACESPHERE == 0 ) && ( SPHERETEXKILLCOMBO == 1 ) )" );
		return ( 40 * m_nFLASHLIGHT ) + ( 80 * m_nLIGHTWARPTEXTURE ) + ( 160 * m_nSPHERETEXKILLCOMBO ) + ( 320 * m_nRAYTRACESPHERE ) + ( 640 * m_nFLASHLIGHTDEPTHFILTERMODE ) + ( 1920 * m_nWORLD_NORMAL ) + 0;
	}
};

#define shaderStaticTest_eye_refract_ps30 psh_forgot_to_set_static_FLASHLIGHT + psh_forgot_to_set_static_LIGHTWARPTEXTURE + psh_forgot_to_set_static_SPHERETEXKILLCOMBO + psh_forgot_to_set_static_RAYTRACESPHERE + psh_forgot_to_set_static_FLASHLIGHTDEPTHFILTERMODE + psh_forgot_to_set_static_WORLD_NORMAL


class eye_refract_ps30_Dynamic_Index
{
	unsigned int m_nPIXELFOGTYPE : 2;
	unsigned int m_nNUM_LIGHTS : 3;
	unsigned int m_nFLASHLIGHTSHADOWS : 2;
	unsigned int m_nUBERLIGHT : 2;
#ifdef _DEBUG
	bool m_bNUM_LIGHTS : 1;
	bool m_bFLASHLIGHTSHADOWS : 1;
	bool m_bUBERLIGHT : 1;
#endif	// _DEBUG
public:
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

	void SetFLASHLIGHTSHADOWS( int i )
	{
		Assert( i >= 0 && i <= 1 );
		m_nFLASHLIGHTSHADOWS = i;
#ifdef _DEBUG
		m_bFLASHLIGHTSHADOWS = true;
#endif	// _DEBUG
	}

	void SetUBERLIGHT( int i )
	{
		Assert( i >= 0 && i <= 1 );
		m_nUBERLIGHT = i;
#ifdef _DEBUG
		m_bUBERLIGHT = true;
#endif	// _DEBUG
	}

	eye_refract_ps30_Dynamic_Index( IShaderDynamicAPI* pShaderAPI )
	{
		m_nPIXELFOGTYPE = ( pShaderAPI->GetSceneFogMode() == MATERIAL_FOG_LINEAR_BELOW_FOG_Z ) ;
		m_nNUM_LIGHTS = 0;
		m_nFLASHLIGHTSHADOWS = 0;
		m_nUBERLIGHT = 0;
#ifdef _DEBUG
		m_bNUM_LIGHTS = false;
		m_bFLASHLIGHTSHADOWS = false;
		m_bUBERLIGHT = false;
#endif	// _DEBUG
	}

	int GetIndex() const
	{
		Assert( m_bNUM_LIGHTS && m_bFLASHLIGHTSHADOWS && m_bUBERLIGHT );
		return ( 1 * m_nPIXELFOGTYPE ) + ( 2 * m_nNUM_LIGHTS ) + ( 10 * m_nFLASHLIGHTSHADOWS ) + ( 20 * m_nUBERLIGHT ) + 0;
	}
};

#define shaderDynamicTest_eye_refract_ps30 psh_forgot_to_set_dynamic_NUM_LIGHTS + psh_forgot_to_set_dynamic_FLASHLIGHTSHADOWS + psh_forgot_to_set_dynamic_UBERLIGHT

