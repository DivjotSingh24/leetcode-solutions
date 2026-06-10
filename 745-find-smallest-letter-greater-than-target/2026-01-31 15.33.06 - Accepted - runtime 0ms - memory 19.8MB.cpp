class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int low=0;
        int ans=0;
        int high=letters.size()-1;
        while(low<=high){
            int mid=low + (high - low) / 2;
            if(letters[mid]>target){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return letters[ans];
    }
};



//NOT SO OPTIMAL BUT BRUTE
// class Solution {
// public:
//     char nextGreatestLetter(vector<char>& letters, char target) {
//        char ans=letters[0];
//        bool flag=false;
//        for(char ch : letters){
//         if(!flag){
//             if(ch>target){
//                 ans=ch;
//                 flag=true;
//             }
//         }
//         else{
//             if(ch>target && ch<ans){
//                 ans=ch;
//             }
//         }
//        } 
//        return ans;
//     }
// };