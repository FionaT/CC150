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

ListNode *partition(ListNode *head, int x){
    if(head == NULL)
        return head;
    
    ListNode *l1 = new ListNode(head->val);
    ListNode *l2 = new ListNode(head->val);
    ListNode *h = head;
    
    
    while(h != NULL){
        if(h->val <= x)
            l1->appendToTail(h->val);
        else
            l2->appendToTail(h->val);
        
        h = h->next;
    }

    l1 = l1->next;
    l2 = l2->next;
    
    if(l1 == NULL)
        return l2;
    
    head = l1;
    
    while(1){
        if(l1->next == NULL)
            break;
        
        l1 = l1->next;
    }
    
    l1->next = l2;
    //cout<<l1->val<<endl;
    
    return head;
}

int main()
{
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
    
    head = partition(head, 4);
    
    h = head;
    
    while(h != NULL){
        cout<<h->val<<" ";
        
        h = h->next;
    }
    
	return 0;
}

