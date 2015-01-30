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

void change(string &s1, int trueLen){
    int countSpace = 0;
    
    
    for(int i = 0; i < trueLen; i++){
        if(s1[i] == ' ')
            countSpace++;
    }
    
    int end = trueLen + countSpace * 2 - 1;
    int len = trueLen + countSpace * 2 - 1;
    
    //int j = trueLen - 1;
    
    for(int j = trueLen - 1; j >= 0; j--){
        
        //cout<<s1[j]<<endl;
        
        if(s1[j] == ' '){
            
            s1[end] = '0';
            s1[end - 1] = '2';
            s1[end - 2] = '%';
            
            end = end - 3;
            
        }else{
            
            s1[end] = s1[j];
            end = end - 1;

        }
        
        /*
        for(int i = 0; i <= len; i++){
            cout<<s1[i]<<" ";
        }
        
        cout<<endl;
         */
    }

    

}


int main()
{
    string s1 = "Mr John Smith    ";
    
    change(s1, 13);
    
    cout<<s1<<endl;

	return 0;
}

