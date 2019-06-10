#include "main.h"
#include "timer.h"

int main() {

//    vek::vector<int> v1(10); //savadarbis
//    std::vector<int> v2(10); //originalus
    Timer timer;
    int kartai = 0;

    timer.startClock();
    int sz = 10000000;  // 100000, 1000000, 10000000, 100000000
    vek::vector<int> v1;
    for (int i = 1; i <= sz; i++) {
        if(v1.capacity() == v1.size())
            kartai++;
        v1.push_back(i);
    }
    timer.endClock("Savadarbio vektorio uzpildymas");

    timer.startClock();
    std::vector<int> v2;
        for (int j = sz+1; j <= sz+sz; j++)
            v2.push_back(j);
    timer.endClock("Originalaus vektorio uzpildymas");
    cout << sz << " elementu uzpildymas" << endl;
    cout << "Savadarbiame vektoriuje ivyko " << kartai << " kartus atminties perskirstymas" << endl;

    vek::vector<int> v3;


    //v1.resize(200);

//    //Size Funkcija
    cout << "SIZE:" << endl;
    cout << v1.size() << endl;
    cout << v2.size() << endl;
    cout << v3.size() << endl;

    //Capacity funkcija
    cout << "CAP:" << endl;
    cout << v1.capacity() << endl;
    cout << v2.capacity() << endl;
    cout << v3.capacity() << endl;

    v3.resize(100);
    v1.swap(v3);

    cout << "SIZE:" << endl;
    cout << v1.size() << endl;
    cout << v2.size() << endl;
    cout << v3.size() << endl;

    //Capacity funkcija
    cout << "CAP:" << endl;
    cout << v1.capacity() << endl;
    cout << v2.capacity() << endl;
    cout << v3.capacity() << endl;

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