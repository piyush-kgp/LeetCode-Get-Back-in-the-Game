#include <iostream>

class TreeNode{
public:
	int data;
	TreeNode *left, *right;
	TreeNode(int data){
		this->data = data;
		this->left =  nullptr;
		this->right = nullptr;
	}
};

// TreeNode *createNode(int data){
// 	TreeNode *temp = new TreeNode;
// 	temp->data = data;
// 	temp->left = nullptr;
// 	temp->right = nullptr;
// 	return temp;
// }

// Left, Root, Right
void printTreeInOrder(TreeNode *root){
	if (root==nullptr) return;
	printTreeInOrder(root->left);
	std::cout<<root->data<<' ';
	printTreeInOrder(root->right);
}

// Root, Left, Right
void printTreePreOrder(TreeNode *root){
	if (root==nullptr) return;
	std::cout<<root->data<<' ';
	printTreePreOrder(root->left);
	printTreePreOrder(root->right);
}

// Left, Right, Root
void printTreePostOrder(TreeNode *root){
	if (root==nullptr) return;
	printTreePostOrder(root->left);
	printTreePostOrder(root->right);
	std::cout<<root->data<<' ';
}

int main(){
	TreeNode *root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->left->left = new TreeNode(4);
	root->left->right = new TreeNode(5);
	root->right->left = new TreeNode(6);
	root->right->right = new TreeNode(7);
	// TreeNode *root = createNode(1);
	// root->left = createNode(2);
	// root->right = createNode(3);
	// root->left->left =createNode(4);
	// root->left->right = createNode(5);
	// root->right->left = createNode(6);
	// root->right->right = createNode(7);
	std::cout<<"Pre Order Traversal"<<std::endl; printTreePreOrder(root); std::cout<<std::endl;
	std::cout<<"In Order Traversal"<<std::endl; printTreeInOrder(root); std::cout<<std::endl;
	std::cout<<"Post Order Traversal"<<std::endl; printTreePostOrder(root); std::cout<<std::endl;
	return 0;
}
