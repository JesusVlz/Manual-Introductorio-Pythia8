//Simulación: Colisión pp 

#include "Pythia8/Pythia.h"
#include "Pythia8Plugins/HepMC2.h"

using namespace Pythia8;

int main() {     

    // Interface for conversion from Pythia8::Event to HepMC event.
    HepMC::Pythia8ToHepMC ToHepMC;

    // Specify file where HepMC events will be stored.
    HepMC::IO_GenEvent ascii_io("pp_to_ttbarhadronic.hepmc", std::ios::out);
 
    //inicio del programa
    Pythia pythia;                                                        
   //Declare  Pythia objet
    pythia.readString("Beams:eCM = 13000.");     // 13 TeV CM energy.
       
    pythia.readString("Top:gg2ttbar = on");      // Switch on g g -> t tbar.
    pythia.readString("Top:qqbar2ttbar = on"); 	 // Switch on q q -> t tbar.

    
    pythia.init();                                                               //initialize.
                                                            
    //número de eventos.
    int numero_evt = 10000;
    int index_evt = 0;
    
    //Inicio de eventos
    for (int iEvent = 0; iEvent < numero_evt; ++iEvent){
                
        if (!pythia.next()){ 
            
            iEvent = iEvent-1;
            continue;
        }
        
        // HEP files
        HepMC::GenEvent* hepmcevt = new HepMC::GenEvent();
        ToHepMC.fill_next_event( pythia, hepmcevt );

        // Write the HepMC event to file. Done with it.
        ascii_io << hepmcevt;
        delete hepmcevt;

    }

    cout << "Finishing ... " << endl;
    return 0;
}
