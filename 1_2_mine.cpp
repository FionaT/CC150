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

void reverse(string &str)
{
    int mid = str.size() / 2;
    
    for(int i = 0, j = str.size() - 1; i < mid; i++, j--){
        char temp = str[i];
        
        str[i] = str[j];
        str[j] = temp;
    }
    
}


int main()
{
    string a = "abcdef";
    
    cout<<a<<endl;
    
    reverse(a);
    
    cout<<a<<endl;
    
	return 0;
}

