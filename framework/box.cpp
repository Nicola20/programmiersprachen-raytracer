#include "box.hpp"
#include <math.h>

Box ():
    min_{0,0,0},
    max_{0,0,0} {}

Box(glm::vec3 min, glm::vec3 max):
    min_{min},
    max_{max} {}

glm::vec3 Box::getMin(){
    return min_;
}

double Box::getMax() {
    return max_;
}

//calculates the surface
double Box::area() const override {
    double a = min_.z + max_.z;  //diference on z-axsis; + because max_ has a negative value
    double b = max_.y - min_.y;  //diference on y axsis
    double c = max_.x - min_.x;  //diference on x axis

    return a*b*c;

}

//calculates the volume
double Box::volume() const override {
    double a = min_.z + max_.z;  //diference on z-axsis; + because max_ has a negative value
    double b = max_.y - min_.y;  //diference on y axsis
    double c = max_.x - min_.x;  //diference on x axis

    return 2*(a*b + b*c + a*c);

} 