
#include <utility>
#include <ostream>
#include <stdexcept>
#include "Location.hpp"

namespace chesslib {

Location::Location(unsigned char f, unsigned char r): file{f}, rank{r} {
    if ((f < 'a' || f > 'h' || r < 1 || r > 8) && (f != 0 || r !=0)) {
        throw std::invalid_argument("File must be a-h, and rank must be 1-8 (or 0,0 for captured)");
    }
}

Location::Location(Location &&l): file{std::move(l.file)}, rank{std::move(l.rank)} {
    l.file = 0;
    l.rank = 0;
}

Location::Location(const Location &) = default;

Location& Location::operator=(const Location &) = default;

Location& Location::operator=(Location &&l) {
    this->file = std::move(l.file);
    this->rank = std::move(l.rank);
    l.file = 0;
    l.rank = 0;
    return *this;
}

bool Location::operator==(const Location &other) const {
    return (this->rank == other.rank) && (this->file == other.file);
}

std::ostream& operator<< (std::ostream &os, const Location &l) {
    os << l.file << static_cast<unsigned int>(l.rank);
    return os;
}

} // namespace chesslib
