//LinkedListQueue.cpp
#ifndef _LINKEDLISTQUEUE_CPP
#define _LINKEDLISTQUEUE_CPP

#include "LinkedListQueue.hpp"
#include <cstdlib> //for NULL
#include <cassert>
#include <iostream>
LinkedListQueue::LinkedListQueue()
{
  head = NULL;
  tail = NULL;
  size = 0;
}

void LinkedListQueue::add(MazeState *elem)
{
  std::cout << "Adding to LinkedListQueue" << std::endl;
  size++;
  if(is_empty() == true){
    std::cout << "LinkedListQueue is Empty" << std::endl;
    return;
  }

  node* temp = new node;
  temp->data = elem;
  temp->next = NULL;

  if(head == NULL){
    head = tail = temp;
    tail-> next = NULL;
  }
  else{
    tail->next = temp;
    tail = temp;
    tail->next = NULL;
  }

  return;
}

MazeState *LinkedListQueue::remove()
{
  std::cout << "removing from LinkedListQueue" << std::endl;
  assert(head != NULL);
  MazeState *ret = head->data;
  node* temp = head->next;
  delete head;
  head = temp;

  size--;
  return ret;
}

bool LinkedListQueue::is_empty()
{
  if ((size == 0))
    return true;
  else
    return false;

}

LinkedListQueue::~LinkedListQueue()
{
  /** node* temp = new node;
  temp = head;
  node* temp2 = new node;


  //go through the array and nuke all data and next pointers
  for( int i = 0; i < size; i++){
    temp2 = temp;

    //remember where next node is
    temp = temp->next;

    //delete the node we're on
    delete temp2->data;
    delete temp2->next;
  }

  //now delete the rest
  delete temp;
  delete temp2;
  delete head;
  delete tail;
  delete size; **/
  while(head != NULL)
    remove();
}

#endif
