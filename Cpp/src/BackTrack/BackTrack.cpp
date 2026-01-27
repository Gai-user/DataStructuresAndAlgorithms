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

int BackTrack::LevenshteinDistance(const std::string& word1, const std::string& word2) 
{
    MaxValue = std::numeric_limits<int>::max();
    LevenshteinDistanceHelper(word1, word2, 0, 0, 0);
    return MaxValue;
}

void BackTrack::LevenshteinDistanceHelper(const std::string& word1, const std::string& word2, int i, int j, int count) 
{
    if (i == word1.size() || j == word2.size()) {
        if (i < word1.size()) { count += word1.size() - i;}
        if (j < word2.size()) { count += word2.size() - j;}
        if (count < MaxValue) { MaxValue = count;}
        return;
    }

    if (word1[i] == word2[j]) {
        LevenshteinDistanceHelper(word1, word2, i+1, j+1, count);
    } else {
        LevenshteinDistanceHelper(word1, word2, i+1, j, count+1); // 删除 word1[i] 或者在 word2[j] 前面加 word1[i]
        LevenshteinDistanceHelper(word1, word2, i, j+1, count+1); // 删除 word2[j] 或者在 word1[i] 前面加 word2[j]
        LevenshteinDistanceHelper(word1, word2, i+1, j+1, count+1); // 将 word1[i] 与 word2[j] 替换为相同的字符
    }
}