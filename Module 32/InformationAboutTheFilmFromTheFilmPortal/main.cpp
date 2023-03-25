#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "nlohmann/json.hpp"

struct ACTOR {
    std::string nameActor = "Name";
    std::string role;
};

struct FILM {
    std::string country;
    std::string dateCreation;
    std::string studio = "Test";
    std::string authorScript;
    std::string director;
    std::string producer;
    ACTOR actor;
};

int main() {
    FILM film;
    std::ofstream file ("record.json");
    nlohmann::json dir {
            {"name" , film.studio},
            {"actor" , film.actor.nameActor}
    };
    file << dir;
    return 0;
}
