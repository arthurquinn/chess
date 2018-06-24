#ifndef __LOCATION_H
#define __LOCATION_H

class Location {
private:
    int _rank;
    int _file;

public:
    Location() = default;
    Location(const unsigned int rank, const unsigned int file) :
            _rank(rank), _file(file) {  }

    virtual ~Location() = default;

    inline unsigned int rank() const { return _rank; }
    inline unsigned int file() const { return _file; }

    bool operator==(const Location& other) const { return _rank == other._rank && _file == other._file; }
};

#endif
