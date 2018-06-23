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
    virtual std::ostream& print(std::ostream& os) const;
    std::string getName() const;
    Color getColor() const;
    virtual ~Shape();
    //~Shape();

    protected:
    std::string name_;
    Color color_;
};

std::ostream& operator<< (std::ostream& os, Shape const& s);

#endif // SHAPE_HPP