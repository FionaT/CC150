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

ListNode *add(ListNode *l1, ListNode *l2){
    ListNode *ans = new ListNode(0);
    int carry = 0, temp;
    
    while(l1 != NULL && l2 != NULL){
        temp = carry + l1->val + l2->val;
        
        if(temp >= 10){
            carry = 1;
            temp %= 10;
        }else
            carry = 0;
        
        ans->appendToTail(temp);
        
        l1 = l1->next;
        l2 = l2->next;
    }
    
    while(l1 != NULL){
        temp = carry + l1->val;
        
        if(temp >= 10){
            carry = 1;
            temp %= 10;
        }else
            carry = 0;
        
        ans->appendToTail(temp);
        
        l1 = l1->next;
    }
    
    while(l2 != NULL){
        temp = carry + l2->val;
        
        if(temp >= 10){
            carry = 1;
            temp %= 10;
        }else
            carry = 0;
        
        ans->appendToTail(temp);
        
        l2 = l2->next;
    }
    
    
    if(l1 == NULL && l2 == NULL && carry == 1){
        ans->appendToTail(1);
    }
    
    //ans = ans->next;
    
    return ans->next;
}

int main()
{
    /*
    int arr[10] = {9, 5, 4, 5, 1, 5, 3, 6, 7, 11};
    ListNode *head = new ListNode(1);

    for(int i = 0; i < 10; i++){
        head->appendToTail(arr[i]);
    }
    
    ListNode *h = head;

    
    while(h != NULL){
        cout<<h->val<<" ";
        
        h = h->next;
    }
    
    cout<<endl;
    */
    
    ListNode *l1, *l2;
    
    l1 = new ListNode(9);
    
    l1->appendToTail(7);
    l1->appendToTail(3);
    l1->appendToTail(9);

    
    l2 = new ListNode(2);
    
    l2->appendToTail(4);
    l2->appendToTail(6);
    l2->appendToTail(2);
    
    ListNode *ans = add(l1, l2);
    
    while(l1 != NULL){
        cout<<l1->val<<" ";
        l1 = l1->next;
    }
    
    cout<<endl;
    
    while(l2 != NULL){
        cout<<l2->val<<" ";
        l2 = l2->next;
    }
    
    cout<<endl;
    
    while (ans != NULL) {
        cout<<ans->val<<" ";
        
        ans = ans->next;
    }
    
	return 0;
}

