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

  if(tail == NULL){
    printf( "Warning: LinkedListQueue is Empty, no element is returned")
    return NULL;
  }
  else{
    node* temp = new node;
    temp->data = elem;
    temp->next = NULL;

    if(front == NULL)
      front = temp;
    else{
      rear->next = temp;
    }

    rear = temp;

    delete temp;
    size++;
    return;
  }

}

MazeState *LinkedListQueue::remove()
{

  MazeState *tempState  = new MazeState;

  if(head == NULL){
    printf( "Warning: LinkedListQueue is Empty, no element is returned")
    return NULL;
  }else{
    node* temp = new node;

    //Grab the pointer to the head of the queue;
    temp = head;

    //Grab the data at the head of the queue so that we can return it later
    tempState = temp->data;

    //make the head of the array the next element
    head = head->next;

    //cleanup and return
    delete temp;
    size--;
    return tempState;
  }

}

bool LinkedListQueue::is_empty()
{
  if ((size == 0) && (head == NULL) && (tail == NULL))
    return TRUE;
  else
    return FALSE;
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
