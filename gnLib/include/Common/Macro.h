#ifndef MACRO_H
#define MACRO_H

#define RELEASE(x) if( (x) != nullptr ){ (x)->Release(); (x) = nullptr; }

#define FVF_CUSTOM2D    ( D3DFVF_XYZRHW | D3DFVF_DIFFUSE | D3DFVF_TEX1 )
#define FVF_CUSTOM    ( D3DFVF_XYZ | D3DFVF_DIFFUSE | D3DFVF_TEX1 )

#endif // !MACRO_H
