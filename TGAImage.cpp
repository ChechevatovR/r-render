#include "TGAImage.h"

#include <bits/stdc++.h>

int TGAImage::write(char *filename) {
    std::ofstream file(filename, std::ios_base::binary | std::ios_base::out);
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
        for (int x = 0; x < width; x++) {
            file
                << (uint8_t) data[y * width + x].b
                << (uint8_t) data[y * width + x].r
                << (uint8_t) data[y * width + x].g
                << (uint8_t) data[y * width + x].a;
        }
    }
    file.close();
    return 0;
}

TGAImage::TGAImage(uint16_t width, uint16_t height) : width(width), height(height) {
    data = (Color *)(operator new(height * width * sizeof(Color)));
}

TGAImage::~TGAImage() {
    operator delete(data);
}

void TGAImage::set(int x, int y, Color c) {
    data[y * width + x] = c;
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
