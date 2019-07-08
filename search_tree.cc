#include "tools.h"

#include <stack>

template<typename T>
class node
{
public: 
    node(const T& val):val(val),left(NULL),right(NULL){}
    T val;
    node* left;
    node* right;
};


template<typename T>
class Search_tree {
public:

    using iterator = node<T> *;

    Search_tree() : root(NULL) {}

    ~Search_tree()
    {
        delete_(root);
    }

    bool insert(const T &val) {
        if (root == NULL) {
            node<T> *tmp = new node<T>(val);
            root = tmp;
            return true;
        }
        iterator iter = root;
        node<T> *tmp = new node<T>(val);
        while (true) {
            if (val >= iter->val) {
                if (iter->right == NULL) {
                    iter->right = tmp;
                    break;
                }
                iter = iter->right;
            } else if (val < iter->val) {
                if (iter->left == NULL) {
                    iter->left = tmp;
                    break;
                }
                iter = iter->left;
            }

        }
    }

    void first()
    {
        first_(root);
    }

    void first1()
    {
        first1_(root);
    }

    void mid()
    {
        mid_(root);
    }

    void mid1()
    {
        mid1_(root);
    }

    void last()
    {
        last_(root);
    }

    void last1()
    {
        last1_(root);
    }

    iterator find(const T& val)
    {
        return find_(root, val);
    }

    void erase(const T& val)
    {
        erase_(root, val);
    }

    T getMax()
    {
        iterator iter = root;
        while(iter->right)
        {
            iter = iter->right;
        }
        return iter->val;
    }

    T getMin()
    {
        iterator iter = root;
        while(iter->left)
        {
            iter = iter->left;
        }
        return iter->val;
    }


private:

    void first_(iterator it)
    {
        iterator iter = it;
        if(it != NULL)
        {
            cout<<it->val<<" ";
            first_(it->left);
            first_(it->right);
        }
    }

    void first1_(iterator it)
    {
        iterator iter = it;
        while(iter != NULL || !stack_.empty())
        {
            while(iter != NULL)
            {
                cout<<iter->val<<" ";
                stack_.push(iter);
                iter = iter->left;
            }
            if(!stack_.empty())
            {
                iter = stack_.top();
                stack_.pop();
                iter = iter->right;
            }
        }
    }

    void mid_(iterator it)
    {
        iterator iter = it;
        if(iter != NULL)
        {
            mid_(iter->left);
            cout<<iter->val<<" ";
            mid_(iter->right);
        }
    }

    void mid1_(iterator it)
    {
        iterator iter = it;
        while(iter != NULL || !stack_.empty())
        {
            while(iter != NULL)
            {
                stack_.push(iter);
                iter = iter->left;
            }
            if(!stack_.empty())
            {
                iter = stack_.top();
                stack_.pop();
                cout<<iter->val<<" ";
                iter = iter->right;
            }
        }
    }

    void last_(iterator it)
    {
        iterator iter = it;
        if(iter != NULL)
        {
            last_(iter->left);
            last_(iter->right);
            cout<<iter->val<<" ";
        }
    }

    void last1_(iterator it)
    {
        iterator iter = it;
        std::stack<iterator> stack2;
        while(iter != NULL || !stack_.empty())
        {
            if(iter)
            {
                stack_.push(iter);
                stack2.push(iter);
                iter = iter->right;
            }else {
                iter = stack_.top();
                stack_.pop();
                iter = iter->left;
            }
        }
        while(stack2.size())
        {
            iterator iter = stack2.top();
            stack2.pop();
            cout<<iter->val<<" ";
        }

    }

    void delete_(iterator it)
    {
        iterator iter = it;
        if(iter != NULL)
        {
            delete_(iter->left);
            delete_(iter->right);
            delete iter;
        }
    }

    iterator find_(iterator it, const T& val)
    {
        iterator iter = it;
        while(iter->val != val)
        {
            if (val > iter->val)
            {
                iter = iter->right;
                if (!iter)
                    break;
            } else
            {
                iter = iter->left;
                if(!iter)
                    break;
            }
        }
        return iter;
    }

    void findT_(iterator& parent, iterator& child, const T& val)
    {
        parent = child = root;
        while(child->val != val)
        {
            if(val > child->val)
            {
                parent = child;
                child = child->right;
                if(!child)
                    break;
            }else
            {
                parent = child;
                child = child->left;
                if(!child)
                    break;
            }
        }
    }

    void erase_(iterator it, const T& val) {
        iterator parent, child;
        findT_(parent, child, val);
        if (child == NULL)
            return;
        if (child->left == NULL && child->right == NULL)//左右节点都为null
        {
            if(child == root)
            {
                delete root;
                root = NULL;
            }
            delete child;
            return;
        }
        //左右节点中有一个不为NULL
        //将不为空的节点替换为原节点
        if(child->left == NULL && child == root)//右不为空 且为头结点
        {
            root = child->right;
            delete child;
            return ;
        }else if(child->left == NULL && child->right != NULL)
        {
            child->val > parent->val ? parent->right = child->right : parent->left = child->right;
            delete child;
            return ;
        }
        if(child->right == NULL && child == root)
        {
            root = child->left;
            delete child;
            return ;
        }else if(child->right == NULL && child->left != NULL)
        {
            child->val > parent->val ? parent->right = child->left : parent->left = child->right;
            return ;
        }
        //都不为空
        //在右子树中找到最小节点替换原节点
        iterator min = child->right;
        parent = min;
        while(min->left)
        {
            parent = min;
            min = min->left;
        }
        if(parent == min)
        {
            child->val = min->val;
            delete min;
            child->left = NULL;
            return ;
        }
        child->val = min->val;
        delete min;
        parent->left = NULL;
    }





private: 
    node<T>* root;
    std::stack<iterator> stack_;


};

int main(int argc, char const *argv[])
{
    Search_tree<int> tree;
    tree.insert(50);
    tree.insert(38);
    tree.insert(70);
    tree.insert(30);
    tree.insert(45);
    tree.insert(40);
    tree.insert(48);
    tree.insert(60);
    tree.insert(75);
    tree.insert(80);
//    tree.first();
//    cout<<endl;
//    tree.first1();
//    cout<<endl;
//    tree.mid();
//    cout<<endl;
//    tree.mid1();
//    cout<<endl;
//    tree.last();
//    cout<<endl;
//    tree.last1();
//    cout<<endl;
//    tree.erase(50);

    cout<<tree.getMax()<<endl;
    cout<<tree.getMin()<<endl;


    return 0;
}