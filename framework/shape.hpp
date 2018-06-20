#ifndef SHAPE_HPP
#define SHAPE_HPP

#include "color.hpp"
#include <string>

class Shape {

    public:
    virtual double area() const = 0;  //calculates the surface
    virtual double volume() const = 0;  //calculates the volume
    Shape();
    Shape(std::string const& name, Color const& col);

    protected:
    std::string name_;
    Color color_;
};
#endif // SHAPE_HPP