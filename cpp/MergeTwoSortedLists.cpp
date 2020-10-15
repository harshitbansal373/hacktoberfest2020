// Link to the problem : https://leetcode.com/problems/merge-two-sorted-lists/

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
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* x = NULL;
        ListNode* y = NULL;
        ListNode* l3 = NULL;
        ListNode* z = NULL;
        x = l1;
        y = l2;
        int temp;
        while(x!=NULL && y!=NULL) {
            if(x->val <= y->val) {
                temp = x->val;
                x = x->next;
            }
            else {
                temp = y->val;
                y = y->next;
            }
            
            if(l3 == NULL) {
                l3 = new ListNode();
                l3->val = temp;
                z = l3;
            }
            else {
                z->next = new ListNode();
                z = z->next;
                z->val = temp;
            }
            
        }
        
        while(x!=NULL){
            if(l3 == NULL) {
                l3 = new ListNode();
                l3->val = x->val;
                z = l3;
                x = x->next;
            }
            else {
                z->next = new ListNode();
                z = z->next;
                z->val = x->val;
                x = x->next; 
            }
            
        }
        
        while(y!=NULL){
            if(l3 == NULL) {
                l3 = new ListNode();
                l3->val = y->val;
                z = l3;
                y = y->next;
            }
            else {
                z->next = new ListNode();
                z = z->next;
                z->val = y->val;
                y = y->next; 
            }
        }
        return l3;
    }
};
