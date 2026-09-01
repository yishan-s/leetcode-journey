# include <iostream>
# include <vector>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix = strs[0]; 

        for (int i = 1; i < strs.size(); i++) {
            int j = 0;
            
            while (j < prefix.length() && j < strs[i].length() && prefix[j] == strs[i][j]) {
                j++;
            }
            
            prefix = prefix.substr(0, j);
            
            if (prefix == "") {
                return "";
            }
        }
        
        return prefix;
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