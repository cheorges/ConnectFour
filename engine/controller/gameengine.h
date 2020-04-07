#ifndef CONNECTFOUR_GAMEENGINE_H
#define CONNECTFOUR_GAMEENGINE_H


#include "../../view/viewmanager.h"
#include "../game.h"

class GameEngine {
private:
    View* view;
    Game* game;
    GameState gameState = RUNNING;

    void running();
    void finish();
public:
    GameEngine(View* view) : view(view), game(new Game()) {};

    void init();
};


#endif
