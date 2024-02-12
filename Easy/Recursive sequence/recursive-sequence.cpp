//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    long long sequence(int n){
        // code here
          long long cnt=1;
        long long res=0;
        for(int i=0;i<n;i++){
            long long prod=1;
            for(int j=0;j<=i;j++){
                prod=(prod*cnt)%1000000007;
                cnt++;
            }
            
            res=(res+prod)%1000000007;
        }
        return res;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        cout<<ob.sequence(N)<<endl;
    }
    return 0;
}
// } Driver Code Ends