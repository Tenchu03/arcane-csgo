#pragma once

#include "../sdk/sdk.hh"

namespace arcane::core::ifaces {
	inline struct ifaces {
		CAPTURE_IFACE( base_client, sdk::ifaces::base_client, "client_panorama.dll", "VClient018" );
		CAPTURE_IFACE( client_entity, sdk::ifaces::client_entity, "client_panorama.dll", "VClientEntityList003" );
		CAPTURE_IFACE( cvar, sdk::ifaces::cvar, "vstdlib.dll", "VEngineCvar007" );
		CAPTURE_IFACE( debug_overlay, sdk::ifaces::debug_overlay, "engine.dll", "VDebugOverlay004" );
		CAPTURE_IFACE( engine, sdk::ifaces::engine, "engine.dll", "VEngineClient014" );
		CAPTURE_IFACE( input_system, sdk::ifaces::input_system, "inputsystem.dll", "InputSystemVersion001" );
		CAPTURE_IFACE( material_system, sdk::ifaces::material_system, "materialsystem.dll", "VMaterialSystem080" );
		CAPTURE_IFACE( panel, sdk::ifaces::panel, "vgui2.dll", "VGUI_Panel009" );
		CAPTURE_IFACE( render_view, sdk::ifaces::render_view, "engine.dll", "VEngineRenderView014" );
		CAPTURE_IFACE( sound, sdk::ifaces::sound, "engine.dll", "IEngineSoundClient003" );
		CAPTURE_IFACE( surface, sdk::ifaces::surface, "vguimatsurface.dll", "VGUI_Surface031" );
	} get_ifaces;
}
