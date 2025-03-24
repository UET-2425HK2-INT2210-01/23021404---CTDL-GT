#include <iostream>

using namespace std;

// �?nh ngh?a c?u tr�c n�t c�y nh? ph�n
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// H�m x�y d?ng c�y t? danh s�ch cha-con
TreeNode* buildTree(int parent[], int N) {
    TreeNode* nodes[N + 1] = {NULL}; // M?ng l�u c�c n�t c?a c�y
    bool isChild[N + 1] = {false}; // ��nh d?u c�c n�t con

    // Kh?i t?o c�c n�t
    for (int i = 1; i <= N; i++) {
        nodes[i] = new TreeNode(i);
    }

    // G�n quan h? cha-con gi?a c�c n�t
    for (int i = 1; i <= N; i++) {
        if (parent[i] != -1) {
            if (!nodes[parent[i]]->left)
                nodes[parent[i]]->left = nodes[i];
            else
                nodes[parent[i]]->right = nodes[i];
            isChild[i] = true;
        }
    }

    // T?m g?c c?a c�y (n�t kh�ng ph?i con c?a b?t k? n�t n�o)
    for (int i = 1; i <= N; i++) {
        if (!isChild[i]) return nodes[i];
    }
    return NULL;
}

// Duy?t c�y theo th? t? tr�?c (Preorder)
void preorder(TreeNode* root) {
    if (!root) return;
    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}

// Duy?t c�y theo th? t? sau (Postorder)
void postorder(TreeNode* root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->val << " ";
}

// Duy?t c�y theo th? t? gi?a (Inorder)
void inorder(TreeNode* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

// T�nh chi?u cao c?a c�y
int treeHeight(TreeNode* root) {
    if (!root) return 0;
    return max(treeHeight(root->left), treeHeight(root->right)) + 1;
}

// Ki?m tra c�y c� ph?i l� c�y nh? ph�n h?p l? kh�ng
bool isBinaryTree(TreeNode* root) {
    if (!root) return true;
    int childCount = 0;
    if (root->left) childCount++;
    if (root->right) childCount++;
    if (childCount > 2) return false;
    return isBinaryTree(root->left) && isBinaryTree(root->right);
}

int main() {
    int N, M;
    cin >> N >> M; // Nh?p s? l�?ng n�t v� s? l�?ng c?nh
    int parent[N + 1];
    for (int i = 1; i <= N; i++) parent[i] = -1;
    
    // Nh?p danh s�ch c�c c?nh
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        parent[v] = u;
    }
    
    // X�y d?ng c�y v� t?m g?c
    TreeNode* root = buildTree(parent, N);
    
    // In ra chi?u cao c?a c�y (tr? 1 �? t�nh s? m?c t? g?c �?n l�)
    cout << treeHeight(root) - 1 << endl;
    
    // In k?t qu? duy?t c�y theo c�c ph��ng ph�p kh�c nhau
    preorder(root); cout << endl;
    postorder(root); cout << endl;
    
    // Ki?m tra xem c� ph?i c�y nh? ph�n h?p l? kh�ng
    if (isBinaryTree(root)) {
        inorder(root);
    } else {
        cout << "NOT BINARY TREE";
    }
    cout << endl;
    
    return 0;
}

