#include <iostream>
# include "Pythia8/Pythia.h"

using namespace Pythia8 ;

int main (){
	Pythia pythia ;

         pythia.readString("Beams:eCM = 13000.");
         pythia.readString("Top:gg2ttbar = on");
         pythia.init();

        int nEvents = 1; //numero de eventos

        for ( int iEvent = 0; iEvent < nEvents ; ++ iEvent ) {
                if (! pythia . next ()) continue ;
                cout <<" Analysis here !" <<endl ;
                }


         pythia.stat();

        }


