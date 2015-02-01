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

ListNode *deleteMiddle(ListNode *head){
    ListNode *ptr1 = head, *ptr2 = head;
    
    while(1){    //find the node before middle node
        ptr2 = ptr2->next->next;
        
        if(ptr2 == NULL || ptr2->next == NULL)
            break;
        
        ptr1 = ptr1->next;
    }
    
    ptr1->next = ptr1->next->next;
    
    
    return head;
}

int main()
{
    int arr[10] = {2,3,4,5,6,7,8,9,10, 11};
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
    head = deleteMiddle(head);
    
    h = head;
    
    while(h != NULL){
        cout<<h->val<<" ";
        
        h = h->next;
    }
    
	return 0;
}

