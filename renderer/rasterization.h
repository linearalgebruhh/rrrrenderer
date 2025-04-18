#pragma once
#include "tgaimage.h"
#include "geometry.h"
class rasterization {
public:
	void drawLine(vec2 s, vec2 e, TGAImage& image, TGAColor color);
	void drawTriangle(vec2 s, vec2 e, TGAImage& image, TGAColor color);
	
};