#include "../hooks.hh"

namespace arcane::core::hooks {
	void __fastcall frame_stage_notify( REGISTERS, const sdk::enums::client_frame_stage client_frame_stage ) {
		GET_ORIG_FUNC( client, 37, void( __thiscall* )( std::uintptr_t, sdk::enums::client_frame_stage ), ecx, client_frame_stage );
	}
}
