/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        
        if(head==NULL)
            return NULL;
        if(head->next && head->next==head)
            return head;
        if(head->next!=NULL && head->next->next!=NULL && head->next->next==head)
            return head;
        
        
        ListNode *f =head;
        ListNode *s = head;
        while(f && f->next)
        {
            f=f->next->next;
            s=s->next;
            if(f==s)
            {
                while(s!=head)
                {
                    s=s->next;
                    head=head->next;
                    if(head==s)
                        return s;
                }
            }
        }
        
        return NULL;
        
    }
};