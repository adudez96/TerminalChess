#include <string>
#include <stdexcept>
#include "GameBoard.hpp"

namespace chesslib {

GameBoard::GameBoard() = default;

GameBoard::GameBoard(const GameBoard&) = default;

GameBoard::GameBoard(GameBoard &&) = default;

GameBoard& GameBoard::operator=(const GameBoard &) = default;

GameBoard& GameBoard::operator=(GameBoard &&) = default;

void GameBoard::handleMove(PlayerType, std::string &) {
    throw std::exception("Not Implemented");
}

inline std::size_t GameBoard::getTurnCount() const {
    return this->turn_count;
}

inline void GameBoard::incrementTurnCount() {
    ++this->turn_count;
}

} // namespace chesslib