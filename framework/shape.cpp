#include "shape.hpp"

Shape::Shape():
    name_{"DefaultShape"},
    color_{0.0f,0.0f,0.0f} {}

Shape::Shape(std::string const& name, Color const& col):
    name_{name},
    color_{col}{}