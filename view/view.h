#ifndef CONNECTFOUR_VIEW_H
#define CONNECTFOUR_VIEW_H


#include <vector>

#include "../object/key.h"
#include "../object/field.h"
#include "../object/player.h"

class View {
public:
    virtual void print(Field* field) = 0;
    virtual void updateCursor(Key key) = 0;
    virtual int getSelectedCol() = 0;
    virtual Key getInput() = 0;
    virtual void showWinner(Player* player) = 0;
    virtual void cleanWinner() = 0;
    virtual void showPlayerInfo(vector<Player>* players) = 0;
};

#endif
