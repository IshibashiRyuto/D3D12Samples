﻿//-------------------------------------------------------------------------------------------------
// File : asdxTexture.h
// Desc : Texture.
// Copyright(c) Project Asura. All right reserved.
//-------------------------------------------------------------------------------------------------
#pragma once

//-------------------------------------------------------------------------------------------------
// Includes
//-------------------------------------------------------------------------------------------------
#include <asdxDescriptorHeap.h>


namespace asdx{

///////////////////////////////////////////////////////////////////////////////////////////////////
// TextureDesc class
///////////////////////////////////////////////////////////////////////////////////////////////////
class TextureDesc : public D3D12_RESOURCE_DESC
{
public:
    DescriptorHeap*     pHeapResource;
    DescriptorHeap*     pHeapTarget;

    TextureDesc();
    ~TextureDesc();
    bool Init1D(uint32_t w, DXGI_FORMAT f);
    bool Init2D(uint32_t w, uint32_t h, DXGI_FORMAT f);
    bool Init3D(uint32_t w, uint32_t h, uint32_t d, DXGI_FORMAT f);
};

///////////////////////////////////////////////////////////////////////////////////////////////////
// Texture class
///////////////////////////////////////////////////////////////////////////////////////////////////
class Texture
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
    bool Init(ID3D12Device* pDevice, const TextureDesc* pDesc);
    void Term();

    ID3D12Resource* GetResource() const;
    D3D12_GPU_DESCRIPTOR_HANDLE GetHandleGPU() const;
    D3D12_CPU_DESCRIPTOR_HANDLE GetHandleCPU() const;

private:
    //=============================================================================================
    // private variables.
    //=============================================================================================
    RefPtr<ID3D12Resource>  m_pResource;
    RefPtr<Descriptor>      m_pDescriptorResource;
    RefPtr<Descriptor>      m_pDescriptorTarget;

    //=============================================================================================
    // private methods.
    //=============================================================================================
    /* NOTHING */
};

} // namespace