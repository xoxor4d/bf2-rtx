<h1 align="center">Battlefield 2 rtx-remix compatibility mod</h1>

<div align="center" markdown="1"> 

This client modification is made to make the game compatible with nvidia's [rtx-remix](https://github.com/NVIDIAGameWorks/rtx-remix).  
It does __not__ come with a 'rtx mod' -> meaning no custom models nor materials.  

<br>
</div>

#### Usage:

1) Install the latest full rtx-remix release (0.4.0 at this time)   
https://github.com/NVIDIAGameWorks/rtx-remix/tags

<br>

2) _(Optional)_ Install the latest `github action` builds of:  
remix bridge - https://github.com/NVIDIAGameWorks/bridge-remix/actions  
remix runtime - https://github.com/NVIDIAGameWorks/dxvk-remix/actions  

<br>

3) Download Ultimate-ASI-Loader (x86)  
  https://github.com/ThirteenAG/Ultimate-ASI-Loader/releases and extract `dinput8.dll` into your bf2 root directory.

<br>

4) Download the latest bf2-rtx `github actions` build:  
  Release-binaries-bf2-rtx - https://github.com/xoxor4d/bf2-rtx/actions 
  - Drop `bf2rtx.asi` into your bf2 root directory  
  - Drop the contents of the `assets` folder into your bf2 root directory  
  > You should hear a single short beep if it was loaded correctly. The window title should display `BF2-RTX-[commit] ...`

<br>

5) Graphic Settings:

- set everything to `low`
- set Geometry to `high`
- set Textures to `high`

<br>

6) Console commands that can be used to tweak stuff further:

- `renderer.forceStaticMeshSkipLod -1`
- `renderer.qualityLodEnabled 1`
- `renderer.tweakNearPlane 1`
- `renderer.tweakNearPlane1p 1`
- `renderer.tweakFarPlane1p 600`
- `renderer.drawPostProduction 0`

<br>
<br>

## ⚠️ Current issues:
- no text in menus
- everything else

<br>

## Questions? 
- join the [rtx-remix showcase](https://discord.gg/j6sh7JD3v9) discord and check out the bf2 thread within the `remix-projects` channel.
- rtx-remix: https://github.com/NVIDIAGameWorks/rtx-remix  

<br>

## Credits
- [people of the showcase discord](https://discord.gg/j6sh7JD3v9) (especially Kamilkampfwagen)
- [nvidia - rtx-remix](https://github.com/NVIDIAGameWorks/rtx-remix)