#pragma once

#include "../../ifaces/ifaces.hh"
#include "../../../dependencies/fgui/FGUI.hh"

namespace arcane::sdk::misc {
	extern fgui::state get_key_state( const fgui::key& );
	extern fgui::delta get_scroll_delta( );
	extern fgui::point get_mouse_position( );
	extern void setup_input_funcs( );
}
