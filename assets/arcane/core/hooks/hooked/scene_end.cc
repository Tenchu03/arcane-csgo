#include "../hooks.hh"

namespace arcane::core::hooks {
	void __fastcall scene_end( REGISTERS ) {
		GET_ORIG_FUNC( render_view, 9, void( __thiscall* )( std::uintptr_t ), ecx );
	}
}
