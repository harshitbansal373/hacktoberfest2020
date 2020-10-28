/*
This is an algorithm for solving the problem of merging k sorted linked list. This problem is an extension of merging 2 sorted list.
The code is commented for better understanding.
Leetcode problem link: https://leetcode.com/problems/container-with-most-water/

--------------------------------
Author: Mudassar Raza(https://github.com/mraza1312)
Suggestions are most welcome.
--------------------------------
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */



/*
we have a dummy list of 1 node and  
*/
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() <=1 ) {
            if(lists.size () == 0 ) return nullptr;
            return lists[0];
        }
        ListNode *newListHead = new ListNode(INT_MIN);    // start with dummy node
        //ListNode *cur = newListHead;
        
        //
        
        for(int i = 0; i<lists.size(); i++){
            
            if(lists[i] != nullptr){
               newListHead = mergeTwo(newListHead,  lists[i]);
            }
        }
        
        return newListHead->next ;
    }
    
    // merges two sorted LL and returns the head of the new list
    ListNode *mergeTwo(ListNode *l1, ListNode *l2){
        if( !l1 ) return l2;
        if( !l2 ) return l1;
        
        ListNode *dummy = new ListNode(0);
        ListNode *cur = dummy;
        
        while(l1 && l2){
            if(l1->val < l2->val){
                cur->next = l1;
                l1 = l1->next;   
            } else {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        
        if(l1 != nullptr) cur->next = l1;           // since its a linkedlist you  only need
        else if(l2 != nullptr) cur->next = l2;      // to attach one link and you're done. 
        
        return dummy->next;
    }
};
