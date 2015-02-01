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

ListNode *removeDuplicate(ListNode *head){
    ListNode *h = head;
    ListNode *cur, *last;
    
    while(h != NULL){
        last = h;
        cur = h->next;
        
        while(cur != NULL){
            if(cur->val == h->val){
                last->next = cur->next;
                cur = cur->next;
            }else{
                last = cur;
                cur = cur->next;
            }
            
            
        }
        
        h = h->next;
    }
    
    return head;
}

int main()
{
    int arr[10] = {1,1,4,2,4,5,5,5,6,7};
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
    
    //head = deleteNode(2, head);
    head = removeDuplicate(head);
    
    h = head;
    
    while(h != NULL){
        cout<<h->val<<" ";
        
        h = h->next;
    }
    
	return 0;
}

