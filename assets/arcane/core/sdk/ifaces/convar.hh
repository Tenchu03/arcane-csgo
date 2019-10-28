#pragma once

#include "utl_vector.hh"

#include "../misc/macros.hh"

namespace arcane::sdk::ifaces {
	// https://github.com/ValveSoftware/source-sdk-2013/blob/master/mp/src/public/tier1/convar.h
	
	struct convar {
		VFUNC( get_float( ), 12, float( __thiscall* )( void* ) );
		VFUNC( get_int( ), 13, std::int32_t( __thiscall* )( void* ) );
		VFUNC( set_value( const char* value ), 14, void( __thiscall* )( void*, const char* ), value );
		VFUNC( set_value( const float value ), 15, void( __thiscall* )( void*, float ), value );
		VFUNC( set_value( const std::int32_t value ), 16, void( __thiscall* )( void*, std::int32_t ), value );

		PAD( pad_1, 24 );

		std::add_pointer_t< void( ) > change_callback;

		convar* parent;

		const char* default_value;

		char* string;

		PAD( pad_2, 28 );

		utl_vector< void( ) > on_change_callbacks;
	};
}
