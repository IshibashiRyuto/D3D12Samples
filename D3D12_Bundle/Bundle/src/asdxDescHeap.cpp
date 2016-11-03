﻿//-------------------------------------------------------------------------------------------------
// File : asdxDescHeap.cpp
// Desc : Descriptor Heap Moudle.
// Copyright(c) Project Asura. All right reserved.
//-------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------
// Includes
//-------------------------------------------------------------------------------------------------
#include <asdxDescHeap.h>
#include <asdxLogger.h>
#include <cassert>


namespace asdx {

//-------------------------------------------------------------------------------------------------
// Constant Values
//-------------------------------------------------------------------------------------------------
const D3D12_CPU_DESCRIPTOR_HANDLE DescHeap::InvalidHandleCPU = { 0 };
const D3D12_GPU_DESCRIPTOR_HANDLE DescHeap::InvalidHandleGPU = { 0 };


///////////////////////////////////////////////////////////////////////////////////////////////////
// DescHeap class
///////////////////////////////////////////////////////////////////////////////////////////////////

//-------------------------------------------------------------------------------------------------
//      コンストラクタです.
//-------------------------------------------------------------------------------------------------
DescHeap::DescHeap()
: m_Heap()
, m_Size( 0 )
{ /* DO_NOTHING */ }

//-------------------------------------------------------------------------------------------------
//      デストラクタです.
//-------------------------------------------------------------------------------------------------
DescHeap::~DescHeap()
{ /* DO_NOTHING */ }

//-------------------------------------------------------------------------------------------------
//      初期化処理を行います.
//-------------------------------------------------------------------------------------------------
bool DescHeap::Init
(
    ID3D12Device*               pDevice,
    D3D12_DESCRIPTOR_HEAP_DESC* pDesc
)
{
    assert( pDevice != nullptr );
    assert( pDesc   != nullptr );

    auto hr = pDevice->CreateDescriptorHeap( pDesc, IID_PPV_ARGS(m_Heap.GetAddress()));
    if ( FAILED( hr ) )
    {
        ELOG( "Error : ID3D12Device::CreateDescriptorHeap() Failed." );
        return false;
    }

    m_Size = pDevice->GetDescriptorHandleIncrementSize(pDesc->Type);

    return true;
}

//-------------------------------------------------------------------------------------------------
//      終了処理を行います.
//-------------------------------------------------------------------------------------------------
void DescHeap::Term()
{
    m_Heap.Reset();
    m_Size = 0;
}

//-------------------------------------------------------------------------------------------------
//      ディスクリプタヒープを取得します.
//-------------------------------------------------------------------------------------------------
ID3D12DescriptorHeap* DescHeap::GetPtr() const
{ return m_Heap.GetPtr(); }

//-------------------------------------------------------------------------------------------------
//      アロー演算子です.
//-------------------------------------------------------------------------------------------------
ID3D12DescriptorHeap* DescHeap::operator -> () const
{ return m_Heap.GetPtr(); }

//-------------------------------------------------------------------------------------------------
//      CPUハンドルを取得します.
//-------------------------------------------------------------------------------------------------
D3D12_CPU_DESCRIPTOR_HANDLE DescHeap::GetHandleCPU( const u32 index ) const
{
    D3D12_CPU_DESCRIPTOR_HANDLE handle = m_Heap->GetCPUDescriptorHandleForHeapStart();
    handle.ptr += ( m_Size ) * index;
    return handle;
}

//-------------------------------------------------------------------------------------------------
//      GPUハンドルを取得します.
//-------------------------------------------------------------------------------------------------
D3D12_GPU_DESCRIPTOR_HANDLE DescHeap::GetHandleGPU( const u32 index ) const
{
    D3D12_GPU_DESCRIPTOR_HANDLE handle = m_Heap->GetGPUDescriptorHandleForHeapStart();
    handle.ptr += ( m_Size ) * index;
    return handle;
}

} // namespace asdx
