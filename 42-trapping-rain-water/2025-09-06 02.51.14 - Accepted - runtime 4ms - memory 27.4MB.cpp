class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;
        vector<int> prefixSum(height.size(), 0);
        vector<int> suffixSum(height.size(), 0);

        prefixSum[0] = 0;
        for(int i =1;i<height.size();i++){
            prefixSum[i] = max(prefixSum[i-1], height[i-1]);
        }
        suffixSum[height.size()-1] = 0;
        for(int i =height.size()-2;i>=0;i--){
            suffixSum[i] = max(suffixSum[i+1], height[i+1]);
        }
        for(int i =0;i<height.size();i++){
            int leftMax = prefixSum[i];
            int rightMax = suffixSum[i];
            if(height[i]<leftMax && height[i]<rightMax){
                ans += min(leftMax, rightMax) - height[i];
            }
        }
        return ans;
    }
};