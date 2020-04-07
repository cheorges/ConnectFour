#ifndef CONNECTFOUR_VIEWMANAGER_H
#define CONNECTFOUR_VIEWMANAGER_H


#include <ncurses.h>
#include "view.h"

class ViewManager : public View {
private:
    int _X, _Y;
    int cursorPosition = 0;

    void goToCurrentPosition();
    void setColor(Token token);
public:
    ViewManager() {
        initscr();
        noecho();
        getmaxyx(stdscr, _Y, _X);
        raw();
        start_color();

        init_pair(CLEAN, COLOR_WHITE, COLOR_BLACK);
        init_pair(PLAYER_1, COLOR_GREEN, COLOR_BLACK);
        init_pair(PLAYER_2, COLOR_RED, COLOR_BLACK);
    };

    void print(Field* field);
    void updateCursor(Key key);
    int getSelectedCol();
    Key getInput();
    void showWinner(Player* player);
    void cleanWinner();
    void showPlayerInfo(vector<Player>* players);
};


#endif
