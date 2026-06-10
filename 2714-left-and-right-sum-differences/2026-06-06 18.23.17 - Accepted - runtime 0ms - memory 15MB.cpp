class Solution {
public:
    vector<int> leftRightDifference(vector<int>& arr) {
        int n = arr.size();

        int sum = 0;
        for(int x : arr) sum += x;

        vector<int> ans(n);
        int lsum = 0;

        for(int i = 0; i < n; i++) {
            sum -= arr[i];
            ans[i] = abs(lsum - sum);
            lsum += arr[i];
        }

        return ans;
    }
};