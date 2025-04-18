#include "rasterization.h"
#include<cmath>
#include <cstdlib>
#include <limits>
using namespace std;

void rasterization::drawLine(vec2 s, vec2 e, TGAImage& image, TGAColor color) {
    int iversed = 0;
    if (abs(s.x - e.x) < abs(s.y - e.y)) {
        swap(s.x, s.y);
        swap(e.x, e.y);
        iversed = 1;
    }
    if (s.x > e.x) {
        swap(s.x, e.x);
        swap(s.y, e.y);
    }
    for (int i = s.x; i <= e.x; i++) {
        float t = (i - s.x) / (float)(e.x - s.x);
        int j = s.y * (1. - t) + e.y * t;
        if (iversed) {
            image.set(j, i, color);
        }
        else {
            image.set(i, j, color);
        }
    }
}

void rasterization::drawLine(vec2 s, vec2 e, TGAImage& image, TGAColor color) {
    if (s.x > e.x) {
        swap(s.x, e.x);
        swap(s.y, e.y);
    }
    for (int x = s.x; x <= e.x; x++) {
        float t = (x - s.x) / static_cast<float>(e.x - s.x);
        int y = round((1 - t) * s.y + t * e.y);
        framebuffer.set(x, y, color);
    }
}
