#pragma once

#include "../misc/macros.hh"

namespace arcane::sdk::ifaces {
	// https://github.com/ValveSoftware/source-sdk-2013/blob/master/mp/src/public/materialsystem/imaterial.h
	
	struct material {
		VFUNC( set_alpha( const float alpha ), 27, void( __thiscall* )( void*, float ), alpha );
		VFUNC( set_color( const float r, const float g, const float b ), 28, void( __thiscall* )( void*, float, float, float ), r, g, b );
		VFUNC( set_flag( const std::int32_t flag, const bool on ), 29, void( __thiscall* )( void*, std::int32_t, bool ), flag, on );
	};
}
