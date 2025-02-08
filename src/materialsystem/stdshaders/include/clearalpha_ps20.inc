#pragma once
#include "shaderlib/cshader.h"
class clearalpha_ps20_Static_Index
{
public:
	clearalpha_ps20_Static_Index( IShaderShadow* pShaderShadow, IMaterialVar** params )
	{
	}

	int GetIndex() const
	{
		return 0;
	}
};

#define shaderStaticTest_clearalpha_ps20 1


class clearalpha_ps20_Dynamic_Index
{
public:
	clearalpha_ps20_Dynamic_Index( IShaderDynamicAPI* pShaderAPI )
	{
	}

	int GetIndex() const
	{
		return 0;
	}
};

#define shaderDynamicTest_clearalpha_ps20 1

