#pragma once

#include <unordered_map>
#include <string>
#include <memory>
#include <cstdint>

#include "../features/features.hh"
#include "../../fgui/FGUI.hh"

namespace arcane::core::menu {
	inline std::unordered_map< std::string, std::shared_ptr< fgui::button > > button;
	inline std::unordered_map< std::string, std::shared_ptr< fgui::checkbox > > checkbox;
	inline std::unordered_map< std::string, std::shared_ptr< fgui::colorlist > > color_list;
	inline std::unordered_map< std::string, std::shared_ptr< fgui::colorpicker > > color_picker;
	inline std::unordered_map< std::string, std::shared_ptr< fgui::combobox > > combobox;
	inline std::unordered_map< std::string, std::shared_ptr< fgui::container > > container;
	inline std::unordered_map< std::string, std::shared_ptr< fgui::keybinder > > key_binder;
	inline std::unordered_map< std::string, std::shared_ptr< fgui::label > > label;
	inline std::unordered_map< std::string, std::shared_ptr< fgui::listbox > > listbox;
	inline std::unordered_map< std::string, std::shared_ptr< fgui::multibox > > multi_box;
	inline std::unordered_map< std::string, std::shared_ptr< fgui::slider > > slider;
	inline std::unordered_map< std::string, std::shared_ptr< fgui::spinner > > spinner;
	inline std::unordered_map< std::string, std::shared_ptr< fgui::tabs > > tabs;
	inline std::unordered_map< std::string, std::shared_ptr< fgui::textbox > > text_box;

	extern void render( );
}
