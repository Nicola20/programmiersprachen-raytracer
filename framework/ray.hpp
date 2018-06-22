#ifndef RAY_HPP
#define RAY_HPP

#include <glm/vec3.hpp>
#include <glm/glm.hpp>
#include <glm/gtx/intersect.hpp>

struct Ray {

    Ray():
        origin_{},
        direction_{} {}

    Ray(glm::vec3 const& origin, glm::vec3 const& distance):
        origin_{origin},
        direction_{glm::normalize(distance)} {}

    glm::vec3 origin_; //= {0.0f, 0.0f, 0.0f};
    glm::vec3 direction_; //= {0.0f, 0.0f, -1.0f};
};
# endif //RAY_HPP