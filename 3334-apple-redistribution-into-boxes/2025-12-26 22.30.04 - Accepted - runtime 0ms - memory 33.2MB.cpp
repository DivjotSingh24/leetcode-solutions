class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int totalApples=0;
        for(int i=0;i<apple.size();i++){
            totalApples+=apple[i];
        }
        sort(capacity.begin(),capacity.end(),greater<int>());
        int sum=0;
        int boxes=0;
        for(int i=0;i<capacity.size();i++){
            sum+=capacity[i];
            boxes++;
            if(sum>=totalApples){
                break;
            }
        }
        return boxes;
    }
};