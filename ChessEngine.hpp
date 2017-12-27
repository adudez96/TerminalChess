#pragma once

#include "GameBoard.hpp"
#include "Player.hpp"

namespace chesslib {

class ChessEngine;

class ChessEngine {
    public:
        ChessEngine();

        ChessEngine(const ChessEngine&) = delete;
    
        ChessEngine(ChessEngine&&);

        ChessEngine& operator=(const ChessEngine&) = delete;

        ChessEngine& operator=(ChessEngine&&);

        void addWhitePlayer(Player *p);

        void addBlackPlayer(Player *p);

        void start();

    private:
        GameBoard board;
        Player* p_black;
        Player* p_white;
};

enum PlayerType {
    PLAYER_WHITE, PLAYER_BLACK
};


}; // namespace chesslib