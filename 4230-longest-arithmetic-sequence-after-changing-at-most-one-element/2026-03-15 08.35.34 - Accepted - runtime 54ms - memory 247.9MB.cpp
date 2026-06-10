class Solution {
public:
    int longestArithmetic(vector<int>& arr) {
        int n=arr.size();
        if(n<=2){
            return n;
        }
        vector<int> diff;
        for(int i=0;i<n-1;i++){
            diff.push_back(arr[i+1]-arr[i]);
        }
        int m=diff.size();
        vector<int> l(m,1);
        for(int i=1;i<m;i++){
            if(diff[i]==diff[i-1]){
                l[i]=l[i-1]+1;
            }
        }
        vector<int> r(m,1);
        for(int i=m-2;i>=0;i--){
            if(diff[i]==diff[i+1]){
                r[i]=r[i+1]+1;
            }
        }
        int ans=0;
        for(int i=0;i<m;i++){
            ans=max(ans,l[i]+2);
        }
        
        for(int k=0;k<m-1;k++){
            int tot=diff[k]+diff[k+1];
            if(tot%2==0){
                int d=tot/2;
                int curr=3;
                // int l=k-1;
                if(k>0 && diff[k-1]==d){
                    curr+=l[k-1];
                }
                if(k+2 <m && diff[k+2]==d){
                    curr+=r[k+2];
                }
                ans=max(ans,curr);
            }
        }
        return min(ans,n);
    }
};