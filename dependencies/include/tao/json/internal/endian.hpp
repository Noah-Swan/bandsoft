// Copyright (c) 2017 Dr. Colin Hirsch and Daniel Frey
// Please see LICENSE for license or visit https://github.com/taocpp/json/

#ifndef TAOCPP_JSON_INCLUDE_INTERNAL_ENDIAN_HPP
#define TAOCPP_JSON_INCLUDE_INTERNAL_ENDIAN_HPP

#include <cstdint>
#include <cstring>

// TODO: Where to put this header?

#if defined( _WIN32 ) && !defined( __MINGW32__ )
#include "endian_win.hpp"
#else
#include "endian_gcc.hpp"
#endif

namespace tao
{
   namespace json
   {
      namespace internal
      {
         template< typename N >
         N h_to_be( const N n ) noexcept
         {
            return N( to_and_from_be< sizeof( N ) >::convert( n ) );
         }

         template< typename N >
         N be_to_h( const N n ) noexcept
         {
            return h_to_be( n );
         }

         template< typename N >
         N be_to_h( const void* p ) noexcept
         {
            N n;
            std::memcpy( &n, p, sizeof( n ) );
            return internal::be_to_h( n );
         }

         template< typename N >
         N h_to_le( const N n ) noexcept
         {
            return N( to_and_from_le< sizeof( N ) >::convert( n ) );
         }

         template< typename N >
         N le_to_h( const N n ) noexcept
         {
            return h_to_le( n );
         }

         template< typename N >
         N le_to_h( const void* p ) noexcept
         {
            N n;
            std::memcpy( &n, p, sizeof( n ) );
            return internal::le_to_h( n );
         }

      }  // namespace internal

   }  // namespace json

}  // namespace tao

#endif
