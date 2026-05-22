#include <iostream>
#include <string>
#include <unordered_map>
#include <climits>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        int l = 0;
        int r = 0;
        int initialWindow = t.size();
        int maximumSize = s.size();
        unordered_map<int, string> mpp;

        while (r <= maximumSize) {
            string substring = s.substr(l, r - l);  

            if (containsAllCharacters(substring, t)) {
                mpp[substring.size()] = substring;
                l++;
                r = l + initialWindow;  
            } else {
                r++;
            }
        }

        int minString = INT_MAX;
        for (auto it : mpp) {
            if (it.first < minString) {
                minString = it.first;
            }
        }

        return minString != INT_MAX ? mpp[minString] : "";
    }

private:
    bool containsAllCharacters(const string& substring, const string& t) {
        unordered_map<char, int> tFreq, windowFreq;
        for (char c : t) tFreq[c]++;
        for (char c : substring) windowFreq[c]++;
        
        for (auto it : tFreq) {
            if (windowFreq[it.first] < it.second) {
                return false;
            }
        }
        return true;
    }
};

