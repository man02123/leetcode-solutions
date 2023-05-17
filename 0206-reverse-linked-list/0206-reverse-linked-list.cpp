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
    ListNode* reverseList(ListNode* head) {
        return help(head);
    }
//     ListNode* help (ListNode* head)
//     {
//         if(head==NULL || head->next==NULL )
//             return head;
        
//         ListNode* res=help(head->next);
//           head->next->next=head;
//         head->next=NULL;
//         return res;
//     }
    
    ListNode* help(ListNode* head)
    {
        ListNode* fow =NULL ,*prev = NULL;
        
        while(head!=NULL)
        {
            fow = head->next;
            head->next = prev;
            prev = head;
            head= fow;
        }
        return prev;
    //     while(head!=NULL)
    //     {
    //         cout<<head->val;
    //         head = head->next;
    //     }
    // return head;
    }
};