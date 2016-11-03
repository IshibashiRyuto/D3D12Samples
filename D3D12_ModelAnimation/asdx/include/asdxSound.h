﻿//-------------------------------------------------------------------------------------------------
// File : asdxSound.h
// Desc : Sound Module.
// Copyright(c) Project Asura. All right reserved.
//-------------------------------------------------------------------------------------------------
#pragma once

//-------------------------------------------------------------------------------------------------
// Includes
//-------------------------------------------------------------------------------------------------
#include <Windows.h>
#include <asdxTypedef.h>
#include <map>


namespace asdx {

///////////////////////////////////////////////////////////////////////////////////////////////////
// SndState
///////////////////////////////////////////////////////////////////////////////////////////////////
enum SndState
{
    Play,       //!< 再生状態.
    Stop,       //!< 停止状態.
    Pause,      //!< 一時停止状態.
    Done,       //!< 再生完了.
    Error,      //!< エラー状態.
};


///////////////////////////////////////////////////////////////////////////////////////////////////
// SndMgr class
///////////////////////////////////////////////////////////////////////////////////////////////////
class SndMgr
{
    //=============================================================================================
    // list of friend classes and methods.
    //=============================================================================================
    friend class DesktopApp;

public:
    //=============================================================================================
    // public variables.
    //=============================================================================================
    /* NOTHING */

    //=============================================================================================
    // public methods.
    //=============================================================================================

    //---------------------------------------------------------------------------------------------
    //! @brief      シングルトンインスタンスを取得します.
    //---------------------------------------------------------------------------------------------
    static SndMgr& GetInstance();

    //---------------------------------------------------------------------------------------------
    //! @brief      サウンドデータを登録します.
    //---------------------------------------------------------------------------------------------
    bool Open( u32 id, const char16* filename );

    //---------------------------------------------------------------------------------------------
    //! @brief      サウンドデータの登録を解除します.
    //---------------------------------------------------------------------------------------------
    void Close( u32 id );

    //---------------------------------------------------------------------------------------------
    //! @brief      サウンドデータを再生します.
    //---------------------------------------------------------------------------------------------
    void Play( u32 id, s32 loopCount = 0 );

    //---------------------------------------------------------------------------------------------
    //! @brief      サウンドデータを停止します.
    //---------------------------------------------------------------------------------------------
    void Stop( u32 id );

    //---------------------------------------------------------------------------------------------
    //! @brief      サウンドデータを一時停止します.
    //---------------------------------------------------------------------------------------------
    void Pause( u32 id );

    //---------------------------------------------------------------------------------------------
    //! @brief      一時停止したサウンドデータを再生します.
    //---------------------------------------------------------------------------------------------
    void Resume( u32 id );

    //---------------------------------------------------------------------------------------------
    //! @brief      状態を取得します.
    //---------------------------------------------------------------------------------------------
    SndState GetState( u32 id );

protected:
    //=============================================================================================
    // protected variables.
    //=============================================================================================
    /* NOTHING */

    //=============================================================================================
    // protected methods.
    //=============================================================================================

    //---------------------------------------------------------------------------------------------
    //! @brief      コールバック用のウィンドウハンドルを設定します.
    //! @note       Applicationから呼び出します.
    //---------------------------------------------------------------------------------------------
    void SetHandle( HWND handle );

    //---------------------------------------------------------------------------------------------
    //! @brief      コールバック処理です.
    //! @note       Applicationから呼び出します.
    //---------------------------------------------------------------------------------------------
    void OnNofity( u32 id, u32 param );

private:
    ///////////////////////////////////////////////////////////////////////////////////////////////
    // Status structure
    ///////////////////////////////////////////////////////////////////////////////////////////////
    struct Status
    {
        s32     MaxLoopCount;   //!< 最大ループ数.
        s32     CurLoopCount;   //!< 現在のループ数.
        s32     State;          //!< 再生状態.
        u32     DeviceId;       //!< デバイスID.
    };

    //=============================================================================================
    // private variables.
    //=============================================================================================
    static SndMgr           s_Instance;     //!< 唯一のインスタンスです.
    std::map<u32, Status>   m_Status;       //!< 状態管理用.
    std::map<u32, u32>      m_UserIds;      //!< デバイスID -> ユーザーID参照用.
    HWND                    m_Handle;       //!< ウィンドウハンドル.

    //=============================================================================================
    // private methods.
    //=============================================================================================

    //---------------------------------------------------------------------------------------------
    //! @brief      コンストラクタです.
    //---------------------------------------------------------------------------------------------
    SndMgr();

    //---------------------------------------------------------------------------------------------
    //! @brief      デストラクタです.
    //---------------------------------------------------------------------------------------------
    ~SndMgr();
};

} // namespace asdx