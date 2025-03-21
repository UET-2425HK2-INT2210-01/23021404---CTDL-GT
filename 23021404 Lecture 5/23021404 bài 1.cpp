#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* buildTree(int parent[], int N) {
    TreeNode* nodes[N + 1] = {NULL};
    bool isChild[N + 1] = {false};

    for (int i = 1; i <= N; i++) {
        nodes[i] = new TreeNode(i);
    }

    for (int i = 1; i <= N; i++) {
        if (parent[i] != -1) {
            if (!nodes[parent[i]]->left)
                nodes[parent[i]]->left = nodes[i];
            else
                nodes[parent[i]]->right = nodes[i];
            isChild[i] = true;
        }
    }

    for (int i = 1; i <= N; i++) {
        if (!isChild[i]) return nodes[i];
    }
    return NULL;
}

void preorder(TreeNode* root) {
    if (!root) return;
    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(TreeNode* root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->val << " ";
}

void inorder(TreeNode* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int treeHeight(TreeNode* root) {
    if (!root) return 0;
    return max(treeHeight(root->left), treeHeight(root->right)) + 1;
}

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
    cin >> N >> M;
    int parent[N + 1];
    for (int i = 1; i <= N; i++) parent[i] = -1;
    
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        parent[v] = u;
    }
    
    TreeNode* root = buildTree(parent, N);
    cout << treeHeight(root) - 1 << endl;
    preorder(root); cout << endl;
    postorder(root); cout << endl;
    
    if (isBinaryTree(root)) {
        inorder(root);
    } else {
        cout << "NOT BINARY TREE";
    }
    cout << endl;
    
    return 0;
}

