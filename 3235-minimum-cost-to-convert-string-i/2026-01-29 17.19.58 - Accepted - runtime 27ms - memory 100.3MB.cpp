//use floyd warshall algo
class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        int maxi=INT_MAX;
        vector<vector<long long>> dist(26, vector<long long>(26, INT_MAX));
        for(int i=0;i<26;i++){
            dist[i][i]=0;
        }
        for(int i=0;i<original.size();i++){
            int u=original[i]-'a';
            int v=changed[i]-'a';
            dist[u][v]=min(dist[u][v], (long long)cost[i]);
        }
        for(int k=0;k<26;k++){
            for(int i=0;i<26;i++){
                for(int j=0;j<26;j++){
                    if(dist[i][k]<maxi && dist[k][j]<maxi){
                        dist[i][j]=min(dist[i][j], dist[i][k]+dist[k][j]);
                    }
                }
            }
        }
        long long ans=0;
        int n=source.length();
        for(int i=0;i<n;i++){
            int u=source[i]-'a';
            int v=target[i]-'a';
            if(dist[u][v]>=maxi){
                return -1;
            }
            ans+=dist[u][v];
        }
        return ans;
    }
};