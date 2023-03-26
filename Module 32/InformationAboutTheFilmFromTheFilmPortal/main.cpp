#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "nlohmann/json.hpp"

struct ACTOR {
    // имя актера
    std::vector <std::string> nameActor = {"Jean Renaud", "Ryoko Hirosue",
        "Michel Muller", "Yoshi Oida", "Carole Bouquet",
        "Christian Sinniger"};
    // исполнение роли
    std::vector <std::string> role = {"Hubert Fiorentini", "Yumi Yoshimido",
        "Maurice «Momo»", "Takanawa","Sofia","Le Squale"};
};

struct FILM {
    std::string nameFilm = "Wasabi"; // имя киноленты
    std::string country = "France, Japan"; // страна производства
    std::string dateCreation = "2001 year"; // дата киноленты
    std::string studio = "EuropaCorp"; // студия
    std::string authorScript = "Luc Besson"; //  автор сценария
    std::string director = "Luc Besson"; // режисер
    std::string producer = "Gerard Kravchik"; // продюсер
    ACTOR actor ;
};

int main() {
    FILM film;
    std::ofstream file ("record.json");
    if (file.is_open()) {
        nlohmann::json dir;
        nlohmann::json actorArr;
        for (int i = 0; i < film.actor.nameActor.size(); i++) {
            actorArr[i]["name"] = film.actor.nameActor[i];
            actorArr[i]["role"] = film.actor.role[i];
        }
        file << actorArr;

        dir["name film"] = film.nameFilm;
        dir["country"] = film.country;
        dir["date creation"] = film.dateCreation;
        dir["studio"] = film.studio;
        dir["author script"] = film.authorScript;
        dir["director"] = film.director;
        dir["producer"] = film.producer;

        file << dir;
        std::cout << "The file was created successfully" << std::endl;
    } else {
        std::cout << "File closed!" << std::endl;
    }
    file.close();
    return 0;
}
