#include "DiagnosedOrgan.h"

// Static field initializer
std::map <DiagnosedOrgan::Organ, float> DiagnosedOrgan::mapOrganWaveRange = std::map <DiagnosedOrgan::Organ, float> ();

// Default constructor
DiagnosedOrgan::DiagnosedOrgan () :
mOrgan (DiagnosedOrgan::UNKNOWN), mFrequency (DiagnosedOrgan::UNKNOWN) {

#ifdef TESTPR
    std::cout << "Default DiagnosedOrgan constructor used.\n";
#endif

}

// Copying constructor
DiagnosedOrgan::DiagnosedOrgan (DiagnosedOrgan & other) {
    this->mOrgan = other.mOrgan;
    this->mFrequency = mapOrganWaveRange[mOrgan];

#ifdef TESTPR
    std::cout << "Copying DiagnosedOrgan constructor used.\n";
#endif

}

// Parameter constructor
DiagnosedOrgan::DiagnosedOrgan (const DiagnosedOrgan::Organ organ) : 
 mOrgan (organ), mFrequency (mapOrganWaveRange[mOrgan]){

#ifdef TESTPR
    std::cout << "Parameter DiagnosedOrgan constructor used.\n";
#endif

}

// Default destructor
DiagnosedOrgan::~DiagnosedOrgan () {

#ifdef TESTPR
    std::cout << "Default DiagnosedOrgan destructor used.\n";
#endif

}

// Getters
DiagnosedOrgan::Organ DiagnosedOrgan::getOrgan () {
    return mOrgan;
}

float DiagnosedOrgan::getFrequency () {
    return mFrequency;
}

// Setters
void DiagnosedOrgan::setOrgan (const Organ organ) {
    this->mOrgan = organ;
    this->mFrequency = mapOrganWaveRange[mOrgan];
}


// Operators
bool DiagnosedOrgan::operator>(DiagnosedOrgan & other) {
    if (this->mFrequency > other.mFrequency)
        return true;
    else
        return false;
}

bool DiagnosedOrgan::operator<(DiagnosedOrgan & other) {
    if (this->mFrequency < other.mFrequency)
        return true;
    else
        return false;
}

DiagnosedOrgan & DiagnosedOrgan::operator= (DiagnosedOrgan & other) {
    if (this != &other) {
        this->mOrgan = other.mOrgan;
        this->mFrequency = other.mFrequency;
    }

    return *this;
}

// Maps all organs to their specific wave frequency
void DiagnosedOrgan::configureOrganWaveRange () {
    mapOrganWaveRange[Organ::BRAIN] = 1.5f;
    mapOrganWaveRange[Organ::HEART] = 2.5f;
    mapOrganWaveRange[Organ::LIVER] = 3.5f;
    mapOrganWaveRange[Organ::KIDNEY] = 5.f;
    mapOrganWaveRange[Organ::PANCREAS] = 6.f;
    mapOrganWaveRange[Organ::INTESTINE] = 15.f;
    mapOrganWaveRange[Organ::SKIN] = 20.f;
    mapOrganWaveRange[Organ::TESTICLE] = 10.f;
    mapOrganWaveRange[Organ::EYE] = 10.f;

    mapOrganWaveRange[Organ::UNKNOWN] = 0.f;
}