#include <iostream>
#include <vector>

using namespace std;

int arr[100001];
int check[100001];

int main() {
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) cin >> arr[i];

    long long cnt = 0;
    int l = 0;

    for (int r = 0; r < N; r++) {
        while (check[arr[r]] > 0) {
            check[arr[l]]--;
            l++;
        }
        check[arr[r]]++;
        cnt += (r - l + 1);
    }

    cout << cnt;
    return 0;
}