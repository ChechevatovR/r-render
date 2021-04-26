#ifndef RT_VECTOR3_H
#define RT_VECTOR3_H


class Vector3 {
    long double x, y, z;
    
    Vector3() = default;
    
    Vector3(long double x_, long double y_, long double z_): x(x_), y(y_), z(z_) {}
    
    Vector3 operator+(const Vector3& other) {
        return {x + other.x, y + other.y, z + other.z};
    }
};


#endif //RT_VECTOR3_H
