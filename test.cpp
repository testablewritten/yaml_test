#include "iostream"
#include "yaml-cpp/yaml.h"
// #include "vector"
// #include <yaml-cpp/parser.h>
// #include <yaml-cpp/node/node.h>

int main(int argc, char* argv[]){

    const std::string yaml_dir = YAML_DIR + std::string("/param.yaml");

    YAML::Node param = YAML::LoadFile(yaml_dir);

    auto humanoidparam = param["humanoid"];

    auto raibert = humanoidparam["raibertGain"].as<double>();
    auto bodyheight = humanoidparam["bodyheight"].as<double>();
    auto vcGainKpKd = humanoidparam["vcGainKpKd"].as< std::vector<double> >();
    auto costGains = humanoidparam["costGains"].as< std::vector<double> >();

    double *vcGainKpKd_arr;
    double *vcGainKpKd_arr_comp;

    //mapping total vector to total array
    vcGainKpKd_arr = vcGainKpKd.data();
    //mapping componentwise
    vcGainKpKd_arr_comp = &vcGainKpKd[1];

    // Wrong way of mapping
    // auto raibert_ver2 = param["humanoid:raibertGain"].as<double>();

    std::cout <<raibert*bodyheight << std::endl;
    std::cout <<vcGainKpKd[0] << vcGainKpKd[1] << std::endl;
    std::cout <<vcGainKpKd_arr[0] << vcGainKpKd_arr[1] << std::endl;
    std::cout <<*vcGainKpKd_arr_comp << std::endl;

    std::cout <<costGains[0] << costGains[1] << costGains[2] << std::endl;


    return 0;
}