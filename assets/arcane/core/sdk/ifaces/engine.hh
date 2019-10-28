#pragma once

#include "player_info.hh"

#include "../misc/vector.hh"
#include "../misc/macros.hh"

namespace arcane::sdk::ifaces {
	// https://github.com/ValveSoftware/source-sdk-2013/blob/master/sp/src/public/cdll_int.h
	
	struct engine {
		VFUNC( get_player_info( const std::int32_t entity, player_info& info ), 8, bool( __thiscall* )( void*, std::int32_t, player_info& ), entity, info );
		VFUNC( get_player_for_user_id( const std::int32_t entity), 9, std::int32_t( __thiscall* )( void*, std::int32_t ), entity );
		VFUNC( get_local_player( ), 12, std::int32_t( __thiscall* )( void* ) );
		VFUNC( get_view_angles( misc::vector& angle ), 18, void( __thiscall* )( void*, misc::vector& ), angle );
		VFUNC( set_view_angles( misc::vector& angle ), 19, void( __thiscall* )( void*, misc::vector& ), angle );
		VFUNC( get_max_clients( ), 20, std::int32_t( __thiscall* )( void* ) );
		VFUNC( is_in_game( ), 26, bool( __thiscall* )( void* ) );
		VFUNC( is_connected( ), 27, bool( __thiscall* )( void* ) );
		VFUNC( is_taking_screenshot( ), 92, bool( __thiscall* )( void* ) );
		VFUNC( is_hltv( ), 93, bool( __thiscall* )( void* ) );
		VFUNC( execute_client_cmd( const char* cmd ), 108, void( __thiscall* )( void*, const char* ), cmd );
	};
}
