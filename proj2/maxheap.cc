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
	//heap = v;
	//makeMaxHeap();
}
MaxHeap::~MaxHeap(){
}
//I can get away with not implementing this
void MaxHeap::makeMaxHeap(){
}
//Put the object in the heap vector at the end, and call heapify on the end of the heap to put it in the right place
void MaxHeap::insert(Node* in){
	heap.push_back(in);
	heapify(heap.size()-1);
}
void MaxHeap::listHeap(void){
	for(int i=0; i < heap.size(); i++){
		std::cout << " (" << heap[i]->frequency << "," << heap[i]->character << ") ,";
	}
	std::cout << std::endl;
}
//I do have to implement this for insert
void MaxHeap::heapify(int index){
	int parentIndex = parent(index);
	if(heap[parentIndex]->frequency < heap[index]->frequency){
		swapUp(parentIndex, index);
	}
}
//Don't need this since we are never going to delete anything from the heap in this assignment, leave blank
void MaxHeap::swapDown(){
}
//Swaps node at index with node at parent
void MaxHeap::swapUp(int parent, int index){
	Node* temp = new Node;
	temp->frequency = heap[parent]->frequency;
	temp->character = heap[parent]->character;
	heap[parent]->frequency = heap[index]->frequency;
	heap[parent]->character = heap[index]->character;
	heap[index]->frequency = temp->frequency;
	heap[index]->character = temp->character;
	delete temp;
	heapify(parent);
}
//http://www.sourcetricks.com/2011/06/c-heaps.html
//Get the index of the left node
int MaxHeap::left(int parent){
    int i = ( 2 * parent ) + 1; // 2 * parent + 1
    return ( i < heap.size() ) ? i : -1;
}
//http://www.sourcetricks.com/2011/06/c-heaps.html
//Get index of the right node
int MaxHeap::right(int parent){
    int i = (2*parent) + 2; // 2 * parent + 2
    return ( i < heap.size() ) ? i : -1;
}
//http://www.sourcetricks.com/2011/06/c-heaps.html
//Get parent index given a node's index
int MaxHeap::parent(int child){
    if (child != 0){
        int i = (child - 1) >> 1;
        return i;
    }
    return -1;
}
