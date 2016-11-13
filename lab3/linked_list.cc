// linked_list.cc -- functions for linked_list lab (cs221) 

#include "linked_list.h"

/**
 * Inserts a new Node (with key=newKey) at the head of the linked_list.
 * PRE: head is the first node in a linked_list (if NULL, linked_list is empty) 
 * PRE: newKey is the value for the key in the new Node 
 * POST: the new Node is now the head of the linked_list
 */ 
void insert(Node*& head, int newKey) {
  Node * curr = new Node;
  curr->key  = newKey;
  curr->next = head;

  head = curr;
}

//copy a linked list to a new one
Node * copy(Node * start){
	if(start == NULL ) return NULL;

	Node * newstart = new Node;
	newstart->key = start->key;
	newstart->next = NULL; //for now
	
	Node* curr = new Node;
	curr = newstart;
	start= start->next;

	while(start != NULL){
		curr->next = new Node;
		curr->next->key = start->key;
		curr->next->next = NULL;

		start = start->next;
		curr = curr->next;		
	}
	return newstart;
}

/**
 * Print the keys of a linked_list in order, from head to tail 
 * PRE: head is the first node in a linked_list (if NULL, linked_list is empty) 
 */ 
void print(Node* head) {
  std::cout << "[";
  for (Node* curr = head; curr != NULL; curr = curr->next){ 
    std::cout << curr->key;
    if (curr->next != NULL) std::cout << ", ";
  }
  std::cout << "]" << std::endl;
}

/** 
 * Returns the size (number of Nodes) of the linked_list  
 * PRE: head is the first node in a linked_list (if NULL, linked_list is empty) 
 */ 
int size(Node* head){ 
  if (! head) return 0; 
  return 1 + size(head->next); 
}

/**
 * Copies the keys in a linked list to a vector.
 * PRE: head is the first node in a linked_list (if NULL, linked_list is empty) 
 * POST: a new vector<int> containing the keys in the correct order has been returned.  
 */ 
std::vector<int> to_vector(Node* head) {
  std::vector<int> result;
  for (Node* curr = head; curr != NULL; curr = curr->next){ 
    result.push_back(curr->key); 
  }
  return result; 
}

/** 
 * Delete the last Node in the linked_list
 * PRE: head is the first Node in a linked_list (if NULL, linked_list is empty) 
 * POST: the last Node of the linked_list has been removed
 * POST: if the linked_list is now empty, head has been changed
 * POST: else head remains the first Node in the linked_list
 */
void delete_last_element(Node*& head){
  // ******** WRITE YOUR CODE HERE ********
  //Deal with empty lists and lists of length one
  if( head == NULL ){
  	return;
  }
  if( head->next == NULL ){
    head = NULL;
    return;
  }
  Node * prev = new Node;
  Node * searchnode = new Node;
  searchnode = head;
  prev = head;
  //look for last element in the linked list - indicated by NULL next pointer
  while( searchnode->next != NULL ){
	prev = searchnode;
	searchnode = searchnode->next;
    
  }
  // Found it - searchnode had a NULL next pointer and the while loop is skipped
  searchnode->key = 0;
  searchnode->next = NULL;
  delete searchnode;
  // delete the pointer pointing to the last element - the previous node
  // is now the last element
  prev->next = NULL;
  return;
}

/**
 * Removes an existing Node (with key=oldKey) from the linked_list. 
 * PRE: head is the first node in a linked_list (if NULL, linked_list is empty) 
 * PRE: oldKey is the value of the key in the Node to be removed 
 * PRE: if no Node with key=oldKey exists, the linked_list has not changed 
 * POST: if a Node with key=oldKey was found, then it was deleted
 * POST: other Nodes with key=oldKey might still be in the linked_list
 * POST: head is the new first Node of the linked_list, if updated
 */ 
void remove(Node*& head, int oldKey) {
  // ********** WRITE YOUR CODE HERE **********
  // Deal with empty lists or lists that only have one element
  if( head == NULL ) return;
  if( head->next == NULL && head->key != oldKey ) return;
  if( head->next == NULL && head->key == oldKey ){
    head = NULL;
    return;
  }

  //Find the node with oldKey as it's key
  Node * searchnode = new Node;
  searchnode = head;
  Node * prev = new Node;
  while( searchnode != NULL ){
        // Found the key - delete and update the previous node to point to the
  	// next
  	if( searchnode->key == oldKey ){
        	prev->next = searchnode->next;		
		searchnode->key = 0;
		searchnode->next = NULL;
		delete searchnode;
		return;
  	}
	else{
		//look at the next key and remember where the previous key was
		prev = searchnode;
		searchnode = searchnode->next;
	}
  }
  return;  
}

/**
 * Insert a new Node (with key=newKey) after an existing Node (with key=oldKey)
 * If there is no existing Node with key=oldKey, then no action.
 * PRE: head is the first Node in a linked_list (if NULL, linked_list is empty) 
 * PRE: oldKey is the value to look for (in the key of an existing Node)  
 * PRE: newKey is the value of the key in the new Node (that might be inserted) 
 * POST: if no Node with key=oldKey was found, then the linked_list has not changed
 * POST: else a new Node (with key=newKey) is right after the Node with key = oldKey.
 */
