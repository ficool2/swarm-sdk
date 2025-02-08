#include "tier1/interface.h"

InterfaceReg *s_pInterfaceRegs = nullptr;

InterfaceReg::InterfaceReg( InstantiateInterfaceFn fn, const char *pName ) :
	m_pName(pName)
{
	m_CreateFn = fn;
	m_pNext = s_pInterfaceRegs;
	s_pInterfaceRegs = this;
}

void* CreateInterface( const char *pName, int *pReturnCode )
{
	for ( InterfaceReg* pCur = s_pInterfaceRegs; pCur; pCur = pCur->m_pNext )
	{
		if ( strcmp( pCur->m_pName, pName ) == 0 )
		{
			if ( pReturnCode )
				*pReturnCode = IFACE_OK;
			return pCur->m_CreateFn();
		}
	}

	if ( pReturnCode )
		*pReturnCode = IFACE_FAILED;
	return nullptr;
}
