#include "../hooks.hh"

namespace arcane::core::hooks {
	void __fastcall paint_traverse( REGISTERS, const std::int32_t panel_name, const bool paint, const bool force ) {
		GET_ORIG_FUNC( panel, 41, void( __thiscall* )( std::uintptr_t, std::int32_t, bool, bool ), ecx, panel_name, paint, force );

		static auto copy = 0;

		if ( !copy && !std::strcmp( ifaces::get_ifaces.panel->get_panel_name( panel_name ), "FocusOverlayPanel" ) )
			copy = panel_name;

		if ( panel_name != copy )
			return;

		features::watermark( );
		features::window( );

		if ( ifaces::get_ifaces.engine->is_connected( ) && ifaces::get_ifaces.engine->is_in_game( ) )
			features::player( );
	}
}
