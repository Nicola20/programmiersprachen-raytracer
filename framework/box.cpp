#include "box.hpp"
#include <math.h>

Box::Box ():
    Shape(),
    min_{0,0,0},
    max_{0,0,0} {}

Box::Box (glm::vec3 const& min, glm::vec3 const& max,std::string const& name, Color const& col):
    Shape(name, col),
    min_{min},
    max_{max} {}

glm::vec3 Box::getMin() const{
    return min_;
}

glm::vec3 Box::getMax() const {
    return max_;
}

//calculates the surface
double Box::area() const {
    double a = max_.z - min_.z;  //diference on z-axsis; + because max_ has a negative value
    double b = max_.y - min_.y;  //diference on y axsis
    double c = max_.x - min_.x;  //diference on x axis

    return a*b*c;

}

//calculates the volume
double Box::volume() const {
    double a = max_.z - min_.z;  //diference on z-axsis; + because max_ has a negative value
    double b = max_.y - min_.y;  //diference on y axsis
    double c = max_.x - min_.x;  //diference on x axis

    return 2*(a*b + b*c + a*c);

} 