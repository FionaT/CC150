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

string compress(string str){
    string ans = "";
    int counter = 1;
    
    if(str.length() == 0)
        return str;
    
    char last = str[0];
    
    for(int i = 1; i < str.length(); i++){
        
        if(i == str.length() - 1){
            if(str[i] == last){
                counter++;
                
                ans += '0' + counter;
                ans += last;
            }else{
                if(counter > 1){
                    ans += '0' + counter;
                    ans += last;
                }else{
                    ans += last;
                }
                
                ans += str[i];
            }
        }else{
            
            if(str[i] == last){
                counter++;
            }else{
                
                if(counter > 1){
                    ans += '0' + counter;
                    ans += last;
                    
                    last = str[i];
                    counter = 1;
                }else{
                    ans += last;
                    last = str[i];
                    counter = 1;
                }

            }
            
            
        }
        
    }
    
    
    return ans;
}


int main()
{
    string s1 = "aaabcrcccdd";
    
    string ans = compress(s1);
    
    cout<<ans<<endl;

	return 0;
}

