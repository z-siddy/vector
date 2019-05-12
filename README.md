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
```
Savadarbio vektorio uzpildymas : 0 s
Originalaus vektorio uzpildymas : 0 s
10000 elementu uzpildymas
```
```
Savadarbio vektorio uzpildymas : 0.003987 s
Originalaus vektorio uzpildymas : 0.0059835 s
100000 elementu uzpildymas
```
```
Savadarbio vektorio uzpildymas : 0.0328687 s
Originalaus vektorio uzpildymas : 0.0578491 s
1000000 elementu uzpildymas
```
```
Savadarbio vektorio uzpildymas : 0.187496 s
Originalaus vektorio uzpildymas : 0.203458 s
10000000 elementu uzpildymas
```
```
Savadarbio vektorio uzpildymas : 2.85341 s
Originalaus vektorio uzpildymas : 3.62831 s
100000000 elementu uzpildymas
```

### Atminties perskirtymas

```
Savadarbio vektorio uzpildymas : 3.4069 s
Originalaus vektorio uzpildymas : 3.45979 s
100000000 elementu uzpildymas
Savadarbiame vektoriuje ivyko 28 kartus atminties perskirstymas
```
