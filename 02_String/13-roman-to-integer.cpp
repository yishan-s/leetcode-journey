# include <iostream>
# include <unordered_map>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        static unordered_map<char, int> romanToInt = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };
        int res = 0;
        for(int i = 0; i < s.length()-1; i++) {
            if(romanToInt[s[i]] < romanToInt[s[i+1]]) {
                res -= romanToInt[s[i]];
            }
            else {
                res += romanToInt[s[i]];
            }
        }
        res += romanToInt[s[s.length()-1]];
        return res;
    }
};

int main() {
    Solution sol;
    
    vector<string> testCases = {
        "III", 
        "LVIII",   
        "MCMXCIV",  
        "IV",   
        "IX"    
    };

    for (int i = 0; i < testCases.size(); i++) {
        string current_roman = testCases[i];
        int result = sol.romanToInt(current_roman);
        
        cout << "Test Case " << i + 1 << ": " << current_roman << "\n";
        cout << "Result: " << result << "\n";
        cout << "------------------------\n";
    }

    return 0;
}