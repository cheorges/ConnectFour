#ifndef CONNECTFOUR_PLAYER_H
#define CONNECTFOUR_PLAYER_H

#include "token.h"

class Player {
private:
    Token token;
    bool active;
    int score;

public:
    Player(Token token, bool active) : token(token), active(active), score(0) {};

    Token getToken() { return token; }
    bool isActive() { return active; }
    void toggleActive() { active = !active; };
    void incrementScore() { score++; }
    int getScore() { return score; }
};

#endif
