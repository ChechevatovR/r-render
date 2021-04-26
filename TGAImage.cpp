#include "TGAImage.h"

#include <bits/stdc++.h>

int TGAImage::write() {
    std::ofstream file("test.tga", std::ios::binary | std::ios::out);
    if (!file.is_open()) return -1;
    
    file << (uint8_t) 0;
    file << (uint8_t) 0;
    
    file << (uint8_t) 2;
    
    file << (uint8_t) 0 << (uint8_t) 0 << (uint8_t) 0 << (uint8_t) 0 << (uint8_t) 0;
    
    file << (uint8_t) 0 << (uint8_t) 0; // X origin
    file << (uint8_t) 0 << (uint8_t) 0; // Y origin
    
    file << (uint8_t) (width & 0xff) << (uint8_t) ((width & 0xff00) >> 8u);
    file << (uint8_t) (height & 0xff) << (uint8_t) ((height & 0xff00) >> 8u);
    
    file << (uint8_t) bitsPerColor; // Pixel depth
    
    file << (uint8_t) (32u | bitsPerAlpha); // smth
    
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) file << (uint8_t) 32 << (uint8_t) 32 << (uint8_t) 32 << (uint8_t) y;
    }
    file.close();
    return 0;
}
/*
 * File structure
 * Field             Len  Val
 * Image Id Length - 1  - 0
 * Color map type  - 1  - 0
 * Image type      - 1  - 2 or 3 for true-color and BW respectively
 * Color map data  - 5  - 0
 * X origin        - 2  - 0
 * Y origin        - 2  - 0
 * Width           - 2  - width (reverse byte order)
 * Height          - 2  - height (reverse byte order)
 * Pixel depth     - 1  - bitsPerPixel
 * Bits 0-3 are
 *  alpha depth,
 *  4-5 direction  - 1  - 32|8
 *
 * Image Data:
 * Blue-Green-Red-Alpha
 */