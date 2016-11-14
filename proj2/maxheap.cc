#include "maxheap.h"
#include <vector>

//v is a vector of unsorted nodes
//Constructor expects the vector to be the list of nodes of character/frequency in no particular order, and orders
// them with the highest frequency at the top. The constructor goes purely off of the frequency, with no care about the character

MaxHeap::MaxHeap(){
	std::vector<Node*> heap;
	//Don't need to call anything beyond this since the heap is empty.
}

MaxHeap::MaxHeap( std::vector<Node *> v){
	std::vector<Node*> heap = v;
	makeMaxHeap();
}
MaxHeap::~MaxHeap(){
}

//I can get away with not implementing this
MaxHeap::makeMaxHeap(){
	heapify();
}

//I do have to implement this for insert
void MaxHeap::heapify(std::vector<Node*> heap){
}
void MaxHeap::swapDown(){
}
void MaxHeap::swapUp(){
}
void MaxHeap::insert(){
}
