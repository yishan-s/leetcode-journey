# include <iostream>
# include <vector>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";

        sort(strs.begin(), strs.end());
        int i = 0;
        while (i < strs.front().length() && i < strs.back().length() && strs.front()[i] == strs.back()[i]) {
            i++; 
        }
        return strs.front().substr(0, i);
    }
};

int main() {
    Solution sol;

    vector<vector<string>> testCases = {
        {"flower", "flow", "flight"},
        {"dog", "racecar", "car"},
        {"interstellar", "interstate", "internet"}, 
        {""},            
        {"a"}        
    };

    for (int i = 0; i < testCases.size(); i++) {
        cout << "Test Case " << i + 1 << ": ";
        
        cout << "[";
        for (int j = 0; j < testCases[i].size(); j++) {
            cout << "\"" << testCases[i][j] << "\"";
            if (j < testCases[i].size() - 1) cout << ", ";
        }
        cout << "] \n";

        string result = sol.longestCommonPrefix(testCases[i]);
        
        cout << "Result: \"" << result << "\"\n";
        cout << "------------------------\n";
    }

    return 0;
}