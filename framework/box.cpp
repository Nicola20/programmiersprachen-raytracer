#include "box.hpp"
#include <math.h>
/*
Box::Box ():
    Shape::Shape(),
    min_{0,0,0},
    max_{0,0,0} {
        std::cout << "ctor of derived class Box \n";
    }

Box::Box (glm::vec3 const& min, glm::vec3 const& max,std::string const& name, Color const& col):
    Shape::Shape(name, col),
    min_{min},
    max_{max} {
        std::cout << "ctor of derived class Box \n";
    }*/

Box (glm::vec3 const& min, glm::vec3 const& max,std::string const& name, std::shared_ptr<Material> const& material):
    Shape::Shape(name, material),
    min_{min},
    max_{max} {
        std::cout << "ctor of derived class Box \n";
    }

Box::~Box(){
    std::cout << "dtor of derived class Box \n";
}

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

std::ostream& Box::print(std::ostream& os) const {
    Shape::print(os);
    os << "Vector max_: (" << max_.x << "," << max_.y << "," << max_.z << "), \n" << "Vector min_: (" << min_.x << "," << min_.y << "," << min_.z << ") \n \n";
    return os;
}

bool Box::intersect (Ray const& ray) const {  
    float tx1 = (min_.x - ray.origin_.x)/ray.direction_.x;
    float tx2 = (max_.x - ray.origin_.x)/ray.direction_.x;

    float ty1 = (min_.y - ray.origin_.y)/ray.direction_.y;
    float ty2 = (max_.y - ray.origin_.y)/ray.direction_.y;

    float tz1 = (min_.z - ray.origin_.z)/ray.direction_.z;
    float tz2 = (max_.z - ray.origin_.z)/ray.direction_.z;
   /*
    float tfarx = std::max(tx1, tx2);
    float tnearx = std::min(tx1, tx2);

    float tfary = std::max(ty1, ty2);  //warum wird hier max und min anders herum verwendet?
    float tneary = std::min(ty1, ty2);

    float tfar = std::min(tfarx, tfary);
    float tnear = std::max(tnearx, tneary);

    if(tfar < tnear){
        return false;
    }

    tfar = std::min(tz2, tfar);
    tnear = std::max(tz1, tnear);       //tnear ist schnittpunkt

    if(tfar < tnear){
        return false;
    }
    //Eigentlichen Schnittpunkt berechnen
     float distance = std::abs(tnear);
    return true;*/
    float tmin = max(max(min(tx1, tx2), min(ty1, ty2)), min(tz1, tz2));
    float tmax = min(min(max(tx1, tx2), max(ty1, ty2)), max(tz1, tz2));

// if tmax < 0, ray (line) is intersecting AABB, but the whole AABB is behind us
if (tmax < 0)
{
    //t = tmax;
    return false;
}

// if tmin > tmax, ray doesn't intersect AABB
if (tmin > tmax)
{
    //t = tmax;
    return false;
}

t = tmin;
return true;
} 