//
//  vbcode.cpp
//  vbcode
//
//  Created by AmemiyaYuko on 14/6/12.
//  Copyright (c) 2014年 AmemiyaYuko. All rights reserved.
//

#include "vbcode.h"
bool VBCode::encoder(string sCatelog){
    bool finish;
    int total=0;
    ifstream file(sCatelog.c_str());
    string termName;
    finish=file.is_open();
    while ((!file.eof())&&(finish)){
        file>>termName;
        // cout<<endl;
        // cout<<"---------New Term-----------"<<endl;
        cout<<termName<<":"<<endl;
        total++;
        if (!VBCode::encodeSingleTerm(termName)){
            
            cout<<"!!!!!!ERROR!!!!!!";
            //finish=false;
            //break;
        }
    }
    file.close();
    // cout<<"\nTotal: "<<total<<endl;
    return finish;
}


bool VBCode::encodeSingleTerm(string sTokenName){
    bool finish=false;
    int last=0;
    ifstream file;
    ofstream fout(("Temp_index\\"+sTokenName).c_str(),ios::binary);
    int byte,tmp;
    vector<char> res;
    file.open((cPath+sTokenName).c_str(),ios::binary);
    if (file.is_open()){
        finish=true;
        while (1){
            file.read((char*)&byte,sizeof(byte));
            if (file.eof()) break;
            // cout<<"real: "<<(int)byte<<endl;
            tmp=byte;
            byte=byte-last;
            last=tmp;
            // cout<<"distance: "<<byte<<endl ;
            if (byte!=0){
                res=VBCode::encodeNumber(byte);
                for (int i=0;i<res.size();i++){
                    fout.write((char*)&res[i],sizeof(res[i]));
                    // cout<<static_cast<int>(res[i])<<" ";
                }
                // cout<<endl<<"next docID"<<endl;
            }
        }
    }
    file.close();
    fout.close();
    return finish;
}


bool VBCode::termAlreadyExisted(string sTerm){
	ifstream f(("Temp_index\\" + sTerm).c_str());
    bool tmp=f.is_open();
    f.close();
    return tmp;
}


vector<char> VBCode::encodeNumber(int nNum){
    vector<char> stream;
    long leftPointer,rightPointer;
    char tmp;
    long n=nNum;
    //page 67 hints
    while (n>128){
        stream.push_back(n % 128);
        n=n/128;
    }
    stream.push_back(n);
    stream[0]+=128;
    leftPointer=0;
    rightPointer=stream.size()-1;
    while (leftPointer<rightPointer){
        tmp=stream[leftPointer];
        stream[leftPointer]=stream[rightPointer];
        stream[rightPointer]=tmp;
        leftPointer++;
        rightPointer--;
    }
    return stream;
}


vector<int> VBCode::decoder(string sTerm){
    vector<int> docID;
    int lastID=0;
    int tmp=0;
    unsigned char byte;
    ifstream file;
    if (termAlreadyExisted(sTerm)){
		file.open(("Temp_index\\" + sTerm), ios::binary);
        while (1){
            tmp=0;
            file.read((char*)&byte,1);
            if (file.eof()){
                file.close();
                break;
            }
            while (byte<128){
                tmp=tmp*128+byte;
                file.read((char*)&byte,1);
            }
            tmp=tmp*128+byte-128;
            // cout<<tmp<<" + "<<lastID<<endl;
            docID.push_back(tmp+lastID);
            lastID=tmp+lastID;
        }
    }
    else{
        cout<<"Term does not existed";
    }
    return docID;
}
