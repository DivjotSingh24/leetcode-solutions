class Solution {
public:
    string mergeCharacters(string s, int k) {
        // int n=s.size();
        while(true){
            bool merge=false;
            for(int i=0;i<s.size();i++){
                for(int j=i+1;j<s.size() && j-i<=k;j++){
                    if(s[i]==s[j]){
                        s.erase(j,1);
                        merge=true;
                        break;
                    }
                }
                if(merge){
                    break;
                }
            }
            if(!merge){
                break;
            }
        }
        return s;
    }
};