class Solution {
public:
    int find_max_index(vector<vector<int>>& mat, int col){
        int n=mat.size();
        int m=mat[0].size();
        int maxi=-1;
        int index=-1;
        for(int i=0;i<n;i++){
            if(mat[i][col]>maxi){
                maxi=mat[i][col];
                index=i;
            }
        }
        return index;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        int low=0;
        int high=m-1;
        while(low<=high){
            int mid=(high+low)/2;
            int maxi_index=find_max_index(mat,mid);
            int left=mid-1 >=0 ? mat[maxi_index][mid-1] : -1;
            int right=mid+1 < m ? mat[maxi_index][mid+1] : -1;
            if(mat[maxi_index][mid]>left && mat[maxi_index][mid]>right){
                return {maxi_index,mid};
            }
            else if(mat[maxi_index][mid]<left){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return {-1,-1};
    }
};