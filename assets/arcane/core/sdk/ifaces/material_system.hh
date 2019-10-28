#pragma once

#include "material.hh"

#include "../misc/macros.hh"

namespace arcane::sdk::ifaces {
	// https://github.com/ValveSoftware/source-sdk-2013/blob/master/sp/src/public/materialsystem/imaterialsystem.h
	
	struct material_system {
		VFUNC( find_material( const char* material_name ), 84, material* ( __thiscall* )( void*, const char* ), material_name );
	};
}
