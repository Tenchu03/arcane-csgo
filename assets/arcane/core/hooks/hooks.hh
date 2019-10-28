#pragma once

#include <memory>
#include <cstdint>

#include "../ifaces/ifaces.hh"
#include "../mem/mem.hh"
#include "../features/features.hh"
#include "../sdk/sdk.hh"

namespace arcane::core::hooks {
	extern std::unique_ptr< sdk::misc::vmt_hook > client;
	extern std::unique_ptr< sdk::misc::vmt_hook > client_mode;
	extern std::unique_ptr< sdk::misc::vmt_hook > render_view;
	extern std::unique_ptr< sdk::misc::vmt_hook > sound;
	extern std::unique_ptr< sdk::misc::vmt_hook > panel;

	extern void __fastcall frame_stage_notify( REGISTERS, sdk::enums::client_frame_stage );
	extern bool __fastcall create_move( REGISTERS, float, sdk::ifaces::user_cmd* );
	extern void __fastcall override_view( REGISTERS, sdk::ifaces::view_setup* );
	extern void __fastcall scene_end( REGISTERS );
	extern void __fastcall emit_sound( REGISTERS, sdk::ifaces::sound_data );
	extern void __fastcall paint_traverse( REGISTERS, std::int32_t, bool, bool );

	extern void create_hooks( );
	extern void destroy_hooks( );
}
