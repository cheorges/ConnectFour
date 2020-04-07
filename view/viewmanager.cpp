#include "viewmanager.h"

void ViewManager::goToCurrentPosition() {
    move(6,cursorPosition * 2);
}

void ViewManager::print(Field* field) {
    for (auto row = 0; row < ROW_COUNT; row++) {
        vector<Token>* tokenRow = field->getRow(row);
        int col = 0;
        for (auto token = tokenRow->begin(); token != tokenRow->end(); token++) {
            setColor(*token);
            mvprintw(row, col * 2, "%c", (*token).getCharacter());
            mvprintw(row, col * 2 + 1, " ");
            col++;
        }
    }
    setColor(Token::clean());
    mvprintw(7, 0, "1 2 3 4 5 6 7");

    goToCurrentPosition();
    refresh();
}

void ViewManager::updateCursor(Key key) {
    if (key == RIGHT && cursorPosition < 6) {
        cursorPosition++;
    } else if (key == LEFT && cursorPosition > 0) {
        cursorPosition--;
    }
    goToCurrentPosition();
}

int ViewManager::getSelectedCol() {
    return cursorPosition;
}

void ViewManager::setColor(Token token) {
    if (Token::player1().same(token)) {
        attrset(A_BOLD | COLOR_PAIR(PLAYER_1));
    } else if (Token::player2().same(token)) {
        attrset(A_BOLD | COLOR_PAIR(PLAYER_2));
    } else {
        attrset(COLOR_PAIR(CLEAN));
    }
}

Key ViewManager::getInput() {
    char key = getch();
    return static_cast<Key>(key);
}

void ViewManager::showWinner(Player *player) {
    if (player == nullptr) {
        mvprintw(9, 0, "No Winner - Tie!");
    } else {
        mvprintw(9, 0, "Winner is ");
        setColor(player->getToken());
        mvprintw(9, 10, "Player %c", player->getToken().getCharacter());
        setColor(Token::clean());
        goToCurrentPosition();
    }
}

void ViewManager::cleanWinner() {
    mvprintw(9, 0, "                   ");
}

void ViewManager::showPlayerInfo(vector<Player>* players) {
    int playerCol = 2;
    for (auto & player : *players) {
        if (player.isActive()) {
            mvprintw(0, 14, "Current Player: ");
            setColor(player.getToken());
            mvprintw(0, 30, "%c", player.getToken().getCharacter());
            setColor(Token::clean());
        }
        setColor(player.getToken());
        mvprintw(playerCol, 14, "Player %c: %i", player.getToken(), player.getScore());
        setColor(Token::clean());
        playerCol++;
    }
    goToCurrentPosition();
}
