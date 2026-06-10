class Solution {
public:
    int almostPalindromic(string s) {
        int n=s.length();
        if(n<=1) return n;
        int maxi=1;
        for(int i=0;i<n;i++){
            if(n-i<=maxi) break;
            for(int j=n-1;j>=i;j--){
                int curr=j-i+1;
                if(curr<=maxi) break;
                int l=i;
                int r=j;
                bool can=true;
                bool used=false;
                while(l<r){
                    if(s[l]==s[r]){
                        l++;
                        r--;
                    }
                    else{
                        if(used){
                            can=false;
                            break;
                        }
                        bool c1=true;
                        int l1=l+1, r1=r;
                        while(l1<r1){
                            if(s[l1++]!=s[r1--]){
                                c1=false;
                                break;
                            }
                        }
                        bool c2=true;
                        int l2=l, r2=r-1;
                        while(l2<r2){
                            if(s[l2++]!=s[r2--]){
                                c2=false;
                                break;
                            }
                        }
                        if(c1 || c2){
                            used=true;
                            break;
                        }
                        else{
                            can=false;
                            break;
                        }
                    }
                }
                if(can){
                    maxi=curr;
                    break;
                }
            }
        }
        return maxi;
        // vector<vector<bool>> val(n,vector<bool>(n.false));
        // for(int i=1;i<=n;i++{
        //     for(int j=0;j<=n;j++){
        //         int m=j+i-1;
        //         if(i==1){
        //             val[i][j]=true;
        //         }
        //     }
        // }
    }
};