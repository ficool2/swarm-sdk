#include "tier1/convar.h"

#define STUB __debugbreak();

ICvar* g_pCVar = nullptr;

void ConVar_Register( int nCVarFlag, IConCommandBaseAccessor* pAccessor )
{
	//STUB
}

void ConVar_Unregister( )
{
	//STUB
}

ConCommandBase::ConCommandBase()
{
	m_bRegistered = false;
	m_pszName = nullptr;
	m_pszHelpString = nullptr;
	m_nFlags = 0;
	m_pNext = nullptr;
}

ConCommandBase::~ConCommandBase()
{
}

bool ConCommandBase::IsCommand() const
{
	STUB
	return false;
}

bool ConCommandBase::IsFlagSet( int nFlags ) const
{
	STUB
	return false;
}

void ConCommandBase::AddFlags( int nFlags )
{
	STUB
}

void ConCommandBase::RemoveFlags( int nFlags )
{
	STUB
}

int ConCommandBase::GetFlags() const
{
	STUB
	return 0;
}

const char* ConCommandBase::GetName() const
{
	STUB
	return "";
}

const char* ConCommandBase::GetHelpText() const
{
	STUB
	return "";
}

bool ConCommandBase::IsRegistered() const
{
	STUB
	return false;
}

int ConCommandBase::GetDLLIdentifier() const
{
	STUB
	return 0;
}

void ConCommandBase::Create( const char *pName, const char *pDefaultValue, int flags )
{
	STUB
}

void ConCommandBase::Init()
{
	STUB
}

ConVar::ConVar( const char *pName, const char *pDefaultValue, int flags )
{
	Create( pName, pDefaultValue, flags );
}

ConVar::~ConVar()
{
	if ( m_Value.m_pszString )
	{
		delete[] m_Value.m_pszString;
		m_Value.m_pszString = NULL;
	}
}

void ConVar::Init()
{
	STUB
}

const char* ConVar::GetName() const
{
	STUB
	return "";
}

const char* ConVar::GetBaseName() const
{
	STUB
	return "";
}

const char* ConVar::GetHelpText() const
{
	STUB
	return "";
}

bool ConVar::IsFlagSet( int nFlags ) const
{
	STUB
	return false;
}

void ConVar::AddFlags( int nFlags )
{
	STUB
}

int ConVar::GetFlags() const
{
	STUB
	return 0;
}

bool ConVar::IsRegistered() const
{
	STUB
	return false;
}

int ConVar::GetSplitScreenPlayerSlot() const
{
	STUB
	return 0;
}

bool ConVar::IsCommand() const
{
	STUB
	return false;
}

void ConVar::SetValue( const char* value )
{
	STUB
}

void ConVar::SetValue( float value)
{
	STUB
}

void ConVar::SetValue( int value )
{
	STUB
}

void ConVar::SetValue( Color value )
{
	STUB
}


void ConVar::InternalSetValue(const char* value)
{
	STUB
}

void ConVar::InternalSetFloatValue( float value )
{
	STUB
}

void ConVar::InternalSetIntValue( int value )
{
	STUB
}

void ConVar::InternalSetColorValue( Color value )
{
	STUB
}

bool ConVar::ClampValue( float& value )
{
	STUB
	return false;
}

void ConVar::ChangeStringValue( const char *tempVal, float flOldValue )
{
	STUB
}

void ConVar::Create( const char *pName, const char *pDefaultValue, int flags,
				const char *pHelpString, bool bMin, float fMin,
				bool bMax, float fMax, FnChangeCallback_t callback )
{
	m_pszDefaultValue = pDefaultValue ? pDefaultValue : "";

	m_Value.m_StringLength = V_strlen( m_pszDefaultValue ) + 1;
	m_Value.m_pszString = new char[m_Value.m_StringLength];
	memcpy( m_Value.m_pszString, m_pszDefaultValue, m_Value.m_StringLength );

	m_Value.m_fValue = ( float )atof( m_Value.m_pszString );
	m_Value.m_nValue = atoi( m_Value.m_pszString ); // dont convert from float to int and lose bits

	m_pszName = pName;
	m_pszHelpString = pHelpString ? pHelpString : "";
	m_nFlags = flags;

	m_pParent = this;

	// TODO
}

class CEmptyConVar : public ConVar
{
public:
	CEmptyConVar() : ConVar( "", "0" ) {}
	// Used for optimal read access
	virtual void SetValue( const char *pValue ) {}
	virtual void SetValue( float flValue ) {}
	virtual void SetValue( int nValue ) {}
	virtual const char *GetName( void ) const { return ""; }
	virtual bool IsFlagSet( int nFlags ) const { return false; }
};

static CEmptyConVar s_EmptyConVar;

ConVarRef::ConVarRef( const char *pName, bool bIgnoreMissing )
{
	// TODO
	m_pConVar = &s_EmptyConVar;
	m_pConVarState = static_cast<ConVar*>(m_pConVar);
}
