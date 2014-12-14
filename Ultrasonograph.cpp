#include "Ultrasonograph.h"

// Default constructor
Ultrasonograph::Ultrasonograph () :
mMode (Ultrasonograph::UNKNOWN), hasGelHeater (false), mModelName ("Unknown model name"),
mMonitor (Monitor ()), pOrgan (new DiagnosedOrgan) {

#ifdef TESTPR
    std::cout << "Default Ultrasonograph constructor used.\n";
#endif

}

// Copying constructor
Ultrasonograph::Ultrasonograph (Ultrasonograph & other) {
    this->mMode = other.mMode;
    this->mModelName = other.mModelName;
    this->hasGelHeater = other.hasGelHeater;

    this->mMonitor = other.mMonitor;
    this->pOrgan = other.pOrgan;

#ifdef TESTPR
    std::cout << "Copying Ultrasonograph constructor used.\n";
#endif

}

// Parameter constructor
Ultrasonograph::Ultrasonograph (const Mode mode, const bool hasGelHeater, const std::string modelName,
                                Monitor monitor, DiagnosedOrgan * organ) :
                                mMode (mode), hasGelHeater (hasGelHeater), mModelName (modelName),
                                mMonitor (monitor), pOrgan (organ) {

#ifdef TESTPR
    std::cout << "Parameter Ultrasonograph constructor used.\n";
#endif

}

// Default destructor
Ultrasonograph::~Ultrasonograph () {
    delete pOrgan;

#ifdef TESTPR
    std::cout << "Drfault Ultrasonograph destructor used.\n";
#endif

}

// Getters
Ultrasonograph::Mode Ultrasonograph::getMode () {
    return mMode;
}

bool Ultrasonograph::getHasGelHeater () {
    return hasGelHeater;
}

std::string Ultrasonograph::getModelName () {
    return mModelName;
}

// Setters
void Ultrasonograph::setMode (const Ultrasonograph::Mode mode) {
    this->mMode = mode;
}

void Ultrasonograph::setHasGelHeater (const bool hasGelHeater) {
    this->hasGelHeater = hasGelHeater;
}

void Ultrasonograph::setModelName (const std::string modelName) {
    this->mModelName = modelName;
}

// Operators
bool Ultrasonograph::operator>(Ultrasonograph & other) {
    if (this->mMode > other.mMode)
        return true;
    else
        return false;
}

bool Ultrasonograph::operator<(Ultrasonograph & other) {
    if (this->mMode < other.mMode)
        return true;
    else
        return false;
}

Ultrasonograph & Ultrasonograph::operator= (Ultrasonograph & other) {
    if (this != &other) {
        this->mMode = other.mMode;
        this->mModelName = other.mModelName;
        this->hasGelHeater = other.hasGelHeater;

        this->mMonitor = other.mMonitor;
        this->pOrgan = other.pOrgan;
    }

    return *this;
}
