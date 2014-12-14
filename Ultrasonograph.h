#ifndef ULTRASONOGRAPH
#define ULTRASONOGRAPH

#include <iostream>
#include "Monitor.h"
#include "DiagnosedOrgan.h"

class Ultrasonograph {
public:
    // Working modes
    enum Mode {
        UNKNOWN,
        _2D,
        _3D,
        _4D
    };

    // Default constructor
    Ultrasonograph ();

    // Copying constructor
    Ultrasonograph (const Ultrasonograph & other);
    
    // Parameter constructor
    Ultrasonograph (const Mode mode, const std::string modelName, Monitor monitor, DiagnosedOrgan * organ = nullptr);

    // Default destructor
    ~Ultrasonograph ();

    // Getters
    Mode getMode ();
    bool getHasGelHeater ();
    std::string getModelName ();

    // Setters
    void setMode (const Mode mode);
    void setHasGelHeater (const bool hasGelHeater);
    void setModelName (const std::string modelName);

    // Operators
    bool operator>(Ultrasonograph & other);
    bool operator<(Ultrasonograph & other);
    Ultrasonograph & operator= (Ultrasonograph & other);

private:
    // Current working mode
    Mode mMode;

    // Whether has gel heater or not
    bool hasGelHeater;

    // Ultrasonograph model name
    std::string mModelName;

    // Associated objects
    Monitor mMonitor;
    DiagnosedOrgan * pOrgan;

    // Output stream operator
    friend std::ostream& operator<< (std::ostream & out, Ultrasonograph & object);
};

#endif
