#pragma once

#include <thread>

#include "../ifaces/ifaces.hh"
#include "../mem/mem.hh"
#include "../hooks/hooks.hh"
#include "../menu/menu.hh"
#include "../sdk/sdk.hh"

namespace arcane::core::main {
	extern BOOL WINAPI detach( );
	extern DWORD WINAPI attach( LPVOID );
}
