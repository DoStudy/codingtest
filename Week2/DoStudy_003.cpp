#include <iostream>
#include "TreeNode.h"
using namespace std;

void main() {
	TreeNode* root = NULL;
	root = root->Insert(12);
	root = root->Insert(5);
	root = root->Insert(15);
	root = root->Insert(3);
	root = root->Insert(4);
	root = root->Insert(7);
	root = root->Insert(6);
	root = root->Insert(13);
	root = root->Insert(17);
	root = root->Insert(1);
	root = root->Insert(9);
	root = root->Insert(19);
	TreeNode* getNode = NULL;
	getNode = root->GetNode(1);
	root->RemoveNode(1);
	root->RemoveNode(17);
	root->RemoveNode(15);
	TreeNode* getRootNode = root->GetRootNode();
	root->GetIncrease();
}