// Copyright 2018 <Author>

#include "node.h"

Node::Node(char data) {
  return;
}

char Node::GetData() {
  return '\0';
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
  return nullptr;
}

Node* Node::InsertNextNode(char data) {
  return nullptr;
}

bool Node::ErasePreviousNode() {
  return false;
}

bool Node::EraseNextNode() {
  return false;
}
