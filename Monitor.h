#ifndef MONITOR
#define MONITOR

#include <iostream>

class Monitor {
public:
    // Color mode
    enum Mode {
        UNKNOWN,
        BLACK_AND_WHITE,
        COLOR
    };

    // Default constructor
    Monitor ();

    // Copying constructor
    Monitor (Monitor & other);

    // Parameter constructor
    Monitor (const Mode mode, const unsigned int size);

    // Default destructor
    ~Monitor ();

    // Getters
    Mode getMode ();
    unsigned int getSize ();

    // Setters
    void setMode (const Mode mode);
    void setSize (const unsigned int size);

    // Operators
    bool operator>(Monitor & other);    // Compares display size
    bool operator<(Monitor & other);    // ...
    Monitor & operator= (Monitor & other);

private:
    // Color mode
    Mode mMode;

    // Display size (in inches)
    unsigned int mSize;

    // Output stream operator
    friend std::ostream& operator<< (std::ostream & out, Monitor & object);
};

#endif

