
#include <stack>  
#include<vector>
#include<queue>
#include <iostream>  

using namespace std;

struct BiTNode {
	int data = 0;
	struct BiTNode *lChild, *rChild;//���Һ���  
};

class BiTree {
private:


public:
	BiTNode *root;


	BiTNode * CreateBiTree();
	void PrintTree(BiTNode *T, int level);
	

	int getTreeHeight(BiTNode* root);
	void printNodeAtLevel(BiTNode* root, int leve);
	void levelOrder( BiTNode* root);
};


//������  
int main() {
	BiTree *biTree = new BiTree();
	cout << "����һ��������������,��-1��ʾ����:" << endl;
	biTree->root = biTree->CreateBiTree();

	cout << "��ӡ��" << endl;
	biTree->PrintTree(biTree->root, 0);

	cout << "���㼶�ṹ�����"<<endl;
	biTree->levelOrder(biTree->root);

	cout << "��Ҫ�������ĵڼ��㣿" << endl;
	int lev;
	cin >> lev;
	if (lev > biTree->getTreeHeight(biTree->root)) {
		cout << "�����û����ô��ѽ" << endl;
	}
	else {
		biTree->printNodeAtLevel(biTree->root,lev-1);
	}
	system("pause");
}


//����ݹ鴴����������  
BiTNode * BiTree::CreateBiTree()
{
	int val;
	BiTNode *current = new BiTNode();
	cin >> val;

	if (val == -1) {
		return current = NULL;
	}
	else
	{
		current = new BiTNode;//�����µ����� 
		current->data = val;
		current->lChild = CreateBiTree();
		current->rChild = CreateBiTree();
		return current;
	}
}

//��������״��νṹ��ʱ�뷴ת90��
void BiTree::PrintTree(BiTNode * T, int level)
{

	if (!T)             //���ָ��Ϊ�գ�������һ��  
	{
		return;
	}
	PrintTree(T->rChild, level + 1);    //��ӡ��������������μ�1  
	for (int i = 0; i<level; i++)    //���յݹ�Ĳ�δ�ӡ�ո�  
	{
		cout << "   ";
	}
	cout << T->data << "\n";  //��������  
	PrintTree(T->lChild, level + 1);    //��ӡ��������������μ�1 
}


int BiTree::getTreeHeight(BiTNode* root){
	if (nullptr == root)
		return 0;
	int leftHeight = getTreeHeight(root->lChild);
	int rightHeight = getTreeHeight(root->rChild);
	return max(leftHeight, rightHeight) + 1;
}


void BiTree::printNodeAtLevel(BiTNode* root, int level){
	
		if (nullptr == root || level < 0)
			return;

		if (0 == level)
		{
			cout << root->data << " ";
			return;
		}

		// �������� level - 1 ��    
		printNodeAtLevel(root->lChild, level - 1);

		// �������� level - 1 ��    
		printNodeAtLevel(root->rChild, level - 1);
	}

void BiTree::levelOrder(BiTNode* root)
{
	if (nullptr == root)
		return;
	int totalLevel = getTreeHeight(root);
	for (int i = 0; i < totalLevel; i++)
	{
		printNodeAtLevel(root, i);
		cout << endl; //��ӡ��һ�㣬����  
	}
		
}








