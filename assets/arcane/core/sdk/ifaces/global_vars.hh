#pragma once

namespace arcane::sdk::ifaces {
	// https://github.com/ValveSoftware/source-sdk-2013/blob/master/mp/src/public/globalvars_base.h
	
	struct global_vars {
		float real_time;
		
		std::int32_t frame_count;
		
		float absolute_frame_time;
		float absolute_frame_start_time;
		float cur_time;
		float frame_time;
		
		std::int32_t max_clients;
		std::int32_t tick_count;
		
		float interval_per_tick;
		float interpolation_amount;
		
		std::int32_t sim_ticks_this_frame;
		std::int32_t network_protocol;
		
		void* save_data;
		
		bool client;
		bool remove_client;
		
		std::int32_t time_stamp_networking_base;
		std::int32_t time_stamp_randomize_window;
	};
}
