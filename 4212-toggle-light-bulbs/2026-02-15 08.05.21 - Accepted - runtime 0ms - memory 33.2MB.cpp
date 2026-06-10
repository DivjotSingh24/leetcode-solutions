class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
        vector<bool> state(105, false);
        vector<int> result;
        for(int b:bulbs){
            state[b]= !state[b];
        }
        for(int i=1;i<=100;i++){
            if(state[i]==true){
                result.push_back(i);
            }
        }
        return result;
    }
};