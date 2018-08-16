// Copyright 2018 <Author>

#include "typing_machine.h"



TypingMachine::TypingMachine() {
	
	cursor = new Node('|');
	size = 0; 
  return;
}

void TypingMachine::HomeKey() {

	Node* running_head; 
	Node* head; 
	
	

	
	

	
	if (cursor->GetPreviousNode() == nullptr)
		return; 

	//remove current cursor 
	cursor = cursor->GetPreviousNode(); 
	cursor->EraseNextNode(); 

	running_head = cursor;
	head = cursor;

	
	while (running_head != nullptr)
	{
		head = running_head; 
		running_head = running_head->GetPreviousNode(); 
	}

	//found the head , and put the cursor; 
	cursor = head->InsertPreviousNode('|');
	 

			

  return;
}

void TypingMachine::EndKey() {


	Node* running_end;
	Node* end;

	
	

	if (cursor->GetNextNode() == nullptr)
		return; 

	//remove current cursor 
	cursor = cursor->GetNextNode();
	cursor->ErasePreviousNode();

	running_end = cursor;
	end = cursor;


	while (running_end != nullptr)
	{
		end= running_end;
		running_end = running_end->GetNextNode();
	}

	//found the tail , and put the data; 
	cursor = end->InsertNextNode('|');
	

   return ;
}

void TypingMachine::LeftKey() {
	
	if (cursor->GetPreviousNode() == nullptr)
		return; 

	//want to remove cursor position
	cursor = cursor->GetPreviousNode();
	//originalcursor is removed
	cursor->EraseNextNode();

	cursor = cursor->InsertPreviousNode('|'); 


  return;
}

void TypingMachine::RightKey() {
	
	
	if (cursor->GetNextNode() == nullptr)
		return; 

	cursor = cursor->GetNextNode(); 
	cursor->ErasePreviousNode(); 
     
	cursor = cursor->InsertNextNode('|');

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


	Node *position; 
	Node *head; 
	Node *running_head; 
	//TypingMachine* tm; 
	string output; 
	char inChar; 
	
	
	//if there is no data, then just put the separator and return output
	if (size == 0)
	{
		//if separator is 0, do not display the separator
		if (separator != 0)
			output += separator; 
		 
		return output; 
	}
		
	
	//we have data now

	// copy the charactor until we meet the separator
	//reserve cursor position; 
	position = cursor; 

	running_head = cursor; 
	head = cursor; 

	//find the home position
	while (running_head != nullptr)
	{
		head = running_head; 
		running_head = running_head->GetPreviousNode(); 
	}

	
	do
	{
		//printf("%c", cursor->GetData()); 
		inChar = head->GetData(); 
		if (inChar != 0)
		{
			if (inChar == '|')
				output += separator;
			else
				output += inChar; 
		}
	     	
		head = head->GetNextNode(); 
	} while (head != nullptr);


			
	
	cursor = position; 

	
  return output;
}
