#ifndef CONNECTFOUR_FIELD_H
#define CONNECTFOUR_FIELD_H


#define COL_COUNT 7
#define ROW_COUNT 6

#include <string>
#include <vector>
#include <stdexcept>
#include "token.h"
#include "player.h"

using namespace std;

class Field {
private:
    Token fields[ROW_COUNT][COL_COUNT] = {};
    int countToken;

public:
    Field() : countToken(0) {};

    void clear();
    bool addNewToken(Token token, int colIndex);
    vector<Token>* getRow(int rowIndex);
    bool hasConnectedFour(Player *player);
    bool hasFreeFields() { return countToken != 42; }
};


#endif
