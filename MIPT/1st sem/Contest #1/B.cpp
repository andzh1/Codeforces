#include <iostream>
#include <stack>

int main() {
    std::string s;
    std::cin >> s;
    bool isCorrect = true;
    std::stack <char> open;
    for(long long i = 0; i < s.length(); i++) {
        if(s[i] == '(' || s[i] == '[' ||  s[i] == '{') open.push(s[i]);
        else {
            if(open.empty()) {
                isCorrect = false;
                break;
            }
            else {
                if((open.top() == '(' && s[i] == ')') || (open.top() == '{' && s[i] == '}') || (open.top() == '[' && s[i] == ']')) open.pop();
                else {
                    isCorrect = false;
                    break;
                }
            }
        }
    }
    if(!open.empty()) isCorrect = false;
    if(isCorrect) {
        std::cout << "yes";
    } else {
        std::cout << "no";
    }
}