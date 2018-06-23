#define CATCH_CONFIG_RUNNER
#include <catch.hpp>

#include "box.hpp"
#include "sphere.hpp"
#include "shape.hpp"
#include "ray.hpp"
#include <glm/glm.hpp>
#include <glm/gtx/intersect.hpp>



TEST_CASE ("sphere_default_constructor","[default]")
{
  std::cout << "--------------------------------------------- \n";
  Sphere s1 {};
  REQUIRE (s1.getCenter().x == 0);
  REQUIRE (s1.getCenter().y == 0);
  REQUIRE (s1.getCenter().z == 0);
  REQUIRE (s1.getRadius() == 1);
  std::cout << "--------------------------------------------- \n";
}

TEST_CASE ("box_default_constructor","[default]")
{
  std::cout << "--------------------------------------------- \n";
  Box b1 {};
  REQUIRE (b1.getMax().x == 0);
  REQUIRE (b1.getMax().y == 0);
  REQUIRE (b1.getMax().z == 0);
  REQUIRE (b1.getMin().x == 0);
  REQUIRE (b1.getMin().y == 0);
  REQUIRE (b1.getMin().z == 0);
  std::cout << "--------------------------------------------- \n";
}
 
TEST_CASE ("box_constructor","[custom_constructor]")
{
  std::cout << "--------------------------------------------- \n";
  Box b1 {glm::vec3{1,1,1}, glm::vec3{3,8,-3}, "francine", Color{1.0f, 1.0f, 1.0f}};
  REQUIRE (b1.getMax().x == 3);
  REQUIRE (b1.getMax().y == 8);
  REQUIRE (b1.getMax().z == -3);
  REQUIRE (b1.getMin().x == 1);
  REQUIRE (b1.getMin().y == 1);
  REQUIRE (b1.getMin().z == 1);
  std::cout << "--------------------------------------------- \n";
}


TEST_CASE ("sphere_constructor","[sphere_constructor]")
{
  std::cout << "--------------------------------------------- \n";
  Sphere s1 {glm::vec3{1,1,1}, 4.0, "karl", Color{0.0f, 0.0f, 0.0f}};
  REQUIRE (s1.getCenter().x == 1);
  REQUIRE (s1.getCenter().y == 1);
  REQUIRE (s1.getCenter().z == 1);
  REQUIRE (s1.getRadius() == 4.0);
  std::cout << "--------------------------------------------- \n";
}

TEST_CASE ("sphere_area","[area]")
{ 
  std::cout << "--------------------------------------------- \n";
  Sphere s1 {glm::vec3{1,1,1}, 4.0,"karl", Color{0.0f, 0.0f, 0.0f}};
  Sphere s2 {};
  REQUIRE (s1.area() == Approx(268.0825731063));
  REQUIRE (s2.area() == Approx(4.1887902048));
  std::cout << "--------------------------------------------- \n";
}

TEST_CASE ("sphere_volume","[volume]")
{ 
  std::cout << "--------------------------------------------- \n";
  Sphere s1 {glm::vec3{1,1,1}, 4.0,"karl", Color{0.0f, 0.0f, 0.0f}};
  Sphere s2 {};
  REQUIRE (s1.volume() == Approx(201.0619298297));
  REQUIRE (s2.volume() == Approx(12.5663706144));
  std::cout << "--------------------------------------------- \n";
} 


TEST_CASE ("box_area","[area]")
{ 
  std::cout << "--------------------------------------------- \n";
  Box b1 {glm::vec3{1,1,1}, glm::vec3{3,8,3}, "francine", Color{1.0f, 1.0f, 1.0f}};
  Box b2{};
  REQUIRE (b1.area() == 28);
  REQUIRE (b2.area() == Approx(0.0));
  std::cout << "--------------------------------------------- \n";
}

TEST_CASE ("box_volume","[volume]")
{ 
  std::cout << "--------------------------------------------- \n";
  Box b1 {glm::vec3{1,1,1}, glm::vec3{3,8,3}, "francine", Color{1.0f, 1.0f, 1.0f}};
  Box b2 {};
  REQUIRE (b1.volume() == 64);
  REQUIRE (b2.volume() == Approx(0.0));
  std::cout << "--------------------------------------------- \n";
}  

