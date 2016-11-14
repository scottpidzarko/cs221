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

void CodeTree::insertSmallestTwo(std::vector<Node*> frequencies, MaxHeap heap){
	if(frequencies.size() == 0) return;
	int smallestIndex;
	Node* smallest = new Node;
	smallest->frequency=0;
	int secondSmallestIndex;
	Node* secondSmallest = new Node;
	secondSmallest->frequency=0;
	Node* newParent = new Node;

	//Root node, skip searching and just add it to the heap;
	if(frequencies.size() == 1){
		heap.insert(frequencies[0]);
		return;
	}

	//find the two smallest frequency characters
	for(int i=0; i < frequencies.size(); i++){
		if( (frequencies[i]->frequency < secondSmallest->frequency) && (frequencies[i]->frequency >= smallest->frequency) ){
			SecondSmallest->frequency = frequencies[i]->frequency;
			secondSmallest->character = frequencies[i]->character;
			SecondSmallestIndex = i;
		} else if( frequencies[i]->frequency < smallest->frequency) ){
			secondSmallest->frequency = smallest->frequency;
			secondSmallest->character = smallest->character;
			secondSmallestIndex = smallestIndex;
			smallest->frequency = frequencies[i]->frequency;
			smallest->character = frequencies[i]->character;
			smallestIndex = i;
		}
	}

	newParent->frequency = smallest->frequency + secondSmallest->frequency;
	newParent->character = -1; //the parent isn't a leaf so doesn't contain a character
	std::cout << smallestIndex << std::endl;
	std::cout << secondSmallestIndex << std::endl;
	std::cout << frequencies[smallestIndex]->frequency << std::endl;
	std::cout << frequencies[secondSmallestIndex]->frequency << std::endl;

	heap.insert(smallest);
	heap.insert(secondSmallest);
	frequencies.erase(frequencies.begin()+smallestIndex); //https://stackoverflow.com/questions/875103/how-to-erase-element-from-stdvector-by-index
	frequencies.erase(frequencies.begin()+secondSmallestIndex);
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
	for(int i = 0; i < 256; i++){
		if( freq[i] != 0 ){
			Node* n = new Node;
			n->frequency = freq[i];
			std::cout << n->frequency;
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
	while(frequencies.empty() != true){
		insertSmallestTwo(frequencies, codeTreeHeap);
	}

	//The heap now contains the codetree, we're done here
	codeTreeHeap.listHeap();

}
