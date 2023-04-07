#ifndef VEC3_H
#define VEC3_H

#include <cmath>
#include <iostream>

class vec3 {
    public:
        vec3() : e{0,0,0} {} //Initialization list sets array to 0,0,0 by default
        vec3(double e0, double e1, double e2) : e{e0, e1, e2} {} //Initialization list sets e to e0,e1,e2

        double x() const { return e[0]; } //Constant member function means the function cannot modify any data
        double y() const { return e[1]; }
        double z() const { return e[2]; }

        vec3 operator-() const { return vec3(-e[0], -e[1], -e[2]); }
        double operator[](int i) const { return e[i]; }
        double& operator[](int i) { return e[i]; }

        vec3& operator+=(const vec3 &v){
            e[0] += v.e[0];
            e[1] += v.e[1];
            e[2] += v.e[2];
            return *this; //This is of type Class*, which means to return a reference, we want the type of Class
        }

        vec3& operator*=(const double t){
            e[0] *= t;
            e[1] *= t;
            e[2] *= t;
            return *this; //This is of type Class*, which means to return a reference, we want the type of Class
        }

        vec3& operator/=(const double t){
            return *this *= 1/t;
        }

        double length_squared() const {
            return e[0]*e[0] + e[1]*e[1] + e[2]*e[2];
        }

        double length() const {
            return std::sqrt(length_squared());
        }
    public:
        double e[3];
};

// Type aliases
using point3 = vec3; //3D point
using color = vec3; //RGB colot

// Utility functions
//Overloaded operators have two arguments here because they are not class member functions
//The class member functions just need one argument because they inherently operate on the class type
inline std::ostream& operator<<(std::ostream &out, const vec3 &v){
    return out << v.e[0] << ' ' << v.e[1] << ' ' << v.e[2];
}

inline vec3 operator+(const vec3 &u, const vec3 &v){
    
}

#endif