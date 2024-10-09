// A parentheses string is valid if and only if:

// It is the empty string,
// It can be written as AB (A concatenated with B), where A and B are valid strings, or
// It can be written as (A), where A is a valid string.
// You are given a parentheses string s. In one move, you can insert a parenthesis at any position of the string.

// For example, if s = "()))", you can insert an opening parenthesis to be "(()))" or a closing parenthesis to be "())))".
// Return the minimum number of moves required to make s valid.

 

// Example 1:

// Input: s = "())"
// Output: 1
// Example 2:

// Input: s = "((("
// Output: 3
 

// Constraints:

// 1 <= s.length <= 1000
// s[i] is either '(' or ')'.

#include <bits/stdc++.h>
using namespace std;


class Solution {  //space complexity is O(1)
public:
    int minAddToMakeValid(string s) {
        int open=0;
        int need=0;

        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                open++;
            }
            if(s[i]==')'){
                if(open>0) open--;
                else if(open==0) need++;

            }
        }

        return need+open;
    }
};

// class Solution {    space complexity is O(n)
// public:
//     int minAddToMakeValid(string s) {
//         stack<char> stk;
//         int count = 0;
        
//         for (char c : s) {
//             if (c == '(') {
//                 stk.push(c);
//             } else if (c == ')') {
//                 if (!stk.empty() && stk.top() == '(') {
//                     stk.pop();
//                 } else {
//                     count++;
//                 }
//             }
//         }
        
//         // Add the remaining unmatched '(' in the stack to the count
//         count += stk.size();
        
//         return count;
//     }
// };