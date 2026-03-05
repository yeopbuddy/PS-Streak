#include <iostream>
#include <vector>

using namespace std;

int N;

bool isPrime(int num) {
    if (num < 2) return false;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}

void dfs(int num, int length) {
    if (length == N) {
        cout << num << "\n";
        return;
    }

    for (int i = 1; i <= 9; i += 2) {
        int nextNum = num * 10 + i;
        if (isPrime(nextNum)) {
            dfs(nextNum, length + 1);
        }
    }
}

int main() {

    cin >> N;

    dfs(2, 1);
    dfs(3, 1);
    dfs(5, 1);
    dfs(7, 1);

    return 0;
}