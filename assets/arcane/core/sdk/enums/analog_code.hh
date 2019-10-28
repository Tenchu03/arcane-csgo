#pragma once

namespace arcane::sdk::enums {
	// https://github.com/ValveSoftware/source-sdk-2013/blob/master/mp/src/public/inputsystem/AnalogCode.h
	
	enum class analog_code {
		analog_code_invalid = -1,
		analog_code_mouse_x = 0,
		analog_code_mouse_y,
		analog_code_mouse_x_y,
		analog_code_mouse_wheel,
		analog_code_last = 10
	};
}
