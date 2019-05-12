# vector
## VU OOP Self-made vector class

### Funkcijų palyginimas su originaliu vektoriumi

Programos `main.cpp` failo kodas:
```
    vek::vector<int> v1(10); //savadarbis
    std::vector<int> v2(10); //originalus

    //Size Funkcija
    cout << "SIZE:" << endl;
    cout << v1.size() << endl;
    cout << v2.size() << endl;

    //Capacity funkcija
    cout << "CAP:" << endl;
    cout << v1.capacity() << endl;
    cout << v2.capacity() << endl;

    //Push_back funkcija
    v1.push_back(14);
    v2.push_back(14);

    //Back funkcija
    cout << "BACK:" << endl;
    cout << v1.back() << endl;
    cout << v2.back() << endl;

    //Clear funkcija
    v1.clear();
    v2.clear();

    //Size Funkcija
    cout << "SIZE:" << endl;
    cout << v1.size() << endl;
    cout << v2.size() << endl;

    //Empty funkcija
    cout << "EMPTY(bool):" << endl;
    cout << v1.empty() << endl;
    cout << v2.empty() << endl;
```

Gauti rezultatai:
```
SIZE:
10
10
CAP:
10
10
BACK:
14
14
SIZE:
0
0
EMPTY(bool):
1
1
```

### Užpildymas

