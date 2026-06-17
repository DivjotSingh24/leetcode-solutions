//like the aggressive cows ques
class Solution {
public:
    bool canweplace(vector<int>& position, int dist, int balls){
        int cnt_balls=1;
        int last=position[0];
        for(int i=1;i<position.size();i++){
            if(position[i]-last>=dist){
                cnt_balls++;
                last=position[i];
            }
            if(cnt_balls>=balls)
                return true;
        }
        return false;
    }
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        int low=1;
        int n=position.size();
        int high=position[n-1]-position[0];
        while(low<=high){
            int mid=(low+high)/2;
            if(canweplace(position,mid,m)){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return high; //or we could also use ans where inside if we could write ans=mid;
    }
};