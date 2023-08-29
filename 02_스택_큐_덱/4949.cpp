#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
    string str;

    while (1) {
        getline(cin, str); 
        stack<char> a;
        if (str[0] == '.') // 입력이 마침표면 루프 종료
            break;

        bool balanced = true; // 괄호가 균형을 이루는가

        for (char c : str) { 
            if (c == '(' || c == '[')
                a.push(c); // 여는 괄호 스택에 추가
            else if (c == ')' || c == ']') { // 닫는 괄호만나면 스택 확인
                if (a.empty() ||
                    (c == ')' && a.top() != '(') ||
                    (c == ']' && a.top() != '[')) {
                    balanced = false; // 괄호 균형 안이루면
                    break; // 루프 종료
                }
                a.pop(); // 짝 맞으면 여는 괄호 제거 
            }
        }

        if (balanced && a.empty())
            cout << "yes" << endl; // 괄호 균형, 스택 빔
        else
            cout << "no" << endl; // 아니면 no
    }

    return 0;
}