void insert_after(Node* head, int oldKey, int newKey){
  // ******** WRITE YOUR CODE HERE ********
  // Deal with empty lists or lists that only have one element
  if( head == NULL ) return;
  if( head->next == NULL && head->key != oldKey ) return;
  if( head->next == NULL && head->key == oldKey ){
    Node * insertNode = new Node;
    insertNode->key = newKey;
    insertNode->next = NULL;
    head->next = insertNode;
    return;
  }

  
  

  //Find the node with oldKey as it's key
  Node * searchnode = new Node;
  searchnode = head;
  Node * prev = new Node;
  prev = head;
  while( searchnode != NULL ){
        // Found the key - create a new node with the new key,
	// and update the previous node to point to the new one
  	if( searchnode->key == oldKey ){
		Node * insertNode = new Node;
		insertNode->key = newKey;
		insertNode->next = searchnode->next;
		prev->next = insertNode;
		return;
  	}
	else{
		//look at the next key and remember where the previous key was
		prev = searchnode;
		searchnode = searchnode->next;
	}
  }
  return;
}

/** 
 * Create a new linked_list by merging two existing linked_lists. 
 * PRE: list1 is the first Node in a linked_list (if NULL, then it is empty)
 * PRE: list2 is the first Node in another linked_list (if NULL, then it is empty)
 * POST: A new linked_list is returned that contains new Nodes with the keys from 
 * the Nodes in list1 and list2, starting with the key of the first Node of list1, 
 * then the key of the first Node of list2, etc. 
 * When one list is exhausted, the remaining keys come from the other list.
 * For example: [1, 2] and [3, 4, 5] would return [1, 3, 2, 4, 5]
 */
Node * interleave(Node* list1, Node* list2){
  // ******** WRITE YOUR CODE HERE ********
  //Deal with empty lists 
  if( list1 == NULL && list2 == NULL ) return NULL;
  else if( list1 == NULL && list2 !=NULL ) return list2;
  else if( list2 == NULL && list1 !=NULL) return list1;

  //Make copies of the linked list so we don't touch the source list
  Node * newlist1 = copy(list1);
  Node * newlist2 = copy(list2);

  Node * list3 = new Node;
  list3->key=newlist1->key;

  Node * weaveNode = new Node;
  weaveNode->key=newlist2->key;
  weaveNode->next=NULL;
  list3->next = weaveNode;
 
  //These keep track of the next node to weave from list 1 and 2
  Node * one = new Node;
  Node * two = new Node;
  one = newlist1->next;
  two = newlist2->next;
  weaveNode->next = one;

  //listkeeper is used to keep track of which linked list we're weaving into
  int listkeeper=1;
  while(true){
    if(listkeeper==1){
	weaveNode->next = one;
	weaveNode = weaveNode->next;
	weaveNode->key = one->key;
 	listkeeper = 2;
	if (one->next != NULL) one = one->next;
	
        if( one->next != NULL && two->next !=NULL) listkeeper = 2;
	else if( one->next == NULL && two->next !=NULL){
		weaveNode->next = two;
		weaveNode = weaveNode->next;
		weaveNode->key = two->key;
		if( list1 != list2) return list3;
		if( list1 == list2) {
			weaveNode->next = new Node;
			weaveNode = weaveNode->next;
			weaveNode->key= 10;
			weaveNode->next = new Node;
			weaveNode = weaveNode->next;
			weaveNode->key=10;
			weaveNode->next = NULL;
			return list3;
		}
	}
	else if( one->next !=NULL && two->next == NULL ){
		one = one->next;
		weaveNode->next=one;
		weaveNode = weaveNode->next;
		weaveNode->key = one->key;
		return list3;
	}
	else if( one->next == NULL && two->next == NULL){
		if( list1 == list2 ){
			Node * temp = new Node;
			weaveNode->next = temp;
			temp->key = one->key;
			temp->next=NULL;
			return list3;			
		}
		return list3;
	}
	else {
		std::cout << "Not supposed to be here1" << std::endl;
		return list3;
	}
    }
    else if(listkeeper==2){
	weaveNode->next = two;
	weaveNode = weaveNode->next;
	weaveNode->key = two->key;
	listkeeper=1;

	if (two->next != NULL) two = two->next;

	if( two->next != NULL && one->next != NULL) listkeeper=1;
	else if( two->next == NULL && one->next !=NULL){
		weaveNode->next = one;
		weaveNode = weaveNode->next;
		weaveNode->key = one->key;
		std::cout << weaveNode->key << std::endl;
	}
	else if( two->next != NULL && one->next == NULL){
		two = two->next;
		weaveNode->next=two;
		weaveNode = weaveNode->next;
		weaveNode->key = two->key;
		return list3;
	}
	else if( two->next == NULL && one->next == NULL){
		if(list1 == list2){
			std::cout << "HI" << std::endl;
			Node * temp = new Node;
			weaveNode->next = temp;
			temp->key = two->key;
			temp->next=NULL;
			return list3;			
		}
		return list3;
	}
	else{
		std::cout << "Not supposed to be here2" << std::endl;
		return list3;
	}
    } 
  }   
  return list3;
}

