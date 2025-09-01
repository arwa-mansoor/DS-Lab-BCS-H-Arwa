#include <iostream>
#include <cfloat>
using namespace std;

int main() {
    int n, m;
    cout << "Enter the number of days: ";
    cin >> n;
    cout << "Enter the number of times in a day: ";
    cin >> m;

    float** temperature = new float*[n];
    for (int i = 0; i < n; i++) {
        temperature[i] = new float[m]{0.0};
    }

    for (int i = 0; i < n; i++) {
        cout << "\nTemperature Reading for Day " << i + 1 << ":\n";
        for (int j = 0; j < m; j++) {
            cout << "Time " << j + 1 << ": ";
            cin >> temperature[i][j];
        }
    }

    float hottest = FLT_MIN, coldest = FLT_MAX;
    int hottestDay = -1, coldestDay = -1;

    for (int i = 0; i < n; i++) {
        float total = 0.0;
        for (int j = 0; j < m; j++) {
            total += temperature[i][j];
        }

        float avg = total / m;
        cout << "Average Temperature for Day " << i + 1 << " : " << avg << endl;

        if (avg > hottest) {
            hottest = avg;
            hottestDay = i + 1;
        }
        if (avg < coldest) {
            coldest = avg;
            coldestDay = i + 1;
        }
    }

    cout << "Hottest Day : Day " << hottestDay << endl;
    cout << "Coldest Day : Day " << coldestDay << endl;
    
    for (int i = 0; i < n; i++) {
        delete[] temperature[i];
    }
    delete[] temperature;

    return 0;
}