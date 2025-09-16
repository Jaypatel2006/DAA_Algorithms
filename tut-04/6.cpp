#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<double> rates = {2, 3, 1.5};
    sort(rates.rbegin(), rates.rend());

    for (double rate : rates)
        cout << rate << " ";
    cout << endl;

    return 0;
}
