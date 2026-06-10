class Solution {
public:
    bool check(const vector<long long>& stations, int r, int k, long long minPower) {
        int n = stations.size();
        vector<long long> add(n, 0);
        long long sum = 0, used = 0;
        for (int i = 0; i <= r && i < n; ++i) {
            sum += stations[i];
        }

        int left = 0, right = r;
        for (int i = 0; i < n; ++i) {
            if (i > 0) {
                right++;
                if (right < n) sum += stations[right] + add[right];
                left = i - r - 1;
                if (left >= 0) sum -= stations[left] + add[left];
            }
            long long curPower = sum;

            if (curPower < minPower) {
                long long need = minPower - curPower;
                if (used + need > k) return false;
                used += need;
                int pos = min(n - 1, i + r);
                add[pos] += need;
                sum += need;
            }
        }
        return true;
    }

    long long maxPower(vector<int>& stations, int r, int k) {
        int n = stations.size();
        vector<long long> stationsLL(stations.begin(), stations.end());

        long long left = 0, right = 0;
        for (auto x : stationsLL) right += x;
        right += k; 

        long long result = 0;
        while (left <= right) {
            long long mid = left + (right - left) / 2;
            if (check(stationsLL, r, k, mid)) {
                result = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return result;
    }
};
