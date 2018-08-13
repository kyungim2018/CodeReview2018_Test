// Copyright 2018 <Author>

#include "typing_machine.h"

TypingMachine::TypingMachine() {
  cursor = nullptr; 
  return;
}

void TypingMachine::HomeKey() {
  Node* temp; 
 Node* temp1; 
 
 temp = cursor; 
 temp1 = nullptr; 

 do
 {
  temp1 = temp->GetPreviousNode();
  if (temp1 == nullptr)
   cursor = temp; 
  else
      temp = temp1; 
 }
 while (temp1 != nullptr)
  return;
}

void TypingMachine::EndKey() {
  Node* temp;
 Node* temp1;

 temp = cursor;
 temp1 = nullptr;

 do
 {
  temp1 = temp->GetNextNode();
  if (temp1 == nullptr)
   cursor = temp;
  else
   temp = temp1;
 } while (temp1 != nullptr)

  return;
  return;
}

void TypingMachine::LeftKey() {
  Node* temp; 

 temp = cursor->GetPreviousNode();
 if (temp != nullptr)
  cursor = temp; 
  return;
}

void TypingMachine::RightKey() {
  Node* temp; 

 temp = cursor->GetNextNode(); 
 if (temp != nullptr)
  cursor = temp; 
    return;
  return;
}

bool TypingMachine::TypeKey(char key) {
  Node* temp; 
 if (key >= 0x20 && key <= 0x7E)
 {
  temp = cursor->InsertNextNode(key); 
  if (temp == nullptr)
   return false; 
  return true; 
 }
  return false;
}

bool TypingMachine::EraseKey() {
  Node* temp; 

 if (cursor->ErasePreviousNode() == true)
  return true; 
  
 return false;
}

std::string TypingMachine::Print(char separator) {
  return "";
}
