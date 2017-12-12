
#include <stack>  
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

	void NotReInOrder();

	void PrintTree(BiTNode *T, int level);

	BiTNode * arrayTotree(int a[], int start, int end);
};


//主函数  
int main() {
	BiTree *biTree = new BiTree();
	/*cout << "创建一颗树，输入数据,用-1表示空树:" << endl;
	biTree->root = biTree->CreateBiTree();*/

	int a[7] = { 1,2,3,4,5,6,7};
	int m = sizeof(a) / sizeof(a[0]);
	cout << "输出数组" << endl;
	for (int i = 0; i < m; i++) {
		cout << a[i] << "  ";
	}
	cout << endl;
	cout << "按照中序遍历创建树" << endl;
	biTree->root = biTree->arrayTotree(a, 0, m-1);

	cout << "打印树" << endl;
	biTree->PrintTree(biTree->root, 0);


	system("pause");
}




//按照中序遍历的方法转换到二叉树中。先要确定一个根节点，然后递归创建

BiTNode * BiTree::arrayTotree(int a[], int start, int end)
{
	if (start>end)
	{
		return NULL;
	}
	int m = start + (end - start) / 2;
	BiTNode *root = new BiTNode();
	root->data = a[m];
	root->lChild = arrayTotree(a, start, m - 1);
	root->rChild = arrayTotree(a, m + 1, end);
	return root;
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


//先序遍历非递归需要借助stack s来实现，模拟递归调用  
//总的循环边界是当前节点不为空或者stack不空，  
//@1 在当前节点p非空时候，将p入栈s,p的左子树赋给p,保证左子树都能入栈  
//  p为空时候，也就是左子树最左边访问到了，这时候在栈非空的时候  
//@2 取栈顶给p，输入p，出栈，这时候最底层的最左边节点访问了，将p的右子树赋给p，重复@1  

void BiTree::NotReInOrder()
{
	stack<BiTNode*> s;

	BiTNode* r = root;//访问根节点

	while (!s.empty() || r != 0)
	{
		while (r != 0)
		{
			s.push(r);
			r = r->lChild;
		}

		if (!s.empty())
		{
			r = s.top();
			s.pop();
			cout << r->data << " ";
			r = r->rChild;
		}
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



