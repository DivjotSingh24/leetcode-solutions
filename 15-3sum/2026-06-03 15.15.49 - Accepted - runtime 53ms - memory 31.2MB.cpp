class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& arr) {
        int n=arr.size();
        vector<vector<int>> ans;
        sort(arr.begin(),arr.end());
        for(int i=0;i<n;i++){
            if(i>0 && arr[i]==arr[i-1]) continue;
            long long j=i+1;
            long long k=n-1;
            while(j<k){
                long long sum= arr[i]+arr[j]+arr[k];
                if(sum<0){
                    j++;
                }
                else if(sum>0){
                    k--;
                }
                else{
                    vector<int> temp={arr[i],arr[j],arr[k]};
                    ans.push_back(temp);
                    j++;
                    k--;
                    while(j<k && arr[j]==arr[j-1]) j++;
                    while(j<k && arr[k]==arr[k+1]) k--;
                }
            }
        }
        return ans;
    }
};

//brute would be just simply iterating with 3 loops and at the end storing it in a set to prevent duplicates, after which it would be returned in the form of an ans list of arrays
//BETTER-: Reduced from O(N^3) to O(N^2)
// class Solution {
// public:
//     vector<vector<int>> threeSum(vector<int>& nums) {
//         int n=nums.size();
//         set<vector<int>> st;
//         for(int i=0;i<n;i++){
//             set<int> hashset;
//             for(int j=i+1;j<n;j++){
//                 int third= -(nums[i]+nums[j]);
//                 if(hashset.find(third)!=hashset.end()){
//                     vector<int> temp= {nums[i],nums[j],third};
//                     sort(temp.begin(),temp.end());
//                     st.insert(temp);
//                 }
//                 hashset.insert(nums[j]);
//             }
//         }
//         vector<vector<int>> ans(st.begin(),st.end());
//         return ans;
//     }
// };
//BRUTE
// class Solution {
// public:
//     vector<vector<int>> threeSum(vector<int>& nums) {
//         set<vector<int>> st;
//         int n=nums.size();
//         for(int i=0;i<n;i++){
//             for(int j=i+1;j<n;j++){
//                 for(int k=j+1;k<n;k++){
//                     if(nums[i]+nums[j]+nums[k]==0){
//                         vector<int> temp={nums[i],nums[j],nums[k]};
//                         sort(temp.begin(),temp.end());
//                         st.insert(temp);
//                     }
//                 }
//             }
//         }
//         vector<vector<int>> ans(st.begin(),st.end());
//     return ans;
//     }
// };
