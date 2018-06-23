#include "shape.hpp"

Shape::Shape():
    name_{"DefaultShape"},
    color_{0.0f,0.0f,0.0f} {
        std::cout << "ctor of base class shape \n";
    }

Shape::Shape(std::string const& name, Color const& col):
    name_{name},
    color_{col}{
        std::cout << "ctor of base class shape \n";
    }

Shape::~Shape(){                  //dtor = destructor
    std::cout << "dtor of base class Shape \n";
}


std::string Shape::getName() const {
    return name_;
}

Color Shape::getColor() const {
    return color_;
}

 std::ostream& Shape::print(std::ostream& os) const{
    os << "Name: " << name_ << ", \n" << "Color: (" << color_.r << "," << color_.g << "," << color_.b << ") \n";
    return os;
}

std::ostream& operator<< (std::ostream& os, Shape const& s){
    return s.print(os);
}