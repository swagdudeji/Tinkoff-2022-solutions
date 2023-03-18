#include <iostream>


using namespace std;


int main() {
    unsigned long a, b, c, x, y, z;
    cin >> a >> b >> c >> x >> y >> z;

    unsigned long n = x / a + y / b + z / c;
    long long answer = (n + 1) * (1 + n + 1) / 2;
  
    cout << answer << endl;
    return 0;
}