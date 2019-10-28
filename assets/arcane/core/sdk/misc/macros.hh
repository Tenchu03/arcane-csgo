#pragma once

#include "capture_iface.hh"
#include "vmt_hook.hh"
#include "netvar_tree.hh"
#include "vfunc_from_index.hh"

#define REGISTERS \
	std::uintptr_t ecx, std::uintptr_t edx

#define PAD( variable_name, size ) \
	std::byte variable_name[ size ]

#define CAPTURE_IFACE( var_name, iface_struct, iface_module, iface_name ) \
	iface_struct* var_name = arcane::sdk::misc::capture_iface< iface_struct* >( iface_module, iface_name )

#define MEM_PTR( var_name, iface_struct, iface_ptr, base, offset ) \
	iface_struct* var_name = **reinterpret_cast< iface_struct*** >( ( *reinterpret_cast< std::uintptr_t** >( iface_ptr ) )[ base ] + offset )

#define SETUP_HOOK( hook_ptr, iface_ptr ) \
	hook_ptr = std::make_unique< arcane::sdk::misc::vmt_hook >( iface_ptr )

#define HOOK_FUNC( var_name, index, func_name ) \
	var_name->hook_func( index, reinterpret_cast< void* >( func_name ) )

#define UNHOOK_FUNC( var_name, index ) \
	var_name->unhook_func( index )

#define GET_ORIG_FUNC( var_name, index, type, ... ) \
	var_name->get_orig_func< type >( index )( __VA_ARGS__ )

#define RETURN_ORIG_FUNC( var_name, index, type, ... ) \
	return var_name->get_orig_func< type >( index )( __VA_ARGS__ )

#define NETVAR( func_name, type, ... ) \
	type& func_name \
	{ \
		return *reinterpret_cast< type* >( reinterpret_cast< std::uintptr_t >( this ) + misc::get_netvar_tree->get_offset( __VA_ARGS__ ) ); \
	};

#define OFFSET( func_name, type, offset ) \
	type& func_name \
	{ \
		return *reinterpret_cast< type* >( std::uintptr_t( this ) + offset ); \
	};

#define VFUNC( func_name, index, type, ... ) \
	auto func_name \
	{ \
		return arcane::sdk::misc::vfunc_from_index< type >( this, index )( this, __VA_ARGS__ ); \
	};

#define CONV_ENUM_TYPE( type, enum_class ) \
    static_cast< type >( enum_class )