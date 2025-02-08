#pragma once
#include "shaderlib/cshader.h"
class fade_blur_ps20_Static_Index
{
public:
	fade_blur_ps20_Static_Index( IShaderShadow* pShaderShadow, IMaterialVar** params )
	{
	}

	int GetIndex() const
	{
		return 0;
	}
};

#define shaderStaticTest_fade_blur_ps20 1


class fade_blur_ps20_Dynamic_Index
{
public:
	fade_blur_ps20_Dynamic_Index( IShaderDynamicAPI* pShaderAPI )
	{
	}

	int GetIndex() const
	{
		return 0;
	}
};

#define shaderDynamicTest_fade_blur_ps20 1

