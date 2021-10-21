#pragma once
#include <list>
#include <iostream>
using namespace std;

class TreeNode final
{
private:
	bool RemoveNodePriv(int data);
	void GetIncreasePriv(TreeNode* InputNode);
public:
	TreeNode(int data);
	TreeNode(TreeNode* parent, int data);

	int data;
	TreeNode* mLeft;
	TreeNode* mRight;
	TreeNode* mParent;

	TreeNode* Insert(int data);
	TreeNode* Insert(int data, TreeNode* parent);

	bool RemoveNode(int data);

	TreeNode* GetNode(int data);
	TreeNode* GetRootNode();
	void GetIncrease();
};

TreeNode::TreeNode(int data) {
	this->data = data;
	this->mLeft = nullptr;
	this->mRight = nullptr;
	this->mParent = nullptr;
}

TreeNode::TreeNode(TreeNode* parent, int data) {
	this->data = data;
	this->mLeft = nullptr;
	this->mRight = nullptr;
	this->mParent = parent;
	if (parent->data > data)
		parent->mLeft = this;
	else
		parent->mRight = this;
}

TreeNode* TreeNode::Insert(int data) {
	if (this == nullptr) {
		return new TreeNode(data);
	}
	else {
		if (this->data > data)
			this->mLeft->Insert(data, this);
		else
			this->mRight->Insert(data, this);
	}
	return this;
}

TreeNode* TreeNode::Insert(int data, TreeNode* parent) {
	if (this == nullptr) {
		return new TreeNode(parent, data);
	}
	else {
		if (this->data > data)
			this->mLeft->Insert(data, this);
		else
			this->mRight->Insert(data, this);
	}
	return this;
}

TreeNode* TreeNode::GetNode(int data) {
	if (this == nullptr)
		return NULL;
	else {
		if (this->data == data)
			return this;
		else if (this->data > data)
			return this->mLeft->GetNode(data);
		else
			return this->mRight->GetNode(data);
	}
	return this;
}

bool TreeNode::RemoveNode(int data) {
	if (this == nullptr)
		return false;
	else {
		if (this->data == data)
		{
			return this->RemoveNodePriv(data);
		}
		else if (this->data > data)
			return this->mLeft->RemoveNode(data);
		else
			return this->mRight->RemoveNode(data);
	}
}

bool TreeNode::RemoveNodePriv(int data) {
	if (this->mRight == nullptr && this->mLeft == nullptr)
	{
		this->mParent->mLeft == this ? this->mParent->mLeft = nullptr : this->mParent->mRight = nullptr;
		delete(this);
	}
	else {
		if (this->mRight == nullptr) {
			TreeNode* temp = this->mLeft;
			while (temp->mRight != nullptr) {
				temp = temp->mRight;
			}
			this->data = temp->data;
			//temp->mParent->mRight = nullptr;

			this->mLeft = temp->mLeft;
			return true;
		}
		else if (this->mLeft == nullptr) {
			TreeNode* temp = this->mRight;
			while (temp->mLeft != nullptr) {
				temp = temp->mLeft;
			}
			this->data = temp->data;
			//temp->mParent->mLeft = nullptr;
			this->mRight = temp->mRight;
			return true;
		}
	}
}

TreeNode* TreeNode::GetRootNode() {
	return this;
}

void TreeNode::GetIncrease() {
	GetIncreasePriv(this->mLeft);
	cout << this->data << " ";
	GetIncreasePriv(this->mRight);
}
void TreeNode::GetIncreasePriv(TreeNode* InputNode) {
	if (InputNode == nullptr)
		return;
	GetIncreasePriv(InputNode->mLeft);
	cout << InputNode->data << " ";
	GetIncreasePriv(InputNode->mRight);
}