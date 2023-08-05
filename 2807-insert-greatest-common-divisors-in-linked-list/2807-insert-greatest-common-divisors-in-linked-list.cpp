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
    ListNode* insertGreatestCommonDivisors(ListNode* he) {
        vector<int> res;
        ListNode* h = he;
        if(he->next == NULL)
            return he;
        
        ListNode *fow = he->next;
        ListNode *back = he;
        
        while(fow != NULL){
         
            ListNode* gc = new ListNode(__gcd(fow->val,back->val));
            back->next = gc;
            gc->next = fow;
            fow = fow->next;
            back = gc->next;
           
        }
        return h;
        
       
        
    }
};