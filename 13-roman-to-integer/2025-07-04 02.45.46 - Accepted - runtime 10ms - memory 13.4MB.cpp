class Solution {
public:
    int romanToInt(string s) {
        int val=0;
        map<char,int>mpp{
            {'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}
        };
        for (int i=0;i<s.length()-1;i++){

            if(mpp[s[i]]<mpp[s[i+1]]){
                val-=mpp[s[i]];
            }
            else{
            val+=mpp[s[i]];}
        }
        val+=mpp[s[s.length()-1]];
        return val;
    }
};