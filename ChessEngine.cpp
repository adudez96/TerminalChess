#include <string>
#include <utility>
#include <array>
#include "ChessEngine.hpp"
#include "Player.hpp"

namespace chesslib {

ChessEngine::ChessEngine() = default;

ChessEngine::ChessEngine(ChessEngine&&) = default;

ChessEngine& ChessEngine::operator=(ChessEngine&&) = default;

void ChessEngine::addBlackPlayer(Player *p) {
    this->p_black = p;
}

void ChessEngine::addWhitePlayer(Player *p) {
    this->p_white = p;
}

void ChessEngine::start() {
    std::array<std::pair<PlayerType, Player*>, 2> players = {
        std::make_pair(PLAYER_WHITE, this->p_white),
        std::make_pair(PLAYER_BLACK, this->p_black),
    };

    while (true) {
        for (const auto & player_pair : players) {
            std::string move = player_pair.second->getNextMove(
                this->board,
                player_pair.first
            );
            this->board.handleMove(player_pair.first, move);
        }
        this->board.incrementTurnCount();
    }
}

} // namespace chesslib