//codetree.h - library that implements a CodeTree

#include <vector>
#include "maxheap.h"
#include "node.h"

#ifndef CODETREE_H
#define CODETREE_H

//freq is array of integer representations of each character within a string
//The index is an ascii character, and at that index is the # of occurences of that ascii character within the input file

class CodeTree{
private:
	int freq[256];
	std::vector<Node*> frequencies;
	MaxHeap heap;
	void printChar(int ch);
	void buildPriorityQ(void);
	void insertSmallestTwo(std::vector<Node*> frequencies, MaxHeap heap);
public:
	CodeTree(int freqin[]);
	~CodeTree();
	void printTree( void );
	void printCode( void );
};

#endif /* CODETREE_H */
