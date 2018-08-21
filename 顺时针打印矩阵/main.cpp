class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        vector<int> result;
        if(row==0 || col==0) return result;
        int topRow=0, topCol=0, botRow=row-1, botCol=col-1;
        while(topRow<=botRow && topCol<=botCol) {
            for(int i=topCol; i<=botCol; ++i) result.push_back(matrix[topRow][i]);
            for(int i=topRow+1; i<=botRow; ++i) result.push_back(matrix[i][botCol]);
            if(topRow!=botRow) {
                for(int i=botCol-1; i>=topCol; --i) result.push_back(matrix[botRow][i]);
            }
            if(topCol!=botCol) {
                for(int i=botRow-1; i>=topRow+1; --i) result.push_back(matrix[i][topCol]);
            }
            ++topRow; ++topCol; --botRow; --botCol;
        }
        return result;
    }
};
