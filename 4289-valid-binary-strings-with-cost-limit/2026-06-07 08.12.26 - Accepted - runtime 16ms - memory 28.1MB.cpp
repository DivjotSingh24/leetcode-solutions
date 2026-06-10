class Solution {
public:
    vector<string> generateValidStrings(int n, int k) {
        vector<string> ans;
        for(int msk=0;msk<(1<<n);msk++){
            int c=0;
            bool can=true;
            string s;
            for(int i=0;i<n;i++){
                if(msk & (1<<i)){
                    c+=i;
                    if(i>0 && (msk&(1<<(i-1)))){
                        can=false;
                        break;
                    }
                }
            }
            if(!can || c>k){
                continue;
            }
            for(int i=0;i<n;i++){
                if(msk&(1<<i)){
                    s.push_back('1');
                }
                else{
                    s.push_back('0');
                }
            }
            ans.push_back(s);
        }
        return ans;
    }
};