class Solution {
public:

    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<vector<int>> prefSum(matrix.size(), vector<int>(matrix[0].size(),0));
        for(int j = 0; j < matrix[0].size(); j++){
            int sum = 0;
            for(int i = 0; i < matrix.size(); i++){
                if(matrix[i][j] == '0') sum = 0;
                sum += matrix[i][j] - '0';
                prefSum[i][j] = sum;
            }
        }
        cout<<"1"<<endl;
        int ans = 0;
        for(int i = 0; i < prefSum.size(); i++){
            int n = prefSum[i].size();
            vector<int> prefix(n);
            vector<int> suffix(n);
            stack<int> mono;
            for(int j = 0; j < prefSum[0].size(); j++){
                while(!mono.empty() && prefSum[i][mono.top()] >= prefSum[i][j] ){
                    mono.pop();
                }
                if(mono.empty()){
                    prefix[j] = -1;
                }else{
                    prefix[j] = mono.top();
                }
                mono.push(j);
            }
            cout<<"2"<<endl;
            mono = stack<int>();

            for(int j = prefSum[0].size()-1; j >= 0; j--){
                while(!mono.empty() && prefSum[i][mono.top()] >= prefSum[i][j] ){
                    mono.pop();
                }
                if(mono.empty()){
                    suffix[j] = prefSum[0].size();
                }else{
                    suffix[j] = mono.top();
                }
                mono.push(j);
            }
            cout<<"3"<<endl;
            for(int j = 0; j < prefSum[0].size(); j++){
                int area = prefSum[i][j] * (suffix[j] - prefix[j] - 1);
                ans = max(ans, area);
            }
        }
        return ans;

    }
};