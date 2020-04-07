#ifndef CONNECTFOUR_GAME_H
#define CONNECTFOUR_GAME_H


#include <vector>

#include "../object/field.h"
#include "../object/player.h"
#include "controller/gamestate.h"

class Game {
private:
    Field field;
    Player player1;
    Player player2;

    Player* evaluateActivePlayer();
    void changeActivePlayer();

public:
    Game() : field(Field()),
             player1(Player(Token::player1(), true)),
             player2(Player(Token::player2(), false)) {}

    bool addToken(int colIndex);
    Field* getField();
    bool hasConnectedFour();
    Player* getWinner();
    vector<Player>* getPlayers();
    void startNewGame();
    bool finish();
};


#endif
