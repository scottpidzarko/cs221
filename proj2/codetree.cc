#include <iostream>
#include <iterator>
#include "codetree.h"


//public functions -------------------

//Constructor
CodeTree::CodeTree(int freqin[]){
	std::copy(freqin, freqin+256, freq); // https://stackoverflow.com/questions/9426932/how-do-i-pass-an-array-to-a-constructor
	std::vector<Node*> frequencies;
	buildPriorityQ();
}
//Destructor
CodeTree::~CodeTree (void){
}

void CodeTree::printTree(void){
}
void CodeTree::printCode(void){
}

void CodeTree::insertSmallestTwo(std::vector<Node*> frequencies, Heap heap){
	if(size(frequencies) == 0) return;

	Node smallest = new Node;
	smallest->frequency=0;
	Node secondSmallest = new Node;
	secondSmallest->frequency=0;
	Node newParent = new Node;

	//Root node, skip searching and just add it to the heap;
	if(size(frequencies) == 1){
		heap.insert(frequencies[0]);
		return;
	}

	//find the two smallest frequency characters
	for(int i=0, j < frequencies.size(), frequencies++){
		if(frequencies[i]->frequency >= secondSmallest->frequency){
			smallest->frequency = secondSmallest->frequency;
			smallest->character = secondSmallest->character;
			secondSmallest->frequency = frequencies[i]->frequencies);
			secondSmallest->character = frequencies[i]->character);
		} else if( (frequencies[i]->frequency < secondSmallest->frequency)) && (frequencies[i]->frequency > smallest->frequency)){
			smallest->frequency = frequencies[i]->frequency;
			smallest->character = frequencies[i]->character;
		}
	}

	newParent->frequency = smallest->frequency + secondSmallest->frequency;
	newParent->character = -1; //the parent isn't a leaf so doesn't contain a character

	heap.insert(smallest);
	heap.insert(secondSmallest);
	frequencies.remove(smallest);
	frequencies.remove(secondSmallest);
	frequencies.push_back(newParent);
	return;
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
	for(int i = 0, i < 256, i++){
		if( freq[i] != 0 ){
			Node n = new Node;
			n->frequency = freq[i];
			n->character = i;
			frequencies.push_back(n);
		}
	}

	MaxHeap codeTreeHeap;

	//Find two smallest frequencies values, and create a parent.
	//Shove the smallest two into heap. Add the parent into the frequencies vector ande delete it's children.
	//Repeat until we have nothing left
	// Yeah yeah I could do this more recursively without the while loop but it's basically the same amount of lines of code
	//for this to call itself recursively. It works. Meh. We aren't running out of stack frames or anything anyway
	while(frequencies.is_empty() != true){
		insertSmallestTwo(frequencies, codeTreeHeap);
	}

	//The heap now contains the codetree, we're done here

}
