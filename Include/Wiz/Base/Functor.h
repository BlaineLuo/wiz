﻿// ============================================================
// @Author	Blaine
// @Date	2015/07
// ============================================================
#ifndef __WIZ_BASE_FUNCTOR_H__
#define __WIZ_BASE_FUNCTOR_H__

// ===================================Namespace Head==========================================
namespace Wiz{ namespace Base{ namespace Functor{

template< typename T >
inline T Add( const T& a, const T& b ){
	return ( a + b );
}

template< typename T >
inline T Sub( const T& a, const T& b ){
	return ( a - b );
}

template< typename T >
inline T AddAssign( T& a, const T& b ){
	return ( a += b );
}

template< typename T >
inline T SubAssign( T& a, const T& b ){
	return ( a -= b );
}

template< typename T >
inline bool Equal( const T& a, const T& b ){
	return ( a == b );
}

template< typename T >
inline T Gcd( const T a, const T b ){
	if( 0 == b )
		return a;
	return Gcd( b, a % b );
}

template< typename T >
inline bool ReduceFraction( T& a, T& b ){
	T gcd = Gcd( a, b );
	if( 0 == gcd )
		return false;

	a /= gcd;
	b /= gcd;
	return true;
}

}}}
// ===================================Namespace Tail==========================================

#endif
