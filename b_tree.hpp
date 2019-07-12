//
// Created by soft01 on 19-7-10.
//
/*
 * B树 未运行
 */

#ifndef TEST_B_TREE_HPP
#define TEST_B_TREE_HPP

#include "tools.h"

#include <vector>

const size_t Maxm = 10;
const size_t m = 4;//阶数
const size_t Max = 2 * m - 1;//每个结点最多有m-1个关键字
const size_t Min = m - 1;//非根结点至少有(m/2)-1个关键字
const size_t ChildMax = Max + 1;
const size_t ChildMin = Min + 1;
/*
 * 每个节点最多有2m-1个原属
 */

template<typename T>
class BNode {
public:
    std::vector<T> keys_;
    std::vector<BNode *> ptrs_;//多一
    BNode *parent_;
    bool leaf_;
    int keyNum_;
    BNode()
        :parent_(NULL),
        keys_(Max),
        ptrs_(ChildMax),
        keyNum_(0)
    {}
};

template<typename T>
class B_tree {
public:
    using iterator = BNode<T> *;
    using node = BNode<T>;

    B_tree() : root(NULL) {}

    ~B_tree() {

    }

    bool search(const T &val) const {
        if (root == NULL)
            return false;
        else
            return search_(root, val);
    }

    bool insert(const T &val) {
        //iterator iter = root;
        if (root == NULL) {
            iterator tmp = new node();
            tmp->leaf_ = false;
            root = tmp;
        }
        if (root->keyNum_ == Max)//超过长度
        {
            iterator s = new node();
            s->leaf_ = false;
            s->ptrs_.emplace_back(root);//添加子节点
            splitChild(s, 0, root);
            root = s;//使新节点成为头节点，从下向上增长
        }
        return insertNonfull(root, val);
    }

    bool remove(const T &val) {
        if (!search(val))
            return false;
        if (root->keyNum_ == 1) {
            if (root->leaf_) {
                root->keys_.clear();
                return true;
            } else {
                iterator child1 = root->ptrs_[0];
                iterator child2 = root->ptrs_[1];
                if (child1->keyNum_ == Min && child2->keyNum_ == Min)//左右子节点个数过短 需要合并
                {
                    mergeChild(root, 0);
                    deleteNode(root);
                    root = child1;
                }
            }
        }
        recursiveRemove(root, val);
        return true;
    }

private:
    /*
     * 非满节点插入
     *
     */
    bool insertNonfull(iterator it, const T &val) {
        int i = it->keyNum_;
        if (it->leaf_)//如果是叶子节点
        {
            while (i > 0 && val < it->keys_[i - 1]) {
                it->keys_[i] = it->keys_[i - 1];
                --i;
            }
            it->keys_[i] = val;
            ++it->keyNum_;
        } else {
            while (i > 0 && val < it->keys_[i - 1])
                --i;
            iterator child = it->ptrs_[i];
            if (child->keyNum_ == Max)//需要切割
            {
                splitChild(it, i, child);
                if (val > it->keys_[i])
                    child = it->ptrs_[i + 1];
            }
            insertNonfull(child, val);
        }
    }

    /*
     * 插入中生成新节点 为parent 原parent变为左兄弟
     * child为左节点 将child的内容切分 迁移到右兄弟和父节点上
     */
    void splitChild(iterator parent, int idx, iterator child) {
        iterator right = new node();//brother
        right->leaf_ = child->leaf_;
        right->keyNum_ = Min;
        for (size_t i = 0; i < Min; ++i)//将右半部复制到兄弟节点上
        {
            right->keys_[i] = child->keys_[i + ChildMin];
        }
        if (!child->leaf_)//如果不是叶子节点，拷贝子节点指针
        {
            for (size_t i = 0; i < ChildMin; ++i)
                right->ptrs_[i] = child->ptrs_[i + ChildMin];
        }
        child->keyNum_ = Min;//更新左子树节点个数
        for (size_t i = parent->keyNum_; i > idx; --i)//将idx后的所有关键字后
        {
            parent->ptrs_[i + 1] = parent->ptrs_[i];
            parent->keys_[i + 1] = parent->keys_[i];
        }
        ++parent->keyNum_;
        parent->ptrs_[idx + 1] = right;
        parent->keys_[idx] = child->keys_[Min];
    }

    bool search_(iterator it, const T &val) const {
        size_t i = 0;
        for (; i < it->keyNum_ && val > it->keys_[i]; ++i) {}
        if (i < it->keyNum_ && val == it->keys_[i])
            return true;
        else {
            if (it->leaf_)
                return false;
            else {
                return search_(it->ptrs_[i], val);
            }
        }

    }

    void deleteNode(iterator it) {
        if (it) {
            delete it;
            it = NULL;
        }
    }

