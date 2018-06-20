#include "shape.hpp"

Shape::Shape():
    name_{"DefaultShape"},
    color_{0.0f,0.0f,0.0f} {}

Shape::Shape(std::string const& name, Color const& col):
    name_{name},
    color_{col}{}

virtual std::ostream& Shape::print(std::ostream& os) const{
    os << name_ << ", \n" << color_;
    return os;
}

std::ostream& Shape::operator<< (std::ostream& os, Shape const& s){
    return s.print(os);
}