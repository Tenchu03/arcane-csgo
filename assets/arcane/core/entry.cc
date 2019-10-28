#include <Windows.h>

#include "main/main.hh"

BOOL WINAPI DllMain( const HINSTANCE instance, const DWORD reason, const LPVOID reserved ) {
	switch ( reason ) {
		case DLL_PROCESS_ATTACH: {
			const auto thread = CreateThread( nullptr, 0, arcane::core::main::attach, instance, 0, nullptr );

			if ( thread != nullptr )
				CloseHandle( thread );
		} break;

		case DLL_PROCESS_DETACH: {
			if ( !reserved )
				arcane::core::main::detach( );
		} break;

		default: break;
	}

	return TRUE;
}
