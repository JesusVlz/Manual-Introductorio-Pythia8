# include "Pythia8/Pythia.h"

#include "TH1D.h"
#include "TFile.h"

using namespace Pythia8;

int main (){

	TFile *outputFile = new TFile("output.root", "RECREATE");
	
	// Crear histogramas
  	TH1D *hEta = new TH1D("hEta", ";Eta;Frecuencia", 50, -5.0, 5.0);
        TH1D *hPhi = new TH1D("hPhi", ";Phi;Frecuencia", 50, -3.2, 3.2);
        TH1D *hPt = new TH1D("hPt", ";pT;Frecuencia", 50, 0.0, 100.0);


        //Configuracion 
	Pythia pythia ;
        pythia.readString("Beams:eCM = 13000.");
        pythia.readString("Top:gg2ttbar = on");
        pythia.readString("Top:qqbar2ttbar = on");

	//Iniciador
        pythia.init();

        int nEvents = 10;

        for( int iEvent = 1; iEvent < nEvents ; ++ iEvent ) {
                if (!pythia.next())continue 
                
                for ( int i = 1; i < pythia.event.size(); ++ i ){
                      
			    if (pythia.event[i].isFinal()) {
				// Llenar histogramas
				hEta->Fill(pythia.event[i].eta());
				hPhi->Fill(pythia.event[i].phi());
				hPt->Fill(pythia.event[i].pT());
			    }
			}
                }

	// Guardar histogramas en un archivo ROOT
   
   hEta->Write();
   hPhi->Write();
   hPt->Write();

   outputFile->Close();

  // Done.
  return 0;

	}