    /*
     * 分裂的逆向操作
     */
    void mergeChild(iterator parent, int idx) {
        iterator child1 = parent->ptrs_[idx];
        iterator child2 = parent->ptrs_[idx + 1];
        child1->keyNum_ = Max;
        child1->keys_[Min] = parent->keys_[idx];//获取中间值
        size_t i = 0;
        for (; i < Min; ++i)//迁移数据
        {
            child1->keys_[i + Min + 1] = child1->keys_[i];
        }
        if (!child1->leaf_)//迁移子节点指针
        {
            for (i = 0; i < ChildMin; ++i) {
                child1->ptrs_[i + ChildMin] = child2->ptrs_[i];
            }
        }
        --parent->keyNum_;
        for (i = idx; i < parent->keyNum_; ++i)//回填父节点的空位
        {
            parent->keys_[i] = parent->keys_[i + 1];
            parent->ptrs_[i + 1] = parent->ptrs_[i + 2];
        }
        deleteNode(child2);
    }

    /*
     * 递归删除关键字
     */
    void recursiveRemove(iterator it, const T &val) {
        size_t i = 0;
        while (i < it->keyNum_ && val < it->keys_[i])//寻找关键字
            ++i;
        if (i < it->keyNum_ && val == it->keys_[i]) {//在当前节点找到关键字
            if (it->leaf_) {//叶节点就直接删除
                --it->keyNum_;
                for (; i < it->keyNum_; ++i) {
                    it->keys_[i] = it->keys_[i + 1];
                }
                return;
                //是内部节点
            } else {
                iterator child1 = it->ptrs_[i];//左子节点
                iterator child2 = it->ptrs_[i + 1];//右子节点
                if (child1->keyNum_ >= ChildMin) {
                    //如果左子节点节点数较多
                    //获取左子节点的最大值
                    T preKey = getPredecessor(child1);
                    recursiveRemove(child1, preKey);
                    it->keys_[i] = preKey;
                    //最大值替换要删除的值 替换后性质不变
                    return ;
                }else if(child2->keyNum_ == ChildMin)
                {
                    //如果右子节点值较多
                    //选择右子节点最小的值
                    T nexKey = getSuccessor(child2);
                    recursiveRemove(child2, nexKey);
                    it->keys_[i] = nexKey;
                    //替换 替换后性质不变
                    return ;
                }else
                {
                    //如果左右子节点数量较小
                    //合并
                    mergeChild(it, i);
                    recursiveRemove(child1, val);
                }
            }
        }else
            //不在当前节点中
        {
            iterator child = it->ptrs_[i];
            //子节点
            //子节点节点数量少
            if(it->keyNum_ == Min)
            {
                //左兄弟节点
                iterator left = i > 0 ? it->ptrs_[i - 1] : NULL;
                //右兄弟节点
                iterator right = i < it->keyNum_ ? it->ptrs_[i + 1] : NULL;
                int j = 0;
                //左兄弟节点数量足够
                if(left && left->keyNum_ >= ChildMin)
                {
                    //将父节点的i-1值下移到child中
                    for(j = child->keyNum_; j > 0; --j)
                    {
                        child->keys_[j] = child->keys_[j - 1];
                    }
                    child->keys_[0] = it->keys_[i - 1];
                    //如果不是页节点
                    //拷贝父节点子节点指针
                    if(!left->leaf_)
                    {
                        for(j = child->keyNum_ + 1; j > 0; --j)
                        {
                            child->ptrs_[j] = child->ptrs_[j - 1];
                        }
                        child->ptrs_[0] = left->ptrs_[left->keyNum_];
                    }
                    ++child->keyNum_;
                    it->keys_[i] = left->keys_[left->keyNum_ - 1];
                    ////pLeft节点中的最大关键字上升到pNode中
                    --left->keyNum_;
                }else if(right && right->keyNum_ >= ChildMin)
                {
                    child->keys_[child->keyNum_] = it->keys_[i];
                    ++child->keyNum_;
                    it->keys_[i] = right->keys_[0];
                    --right->keyNum_;
                    for(j = 0; j < right->keyNum_; ++j)
                    {
                        right->keys_[j] = right->keys_[j + 1];
                    }
                    if(!right->leaf_)
                    {
                        child->ptrs_[child->keyNum_] = right->ptrs_[0];
                        for(j = 0; j < right->keyNum_; ++j)
                        {
                            right->ptrs_[j] = right->ptrs_[j + 1];
                        }
                    }
                    //左右兄弟节点都只包含CHILD_MIN-1个节点
                }else if(left)//与左兄弟合并
                {
                    mergeChild(it, i - 1);
                    child = left;
                }
                else if(right)//与右兄弟合并
                    mergeChild(it, i);
            }
            recursiveRemove(child, val);

        }
    }

    /*
     * 获取it的左子叶子节点的最大值
     */
    T getPredecessor(iterator it)
    {
        while(!it->leaf_)//一直到叶子节点
        {
            it = it->ptrs_[it->keyNum_];
        }
        return it->keys_[it->keyNum_ - 1];
    }

    /*
     * 获取it的右子节点的最小值
     */
    T getSuccessor(iterator it)
    {
        while(!it->leaf_)
        {
            it = it->ptrs_[0];
        }
        return it->keys_[0];
    }


private:
    iterator root;

};





#endif //TEST_B_TREE_HPP
