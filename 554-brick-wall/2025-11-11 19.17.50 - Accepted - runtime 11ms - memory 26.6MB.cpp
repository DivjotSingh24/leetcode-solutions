class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        int n = wall.size();
        unordered_map<long long,long long> mp;
        long long maxiSum = 0;
        for(int i = 0;i<n;i++){
            long long sum = 0;
            for(int j =0;j<wall[i].size()-1;j++){
                sum+=wall[i][j];
                mp[sum]++;
                maxiSum = max(maxiSum,mp[sum]);
            }
        }
        return n-maxiSum;
    }
};