#ifndef RT_TGAIMAGE_H
#define RT_TGAIMAGE_H

#include <bits/stdc++.h>


class TGAImage {

public:
    uint8_t bitsPerColor;
    uint8_t bitsPerAlpha;
    uint16_t width, height;
    
    int write();
    
private:
    // None
};

#endif // RT_TGAIMAGE_H