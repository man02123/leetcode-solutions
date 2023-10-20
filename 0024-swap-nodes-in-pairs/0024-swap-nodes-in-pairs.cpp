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
    ListNode* swapPairs(ListNode* head) {
        
        
        if(head==NULL || head->next==NULL)
            return head;
        ListNode dum(0);
        dum.next = head;
        
        ListNode *cur = head , *prev = &dum;
       
        
        while(cur && cur->next){
            
            prev->next = cur->next;
            prev = prev->next;
            cur->next = prev->next;
            prev->next = cur;
            
            prev = cur;
            cur = cur->next;
            
    
        }
        return dum.next;
        
    }
};

// if(!head) return NULL;
//         ListNode tmp(0);
//         tmp.next = head;
//         ListNode *pre = &tmp, *cur = head;
//         while(cur && cur->next){
//             pre->next = cur->next;
//             pre = pre->next;
//             cur->next = pre->next;
//             pre->next = cur;
//             pre = cur;
//             cur = cur->next;
//         }