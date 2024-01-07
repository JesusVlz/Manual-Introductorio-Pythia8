# include "Pythia8/Pythia.h"
using namespace Pythia8;

int main (){
	Pythia pythia ;
        pythia.readString("Beams:eCM=13000.");
        pythia.readString("Top:gg2ttbar = on");
        pythia.readString("Top:qqbar2ttbar = on");

        pythia.init();

        int nEvents = 10;

        for( int iEvent = 1; iEvent < nEvents ; ++ iEvent ) {
                if (!pythia.next())continue ;

                // El for inicia en la primera particula y se detiene en el tam$
                for ( int i = 1; i < pythia.event.size(); ++ i ){

                        if ( pythia.event[i].isFinal()){

                        cout<<" Particula final: "
                            << pythia.event[i].name()
                            <<" , id: "
                            << pythia.event[i].id()
                            <<" , su energia: "
                            << pythia.event[i].e() <<endl;
                                                                }
                        }
                }

  // Done.
  return 0;

	}


