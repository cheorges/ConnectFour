#include "field.h"

void Field::clear() {
    countToken = 0;
    for(auto col = 0; col < COL_COUNT; col++) {
        for(auto row = 0; row < ROW_COUNT; row++) {
            fields[row][col] = Token::clean();
        }
    }
}

vector<Token>* Field::getRow(int rowIndex) {
    vector<Token>* token = new vector<Token>;
    try {
        for (auto col = 0; col < COL_COUNT; col++) {
            token->push_back(fields[rowIndex][col]);
        }
    } catch (out_of_range) {
        throw invalid_argument("invalid row count");
    }
    return token;
}

bool Field::addNewToken(Token token, int colIndex) {
    for (auto row = ROW_COUNT; row >= 0; row--) {
        if (Token::clean().same(fields[row][colIndex])) {
            countToken++;
            fields[row][colIndex] = token;
            return true;
        }
    }
    return false;
}

bool Field::hasConnectedFour(Player *player) {
    Token currentToken;
    for(int col = 0; col < COL_COUNT; col++) {
        for (int row = ROW_COUNT - 1; row > ROW_COUNT - 4; row--) {
            if (player->getToken().same(fields[row][col])) {
                currentToken = fields[row][col];
                if (currentToken.same(fields[row][col - 1])
                    && currentToken.same(fields[row][col - 2])
                    && currentToken.same(fields[row][col - 3])) {
                    return true;
                }
            }
        }
    }
    for(int col = 0; col < COL_COUNT - 3; col++) {
        for (int row = 0; row < ROW_COUNT; row++) {
            if (player->getToken().same(fields[row][col])) {
                currentToken = fields[row][col];
                if (currentToken.same(fields[row + 1][col])
                    && currentToken.same(fields[row + 2][col])
                    && currentToken.same(fields[row + 3][col])) {
                    return true;
                }
            }
        }
    }
    for(int col = 0; col < COL_COUNT - 3; col++) {
        for(int row = ROW_COUNT; row > ROW_COUNT - 4; row--) {
            if(player->getToken().same(fields[row][col])) {
                currentToken = fields[row][col];
                if(currentToken.same(fields[row - 1][col + 1])
                        && currentToken.same(fields[row - 2][col + 2])
                        && currentToken.same(fields[row - 3][col + 3])) {
                    return true;
                }
            }
        }
    }
    for(int col = 0; col < COL_COUNT - 3; col++) {
        for (int row = 0; row < ROW_COUNT - 3; row++) {
            if (player->getToken().same(fields[col][row])) {
                currentToken = fields[col][row];
                if (currentToken.same(fields[col + 1][row + 1])
                    && currentToken.same(fields[col + 2][row + 2])
                    && currentToken.same(fields[col + 3][row + 3])) {
                    return true;
                }
            }
        }
    }
    return false;
}