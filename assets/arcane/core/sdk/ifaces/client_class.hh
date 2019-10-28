#pragma once

#include <cstdint>

namespace arcane::sdk::ifaces {
	// https://github.com/ValveSoftware/source-sdk-2013/blob/master/mp/src/public/dt_recv.h

	struct recv_proxy_data;
	struct recv_table;
	struct recv_prop;

	using recv_var_proxy = void( __cdecl* )( const recv_proxy_data*, void*, void* );
	using create_client_class = void* ( * )( std::int32_t, std::int32_t );
	using create_event = void* ( * )( );

	struct d_variant {
		union {
			float float_type;

			long int_type;

			char* string_type;

			void* data_type;

			float vector_type[ 3 ];

			__int64 int_64_type;
		};

		std::int32_t type;
	};

	struct recv_proxy_data {
		const recv_prop* prop;

		d_variant value;

		std::int32_t element;
		std::int32_t object_id;
	};

	struct recv_table {
		recv_prop* prop;

		std::int32_t props;

		void* decoder;

		char* net_table_name;

		bool is_initialized;
		bool is_in_main_list;
	};

	struct recv_prop {
		char* var_name;

		std::int32_t recv_type;
		std::int32_t flags;
		std::int32_t string_buffer_size;

		bool is_inside_array;

		const void* extra_data;

		recv_prop* array_prop;

		void* array_length_proxy;

		recv_var_proxy var_proxy;

		void* data_table_proxy;

		recv_table* data_table;

		std::int32_t offset;
		std::int32_t element_stride;
		std::int32_t elements;

		const char* parent_array_prop_name;
	};

	class client_class {
	public:
		create_client_class client;
		create_event event;

		char* network_name;

		recv_table* table;
		client_class* next;

		std::int32_t class_id;
	};
}
