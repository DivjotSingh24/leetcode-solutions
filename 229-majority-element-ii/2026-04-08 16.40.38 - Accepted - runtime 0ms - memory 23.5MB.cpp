// o(n2) approach would be just traversing each elem and checkting if its total is greater than the constraint and then store it in a list which is the ans
//o(n)+log n approach would be using map but it has a space complexity of o(n) which isnt optimized
// class Solution {
// public:
//     vector<int> majorityElement(vector<int>& nums) {
//         vector<int> ls;
//         map<int,int> mpp;
//         int n=nums.size();
//         int mini=(int) (n/3)+1;
//         for(int i=0;i<n;i++){
//             mpp[nums[i]]++;
//             if(mpp[nums[i]]==mini){
//                 ls.push_back(nums[i]);
//             }
//             if(ls.size()==2) break;
//         }
//         sort(ls.begin(),ls.end());
//         return ls;
//     }
// };
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size(); 
        int cnt1 = 0, cnt2 = 0;
        int el1 = INT_MIN, el2 = INT_MIN;
        for (int i = 0; i < n; i++) {
            
            if (cnt1 == 0 && el2 != nums[i]) {
                cnt1 = 1;
                el1 = nums[i]; 
            }
            else if (cnt2 == 0 && el1 != nums[i]) {
                cnt2 = 1;
                el2 = nums[i]; 
            } 
            else if (nums[i] == el1) {
                cnt1++;
            } 
            else if (nums[i] == el2) {
                cnt2++; 
            } 
            else {
                cnt1--; 
                cnt2--;
            }
        }
        cnt1 = 0, cnt2 = 0; 
        
        for (int i = 0; i < n; i++) {
            if (nums[i] == el1) {
                cnt1++; 
            }
            if (nums[i] == el2) {
                cnt2++;
            }
        }
        int mini = n / 3 + 1;
        vector<int> result; 
        if (cnt1 >= mini) {
            result.push_back(el1);
        }
        if (cnt2 >= mini && el1 != el2) {
            result.push_back(el2); 
        }
        return result;
    }
};