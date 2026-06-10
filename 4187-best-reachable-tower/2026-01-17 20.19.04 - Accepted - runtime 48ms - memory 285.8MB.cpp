class Solution {
public:
    vector<int> bestTower(vector<vector<int>>& towers, vector<int>& center, int radius) {
        vector<array<int,3>> possible;
        int cx=center[0], cy=center[1];
        for(int i=0;i<towers.size();i++){
            int x=towers[i][0];
            int y=towers[i][1];
            int z=towers[i][2];
            int dist=abs(x-cx)+abs(y-cy);
            if(dist<=radius)
                possible.push_back({-z,x,y});
        }
        if(possible.empty())
            return{-1,-1};
        sort(possible.begin(),possible.end());
        return{possible[0][1], possible[0][2]};
    }
};