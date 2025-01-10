class Solution {
public:
      string removeStars(string s) {
            stack<char> st; // Initialize a stack to keep track of characters
            
            // Iterate through each character in the string
            for(char c: s){
                  if(c=='*') st.pop(); // If the character is a star, pop the top character from the stack
                  else st.push(c); // Otherwise, push the character onto the stack
            }
            
            // Create a string with the size of the stack, initialized with spaces
            string str(st.size(),' ');
            int index=str.length()-1; // Set the index to the last position of the string

            // While the stack is not empty
            while(!st.empty()){
                  str[index--]=st.top(); // Assign the top character of the stack to the current index of the string
                  st.pop(); // Pop the top character from the stack
            }

            return str; // Return the resulting string
      }
};
