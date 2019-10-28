#include "hooks.hh"

namespace arcane::core::hooks {
	std::unique_ptr< sdk::misc::vmt_hook > client;
	std::unique_ptr< sdk::misc::vmt_hook > client_mode;
	std::unique_ptr< sdk::misc::vmt_hook > render_view;
	std::unique_ptr< sdk::misc::vmt_hook > sound;
	std::unique_ptr< sdk::misc::vmt_hook > panel;

	void create_hooks( ) {
		SETUP_HOOK( client, ifaces::get_ifaces.base_client );

		if ( client )
			HOOK_FUNC( client, 37, frame_stage_notify );

		SETUP_HOOK( client_mode, mem::get_mem.client_mode );

		if ( client_mode ) {
			HOOK_FUNC( client_mode, 24, create_move );
			HOOK_FUNC( client_mode, 18, override_view );
		}

		SETUP_HOOK( render_view, ifaces::get_ifaces.render_view );

		if ( render_view )
			HOOK_FUNC( render_view, 9, scene_end );

		SETUP_HOOK( sound, ifaces::get_ifaces.sound );

		if ( sound )
			HOOK_FUNC( sound, 5, emit_sound );

		SETUP_HOOK( panel, ifaces::get_ifaces.panel );

		if ( panel )
			HOOK_FUNC( panel, 41, paint_traverse );
	}

	void destroy_hooks( ) {
		UNHOOK_FUNC( client, 37 );
		UNHOOK_FUNC( client_mode, 24 );
		UNHOOK_FUNC( client_mode, 18 );
		UNHOOK_FUNC( render_view, 9 );
		UNHOOK_FUNC( sound, 5 );
		UNHOOK_FUNC( panel, 41 );
	}
}
