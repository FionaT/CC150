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

ListNode *findKthToLast(ListNode *head, int k){
    ListNode *h = head;
    int size = 0;
    
    while(h != NULL){
        size++;
        h = h->next;
    }
    
    size = size - k;
    h = head;
    
    while(size--){
        h = h->next;
    }
    
    return h;
}

int main()
{
    int arr[10] = {2,3,4,5,6,7,8,9,10,11};
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
    ListNode *ans = findKthToLast(head, 3);
    
    cout<<ans->val<<endl;
    
	return 0;
}

