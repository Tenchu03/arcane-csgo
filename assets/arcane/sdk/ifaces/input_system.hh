#pragma once

#include "../misc/macros.hh"
#include "../enums/analog_code.hh"

namespace arcane::sdk::ifaces {
	// https://github.com/ValveSoftware/source-sdk-2013/blob/master/mp/src/public/inputsystem/iinputsystem.h
	
	struct input_system {
		VFUNC( is_button_down( const std::int32_t key_code ), 15, bool( __thiscall* )( void*, std::int32_t ), key_code );
		VFUNC( get_analog_value( const enums::analog_code analog_code ), 18, std::int32_t( __thiscall* )( void*, enums::analog_code ), analog_code );
		VFUNC( get_analog_delta( const enums::analog_code analog_code ), 19, std::int32_t( __thiscall* )( void*, enums::analog_code ), analog_code );
		VFUNC( button_code_to_string( const std::int32_t button_code ), 40, const char* ( __thiscall* )( void*, std::int32_t ), button_code );
	};
}
