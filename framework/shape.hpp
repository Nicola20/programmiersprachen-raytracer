#ifndef SHAPE_HPP
#define SHAPE_HPP

#include "color.hpp"
#include "ray.hpp"
#include "material.hpp"
#include <string>

class Shape {

    public:
    virtual double area() const = 0;  //calculates the surface
    virtual double volume() const = 0;  //calculates the volume
    Shape();
    Shape(std::string const& name, std::shared_ptr<Material> const& material);
    Shape(std::string const& name, Color const& col);
    virtual std::ostream& print(std::ostream& os) const;
    std::string getName() const;
    Color getColor() const;
    virtual ~Shape();
    //~Shape();
    virtual bool intersect (Ray const& ray, float& t) const = 0;

    protected:
    std::string name_;
    std::shared_ptr<Material> material_; 
    Color color_;
};

std::ostream& operator<< (std::ostream& os, Shape const& s);

#endif // SHAPE_HPP