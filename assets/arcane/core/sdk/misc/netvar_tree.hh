#pragma once

#include <unordered_map>
#include <memory>

namespace arcane::sdk::ifaces {
	struct recv_table;
}

namespace arcane::sdk::misc {
	// https://gist.github.com/AltimorTASDK/75fe97ff3174a7de3739

	class netvar_tree final {
		struct node;

		using map_type = std::unordered_map< std::string, std::shared_ptr< node > >;

		struct node {
			explicit node( const std::int32_t offset ) : offset( offset ) { }

			map_type nodes;

			std::int32_t offset;
		};

		map_type nodes { };

	public:
		netvar_tree( );

		template < typename... T > std::int32_t get_offset( const char* name, T ... args ) {
			const auto& node = nodes[ name ];

			return get_offset_recursive( node->nodes, node->offset, args... );
		}

	private:
		void populate_nodes( ifaces::recv_table* recv_table, map_type* map ) const;

		static std::int32_t get_offset_recursive( map_type& map, const std::int32_t acc, const char* name ) {
			return acc + map[ name ]->offset;
		}

		template < typename... T > std::int32_t get_offset_recursive( map_type& map, const std::int32_t acc, const char* name, T ... args ) {
			const auto& node = map[ name ];

			return get_offset_recursive( node->nodes, acc + node->offset, args... );
		}
	};

	extern std::unique_ptr< netvar_tree > get_netvar_tree;
}
