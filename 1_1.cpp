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

bool uniqueChar(string str){
    
    if(str.length() > 128)
        return false;
    
    int bucket[128];
    
    for(int i = 0; i < 128; i++)
        bucket[i] = 0;
    
    for(int i = 0; i < str.length(); i++){
        
        bucket[int(str[i])] ++;
        
        if(bucket[int(str[i])] == 2)
            return false;
    }
    
    return true;
}


int main()
{
    string str = "asbety";
    
    cout<<uniqueChar(str)<<endl;

	return 0;
}

