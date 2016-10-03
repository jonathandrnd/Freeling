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
