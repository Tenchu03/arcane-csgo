#pragma once

namespace arcane::sdk::enums {
	// https://github.com/ValveSoftware/source-sdk-2013/blob/master/sp/src/public/cdll_int.h
	
	enum client_frame_stage {
		client_frame_stage_undefined = -1,
		client_frame_stage_start,
		client_frame_stage_net_update_start,
		client_frame_stage_net_update_post_data_update_start,
		client_frame_stage_net_update_post_data_update_end,
		client_frame_stage_net_update_end,
		client_frame_stage_render_start,
		client_frame_stage_render_end
	};
}
