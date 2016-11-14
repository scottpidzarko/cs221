#include <vector>

struct Node {
	int frequency;
	int character; //all the nodes except leaves will not have a character
				   //character being -1 indicates that the node does not contain any valid character data.
};

class MaxHeap{
	//Our heap is done with a vector, so we don't need leftchild/rightchild pointers.
	std::vector<Node *> heap;
public:
	MaxHeap(std::vector<Node *>);
	~MaxHeap();
	//contains();
	//at();
private:
	void makeMaxHeap();
	void heapify(std::vector<Node *>, std::vector<Node*>);
	void swapDown();
	void swapUp();
	void insert();
};
