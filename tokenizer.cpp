#include <cassert>
#include <fstream>
#include <vector>
#include <cctype>
#include <algorithm>
#include "tokenizer.h"

#define BUF_LENGTH 50

using namespace std;

CTokenizer::CTokenizer():m_sCorpusPath("Reuters"), m_sTemporalPath("Temp"), 
               m_sDelimiterPath("Delimiter"), m_sStopWordPath("StopWord"),
               m_nTermNum(0), m_nDocNum(0)
{

}
int CTokenizer::Init()
{
	char buf[BUF_LENGTH];
  ifstream fin;
  vector<string>::iterator it;

  //Delimiters
  fin.open(m_sDelimiterPath.c_str());
  cout << "Delimiters are: ";
  while(fin.getline(buf,BUF_LENGTH)){
    m_vsDelimiter.push_back(buf);
    cout << buf;
  }
  cout << endl;
  cout << m_vsDelimiter.size() << endl;
  fin.close();
  
  
  //Stop words
  fin.open(m_sStopWordPath.c_str());
  cout << "StopWords are: ";
  while(fin.getline(buf,BUF_LENGTH)){
    m_vsStopWord.push_back(buf);
    cout << buf << " ";
  }
  cout << endl;
  cout << m_vsStopWord.size() << endl;
  fin.close();  
   
}


int CTokenizer::__ProcessOneDoc(string DocPath)
{
	cout << "Processing Doc " << DocPath << endl;
	ifstream fin;
	ofstream fout;
	
	string buf;
	size_t found;
	vector<string>::iterator iter_d;
	vector<string>::iterator iter_t;
	vector<string> vWordToken;
	
	fin.open(DocPath.c_str());
	while(fin >> buf){
		//use Delimiter to split buf to tokens
		transform(buf.begin(),buf.end(),buf.begin(), (int (*)(int))tolower); //to lower case
		vWordToken.push_back(buf);
		iter_d = m_vsDelimiter.begin();
		while(iter_d != m_vsDelimiter.end()){	
			iter_t = vWordToken.begin();
			while(iter_t != vWordToken.end()){
				buf = (*iter_t);		
				found = buf.find(*iter_d);
				if(found != string::npos){
				  vWordToken.erase(iter_t);
					vWordToken.push_back(buf.substr(0, found));
					if(found < buf.size()-1){
						vWordToken.push_back(buf.substr(found+1));
					}
					iter_d = m_vsDelimiter.begin()-1;
					break;
				}else{
					iter_t++;
				}
			}// end subString-while
			iter_d++;
		}//end Delimiter-while
		
		//user stop word to filter splitted token
		iter_t = vWordToken.begin();
		while(iter_t != vWordToken.end()){
			
			if ((*iter_t).size() > 1 
			 	&& !__IsNum(*iter_t)  //ignore number
			 	&& !(find(m_vsStopWord.begin(),m_vsStopWord.end(),(*iter_t)) != m_vsStopWord.end())){//one available term
				
				if(!(find(m_vsTerm.begin(),m_vsTerm.end(),(*iter_t)) != m_vsTerm.end())){
					m_vsTerm.push_back(*iter_t); //add new term to term vector
					m_nTermNum++;
				}
				
				fout.open((m_sTemporalPath+"/"+(*iter_t)).c_str(), ios::binary|ios::app);
				fout.write((char *)(&m_nDocNum), sizeof(m_nDocNum));
				fout.close();
				
			}
			iter_t++;
		}
		vWordToken.clear();
	}
	fin.close();
}

bool CTokenizer::__IsNum(string str) 
{ 
	for(int i=0;i<str.size();i++) 
 	{   
  	if ((str.at(i)>'9') || (str.at(i)<'0') )
  	{ 
   		return false; 
  	} 
 } 
 return	true; 
}

int CTokenizer::ProcessAllDoc()
{
	int firstDocID = 1;
	int lastDocID = 21576;
	int i = firstDocID;
	char str[10];
	while(i <= lastDocID){
		m_nDocNum++;
		sprintf(str,"%d",i);
		__ProcessOneDoc(m_sCorpusPath+"/"+str+".html");
		++i;
	}
	
	cout << "Total Doc: " << m_nDocNum << endl;
	cout << "Total Term: " << m_nTermNum << endl;
}
