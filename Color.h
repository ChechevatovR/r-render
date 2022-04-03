#ifndef RT_COLOR_H
#define RT_COLOR_H

#include <cstdint>

class Color {
public:
    Color() = default;

    Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a);

    uint8_t r, g, b, a;
};


#endif //RT_COLOR_H
