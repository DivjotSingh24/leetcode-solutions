class Solution {
public:
    bool hasAlternatingBits(int n) {
        int prev=9;
        while(n>0){
            int bit=n%2;
            n/=2;
            if(prev==9){
                prev=bit;
            }
            else{
                if(bit==prev) return false;
                prev=bit;
            }
        }
        return true;
    }
};