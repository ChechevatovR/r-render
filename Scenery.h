#ifndef IT_GEOMETRIES_H
#define IT_GEOMETRIES_H

#include "bits/stdc++.h"
#include "TGAImage.h"
#include "Color.h"

#define PI 3.1415926535897932384626433832795


std::vector<double> matrixMultiply(std::vector<double> a, std::vector<std::vector<double>> b) {
    /*
       a11
       a21
       a31
       ---*
          | b11 b12 b13
          | b21 b22 b23
          | b31 b32 b33
     */
    std::vector<double> c(3);
    for (int i = 0; i < 3; i++) {
        c[i] = 0;
        for (int j = 0; j < 3; j++) {
            c[i] += a[j] * b[i][j];
        }
    }
    return c;
}

struct Point {
    double x, y, z;

    Point(double a, double b, double c) {
        x = a;
        y = b;
        z = c;
    }
};

struct Sphere {
    double r;
    Point c;
    Color color;
    unsigned int sharpeness; // if 0 - no highlights
    double reflectivity;

    Sphere(double x, double y, double z, double rad, int r, int g, int b, unsigned int shrp, double refl) : c(
            Point(x, y, z)), r(rad),
                                                                                                            color(Color(
                                                                                                                    r,
                                                                                                                    g,
                                                                                                                    b,
                                                                                                                    255)),
                                                                                                            sharpeness(
                                                                                                                    shrp),
                                                                                                            reflectivity(
                                                                                                                    refl) {}
};

struct Light {
    double strength;
    Point c;

    Light(double str, double x, double y, double z) : c(Point(x, y, z)), strength(str) {}
};

double deg_to_rad(double rad) {
    return rad * PI / 360;
}

// ============================== Low functions =============================
template<typename T>
T to_range(T a, T min_, T max_) {
    return std::min(max_, std::max(min_, a));
}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
std::ostream &operator<<(std::ostream &out, Point &p) {
    out << "Point(" << p.x << "; " << p.y << "; " << p.z << ")";
    return out;
}

Point operator+(Point a, Point b) {
    return Point(a.x + b.x, a.y + b.y, a.z + b.z);
}

Point operator*(Point a, double k) {
    return Point(a.x * k, a.y * k, a.z * k);
}

double operator*(Point a, Point b) {
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

Point operator/(Point a, double k) {
    return Point(a.x / k, a.y / k, a.z / k);
}

Point operator-(Point a, Point b) {
    return a + (b * -1.);
}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
Color mix(Color a, Color b) {
    return Color((a.r + b.r) / 2, (a.g + b.g) / 2, (a.b + b.b) / 2, 255);
}

Color operator*(Color a, double k) {
    return Color(to_range(a.r * k, 0., 255.), to_range(a.g * k, 0., 255.), to_range(a.b * k, 0., 255.), 255);
}

Color operator+(Color a, Color b) {
    return Color(to_range(a.r + b.r, 0, 255), to_range(a.g + b.g, 0, 255), to_range(a.b * b.b, 0, 255), 255);
}

// ================================= Scene =================================
const std::vector<Sphere>
spheres = {
        //      x   y      z  rad    r    g    b  shrp  refl
        Sphere(10, -3, -1, 0.5, 0, 255, 255, 20, 0.3),
        Sphere(15, 5, 0, 2, 255, 0, 255, 100, 0),
        Sphere(15, 1, 0, 1, 0, 0, 255, 25, 0.15),
        Sphere(25, -6, 1, 3, 255, 255, 0, 15, 0.7),
        Sphere(10, -2, 1, 0.5, 0, 255, 0, 75, 0),
        Sphere(0, 0, -1005, 999, 255, 255, 255, 30, 1)
};

const std::vector<Light> lights_p = {
        Light(0.4, 3, -3, 10)
};
const Light light_d = Light(0.7, -1, 3, 3); // Directional light
const double light_a = 0.1; // Ambient light
// =========================================================================

#endif
