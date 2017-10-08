//-------------------------------------------------------------------------------------------------
// File : SimplePS.hlsl
// Desc : Simple Pixel Shader
// Copyright(c) Project Asura. All right reserved.
//-------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------
// Includes
//-------------------------------------------------------------------------------------------------
#include "SimpleDef.hlsli"


//-------------------------------------------------------------------------------------------------
//      �s�N�Z���V�F�[�_�̃��C���G���g���[�|�C���g�ł�.
//-------------------------------------------------------------------------------------------------
PSOutput PSFunc(const VSOutput input)
{
    PSOutput output = (PSOutput)0;

    float4 diffuseMap = ColorTexture.Sample( ColorSmp, input.TexCoord );

    output.Color.rgb = diffuseMap.rgb * Diffuse;
    output.Color.a = Alpha * diffuseMap.a;

    return output;
}

