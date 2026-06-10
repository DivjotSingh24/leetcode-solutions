class Solution {
public:
    static bool cmp (vector<int> &a,vector<int> &b){
        return a[1]<b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),cmp);
        int start = intervals[0][0];
        int end = intervals[0][1];
        int n = intervals.size();
        int count = 0;
        for(int i = 1;i<n;i++){
            int currs = intervals[i][0];
            int curre = intervals[i][1];
            if(currs<end){
                count++;
            }
            else{
                start = currs;
                end = curre;
            }
        }
        return count;
    }
};