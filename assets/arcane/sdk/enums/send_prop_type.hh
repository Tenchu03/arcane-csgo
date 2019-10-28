#pragma once

namespace arcane::sdk::enums {
	// https://github.com/ValveSoftware/source-sdk-2013/blob/master/sp/src/public/dt_common.h
	
	enum send_prop_type {
		send_prop_type_int = 0,
		send_prop_type_float,
		send_prop_type_vector,
		send_prop_type_vector_x_y,
		send_prop_type_string,
		send_prop_type_array,
		send_prop_type_data_table,
		send_prop_type_int_64,
		send_prop_type_num
	};
}