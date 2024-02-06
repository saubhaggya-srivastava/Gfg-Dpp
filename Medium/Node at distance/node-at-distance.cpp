//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}



// Function to Build Tree
Node* buildTree(string str)
{
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if(currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if(currVal != "N") {

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
//Node Structure
/*struct Node
{
	int k;
	Node *left, *right;
};*/

class Solution
{
    public:
    //Function to return count of nodes at a given distance from leaf nodes.
    int solve(Node*root,int k){
        if(root==NULL)return 0;
        int t1 = solve(root->left,k);
        int t2 = solve(root->right,k);
        queue<Node*>q;
        q.push(root);
        bool f=false;
        int t = 0;
        int ctu = 0;
        while(((!q.empty() and t<k)||k==0) and (!q.empty())){
            int s = q.size();
            for(int i=0;i<s;i++){
                Node*ptr = q.front();
                q.pop();
                if(ptr->left){
                    q.push(ptr->left);
                }
                if(ptr->right){
                    q.push(ptr->right);
                }
                if(!ptr->left and !ptr->right){
                    ctu++;
                }
            }
            t++;
            if(t==k){
                while(q.size()>0){
                    Node*p = q.front();
                    if(!p->left and !p->right){
                        f=true;
                        break;
                    }
                    q.pop();
                }
                break;
            }
        }
        if(k==0)return ctu;
        if(f){
            return 1+t1+t2;
        }
        return t1+t2;
    }
    int printKDistantfromLeaf(Node* root, int k)
    {
    	//Add your code here. 
    	
    	return solve(root,k);
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    string tc;
    getline(cin, tc);
    t=stoi(tc);
    while(t--)
    {
        string s, ks;
        getline(cin, s);
        Node* root = buildTree(s);
        getline(cin, ks);
        int k=stoi(ks);
        Solution obj;
        cout<<obj.printKDistantfromLeaf(root, k)<<endl;
    }
    return 0;
}


// } Driver Code Ends