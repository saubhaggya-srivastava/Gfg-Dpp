//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// Node Class
class Node {
public:
    int data;
    Node* next;

    Node(int val) : data(val), next(NULL) {}
};

// Linked List Class
class LinkedList {
public:
    Node* head;
    Node* tail;

    LinkedList() : head(NULL), tail(NULL) {}

    // creates a new node with given value and appends it at the end of the linked list
    void insert(int val) {
        if (head == NULL) {
            head = new Node(val);
            tail = head;
        } else {
            tail->next = new Node(val);
            tail = tail->next;
        }
    }
};


// } Driver Code Ends
//User function Template for C++


class Solution {
public:
    string num(Node * head){
        string res = "";
        while(head!= NULL and head->data == 0){
            head = head->next;
        }
        while(head!=NULL){
            int x = head->data;
            res += to_string(x);
            head = head->next;
        }
        return res;
    }
    Node* subLinkedList(Node* head1, Node* head2) {
        // Your implementation of subLinkedList goes here
        // Make sure to return the head of the resulting linked list
        string s1 = num(head1);
        string s2 = num(head2);
        string s3 = "";
        
       
        if(s1.size()<s2.size()) swap(s1, s2);
        if(s1.size()==s2.size()){
            int i=0, j=0;
            while(i<s1.size() and j<s2.size()){
                if(s1[i]==s2[j]){
                    i++;
                    j++;
                }
                else break;
            }
            if(i==s1.size()){
                Node * head = new Node(0);
                return head;
            }
            if(s1[i]<s2[j]) swap(s1,s2);
        }
        int m = s1.size(), n=s2.size();
        
        int i=m-1, j=n-1;
        int carry = 0;
        
        
        Node * curr = NULL;
        
        while(i>=0 or j>=0){
            int f = i>=0 ? (s1[i]-'0') : 0;
            int s = j>=0 ? (s2[j]-'0') : 0;
            s = s + carry;
            if(f>=s){
                int temp = f-s;
                carry=0;
                Node * nn = new Node(temp);
                nn->next = curr;
                curr = nn;
            }
            else{
                f = f+ 10;
                int temp = f-s;
                carry = 1;
                Node * nn = new Node(temp);
                nn->next = curr;
                curr = nn;
            }
            i--;
            j--;
        }
        while(curr->next!=NULL and curr->data==0) curr = curr->next;
        return curr;
    }
};


//{ Driver Code Starts.

// prints the elements of linked list starting with head
void printList(Node* n) {
    while (n) {
        cout << n->data;
        n = n->next;
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        int n;
        cin >> n;
        LinkedList LL1;
        string l1,l2;
        cin>>l1;
        for (int j = 0; j < n; ++j) {
            int x=(l1[j]-'0');
            LL1.insert(x);
        }

        int m;
        cin >> m;
        LinkedList LL2;
        cin>>l2;
        for (int j = 0; j < m; ++j) {
            int x=(l2[j]-'0');
            LL2.insert(x);
        }

        Solution ob;
        Node* res = ob.subLinkedList(LL1.head, LL2.head);
        printList(res);
    }

    return 0;
}

// } Driver Code Ends