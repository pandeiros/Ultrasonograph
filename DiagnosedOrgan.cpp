#include "DiagnosedOrgan.h"

// Static field initializer
std::map <DiagnosedOrgan::Organ, float> DiagnosedOrgan::mapOrganWaveRange = std::map <DiagnosedOrgan::Organ, float> ();

// Default constructor
DiagnosedOrgan::DiagnosedOrgan () {

}

// Copying constructor
DiagnosedOrgan::DiagnosedOrgan (DiagnosedOrgan & other) {

}

// Parameter constructor
DiagnosedOrgan::DiagnosedOrgan (const DiagnosedOrgan::Organ organ, const float frequency) {

}

// Default destructor
DiagnosedOrgan::~DiagnosedOrgan () {

}

// Getters
DiagnosedOrgan::Organ DiagnosedOrgan::getOrgan () {

}

float DiagnosedOrgan::getFrequency () {

}

// Setters
void DiagnosedOrgan::setOrgan (const Organ organ) {

}

void DiagnosedOrgan::setFrequency (const float frequency) {

}

// Operators
bool DiagnosedOrgan::operator>(DiagnosedOrgan & other) {

}

bool DiagnosedOrgan::operator<(DiagnosedOrgan & other) {

}

DiagnosedOrgan & DiagnosedOrgan::operator= (DiagnosedOrgan & other) {

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