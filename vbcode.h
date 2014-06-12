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
#include "stdlib.h"
class VBCode{
public:
    bool encoder(string name);
    vector<string> decoder(string token);
private:
    string fileName;
};



#endif
