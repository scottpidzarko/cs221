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

  MazeState * ret = heap[0];
  if( heap.size == 0)
    return ret;

  heap[0] = heap[heap.size - 1];
  heap.pop_back();

  bubble_down(0);

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

void HeapPriorityQueue::bubble_up(int index){
    if(index == 0)
      return;
    int parent_index = parent(index)
    if((heap[parent_index])->getBadness() > (heap[index])->getBadness){
      MazeState* temp = heap[parent_index];
      heap[parent_index)] = heap[index];
      bubble_up(parent_index)
    }
}

void HeapPriorityQueue::bubble_down(int index){
  int length = heap.size();
  int left_child_index = first_child(index);
  int right_child_index = left_child_index + 1;

  //index is a leaf so we don't need to do anything
  if(is_leaf(index) == true)
    return;

  int min_index = index;

  if((heap[index])->getBadness() > (heap[left_child_index])->getBadness() )
    min_index = left_child_index;

  if(( right_child_index < length ) && ((heap[min_index])->getBadness() > (heap[right_child_index])->getBadness() )
    min_index = right_child_index;

  //swap
  if( min_index != index)
    MazeState* temp = heap[index];
    heap[index] = heap[min_index];
    heap[min_index] = temp;
    bubble_down(min_index);
}
#endif
