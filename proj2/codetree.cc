#include <iostream>
#include <iterator>
#include <iomanip>
#include "codetree.h"
#include "node.h"
#include "maxheap.h"

//public functions -------------------

//Constructor
CodeTree::CodeTree(int freqin[]){
	for(int i=0; i < 256; i++){
		freq[i]=freqin[i];
	}
	buildTree();
}
//Destructor
CodeTree::~CodeTree (void){
}

void CodeTree::printTree(void){
	recursePrintTree(treeRoot, 0);
}
void CodeTree::printCode(void){
}

//private functions -----------------

void CodeTree::recursePrintTree( Node* r, int d) {
	if( r == NULL ) return;
    recursePrintTree( r->right, d+1 );
	std::cout << std::setw( 3 * d ) << ""; // output 3 * d spaces
	std::cout << " (";
	printChar(r->character);
	std::cout << "," << r->frequency << ") ";
	recursePrintTree( r->left, d+1 );
}


//PROVIDED BY THE PROF, DO NOT ALTER
//Takes an integer and prints it as ASCII character
void CodeTree::printChar( int ch ) {
	//accunt for non-leaf nodes that don't have a character associated
	if( ch == -1) {
		std::cout << "NUL";
		return;
	}
    if( ch < 16 ) {
        std::cout << "x0" << std::hex << ch;
    } else if( ch < 32 || ch > 126 ) {
        std::cout << "x" << std::hex << ch;
    } else {
        std::cout << "\"" << (char)ch << "\"";
	}
}

MaxHeap CodeTree::buildPriorityQ(){
	//Build list of nodes
	for(int i = 0; i < 256; i++){
		if( freq[i] != 0 ){
			Node* n = new Node;
			n->frequency = freq[i];
			n->character = i;
			frequencies.push_back(n);
		}
	}

	//Maxheap is priorityQ - least element is at back, greatest is as front
	//Done that way because std::vector.pop_back makes for a simple "pop Minimum" function
	MaxHeap codeTreeHeap(frequencies);
	codeTreeHeap.listHeap();
	return codeTreeHeap;
}

//returns root node of the tree
//Builds tree using huffman's algorithm
void CodeTree::buildTree(void){
	MaxHeap pQ = buildPriorityQ();
	while(pQ.size() > 1){
		Node* left = pQ.removeMin();
		Node* right = pQ.removeMin();
		Node* parent = new Node;
		parent->frequency = left->frequency + right->frequency;
		std::cout << "parent frequency is: " << parent->frequency << std::endl;
		parent->character = -1;
		parent->right = right;
		parent->left = left;
		pQ.insert(parent);
	}
	//one node left - this is the root
	treeRoot = pQ.removeMin();
	std::cout << "root node frequency is: " << treeRoot->frequency << std::endl;
	return;
}
