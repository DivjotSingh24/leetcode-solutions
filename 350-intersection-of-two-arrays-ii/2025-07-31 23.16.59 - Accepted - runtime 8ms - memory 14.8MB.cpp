class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int>res;
        map<int,int>mpp;
        for (int i=0;i<nums1.size();i++){
            mpp[nums1[i]]++;

        }
        for (int num:nums2){
            if (mpp[num]>0){
                res.push_back(num);
                mpp[num]--;

            }
        }
        return res;
        
    }
};