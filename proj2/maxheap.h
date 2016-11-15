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
	Node* removeMin();
	int size();
private:
	std::vector<Node *> heap;
private:
	void heapify(int size);
	void sort(int size);
	void swapDown(int i, int size);
	int parent(int child);
	int right(int parent);
	int left(int parent);
	void heapPrintChar(int ch);
};

#endif /* MAXHEAP_H */
