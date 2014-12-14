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
Ultrasonograph::Ultrasonograph (const Ultrasonograph & other) {
    this->mMode = other.mMode;
    this->mModelName = other.mModelName;
    this->hasGelHeater = other.hasGelHeater;

    this->mMonitor = other.mMonitor;
    this->pOrgan = other.pOrgan;
}

// Parameter constructor
Ultrasonograph::Ultrasonograph (const Mode mode, const std::string modelName, Monitor monitor, DiagnosedOrgan * organ = nullptr) {

}

// Default destructor
Ultrasonograph::~Ultrasonograph () {

}

// Getters
Ultrasonograph::Mode Ultrasonograph::getMode () {

}

bool Ultrasonograph::getHasGelHeater () {

}

std::string Ultrasonograph::getModelName () {

}

// Setters
void Ultrasonograph::setMode (const Ultrasonograph::Mode mode) {

}

void Ultrasonograph::setHasGelHeater (const bool hasGelHeater) {

}

void Ultrasonograph::setModelName (const std::string modelName) {

}

// Operators
bool Ultrasonograph::operator>(Ultrasonograph & other) {

}

bool Ultrasonograph::operator<(Ultrasonograph & other) {

}

Ultrasonograph & Ultrasonograph::operator= (Ultrasonograph & other) {

}
