#include <iostream>

int main() {
    int stack[10002];
    int length = 0;
    std::string s;
    std::cin >> s;
    while(s != "exit") {
        if(s == "push") {
            int n;
            std::cin >> n;
            stack[length] = n;
            length++;
            std::cout << "ok" << '\n';
        }
        else if(s == "pop") {
            if(length == 0) {
                std::cout << "error" << '\n';
            } else {
                std::cout << stack[length-1] << '\n';
                length --;
            }
        }
        else if(s == "back") {
            if(length == 0) {
                std::cout << "error" << '\n';
            } else {
                std::cout << stack[length-1] << '\n';
            }
        }
        else if(s == "size") {
            std::cout << length << '\n';
        }
        else if(s == "clear") {
            length = 0;
            std::cout << "ok" << '\n';
        }
        std::cin >> s;
    }
    std::cout << "bye" << '\n';
    
}