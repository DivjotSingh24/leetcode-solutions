class Solution {
public:
    string findDifferentBinaryString(vector<string>& arr) {
        int n=arr.size();
        string ans="";
        for(int i=0;i<n;i++){
            if(arr[i][i]=='0'){
                ans+='1';
            }
            else{
                ans+='0';
            }
        }
        return ans;
    }
};