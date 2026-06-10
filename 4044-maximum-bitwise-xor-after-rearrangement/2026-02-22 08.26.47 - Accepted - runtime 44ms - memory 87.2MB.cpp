class Solution {
public:
    string maximumXor(string s, string t) {
        int ss=s.size();
        int tt=t.size();
        int c0=0,c1=0;
        for(char c:t){
            if(c=='0'){
                c0++;
            }
            else{
                c1++;
            }
        }
        string ans="";
        for(int i=0;i<ss;i++){
            if(s[i]=='0'){
                if(c1>0){
                    ans+='1';
                    c1--;
                }
                else{
                    ans+='0';
                    c0--;
                }
            }
            else{
                if(c0>0){
                    ans+='1';
                    c0--;
                }
                else{
                    ans+='0';
                    c1--;
                }
            }
        }
        return ans;
    }
};