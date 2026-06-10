class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = (int)heights.size();
        vector<int> prefixSum(n, 0), suffixSum(n, 0);
        stack<int> st;

        for (int i = 0; i < n; ++i) {
            while (!st.empty() && heights[st.top()] >= heights[i]) st.pop();
            prefixSum[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        while (!st.empty()) st.pop();

        for (int i = n - 1; i >= 0; --i) {
            while (!st.empty() && heights[st.top()] >= heights[i]) st.pop();
            suffixSum[i] = st.empty() ? n : st.top(); 
            st.push(i);
        }

        long long ans = 0;
        for (int i = 0; i < n; ++i) {
            long long width = suffixSum[i] - prefixSum[i] - 1;
            ans = max(ans, width * (long long)heights[i]);
        }
        return (int)ans;
    }
};
