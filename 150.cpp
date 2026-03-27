class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;                        // stack to hold operands and intermediate results

        for (const string& t : tokens) {      // process each token from left to right
            // If the token is one of the four operators, we apply it to the top two stack values
            if (t == "+" || t == "-" || t == "*" || t == "/") {
                int rhs = st.top(); st.pop(); // pop right-hand side operand (the most recent number)
                int lhs = st.top(); st.pop(); // pop left-hand side operand (the next most recent)

                int res;                      // will store the operation result
                if (t == "+")      res = lhs + rhs;   // add
                else if (t == "-") res = lhs - rhs;   // subtract (order matters!)
                else if (t == "*") res = lhs * rhs;   // multiply
                else               res = lhs / rhs;   // divide (C++ int division truncates toward 0)

                st.push(res);                 // push the result back for future operations
            } else {
                // Otherwise, the token is an integer literal (could be negative, e.g., "-11")
                st.push(stoi(t));             // convert string to int and push it
            }
        }

        return st.top();                      // final result remains at the top of the stack
    }
};

/*

150. Evaluate Reverse Polish Notation

You are given an array of strings tokens that represents an arithmetic expression in a Reverse Polish Notation.

Evaluate the expression. Return an integer that represents the value of the expression.

Note that:

The valid operators are '+', '-', '*', and '/'.
Each operand may be an integer or another expression.
The division between two integers always truncates toward zero.
There will not be any division by zero.
The input represents a valid arithmetic expression in a reverse polish notation.
The answer and all the intermediate calculations can be represented in a 32-bit integer.
 

Example 1:

Input: tokens = ["2","1","+","3","*"]
Output: 9
Explanation: ((2 + 1) * 3) = 9
Example 2:

Input: tokens = ["4","13","5","/","+"]
Output: 6
Explanation: (4 + (13 / 5)) = 6
Example 3:

Input: tokens = ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]
Output: 22
Explanation: ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
= ((10 * (6 / (12 * -11))) + 17) + 5
= ((10 * (6 / -132)) + 17) + 5
= ((10 * 0) + 17) + 5
= (0 + 17) + 5
= 17 + 5
= 22
 

Constraints:

1 <= tokens.length <= 104
tokens[i] is either an operator: "+", "-", "*", or "/", or an integer in the range [-200, 200].
*/