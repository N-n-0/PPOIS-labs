#include "Library.h"
/// <summary>
/// create vocabluary
/// </summary>
void  anglo_russkii::tree()
{
    root = nullptr;
    size = 0;
}
/// <summary>
/// add word in vocabluary
/// </summary>
/// <param name="x">english word</param>
/// <param name="s">russian word</param>
//void anglo_russkii::add(string x, string s)
//{
//    if (root == nullptr)
//    {
//        root = new Node(x, s);
//        size++;
//    }
//    else
//    {
//        Node* prev, * t;
//        t = root;
//        prev = nullptr;
//        bool find = true;
//        while (t && find)
//        {
//            prev = t;
//            if (x == t->angl)
//            {
//                find = false;
//                cout << "������ �����!" << endl;
//
//            }
//            else
//                if (x < t->angl) t = t->left;
//                else t = t->right;
//        }
//        if (find)
//        {
//            t = new Node(x, s);
//            if (x < prev->angl) prev->left = t;
//            else prev->right = t;
//        }
//        size++;
//    }
//}
//anglo_russkii operator+=(string x, string s) 
//{
//
//    if (root == nullptr)
//    {
//        root = new Node(x, s);
//        size++;
//    }
    /*else
    {
        Node* prev, * t;
        t = root;
        prev = nullptr;
        bool find = true;
        while (t && find)
        {
            prev = t;
            if (x == t->angl)
            {
                find = false;
                cout << "������ �����!" << endl;

            }
            else
                if (x < t->angl) t = t->left;
                else t = t->right;
        }
        if (find)
        {
            t = new Node(x, s);
            if (x < prev->angl) prev->left = t;
            else prev->right = t;
        }
        size++;
    }*/
//}
/// <summary>
/// view vocabluary
/// </summary>
/// <param name="root"> vocabluary</param>
/// <param name="counter">amount words in vocabluary</param>
void anglo_russkii::view_tree(Node* root, int counter)
{
    string str;
    if (root == NULL) {
        return;
    }
    else {
        for (int i = 0; i < counter; ++i) cout << "   ";
        cout << root->angl << " = " << root->rus << endl;
        view_tree(root->left, --counter);
    }
    view_tree(root->right, ++counter);

}
/// <summary>
/// delete word from vocabluary
/// </summary>
/// <param name="x">english word</param>
//void anglo_russkii::del_info(string x)
//{
//    Node* del, * prev_del, * R, * prev_R;
//    del = root;
//    prev_del = nullptr;
//    while (del != nullptr && del->angl != x)
//    {
//        prev_del = del;
//        if (del->angl > x) del = del->left;
//        else del = del->right;
//    }
//    if (del == nullptr)
//    {
//        cout << "There isnt the key!" << endl;
//        return;
//    }
//    if (del->right == nullptr) R = del->left;
//    else
//        if (del->left == nullptr) R = del->right;
//        else
//        {
//            prev_R = del;
//            R = del->left;
//            while (R->right != nullptr)
//            {
//                prev_R = R;
//                R = R->right;
//            }
//            if (prev_R == del) R->right = del->right;
//            else {
//                R->right = del->right;
//                prev_R->right = R->left;
//                R->left = del->left;
//            }
//        }
//    if (del == root) root = R;
//    else
//        if (del->angl < prev_del->angl)
//            prev_del->left = R;
//        else prev_del->right = R;
//    delete del;
//    size--;
//    return;
//}
/// <summary>
/// find word in vocabluary
/// </summary>
/// <param name="x">english word</param>
//void anglo_russkii::search_info(string x)
//{
//    if (root != nullptr)
//    {
//        Node* temp = root;
//        while (temp != nullptr && temp->angl != x)
//        {
//            if (temp->angl > x) temp = temp->left;
//            else temp = temp->right;
//        }
//        if (temp != nullptr)
//            cout << "�������: " << temp->rus << endl;
//        else cout << "��� ������ �����" << endl;
//    }


//}
/// <summary>
/// change translate of english word
/// </summary>
/// <param name="x">english word</param>
/// <param name="s">new translate</param>
void anglo_russkii::change_info(string x, string s)
{
    if (root != nullptr)
    {
        Node* temp = root;
        while (temp != nullptr && temp->angl != x)
        {
            if (temp->angl > x) temp = temp->left;
            else temp = temp->right;
        }
        if (temp != nullptr) {
            cout << "����: " << temp->angl << " " << temp->rus << endl;
            temp->rus = s;
            cout << "�����: " << temp->angl << " " << temp->rus << endl;
        }
        else cout << "��� ������ �����" << endl;

    }

}



anglo_russkii operator+=(anglo_russkii x, pair<string,string> s)
{
 
    if (x.root == nullptr)
           {
        x.root= new anglo_russkii :: Node(s.first, s.second);
                x.size++;
    }
    else
    {
        anglo_russkii::Node* prev, * t;
        t = x.root;
        prev = nullptr;
        bool find = true;
        while (t && find)
        {
            prev = t;
            if (s.first == t->angl)
            {
                find = false;
                cout << "������ �����!" << endl;

            }
            else
                if (s.first < t->angl) t = t->left;
                else t = t->right;
        }
        if (find)
        {
            t = new anglo_russkii :: Node(s.first, s.second);
            if (s.first < prev->angl) prev->left = t;
            else prev->right = t;
        }
        x.size++;
    }
  return x;
}
anglo_russkii operator-= (anglo_russkii x, string s)
{
    anglo_russkii :: Node* del, * prev_del, * R, * prev_R;
    del = x.root;
    prev_del = nullptr;
    while (del != nullptr && del->angl != s)
    {
        prev_del = del;
        if (del->angl > s) del = del->left;
        else del = del->right;
    }
    if (del == nullptr)
    {
        cout << "There isnt the key!" << endl;
        return x;
    }
    if (del->right == nullptr) R = del->left;
    else
        if (del->left == nullptr) R = del->right;
        else
        {
            prev_R = del;
            R = del->left;
            while (R->right != nullptr)
            {
                prev_R = R;
                R = R->right;
            }
            if (prev_R == del) R->right = del->right;
            else {
                R->right = del->right;
                prev_R->right = R->left;
                R->left = del->left;
            }
        }
    if (del == x.root) x.root = R;
    else
        if (del->angl < prev_del->angl)
            prev_del->left = R;
        else prev_del->right = R;
    delete del;
    x.size--;
    return x;
}

    
    anglo_russkii :: Node* anglo_russkii::operator[](string str)
{
        if (root != nullptr)
    {
            //Node* temp = root;
            while (root != nullptr && root->angl != str){
                
                if (str < root->angl) root = root->left;
                else root = root->right;
            }
            if (root == nullptr)
                cout << "��� ������ �����" << endl;

        }
        return root;
    }
    /*void anglo_russkii::operator[](string str)
    {
        if (root != nullptr)
        {
            Node* temp = root;
            while (temp != nullptr && temp->angl != str) {

                if (str < temp->angl) temp = temp->left;
                else temp = temp->right;
            }
            if (temp != nullptr)
                cout << "�������: " << temp->rus << endl;
            else cout << "��� ������ �����" << endl;
        }
    }*/