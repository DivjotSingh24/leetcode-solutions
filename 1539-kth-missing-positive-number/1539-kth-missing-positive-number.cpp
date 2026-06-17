class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int low = 0;
        int high = arr.size() - 1;

        while (low <= high) {
            int mid = (low + high) / 2;
            int missing = arr[mid] - (mid + 1);
            if (missing < k) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return low + k; // we got this from high+1+k 
        //arr[high]+more where more is k - missing andd missing is arr[high]-(high+1)
        // hence we get high+1+k
    }
};
