#pragma once
#include "shaderlib/cshader.h"
class blurentity_ps20_Static_Index
{
public:
	blurentity_ps20_Static_Index( IShaderShadow* pShaderShadow, IMaterialVar** params )
	{
	}

	int GetIndex() const
	{
		return 0;
	}
};

#define shaderStaticTest_blurentity_ps20 1


class blurentity_ps20_Dynamic_Index
{
public:
	blurentity_ps20_Dynamic_Index( IShaderDynamicAPI* pShaderAPI )
	{
	}

	int GetIndex() const
	{
		return 0;
	}
};

#define shaderDynamicTest_blurentity_ps20 1

