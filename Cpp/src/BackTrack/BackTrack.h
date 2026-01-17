#ifndef BACK_TRACK_H
#define BACK_TRACK_H

#include <vector>

class BackTrack {
public:
    BackTrack() = default;
    ~BackTrack() = default;

    void EightQueens(int row, std::vector<std::vector<int>>& result);

private:
    std::vector<int> position = std::vector<int>(8); // 记录棋盘布局
    bool CanPlaceQueen(int row, int col);
};

#endif // BACK_TRACK_H