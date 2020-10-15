// Link to the problem : https://leetcode.com/problems/repeated-substring-pattern/
// Problem Name : Repeated Substring Pattern
// Solution Method : Concatenation + Find() 

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string x = s;
        s = s + s;
        s = s.substr(1, s.length() - 2);
        size_t found = s.find(x);
        if (found != string::npos) {
            return true;
        } 
        else {
            return false;
        }
    }
};
