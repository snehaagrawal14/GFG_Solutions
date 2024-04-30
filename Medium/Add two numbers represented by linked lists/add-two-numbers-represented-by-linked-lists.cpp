//{ Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    
    struct Node* reverse(struct Node* head){
        if(!head)
            return head;
            
        struct Node* prev = NULL;
        struct Node* curr = head;
        struct Node* next = NULL;
        while(curr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    
    public:
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* num1, struct Node* num2)
    {
        
        num1 = reverse(num1);
        num2 = reverse(num2);
        struct Node* a = num1;
        struct Node* b = num2;
        struct Node* ans = new struct Node(-1);
        struct Node* temp = ans;
        int carry = 0;
        while(a || b){
            int n1 = (a)?a->data:0;
            int n2 = (b)?b->data:0;
            int sum = n1 + n2 + carry;
            struct Node* newnode = new struct Node(sum%10);
            carry = sum/10;
            temp->next = newnode;
            temp = temp->next;
            a = (a)?a->next:a;
            b = (b)?b->next:b;
        }
        if(carry){
            struct Node* newnode = new struct Node(carry);
            temp->next = newnode;
            temp = temp->next;
        }
        
        ans = reverse(ans->next);
        while(ans->next && ans->data == 0)
            ans = ans->next;
        
        return ans;
        
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* num1 = buildList(n);
        
        cin>>m;
        Node* num2 = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(num1,num2);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends