// Copyright 2018 <Author>

#include "typing_machine.h"



TypingMachine::TypingMachine() {
	cursor = nullptr; 
	size = 0; 
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
	} while (temp1 != nullptr); 
	
	

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
	} while (temp1 != nullptr);

   return ;
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
}

bool TypingMachine::TypeKey(char key) {

	Node* temp; 
	if (size == 100)
		return false; 

	if (key >= 0x20 && key <= 0x7E )
	{
		temp = cursor->InsertPreviousNode(key); 
		if (temp == nullptr)
			return false; 
		size++; 
		return true; 
	}
  return false; 
}

bool TypingMachine::EraseKey() {
	

	if (cursor->ErasePreviousNode() == true)
	{
		size--; 
		return true; 
	}
		

  return false;
}

std::string TypingMachine::Print(char separator) {


	Node *temp; 
	//TypingMachine* tm; 
	string output; 
	
	//reserve cursor position 
	temp = cursor; 

	//move cursor to home position
	this->HomeKey(); 

	//if there is no data, then just put the separator and return output
	if (cursor == nullptr)
	{
		//if separator is 0, do not display the separator
		if (separator != 0)
			output += separator; 
		 
		return output; 
	}
		
	
	//we have data now

	// copy the charactor until we meet the separator
	do
	{
		//printf("%c", cursor->GetData()); 
		
		output += cursor->GetData(); 
		cursor = cursor->GetNextNode(); 
	} while (cursor != temp);


	//separator printf
	if (separator != 0)
		output += separator; 

	

	//after separator, print all characters untill the end 

	while (cursor != nullptr)
	{
		output += cursor->GetData();
		cursor = cursor->GetNextNode();
	}
	
	
	cursor = temp; 

	
  return output;
}
