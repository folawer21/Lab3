//if (chislo == 8)
//        {
//            string line;
//            cout<<"Введите элементы дерева через пробел"<<endl;
//            getline(cin,line);
//            string *lineptr=&line;
//            tree->MakeFromStr(lineptr);
//            tree->print(tree);
//        }
//template <class T>
//Bin_tree<T>* Bin_tree<T>::MakeFromStr(string* str)
//{
//    Bin_tree<T>* res=nullptr;
//    char* strn=(char *) str;
//    char * token=strtok(strn, " ");
//    while (token)
//    {
//        res->add(res,* (int *) token);
//        token=strtok(nullptr," ");
//    }
//
//    return res;
//}
//if (chislo == 7)
//{
//Bin_tree<int> *tree2=nullptr;
//int s;
//int n;
//cout << "kolvo elementov dobavlyemoe  v derevo: " << endl;
//cin >> n;
//for (int i = 0; i < n; ++i)
//{
//cin >> s;
//tree2->add(tree2, s);
//}
//bool ans=tree->ContainsSubTree(tree,tree2);
//if (ans==true)
//cout<<"Поддерево есть в дереве"<<endl;
//else
//cout<<"Поддерева нет в дереве"<<endl;
//}