TEST_CASE ("sphere_getter_shape","[shape_getter]")
{ 
  std::cout << "--------------------------------------------- \n";
  Sphere shapie {glm::vec3{1,1,1}, 4.0,"francine", Color{1.0f, 1.0f, 1.0f}};
  Sphere s2 {};
  REQUIRE (shapie.getName() == "francine");
  REQUIRE (shapie.getColor().r == 1.0f);
  REQUIRE (shapie.getColor().g == 1.0f);
  REQUIRE (shapie.getColor().b == 1.0f);
  REQUIRE (s2.getName() == "DefaultShape");
  REQUIRE (s2.getColor().r == 0.0f);
  REQUIRE (s2.getColor().g == 0.0f);
  REQUIRE (s2.getColor().b == 0.0f);
  std::cout << "--------------------------------------------- \n";
}  

TEST_CASE ("box_getter_shape","[shape_getter]")
{ 
  std::cout << "--------------------------------------------- \n";
  Box boxie {glm::vec3{1,1,1}, glm::vec3{2,5,7},"francine", Color{1.0f, 1.0f, 1.0f}};
  Box b2{};
  REQUIRE (boxie.getName() == "francine");
  REQUIRE (boxie.getColor().r == 1.0f);
  REQUIRE (boxie.getColor().g == 1.0f);
  REQUIRE (boxie.getColor().b == 1.0f);
  REQUIRE (b2.getName() == "DefaultShape");
  REQUIRE (b2.getColor().r == 0.0f);
  REQUIRE (b2.getColor().g == 0.0f);
  REQUIRE (b2.getColor().b == 0.0f);
  std::cout << "--------------------------------------------- \n";
} 

TEST_CASE ("sphere_print","[print]")
{ 
  std::cout << "--------------------------------------------- \n";
  Sphere shapie {glm::vec3{1,1,1}, 4.0,"shapie", Color{1.0f, 1.0f, 1.0f}};
  Sphere s2 {};
  std::cout << shapie;
  std::cout << s2;
  std::cout << "--------------------------------------------- \n";
}  

TEST_CASE ("box_print","[print]")
{ 
  std::cout << "--------------------------------------------- \n";
  Box boxie {glm::vec3{1,1,1}, glm::vec3{2,5,7},"francine", Color{1.0f, 1.0f, 1.0f}};
  Box box2 {};
  std::cout << boxie;
  std::cout << box2;
  std::cout << "--------------------------------------------- \n";
} 

TEST_CASE ("intersect_ray_sphere","[intersect]")  
{
    std::cout << "--------------------------------------------- \n";
    // Ray
    glm::vec3 ray_origin{0.0f,0.0f,0.0f};

    // ray direction has to be normalized !
    // you can use :
    // v = glm::normalize (some_vector)
    glm::vec3 ray_direction{0.0f,0.0f,1.0f};

    // Sphere
    glm::vec3 sphere_center{0.0f,0.0f,5.0f};
    float sphere_radius {1.0f};

    float distance = 0.0f;  //welche distanz genau ist das?
    auto result = glm::intersectRaySphere(
        ray_origin, ray_direction, sphere_center, 
        sphere_radius*sphere_radius, // squared radius !!!
        distance);

    Sphere s1{sphere_center, sphere_radius, "experimental", Color{1.0f, 1.0f, 1.0f}};
    Ray ray1 {ray_origin, ray_direction};

    REQUIRE (distance == Approx(4.0f));
    REQUIRE (s1.intersect(ray1,distance) == true);

    std::cout << "--------------------------------------------- \n";
}  

TEST_CASE ("ctor_and_dtor", "[5.8")
{
    std::cout << "--------------------------------------------- \n";
    Color red {255,0,0};
    glm::vec3 position {0.0f,0.0f,0.0f};

    Sphere* s1 = new Sphere {position,1.2,"sphere0", red};
    Shape* s2 = new Sphere {position,1.2, "sphere1", red};

    s1 -> print (std::cout);
    s2 -> print (std::cout);

    delete s1;
    delete s2;
    std::cout << "--------------------------------------------- \n";
}  

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
