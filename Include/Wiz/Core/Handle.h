﻿// ============================================================
// @Author: Blaine Luo
// @Date: 2016/08
// ============================================================
#ifndef __WIZ_CORE_HANDLE_H__
#define __WIZ_CORE_HANDLE_H__

#include "Wiz/Core/Forward.h"

// ===================================Namespace Head==========================================
namespace Wiz{ namespace Core{

// ============================================================
// @Brief: Handle Template
// ============================================================
template< typename T, T NullHandle >
class HandleT{

public:
	typedef T Handle;
	enum{ _nullHandle = (int)NullHandle };

private:
	Handle _handle;

public:
	static Handle GetNullHandle(){
		return (Handle)_nullHandle;
	}

	HandleT(){
		this->setNullHandle();
	}

	~HandleT(){
		this->setNullHandle();
	}

	inline Handle& getHandle(){
		return _handle;
	}

	inline Handle* getHandleAddress(){
		return &_handle;
	}

	inline HandleT& setHandle( Handle handle ){
		_handle = handle;
		return *this;
	}

	inline HandleT& setNullHandle(){
		return this->setHandle( this->GetNullHandle() );
	}

	inline bool isCreated(){
		return( this->getHandle() != this->GetNullHandle() );
	}

	inline BOOL closeHandle(){
		return ::CloseHandle( this->getHandle() );
	}

	operator Handle&(){
		return this->getHandle();
	}
};

// ============================================================
// @Brief: Handle Pointer Template
// @Note: This Pointer Template only handle
//        Pointer once, it has no reference count.
// ============================================================
template< typename T >
class HandleP : public HandleT< T*, NULL >{

public:
	HandleP(){
		this->HandleT::HandleT();
	}

	HandleP( T* type ){
		this->setHandle( type );
	}

	~HandleP(){
		if( this->isCreated() )
			delete this->getHandle();
	}

	HandleP& operator =( T* type ){
		this->setHandle( type );
		return *this;
	}

	T* operator ->(){
		return this->getHandle();
	}
};

}}
// ===================================Namespace Tail==========================================

#endif