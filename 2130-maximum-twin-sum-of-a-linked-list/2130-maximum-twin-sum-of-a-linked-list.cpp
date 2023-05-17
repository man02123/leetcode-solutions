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
    int pairSum(ListNode* head) {
        ListNode *mid =head,*s = head,*prev = NULL;
        
        while(mid && mid->next)
        {
            mid=mid->next->next;
            prev = s;
            s = s->next;
            
            
        }
        prev ->next =NULL;
        int maxi= 0;
        
        ListNode *y  = s;
        ListNode *x = reverse(s);
        // x->next = y;
        // while(x)
        // {
        //     cout<<x->val;
        //     x = x->next;
        // }
        
        while(head!=NULL)
        {
            int temp = head->val;
            temp+=x->val;
            maxi = max(maxi,temp);
            
            head = head->next;
            x = x->next;
        }
    
       return maxi; 
        
    }
    ListNode* reverse(ListNode* head)
    {
         ListNode* f,*prev = NULL;
        
        while(head!=NULL)
        {
            f = head->next;
            head->next = prev;
            prev = head;
            
            head = f;
        }
        return prev;
    }
};