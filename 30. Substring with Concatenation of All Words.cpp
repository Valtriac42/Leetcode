#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        if(s.empty() || words.empty()) {
            return {};
        }
        int len = words[0].length();
        int arrLen = words.size();
        vector<int> ans;
        unordered_map<string, int> toVisit;
        for(string i : words) {
            toVisit[i]++;
        }
        for(int i = 0; i < len; i++) {
            int left = i, right = i, count = 0;
            unordered_map<string, int> visited;
            while(right + len <= s.length()) {
                string word = s.substr(right, len);
                right += len;
                
                if(!toVisit.count(word)) {
                    visited.clear();
                    left = right;
                    count = 0;
                } else {
                    visited[word]++;
                    count++;
                    while(visited[word] > toVisit[word]) {
                        string leftWord = s.substr(left, len);
                        visited[leftWord]--;
                        count--;
                        left += len;
                    }
                    if(count == arrLen) {
                        ans.push_back(left);
                    }
                }
            }
        }
        return ans;
    }
};

int main() {
    Solution solution;
    string s;
    cout << "Enter the string: ";
    cin >> s;
    int n;
    cout << "Enter the number of words: ";
    cin >> n;
    vector<string> words(n);
    cout << "Enter the words: ";
    for(int i = 0; i < n; i++) {
        cin >> words[i];
    }
    vector<int> result = solution.findSubstring(s, words);
    cout << "Indices where substring is found: ";
    for(int index : result) {
        cout << index << " ";
    }
    cout << endl;
    return 0;
}
