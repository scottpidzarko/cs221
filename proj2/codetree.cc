#include "codetree.h"

//public functions -------------------

//Constructor
CodeTree::CodeTree(int freqin[]){
	std::copy(freqin, freqin+256, freq); // https://stackoverflow.com/questions/9426932/how-do-i-pass-an-array-to-a-constructor
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

CodeTree::buildPriorityQ(){
	//Huffman's algorithm builds the code tree by starting with a priority queue containing
	//separate nodes, one for each distinct character in the input, whose priorities are the frequencies of
	//their corresponding characters. It picks two nodes with the lowest frequencies (the nodes r and
	//in our example) and joins them with a new common parent node whose frequency is the sum of
	//the two frequencies (the node labeled 3). The parent node replaces its two children in the queue.
	//The algorithm repeats this process until only one node, the root, remains.

}
