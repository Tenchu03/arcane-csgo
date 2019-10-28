#include "../hooks.hh"

namespace arcane::core::hooks {
	void __fastcall emit_sound( REGISTERS, const sdk::ifaces::sound_data sound_data ) {
		GET_ORIG_FUNC( sound, 5, void( __thiscall* )( std::uintptr_t, sdk::ifaces::sound_data ), ecx, sound_data );
	}
}
