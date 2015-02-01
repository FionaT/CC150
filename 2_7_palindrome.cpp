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
#include <stack>

#define SIZE1 4
#define SIZE2 6

using namespace std;

class ListNode {
public:
    int val;
    ListNode *next = NULL;
    
    ListNode(int x) : val(x), next(NULL) {}
    
    void appendToTail(int d){
        ListNode *end = new ListNode(d);
        ListNode *n = this;
        
        while(n->next != NULL){
            n = n->next;
        }
        
        n->next = end;
    }
    

};

bool palindrome(ListNode *l){
    ListNode *ptr1 = l, *ptr2 = l;
    stack<int> s;
    
    while(ptr2 != NULL && ptr2->next != NULL){
        s.push(ptr1->val);
        
        //cout<<"ptr1 "<<ptr1->val<<endl;
        ptr1 = ptr1->next;
        
        //cout<<"ptr2 "<<ptr2->val<<endl;
        ptr2 = ptr2->next->next;
        
    }
    
    //cout<<ptr2->val<<"! "<<endl;
    
    if(ptr2 != NULL && ptr2->next == NULL){
        ptr1 = ptr1->next;
    }
    
    //cout<<ptr1->val<<endl;
    
    while(s.size()){
        if(s.top() != ptr1->val)
            return false;
        
        ptr1 = ptr1->next;
        s.pop();
    }
    
    return true;
}

int main()
{
    ListNode *l = new ListNode(1);
    
    l->appendToTail(2);
    l->appendToTail(0);
    l->appendToTail(2);
    l->appendToTail(1);
    
    
    cout<<palindrome(l)<<endl;
    
	return 0;
}

