#pragma once

namespace game
{
	class CRendererInfo
	{
	public:
		virtual void function0(); //
		virtual void function1(); //
		virtual void function2(); //
		virtual void function3(); //
		virtual void function4(); //
		virtual void function5(); //
		virtual void function6(); //
		virtual void function7(); //
		virtual float getFOV(); //
		virtual float getInsideFOV(); //
		virtual void function10(); //
		virtual void function11(); //
		virtual void function12(); //
		virtual void function13(); //
		virtual void function14(); //
		virtual void function15(); //
		virtual void function16(); //
		virtual void function17(); //
		virtual void function18(); //
		virtual void function19(); //
		virtual void function20(); //
		virtual void function21(); //
		virtual void function22(); //
		virtual void function23(); //
		virtual void setInverseView(D3DXMATRIX*); //

		virtual D3DXMATRIX* getInverseViewMatrix(); //
		virtual D3DXMATRIX* getViewMatrix(); //
		virtual D3DXMATRIX* getProjectionMatrix(); //
		char unknown4[12]; //0x0004
		float screenWidht; //0x0010  
		float screenHeight; //0x0014  
		char unknown24[12]; //0x0018
		float viewFOV; //0x0024  
		char unknown40[20]; //0x0028
		D3DXMATRIX matInverseView; //0x003C  
		D3DXMATRIX matView; //0x007C  
		char unknown188[64]; //0x00BC
		D3DXMATRIX matViewProjection; //0x00FC  
		D3DXMATRIX matProjection; //0x013C  

		D3DXVECTOR3* getViewRight()
		{
			return reinterpret_cast<D3DXVECTOR3*>(&matInverseView.m[0][0]);
		}

		D3DXVECTOR3* getViewUp()
		{
			return reinterpret_cast<D3DXVECTOR3*>(&matInverseView.m[1][0]);
		}

		D3DXVECTOR3* getViewDirection()
		{
			return reinterpret_cast<D3DXVECTOR3*>(&matInverseView.m[2][0]);
		}

		D3DXVECTOR3* getViewPosition()
		{
			return reinterpret_cast<D3DXVECTOR3*>(&matInverseView.m[3][0]);
		}
	};

	struct CRenderer
	{
		char _0x0000[8];
		IDirect3D9* Direct3D_Device; //0x0008 
		IDirect3DDevice9* Game_Device; //0x000C
		char _0x0010[20];
		int screenWidth; //0x0024
		int screenHeight; //0x0028
		char unknown44[24]; //0x002C
		int isWindowed; //0x0044  
		char unknown72[4]; //0x0048
		int refreshRate; //0x004C  
		char unknown80[168]; //0x0050
		CRendererInfo* rendererInfo; //0x00F8
		char _0x002C[1440]; // 1648
		BYTE N00FA8F34; //0x069C 
		BYTE N01061B57; //0x069D 
		BYTE N01053840; //0x069E 
		BYTE bDrawWater; //0x069F 
		BYTE N00FA8F33; //0x06A0 
		BYTE N01048FDA; //0x06A1 
		BYTE N0104978B; //0x06A2 
		BYTE bShowBodies; //0x06A3 
		BYTE N00FA8F32; //0x06A4 
		BYTE bShowGround; //0x06A5 
		BYTE bShowGrass; //0x06A6 
		BYTE bShowTrees; //0x06A7 
		BYTE bShowNameTags; //0x06A8 Nametags
		BYTE N00FBAEB4; //0x06A9 
		BYTE N00FC0334; //0x06AA 
		BYTE N00FBAEB5; //0x06AB 
		int DrawFps; //0x06AC 
		BYTE N00DCC523; //0x06B0 
		BYTE bShowHud; //0x06B1 
		BYTE bDrawSky; //0x06B2 
		BYTE bDrawSunFlare; //0x06B3 
		BYTE bDrawConsole; //0x06B4 
	};
	STATIC_ASSERT_OFFSET(CRenderer, rendererInfo, 0x00F8);
	STATIC_ASSERT_OFFSET(CRenderer, N00FA8F34, 0x069C);
	STATIC_ASSERT_OFFSET(CRenderer, DrawFps, 0x06AC);
}

