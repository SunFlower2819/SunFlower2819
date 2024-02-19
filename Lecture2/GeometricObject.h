#pragma once

#include "Game2D.h"

namespace jm
{
	class GeometricObject
	{
	public:
		vec2 pos;
		RGB color;

		void init(const RGB& _color, const vec2& _pos)
		{
			color = _color;
			pos = _pos;
		}

		// 순수 가상 함수
		virtual void drawGeometry() const = 0;

		void draw()
		{
			beginTransformation();
			{
				translate(pos);
				drawGeometry();
			}
			endTransformation();
		}
	};
}