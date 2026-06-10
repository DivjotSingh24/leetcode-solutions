//OPTIMAL, same approach of 4 pointers
//T.C-: O(n2*n)=o(n3), S.C= o(number of quads) it is being returned only to return the ans
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& arr, int target) {
        sort(arr.begin(),arr.end());
        vector<vector<int>> ans;
        int n=arr.size();
        for(int i=0;i<n;i++){
            if(i>0 && arr[i]==arr[i-1]) continue;
            for(int j=i+1;j<n;j++){
                if(j!=i+1 && arr[j]==arr[j-1]) continue;
                int k=j+1;
                int l=n-1;
                while(k<l){
                    long long sum=arr[i];
                    sum+=arr[j];
                    sum+=arr[k];
                    sum+=arr[l];
                    if(sum==target){
                        vector<int> temp={arr[i],arr[j],arr[k],arr[l]};
                        ans.push_back(temp);
                        k++;
                        l--;
                        while(k<l && arr[k]==arr[k-1]) k++;
                        while(k<l && arr[l]==arr[l+1]) l--;
                    }
                    else if(sum<target){
                        k++;
                    }
                    else{
                        l--;
                    }
                }
            }
        }
        return ans;
    }
};


// //Better approach same as 3sum, T.C is O(n3*number of elements in the set), S.C=o(N)+o(quads)*2
// class Solution {
// public:
//     vector<vector<int>> fourSum(vector<int>& nums, int target) {
//         int n=nums.size();
//         set<vector<int>> st;
//         for(int i=0;i<n;i++){
//             for(int j=i+1;j<n;j++){
//                 set<long long> hashset;
//                 for(int k=j+1;k<n;k++){
//                     long long sum=nums[i]+nums[j];
//                     sum+=nums[k];
//                     long long fourth=target-(sum);
//                     if(hashset.find(fourth)!=hashset.end()){
//                         vector<int> temp={nums[i],nums[j],nums[k],(int)fourth};
//                         sort(temp.begin(),temp.end());
//                         st.insert(temp);
//                     }
//                     hashset.insert(nums[k]);
//                 }
//             }
//         }
//         vector<vector<int>> ans(st.begin(),st.end());
//         return ans;
//     }
// };