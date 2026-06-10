class Solution {
public:
    string reverseByType(string s) {
        int n=s.size();

        //reverse letters
        int i=0, j=n-1;
        while(i<=j){
            if(isalpha(s[i]) && isalpha(s[j])){
                swap(s[i++],s[j--]);
            }
            else if(isalpha(s[i])){
                j--;
            }
            else if(isalpha(s[j])){
                i++;
            }
            else{
                i++;
                j--;
            }
        }

        //reverse special
        i=0, j=n-1;
        while(i<=j){
            if(!isalpha(s[i]) && !isalpha(s[j])){
                swap(s[i++],s[j--]);
            }
            else if(!isalpha(s[i])){
                j--;
            }
            else if(!isalpha(s[j])){
                i++;
            }
            else{
                i++;
                j--;
            }
        }
        return s;
    }
};