#include "std_include.hpp"

// fix wobble -> renderer.tweakNearPlane to 4 or something

namespace components
{
	void begin_scene()
	{
		const auto rr = game::get_renderer();
		if (rr->rendererInfo)
		{
			rr->Game_Device->SetTransform(D3DTS_VIEW, &rr->rendererInfo->matView);
			rr->Game_Device->SetTransform(D3DTS_PROJECTION, &rr->rendererInfo->matProjection);
		}
	}

	uint32_t begin_scene_stub_retn_addr = 0;
	void __declspec(naked) begin_scene_stub()
	{
		__asm
		{
			pushad
			call	begin_scene
			popad

			// og code
			mov     eax, [esi + 0xC];
			mov     ecx, [eax];
			jmp     begin_scene_stub_retn_addr;
		}
	}

	main_module::main_module()
	{
		// unlock console commands
		utils::hook::set<BYTE>(0x69FD00, 0xEB); // bf2_r 0x8CBF01, 0xEB
		utils::hook::set<BYTE>(0x69FD18, 0xEB); // bf2_r 0x8CBF65, 0xEB

		utils::hook(game::render_module + 0x5949, begin_scene_stub, HOOK_JUMP).install()->quick(); // bf2_r 0x22BBD
		begin_scene_stub_retn_addr = game::render_module + 0x594E; // bf2_r 0x22BC2
	}
}
