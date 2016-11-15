#include <iostream>
#include <vector>
#include <iterator>

#include "maxheap.h"
#include "node.h"


//Blank constructor
MaxHeap::MaxHeap(){
	//Don't need to call anything beyond this since the heap is empty.
}
//Constructor expects the vector to be the list of nodes of character/frequency in no particular order, and orders
// them with the highest frequency at the top. The constructor goes purely off of the frequency, with no care about the character
//v is a vector of unsorted nodes
MaxHeap::MaxHeap( std::vector<Node* > v){
	heap = v;
	sort(heap.size());
}
MaxHeap::~MaxHeap(){
}
//Put the object in the heap vector at the end, and call heapify on the end of the heap to put it in the right place
void MaxHeap::insert(Node* in){
	heap.push_back(in);
	if(heap.size() > 1) heapify(heap.size());
}

void MaxHeap::listHeap(void) {
    for (int i = 0; i < heap.size(); i++){
		int ch = heap[i]->character;
        std::cout << " (";
		heapPrintChar(ch);
		std::cout << "," << heap[i]->frequency << ") ";
	}
    std::cout << std::endl;
}

void MaxHeap::sort(int size) {
    heapify(size);  // Heapify algorithm
    for (int i = size - 1; i > 0; i--) {
        std::swap(heap[0], heap[i]);
        swapDown(0, i);
    }
}
void MaxHeap::heapify(int size) {
    for (int i = (size - 2) / 2; i >= 0; i--)
        swapDown(i, size);
}
void MaxHeap::swapDown( int i, int size) {
    int leftChild = left(i);
    int rightChild = right(i);
    int min = i;
    // find who holds smallest element of i and its two children
    if (leftChild < size && heap[leftChild]->frequency < heap[min]->frequency)
        min = leftChild;
    if (rightChild < size && heap[rightChild]->frequency < heap[min]->frequency)
        min = rightChild;
    // if a child holds smallest element, swap i's element to that child
    // and recurse.
    if (min != i) {
        std::swap(heap[i], heap[min]);
        swapDown(min, size);
    }
}

//Get the index of the left node
int MaxHeap::left(int parent){
	return ( 2 * parent ) + 1;
}
//Get index of the right node
int MaxHeap::right(int parent){
    return (2*parent) + 2;
}
//Get parent index given a node's index
int MaxHeap::parent(int child){
    if (child != 0){
        int i = (child - 1) >> 1;
        return i;
    }
    return -1;
}

//PROVIDED BY THE PROF, DO NOT ALTER
//Takes an integer and prints it as ASCII character
void MaxHeap::heapPrintChar( int ch ) {
    if( ch < 16 ) {
        std::cout << "x0" << std::hex << ch;
    } else if( ch < 32 || ch > 126 ) {
        std::cout << "x" << std::hex << ch;
    } else {
        std::cout << "\"" << (char)ch << "\"";
	}
}
