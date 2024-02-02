#include "std_include.hpp"

namespace game
{
	std::vector<std::string> loaded_modules;

	HWND  main_window;
	DWORD render_module;

	game::CRenderer* get_renderer()
	{
		const auto out = reinterpret_cast<game::CRenderer*>(*game::renderer_ptr);
		return out;
	}
}
