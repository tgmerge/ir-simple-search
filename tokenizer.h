#ifndef _INDEXMAKER_H
#define _INDEXMAKER_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class CTokenizer
{
private:
	string m_sCorpusPath;
	string m_sTemporalPath;
	string m_sDelimiterPath;
	string m_sStopWordPath;
	
	vector<string> m_vsDelimiter;
	vector<string> m_vsStopWord;
	vector<string> m_vsTerm;
	int m_nTermNum;
	int m_nDocNum;
private:
  int __ProcessOneDoc(string DocPath);
  bool __IsNum(string str);
public:
  CTokenizer();
  int Init();
	int ProcessAllDoc();
};

#endif
