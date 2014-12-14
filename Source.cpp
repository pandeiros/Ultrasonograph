#include <iostream>
#include "Ultrasonograph.h"
#include "Monitor.h"
#include "DiagnosedOrgan.h"

int main (int argc, char *argv[]) {
    // Configure mapping
    DiagnosedOrgan::configureOrganWaveRange ();

    Monitor monitorDefault;
    Monitor monitorParam (Monitor::COLOR, 19);
    Monitor monitorCopy (monitorParam);

    DiagnosedOrgan organDefault;
    DiagnosedOrgan organParam (DiagnosedOrgan::BRAIN);
    DiagnosedOrgan organCopy (organParam);

    Ultrasonograph usDefault;
    Ultrasonograph usParam (Ultrasonograph::_2D, true, std::string ("Samsung Medison MySono U6"),
                        monitorParam, &organParam);
    Ultrasonograph usCopy (usParam);
    std::cout << usParam;

    std::cin.get ();
    return 0;
}