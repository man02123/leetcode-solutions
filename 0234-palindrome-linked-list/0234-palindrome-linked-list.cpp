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
    bool isPalindrome(ListNode* head) {
        if(head->next==NULL)
            return true;
        if(head!=NULL && head->next!=NULL && head->next->next==NULL)
        {
            if(head->val == head->next->val)
                return true;
            return false;
        }
        
        
       ListNode* s=head,*f=head;
        while(f && f->next)
        {
            f=f->next->next;
            s=s->next;
        }
        
        ListNode *rev=help(s);
        
       while(head!=s && rev!=NULL)
       {
           if(head->val!=rev->val)
               return false;
           head=head->next;
           rev=rev->next;
       }
        // while(rev)
        // {
        //     cout<<rev->val;
        //     rev=rev->next;
        // }
        
       return true; 
    }
    ListNode* help(ListNode* mid)
    {
        if(mid==NULL || mid->next==NULL )
            return mid;
        
        ListNode *res=help(mid->next);
        
        mid->next->next=mid;
        mid->next=NULL;
        return res;
    }
};