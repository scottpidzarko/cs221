//HeapPriorityQueue.cpp
#ifndef _HEAPPRIORITYQUEUE_CPP
#define _HEAPPRIORITYQUEUE_CPP

#include "HeapPriorityQueue.hpp"
#include <cassert>
#include <cstdlib>//for NULL
#include <iostream>

HeapPriorityQueue::HeapPriorityQueue() {
  // Empty... nothing needs to be done.
}

HeapPriorityQueue::~HeapPriorityQueue() {
  // no clean-up to do, since the heap is not dynamically allocated
}

void HeapPriorityQueue::add(MazeState *elem) {
  heap.push_back(elem);
  min_heapify();
}

MazeState * HeapPriorityQueue::remove() {
  assert(!is_empty());

  if (heap.size() < 1)
    return (MazeState *)NULL;

  int min_index = 0;

  for (int i = 0; i < (int)heap.size(); i++) {
    if (heap[i]->getBadness() < heap[min_index]->getBadness())
      min_index = i;
  }

  MazeState *ret = heap[min_index];
  heap.erase(heap.begin() + min_index); // remove list[min_index]
  return ret;

}

bool HeapPriorityQueue::is_empty() {
  return (heap.size() == 0);
}

// You might find these helper functions helpful...
int HeapPriorityQueue::parent(int index) {
  return (index - 1) / 2;
}

int HeapPriorityQueue::first_child(int index) {
  return 2 * index + 1;
}

bool HeapPriorityQueue::is_root(int index) {
  return index == 0;
}

bool HeapPriorityQueue::is_leaf(int index) {
  return num_children(index) == 0;
}

int HeapPriorityQueue::num_children(int index) {
  int fchild = first_child(index);
  return max(0, min(2, (int)heap.size() - fchild));
}

//so you can shove an element in, and call min heapify, and call it a day
//Doesn't assume that the vector has already been heapified for stability, with a performance
// impact as a result
void HeapPriorityQueue::min_heapify( void ){
  vector<MazeState* > newVector;
  vector<MazeState* > oldVector;



  heap = newVector;

  //~newVector();
  //~oldVector();
}

#endif
