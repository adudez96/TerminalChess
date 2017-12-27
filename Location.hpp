#pragma once

#include <utility>

namespace chesslib {

class Location;

class Location {
    public:
        
        Location() = delete;

        Location(unsigned char f, unsigned char r);

        Location(const Location &l);

        Location(Location &&l);

        Location& operator=(const Location &l);

        Location& operator=(Location &&l);

        bool operator==(const Location &other) const;

        friend std::ostream& operator<< (std::ostream &os, const Location &l);

        unsigned char file;
        unsigned char rank;
};

} // namespace chesslib
