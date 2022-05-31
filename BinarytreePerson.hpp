#ifndef BINARYTREEPERSON_HPP
#define BINARYTREEPERSON_HPP
#ifndef BINARYTREE2_HPP
#define BINARYTREE2_HPP
#include "node.hpp"
#include <iostream>
#include <cstring>


using namespace std;
template <class T>
class Bin_tree
{
private:
    T zn;// значение в дерево
    Bin_tree* left; // указатель на левый
    Bin_tree* right; // указатель на правый
public:
    Bin_tree();
    Bin_tree(T data);
    Bin_tree* Get_left();
    Bin_tree* Get_right();
    T Get_zn();
    Bin_tree<T>* find(Bin_tree<T>* Tree, T a);
    void del(Bin_tree<T>* tree, T b,Bin_tree<T>* prev = nullptr);
    void PKL(Bin_tree<T>* Tree);
    void PLK(Bin_tree<T>* Tree);
    void KLP(Bin_tree<T>* Tree);
    void KPL(Bin_tree<T>* Tree);
    void LPK(Bin_tree<T>* Tree);
    void LKP(Bin_tree<T>* tree);
    void add(Bin_tree<T>*& Tree, T k);
    void print(Bin_tree<T>*& tree,int level);
    void del_tree(Bin_tree<T>* tree);
    bool ContainsNode(Bin_tree<T>* Tree,T value);
    bool ContainsSubTree(Bin_tree<T>* Tree,Bin_tree<T>* SubTree);
    Bin_tree<T>* Get_subTree(Bin_tree<T>* Tree,T a);
    void Concat(Bin_tree<T>* tree1,Bin_tree<T>* tree2);
    string* WriteIntoStr(Bin_tree<T>* tree1,string *res);
    Bin_tree<T>* Where(bool (*f) (T data),Bin_tree<T>* tree1,Bin_tree<T>* res);
    Bin_tree<T>* Map(T (*f) (T data),Bin_tree<T>* tree1,Bin_tree<T>* res);
    Bin_tree<T>* ConstructTreeIntandDouble(const string& str, int *start);
    Bin_tree<T>* ConstructTreeString(const string& str, int *start);
};
template <class T>
Bin_tree<T>::Bin_tree(T data)
{
    this->zn= data;
    this->left=nullptr;
    this->right=nullptr;
}
template <class T>
Bin_tree<T>::Bin_tree()
{
    this->left=nullptr;
    this->right=nullptr;
}
template <class T>
Bin_tree<T>* Bin_tree<T>::Get_left()
{
    return this->left;
}
template <class T>
Bin_tree<T>* Bin_tree<T>::Get_right()
{
    return this->right;
}
template <class T>
T Bin_tree<T>::Get_zn()
{
    return this->zn;
}
template <class T>
string* Bin_tree<T>::WriteIntoStr(Bin_tree<T>* tree1,string* res)
{
    if (tree1== nullptr)
        return nullptr;
    *res= *res+ to_string(tree1->Get_zn());
    *res= *res + " ";
    if (tree1->Get_left()!= nullptr)
        WriteIntoStr(tree1->Get_left(),res);
    if (tree1->Get_right()!= nullptr)
        WriteIntoStr(tree1->Get_right(),res);
    return res;
}

template <class T>
Bin_tree<T>* Bin_tree<T>::Where(bool (*f) (T data),Bin_tree<T>* tree1,Bin_tree<T>* res)
{
    if (tree1!=nullptr)
    {
        if (f(tree1->Get_zn()))
            res->add(res,tree1->Get_zn());
        if (tree1->Get_left()!=nullptr)
            Where(f,tree1->Get_left(),res);
        if (tree1->Get_right()!=nullptr)
            Where(f,tree1->Get_right(),res);
    }
    return res;
}

template <class T>
Bin_tree<T>* Bin_tree<T>::Map(T (*f) (T data),Bin_tree<T>* tree1,Bin_tree<T>* res)
{
    if (tree1== nullptr)
        return nullptr;
    if (tree1!=nullptr)
    {
        if (tree1->Get_zn())
            res->add(res, f(tree1->Get_zn()));
        if (tree1->Get_left()!=nullptr)
            Map(f,tree1->Get_left(),res);
        if (tree1->Get_right()!=nullptr)
            Map(f,tree1->Get_right(),res);
    }
    return res;
}

