class Solution {
public:
typedef long long ll;
unordered_map<ll,int>dp;
int solve(ll i , ll mask , ll change , int k , string &s , int n){
    if(i==n) return 1;
    ll curr = (i<<27)|(mask<<1)|(change);
    if(dp.find(curr)!=dp.end()) return dp[curr];
    ll new_mask = mask|(1<<(s[i]-'a'));
    int count = __builtin_popcount(new_mask);
    int maxi = 0;
    if(count>k){
        maxi = max(1 + solve(i+1 , (1<<(s[i]-'a')) , change , k , s , n),maxi);
    }
    else{
        maxi = max(solve(i+1 , new_mask , change , k , s , n),maxi);
    } 
    if(change) return dp[curr] = maxi;
    for(int j=0;j<26;j++){
        new_mask = mask|(1<<j);
        count = __builtin_popcount(new_mask);
        if(count>k){
        maxi = max(1 + solve(i+1 , (1<<j) , 1 , k , s , n),maxi);
        }
        else{
        maxi = max(solve(i+1 , new_mask , 1 , k , s , n),maxi);
        }
    }
    return dp[curr] = maxi;
}
    int maxPartitionsAfterOperations(string s, int k) {
        int n = s.size();
        return solve(0,0,0,k,s,n);
    }
};