#include "tools.h"

enum COLOR{RED, BLACK};

/*
 * 红黑树的特性:
    (1) 每个节点或者是黑色，或者是红色。
    (2) 根节点是黑色。
    (3) 每个叶子节点是黑色。 [注意：这里叶子节点，是指为空的叶子节点！]
    (4) 如果一个节点是红色的，则它的子节点必须是黑色的。
    (5) 从一个节点到该节点的子孙节点的所有路径上包含相同数目的黑节点。
 */

template<typename T>
class node
{
public:
    node(const T& val, COLOR color = RED):value(val),color(color){}
    T value;
    node* left;
    node* right;
    node* parent;
    COLOR color;
};

template <typename T>
class rb_tree {
public:
    using iterator = node<T> *;

    rb_tree() : root(NULL) {}

    ~rb_tree() {
        delete_(root);

    }

    void insert(const T &val) {
        iterator iter = root;
        if (root == NULL) {
            iterator tmp = new node<T>(val);
            root = tmp;
            root->color = BLACK;
            return;
        }
        iterator parent = iter;
        while (iter) {
            parent = iter;
            if (val >= iter->value)
                iter = iter->right;
            else
                iter = iter->left;
        }
        iterator tmp = new node<T>(val);
        if (val >= parent->value) {
            parent->right = tmp;
            tmp->parent = parent;
        } else {
            parent->left = tmp;
            tmp->parent = parent;
        }
        insertFixUp(tmp);
    }

    iterator find(const T &val) {
        iterator res = root;
        while (res->value != val) {
            if (val >= res->value)
                res = res->right;
            else
                res = res->left;
        }
        return res;
    }

    void remove(const T &val)
    {
        iterator it = find(val);
        if(!it)
            return ;
        iterator child, parent;
        COLOR color;
        //左右不为空
        if(it->left != NULL && it->right != NULL)
        {
            iterator tmp = it->right;
            while(tmp->left != NULL)//替代节点
            {
                tmp = tmp->left;
            }
           if(rb_parent(it))//不是root节点
           {
               if(rb_parent(it)->left == it)
                   rb_parent(it)->left = tmp;
               else
                   rb_parent(it)->right = tmp;
           }else
               root = tmp;//如果是根节点 更新

               /*
                * 保存替换节点子父节点相关信息
                */
           child = tmp->right;//替代节点的右孩子
           //一定不存在左孩子
           parent = rb_parent(tmp);//替代节点的父节点
           color = tmp->color;//替代节点的颜色

           /*
            * 连接节点
            */
           if(parent == it)//替代节点是删除节点的子节点
           {
               parent = tmp;
           }else
           {
               if(child)
                   child->parent = parent;//设置子节点父亲节点
               //修改父亲节点的子节点
               parent->left = child;

               tmp->right = it->right;
               it->right->parent = tmp;
               //修改删除节点子节点相关信息
           }
           tmp->parent = it->parent;
           tmp->color = it->color;
           tmp->left = it->left;
           //替换节点设置为原节点一样的信息
           it->left->parent = tmp;
           //修改子节点父信息

           if(color == BLACK)//如果替换节点颜色为黑 fixup
               removeFixUp(child, parent);
           //如果颜色为红色，红黑树仍然性质仍然保持
           //1.树中的黑高度没有变化
           //2.不存在两个相邻的红接节点
           //3.如果原节点是红色，就不可能是根节点。所以根结点仍然是黑色
           delete it;
           return ;
        }
        if(it->left != NULL)//右为空
            child = it->left;
        else//左为空
            child = it->right;
        parent = it->parent;

        color = it->color;

        if(child)
            child->parent = parent;
        if(parent)
        {
            if(parent->left == it)
                parent->left = child;
            else
                parent->right = child;
        }else
            root = child;
        if(color == BLACK)
            removeFixUp(child, parent);
        delete it;
    }

private:
    /*
 * 对红黑树的节点(x)进行左旋转
 *
 * 左旋示意图(对节点x进行左旋)：
 *      px                              px
 *     /                               /
 *    x                               y
 *   /  \      --(左旋)-->           / \                #
 *  lx   y                          x  ry
 *     /   \                       /  \
 *    ly   ry                     lx  ly
 *
 *
 */
    void leftRotate(iterator it)
    {
        iterator iter = it;
        iterator iter1 = iter->right;
        iter->right = iter1->left;//child节点的左节点给父节点的右节点
        if(iter1->left)//设置要过继节点的父节点
        {
            iter1->left->parent = iter;
        }
        iter1->parent = iter->parent;//设置字节点的父节点
        if(!iter->parent)//为root节点设置root的值
        {
            root = iter1;
        }else
        {
            if(iter->parent->left == iter)//设置父节点
                iter->parent->left = iter1;
            else
                iter->parent->right = iter1;
        }
        iter1->left = iter;// 将 “x” 设为 “y的左孩子”
        iter->parent = iter1;// 将 “x的父节点” 设为 “y”
    }

