
#include <stack>  
#include <iostream>  

using namespace std;

struct BiTNode {
	int data=0;
	struct BiTNode *lChild, *rChild;//���Һ���  
};

class BiTree {
private:
	

public:
	BiTNode *root;


	BiTNode * CreateBiTree();
	
	void NotReInOrder();

	void PrintTree(BiTNode *T, int level);
};


//������  
int main() {
	BiTree *biTree = new BiTree();
	cout << "����һ��������������,��-1��ʾ����:" << endl;
	biTree->root=biTree->CreateBiTree();

	cout << "��ӡ��" << endl;
	biTree->PrintTree(biTree->root, 0);

	cout << "����ǵݹ������" << endl;
	biTree->NotReInOrder();

	system("pause");
}


//����ݹ鴴����������  
BiTNode * BiTree::CreateBiTree()
{
	int val;
	BiTNode *current = new BiTNode();
	cin >> val;

	if (val == -1) {
		return current=NULL;
	}else
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
	//����  
	if (root == NULL)
		return;
	//���ǿ�  
	BiTNode* p = root;
	stack<BiTNode*> s;
	while (!s.empty() || p)
	{
		if (p)
		{
			s.push(p);
			p = p->lChild;
		}
		else
		{
			p = s.top();
			s.pop();
			cout << p->data;
			p = p->rChild;
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



