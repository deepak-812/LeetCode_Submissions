class Solution { // O(n) and Space Complexity O(1)
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int i=0;
        for(int i=0;i<n/2;i++){
            for(int j=i;j<n-i-1;j++){
                swap(matrix[i][j],matrix[n-j-1][i]);
                swap(matrix[n-j-1][i],matrix[n-i-1][n-j-1]);
                swap(matrix[n-i-1][n-j-1],matrix[j][n-i-1]);
            }
        }
    }
};
