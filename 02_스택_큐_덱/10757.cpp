#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

string addStrings(string num1, string num2) { //두 문자열 더하는 함수 
    reverse(num1.begin(), num1.end());
    reverse(num2.begin(), num2.end());

    string long_str, short_str; // 더 긴 문자열 long_str에
    if (num1.size() >= num2.size()) {
        long_str = num1;
        short_str = num2;
    } else {
        long_str = num2;
        short_str = num1;
    }

    stack<int> result_stack;
    int carry = 0; 

    for (int i = 0; i < long_str.length(); i++) {
        int sum = (i < short_str.length()) ? (long_str[i] - '0') + (short_str[i] - '0') : (long_str[i] - '0');
        sum += carry;
        carry = sum / 10; //자릿수 올림
        sum %= 10; //현재 자릿수 값 저장
        result_stack.push(sum); //스택에 저장
    }

    if (carry) { 
        result_stack.push(carry);
    }

    string result = "";
    while (!result_stack.empty()) {
        result += to_string(result_stack.top());
        result_stack.pop();
    }

    return result;
}

int main() {
    string A, B;
    cin >> A >> B;

    string sum = addStrings(A, B); //두 문자열 더하고 결과 출력
    cout << sum << endl;

    return 0;
}