class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        map<int, vector<int>> nindice;

        for (int i = 0; i < arr.size(); i++) {
            nindice[arr[i]].push_back(i);
        }
        int rank = 1;
        for (auto& pair : nindice) {
            for (int index : pair.second) {
                arr[index] = rank;
            }
            rank++;
        }
        return arr;
    }
};