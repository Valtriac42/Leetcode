#include <iostream>
#include <cmath>

class Solution {
public:
    int pivotInteger(int n) {
        int sum = n * (n + 1) / 2;
        double a = sqrt(sum);

        if (a - ceil(a) == 0)
            return int(a);
        else
            return -1;
    }
};

int main() {
    int n;
    std::cout << "Enter a positive integer: ";
    std::cin >> n;

    Solution solution;
    int result = solution.pivotInteger(n);
    if (result != -1)
        std::cout << "The pivot integer is: " << result << std::endl;
    else
        std::cout << "No pivot integer exists for the given input." << std::endl;

    return 0;
}
