#ifndef __LOCATION_H
#define __LOCATION_H

class Location {
private:
    unsigned int _rank;
    unsigned int _file;

public:
    Location() = default;
    Location(const unsigned int rank, const unsigned int file) :
            _rank(rank), _file(file) {  }

    virtual ~Location() = default;

    inline unsigned int rank() const { return _rank; }
    inline unsigned int file() const { return _file; }
};

#endif
