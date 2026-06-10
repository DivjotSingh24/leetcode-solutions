//Optimal
class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            if (nums[i]==nums[i+1]) return nums[i];
            if (i+2<nums.size() && nums[i]==nums[i+2]) return nums[i];
            if (i+3<nums.size() && nums[i]==nums[i+3]) return nums[i];
        }
        return -1;
    }
};


//Better solution O(n) space
// class Solution {
// public:
//     int repeatedNTimes(vector<int>& nums) {
//         int n=nums.size()/2;
//         unordered_map<int,int> freq;
//         for(int x:nums){
//             freq[x]++;
//             if(freq[x]==n){
//                 return x;
//             }
//         }
//         return -1;
//     }
// };