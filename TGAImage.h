#ifndef RT_TGAIMAGE_H
#define RT_TGAIMAGE_H

#include <bits/stdc++.h>
#include "Color.h"

class TGAImage {
public:
    TGAImage(uint16_t width, uint16_t height);

    uint8_t bitsPerColor = 32;
    uint8_t bitsPerAlpha = 8;
    uint16_t width, height;

    Color* data = nullptr;

    int write(char *string);

    void set(int x, int y, Color c);

private:
public:
    virtual ~TGAImage();
};

#endif // RT_TGAIMAGE_H
