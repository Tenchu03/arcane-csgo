#include "../hooks.hh"

namespace arcane::core::hooks {
	bool __fastcall create_move( REGISTERS, const float frame, sdk::ifaces::user_cmd* cmd ) {
		if ( !cmd || !cmd->command_number )
			GET_ORIG_FUNC( client_mode, 24, bool( __thiscall* )( std::uintptr_t, float, sdk::ifaces::user_cmd* ), ecx, frame, cmd );

		if ( ifaces::get_ifaces.engine->is_connected( ) && ifaces::get_ifaces.engine->is_in_game( ) ) {
			features::grenade_preview( );
			features::flash_alpha( );
			features::auto_bunny_hop( cmd );
			features::rank_revealer( );
			features::clamp_view_angles( cmd );
		}

		return false;
	}
}
