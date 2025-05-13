#include"pch.h"
#include<Windows.h>
#include<d3d11.h>
#include<d3d11sdklayers.h>
#pragma comment(lib,"d3d11.lib")
#pragma comment(lib,"dxguid.lib")

#define HR(hr)																\
if (FAILED(hr))																\
{																						\
	MessageBox(0, #hr, 0, 0);											\
	return;																				\
}

TEST(D3DTest, D3DInitialization)
{
	UINT createDeviceFlag = 0;
#if defined(DEBUG) || defined(_DEBUG)
	createDeviceFlag |= D3D11_CREATE_DEVICE_DEBUG;
#endif
	D3D_FEATURE_LEVEL feateureLevel;
	ID3D11Device* md3dDevice;
	ID3D11DeviceContext* md3dImmediateContext;
	HRESULT hr = D3D11CreateDevice(
		0,
		D3D_DRIVER_TYPE_HARDWARE,
		0,
		createDeviceFlag,
		0, 0,
		D3D11_SDK_VERSION,
		&md3dDevice,
		&feateureLevel,
		&md3dImmediateContext);
	if (FAILED(hr))
	{
		MessageBox(0,L"D3D11CreateDevice failed!",0,0);
		return;
	}

	if (feateureLevel != D3D_FEATURE_LEVEL_11_0)
	{
		MessageBox(0, L"DX 11_0 not support!", 0, 0);
		return;
	}

	UINT m4xMsaaQuality;
	hr = md3dDevice->CheckMultisampleQualityLevels(
		DXGI_FORMAT_R8G8B8A8_UNORM, 4, &m4xMsaaQuality);

	assert(m4xMsaaQuality > 0);

	if (FAILED(hr))
	{
		MessageBox(0, L"Check MultisampleQualityLevels failed!", 0, 0);
		return;
	}




}