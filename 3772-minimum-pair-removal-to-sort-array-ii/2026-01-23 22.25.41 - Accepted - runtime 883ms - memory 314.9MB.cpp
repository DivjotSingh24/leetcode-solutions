class Solution {
public:
    typedef long long ll;
    int minimumPairRemoval(vector<int>& nums) {
        set<pair<ll,int>> minSum;
        int n = nums.size();
        vector<ll> temp(n);
        for(int i = 0; i<n; i++) temp[i] = nums[i];
        vector<int> prevInd(n,-1);
        vector<int> nextInd(n,-1);
        for(int i = 0; i < n; i++){
            prevInd[i] = i-1;
            nextInd[i] = i+1;
        }
        int badPair = 0;
        for(int i = 0; i < n-1; i++){
            if(nums[i] > nums[i+1]) badPair++;
            minSum.insert({temp[i] + temp[i+1],i});
        }
        int op = 0;
        while(badPair > 0){
            int first = minSum.begin()->second;
            int second = nextInd[first];
            int first_left = prevInd[first];
            int second_right = nextInd[second];
            minSum.erase(minSum.begin());
            if(temp[first] > temp[second]) badPair--;
            if(first_left >= 0){
                if(temp[first_left] > temp[first] && temp[first_left] <= temp[first] + temp[second]){
                    badPair--;
                } else if(temp[first_left] <= temp[first] && temp[first_left] > temp[first] + temp[second]){
                    badPair++;
                }
                minSum.erase({temp[first_left] + temp[first],first_left});
                minSum.insert({temp[first_left] + temp[first] + temp[second],first_left});
            }
            if(second_right < n){
                if(temp[second] > temp[second_right] && temp[second] + temp[first] <=  temp[second_right]){
                    badPair--;
                } else if(temp[second] <= temp[second_right] && temp[second] + temp[first] >  temp[second_right]){
                    badPair++;
                }
                minSum.erase({temp[second] + temp[second_right],second});
                minSum.insert({temp[second_right] + temp[first] + temp[second],first});
                prevInd[second_right] = first;
            }
            nextInd[first] = second_right;
            temp[first] += temp[second];
            op++;
        }
        return op;
    }
};