#include <vector>
#include "node.h"

#ifndef MAXHEAP_H
#define MAXHEAP_H

class MaxHeap{
	//Our heap is done with a vector, so we don't need leftchild/rightchild pointers.
public:
	MaxHeap();
	MaxHeap(std::vector<Node *>);
	~MaxHeap();
	//contains();
	//at();
	void insert(Node* );
	void listHeap();
private:
	std::vector<Node *> heap;
private:
	void makeMaxHeap();
	void heapify(int index);
	void swapDown();
	void swapUp(int parent, int index);
	int parent(int child);
	int right(int parent);
	int left(int parent);
};

#endif /* MAXHEAP_H */
