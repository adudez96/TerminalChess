#pragma once

#include <map>
#include <string>
#include "Location.hpp"
#include "ChessEngine.hpp"
#include "GameBoard.hpp"

namespace chesslib {

class GameBoard {
    public:
        GameBoard();

        GameBoard(const GameBoard&);

        GameBoard(GameBoard&&);

        GameBoard& operator=(const GameBoard&);
        
        GameBoard& operator=(GameBoard&&);

        void handleMove(PlayerType, std::string &);

        inline std::size_t getTurnCount() const;

        inline void incrementTurnCount();

    private:
        std::size_t turn_count;
};

} // namespace chesslib