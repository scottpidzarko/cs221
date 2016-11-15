#include <iostream>
#include <iterator>
#include "codetree.h"
#include "node.h"
#include "maxheap.h"

//public functions -------------------

//Constructor
CodeTree::CodeTree(int freqin[]){
	for(int i=0; i < 256; i++){
		freq[i]=freqin[i];
	}
	buildPriorityQ();
}
//Destructor
CodeTree::~CodeTree (void){
}

void CodeTree::printTree(void){
}
void CodeTree::printCode(void){
}

//private functions -----------------

//PROVIDED BY THE PROF, DO NOT ALTER
//Takes an integer and prints it as ASCII character
void printChar( int ch ) {
    if( ch < 16 ) {
        std::cout << "x0" << std::hex << ch;
    } else if( ch < 32 || ch > 126 ) {
        std::cout << "x" << std::hex << ch;
    } else {
        std::cout << "\"" << (char)ch << "\"";
	}
}

void CodeTree::buildPriorityQ(){
	//Huffman's algorithm builds the code tree by starting with a priority queue containing
	//separate nodes, one for each distinct character in the input, whose priorities are the frequencies of
	//their corresponding characters. It picks two nodes with the lowest frequencies (the nodes r and
	//in our example) and joins them with a new common parent node whose frequency is the sum of
	//the two frequencies (the node labeled 3). The parent node replaces its two children in the queue.
	//The algorithm repeats this process until only one node, the root, remains.

	//Build list of nodes
	for(int i = 0; i < 256; i++){
		if( freq[i] != 0 ){
			Node* n = new Node;
			n->frequency = freq[i];
			n->character = i;
			frequencies.push_back(n);
		}
	}

	MaxHeap codeTreeHeap(frequencies);

	//Find two smallest frequencies values, and create a parent.
	//Shove the smallest two into heap. Add the parent into the frequencies vector ande delete it's children.
	//Repeat until we have nothing left
	// Yeah yeah I could do this more recursively without the while loop but it's basically the same amount of lines of code
	//for this to call itself recursively. It works. Meh. We aren't running out of stack frames or anything anyway

	//The heap now contains the codetree, we're done here
	codeTreeHeap.listHeap(); //should be 4 4 4 2 2 1

}
