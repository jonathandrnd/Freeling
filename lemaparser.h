#include<iostream>
#include "freeling.h"
#include "freeling/morfo/traces.h"
#include <time.h>

using namespace std;
using namespace freeling;

string PrintLemma(list<sentence> &ls) {
  sentence::const_iterator w;
  string ans="";
  for (list<sentence>::iterator is=ls.begin(); is!=ls.end(); is++) {
      bool first=1;
      for (w=is->begin(); w!=is->end(); w++) {   
          if(first==0)ans+=" ";
	  wstring pal=w->get_form();
          wstring lemma=w->get_lemma();	  
    	  if(lemma.find(L"??")!=-1){
              ans+=string(pal.begin(),pal.end());
	  }else{
              ans+=string(lemma.begin(),lemma.end());
	  }	 
	  first=0;
      }    
  }

   return ans;
}

maco init(){
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
    return morfo;
}

string parserlemma(string s,maco &morfo){
    wstring ipath=L"/usr/local";
    wstring path=ipath+L"/share/freeling/es/";
    tokenizer tk(path+L"tokenizer.dat"); 
    splitter sp(path+L"splitter.dat");
    splitter::session_id sid=sp.open_session();
    wstring text(s.begin(),s.end());
    list<word> lw=tk.tokenize(text);
    list<sentence> ls;
    sp.split(sid, lw, true, ls);
    morfo.analyze(ls);
    string answer=PrintLemma(ls);
    lw.clear(); ls.clear();    
    sp.close_session(sid);

    return answer;
}
