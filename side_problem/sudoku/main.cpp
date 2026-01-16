#include <iostream>
#include <vector>

class SudokuBoard {
public:
    std::vector<std::vector<int> > board;

    SudokuBoard() : board(9, std::vector<int>(9, 0)) {
    }

    SudokuBoard(const std::vector<std::vector<int> > &initialBoard) {
        if (initialBoard.size() == 9 && initialBoard[0].size() == 9)
            board = initialBoard;
        else
            throw std::invalid_argument("Board must be 9x9");
    }

    void setValue(int row, int col, int value) {
        if (row < 0 || row >= 9 || col < 0 || col >= 9)
            throw std::out_of_range("Invalid cell position");
        if (value < 0 || value > 9)
            throw std::invalid_argument("Value must be 0–9");
        board[row][col] = value;
    }

    int getValue(int row, int col) const {
        if (row < 0 || row >= 9 || col < 0 || col >= 9)
            throw std::out_of_range("Invalid cell position");
        return board[row][col];
    }

    void print() const {
        for (int i = 0; i < 9; ++i) {
            if (i % 3 == 0 && i != 0)
                std::cout << "------+-------+------\n";

            for (int j = 0; j < 9; ++j) {
                if (j % 3 == 0 && j != 0)
                    std::cout << "| ";
                std::cout << board[i][j] << " ";
            }
            std::cout << "\n";
        }
    }

    void fillSample() {
        board = {
            {5, 3, 0, 0, 7, 0, 0, 0, 0},
            {6, 0, 0, 1, 9, 5, 0, 0, 0},
            {0, 9, 8, 0, 0, 0, 0, 6, 0},
            {8, 0, 0, 0, 6, 0, 0, 0, 3},
            {4, 0, 0, 8, 0, 3, 0, 0, 1},
            {7, 0, 0, 0, 2, 0, 0, 0, 6},
            {0, 6, 0, 0, 0, 0, 2, 8, 0},
            {0, 0, 0, 4, 1, 9, 0, 0, 5},
            {0, 0, 0, 0, 8, 0, 0, 7, 9}
        };
    }
};

class SudokuSolver {
    static void solve(SudokuBoard sudoku_board) {
        int x = 9;
        std::vector<std::vector<int>> row;
        std::vector<std::vector<int>> col;
        auto board = sudoku_board.board;
        for (int i = 0; i < x; ++i) {
            for (int j = 0; j < x; ++j) {
                if (board[i][j]) {

                }
            }
        }
    }
};

int main() {
    SudokuBoard board;
    board.fillSample();


    // In bảng
    board.print();

    return 0;
}
