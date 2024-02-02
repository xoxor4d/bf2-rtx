#pragma once
#include "utils/function.hpp"

namespace game
{
	extern std::vector<std::string> loaded_modules;

	extern HWND main_window;
	extern DWORD render_module;

	extern game::CRenderer* get_renderer();
	static DWORD* renderer_ptr = (DWORD*)(0x9A557C); // bf2_r 0xF2833C
}
