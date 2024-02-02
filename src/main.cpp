#include "std_include.hpp"
#define GAME_150_TITLE "BF2 (v1.5.3153-802.0, pid: %d)"

DWORD WINAPI find_window_loop(LPVOID)
{
	char hwnd_title[255] = {};
	sprintf_s(hwnd_title, GAME_150_TITLE, GetCurrentProcessId());

	std::uint32_t _time = 0;

	// wait for window creation
	while (!game::main_window && !game::render_module)
	{
		// get main window hwnd
		game::main_window = FindWindowA(nullptr, hwnd_title);

		// get render module (base address)
		if (!game::render_module)
		{
			game::render_module = (DWORD)GetModuleHandleA("RendDX9.dll"); // RendDX9_r
		}
		
		Sleep(500); _time += 500;

		if (_time >= 10000)
		{
			Beep(300, 100); Sleep(100); Beep(200, 100); Sleep(100); Beep(100, 100);
			return TRUE;
		}
	}

	Beep(523, 100);
	Sleep(1000);

#ifdef GIT_DESCRIBE
	SetWindowTextA(game::main_window, utils::va("BF2-RTX: %s - %s", GIT_DESCRIBE, hwnd_title));
#else
	SetWindowTextA(game::main_window, utils::va("BF2-RTX - %s", hwnd_title));
#endif

	components::loader::initialize();
	return TRUE;
}

BOOL APIENTRY DllMain(HMODULE /*hModule*/, DWORD  ul_reason_for_call, LPVOID /*lpReserved*/)
{
	if (ul_reason_for_call == DLL_PROCESS_ATTACH)
	{
		CreateThread(nullptr, 0, find_window_loop, nullptr, 0, nullptr);
	}
	else if (ul_reason_for_call == DLL_PROCESS_DETACH)
	{
		components::loader::uninitialize();
	}

	return TRUE;
}
