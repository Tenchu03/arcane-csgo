#pragma once

#include "../misc/macros.hh"
#include "../misc/vector.hh"

namespace arcane::sdk::ifaces {
	// https://github.com/ValveSoftware/source-sdk-2013/blob/master/mp/src/public/engine/ivdebugoverlay.h
	
	struct debug_overlay {
		VFUNC( screen_position( const misc::vector& point, misc::vector& screen ), 13, std::int32_t( __thiscall* )( void*, const misc::vector&, misc::vector& ), point, screen );
	};
}
