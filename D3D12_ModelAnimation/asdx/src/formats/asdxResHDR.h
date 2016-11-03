﻿//-------------------------------------------------------------------------------------------------
// File : asdxResHDR.h
// Desc : Radiance HDR Format Loader.
// Copyright(c) Project Asura. All right reserved.
//-------------------------------------------------------------------------------------------------
#pragma once

//-------------------------------------------------------------------------------------------------
// Includes
//-------------------------------------------------------------------------------------------------
#include <asdxResTexture.h>


namespace asdx {

//--------------------------------------------------------------------------------------------------
//! @brief      HDRファイルからリソーステクスチャを読込します.
//!
//! @param[in]      filename        ファイル名です.
//! @param[out]     pResult         リソーステクスチャの格納先です.
//! @retval true    読込に成功.
//! @retval false   読込に失敗.
//--------------------------------------------------------------------------------------------------
bool LoadResTextureFromHDR( const char16* filename, ResTexture* pResult );

} // namespace asdx
