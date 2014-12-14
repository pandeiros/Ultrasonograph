#ifndef ULTRASONOGRAPH
#define ULTRASONOGRAPH

#include <iostream>
#include <string>
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

    // Object instance counter and getter
    static unsigned long ObjectCount;
    static unsigned long getObjectCount () {
        return ObjectCount;
    };

    // Default constructor
    Ultrasonograph ();

    // Copying constructor
    Ultrasonograph (Ultrasonograph & other);
    
    // Parameter constructor
    Ultrasonograph (const Mode mode, const bool hasGelHeater, const std::string modelName, 
                    Monitor & monitor, DiagnosedOrgan * organ = nullptr);

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
    bool operator>(Ultrasonograph & other);     // Compares display modes
    bool operator<(Ultrasonograph & other);     // ...
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
    friend std::ostream & operator<< (std::ostream & out, Ultrasonograph & object) {
        out << "Ultrasonograph : ";
        out << object.getModelName();
        out << ", ";

        switch (object.mMode) {
            case Ultrasonograph::_2D : 
                out << "2D"; break;
            case Ultrasonograph::_3D :
                out << "3D"; break;
            case Ultrasonograph::_4D :
                out << "4D"; break;
            default :
                out << "unknown"; break;
        }

        out << " mode";

        if (object.hasGelHeater)            
           out << " (Gel heater included)";

        out << std::endl;
        //out << object.mMonitor << *object.pOrgan;
          
        return out;
    }
};

#endif
