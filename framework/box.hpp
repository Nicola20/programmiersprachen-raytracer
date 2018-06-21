#ifndef BOX_HPP
#define BOX_HPP

#include <glm/vec3.hpp>
#include "shape.hpp"

class Box: public Shape {

    public:
    Box ();
    Box (glm::vec3 const& min, glm::vec3 const& max,std::string const& name, Color const& col);
    double area() const override;  //calculates the surface
    double volume() const override;  //calculates the volume
    glm::vec3 getMax() const;
    glm::vec3 getMin() const;
    std::ostream& print(std::ostream& os) const override;

    private:
    glm::vec3 max_;
    glm::vec3 min_;

};
#endif // BOX_HPP

