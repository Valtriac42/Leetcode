#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int fcn(vector<char>& A) {
        if(A.size() <= 1)
            return A.size();

        int i = 0, j = 1;
        int suff = 0, pre = 0;

        while(true) {
            if(A[i] == A[j]) {
                pre = pre + 1;
                j = j + 1;
            } else {
                break;
            }
            if(j >= A.size())
                break;
        }
        
        i = A.size() - 1;
        j = i - 1;
        
        while(true) {
            if(A[i] == A[j]) {
                suff = suff + 1;
                j = j - 1;
            } else {
                break;
            }
            if(j <= 0)
                break;
        }

        vector<char> A1;
        
        if(pre == A.size() - 1)
            return 0;
        else if(A[0] == A[A.size() - 1]) {
            i = pre + 1;
            j = A.size() - suff - 1;
            while(true) {
                A1.push_back(A[i]);
                i = i + 1;
                if(i == j)
                    break;
            }
            return fcn(A1);
        } else {
            return A.size();
        }
    }
    
    int minimumLength(string s) {
        vector<char> A;
        for(int i = 0; i < s.length(); ++i) {
            A.push_back(s[i]);
        }
        int a = fcn(A);
        return a;
    }
};

int main() {
    Solution obj;
    string input;
    cout << "Enter a string: ";
    cin >> input;
    int result = obj.minimumLength(input);
    cout << "Minimum length after operations: " << result << endl;
    return 0;
}
