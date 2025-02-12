#include <iostream>
#include <stack>
using namespace std;

typedef int TYPEINFO;
//==============================================================
/* Cài đặt cấu trúc BST */
struct NODE {
	TYPEINFO data;
	NODE* left;
	NODE* right;
};
typedef NODE* BST;
typedef BST nodeptr;
void initTree(BST& tree);
nodeptr createNode(TYPEINFO data);
void insertTreeByRecursion(BST& tree, TYPEINFO value);
void insertTreeByLoop(BST& tree, TYPEINFO value);
void createBinarySearchTree(BST& tree);
//Tree traversal by recursion
void inorderTraversal_byRecursion(BST tree);
void preorderTraversal_byRecursion(BST tree);
void postorderTraversal_byRecursion(BST tree);
//Tree traversal by loop
void inorderTraversal_byLoop(BST tree);
void preorderTraversal_byLoop(BST tree);
void postorderTraversal_byLoop(BST tree);
// find value
bool findValueInTree_ByRecursion(BST tree, TYPEINFO valueToFind);
bool findValueInTree_ByLoop(BST tree, TYPEINFO valueToFind);
//delete node 
void findLeftMostOnRight(BST& tree, nodeptr p_Tree);
void findRightMostOnLeft(BST& tree, nodeptr p_Tree);
void deleteNodeInTreeWithValueX(BST& tree, TYPEINFO valueX);

//===============================================================

