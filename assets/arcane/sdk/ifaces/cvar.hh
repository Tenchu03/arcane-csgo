#pragma once

#include "convar.hh"

#include "../misc/macros.hh"

namespace arcane::sdk::ifaces {
	// https://github.com/ValveSoftware/source-sdk-2013/blob/master/mp/src/public/icvar.h
	
	struct cvar {
		VFUNC( find_cvar( const char* cvar ), 15, convar* ( __thiscall* )( void*, const char* ), cvar );
	};
}
