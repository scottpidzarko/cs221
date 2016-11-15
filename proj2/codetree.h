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
	Node* treeRoot;
	void printChar(int ch);
	MaxHeap buildPriorityQ(void);
	void buildTree();
	void recursePrintTree( Node* r, int d );
public:
	CodeTree(int freqin[]);
	~CodeTree();
	void printTree( void );
	void printCode( void );
};

#endif /* CODETREE_H */
