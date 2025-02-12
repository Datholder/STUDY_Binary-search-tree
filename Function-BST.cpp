#include "library-BST.h"
// INIT TREE
void initTree(BST& tree) {
	tree = nullptr;
}
//CREATE NODE
nodeptr createNode(TYPEINFO data) {
	nodeptr newNode = new NODE;
	newNode->data = data;
	newNode->left = nullptr;
	newNode->right = nullptr;
	return newNode;
}
// INSERT TREE
// by recursion
void insertTreeByRecursion(BST& tree, TYPEINFO value) {
	if (tree == nullptr) {
		tree = createNode(value);
	}
	else {
		if (tree->data == value) {
			cout << "Duplicate value!\n";
			return;
		}
		else if (tree->data > value) {
			insertTreeByRecursion(tree->left, value);
		}
		else
			insertTreeByRecursion(tree->right, value);
	}
}
//by loop
void insertTreeByLoop(BST& tree, TYPEINFO value) {
	if (tree == nullptr) {
		tree = createNode(value);
		return;
	}
	nodeptr current = tree;
	nodeptr parent = nullptr;
	while (current != nullptr) {
		parent = current;
		if (current->data == value) {
			cout << "Duplicate value!\n";
			return;
		}
		else if (current->data > value) {
			current = current->left;
		}
		else current = current->right;
	}
	if (parent->data > value)
		parent->left = createNode(value);
	else
		parent->right = createNode(value);
}
// CREATE BST
void createBinarySearchTree(BST& tree) {
	TYPEINFO data;
	while (true) {
		cout << "Enter data (-99 break): "; cin >> data;
		if (data != -99) {
			//insertTreeByLoop(tree, data);
			insertTreeByRecursion(tree, data);
		}
		else break;
	}
}
//Tree traversal by recursion
void inorderTraversal_byRecursion(BST tree) {
	if (tree != nullptr) {
		inorderTraversal_byRecursion(tree->left);
		cout << tree->data << "\t";
		inorderTraversal_byRecursion(tree->right);
	}
}
void preorderTraversal_byRecursion(BST tree) {
	if (tree != nullptr) {
		cout << tree->data << "\t";
		preorderTraversal_byRecursion(tree->left);
		preorderTraversal_byRecursion(tree->right);
	}
}
void postorderTraversal_byRecursion(BST tree) {
	if (tree != nullptr) {
		postorderTraversal_byRecursion(tree->left);
		postorderTraversal_byRecursion(tree->right);
		cout << tree->data << "\t";
	}
}

//Tree traversal by loop
void inorderTraversal_byLoop(BST tree) {
	if (tree == nullptr) return;
	stack<NODE*> Stack;
	NODE* current = tree;
	while (current != nullptr || !Stack.empty()) {
		// Step 1: Go to the leftmost leaf node
		while (current != nullptr) {
			Stack.push(current);
			current = current->left;
		}
		// Step 2: Process the node at the top of the stack
		current = Stack.top();
		Stack.pop();
		cout << current->data << "\t";
		// Step 3: Switch to the right branch
		current = current->right;
	}
}
void preorderTraversal_byLoop(BST tree) {
	if (tree == nullptr) return;
	stack<NODE*> Stack;
	NODE* current = tree;
	Stack.push(current);
	while (!Stack.empty()) {
		// Step 1: Get the top element of the stack and process it
		current = Stack.top();
		Stack.pop();
		cout << current->data<<"\t";
		// Step 2: Push the right branch first, then the left branch 
		//(to ensure the order Left -> Right)
		if (current->right != nullptr)
			Stack.push(current->right);
		if (current->left != nullptr)
			Stack.push(current->left);
	}
}


void postorderTraversal_byLoop(BST tree) {
	if (!tree)
		return;
	stack<NODE*>Stack;
	NODE* current = tree;
	while (current != nullptr || !Stack.empty()) {
		if (current != nullptr) {
			Stack.push(current);
			current = current->left;
		}
		else {
			NODE* temp = Stack.top()->right;
			if (temp == nullptr) {
				temp = Stack.top();
				Stack.pop();
				cout << temp->data << "\t";
				while (!Stack.empty() && temp == Stack.top()->right) {
					temp = Stack.top();
					Stack.pop();
					cout << temp->data << "\t";
				}
			}
			else {
				current = temp;
			}
		}
	}
}
//=================================================
/*
	1. Find value in tree by loop or recursion.
	2. Insert value into an existing tree use loop or recursion. => completed
	3. Delete node in tree by loop or recursion.

*/

// 1: Find value in tree
// by recursion
bool findValueInTree_ByRecursion(BST tree, TYPEINFO valueToFind){
	if (tree == nullptr)
		return false;
	else if (tree->data == valueToFind)
		return true;
	else if (tree->data > valueToFind)
		return findValueInTree_ByRecursion(tree->left, valueToFind);
	else
		return findValueInTree_ByRecursion(tree->right, valueToFind);
}
// by loop
bool findValueInTree_ByLoop(BST tree, TYPEINFO valueToFind) {
	NODE* current = tree;
	while (current != nullptr) {
		if (current->data == valueToFind)
			return true;
		else if (current->data > valueToFind)
			current = current->left;
		else current = current->right;
	}
	return false;
}


// Delete node: this is a big problem for me.
// write function find left most on right or find right most on left
void findLeftMostOnRight(BST& tree, nodeptr p_Tree) {
	if (tree->left != nullptr) {
		tree = tree->left;
	}
	else {
		p_Tree->data = tree->data;
		nodeptr temp = tree;
		tree = tree->right;
		delete temp;
	}
}
void findRightMostOnLeft(BST& tree, nodeptr p_Tree) {
	if (tree->right != nullptr) {
		tree = tree->right;
	}
	else {
		p_Tree->data = tree->data;
		nodeptr temp = tree;
		tree = tree->left;
		delete temp;
	}
}
void deleteNodeInTreeWithValueX(BST& tree, TYPEINFO valueX) {
	if (tree == nullptr)
		return;
	else {
		if (tree->data > valueX)
			deleteNodeInTreeWithValueX(tree->left, valueX);

		else if (tree->data < valueX) 
			deleteNodeInTreeWithValueX(tree->right, valueX);
		
		else {
			if (tree->left == nullptr && tree->right == nullptr)
				delete tree;
			else if (tree->left == nullptr) {
				nodeptr temp = tree;
				tree = tree->right;
				delete temp;
			}
			else if (tree->right == nullptr) {
				nodeptr temp = tree;
				tree = tree->left;
				delete temp;
			}
			else {
				findLeftMostOnRight(tree->right, tree);
				//findRightMostOnLeft(tree->left, tree);
			}
		}
	}
}