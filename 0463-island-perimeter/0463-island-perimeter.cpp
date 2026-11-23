class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int row=grid.size();
        int col=grid[0].size();
        int count=0;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]==1){
                    if(i>0 && grid[i-1][j]==0||i==0){
                        count+=1;
                    }
                    if(j<col-1 && grid[i][j+1]==0||j==col-1){
                        count+=1;
                    }
                    if(i<row-1 && grid[i+1][j]==0||i==row-1){
                        count+=1;
                    }
                    if(j>0 && grid[i][j-1]==0||j==0){
                        count+=1;
                    }
                }
            }

        }
        return count;
    }
};