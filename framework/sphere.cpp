#include "sphere.hpp"
#include <math.h>

Sphere::Sphere ():
    Shape(),
    center_{0,0,0},
    radius_{1} {}

Sphere::Sphere (glm::vec3 const& c, double r,std::string const& name, Color const& col):
    Shape(name, col),
    center_{c},
    radius_{r} {}

glm::vec3 Sphere::getCenter() const{
    return center_;
}

double Sphere::getRadius() const {
    return radius_;
}

//calculates the surface
double Sphere::area() const{
    return ((4/3.0f)*M_PI*pow(radius_,3));
}

//calculates the volume
double Sphere::volume() const {
    return (4*M_PI*pow(radius_,2));
}  