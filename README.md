--------------------- Freeling -----------------
-------------- INSTALACION ---------------------
sudo apt-get install build-essential automake autoconf libtool git
sudo apt-get install libboost-regex-dev libicu-dev zlib1g-dev
sudo apt-get install libboost-system-dev libboost-program-options-dev libboost-thread-dev

git clone https://github.com/TALP-UPC/FreeLing.git
autoreconf --install
./configure
make
sudo make install

------------- SETEAR VARIABLES DEL SISTEMA  -------------
LIBS="-lfreeling -lboost_system"
PATHS="-L/usr/local/lib -I/usr/local/include -I/usr/local/include/foma -L/usr/local/lib -I/usr/local/include"

------------- AÑADIR LOS SIGUIENTES ARCHIVOS PARA GENERAR EL LEMA FACILMENTE -----------
lemaparser.h ,  sample.cpp
https://github.com/jonathandrnd/Freeling
------------- COMANDO PARA COMPILAR Y EJECUTAR -------------
g++ -std=c++0x -o sample sample.cpp $PATHS $LIBS
./sample
------------------------------------------------------------


---pagina de referencia de instalacion
https://talp-upc.gitbooks.io/freeling-user-manual/content/installation.html
