﻿//-------------------------------------------------------------------------------------------------
// File : asdxShader.h
// Desc : Shader Module.
// Copyright(c) Project Asura. All right reserved.
//-------------------------------------------------------------------------------------------------
#pragma once

//-------------------------------------------------------------------------------------------------
// Includes
//-------------------------------------------------------------------------------------------------
#include <d3d12.h>
#include <vector>
#include <asdxRef.h>


#ifdef ASDX_AUTO_LINK
//-------------------------------------------------------------------------------------------------
// Linker
//-------------------------------------------------------------------------------------------------
#pragma comment( lib, "d3dcompiler.lib" )
#endif//ASDX_AUTO_LINK


namespace asdx {

///////////////////////////////////////////////////////////////////////////////////////////////////
// Shader class
///////////////////////////////////////////////////////////////////////////////////////////////////
class Shader final
{
    //=============================================================================================
    // list of friend classes and methods.
    //=============================================================================================
    /* NOTHING */

public:
    //=============================================================================================
    // public variables.
    //=============================================================================================
    /* NOTHING */

    //=============================================================================================
    // public methods.
    //=============================================================================================

    //---------------------------------------------------------------------------------------------
    //! @brief      コンストラクタです.
    //---------------------------------------------------------------------------------------------
    Shader();

    //---------------------------------------------------------------------------------------------
    //! @brief      デストラクタです.
    //---------------------------------------------------------------------------------------------
    virtual ~Shader();

    //---------------------------------------------------------------------------------------------
    //! @brief      ソースコードからコンパイルします.
    //!
    //! @param[in]      filename        ソースコードが記述されているファイル名.
    //! @param[in]      entryPoint      エントリーポイント名です.
    //! @param[in]      shaderModel     シェーダモデルです.
    //! @return     コンパイルに成功したら true を返却します.
    //---------------------------------------------------------------------------------------------
    bool Compile( const char16* filename, const char8* entryPoint, const char8* shaderModel );

    //---------------------------------------------------------------------------------------------
    //! @brief      コンパイル済みバイナリをロードします.
    //!
    //! @param[in]      filename        CSOファイル名.
    //! @return     ロードに成功したら true を返却します.
    //---------------------------------------------------------------------------------------------
    bool Load( const char16* filename );

    //---------------------------------------------------------------------------------------------
    //! @brief      入力要素を取得します.
    //!
    //! @param[out]     desc            入力要素の格納先.
    //! @retval true    生成に成功.
    //! @retval false   生成に失敗.
    //---------------------------------------------------------------------------------------------
    bool GetInputElements( std::vector<D3D12_INPUT_ELEMENT_DESC>& elementDesc );

    //---------------------------------------------------------------------------------------------
    //! @brief      バイトコードを取得します.
    //!
    //! @return     バイトコードを返却します.
    //---------------------------------------------------------------------------------------------
    D3D12_SHADER_BYTECODE GetByteCode();

private:
    //=============================================================================================
    // private variables.
    //=============================================================================================
    RefPtr<ID3DBlob>  m_Blob;       //!< シェーダコードです.

    //=============================================================================================
    // private methods.
    //=============================================================================================
    /* NOTHING */
};

} // namespace asdx
