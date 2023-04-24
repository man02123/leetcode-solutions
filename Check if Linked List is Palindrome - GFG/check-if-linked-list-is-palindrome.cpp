//{ Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
using namespace std;
/* Link list Node */
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};




// } Driver Code Ends
/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

class Solution{
  public:
    //Function to check whether the list is palindrome.
    bool isPalindrome(Node *head)
    {
        if(head->next==NULL)
            return true;
        if(head!=NULL && head->next!=NULL && head->next->next==NULL)
        {
            if(head->data == head->next->data)
                return true;
            return false;
        }
        
        
       Node* s=head,*f=head;
        while(f && f->next)
        {
            f=f->next->next;
            s=s->next;
        }
        
        Node *rev=help(s);
        
       while(head!=s && rev!=NULL)
       {
           if(head->data!=rev->data)
               return false;
           head=head->next;
           rev=rev->next;
       }
        
        
       return true; 
    }
    Node* help(Node* mid)
    {
        if(mid==NULL || mid->next==NULL )
            return mid;
        
        Node *res=help(mid->next);
        
        mid->next->next=mid;
        mid->next=NULL;
        return res;
    }
        
    
};



//{ Driver Code Starts.
/* Driver program to test above function*/
int main()
{
  int T,i,n,l,firstdata;
    cin>>T;
    while(T--)
    {
        
        struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        // taking first data of LL
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        // taking remaining data of LL
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
    Solution obj;
   	cout<<obj.isPalindrome(head)<<endl;
    }
    return 0;
}


// } Driver Code Ends