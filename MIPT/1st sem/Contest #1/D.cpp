#include <iostream>
#include <stack>
#include <queue>

int main() {
    int n;
    std::cin >> n;
    std::queue <int> first;
    int firstSize = 0, secondSize = 0;
    std::stack <int> back, front;
    for(int i = 0; i < n; i++) {
        std::string s;
        std::cin >> s;
        if(s == "+") {
            int x;
            std::cin >> x;
            back.push(x);
            secondSize++;
        }
        else if(s == "*") {
            int x;
            std::cin >> x;
            while(firstSize < secondSize) {
                if(front.empty()) {
                    while(!back.empty()) {
                        front.push(back.top());
                        back.pop();
                    }
                } else {
                    first.push(front.top());
                    front.pop();
                    firstSize++;
                    secondSize--;
                }
            }
            if(secondSize == firstSize) {
                first.push(x);
                firstSize++;
            } else {
                front.push(x);
                secondSize++;
            }            
        } else {
            if(!first.empty()) {
                std::cout << first.front() << '\n';
                first.pop();
                firstSize--;
            } else {
                if(front.empty()) {
                    while(!back.empty()) {
                        front.push(back.top());
                        back.pop();
                    }
                } 
                first.push(front.top());
                front.pop();
                firstSize++;
                secondSize--;
                std::cout << first.front() << '\n';
                first.pop();
                firstSize--;
            }
        }
    }
}