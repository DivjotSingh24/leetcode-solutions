class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int>res;

        map <int,int>mpp;
        for (int i=0;i<nums1.size();i++){
            mpp[nums1[i]]++;


        }
        map<int,bool>added;
        for (int iter:nums2){
            if (mpp.find(iter)!=mpp.end() && added[iter]==false){
                res.push_back(iter);
                added[iter]=true;
            }
        }
        return res;
    }
};