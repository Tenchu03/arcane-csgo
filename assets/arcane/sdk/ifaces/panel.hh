#pragma once

#include "../misc/macros.hh"

namespace arcane::sdk::ifaces {
	// https://github.com/ValveSoftware/source-sdk-2013/blob/master/mp/src/public/vgui/IPanel.h
	
	struct panel {
		VFUNC( get_panel_name( const std::uint32_t panel_name ), 36, const char* ( __thiscall* )( void*, std::uint32_t ), panel_name );
		VFUNC( get_class_name( const std::uint32_t class_name ), 37, const char* ( __thiscall* )( void*, std::uint32_t ), class_name );
	};
}
