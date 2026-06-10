class Solution {
public:
    int minimumOR(vector<vector<int>>& grid) {
        int curr=(1<<17)-1;
        for(int b=16;b>=0;b--){
            int target=curr^(1<<b);
            bool can=true;
            for(const auto& row: grid){
                bool ok=false;
                for(int x:row){
                    if((x| target)==target){
                        ok=true;
                        break;
                    }
                }
                if(!ok){
                    can=false;
                    break;
                }
            }
            if(can){
                curr=target;
            }
        }
        return curr;
    }
};