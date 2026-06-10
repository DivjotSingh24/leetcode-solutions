class Solution {
public:
    bool isValid(string word) {
        
int a=0;
int c=0;
        if(word.length()<3){
            return false;
        }
        for (char ch:word){
            ch=tolower(ch);
            if (!(isdigit(ch) || ch>='a' && ch<='z')) {
                return false;
            }
            
            if (ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u'){
                c++;
            }
            else if (ch>='a' && ch<='z'){
                a++;
            }
           
        }
         if (c==0 || a==0){
                return false;
            }
       return true; 
    }
};