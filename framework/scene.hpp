#ifndef SCENE_HPP
#define SCENE_HPP

#include "shape.hpp"
#include <ifstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

struct Scene {


};
 std::vector SDFFileLoader(std::string const& fileIn) const {  //Frage: wie genau increase ich die linien und lese von genau dieser Linie etwas?

     std::ifstream file;
     std::string line;
     file.open(fileIn);
     std::vector<std::shared_ptr<Material>> vec;

     if (file.is_open()){
            while(std::getline(file,line)){     //while file has lines
            std::stringstream ss;
            std::string keyword;

            ss<<line;               //add stringobject first line
            ss>>keyword;            //read ffirst word

            if(keyword == "define"){
                ss>>keyword;        //read next word

                if(keyword == "material"){

                    Material mat;

                    ss>>mat.name_;

                    ss>> mat.ka_.r;
                    ss>> mat.ka_.g;
                    ss>> mat.ka_.b;
                    ss>> mat.kd_.r;
                    ss>> mat.kd_.g;
                    ss>> mat.kd_.b;
                    ss>> mat.ks_.r;
                    ss>> mat.ks_.g;
                    ss>> mat.ks_.b;

                    ss>> mat.m_;
                    std::make_shared<Material> (mat);
                    vec.push_back(std::move();
                }

                if(keyword == "shape"){
                    //ss<<line;     
                    ss>>keyword;
                    if(keyword == "box"){
                        std::string bname;
                        glm::vec3 bmin;
                        glm::vec3 bmax;
                        Material mat;
                        ss>> bname;
                        ss>> bmin.x;
                        ss>> bmin.y;
                        ss>> bmin.z;
                        ss>> bmax.x;
                        ss>> bmax.y;
                        ss>> bmax.z;
                        ss>>mat;
                        Box b {bmin, bmax, bname, mat};
                    }
                    if(keyword == "sphere"){
                        std::string sname;
                        glm::vec3 scenter;
                        float sradius;
                        Material mat;
                        ss>> sname;
                        ss>> scenter.x; 
                        ss>> scenter.y; 
                        ss>> scenter.z;
                        ss>> sradius;
                        ss>> mat;
                        Sphere s {scenter, sradius, sname, mat}; 
                    }
                    
                }
            }
        file.close(); 
       }
     }
     return vec;

 }
#endif

