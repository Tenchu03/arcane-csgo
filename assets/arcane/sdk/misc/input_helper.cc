#include "input_helper.hh"

namespace arcane::sdk::misc {
	fgui::state get_key_state( const fgui::key& key ) {
		return core::ifaces::get_ifaces.input_system->is_button_down( key );
	}

	fgui::delta get_scroll_delta( ) {
		return core::ifaces::get_ifaces.input_system->get_analog_delta( enums::analog_code::analog_code_mouse_wheel );
	}

	fgui::point get_mouse_position( ) {
		static fgui::point point = { 0, 0 };

		core::ifaces::get_ifaces.surface->get_cursor_position( point.x, point.y );

		return point;
	}

	void setup_input_funcs( ) {
		fgui::input.get_key_state = get_key_state;
		fgui::input.get_scroll_delta = get_scroll_delta;
		fgui::input.get_mouse_position = get_mouse_position;
	}
}