    /*
 * 对红黑树的节点(y)进行右旋转
 *
 * 右旋示意图(对节点y进行左旋)：
 *            py                               py
 *           /                                /
 *          y                                x
 *         /  \      --(右旋)-->            /  \                     #
 *        x   ry                           lx   y
 *       / \                                   / \                   #
 *      lx  rx                                rx  ry
 *
 */
    void rightRotate(iterator it)
    {
        iterator iter = it;
        iterator iter1 = it->left;
        iter->left = iter1->right;//过继子节点
        if(iter1->right)
        {
            iter1->right->parent = iter;//设置子节点的父亲
        }
        iter1->parent = iter->parent;//设置父亲
        if(!iter->parent)
        {
            root = iter1;//如果是头节点
        }else
        {
            if(iter->parent->left == iter)
                iter->parent->left = iter1;//设置父节点
            else
                iter->parent->right = iter;
        }
        // 将 “y” 设为 “x的右孩子”
        iter1->right = iter;
        // 将 “y的父节点” 设为 “x”
        iter->parent = iter1;
    }


    // 如果一个节点是红色的，则它的子节点必须是黑色的。
    /*
     * 因为uncle.color==x.p.color==red,所以x.p.p.color==black.（性质3）接下来把x.p.p设置为红色（原为黑色）
     * 把x.p和uncle设置成黑色（原为红色）。那么性质4显然是不变的；并且性质3对于x而言也得到了满足。然而，因为x.p.p的颜色改变了，他有可能违背了性质3。
     * 所以，我们需要把x更新成为x.p.p。
     *
     * 我们第三层假设（uncle此时已经是黑色的了），是x是x.p的左孩子还是右孩子。如果x是x.p的左孩子，我们可以交换x.p与x.p.p的颜色并且对x.p.p进行一次右旋来解决，
     * 并且此循环到此结束。然而，如果x为x.p的左孩子，我们没有可以直接解决的方法；但是，我们可以对x.p进行一次左旋，并且将x更新为原来的x.p，
     * 这样这种情况就会被归于x为x.p的左孩子的情况
     *
    */

    void insertFixUp(iterator it)
    {
        iterator parent, guard;
        while((parent = rb_parent(it)) && rb_is_red(parent))
        {
            guard = rb_parent(parent);
            if(guard->left == parent)//父节点位与左边
            {
                iterator uncle = guard->right;
                //情况一 it的叔叔节点为红色
                if(uncle && rb_is_red(uncle))//父叔节点都为红色 直接改变颜色
                {
                    rb_set_black(parent);
                    rb_set_black(uncle);
                    rb_set_red(guard);
                    it = guard;
                    continue;
                }
                //情况二 it位与父右边
                else if(it == parent->right)//当前节点位与右边-》叔为黑 只由在右边才需要修改父子关系
                {
                    leftRotate(parent);//修改父子节点位置
                    iterator tmp = parent;
                    parent = it;
                    it = tmp;

                }
                //情况三 it位与父左边
                else if(it == parent->left)//修改新父节点和祖父节点位置
                {
                    rb_set_red(guard);
                    rb_set_black(parent);
                    rightRotate(guard);
                }



            }else//同上 只是左右的相反
            {
                iterator uncle = guard->left;
                //情况一 父叔均为红色 族为黑色
                if(uncle && rb_is_red(uncle))
                {
                    rb_set_black(parent);
                    rb_set_black(uncle);
                    rb_set_red(guard);
                    it = guard;
                    continue;
                }
                //情况二 it位与父左边
                else if(it == parent->left)//新节点在左边才需要修改父子关系
                {
                    rightRotate(parent);
                    iterator tmp = parent;
                    parent = it;
                    it = tmp;

                }
                //情况三 it为与父右边
                else if(it == parent->right)//修改父和祖父关系
                {
                    rb_set_black(parent);
                    rb_set_red(guard);
                    leftRotate(guard);
                }
            }
        }
        rb_set_black(root);
    }

