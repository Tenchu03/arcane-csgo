#pragma once

#include "../ifaces/ifaces.hh"
#include "../sdk/sdk.hh"

namespace arcane::core::mem {
	inline struct mem {
		MEM_PTR( client_mode, sdk::ifaces::client_mode, ifaces::get_ifaces.base_client, 10, 5 );
		MEM_PTR( global_vars, sdk::ifaces::global_vars, ifaces::get_ifaces.base_client, 11, 10 );
		MEM_PTR( input, sdk::ifaces::input, ifaces::get_ifaces.base_client, 16, 1 );
	} get_mem;
}
