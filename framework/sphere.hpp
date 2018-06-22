# ifndef SPHERE_HPP
# define SPHERE_HPP

#include <glm/vec3.hpp>
#include "shape.hpp"
#include "ray.hpp"

class Sphere: public Shape {

    public:
    Sphere ();
    Sphere (glm:: vec3 const& c, double r, std::string const& name, Color const& col);
    double area() const override;  //calculates the surface
    double volume() const override;  //calculates the volume
    glm::vec3 getCenter() const;
    double getRadius() const;
    std::ostream& print(std::ostream& os) const override;
    bool intersect (Ray const& ray, float& distance) const;

    private:
    glm::vec3 center_;
    double radius_;

};
# endif // SPHERE_HPP