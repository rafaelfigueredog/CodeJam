#include <iostream>
#include <string>
#include <deque>
#include <stack>

using namespace std; 

typedef struct Number {
    int integer;
    char chr; 
} number ;


int charToint(char c) {
    return c -'0'; 
}

void addNumer(char c, string &str) {
    str.push_back(c); 
}

void openParentheses(int n, std::string &str) {
    for (int i = 0; i < n; i++) {
       str.push_back('('); 
    }
}

void closeParentheses(int n, std::string &str) {
    for (int i = 0; i < n; i++) {
       str.push_back(')'); 
    }
}

void nestingDepthSolution(string str, int c) {

    string newstring; 
    stack<number> numberstk;
    number num; 

    for ( int i = 0; i < str.length(); i++ ) {
        num.integer = charToint(str[i]); 
        num.chr = str[i]; 
        if (i == 0) { 
            openParentheses(num.integer, newstring); 
            addNumer(num.chr, newstring); 
            numberstk.push(num); 
        } else {

            if (numberstk.top().integer == num.integer) {
                addNumer(num.chr, newstring);  
            }

            else if (numberstk.top().integer > num.integer) {
                int dif = numberstk.top().integer - num.integer; 
                closeParentheses(dif, newstring); 
                numberstk.pop(); 
                numberstk.push(num); 
                addNumer(num.chr, newstring);
            }

            else { 

                int dif = num.integer - numberstk.top().integer;
                openParentheses(dif, newstring); 
                addNumer(num.chr, newstring); 
                numberstk.pop(); 
                numberstk.push(num);

                /* closeParentheses(numberstk.top().integer, newstring); 
                numberstk.pop(); 
                numberstk.push(num);
                openParentheses(num.integer, newstring); 
                addNumer(num.chr, newstring);   */
            }

        }

    }
    closeParentheses(numberstk.top().integer, newstring); 
    printf("Case #%d: %s\n", c, newstring.c_str()); 
}


int main () {
    int t; 
    cin >> t;
    for(int c = 1; c <= t; c++) {
        string str; 
        cin >> str;  
        nestingDepthSolution(str, c); 
    }
    return 0; 
}