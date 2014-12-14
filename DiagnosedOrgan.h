#ifndef DIAGNOSED_ORGAN
#define DIAGNOSED_ORGAN

#include <map>
#include <iostream>

class DiagnosedOrgan {
public:
    // Available organs
    enum Organ {
        UNKNOWN,
        HEART,
        BRAIN,
        LIVER,
        KIDNEY,
        PANCREAS,
        INTESTINE,
        SKIN,
        TESTICLE,
        EYE,
    };

    // Organ-wave mapping
    static std::map <DiagnosedOrgan::Organ, float> mapOrganWaveRange;

    // Maps all organs to their specific wave frequency
    static void configureOrganWaveRange ();

    // Default constructor
    DiagnosedOrgan ();

    // Copying constructor
    DiagnosedOrgan (DiagnosedOrgan & other);

    // Parameter constructor
    DiagnosedOrgan (const Organ organ);

    // Default destructor
    ~DiagnosedOrgan ();

    // Getters
    Organ getOrgan ();
    float getFrequency ();

    // Setters
    void setOrgan (const Organ organ);

    // Operators
    bool operator>(DiagnosedOrgan & other);     // Compares frequencies
    bool operator<(DiagnosedOrgan & other);     // ...
    DiagnosedOrgan & operator= (DiagnosedOrgan & other);

private:
    // Dedicated organ
    Organ mOrgan;

    // Ultrasound wave frequency (in Hz)
    // (can be only set via setOrgan() method)
    float mFrequency;

    // Output stream operator
    friend std::ostream& operator<< (std::ostream & out, DiagnosedOrgan & object) {
        out << "Organ : ";

        switch (object.mOrgan) {
            case DiagnosedOrgan::HEART :
                out << "heart, "; break;
            case DiagnosedOrgan::BRAIN :
                out << "brain, "; break;
            case DiagnosedOrgan::EYE :
                out << "eye, "; break;
            case DiagnosedOrgan::INTESTINE :
                out << "intestine, "; break;
            case DiagnosedOrgan::KIDNEY :
                out << "kidney, "; break;
            case DiagnosedOrgan::LIVER :
                out << "liver, "; break;
            case DiagnosedOrgan::PANCREAS :
                out << "pancreas, "; break;
            case DiagnosedOrgan::SKIN :
                out << "skin, "; break;
            case DiagnosedOrgan::TESTICLE :
                out << "testicle, "; break;
            default:
                out << "unknown, "; break;
        }

        out << "diagnosed with " << object.mFrequency << " Hz wave.\n";
        return out;
    }
};

#endif

