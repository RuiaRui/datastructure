#include<string>
#include<iostream>
using namespace std;

class BiTNode
{
public:
	BiTNode(string str);
	BiTNode* lChild;
	BiTNode* rChild;
	BiTNode* parent;
	string data;
};

BiTNode::BiTNode(string str)
{
	lChild = rChild = parent = nullptr;
	data = str;
}

class BiTree
{
public:
	BiTNode* root;

	BiTree(string expr);
	BiTNode* search(const string name);
	BiTNode* search(const string name, BiTNode* node);
	void add(string expr);
	void addRoot(string name);
	void addChild(string parentname, string name, bool right = false);
	void PrintTree(BiTNode * T, int level);
};

int main()
{
	string expr = "A B(A) C(A) D(BR) E(C) F(C) G(E) H(E) ";
	BiTree* tree = new BiTree(expr);
	
	cout << "打印树" << endl;
	tree->PrintTree(tree->root, 0);

	system("pause");
	return 0;
}


BiTNode* BiTree::search(string name)
{
	return search(name, root);
}

BiTNode* BiTree::search(const string name, BiTNode* node)
{
	BiTNode* result = nullptr;
	if (node->data == name)
		result = node;
	if (result == nullptr)
	{
		if (node->lChild != nullptr)
			result = search(name, node->lChild);
	}
	if (result == nullptr)
	{
		if (node->rChild != nullptr)
			result = search(name, node->rChild);
	}
	return result;
}

void BiTree::add(string expr)
{
	if (expr.find('(') == string::npos)
		addRoot(expr);
	else
	{
		int pos = expr.find('(');
		string name = expr.substr(0, pos);
		string parentname = expr.substr(pos + 1, expr.length() - pos - 2);
		if (parentname.find_last_of('R') == parentname.length() - 1)
			addChild(parentname.substr(0, parentname.length() - 1), name, true);
		else
			addChild(parentname, name);
	}
}

void BiTree::addRoot(string name)
{
	root = new BiTNode(name);
}

void BiTree::addChild(string parentname, string name, bool right)
{
	BiTNode* node = new BiTNode(name);
	BiTNode* parent = search(parentname);
	node->parent = parent;
	if (parent->lChild != nullptr || right)
		parent->rChild = node;
	else
		parent->lChild = node;
}

BiTree::BiTree(string expr)
{
	while (expr.find(' ') != string::npos)
	{
		int pos = expr.find(' ');
		add(expr.substr(0, pos));
		expr = expr.replace(0, pos + 1, "");
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
