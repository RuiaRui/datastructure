
#include <stack>  
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

	void NotReInOrder();

	void PrintTree(BiTNode *T, int level);

	BiTNode * arrayTotree(int a[], int start, int end);
};


//������  
int main() {
	BiTree *biTree = new BiTree();
	/*cout << "����һ��������������,��-1��ʾ����:" << endl;
	biTree->root = biTree->CreateBiTree();*/

	int a[7] = { 1,2,3,4,5,6,7};
	int m = sizeof(a) / sizeof(a[0]);
	cout << "�������" << endl;
	for (int i = 0; i < m; i++) {
		cout << a[i] << "  ";
	}
	cout << endl;
	cout << "�����������������" << endl;
	biTree->root = biTree->arrayTotree(a, 0, m-1);

	cout << "��ӡ��" << endl;
	biTree->PrintTree(biTree->root, 0);


	system("pause");
}




//������������ķ���ת�����������С���Ҫȷ��һ�����ڵ㣬Ȼ��ݹ鴴��

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


//��������ǵݹ���Ҫ����stack s��ʵ�֣�ģ��ݹ����  
//�ܵ�ѭ���߽��ǵ�ǰ�ڵ㲻Ϊ�ջ���stack���գ�  
//@1 �ڵ�ǰ�ڵ�p�ǿ�ʱ�򣬽�p��ջs,p������������p,��֤������������ջ  
//  pΪ��ʱ��Ҳ��������������߷��ʵ��ˣ���ʱ����ջ�ǿյ�ʱ��  
//@2 ȡջ����p������p����ջ����ʱ����ײ������߽ڵ�����ˣ���p������������p���ظ�@1  

void BiTree::NotReInOrder()
{
	stack<BiTNode*> s;

	BiTNode* r = root;//���ʸ��ڵ�

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



