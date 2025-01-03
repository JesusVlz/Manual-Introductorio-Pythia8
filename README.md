# Manual-Introductorio-Pythia
Este es un breve resumen de los pasos de instalacion de las herramientas a utlizar en este manual, junto con con los comandos necesarios para compilar y correr de manera practica. L

Los enlaces que se utlizaron: 
Pythia [Version 8.309](https://pythia.org/releases/),
HepMC2 [Version 2.06.09](https://hepmc.web.cern.ch/hepmc/releases/hepmc2.06.09.tgz),
Delphes [Version 3.5.0](https://cp3.irmp.ucl.ac.be/projects/delphes/wiki/Releases).

Los pasos de instalacion de pythia en un sistema operativo unix.
```plaintext
wget https://pythia.org/download/pythia83/pythia83XX.tgz
```
```plaintext
tar xvfz pythia83XX.tgz
```
```plaintext
make
```
A continuacion desglozare la instalacion del paquete Hepmc.
```plaintext
wget  http://hepmc.web.cern.ch/hepmc/releases/hepmc2.06.09.tgz
```
```plaintext
tar -zxf hepmc2.06.09.tgz
```
comandos para compilar el paquete
```plaintext
cd $HEPMC/HepMC-2.6.9

./configure --with-momentum=GEV --with-length=MM --prefix=/LUSTRE/home/jvelazquez/software/hepmc2.06.09/build

 make 
 make install
```
Ahora estamos listo para compilar desde la carpeta de ejemplos (en ingles examples) del directorio de pythia. (Se encuentran las lineas para compilar pythia solo y junto con Hepmc, root en el archivo de texto compilar)
```plaintext
 g++ mymain03.cc -o mymain03 -I../include -O2 -std=c++11 -pedantic -W -Wall -Wshadow -fPIC -pthread  -L../lib -Wl,-rpath,../lib -lpythia8 -ldl -I/miDirectorio/hepmc2.06.09/build/include -L/miDirectorio/hepmc2.06.09/build/lib -Wl,-rpath,/miDirectorio/hepmc2.06.09/build/lib -lHepMC \-DHEPMC2

```
Una vez compilado el configurador en la carpeta ejemplos y tengamos el ejecutable, podemos ejecutarlo generando un archivo de extension hepmc.
```plaintext
./mymain03
```
A partir de aqui se asumira que ya se cuenta con el archivo hepmc generado de pythia, y procedemos a procesarlo con delphes. Donde usaremos el configurador que implementa el detector CMS en nuestro simulacion rapida.
```plaintext
$ nano /Delphes-3.5.0/cards/delphes_card_CMS.tcl
```
ahora para ejecutar delphes
```plaintext
$ ./DelphesHepMC2 cards/delphes_card_CMS.tcl output.root input.hepmc
```
Con esto ya contaremos un archivo root con toda la informacion simulada de detector, es posible ejecutar un macro de analisis basico de la carpeta ejemplos del propio delphes de la siguiente manera.
```plaintext
$ root -l examples/macro.C'("delphes_output.root")'
```
