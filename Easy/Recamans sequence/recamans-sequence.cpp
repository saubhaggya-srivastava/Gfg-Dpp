//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> recamanSequence(int n){
        // code here
           // code here
        unordered_set<int>st;
        vector<int>dp(n+1);
        dp[0]=0;
        st.insert(0);
        for(int i=1;i<=n;i++)
        {
            dp[i]=dp[i-1]-i;
            if(dp[i]<0 || st.find(dp[i])!=st.end()){
                dp[i]=dp[i-1]+i;
            }
            st.insert(dp[i]);
        }
        return dp;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<int> ans = ob.recamanSequence(n);
        for(int i = 0;i < n;i++)
            cout<<ans[i]<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends