#include "StackArray.h"
#include "StackList.h"
#include "Test.h"
#include <iostream>
using namespace std;

int main() {
//    cout<<"Stos oparty na tablicy:"<<endl;
//    StackArray sa(10);
//    sa.push(5);
//    sa.push(6);
//    sa.push(7);
//    cout<<endl<<"Elementy stosu:"<<endl;
//    sa.display();
//    cout<<"Rozmiar stosu: "<<sa.size()<<endl;
//    cout<<"Wierzcholek stosu: "<<sa.top()<<endl;
//    cout<<"Elementy stosu po usunieciu wierzcholka:"<<endl;
//    sa.pop();
//    sa.display();
//
//
//    cout<<endl<<"Stos oparty na liscie:"<<endl;
//    StackList sl;
//    sl.push(3);
//    sl.push(2);
//    sl.push(1);
//    cout<<endl<<"Elementy stosu:"<<endl;
//    sl.display();
//    cout<<"Rozmiar stosu: "<<sa.size()<<endl;
//    cout<<"Wierzcholek stosu: "<<sa.top()<<endl;
//    cout<<"Elementy stosu po usunieciu wierzcholka:"<<endl;
//    sl.pop();
//    sl.display();



    //Testy wydajności
    cout << "Test wydajnosci:" << endl;
    Test::testStackArray(100);
    Test::testStackArray(1000);
    Test::testStackArray(100000);
    cout<<endl;
    Test::testStackList(100);
    Test::testStackList(1000);
    Test::testStackList(100000);

    return 0;
}
