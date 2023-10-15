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
    ListNode *detectCycle(ListNode *h) {
        if(h == NULL)
            return NULL;
        if(h->next!=nullptr && h->next == h)
            return h;
         if(h->next!=nullptr && h->next->next!=nullptr && h->next->next == h)
            return h;
     
        ListNode *f = h,*s = h;
        
        while(f && f->next){
            
            f= f->next->next;
            s = s->next;
            if(f==s)
            {
                while(s!=h)
                {
                    s=s->next;
                    h=h->next;
                    if(h==s)
                        return s;
                }
            }
        }
        return NULL;
        
//        ListNode *n = h;
//         int cnt =0;
//         while(n != s){
//             n = n->next;
//             cnt++;
            
//         }
//         return cnt;
    }
};















