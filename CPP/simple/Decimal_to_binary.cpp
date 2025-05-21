#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int ans = 0;
    int placeValue = 1; // This replaces pow(10, i)

    while (n != 0) {
        int bit = n & 1;  // Get last bit
        ans += bit * placeValue; // Add bit at the correct position
        placeValue *= 10; // Move to the next decimal place
        n = n >> 1; // Right shift to get next bit
    }

    cout << "Answer is " << ans << endl;
    return 0;
}
