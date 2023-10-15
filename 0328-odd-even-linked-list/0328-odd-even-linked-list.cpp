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
    ListNode* oddEvenList(ListNode* head) {
        if(head==nullptr || head->next==nullptr)return head;
        
        
        
        ListNode* o=head;
        ListNode* e  = head->next;
        ListNode* x = e;
        
        while(e && e->next )
        {
            
            o->next = o->next->next;
            e->next = e->next->next;
            
            
            o=o->next;
            e = e->next;
            
            
            
        }
        o->next = x;
        
        return head;
        
    } 
    
    
//         while (even != null && even.next != null) {
//             odd.next = odd.next.next; 
//             even.next = even.next.next; 
//             odd = odd.next;
//             even = even.next;
//         }
//         odd.next = evenHead; 
        
    
};