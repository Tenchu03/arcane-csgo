#include "../hooks.hh"

namespace arcane::core::hooks {
	void __fastcall override_view( REGISTERS, sdk::ifaces::view_setup* view_setup ) {
		if ( ifaces::get_ifaces.engine->is_connected( ) && ifaces::get_ifaces.engine->is_in_game( ) )
			features::view_model_fov( view_setup );

		GET_ORIG_FUNC( client_mode, 18, void( __thiscall* )( std::uintptr_t, sdk::ifaces::view_setup* ), ecx, view_setup );
	}
}
