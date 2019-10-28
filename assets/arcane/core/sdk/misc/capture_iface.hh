#pragma once

#include <Windows.h>
#include <cstdint>

namespace arcane::sdk::misc {
	// https://github.com/ValveSoftware/source-sdk-2013/blob/master/sp/src/tier1/interface.cpp

	template < typename T > static T capture_iface( const char* module_name, const char* interface_name ) {
		const auto module_handle = GetModuleHandleA( module_name );

		if ( !module_handle )
			return { };

		const auto proc_address = GetProcAddress( module_handle, "CreateInterface" );

		if ( !proc_address )
			return { };

		const auto create_interface = reinterpret_cast< T( __cdecl*)( const char*, std::int32_t* ) >( proc_address );

		return create_interface( interface_name, nullptr );
	}
}
