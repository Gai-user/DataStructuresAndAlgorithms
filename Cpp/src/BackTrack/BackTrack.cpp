#include <vector>
#include "BackTrack.h"

/**
 * 八皇后问题
 * @param row 在哪一行放置棋子
 * @param position 记录八皇后问题的一个解
 * @return 八皇后问题的一个解
 */
void BackTrack::EightQueens(int row, std::vector<std::vector<int>>& result)
{
    if (row == 8) {
        result.push_back(position);
        return;
    }
    
    // 判断在当前行的哪一列放置棋子
    for (int col = 0; col < 8; col++) {
        if (CanPlaceQueen(row, col)) {
            position[row] = col;
            EightQueens(row+1, result);
        }
    }
}

bool BackTrack::CanPlaceQueen(int row, int col)
{
    // 当前行没有放置棋子，我们只需要判断当前列以及对角线有没有棋子
    int leftCol = col - 1;
    int rightCol = col + 1;
    for (int curRow = row - 1; curRow >= 0; curRow--) {
        if (position[curRow] == col) {
            return false;
        }
        if (leftCol >= 0 && position[curRow] == leftCol) {
            return false;
        }
        if (rightCol < 8 && position[curRow] == rightCol) {
            return false;
        }
        leftCol--;
        rightCol++;
    }
    return true;
}