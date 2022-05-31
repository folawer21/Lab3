#include <iostream>
#include "test.h"
#include "menu.cpp"

int main()
{
    menu();
//    Bin_tree<int>* tree=nullptr;
//    tree->add(tree,12);
//    tree->print(tree,0);


//    menu();
//    cout<<"Выберите тип обхода для считывания :\n1)KLP\n2)KPL\n3)LKP\n4)PKL\n5)LPK\n6)PLK\n0)Exit\n:";
//    int choice=-1;
//    cin>>choice;
//    string str;
//    Bin_tree<int>* tree=nullptr;
//    int start=0;
//    while(choice!=0)
//    {
//    switch(choice) {
//        case (1): {
//            cout << "Введите строку в формате K(L)(P) например 4(2(3)(1))(6(5)): " << endl;
//
//            cin >> str;
//            tree = nullptr;
//            start = 0;
//            int t1 = __rdtsc();
//            tree = tree->ConstructTree(str, &start);
//            int t2 = __rdtsc();
//            cout << t2 - t1<<endl;
//            tree->print(tree, 0);
//            break;
//        }
//        case (2): {
//            cout << "Введите строку в формате K(P)(L) например 4(6()(5))(2(3)(1)): " << endl;
//            cin >> str;
//            tree = nullptr;
//            start = 0;
//            int t1 = __rdtsc();
//            tree = tree->ConstructTreeKPL(str, &start);
//            int t2 = __rdtsc();
//            cout << t2 - t1 << endl;
//            tree->print(tree, 0);
//            break;
//        }
//        case (3): {
//            cout << "Введите строку в формате (L)K(P) например (2(3)(1))4(6(5)): " << endl;
//            cin >> str;
//            tree = nullptr;
//            start = 0;
//            tree = tree->ConstructTreeLKP(str, &start);
//            tree->print(tree, 0);
//            break;
//        }
//        case (4): {
//            cout << "Введите строку в формате (P)K(L) например (6(5))4(2(3)(1)): " << endl;
//            cin >> str;
//            tree = nullptr;
//            start = 0;
//            tree = tree->ConstructTreePKL(str, &start);
//            tree->print(tree, 0);
//            break;
//        }
//        case (5): {
//            cout << "Введите строку в формате (L)(P)K например (2(3)(1))(6(5))4: " << endl;
//            cin >> str;
//            tree = nullptr;
//            start = 0;
//            tree = tree->ConstructTreeLPK(str, &start);
//            tree->print(tree, 0);
//            break;
//        }
//        case (6): {
//            cout << "Введите строку в формате (P)(L)K например (6(5))(2(3)(1))4: " << endl;
//            cin >> str;
//            tree = nullptr;
//            start = 0;
//            tree = tree->ConstructTreePLK(str, &start);
//            tree->print(tree, 0);
//            break;
//        }
//
//    }
//        cin>>choice;
//    }
//    string nw;
//    cin>>nw;
//    Bin_tree<int>* tree=nullptr;
//    tree->add(tree,12);
//    tree->add(tree,11);
//    tree->add(tree,15);
//    tree->add(tree,10);
//    string *newone=new string();
//    newone=tree->IntoStringKPL(tree,newone);
//    cout<<newone;
//    int statr=0;
//    tree=tree->ConstructTreeLPK(nw,&statr);
//    tree->print(tree,0);
//    string *newone=new string();
//    newone=tree->IntoStringLPK(tree,newone);
//    cout<<newone;
//    Bin_tree<int> *tree = nullptr;
//    string line;
//    cout<<"Введите строку в формате корень(левый)(правый) например:4(2(1)(3))(6(5))\n:";
//    cin.ignore();
//    getline(cin,line);
//    int start=0;
//    int t1 = __rdtsc();
//
//    tree=tree->ConstructTree(line,&start);
//    return 0;
//    int t2 = __rdtsc();
//    cout<<"Время постройки обходом КЛП"<<t2-t1;
//    tree->print(tree,0);
//    Bin_tree<int> *tree = nullptr;
//    tree->print(tree,0);
//    tree->add(tree,20);
//    tree->add(tree,10);
//    tree->add(tree,5);
//    tree->add(tree,40);
//    tree->add(tree,15);
//    tree->add(tree,12);
//    tree->add(tree,17);
//    tree->add(tree,8);
//    tree->print(tree,0);
//    tree->erase(20);


    return 0;
}
