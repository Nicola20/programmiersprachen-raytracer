#ifndef MATERIAL_HPP
#define MATERIAL_HPP

#include "color.hpp"
#include <string>

struct Material {

Material():
    name_{"DefaultMaterial"},
    ks_{0.0f, 0.0f, 0.0f},
    kd_{0.0f, 0.0f, 0.0f},
    ka_{0.0f, 0.0f, 0.0f},
    m_{1.0f} {}

Material (std::string name, Color ks, Color kd, Color ka, float m):
    name_{name},
    ks_{ks},
    kd_{kd},
    ka_{ka},
    m_{m} {}

 friend std::ostream& operator<<(std::ostream& os, Material const& m){
    os << "Material: " << m.name_ << 
        "Ka: " << m.ka_ << 
        "Kd: " << m.kd_ << 
        "Ks: " << m.ks_ << 
        "Spekularreflexionsexponent: " << m.m_ << "\n";
    return os;
}

    

std::string name_;
Color ks_;
Color kd_;
Color ka_;
float m_;

};
#endif