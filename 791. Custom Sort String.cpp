#include <iostream>
#include <unordered_map>
#include <string>

class Solution {
public:
    std::string customSortString(std::string order, std::string s) {
        std::unordered_map<char, int> charCount;
        for (char c : order) {
            charCount[c] = 0;
        }
        
        for (char c : s) {
            if (charCount.find(c) != charCount.end()) {
                charCount[c]++;
            }
        }
        
        std::string sortedS;
        for (char c : order) {
            sortedS.append(charCount[c], c);
        }
        
        for (char c : s) {
            if (charCount.find(c) == charCount.end()) {
                sortedS.push_back(c);
            }
        }
        
        return sortedS;
    }
};

int main() {
    std::string order, s;
    std::cout << "Enter order string: ";
    std::cin >> order;
    std::cout << "Enter string to sort: ";
    std::cin >> s;

    Solution obj;
    std::string result = obj.customSortString(order, s);
    std::cout << "Sorted string: " << result << std::endl;

    return 0;
}
