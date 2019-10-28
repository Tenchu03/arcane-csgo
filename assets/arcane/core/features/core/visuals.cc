#include "misc.hh"

namespace arcane::core::features {
	void watermark( ) {
		if ( !menu::checkbox[ "#watermark_checkbox" ]->get_bool( ) )
			return;

		sdk::misc::text( 5, 5, fgui::color( 255, 255, 255 ), sdk::misc::fonts[ sdk::enums::font_watermark ], "arcane - internal csgo cheat base" );
	}

	void window( ) {
		ifaces::get_ifaces.surface->clipping_enabled( ) = true;

		fgui::handler::render_window( );

		ifaces::get_ifaces.surface->clipping_enabled( ) = false;
	}

	void player( ) {
		if ( !menu::checkbox[ "#player_visuals_enabled_checkbox" ]->get_bool( ) )
			return;

		static auto local_player = ifaces::get_ifaces.client_entity->get_client_entity( ifaces::get_ifaces.engine->get_local_player( ) );

		if ( !local_player )
			return;

		for ( auto index = 1; index <= ifaces::get_ifaces.engine->get_max_clients( ); index++ ) {
			const auto entity = ifaces::get_ifaces.client_entity->get_client_entity( index );

			if ( !entity )
				continue;

			if ( entity == local_player )
				continue;

			if ( !( entity->get_health( ) > 0 ) )
				continue;

			if ( entity->is_dormant( ) )
				continue;

			static sdk::ifaces::player_info player_info;

			if ( !ifaces::get_ifaces.engine->get_player_info( index, player_info ) )
				continue;

			static sdk::misc::vector screen;

			if ( !( ifaces::get_ifaces.debug_overlay->screen_position( entity->get_vec_origin( ), screen ) != 1 ) )
				continue;

			if ( !( local_player->get_team( ) != entity->get_team( ) ) )
				return;

			if ( menu::checkbox[ "#player_name_checkbox" ]->get_bool( ) )
				sdk::misc::text( screen.x, screen.y, fgui::color( 255, 150, 0 ), sdk::misc::fonts[ sdk::enums::font_visuals ], player_info.name );

			if ( menu::checkbox[ "#player_health_checkbox" ]->get_bool( ) )
				sdk::misc::text( screen.x, screen.y + 15, fgui::color( 255, 255, 255 ), sdk::misc::fonts[ sdk::enums::font_visuals ], fmt::format( "H: {:d}", entity->get_health( ) ) );

			if ( menu::checkbox[ "#player_armor_checkbox" ]->get_bool( ) )
				sdk::misc::text( screen.x, screen.y + 30, fgui::color( 255, 255, 255 ), sdk::misc::fonts[ sdk::enums::font_visuals ], fmt::format( "A: {:d}", entity->get_armor_value( ) ) );
		}
	}

	void grenade_preview( ) {
		static auto cvar = ifaces::get_ifaces.cvar->find_cvar( "cl_grenadepreview" );
		static auto local_player = ifaces::get_ifaces.client_entity->get_client_entity( ifaces::get_ifaces.engine->get_local_player( ) );

		if ( !cvar || !local_player )
			return;

		if ( !( local_player->get_health( ) > 0 ) )
			return;

		cvar->set_value( menu::checkbox[ "#grenade_preview_checkbox" ]->get_bool( ) ? 1 : 0 );
	}

	void flash_alpha( ) {
		static auto local_player = ifaces::get_ifaces.client_entity->get_client_entity( ifaces::get_ifaces.engine->get_local_player( ) );

		if ( !local_player )
			return;

		local_player->get_flash_alpha( ) = menu::checkbox[ "#flash_alpha_checkbox" ]->get_bool( ) ? menu::slider[ "#flash_alpha_slider" ]->get_value( ) : 255.0f;
	}

	void view_model_fov( sdk::ifaces::view_setup* view_setup ) {
		static auto local_player = ifaces::get_ifaces.client_entity->get_client_entity( ifaces::get_ifaces.engine->get_local_player( ) );

		if ( !local_player )
			return;

		view_setup->view_model_fov += menu::checkbox[ "#viewmodel_fov_checkbox" ]->get_bool( ) && !local_player->is_scoped( ) ? menu::slider[ "#viewmodel_fov_slider" ]->get_value( ) : 0.0f;
	}
}
