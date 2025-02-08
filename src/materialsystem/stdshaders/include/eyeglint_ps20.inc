#pragma once
#include "shaderlib/cshader.h"
class eyeglint_ps20_Static_Index
{
public:
	eyeglint_ps20_Static_Index( IShaderShadow* pShaderShadow, IMaterialVar** params )
	{
	}

	int GetIndex() const
	{
		return 0;
	}
};

#define shaderStaticTest_eyeglint_ps20 1


class eyeglint_ps20_Dynamic_Index
{
public:
	eyeglint_ps20_Dynamic_Index( IShaderDynamicAPI* pShaderAPI )
	{
	}

	int GetIndex() const
	{
		return 0;
	}
};

#define shaderDynamicTest_eyeglint_ps20 1

