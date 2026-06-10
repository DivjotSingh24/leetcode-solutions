class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> result;
        for (int num : nums) {
            int found = -1;
            for (int x = 0; x <= num; x++) {
                if ( (x | (x + 1)) == num ) {
                    found = x;
                    break; 
                }
            }

            result.push_back(found);
        }

        return result;
    }
};
