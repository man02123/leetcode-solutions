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
    ListNode* rotateRight(ListNode* h, int k) {
        if(h == NULL || k==0 || h->next ==NULL)
            return h;
        
        int len =0;
        ListNode *x = h ,*l = h;
        
        while(x!=NULL)
            x=x->next,len++;
        
        
        k = k%len;
        
       int pt = len-k;
        
        x = h;
        while(pt > 1){
            x = x->next;
            pt--;
        }
       
        
        while(l->next != NULL)
            l=l->next;
        
        
        
        
        l->next = h;
        h = x->next;
        x->next  = NULL;
        
        
            
            return h;
        
    }
};