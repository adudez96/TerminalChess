
#include <utility>
#include <ostream>
#include "Location.hpp"

namespace chesslib {

Location::Location(unsigned char f, unsigned char r): file{f}, rank{r} {}

Location::Location(Location &&l): file{std::move(l.file)}, rank{std::move(l.rank)} {
    l.file = 0;
    l.rank = 0;
}

Location::Location(const Location &l) = default;

Location& Location::operator=(const Location &l) = default;

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
    return os << l.file << static_cast<unsigned int>(l.rank);
}

} // namespace chesslib
