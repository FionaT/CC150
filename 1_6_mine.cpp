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

void rotate(vector<vector<int>> &v){
    vector<vector<int>> temp = v;
    int n = v.size() - 1;
    
    
    for(int i = 0; i < v.size(); i++){
        for(int j = 0; j < v[0].size(); j++){
            v[j][i] = temp[n - i][j];
        }
    }
    
    
}


int main()
{
    int arr[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<vector<int>> v;
    
    
    for(int i = 0; i < 3; i++){
        vector<int> temp;
        
        for(int j = 0; j < 3; j++){
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
    
    
    rotate(v);
    
    cout<<endl;
    
    for(int i = 0; i < v.size(); i++){
        for(int j = 0; j < v[0].size(); j++){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
    

	return 0;
}

