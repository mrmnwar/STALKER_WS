#include "stdafx.h"

void CRenderTarget::render_posteffect(ref_rt& rt_Posteffect, u32& Offset, ref_selement& s_posteffect)
{
	Fvector2		p0,p1;

	u_setrt			(rt_Posteffect,		0,0,HW.pBaseZB);
	RCache.set_CullMode		(CULL_NONE);
	RCache.set_Stencil		(FALSE);

	struct v_combine2	{
		Fvector4		p;
		Fvector2		uv0;
	};

	float	_w		= float(Device.dwWidth);
	float	_h		= float(Device.dwHeight);
	p0.set			(0.5f/_w,	0.5f/_h);
	p1.set			((_w+0.5f)/_w,	(_h+0.5f)/_h);

	v_combine2* pv		= (v_combine2*)		RCache.Vertex.Lock(4,g_combine2->vb_stride,Offset);
	pv->p.set(EPS, float(_h+EPS), EPS, 1.0f);				pv->uv0.set(p0.x,p1.y);		pv++;
	pv->p.set(EPS, EPS, EPS, 1.0f);							pv->uv0.set(p0.x,p0.y);		pv++;
	pv->p.set(float(_w+EPS), float(_h+EPS), EPS, 1.0f);		pv->uv0.set(p1.x,p1.y);		pv++;
	pv->p.set(float(_w+EPS), EPS, EPS, 1.0f);				pv->uv0.set(p1.x,p0.y);		pv++;
	RCache.Vertex.Unlock	(4,g_combine2->vb_stride);
	RCache.set_Geometry		(g_combine2);

	RCache.set_Element		(s_posteffect);
}