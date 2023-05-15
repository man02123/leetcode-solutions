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
    ListNode* swapNodes(ListNode* head, int k) {
        int count=1;
        ListNode* temp,*temp2,*temp1;
        temp=temp1=temp2=head;
        while(temp1)
        {
          count++;
            temp1=temp1->next;
            }
        for(int i=1;i<k;i++)
        {
            temp=temp->next;
        }
        for(int j=1;j<count-k;j++)
        {
        
        temp2=temp2->next;
        }
        swap(temp->val,temp2->val);
      
        return head;
    }
};