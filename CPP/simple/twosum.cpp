#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    int arr[100];  
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int target;
    cin >> target;

    int a = -1, b = -1; 

    
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) { 
            if (arr[i] + arr[j] == target) {
                a = i;
                b = j;
                break;
            }
        }
        if (a != -1) break; 
    }

    if (a != -1) {
        cout << "Answer: " << a << " " << b << endl;
    } else {
        cout << "No valid pair found!" << endl;
    }

    return 0;
}
