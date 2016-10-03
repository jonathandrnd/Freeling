#include <iostream>
#include "freeling.h"
#include "freeling/morfo/traces.h"
#include "lemaparser.h"
#include <time.h>
using namespace std;
using namespace freeling;

int main(){

    util::init_locale(L"default");
    wstring ipath=L"/usr/local";
    wstring path=ipath+L"/share/freeling/es/";
    
    maco_options opt(L"es");
    opt.UserMapFile=L"";
    opt.LocutionsFile=path+L"locucions.dat"; opt.AffixFile=path+L"afixos.dat";
    opt.ProbabilityFile=path+L"probabilitats.dat"; opt.DictionaryFile=path+L"dicc.src";
    opt.NPdataFile=path+L"np.dat"; opt.PunctuationFile=path+L"../common/punct.dat"; 
    maco morfo(opt);
    morfo.set_active_options (false,// UserMap
                             true, // NumbersDetection,
                             true, //  PunctuationDetection,
                             true, //  DatesDetection,
                             true, //  DictionarySearch,
                             true, //  AffixAnalysis,
                             false, //  CompoundAnalysis,
                             true, //  RetokContractions,
                             true, //  MultiwordsDetection,
                             true, //  NERecognition,
                             false, //  QuantitiesDetection,
                             true);  //  ProbabilityAssignment
    hmm_tagger tagger(path+L"tagger.dat", true, FORCE_TAGGER); 
    // create chunker 
    chart_parser parser(path+L"chunker/grammar-chunk.dat");
    // create dependency parser 
    dep_txala dep(path+L"dep_txala/dependences.dat", parser.get_start_symbol());
   
    string a=parserlemma("estudia estudiar estudio estudiaste dfdfoejoej binaryindexedtrees enero",morfo);
    cout<<a<<endl;
    string b=parserlemma("querer es poder abc def uno dos tres cuatro",morfo);
    cout<<b<<endl;
    string c=parserlemma("abc tengo tuve tener abc def uno dos tres cuatro cinco",morfo);
    cout<<c<<endl;
    
    return 0;
}
