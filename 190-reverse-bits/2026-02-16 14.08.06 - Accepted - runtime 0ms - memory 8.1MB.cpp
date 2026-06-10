class Solution {
public:
    int reverseBits(int n) {
       int res=0;
       for(int i=0;i<32;i++){
        res<<=1;   //shift it to left
        res|=(n&1);  //take last bit by AND operator
        n>>=1;   //shift n right
       } 
       return res;
    }
};