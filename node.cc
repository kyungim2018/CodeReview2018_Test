// Copyright 2018 <Author>

#include "node.h"

Node::Node(char data) {
  this->val = data; 
  this->pPriv = nullptr; 
  this->pNext = nullptr; 

  return;
}



char Node::GetData() {

  return this->val;

}



Node* Node::GetPreviousNode() {
  //if there is no previous Node
 if (this->pPriv == nullptr)
  return nullptr;
 else
  return this->pPriv; 

 // return nullptr;
}

Node* Node::GetNextNode() {
  //if there is no next Node
 if (this->pNext == nullptr)
  return nullptr;
 else
  return this->pNext; 
  
 //return nullptr;
}

Node* Node::InsertPreviousNode(char data) {
  
  Node *NewNode=new Node(data);

 Node *temp; 

 temp = GetPreviousNode();
 if (temp == nullptr)
 {
  this->pPriv = NewNode;
  NewNode->pNext = this; 
 }
 else
 {
  temp->pNext = NewNode;
  NewNode->pPriv = temp;

  NewNode->pNext = this;
  this->pPriv = NewNode;
 }
  return NewNode;
}

Node* Node::InsertNextNode(char data) {
   Node *NewNode = new Node(data);

 Node *temp;

 temp = GetNextNode(); 

 if (temp == nullptr)
 {
  //no next node
  this->pNext = NewNode;
  NewNode->pPriv = this; 

 }
 else
 {
  this->pNext = NewNode; 
  temp->pPriv = NewNode; 

  NewNode->pPriv = this;
  NewNode->pNext = temp; 

 }


  return NewNode;
}

bool Node::ErasePreviousNode() {
  Node *DellNode; 
 Node *temp; 

 DellNode = GetPreviousNode();

 if (DellNode == nullptr)
  return false; 
 else
 {
  temp = DellNode->pPriv; 
  if (temp == nullptr)
  {
   this->pPriv = nullptr; 
  }
  else
  {
   this->pPriv = temp; 
   temp->pNext = this; 
  }
  
  delete(DellNode);

 }
  return true;
}

bool Node::EraseNextNode() {
  Node *DellNode;
 Node *temp;

 DellNode = GetNextNode();

 if (DellNode == nullptr)
  return false;
 else
 {
  temp = DellNode->pNext;
  if (temp == nullptr)
  {
   this->pNext = nullptr;
  }
  else
  {
   temp->pPriv = this;
   this->pNext = temp;
  }

  delete(DellNode); 

 }
 return true;
}
