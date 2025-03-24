#include <iostream>

using namespace std;

// Ð?nh ngh?a c?u trúc nút cây nh? phân
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Hàm xây d?ng cây t? danh sách cha-con
TreeNode* buildTree(int parent[], int N) {
    TreeNode* nodes[N + 1] = {NULL}; // M?ng lýu các nút c?a cây
    bool isChild[N + 1] = {false}; // Ðánh d?u các nút con

    // Kh?i t?o các nút
    for (int i = 1; i <= N; i++) {
        nodes[i] = new TreeNode(i);
    }

    // Gán quan h? cha-con gi?a các nút
    for (int i = 1; i <= N; i++) {
        if (parent[i] != -1) {
            if (!nodes[parent[i]]->left)
                nodes[parent[i]]->left = nodes[i];
            else
                nodes[parent[i]]->right = nodes[i];
            isChild[i] = true;
        }
    }

    // T?m g?c c?a cây (nút không ph?i con c?a b?t k? nút nào)
    for (int i = 1; i <= N; i++) {
        if (!isChild[i]) return nodes[i];
    }
    return NULL;
}

// Duy?t cây theo th? t? trý?c (Preorder)
void preorder(TreeNode* root) {
    if (!root) return;
    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}

// Duy?t cây theo th? t? sau (Postorder)
void postorder(TreeNode* root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->val << " ";
}

// Duy?t cây theo th? t? gi?a (Inorder)
void inorder(TreeNode* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

// Tính chi?u cao c?a cây
int treeHeight(TreeNode* root) {
    if (!root) return 0;
    return max(treeHeight(root->left), treeHeight(root->right)) + 1;
}

// Ki?m tra cây có ph?i là cây nh? phân h?p l? không
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
    cin >> N >> M; // Nh?p s? lý?ng nút và s? lý?ng c?nh
    int parent[N + 1];
    for (int i = 1; i <= N; i++) parent[i] = -1;
    
    // Nh?p danh sách các c?nh
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        parent[v] = u;
    }
    
    // Xây d?ng cây và t?m g?c
    TreeNode* root = buildTree(parent, N);
    
    // In ra chi?u cao c?a cây (tr? 1 ð? tính s? m?c t? g?c ð?n lá)
    cout << treeHeight(root) - 1 << endl;
    
    // In k?t qu? duy?t cây theo các phýõng pháp khác nhau
    preorder(root); cout << endl;
    postorder(root); cout << endl;
    
    // Ki?m tra xem có ph?i cây nh? phân h?p l? không
    if (isBinaryTree(root)) {
        inorder(root);
    } else {
        cout << "NOT BINARY TREE";
    }
    cout << endl;
    
    return 0;
}

