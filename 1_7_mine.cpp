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

void setZero(vector<vector<int>> &v){
    vector<vector<int>> temp = v;
    
    int r[1000];
    int c[1000];
    
    for(int i = 0; i < 1000; i++){
        r[i] = c[i] = 0;
    }
    
    for(int i = 0; i < v.size(); i++){
        for(int j = 0; j < v[0].size(); j++){
            if(v[i][j] == 0){
                r[i] = c[j] = 1;
            }
        }
    }
    
    for(int i = 0; i < v.size(); i++){
        if(r[i]){
            for(int j = 0; j < v[0].size(); j++){
                v[i][j] = 0;
            }
        }
    }
    
    
    for(int i = 0; i < v[0].size(); i++){
        if(c[i]){
            for(int j = 0; j < v.size(); j++){
                v[j][i] = 0;
            }
        }
    }
    
}


int main()
{
    int arr[3][4] = {{1, 2, 3, 4}, {5, 6, 0, 8}, {9, 10, 11, 12}};
    vector<vector<int>> v;
    
    
    for(int i = 0; i < 3; i++){
        vector<int> temp;
        
        for(int j = 0; j < 4; j++){
            temp.push_back(arr[i][j]);
            //cout<<arr[i][j]<<" ";
        }
        
        v.push_back(temp);
    }
    
    
    for(int i = 0; i < v.size(); i++){
        for(int j = 0; j < v[0].size(); j++){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
    
    
    setZero(v);
    
    cout<<endl;
    
    for(int i = 0; i < v.size(); i++){
        for(int j = 0; j < v[0].size(); j++){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
    

	return 0;
}

