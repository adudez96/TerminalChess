#pragma once

#include <string>
#include "GameBoard.hpp"
#include "ChessEngine.hpp"

namespace chesslib {

class Player;

class Player {
    public:
        virtual std::string getNextMove(GameBoard&, PlayerType) = 0;

        virtual ~Player() = default;
};

}; // namespace chesslib