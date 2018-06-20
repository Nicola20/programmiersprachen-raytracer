#ifndef SHAPE_HPP
#define SHAPE_HPP

class Shape {

    public:
    virtual double area() const = 0;  //calculates the surface
    virtual double volume() const = 0;  //calculates the volume
};
#endif // SHAPE_HPP