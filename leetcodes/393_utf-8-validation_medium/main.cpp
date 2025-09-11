#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int getByteCount(int byte) {
        if (byte >> 7 == 0) {
            return 1;
        }
        if (byte >> 6 == 0b10) {
            return -1;
        }
        if (byte >> 5 == 0b110) {
            return 2;
        }
        if (byte >> 4 == 0b1110) {
            return 3;
        }
        if (byte >> 3 == 0b11110) {
            return 4;
        }

        return -1;
    }

    bool isCorrectContinueByte(int byte) {
        if (byte >> 6 == 0b10) {
            return true;
        }
        return false;
    }

    bool validUtf8(vector<int> &data) {
        if (data.size() == 1) {
            if (data[0] <= 127)
                return true;
            return false;
        }


        int i = 0;
        while (i < data.size()) {
            int byteCount = getByteCount(data[i]);
            if (byteCount == -1) {
                return false;
            }

            if (i + byteCount > data.size()) {
                return false;
            }
            for (int j = 1; j < byteCount; j++) {
                if (!isCorrectContinueByte(data[i + j])) {
                    return false;
                }
            }

            i += byteCount;
        }

        return true;
    }
};


int main() {
    // vector input = {197, 130, 1};
    // vector input = {145};
    // vector input = {230, 136, 145};
    vector input = {240, 162, 138, 147, 145};
    Solution s;
    cout << s.validUtf8(input) << endl;

    return 0;
}