template <class T>
void Bin_tree<T>::Concat(Bin_tree<T>* tree1,Bin_tree<T>* tree2)
{

    if (tree1->Get_left()!=nullptr)
        Concat(tree1->left,tree2);
    if (tree1->Get_right()!=nullptr)
        Concat(tree1->Get_right(),tree2);
    tree2->add(tree2,tree1->Get_zn());
}
template <class T>
bool Bin_tree<T>::ContainsNode(Bin_tree<T>* Tree,T value)
{
    Bin_tree<T> *nwtree=nullptr;
    nwtree=Tree->find(Tree,value);

    if (nwtree==nullptr)
        return false;
    else
        return true;
}
template <class T>
bool Bin_tree<T>::ContainsSubTree(Bin_tree<T>* Tree,Bin_tree<T>* SubTree)
{

    bool cont=Tree->ContainsNode(Tree,SubTree->Get_zn());
    if (cont == false)
        return false;
    if (Tree->Get_left()!= nullptr) {
        cont = ContainsSubTree(Tree, SubTree->Get_left());
        if (cont == false)
            return false;
    }
    if (Tree->Get_right()!= nullptr){
        cont=ContainsSubTree(Tree,SubTree->Get_right());
        if (cont==false)
            return false;
    }
    if (cont==true)
    {
        return true;
    }
}

template <class T>
Bin_tree<T>* getmin(Bin_tree<T>* Tree, Bin_tree<T>*& prev)
{
    if (Tree == nullptr)
    {
        return nullptr;
    }
    if (Tree->Get_left() != nullptr)
    {
        Bin_tree<T>* tmp =  getmin(Tree->Get_left(), Tree);
        prev = Tree;
        return tmp;
    }
    else
    {
        return Tree;
    }
}
template <class T>
Bin_tree<T>* Bin_tree<T>::Get_subTree(Bin_tree<T>* Tree,T a)
{
    Bin_tree<T>* res=find(Tree,a);
    return res;
}
// поиск
template <class T>
Bin_tree<T>* Bin_tree<T>::find(Bin_tree<T>* Tree, T a)
{
    if (Tree != nullptr)
    {
        if (Tree->zn == a)
        {
            return Tree;
        }
        else if (a < Tree->zn)
        {
            return find(Tree->left, a);
        }
        else if (a > Tree->zn)
        {
            return find(Tree->right, a);
        }

    }
    else
        return nullptr;

}

// удаление элем
template <class T>
void Bin_tree<T>::del(Bin_tree<T>* tree, T b ,Bin_tree<T>* prev)
{

    if (tree != nullptr)
    {
        if (b == tree->zn)
        {
            if ((tree->left == nullptr) && (tree->right == nullptr))
            {
                if (prev != nullptr && prev->zn <= tree->zn)
                    prev->right = nullptr;
                else
                    prev->left = nullptr;
                delete tree;
            }
            else if (tree->left == nullptr && tree->right != nullptr)
            {
                if (prev != nullptr && prev->zn <= tree->zn)
                    prev->right = tree->right;
                else
                    prev->left = tree->right;
                delete tree;
            }
            else if (tree->left != nullptr && tree->right == nullptr) {
                if (prev != nullptr && prev->zn <= tree->zn)
                    prev->right = tree->left;
                else
                    prev->left = tree->left;
                delete tree;

            }
            else if (tree->left != nullptr && tree->right != nullptr)
            {
                Bin_tree<T>* prev = nullptr;
                Bin_tree<T>* ptr = getmin(tree->right, prev);
                if (ptr->right == nullptr) {
                    if (prev != nullptr)
                        prev->left = nullptr;
                }
                else {
                    if (prev != nullptr)
                        prev->left = ptr->right;
                }
                tree->zn = ptr->zn;
                delete ptr;
            }

        }
        else if (b < tree->zn)  //   c помощью 1 и 2 if идем влево
            //потом вправо пока не найдем нужный элемент и не вызовем рекурсивную функцию
        {
            del(tree->left, b, tree); // рекурсия
        }
        else if (b > tree->zn)
        {
            del(tree->right, b, tree); // рекурсия
        }
    }
    else
    {
        cout << " elementa net " << endl;
    }
}
// обход клп
template <class T>
void Bin_tree<T>::KLP(Bin_tree<T>* tree)
{
    if (tree != nullptr)
    {
        cout << tree->zn << "\t";
        KLP(tree->left);
        KLP(tree->right);
    }
}
// обход кпл
template <class T>
void Bin_tree<T>::KPL(Bin_tree<T>* tree)
{
    if (tree != nullptr)
    {
        cout << tree->zn << "\t";
        KPL(tree->right);
        KPL(tree->left);
    }
}
//обход лпк
template <class T>
void Bin_tree<T>::LPK(Bin_tree<T>* Tree)
{
    if (Tree != nullptr)
    {
        LPK(Tree->left);
        LPK(Tree->right);
        cout << Tree->zn << "\t";

    }
}
// обход лкп
template <class T>
void Bin_tree<T>::LKP(Bin_tree<T>* Tree)
{
    if (Tree != nullptr)
    {
        LKP(Tree->left);
        cout << Tree->zn << "\t";
        LKP(Tree->right);
    }
}
// обход пкл
template <class T>
void Bin_tree<T>::PKL(Bin_tree<T>* Tree)
{
    if (Tree != nullptr)
    {
        PKL(Tree->right);
        cout << Tree->zn << "\t";
        PKL(Tree->left);
    }

}
// обход пкл
template <class T>
void Bin_tree<T>::PLK(Bin_tree<T>* Tree)
{
    if (Tree != nullptr)
    {
        PLK(Tree->right);
        PLK(Tree->left);
        cout << Tree->zn << "\t";
    }
}


