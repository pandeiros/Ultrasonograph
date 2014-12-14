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
    DiagnosedOrgan (const Organ organ, const float frequency);

    // Default destructor
    ~DiagnosedOrgan ();

    // Getters
    Organ getOrgan ();
    float getFrequency ();

    // Setters
    void setOrgan (const Organ organ);
    void setFrequency (const float frequency);

    // Operators
    bool operator>(DiagnosedOrgan & other);
    bool operator<(DiagnosedOrgan & other);
    DiagnosedOrgan & operator= (DiagnosedOrgan & other);

private:
    // Dedicated organ
    Organ mOrgan;

    // Ultrasound wave frequency (in Hz)
    float mFrequency;

    // Output stream operator
    friend std::ostream& operator<< (std::ostream & out, DiagnosedOrgan & object);
};

#endif

