#ifndef BACK_TRACK_H
#define BACK_TRACK_H

#include <vector>
#include <string>
#include <limits>

class BackTrack {
public:
    BackTrack() = default;
    ~BackTrack() = default;

    void EightQueens(int row, std::vector<std::vector<int>>& result);

    int LevenshteinDistance(const std::string& word1, const std::string& word2);

private:
    void LevenshteinDistanceHelper(const std::string& word1, const std::string& word2, int i, int j, int count);
    std::vector<int> position = std::vector<int>(8); // 记录棋盘布局
    bool CanPlaceQueen(int row, int col);
    int MaxValue = std::numeric_limits<int>::max();

};

#endif // BACK_TRACK_H