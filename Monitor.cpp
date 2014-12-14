#include "Monitor.h"

// Default constructor
Monitor::Monitor () :
mMode (Monitor::UNKNOWN), mSize (0) {

#ifdef TESTPR
    std::cout << "Default Monitor constructor used.\n";
#endif

}

// Copying constructor
Monitor::Monitor (Monitor & other) {
    this->mMode = other.mMode;
    this->mSize = other.mSize;

#ifdef TESTPR
    std::cout << "Copying Monitor constructor used.\n";
#endif

}

// Parameter constructor
Monitor::Monitor (const Mode mode, const unsigned int size) :
mMode (mode), mSize (size) {

#ifdef TESTPR
    std::cout << "Parameter Monitor constructor used.\n";
#endif

}

// Default destructor
Monitor::~Monitor () {

#ifdef TESTPR
    std::cout << "Default Monitor destructor used.\n";
#endif

}

// Getters
Monitor::Mode Monitor::getMode () {
    return mMode;
}

unsigned int Monitor::getSize () {
    return mSize;
}

// Setters
void Monitor::setMode (const Monitor::Mode mode) {
    this->mMode = mode;
}

void Monitor::setSize (const unsigned int size) {
    this->mSize = size;
}

// Operators
bool Monitor::operator>(Monitor & other) {
    if (this->mMode > other.mMode)
        return true;
    else
        return false;
}

bool Monitor::operator<(Monitor & other) {
    if (this->mMode < other.mMode)
        return true;
    else
        return false;
}

Monitor & Monitor::operator= (Monitor & other) {
    if (this != &other) {
        this->mMode = other.mMode;
        this->mSize = other.mSize;
    }

#ifdef TESTPR
    std::cout << "Monitor = Monitor (operator= used)\n";
#endif

    return *this;
}