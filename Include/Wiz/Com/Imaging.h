// ============================================================
// @Brief: Windows COM Imaging Classes (for WinCE)
// @Author: Blaine Luo
// @Date: 2016/08
// ============================================================
#ifndef __WIZ_COM_IMAGING_H__
#define __WIZ_COM_IMAGING_H__

#ifdef _WIN32_WCE

#include "Wiz/Com/Basic.h"
#include <Imaging.h>

// ===================================Namespace Head==========================================
namespace Wiz{ namespace Com{ namespace Imaging{

// ============================================================
class Factory : public ComObject< IImagingFactory >{
public:
	inline HRESULT createComObject(){
		return this->ComObject::createComObject( CLSID_ImagingFactory, IID_IImagingFactory );
	}
};

// ============================================================
class Image : public ComObject< IImage >{};

// ============================================================
class Bitmap : public ComObject< IBitmapImage >{};

}}}
// ===================================Namespace Tail==========================================

#endif

#endif
