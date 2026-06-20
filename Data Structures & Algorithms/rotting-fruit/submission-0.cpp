class Solution {

public:
    int orangesRotting(vector<vector<int>>& grid) {
        // vector<vector<vector<int>>> timelapse[2][grid.size()][grid[0].size()];
        // timelapse[0] = grid;

        int rows = grid.size();
        int cols = grid[0].size();
        queue<pair<int, int>> q;
        int fresh = 0;

        
        for(int r =0; r< rows; ++r){
            for(int c = 0; c< cols; ++c){
                if(grid[r][c] == 2){
                    q.push({r,c});

                } else if(grid[r][c] == 1) fresh++;
            }
        }
        if (fresh == 0) return 0;

        int min = 0;
        vector<pair<int,int>> dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}};

        while(!q.empty() && fresh>0){
            int size = q.size();
            min++;

            while(size--){
                auto [r, c] = q.front();
                q.pop();
                for (auto [dr, dc] : dirs) {
                    int nr = r + dr;
                    int nc = c + dc;

                    if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && grid[nr][nc] == 1) {
                        grid[nr][nc] = 2;
                        fresh--;
                        q.push({nr, nc});
                    }


                }
            }


        }



        

        return fresh == 0? min : -1 ;

        
    }
};
