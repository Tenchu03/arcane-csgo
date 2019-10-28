#pragma once

#include "client_class.hh"

#include "../misc/macros.hh"

namespace arcane::sdk::ifaces {
	// https://github.com/ValveSoftware/source-sdk-2013/blob/master/sp/src/public/cdll_int.h
	
	struct base_client {
		VFUNC( get_all_classes( ), 8, client_class* ( __thiscall* )( void* ) );
		VFUNC( dispatch_user_message( const std::int32_t message, const std::int32_t first_arg, const std::int32_t second_arg, void* data ), 38, bool( __thiscall* )( void*, std::int32_t, std::uint32_t, std::uint32_t, void* ), message, first_arg, second_arg, data );
	};
}
