#ifndef CONNECTFOUR_TOKEN_H
#define CONNECTFOUR_TOKEN_H


#include "character.h"

class Token {
private:
    char character = CLEAN;

public:
    bool same(Token token) { return this->character == token.character; }

    char getCharacter() { return character; }

    static Token clean() {
        return Token();
    }

    static Token player1() {
        Token token = Token();
        token.character = PLAYER_1;
        return token;
    }

    static Token player2() {
        Token token = Token();
        token.character = PLAYER_2;
        return token;
    }
};


#endif
