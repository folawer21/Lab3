#include "test.h"
#include <iostream>
using namespace std;
void add_test()
{
    Bin_tree<int>* tree=nullptr;
    tree->add(tree,12);
    tree->add(tree,10);
    tree->add(tree,13);
    assert(tree->Get_zn()==12);
    assert(tree->Get_left()->Get_zn()==10);
    assert(tree->Get_right()->Get_zn()==13);
}

void del_test()
{
    Bin_tree<int>* tree=nullptr;
    tree->add(tree,12);
    tree->add(tree,10);
    tree->add(tree,13);
    tree->del(tree,13);
    tree->del(tree,10);
    assert(tree->Get_left()==nullptr);
    assert(tree->Get_right()==nullptr);
}

void Writeintostr_test()
{
    Bin_tree<int>* tree=nullptr;
    tree->add(tree,12);
    tree->add(tree,10);
    tree->add(tree,13);
    tree->add(tree,9);
    tree->add(tree,8);
    string str12="12 10 9 8 13 ";
    string *str=new string();
    string *str1=new string(str12);
    str=tree->WriteIntoStr(tree,str);
    for (int i=0;i<12;i++)
    {
        assert(str[i]==str1[i]);
    }

}

void ContainsNode_test()
{
    Bin_tree<int>* tree=nullptr;
    tree->add(tree,12);
    tree->add(tree,10);
    tree->add(tree,13);
    bool cont = tree->ContainsNode(tree,10);
    assert(cont == true);
}


void Get_SubTree_test()
{
    Bin_tree<int>* tree=nullptr;
    tree->add(tree,12);
    tree->add(tree,10);
    tree->add(tree,13);
    tree->add(tree,90);
    tree->add(tree,11);
    tree->add(tree,9);
    tree->add(tree,87);
    Bin_tree<int>* tree2=tree->Get_subTree(tree,10);
    string *str=new string ();
    string *str5=tree2->WriteIntoStr(tree2,str);
    string str12="10 9 11";
    string *str1=new string(str12);
    for (int i=0;i<str->length();i++)
        assert(str[i]==str5[i]);
}

void Concat_test()
{
    Bin_tree<int>* tree=nullptr;
    Bin_tree<int>* tree2=nullptr;
    tree->add(tree,12);
    tree->add(tree,10);
    tree->add(tree,13);
    tree->add(tree,90);
    tree2->add(tree2,80);
    tree2->add(tree2,7);
    tree2->add(tree2,67);
    tree2->Concat(tree,tree2);
    string *str=new string();
    string str2="80 7 67 10 13 12 90";
    string *str3=new string (str2);
    string *str5=tree2->WriteIntoStr(tree2,str);
    for (int i=0;i<str->length();i++)
        assert(str[i]==str5[i]);
}
int mult(int a)
{
    return a*8;
}
void Map_test()
{
    Bin_tree<int>* tree=nullptr;
    Bin_tree<int>* tree2=nullptr;
    tree->add(tree,12);
    tree->add(tree,10);
    tree->add(tree,13);
    tree->add(tree,90);
    tree2=tree2->Map(&mult,tree,tree2);
    string *str=new string ();
    str=tree2->WriteIntoStr(tree2,str);
    string str2="96 80 104 720";
    string *str1=new string(str2);
    for (int i=0;i<str1->length();i++)
        assert(str2[i]==str[0][i]);
}
bool More(int a)
{
    if (a%3==0)
        return true;
    else
        return false;
}
void Where_test()
{
    Bin_tree<int>* tree=nullptr;
    Bin_tree<int>* tree2=nullptr;
    tree->add(tree,12);
    tree->add(tree,10);
    tree->add(tree,15);
    tree->add(tree,90);
    tree->add(tree,81);
    tree->add(tree,27);
    tree->add(tree,40);
    tree2=tree2->Where(&More,tree,tree2);
    string *str=new string ();
    str=tree2->WriteIntoStr(tree2,str);
    string str2="12 15 90 81 27";
    string *str1=new string(str2);
    for (int i=0;i<str1->length();i++)
        assert(str2[i]==str[0][i]);
}
void Bintree_test()
{
    add_test();//
    del_test();//
    Writeintostr_test();//
    ContainsNode_test();//
    Get_SubTree_test();//
    Concat_test();//
    Where_test();//
    Map_test();//
    cout<<"Тесты прошли успешно"<<endl;
}