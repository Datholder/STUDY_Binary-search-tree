#include "library-BST.h"

int main() {
	BST tree;
	initTree(tree);
	TYPEINFO valueToFind, valueToDelete;
	int choice;
	do
	{
		cout << "\n\nBinary search tree program.\n";
		cout << "1: Create binary search tree.\n";
		cout << "2: Inorder  traversal by loop.\n";
		cout << "3: Preorder traversal by loop.\n";
		cout << "4: Postorder traversal by loop.\n";
		cout << "5: Inorder traversal by recursion.\n";
		cout << "6: Preorder traversal by recursion.\n";
		cout << "7: Postorder traversal by recursion.\n";
		cout << "8: Find value in tree by loop.\n";
		cout << "9: Find value in tree by recursion.\n";
		cout << "10: Delete node in tree.\n";
		cout << "-99: break program.\n";
		cout << "ENTER YOUR CHOICE: "; cin >> choice;

		switch (choice){
		case 1: createBinarySearchTree(tree);
			break;
		case 2:
			if (tree == nullptr) {
				cout << "Tree is empty, please create tree!\n";
			}
			else {
				cout << "\nInorder by loop: ";
				inorderTraversal_byLoop(tree);
			}
			break;
		case 3:
			if (tree == nullptr) {
				cout << "Tree is empty, please create tree!\n";
			}
			else {
				cout << "\nPreorder by loop: ";
				preorderTraversal_byLoop(tree);
			}
			break;
		case 4:
			if (tree == nullptr) {
				cout << "Tree is empty, please create tree!\n";
			}
			else {
				cout << "\nPostorder by loop: ";
				preorderTraversal_byLoop(tree);
			}
			break;
		case 5:
			if (tree == nullptr) {
				cout << "Tree is empty, please create tree!\n";
			}
			else {
				cout << "\nInorder by recursion: ";
				inorderTraversal_byRecursion(tree);
			}
			break;
		case 6:
			if (tree == nullptr) {
				cout << "Tree is empty, please create tree!\n";
			}
			else {
				cout << "\nPreorder by recursion: ";
				preorderTraversal_byRecursion(tree);
			}
			break;
		case 7: 
			if (tree == nullptr) {
				cout << "Tree is empty, please create tree!\n";
			}
			else {
				cout << "\nPostorder by recursion: ";
				postorderTraversal_byRecursion(tree);
			}
			break;
		case 8:
			if (tree == nullptr) {
				cout << "Tree is empty, please create tree!\n";
			}
			else {
				cout << "\nEnter value to find: "; cin >> valueToFind;
				if (findValueInTree_ByLoop(tree, valueToFind))
					cout << "\nFind " << valueToFind << " in this tree!";
				else {
					cout << "\nDon't find!";
				}
			}
			break;
		case 9:
			if (tree == nullptr) {
				cout << "Tree is empty, please create tree!\n";
			}
			else {
				cout << "\nEnter value to find: "; cin >> valueToFind;
				if (findValueInTree_ByRecursion(tree, valueToFind))
					cout << "\nFind " << valueToFind << " in this tree!";
				else {
					cout << "\nDon't find!";
				}
			}
			break;
		case 10:
			if (tree == nullptr) {
				cout << "Tree is empty, please create tree!\n";
			}
			else {
				cout << "\nEnter value to delete: "; cin >> valueToDelete;
				deleteNodeInTreeWithValueX(tree, valueToDelete);
				cout << "\nDeleted successfully.";
			}
			break;
		default:
			break;
		}

	} while (choice != -99);
	return 0;
}