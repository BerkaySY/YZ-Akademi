#include <iostream>

using namespace std;

void compareTriplets(int a[3], int b[3]) {
    int c[2];
    int alicePoints = 0, bobPoints = 0;
    for (int i = 0; i < 3; i++) {
        if (a[i] > b[i])
            alicePoints++;
        else if (a[i] == b[i])
            continue;
        else
            bobPoints++;
    }
    c[0] = alicePoints; c[1] = bobPoints;
    cout << "Alice : " << c[0] << " " << "Bob : " << c[1];
}

int main()
{
    
    int a[3], b[3];
    bool isAliceBetween = false;
    bool isBobBetween = false;
    while (isAliceBetween == false) {
        cout << "Please input Alice's reviewer rates (Your inputs have to in [1,99]!) \n";
        cin >> a[0] >> a[1] >> a[2] ;
        
        if (a[0] >= 1 && a[0] <= 100 && a[1] >= 1 && a[1] <= 100 && a[2] >= 1 && a[2] <= 100)
            isAliceBetween = true;
    }

    while (isBobBetween == false) {
        cout << "Please input Bob's reviewer rates (Your inputs have to in [1,99]!) \n";
        cin >> b[0] >> b[1] >> b[2];
        
        if (b[0] >= 1 && b[0] <= 100 && b[1] >= 1 && b[1] <= 100 && b[2] >= 1 && b[2] <= 100)
            isBobBetween = true;
    }
    compareTriplets(a, b);
}