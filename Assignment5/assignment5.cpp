#include <iostream>
#include <stack>
using namespace std;

template <class Type> class PostOrder;



template<class Type> struct BTNode {
	BTNode *left;
	Type data;
	BTNode *right;
	BTNode(Type x) {
		data = x;
		left = right = NULL;
	}
};



template<class Type> class BinaryTree {
private:
	BTNode<Type> *root;
	friend class PostOrder<Type>;
public:
	BinaryTree(BTNode<Type>*t) { root = t; }
};

//Base class for BT Iterator
template <class Type> class TreeIterator {
protected:
	const BinaryTree <Type> & T;//BT
	const BTNode<Type> *current;
public:
	TreeIterator(const BinaryTree <Type> & BT)
		: T(BT), current(NULL) { }
	virtual ~TreeIterator() { }
	virtual void First() = 0;
	virtual void operator ++ () = 0;
	operator bool() { return current != NULL; }
	const Type operator()()const {
		if (current)
			return current->data;
		return (Type)0;
	}
};


template <class Type> struct StkNode {
	//Stack node definition
	const BTNode <Type> *Node;  //Node Address
	int PopTime;                                        //Counter
	StkNode(BTNode <Type> *N = NULL) : Node(N), PopTime(0) { }
};


template <class Type> class PostOrder :public TreeIterator <Type> {
	bool renew;
public:
	PostOrder(const BinaryTree <Type> & BT) :TreeIterator<Type>(BT) { renew = false; }
	~PostOrder() {}
	void First();
	//Seek to the first node in postorder traversal
	void operator ++ ();
	//Seek to the successor
protected:
	stack < StkNode<Type> > st;     //Active record stack
};

template <class Type>
void PostOrder<Type>::First() {
	this->current = this->T.root;
	while (st.empty() == false) { st.pop(); }
	renew = true;
	operator++();
}

template <class Type>
void PostOrder<Type>::operator ++() {
	if (!renew && this->current == this->T.root && st.empty()) {
		this->current = NULL;
		return;
	}
	renew = false;
	const BTNode<Type> *p = this->current;
	StkNode<Type> w;
	do {
		if (!st.empty()) {
			//更新w
			w=st.top();
			//左子树遍历完成后的pop
			st.pop();
			if (w.PopTime == 1) {
				w.PopTime = 0;
				//遍历右子树时再次压入
				st.push(w);
				p = w.Node->right;
			}
			//poptime=0且跳出while，即为叶子节点 ，直接输出
			else {
				this->current = w.Node;
				p = NULL;
				return;
			}
		}
		//持续到最左的节点，停止
		while (p) {
			
			w.Node = p;
			w.PopTime = 1;
			//第一次压入
			st.push(w);
			p = p->left;
		}
	} while (p || !st.empty());
}


int main() {
	BTNode<int> *p = new BTNode<int>(6);
	p->left = new BTNode<int>(4);
	p->right = new BTNode<int>(10);
	p->left->left = new BTNode<int>(2);
	p->right->left = new BTNode<int>(8);
	p->right->right = new BTNode<int>(12);
	BinaryTree<int> T(p);
	PostOrder<int> it(T);
	for (it.First(); it; ++it) {
		std::cout << it() << std::endl;
	}
	system("pause");
}

