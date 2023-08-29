#include <iostream>
#include <queue>
using namespace std;

int main() {
    
    queue <int> survivors; //정수를 저장하는 큐 생성

    int N; //사람 수
    int K; //제거 인덱스 간격
    cin >> N >> K; //사람 수와 인덱스 간격 입력 받기

    for (int i = 0; i < N; i++) {
        survivors.push(i + 1); //1부터 N까지 숫자 큐에 저장
    }

    cout << "<"; //결과 출력 시작

    while (!survivors.empty()) {   //큐가 비어있지 않을 때만
        for (int i = 0; i < K-1; i++) {
            survivors.push(survivors.front()); //맨 앞사람을 큐 뒤에 추가 
            survivors.pop(); //맨 앞 사람 제거
        }
        if (survivors.size() == 1) {
            cout << survivors.front() << ">"; //마지막 사람 출력
            survivors.pop(); //큐에서 제거
        }
        else {
            cout << survivors.front() << ", "; //남은 사람 출력
            survivors.pop(); //큐 제거
        }
    }
}