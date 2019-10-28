#pragma once

#include "entity.hh"

#include "../misc/macros.hh"

namespace arcane::sdk::ifaces {
	// https://github.com/ValveSoftware/source-sdk-2013/blob/master/sp/src/game/client/cliententitylist.h
	
	struct client_entity {
		VFUNC( get_client_entity( const std::int32_t index ), 3, entity* ( __thiscall* )( void*, std::int32_t ), index );
		VFUNC( get_client_entity_from_handle( void* handle ), 7, entity* ( __thiscall* )( void*, void* ), handle );
		VFUNC( get_highest_entity_index( ), 8, std::int32_t( __thiscall* )( void* ) );
		VFUNC( set_max_entities( const std::int32_t entity ), 9, void( __thiscall* )( void*, std::int32_t ), entity );
		VFUNC( get_max_entities( ), 10, std::int32_t( __thiscall* )( void* ) );
	};
}
