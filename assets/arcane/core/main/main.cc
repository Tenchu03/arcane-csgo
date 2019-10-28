#include "main.hh"

namespace arcane::core::main {
	BOOL WINAPI detach( ) {
		hooks::destroy_hooks( );

		return TRUE;
	}

	DWORD WINAPI attach( const LPVOID thread ) {
		try {
			ifaces::ifaces { };
			mem::mem { };

			sdk::misc::get_netvar_tree = std::make_unique< sdk::misc::netvar_tree >( );
			sdk::misc::setup_render_funcs( );
			sdk::misc::setup_input_funcs( );

			hooks::create_hooks( );

			menu::render( );

			fgui::handler::call_notification( "success, arcane has been loaded", fgui::animation_type::LINEAR );

			while ( !menu::checkbox[ "#unload_cheat_checkbox" ]->get_bool( ) )
				std::this_thread::sleep_for( std::chrono::milliseconds( 50 ) );
		} catch ( ... ) {
			std::throw_with_nested( std::runtime_error( "error, failed to initialize arcane" ) );
		}

		std::this_thread::sleep_for( std::chrono::milliseconds( 400 ) );
		detach( );
		FreeLibraryAndExitThread( static_cast< HMODULE >( thread ), EXIT_SUCCESS );
	}
}
