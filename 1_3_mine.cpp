//
//  main.cpp
//  leet
//
//  Created by Fiona on 14-7-28.
//  Copyright (c) 2014年 Fiona. All rights reserved.
//

//
//  main.cpp
//  test
//
//  Created by Fiona on 14-7-20.
//  Copyright (c) 2014年 Fiona. All rights reserved.
//

#include <iostream>
#include <map>
#include <vector>
#define SIZE1 4
#define SIZE2 6

using namespace std;

bool isPermu(string s1, string s2){
    int bucket1[128];
    int bucket2[128];
    
    if(s1.length() != s2.length())
        return false;
    
    for(int i = 0; i < 128; i++){
        bucket1[i] = 0;
        bucket2[i] = 0;
    }
    
    for(int i = 0; i < s1.length(); i++){
        bucket1[int(s1[i])] ++;
        bucket2[int(s2[i])] ++;
    }
    
    for(int i = 0; i < 128; i++){
        if(bucket1[i] != bucket2[i])
            return false;
    }
    
    return true;
}


int main()
{
    string s1 = "abcdef";
    string s2 = "bcdaef";
    
    
    cout<<isPermu(s1, s2)<<endl;

	return 0;
}

