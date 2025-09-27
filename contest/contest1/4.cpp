
#include <bits/stdc++.h>
using namespace std;

struct cell {
    int row, col;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int h, w;
    cin >> h >> w;

    vector<string> grid(h);
    for (int i = 0; i < h; i++) {
        cin >> grid[i];
    }

    int drow[4] = {-1, 0, 1, 0};
    int dcol[4] = {0, 1, 0, -1};


    vector<vector<int>> is_black(h, vector<int>(w, 0));
    int total_black = 0;

    queue<cell> work_queue;


    for (int r = 0; r < h; r++) {
        for (int c = 0; c < w; c++) {
            if (grid[r][c] == '#') {
                is_black[r][c] = 1;
                total_black++;


                for (int k = 0; k < 4; k++) {
                    int nr = r + drow[k];
                    int nc = c + dcol[k];
                    if (nr >= 0 && nr < h && nc >= 0 && nc < w && grid[nr][nc] == '.') {
                        work_queue.push({nr, nc});
                    }
                }
            }
        }
    }

    while (!work_queue.empty()) {
        vector<cell> to_flip; 
        set<pair<int,int>> next_candidates; 

        
        while (!work_queue.empty()) {
            cell cur = work_queue.front();
            work_queue.pop();

            if (is_black[cur.row][cur.col]) continue; 

            int black_neighbors = 0;
            for (int k = 0; k < 4; k++) {
                int nr = cur.row + drow[k];
                int nc = cur.col + dcol[k];
                if (nr >= 0 && nr < h && nc >= 0 && nc < w && is_black[nr][nc]) {
                    black_neighbors++;
                }
            }

            if (black_neighbors == 1) {
                to_flip.push_back(cur);
            }
        }


        for (auto cell : to_flip) {
            is_black[cell.row][cell.col] = 1;
            total_black++;

            
            for (int k = 0; k < 4; k++) {
                int nr = cell.row + drow[k];
                int nc = cell.col + dcol[k];
                if (nr >= 0 && nr < h && nc >= 0 && nc < w && !is_black[nr][nc]) {
                    next_candidates.insert({nr, nc});
                }
            }
        }

        
        for (auto [r, c] : next_candidates) {
            work_queue.push({r, c});
        }
    }

    cout << total_black <<endl;
    return 0;
}
