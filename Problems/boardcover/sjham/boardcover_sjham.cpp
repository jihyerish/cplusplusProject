#include <iostream>
#include <vector>

#define MAX_TYPE_L_BLOCK        (4)
#define NUM_ROOM_L_BLOCK        (3)


using namespace std;

const int L_block_type[MAX_TYPE_L_BLOCK][NUM_ROOM_L_BLOCK][2] = {
                                                                    {{0, 0}, {1, 0}, {0, 1}},
                                                                    {{0, 0}, {0, 1}, {1, 1}}, 
                                                                    {{0, 0}, {1, 0}, {1, 1}}, 
                                                                    {{0, 0}, {1, 0}, {1, -1}} };

bool setBoard(vector<vector<char>>& board, int x, int y, int type, bool bSetType) {
    bool bSet = true;
    for (auto i = 0; i < NUM_ROOM_L_BLOCK; i++) {
        int tgt_x = x + L_block_type[type][i][1];
        int tgt_y = y + L_block_type[type][i][0];

        if (tgt_x < 0 || tgt_x >= board[0].size() || tgt_y < 0 || tgt_y >= board.size())
            bSet = false;
        else if ((board[tgt_y][tgt_x] += (bSetType) ? 1 : -1) > 1)
            bSet = false;
    }
    return bSet;
}

int cal_covered_board(vector<vector<char>>& board) {
    int result = 0;
    int curr_x, curr_y;

    // 최상단 좌측 빈 칸 찾기
    bool bNext = false;

    for (int j = 0; j < board.size() && !bNext; j++) {
        for (int i = 0; i < board[j].size() && !bNext; i++) {
            if (board[j][i] == 0) {
                bNext = true;
                curr_x = i;
                curr_y = j;
            }
        }
    }

    // 빈 칸이 없다면 완벽하게 완성된 Game board이므로 1 리턴
    if (!bNext)    return 1;
    
    for (int c = 0; c < MAX_TYPE_L_BLOCK; c++) {
        if (setBoard(board, curr_x, curr_y, c, true)) {
            result += cal_covered_board(board);
        }
        setBoard(board, curr_x, curr_y, c, false);
    }

    return result;
}

int main()
{
    int tc_num, height, width;
    cin >> tc_num;

    for (auto n = 0; n < tc_num; n++) {
        // Game board의 높이, 넓이 입력
        cin >> height >> width;

        // Game board 입력
        vector<vector<char>> gameboard;
        for (auto i = 0; i < height; i++) {
            vector<char> row;
            for (auto j = 0; j < width; j++) {
                char space;
                cin >> space;
                row.push_back((space == '#') ? 1 : 0);
            }
            gameboard.push_back(row);
        }
        
        // 주어진 게임 규칙에 따라 Game board가 완벽하게 완성되는 경우의 수 계산
        int numcase = cal_covered_board(gameboard);
        cout << numcase << endl;
    }
    return 0;
}
