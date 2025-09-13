#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O'
               || c == 'U';
    }


    string sortVowels(string s) {
        vector buckets(60, 0);
        for (int i = 0; i < s.length(); i++) {
            if (isVowel(s[i])) {
                buckets[s[i] - 'A']++;
            }
        }

        int j = 0;

        for (int i = 0; i < s.size(); i++) {
            while (j < buckets.size() && buckets[j] == 0) {
                j++;
            }
            if (j >= buckets.size())break;

            if (isVowel(s[i])) {
                s[i] = j + 'A';
                buckets[j]--;
            }
        }

        return s;
    }
};

int main() {
    Solution s;
    cout << s.sortVowels(
        "lEetcOde");
    return 0;
}
