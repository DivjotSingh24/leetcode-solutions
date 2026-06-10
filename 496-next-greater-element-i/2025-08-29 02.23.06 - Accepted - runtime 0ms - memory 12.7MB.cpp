class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector <int>ans;
       stack<int>stk;
       map<int,int>mpp;
       for (int i=0;i<nums2.size();i++){
        while (!stk.empty() && nums2[i]>stk.top()){
            mpp[stk.top()]=nums2[i];
            stk.pop();

        }
        stk.push(nums2[i]);
       }
       for (int  it:nums1){
        if (mpp.find(it)!=mpp.end()){
            ans.push_back(mpp[it]);
        }
        else{
            ans.push_back(-1);
        }
       }
       return ans;
    }
};