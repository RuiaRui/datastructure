
#include <stack>  
#include<vector>
#include<queue>
#include <iostream>  

using namespace std;

struct BiTNode {
	int data = 0;
	struct BiTNode *lChild, *rChild;//左右孩子  
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


//主函数  
int main() {
	BiTree *biTree = new BiTree();
	cout << "创建一颗树，输入数据,用-1表示空树:" << endl;
	biTree->root = biTree->CreateBiTree();

	cout << "打印树" << endl;
	biTree->PrintTree(biTree->root, 0);

	cout << "按层级结构输出树"<<endl;
	biTree->levelOrder(biTree->root);

	cout << "想要输入数的第几层？" << endl;
	int lev;
	cin >> lev;
	if (lev > biTree->getTreeHeight(biTree->root)) {
		cout << "这个树没有这么高呀" << endl;
	}
	else {
		biTree->printNodeAtLevel(biTree->root,lev-1);
	}
	system("pause");
}


//先序递归创建二叉树树  
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
		current = new BiTNode;//产生新的子树 
		current->data = val;
		current->lChild = CreateBiTree();
		current->rChild = CreateBiTree();
		return current;
	}
}

//二叉树树状层次结构逆时针反转90度
void BiTree::PrintTree(BiTNode * T, int level)
{

	if (!T)             //如果指针为空，返回上一层  
	{
		return;
	}
	PrintTree(T->rChild, level + 1);    //打印右子树，并将层次加1  
	for (int i = 0; i<level; i++)    //按照递归的层次打印空格  
	{
		cout << "   ";
	}
	cout << T->data << "\n";  //输出根结点  
	PrintTree(T->lChild, level + 1);    //打印左子树，并将层次加1 
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

		// 左子树的 level - 1 级    
		printNodeAtLevel(root->lChild, level - 1);

		// 右子树的 level - 1 级    
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
		cout << endl; //打印完一层，换行  
	}
		
}