// вставка элемента
template <class T>
void Bin_tree<T>::add(Bin_tree<T>*& Tree, T k)
{

    if (Tree == nullptr)
    {
        Tree = new Bin_tree<T>;
        Tree->zn = k;
        Tree->left = Tree->right = nullptr;
        return;
    }

    if (k < Tree->zn)
    {
        if (Tree->left != nullptr) add(Tree->left, k);
        else
        {
            Tree->left = new Bin_tree<T>;
            Tree->left->left = Tree->left->right = nullptr;
            Tree->left->zn = k;
        }

    }
    if (k >= Tree->zn)
    {
        if (Tree->right != nullptr) add(Tree->right, k);
        else
        {
            Tree->right = new Bin_tree<T>;
            Tree->right->right = Tree->right->left = nullptr;
            Tree->right->zn = k;
        }
    }
}

template <class T>
void Bin_tree<T>::print(Bin_tree<T>*& tree,int level) {
    if (tree!=nullptr)
    {
        print(tree->left, level + 1);
        for (int i = 0; i < level; i++) cout << "   ";
        cout << tree->zn << endl;
        print(tree->right, level + 1);
    }

}

//удаление бин дерева
template <class T>
void Bin_tree<T>::del_tree(Bin_tree<T>* tree)
{
    if (tree != nullptr)
    {
        del_tree(tree->Get_left());
        del_tree(tree->Get_right());

        delete tree;
        tree = nullptr;
    }

}
template<class T>
Bin_tree<T>* Bin_tree<T>::ConstructTreeIntandDouble(const string& str, int *start)
{
    if (str.empty() || *start >= str.size())
        return nullptr;

    T num = 0;
// Получаем первое число
    while(*start < str.size() && str[*start] != '(' && str[*start] != ')')
    {
        T num_here = (T)(str[*start] - '0');
        num = num * 10 + num_here;
        *start = *start + 1;
    }
// Создаем узел с нашим числом
    Bin_tree<T> *root = nullptr;
    if (num > 0)
        root = new Bin_tree(num);
// Встречаем правую скобку - начинаем строить дерево слева.
    if (*start < str.size() && str[*start] == '(')
    {
        *start = *start + 1;
        root->left = ConstructTreeIntandDouble(str, start);
    }
    if (*start < str.size() && str[*start] == ')')
    {
        *start = *start + 1;
        return root;
    }
// Когда мы встречаем вторую правую скобку от узла, строим дерево вправо.
    if (*start < str.size() && str[*start] == '(')
    {
        *start = *start + 1;
        root->right = ConstructTreeIntandDouble(str, start);
    }

    if (*start < str.size() && str[*start] == ')')
        *start = *start + 1;

    return root;

}
template<class T>
Bin_tree<T>* Bin_tree<T>::ConstructTreeString(const string& str, int *start)
{
    if (str.empty() || *start >= str.size())
        return nullptr;

    T num = 0;
// Получаем первое число
    while(*start < str.size() && str[*start] != '(' && str[*start] != ')')
    {
        T num_here = (T)(str[*start] - '0');
        num = num * 10 + num_here;
        *start = *start + 1;
    }
// Создаем узел с нашим числом
    Bin_tree<T> *root = nullptr;
    if (num > 0)
        root = new Bin_tree(num);
// Встречаем правую скобку - начинаем строить дерево слева.
    if (*start < str.size() && str[*start] == '(')
    {
        *start = *start + 1;
        root->left = ConstructTreeIntandDouble(str, start);
    }
    if (*start < str.size() && str[*start] == ')')
    {
        *start = *start + 1;
        return root;
    }
// Когда мы встречаем вторую правую скобку от узла, строим дерево вправо.
    if (*start < str.size() && str[*start] == '(')
    {
        *start = *start + 1;
        root->right = ConstructTreeIntandDouble(str, start);
    }

    if (*start < str.size() && str[*start] == ')')
        *start = *start + 1;

    return root;

}
#endif //BINARYTREE2_HPP





#endif //BINARYTREEPERSON_HPP
