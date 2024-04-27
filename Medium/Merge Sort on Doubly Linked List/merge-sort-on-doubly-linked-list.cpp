//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next, *prev;

    Node(int x) {
        data = x;
        next = NULL;
        prev = NULL;
    }
};


// } Driver Code Ends

/* Structure of the node of the list is as
struct Node
{
    int data;
    struct Node *next, *prev;
    Node (int x){
        data = x;
        next = prev = NULL;
    }
};
*/

class Solution {
    
    struct Node* middle(struct Node* head){
        struct Node* slow = head;
        struct Node* fast = head->next;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    

    struct Node* merge(struct Node* left,struct Node* right){
        if(left==NULL)
            return right;
        if(right==NULL)
            return left;
        struct Node* temp=new struct Node(-1);
        struct Node* ans=temp;
        while(left!=NULL && right!=NULL){
            if(left->data<right->data){
                ans->next=left;
                left->prev=ans;
                ans=left;
                left=left->next;
            }
            else{
                ans->next=right;
                right->prev=ans;
                ans=right;
                right=right->next;
            }
        }
        while(left!=NULL){
            ans->next=left;
            left->prev=ans;
            ans=left;
            left=left->next;
        }
        while(right!=NULL){
            ans->next=right;
            right->prev=ans;
            ans=right;
            right=right->next;
        }
        temp->next->prev=NULL;
        return temp->next;
    }
    
    
    struct Node* mergeSort(struct Node *head) {
        if(head==NULL || head->next==NULL)
            return head;
        
        struct Node* mid=middle(head);
        struct Node* left=head;
        struct Node* right=mid->next;
        mid->next->prev=NULL;
        mid->next=NULL;
        
        left=mergeSort(left);
        right=mergeSort(right);
        
        struct Node* ans=merge(left,right);
        return ans;
        }
    
    
  public:
    // Function to sort the given doubly linked list using Merge Sort.
    struct Node *sortDoubly(struct Node *head) {
        
        return mergeSort(head);

    }
};


//{ Driver Code Starts.

void insert(struct Node **head, int data) {
    struct Node *temp = new Node(data);
    if (!(*head))
        (*head) = temp;
    else {
        temp->next = *head;
        (*head)->prev = temp;
        (*head) = temp;
    }
}

void print(struct Node *head) {
    struct Node *temp = head;
    while (head) {
        cout << head->data << ' ';
        temp = head;
        head = head->next;
    }
    cout << endl;
    while (temp) {
        cout << temp->data << ' ';
        temp = temp->prev;
    }
    cout << endl;
}

// Utility function to swap two integers
void swap(int *A, int *B) {
    int temp = *A;
    *A = *B;
    *B = temp;
}

// Driver program
int main(void) {
    long test;
    cin >> test;
    while (test--) {
        int n, tmp;
        struct Node *head = NULL;
        cin >> n;
        while (n--) {
            cin >> tmp;
            insert(&head, tmp);
        }
        Solution ob;
        head = ob.sortDoubly(head);
        print(head);
    }
    return 0;
}

// } Driver Code Ends