//{ Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution{
    public:
    /* Should return minimum distance between a and b
    in a tree with given root*/
    int findDist(Node* root, int a, int b) {
       unordered_map<Node*,Node*>parent;
       unordered_map<int,int>vis;
       Node* node = NULL;
       parent[root] = NULL;
       help(parent,vis,root,a,&node);
       
       return help1(parent,vis,node,b);
    }
    void help(unordered_map<Node*,Node*>&parent,unordered_map<int,int>&vis,Node*root,int a, Node**node)
    {
        if(root == NULL)
        {
            return;
        }
        vis[root->data] = 0;
        if(root->data == a)
        {
            *node = root;
        }
        if(root->left!= NULL)
        {
            parent[root->left] = root;
            help(parent,vis,root->left,a,node);
        }
        if(root->right!= NULL)
        {
            parent[root->right] = root;
            help(parent,vis,root->right,a,node);
        }
    }
    int help1(unordered_map<Node*,Node*>&parent,unordered_map<int,int>&vis,Node* root , int b)
    {
        if(root == NULL)
        {
            return 1e9;
        }
        vis[root->data] = 1;
        if(root->data == b)
        {
            return 0;
        }
        int lef = 1e9;
        int rig = 1e9;
        int par = 1e9;
        if(root->left!= NULL && vis[root->left->data] == 0)
        {
            lef = 1 + help1(parent,vis,root->left,b);
        }
         if(root->right!= NULL && vis[root->right->data] == 0)
        {
            rig = 1 + help1(parent,vis,root->right,b);
        }
        if(parent[root]!=NULL && vis[parent[root]->data] == 0)
        {
            par = 1+help1(parent,vis,parent[root],b);
        }
        return min(lef,min(rig,par));
    }
};

//{ Driver Code Starts.

/* Driver program to test size function*/

  

int main() {

   
    int t;
    scanf("%d ", &t);
    while (t--) {
        string s, ch;
        getline(cin, s);
        
        Node* root = buildTree(s);
        int n1, n2;
        scanf("%d %d ", &n1, &n2);
        Solution ob;
        cout << ob.findDist(root, n1, n2) << endl;
     
    }
    return 0;
}

// } Driver Code Ends