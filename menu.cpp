#include "Binarytree2.hpp"
#include <iostream>
#include <ctime>
using namespace std;

int menu()
{
    setlocale(LC_ALL, "RUS");
    cout<<"Выберите тип данных: 1-Double, 2-Int: ";
    int type;
    cin>>type;
    if (type==1) {
        Bin_tree<double> *tree = NULL;
        int chislo;
        chislo = 10;
        while (chislo != 322) {
            cout << "Выберете операцию, осуществляемую с бинарным деревом:" << endl;
            cout << "1) вставка элементов в бинарное дерево поиска;\n"
                    "2) удаление элемента из бинарного дерево поиска;\n"
                    "3) поиск элемента в бинарном дереве поиска;\n"
                    "4) обход бинарного дерева поиска;\n"
                    "5) вывод бинарного дерева поиска;\n"
                    "6) Проверка элемента на вхождение;\n"
                    "7) Чтение дерева из строки;\n"
                    "8) Запись дерева в строку;\n"
                    "322) выйти из меню;\n" << endl;
            cin >> chislo;
//        if (tree== nullptr)

            if (chislo == 1) {

                double s;
                int n;
                cout << "kolvo elementov dobavlyemoe  v derevo: " << endl;
                cin >> n;
                for (int i = 0; i < n; ++i) {
                    cin >> s;
                    tree->add(tree, s);
                }
            }
            if (chislo == 2) {
                cout << "Введите элемент" << endl;
                double p;
                cin >> p;
                tree->erase(p);
                cout << endl;
            }
            if (chislo == 3) {
                cout << "Введите элемент" << endl;
                double q;
                cin >> q;
                tree->find(tree, q);
                cout << endl;
            }
            if (chislo == 4) {
                cout << "Выберите обход бинарного дерева поиска: 1-ПКЛ 2-ПЛК 3-ЛПК 4-ЛКП 5-КЛП 6-КПЛ" << endl;
                int q;
                cin >> q;
                switch (q) {
                    case 1:
                        cout << "Обход бинарного дерева поиска(ПКЛ):" << endl;
                        tree->PKL(tree);
                        break;
                    case 2:
                        cout << "Обход бинарного дерева поиска(ПЛК):" << endl;
                        tree->PLK(tree);
                        break;
                    case 3:
                        cout << "Обход бинарного дерева поиска(ЛПК):" << endl;
                        tree->LPK(tree);
                        break;
                    case 4:
                        cout << "Обход бинарного дерева поиска(ЛКП):" << endl;
                        tree->LKP(tree);
                        break;
                    case 5:
                        cout << "Обход бинарного дерева поиска(КЛП):" << endl;
                        tree->KLP(tree);
                        break;
                    case 6:
                        cout << "Обход бинарного дерева поиска(КПЛ):" << endl;
                        tree->KPL(tree);
                        break;

                }
                cout << endl;
            }

            if (chislo == 5) {
                cout << "binarnoe derevo: " << endl;
                tree->print(tree,0);
            }
            if (chislo == 6) {
                double q;
                cout << "Введите элемент: " << endl;
                cin >> q;
                bool ans = tree->ContainsNode(tree, q);
                if (ans == true)
                    cout << "Элемент есть в дереве" << endl;
                else
                    cout << "Элемент нет в дереве" << endl;
            }

            if (chislo == 7) {
                string line;
                cout<<"Введите строку в формате корень(левый)(правый) например:4(2(1)(3))(6(5))\n:";
                cin.ignore();
                getline(cin,line);
                int start=0;
                int t1 = __rdtsc();
                tree=tree->ConstructTree(line,&start);
                int t2 = __rdtsc();
                cout<<"Время постройки обходом КЛП"<<t2-t1;
                tree->print(tree,0);


            }

            if (chislo==9)
            {
                string line;
                cout<<"Введите строку в формате (правый)корень(левый) например:((5)6())4((3)2(1))\n:";
                cin.ignore();
                getline(cin,line);
                int start=0;
                int t1 = __rdtsc();
                tree=tree->ConstructTreePKL(line,&start);
                int t2 = __rdtsc();
                cout<<"Время постройки обходом PKL"<<t2-t1;
                tree->print(tree,0);
            }





            if (chislo == 8)
            {
                string *res=new string();
                tree->IntoString(tree,res);
                cout<<res[0];
            }
        }
    }
    else
    {
        Bin_tree<int> *tree = NULL;
        int chislo;
        chislo = 10;
        while (chislo != 322) {
            cout << "Выберете операцию, осуществляемую с бинарным деревом:" << endl;
            cout << "1) вставка элементов в бинарное дерево поиска;\n"
                    "2) удаление элемента из бинарного дерево поиска;\n"
                    "3) поиск элемента в бинарном дереве поиска;\n"
                    "4) обход бинарного дерева поиска;\n"
                    "5) вывод бинарного дерева поиска;\n"
                    "6) Проверка элемента на вхождение;\n"
                    "7) Чтение дерева из строки;\n"
                    "8) Запись дерева в строку;\n"
                    "322) выйти из меню;\n" << endl;
            cin >> chislo;
//        if (tree== nullptr)

            if (chislo == 1) {

                int s;
                int n;
                cout << "kolvo elementov dobavlyemoe  v derevo: " << endl;
                cin >> n;
                for (int i = 0; i < n; ++i) {
                    cin >> s;
                    tree->add(tree, s);
                }
            }
            if (chislo == 2) {
                cout << "Введите элемент" << endl;
                int p;
                cin >> p;
                tree->erase(p);
                cout << endl;
            }
            if (chislo == 3) {
                cout << "Введите элемент" << endl;
                int q;
                cin >> q;
                tree->find(tree, q);
                cout << endl;
            }
            if (chislo == 4) {
                cout << "Выберите обход бинарного дерева поиска: 1-ПКЛ 2-ПЛК 3-ЛПК 4-ЛКП 5-КЛП 6-КПЛ" << endl;
                int q;
                cin >> q;
                switch (q) {
                    case 1:
                        cout << "Обход бинарного дерева поиска(ПКЛ):" << endl;
                        tree->PKL(tree);
                        break;
                    case 2:
                        cout << "Обход бинарного дерева поиска(ПЛК):" << endl;
                        tree->PLK(tree);
                        break;
                    case 3:
                        cout << "Обход бинарного дерева поиска(ЛПК):" << endl;
                        tree->LPK(tree);
                        break;
                    case 4:
                        cout << "Обход бинарного дерева поиска(ЛКП):" << endl;
                        tree->LKP(tree);
                        break;
                    case 5:
                        cout << "Обход бинарного дерева поиска(КЛП):" << endl;
                        tree->KLP(tree);
                        break;
                    case 6:
                        cout << "Обход бинарного дерева поиска(КПЛ):" << endl;
                        tree->KPL(tree);
                        break;

                }
                cout << endl;
            }

            if (chislo == 5) {
                cout << "binarnoe derevo: " << endl;
                tree->print(tree,0);
            }
            if (chislo == 6) {
                int q;
                cout << "Введите элемент: " << endl;
                cin >> q;
                bool ans = tree->ContainsNode(tree, q);
                if (ans == true)
                    cout << "Элемент есть в дереве" << endl;
                else
                    cout << "Элемент нет в дереве" << endl;
            }

            if (chislo == 7) {
                string line;
                cout<<"Введите строку в формате корень(левый)(правый) например:4(2(1)(3))(6(5)())\n:";
                cin.ignore();
                getline(cin,line);
                int start=0;
                tree=tree->ConstructTree(line,&start);
                tree->print(tree,0);

            }
            if (chislo == 8)
            {
                string *res=new string();
                tree->IntoString(tree,res);
                cout<<res[0];
            }
            if (chislo==9)
            {
                string line;
                cout<<"Введите строку в формате (правый)корень(левый) например:((5)6())4((3)2(1))\n:";
                cin.ignore();

                getline(cin,line);
                int start=0;
                int t1 = __rdtsc();
                tree=tree->ConstructTreePKL(line,&start);
                int t2 = __rdtsc();
                cout<<"Время постройки обходом PKL"<<t2-t1<<endl;
                tree->print(tree,0);
            }
        }
    }
    return 0;
}


ostream& operator<<(ostream& out,string *str)
{
    for (int i=0;i<str->length();i++)
        out<<str[i];
    return out;
}