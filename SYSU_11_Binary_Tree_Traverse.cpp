/*
Description
请完成以下AVLTree的查找、插入函数的定义：
*/

// 参考资料：http://blog.chinaunix.net/uid-25324849-id-2182877.html 
#ifndef AVL_NODE
#define AVL_NODE

template <class Entry>
struct AvlNode
{
         Entry entry;
         AvlNode<Entry> *left;
         AvlNode<Entry> *right;
         int bf;                // balance factor
         int height;  //  The height of this node(subtree)
};
#endif

// 查找AVL树里面是否有元素entry，如果有则返回该结点，没有则返回NULL
template <class Entry>
AvlNode<Entry> *AVL_search(AvlNode<Entry> *&root, const Entry entry) {
    if (root = NULL)
        return NULL;
    if (root->entry == entry) {
        return root;
    } else {  //  AVL树本质上是binary search tree 
        if (entry < root->entry)
            return AVL_search(root->left, entry);
        else
            return AVL_search(root->right, entry);
    }
}

template <class Entry>
int getHeight(AvlNode<Entry> *node) {
    if (node == NULL)  //  NULL的情况不要忘记单独处理；若为空树，则高度为0
        return 0;
    else
        return node->height;
}

//  比较左右子树的高度，返回高度较大的子树，用以确定根的高度 
int Larger(int a, int b) {
    return a >= b ? a : b;
}

//   情况1：对该结点的左儿子的左子树进行了一次插入 
template <class Entry>
void RotateWithLeft(AvlNode<Entry>* &node) {
    AvlNode<Entry>* temp;
    temp = node->left;
    node->left = temp->right;
    temp->right = node;
    node->height = Larger(getHeight(node->left), getHeight(node->right)) + 1;
    temp->height = Larger(getHeight(temp->left), node->height) + 1;
    node = temp;
}

//   情况2：对该结点的右儿子的右子树进行了一次插入 
template <class Entry>
void RotateWithRight(AvlNode<Entry>* &node) {
    AvlNode<Entry>* temp;
    temp = node->right;
    node->right = temp->left;
    temp->left = node;
    node->height = Larger(getHeight(node->left), getHeight(node->right)) + 1;
    temp->height = Larger(getHeight(temp->left), node->height) + 1;
    node = temp;
}

//   情况3：对该结点的左儿子的右子树进行了一次插入
template <class Entry>
void DoubleRotateWithLeft(AvlNode<Entry>* &node) {
    RotateWithRight(node->left);
    RotateWithLeft(node);
}

//   情况4：对该结点的右儿子的左子树进行了一次插入
template <class Entry>
void DoubleRotateWithRight(AvlNode<Entry>* &node) {
    RotateWithLeft(node->right);
    RotateWithRight(node);
}

// 将entry插入到AVL树
template <class Entry>
void AVL_insert(AvlNode<Entry> *&root, const Entry entry) {
    if (root == NULL) {  //  递归终止条件，创建并加入该元素 
        root = new AvlNode<Entry>;
        root->left = NULL;
        root->right = NULL;
        root->entry = entry;
    } else if (entry < root->entry) {  //  在左子树递归查找并插入 
        AVL_insert(root->left, entry);  //  先插入 
        if (getHeight(root->left) - getHeight(root->right) >= 2) {  // 再旋转调整 
            if (entry < root->left->entry) {  //  在左子树的左子树插入 
                RotateWithLeft(root);
            } else {    //  在左子树的右子树插入 
                DoubleRotateWithLeft(root);
            }
        } 
    } else if (entry > root->entry) {  //  在右子树递归查找并插入 
        AVL_insert(root->right, entry);
        if (getHeight(root->right) - getHeight(root->left) >= 2) {
            if (entry > root->right->entry) {  //  在右子树的右子树插入 
                RotateWithRight(root);
            } else {  //  在右子树的左子树插入 
                DoubleRotateWithRight(root);
            }
        }
    } else if (entry == root->entry) {
        // Do nothing
    }
    root->height = Larger(getHeight(root->left), getHeight(root->right)) + 1;  //  别忘记更新插入后根的高度 
}
