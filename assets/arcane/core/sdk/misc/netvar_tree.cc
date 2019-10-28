#include "netvar_tree.hh"

#include "../../ifaces/ifaces.hh"

namespace arcane::sdk::misc {
	// https://gist.github.com/AltimorTASDK/55b8b28e552eba0f6162

	netvar_tree::netvar_tree( ) {
		const auto* client_class = core::ifaces::get_ifaces.base_client->get_all_classes( );

		while ( client_class != nullptr ) {
			const auto class_info = std::make_shared< node >( 0 );

			auto recv_table = client_class->table;

			populate_nodes( recv_table, &class_info->nodes );

			nodes.emplace( recv_table->net_table_name, class_info );

			client_class = client_class->next;
		}
	}

	void netvar_tree::populate_nodes( ifaces::recv_table* recv_table, map_type* map ) const {
		for ( auto i = 0; i < recv_table->props; i++ ) {
			const ifaces::recv_prop* prop = &recv_table->prop[ i ];

			const auto prop_info = std::make_shared< node >( prop->offset );

			if ( prop->recv_type == CONV_ENUM_TYPE( std::int32_t, enums::send_prop_type::send_prop_type_data_table ) )
				populate_nodes( prop->data_table, &prop_info->nodes );

			map->emplace( prop->var_name, prop_info );
		}
	}

	std::unique_ptr< netvar_tree > get_netvar_tree;
}
