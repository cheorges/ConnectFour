#include "gameengine.h"

void GameEngine::init() {
    while (gameState != QUIT) {
        while (gameState == RUNNING) {
            view->cleanWinner();
            running();
        }
        while (gameState == FINISH) {
            finish();
        }
    }
}

void GameEngine::running() {
    view->print(game->getField());
    view->showPlayerInfo(game->getPlayers());

    Key key = view->getInput();
    switch (key) {
        case LEFT:
        case RIGHT:
            view->updateCursor(key);
            break;
        case Q:
            gameState = QUIT;
            break;
        case ENTER:
            if (game->addToken(view->getSelectedCol())) {
                if (game->hasConnectedFour()) {
                    view->showWinner(game->getWinner());
                    gameState = FINISH;
                }
                if (!game->finish()) {
                    view->showWinner(nullptr);
                    gameState = FINISH;
                }
            }
            break;
        default:
            break;
    }
}

void GameEngine::finish() {
    view->print(game->getField());
    view->showPlayerInfo(game->getPlayers());

    Key key = view->getInput();
    switch (key) {
        case Q:
            gameState = QUIT;
            break;
        case y:
        case Y:
            game->startNewGame();
            gameState = RUNNING;
            break;
        default:
            break;
    }
}