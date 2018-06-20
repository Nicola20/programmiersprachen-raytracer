# ifndef SPHERE_HPP
# define SPHERE_HPP

#include <glm/vec3.hpp>
#include "shape.hpp"

class Sphere: public Shape {

    public:
    Sphere ();
    Sphere (glm:: vec3 const& c, double r);
    double area() const override;  //calculates the surface
    double volume() const override;  //calculates the volume
    glm::vec3 getCenter() const;
    double getRadius() const;

    private:
    glm::vec3 center_;
    double radius_;

};
# endif // SPHERE_HPP