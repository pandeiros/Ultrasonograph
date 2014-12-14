#include <iostream>
#include "Ultrasonograph.h"
#include "Monitor.h"
#include "DiagnosedOrgan.h"

int main (int argc, char *argv[]) {
    // Configure mapping
    DiagnosedOrgan::configureOrganWaveRange ();

    // Create objects
    std::cout << ">>> Creating Monitors:\n";
    Monitor monitorDefault;
    Monitor monitorParam (Monitor::COLOR, 19);
    Monitor monitorCopy (monitorParam);

    std::cout << "\n>>> Creating Organs:\n";
    DiagnosedOrgan organDefault;
    DiagnosedOrgan organParam (DiagnosedOrgan::BRAIN);
    DiagnosedOrgan organCopy (organParam);

    std::cout << "\n>>> Creating Ultrasonographs:\n";
    Ultrasonograph usDefault;
    Ultrasonograph usParam (Ultrasonograph::_2D, true, std::string ("Samsung Medison MySono U6"),
                            monitorParam, &organParam);
    Ultrasonograph usCopy (usParam);

    std::cout << "\n\n";

    // Print initial objects state
    std::cout << "=== Initial state ===\nUltrasonographs count: " << Ultrasonograph::getObjectCount () << std::endl;
    std::cout << usDefault << usParam << usCopy;
    std::cout << monitorDefault << monitorParam << monitorCopy;
    std::cout << organDefault << organParam << organCopy;

    // Do some modifications to default objects
    std::cout << "\n\n>>> Changing default object's parameters....\n";
    monitorDefault.setSize (25);
    organDefault.setOrgan (DiagnosedOrgan::TESTICLE);
    usDefault.setMode (Ultrasonograph::_4D);
    usDefault.setHasGelHeater (true);
    usDefault.setModelName ("Samsung Medison Accuvix A30");

    // Print info about default objects
    std::cout << "\n\n=== Printing default object's information ===\n";
    std::cout << usDefault << monitorDefault << organDefault;

    // Doing some comparisons
    std::cout << "\n\n=== Doing some comparisons ===\n";

    std::cout << "Comparing default ultrasonograph with parameter one:\n";
    if (usDefault < usParam)
        std::cout << "   Default Ultrasonograph < Parameter Ultrasonograph\n\n";
    else if (usDefault > usParam)
        std::cout << "   Default Ultrasonograph > Parameter Ultrasonograph\n\n";
    else
        std::cout << "   Default Ultrasonograph == Parameter Ultrasonograph\n\n";

    std::cout << "Comparing parameter monitor with copied one:\n";
    if (monitorParam < monitorCopy)
        std::cout << "   Parameter Monitor < Copied Monitor\n\n";
    else if (monitorParam > monitorCopy)
        std::cout << "   Parameter Monitor > Copied Monitor\n\n";
    else
        std::cout << "   Parameter Monitor == Copied Monitor\n\n";

    std::cout << "Comparing copied organ with default one:\n";
    if (organCopy < organDefault)
        std::cout << "   Copied Organ < Default Organ\n\n";
    else if (organCopy > organDefault)
        std::cout << "   Copied Organ > Default Organ\n\n";
    else
        std::cout << "   Copied Organ == Default Organ\n\n";


    // Doing some assigments
    std::cout << "\n\n=== Doing some assignments ===";

    std::cout << "\n > Assigning copied Ultrasonograph to a new one:\n";
    Ultrasonograph usAssign;
    usAssign = usCopy;

    std::cout << "\n > Assigning param Monitor to a new one:\n";
    Monitor monitorAssign;
    monitorAssign = monitorParam;

    std::cout << "\n > Assigning default Organ to a new one:\n";
    DiagnosedOrgan organAssign;
    organAssign = organDefault;

    // Print current objects state
    std::cout << "\n\n=== Current state ===\nUltrasonographs count: " << Ultrasonograph::getObjectCount () << std::endl;
    std::cout << usDefault << usParam << usCopy << usAssign;
    std::cout << monitorDefault << monitorParam << monitorCopy << monitorAssign;
    std::cout << organDefault << organParam << organCopy << organAssign;

    // Dynamic allocation
    std::cout << "\n\n=== Creating some dynamic objects: ===";

    std::cout << "\n > Dynamic Ultrasonograph based on a parameter one:\n";
    Ultrasonograph * pUS = new Ultrasonograph (usParam);

    std::cout << "\n > Dynamic Monitor based on an assign one:\n";
    Monitor * pM = new Monitor (monitorAssign);

    std::cout << "\n > Dynamic DiagnosedOrgan based on a copied one:\n";
    DiagnosedOrgan * pO = new DiagnosedOrgan (organCopy);

    // Print all again
    std::cout << "\n\n=== Dynamic objects ===\nUltrasonographs count: " << Ultrasonograph::getObjectCount () << std::endl;
    std::cout << *pUS << *pM << *pO;
    
    //Free memory
    std::cout << "\n\n=== Free dynamically allocated memory : ===\n";
    delete pO;
    delete pM;
    delete pUS;

    // Print final objects state
    std::cout << "\n\n=== FINAL state ===\nUltrasonographs count: " << Ultrasonograph::getObjectCount () << std::endl;
    std::cout << usDefault << usParam << usCopy << usAssign;
    std::cout << monitorDefault << monitorParam << monitorCopy << monitorAssign;
    std::cout << organDefault << organParam << organCopy << organAssign;

    // All done.
    std::cout << "\n\n >>> Everything's done. Press Return to exit...";
    std::cin.get ();

    return 0;
}