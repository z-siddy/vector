#include "main.h"
#include "timer.h"

int main() {

//    vek::vector<int> v1(10); //savadarbis
//    std::vector<int> v2(10); //originalus
    Timer timer;

    timer.startClock();
    int sz = 100000;  // 100000, 1000000, 10000000, 100000000
    vek::vector<int> v1;
    for (int i = 1; i <= sz; i++)
        v1.push_back(i);
    timer.endClock("Savadarbio vektorio uzpildymas");

    timer.startClock();
    std::vector<int> v2;
        for (int j = 1; j <= sz; j++)
            v2.push_back(j);
    timer.endClock("Originalaus vektorio uzpildymas");

//    //Size Funkcija
//    cout << "SIZE:" << endl;
//    cout << v1.size() << endl;
//    cout << v2.size() << endl;
//
//    //Capacity funkcija
//    cout << "CAP:" << endl;
//    cout << v1.capacity() << endl;
//    cout << v2.capacity() << endl;
//
//    //Push_back funkcija
//    v1.push_back(14);
//    v2.push_back(14);
//
//    //Back funkcija
//    cout << "BACK:" << endl;
//    cout << v1.back() << endl;
//    cout << v2.back() << endl;
//
//    //Clear funkcija
//    v1.clear();
//    v2.clear();
//
//    //Size Funkcija
//    cout << "SIZE:" << endl;
//    cout << v1.size() << endl;
//    cout << v2.size() << endl;
//
//    //Empty funkcija
//    cout << "EMPTY(bool):" << endl;
//    cout << v1.empty() << endl;
//    cout << v2.empty() << endl;

    return 0;
}