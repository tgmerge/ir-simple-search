//
//  vbcode.h
//  vbcode
//
//  Created by AmemiyaYuko on 14/6/12.
//  Copyright (c) 2014年 AmemiyaYuko. All rights reserved.
//

#ifndef vbcode_vbcode_h
#define vbcode_vbcode_h
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
using namespace std;
class VBCode{
public:
    bool encoder(string sCatelog);
    vector<int> decoder(string sTerm);
    bool termAlreadyExisted(string sTerm);
    bool encodeSingleTerm(string sTokenName);
private:
    vector<char> encodeNumber(int nNum);
    string cPath="temp/";
    int nLastID;
};



#endif
