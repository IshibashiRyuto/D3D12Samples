﻿//-------------------------------------------------------------------------------------------------
// File : asdxResMotion.h
// Desc : Resource Motion Module.
// Copyright(c) Project Asura. All right reserved.
//-------------------------------------------------------------------------------------------------
#pragma once

//-------------------------------------------------------------------------------------------------
// Includes
//-------------------------------------------------------------------------------------------------
#include <asdxMath.h>
#include <vector>


namespace asdx {

///////////////////////////////////////////////////////////////////////////////////////////////////
// ResKeyFrame structure
///////////////////////////////////////////////////////////////////////////////////////////////////
struct ResKeyFrame
{
    u32     Time;           //!< キーフレーム番号です.
    Matrix  Transform;      //!< 変換行列です.
};

///////////////////////////////////////////////////////////////////////////////////////////////////
// ResKeyFrameSet structure
///////////////////////////////////////////////////////////////////////////////////////////////////
struct ResKeyFrameSet
{
    std::wstring                BoneName;   //!< ボーン名です.
    std::vector<ResKeyFrame>    KeyFrames;  //!< キーフレームデータです.
};

///////////////////////////////////////////////////////////////////////////////////////////////////
// ResMotion structure
///////////////////////////////////////////////////////////////////////////////////////////////////
struct ResMotion
{
    u32                          Duration;   //!< 最大キーフレーム番号です.
    std::vector<ResKeyFrameSet>  Bones;      //!< ボーンのモーションデータです.
};

///////////////////////////////////////////////////////////////////////////////////////////////////
// MotionFactory class
///////////////////////////////////////////////////////////////////////////////////////////////////
class MotionFactory
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
    //! @brief      モーションリソースを生成します.
    //!
    //! @param[in]      filename        モーションファイル名です.
    //! @param[out]     pResult         モーションリソースの格納先です.
    //---------------------------------------------------------------------------------------------
    static bool Create( const char16* filename, ResMotion* pResult );

    //---------------------------------------------------------------------------------------------
    //! @brief      モーションリソースを破棄します.
    //!
    //! @param[in]      ptr         破棄するモーションリソースへのポインタ.
    //---------------------------------------------------------------------------------------------
    static void Dispose( ResMotion*& ptr );
};

} // namespace asdx
