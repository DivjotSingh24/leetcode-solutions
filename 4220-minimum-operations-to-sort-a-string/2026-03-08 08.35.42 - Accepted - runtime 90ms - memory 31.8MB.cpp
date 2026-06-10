class Solution {
public:
    int minOperations(string s) {
        int n=s.size();
        string t=s;
        sort(t.begin(),t.end());
        if(s==t) return 0;
        if(n==2) return -1;
        int l=0, r=n-1;
        while(s[l]==t[l]) l++;
        while(s[r]==t[r]) r--;
        if(l>0 || r<n-1) return 1;
        bool startMax=true;
        for(int i=1;i<n;i++){
            if(s[i]>=s[0]){
                startMax=false;
                break;
            }
        }
        bool endMin=true;
        for(int i=0;i<n-1;i++){
            if(s[i]<=s[n-1]){
                endMin=false;
                break;
            }
        }
        if(startMax && endMin){
            return 3;
        }
        else{
            return 2;
        }
    }
};