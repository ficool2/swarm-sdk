#pragma once
#include "shaderlib/cshader.h"
class gamecontrols_ps20_Static_Index
{
public:
	gamecontrols_ps20_Static_Index( IShaderShadow* pShaderShadow, IMaterialVar** params )
	{
	}

	int GetIndex() const
	{
		return 0;
	}
};

#define shaderStaticTest_gamecontrols_ps20 1


class gamecontrols_ps20_Dynamic_Index
{
public:
	gamecontrols_ps20_Dynamic_Index( IShaderDynamicAPI* pShaderAPI )
	{
	}

	int GetIndex() const
	{
		return 0;
	}
};

#define shaderDynamicTest_gamecontrols_ps20 1

