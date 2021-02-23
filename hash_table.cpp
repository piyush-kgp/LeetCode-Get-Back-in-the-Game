// Hash Table Implementation using Linked Lists with chaining
// Has O(1) average search complexity

#include <iostream>

class LinkedListNode{
public:
	int key, value;
	LinkedListNode *next;
};


LinkedListNode *createNode(int k,int v){
	LinkedListNode *temp = new LinkedListNode;
	temp->key = k;
	temp->value = v;
	temp->next = NULL;
	return temp;
}


class HashTable{

private:

	int size;
	LinkedListNode **ht;

public:

	HashTable(int size){
		this->size=size;
		this->ht = new LinkedListNode*[size]; //array of pointers, length of array=#indices in HT, we have a LL at each index
		for (int i = 0; i < size; i++) {
			this->ht[i] = NULL;
		}
	};

	int hashFunction(int key){
		return key%this->size;
	}

	void Insert(int key, int value){
		int index = hashFunction(key);
		if (this->ht[index]==NULL){
			this->ht[index] = createNode(key, value);
		} else {
			LinkedListNode *curr = this->ht[index];
			// std::cout << "Sth there" << '\n' << "Present:" << curr->value << " Incoming:" << value << '\n';
			if (curr->key==key) {this->ht[index] = createNode(key, value); return;}
			while(curr->next!=NULL && curr->next->key != key){
				curr = curr->next;
			}
			curr->next = createNode(key, value);
		}
		return;
	};

	bool Search(int key){
		int index = hashFunction(key);
		if (this->ht[index]==NULL){
			std::cout << "Key Not Found." << '\n';
			return 0;
		}
		LinkedListNode *curr = this->ht[index];
		while(curr!=NULL){
			std::cout << "Traversing LL to look for " << key << " Curr:" << curr->key << '\n';
			if (curr->key==key) {
				std::cout << "Key Found with value " << curr->value << '\n';
				return 1;
			}
			curr = curr->next;
		}
		std::cout << "Index found but Key Not Found." << '\n';
		return 0;
	};

	void Delete(int key){
		if (!Search(key)){ std::cout << "Key Not Found." << '\n'; return; }

		int index = hashFunction(key);
		if (this->ht[index]->key==key){ this->ht[index]=this->ht[index]->next; return;  }

		LinkedListNode *curr = this->ht[index];
		while (curr->next->key!=key) curr = curr->next;
		curr->next = curr->next->next;
		return;
	};

	void Display(){
		std::cout << "Current HashTable" << '\n';
		for (int idx=0; idx<this->size; idx++) {
			std::cout << idx << ": [";
			LinkedListNode *curr = this->ht[idx];
			while(curr!=NULL){
				std::cout << '{' << curr->key << ':' << curr->value <<'}' << ',';
				curr = curr->next;
			}
			std::cout << ']' << '\n';
		}
		return;
	};

	~HashTable(){
		delete []ht;
	};

};


void test(){
	LinkedListNode *ll = createNode(2,3);
	ll->next = createNode(3,4);
	ll->next->next = createNode(4,5);
}


int  main(){
	HashTable ht =  HashTable(20);
	int key, value;
	int choice;
	while (1){
		std::cout << "Enter 1 for Insertion," << ' ' <<
		"2 for Search," << ' ' <<
		"3 for Deletion," << ' ' <<
		"4 for Display," << ' ' <<
		"5 for Exit." << '\n';
		if (!(std::cin>>choice)){
			std::cin.clear();
			while (std::cin.get()!= '\n');
			std::cout << "Invalid Input data type!\n";
			continue;
		}
		switch (choice) {
			case 1:
				std::cout<<"Enter Key to Insert"<<'\n';
				std::cin>>key;
				std::cout<<"Enter Value"<<'\n';
				std::cin>>value;
				ht.Insert(key, value);
				break;
			case 2:
				std::cout<<"Enter Key to Search"<<'\n';
				std::cin>>key;
				ht.Search(key);
				break;
			case 3:
				std::cout<<"Enter Key to Delete"<<'\n';
				std::cin>>key;
				ht.Delete(key);
				break;
			case 4:
				ht.Display();
				break;
			case 5:
				exit(1);
			default:
				std::cout<<"Enter an int from 1 to 5 as choice"<<'\n';
				break;
		}
	}
	return 0;
}
