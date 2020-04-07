#include "game.h"

Field* Game::getField() {
    return &field;
}

Player* Game::evaluateActivePlayer() {
    return player1.isActive() ? &player1 : &player2;

}

bool Game::addToken(int colIndex) {
    return field.addNewToken(evaluateActivePlayer()->getToken(), colIndex);

}

void Game::changeActivePlayer() {
    player1.toggleActive();
    player2.toggleActive();
}

bool Game::hasConnectedFour() {
    Player* activePlayer = evaluateActivePlayer();
    if(field.hasConnectedFour(activePlayer)) {
        activePlayer->incrementScore();
        return true;
    }
    changeActivePlayer();
    return false;
}

Player* Game::getWinner() {
    return evaluateActivePlayer();
}

vector<Player>* Game::getPlayers() {
    vector<Player>* players = new vector<Player>;
    players->push_back(player1);
    players->push_back(player2);
    return players;
}

void Game::startNewGame() {
    field.clear();
    changeActivePlayer();
}

bool Game::finish() {
    return field.hasFreeFields();
}
