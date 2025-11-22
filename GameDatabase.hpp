#ifndef GAMEDATABASE_HPP
#define GAMEDATABASE_HPP
#include <iostream>
#include <array>

#define IncludeArray std::array<Entity *, 2048>

enum EntityType {
    PLAYER_ID = 0,
    MESH_ID = 1
};

class Entity {
private:
    std::string name;
    int IndexN;
    bool isPlayer;
    IncludeArray includeArray;
    int includeCount = 0;
    EntityType type;
public:
    Entity(std::string name, EntityType type, int IndexN) : name(std::move(name)), type(type), IndexN(IndexN) {}
    std::string getName() const {
        return name;
    }
    EntityType getID() const {
        return type;
    }
    int getIndexN() const {
        return IndexN;
    }
    void include(Entity *entity) {
        if (includeCount < includeArray.size()) {
            includeArray[includeCount++] = entity;
        }
    }
    IncludeArray getIncludeArray() const {
        return includeArray;
    }
    void debug() {
        std::cout << "[Debug Log] Debug log for " << name << ": Type -> " << type << "; IndexN -> " << IndexN << std::endl;
    }
    void debugFor(Entity *entity) {
        std::cout << "[Debug Log] Debug log for " << entity->name << ": Type -> " << entity->type << "; IndexN -> " << entity->IndexN << std::endl;
    }
};


class Game {
private:
    std::string name;
    IncludeArray array;
    int includeCount = 0;
public:
    Game(std::string name) : name(std::move(name)) {};
    void addToArray(Entity * entity) {
        if (includeCount < array.size()) {
            array[includeCount++] = entity;
        }
    }
    std::string getName() const {
        return name;
    }
    std::array<Entity *, 2048> getArray() const {
        return array;
    }
};


#endif
