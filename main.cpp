#include "GameDatabase.hpp"

int main(int argc, char *argv[]) {
    Game *myGame = new Game("Oyunum");
    
    Entity *player = new Entity("Player123", PLAYER_ID, 0);
    Entity *gun = new Entity("AK47", MESH_ID, 1);
    
    player->include(gun);
    
    myGame->addToArray(player);
    myGame->addToArray(gun);
    return 0;
}