    void removeFixUp(iterator it, iterator parent)
    {
        iterator other;
        while((!it || rb_is_black(it)) && it != root)
        {
            if(parent->left == it)
            {
                other = parent->right;
                //情况一 相邻节点为红色 父节点为黑色
                if(rb_is_red(other))
                {
                    //直接修改颜色 使根结点为黑色 父节点为红色 并leftrotate
                    rb_set_black(other);
                    rb_set_red(parent);
                    leftRotate(parent);
                    other = parent->right;
                }
                //情况二 相邻节点为黑色 且子节点都为黑色 父节点为红色
                if((!other->left || rb_is_black(other->left)) && (!other->right || rb_is_black(other->right)))
                {
                    //直接修改颜色为红色
                    rb_set_red(other);
                    it = parent;
                    parent = rb_parent(it);
                }else
                {
                    //情况三 相邻节点为黑色 且右节点为黑色 父节点为红色
                    if(!other->right || rb_is_black(other->right))
                    {
                        rb_set_black(other->left);
                        rb_set_red(other);
                        rightRotate(other);
                        other = parent->right;
                    }
                    //情况四 相邻节点为黑色 右节点为红色 左颜色随意 父节点为红色
                    other->color = parent->color;//o颜色为红色
                    rb_set_black(parent);
                    rb_set_black(other->right);
                    leftRotate(parent);
                    it = root;
                    break;
                }
            }
            else
            {
                other = parent->left;
                //情况一 相邻为红色 父为黑色
                if(rb_is_red(other))
                {
                    rb_set_black(other);
                    rb_set_red(parent);
                    rightRotate(parent);
                    other = parent->left;
                }
                //情况二 相邻左右都为黑色 相邻为黑色 父为红色
                if((!other->left || rb_is_black(other->left)) && (!other->right || rb_is_black(other->right)))
                {
                    //直接修改为红色
                    rb_set_red(other);
                    it = parent;
                    parent = rb_parent(it);
                }
                else
                {
                    //相邻为黑 左为黑 右为红
                    if(!other->left || rb_is_black(other->left))
                    {
                        rb_set_black(other->right);
                        rb_set_red(other);
                        leftRotate(other);
                        other = parent->left;
                    }
                    other->color = parent->color;
                    rb_set_black(parent);
                    rb_set_black(other->left);
                    rightRotate(parent);
                    it = root;
                    break;
                }
            }
        }
        if(it)
            rb_set_black(it);

    }

    iterator rb_parent(iterator it)
    {
        return it->parent;
    }

    bool rb_is_red(iterator it)
    {
        return it->color == RED;
    }

    bool rb_is_black(iterator it)
    {
        return it->color == BLACK;
    }

    void rb_set_red(iterator it)
    {
        it->color = RED;
    }

    void rb_set_black(iterator it)
    {
        it->color = BLACK;
    }

    void delete_(iterator it)
    {
        iterator iter = it;
        if(it != NULL)
        {
            delete_(it->left);
            delete_(it->right);
            delete it;
        }

    }

private:
    iterator root;

};


int main()
{
    rb_tree<int> tree;
    for(int i = 0; i < 10; ++i)
    {
        tree.insert(i);
    }

    tree.remove(5);

    //auto it = tree.find(5);

    return 0;
}

