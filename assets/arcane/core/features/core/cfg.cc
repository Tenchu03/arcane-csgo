#include "cfg.hh"

namespace arcane::core::features {
	void save_cfg( ) {
		menu::container[ "#window" ]->save_config( "arcane_cfg.json" );

		fgui::handler::call_notification( "success, config has been saved", fgui::animation_type::LINEAR );
	}

	void load_cfg( ) {
		menu::container[ "#window" ]->load( "arcane_cfg.json" );

		fgui::handler::call_notification( "success, config has been loaded", fgui::animation_type::LINEAR );
	}
}
