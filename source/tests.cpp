#define CATCH_CONFIG_RUNNER
#include <catch.hpp>

#include "box.hpp"
#include "sphere.hpp"



TEST_CASE ("sphere_default_constructor","[default]")
{
  
  Sphere s1 {};
  REQUIRE (s1.getCenter().x == 0);
  REQUIRE (s1.getCenter().y == 0);
  REQUIRE (s1.getCenter().z == 0);
  REQUIRE (s1.getRadius() == 1);

}

TEST_CASE ("box_default_constructor","[default]")
{
  
  Box b1 {};
  REQUIRE (b1.getMax().x == 0);
  REQUIRE (b1.getMax().y == 0);
  REQUIRE (b1.getMax().z == 0);
  REQUIRE (b1.getMin().x == 0);
  REQUIRE (b1.getMin().y == 0);
  REQUIRE (b1.getMin().z == 0);

}
 
TEST_CASE ("box_constructor","[custom_constructor]")
{
  
  Box b1 {glm::vec3{1,1,1}, glm::vec3{3,8,-3}, "francine", Color{1.0f, 1.0f, 1.0f}};
  REQUIRE (b1.getMax().x == 3);
  REQUIRE (b1.getMax().y == 8);
  REQUIRE (b1.getMax().z == -3);
  REQUIRE (b1.getMin().x == 1);
  REQUIRE (b1.getMin().y == 1);
  REQUIRE (b1.getMin().z == 1);

}


TEST_CASE ("sphere_constructor","[sphere_constructor]")
{
  
  Sphere s1 {glm::vec3{1,1,1}, 4.0, "karl", Color{0.0f, 0.0f, 0.0f}};
  REQUIRE (s1.getCenter().x == 1);
  REQUIRE (s1.getCenter().y == 1);
  REQUIRE (s1.getCenter().z == 1);
  REQUIRE (s1.getRadius() == 4.0);

}
 //Werte anpassen
TEST_CASE ("sphere_area","[area]")
{ 
  Sphere s1 {glm::vec3{1,1,1}, 4.0,"karl", Color{0.0f, 0.0f, 0.0f}};
  REQUIRE (s1.area() == Approx(268.0825731063));
}

TEST_CASE ("sphere_volume","[volume]")
{ 
  Sphere s1 {glm::vec3{1,1,1}, 4.0,"karl", Color{0.0f, 0.0f, 0.0f}};
  REQUIRE (s1.volume() == Approx(201.0619298297));
} 


TEST_CASE ("box_area","[area]")
{ 
  Box b1 {glm::vec3{1,1,1}, glm::vec3{3,8,3}, "francine", Color{1.0f, 1.0f, 1.0f}};
  REQUIRE (b1.area() == 28);
}

TEST_CASE ("box_volume","[volume]")
{ 
  Box b1 {glm::vec3{1,1,1}, glm::vec3{3,8,3}, "francine", Color{1.0f, 1.0f, 1.0f}};
  REQUIRE (b1.volume() == 64);
}  

//To add: ostream<< , print,
TEST_CASE ("sphere_getter_shape","[shape_getter]")
{ 
  Sphere shapie {glm::vec3{1,1,1}, 4.0,"francine", Color{1.0f, 1.0f, 1.0f}};
  REQUIRE (shapie.getName() == "francine");
  REQUIRE (shapie.getColor().r == 1.0f);
  REQUIRE (shapie.getColor().g == 1.0f);
  REQUIRE (shapie.getColor().b == 1.0f);
}  

TEST_CASE ("box_getter_shape","[shape_getter]")
{ 
  Box boxie {glm::vec3{1,1,1}, glm::vec3{2,5,7},"francine", Color{1.0f, 1.0f, 1.0f}};
  REQUIRE (boxie.getName() == "francine");
  REQUIRE (boxie.getColor().r == 1.0f);
  REQUIRE (boxie.getColor().g == 1.0f);
  REQUIRE (boxie.getColor().b == 1.0f);
} 

TEST_CASE ("sphere_print","[print]")
{ 
  Sphere shapie {glm::vec3{1,1,1}, 4.0,"shapie", Color{1.0f, 1.0f, 1.0f}};
  std::cout << shapie;
}  

TEST_CASE ("box_print","[print]")
{ 
  Box boxie {glm::vec3{1,1,1}, glm::vec3{2,5,7},"francine", Color{1.0f, 1.0f, 1.0f}};
  std::cout << boxie;
}  // working until here



int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
