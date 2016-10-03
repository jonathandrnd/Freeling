#include <iostream>
#include "freeling.h"
#include "freeling/morfo/traces.h"
#include "lemaparser.h"
#include <time.h>
using namespace std;
using namespace freeling;

int main(){

    maco morfo=init();
   
    string a=parserlemma("estudia estudiar estudio estudiaste dfdfoejoej binaryindexedtrees enero",morfo);
    cout<<a<<endl;
    string b=parserlemma("querer es poder abc puedo puedes def uno dos tres cuatro",morfo);
    cout<<b<<endl;
    string c=parserlemma("soy eres es ser fuiste",morfo);
    cout<<c<<endl;
    string d=parserlemma("a b c d e f g h",morfo);
    cout<<d<<endl;
    
    return 0;
}
