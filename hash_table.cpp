// Hash Table Implementation using Linked Lists with chaining
// Has O(1) Search

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
		this->ht = new LinkedListNode*[size]; //array of pointers
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
			while(curr->next!=NULL){
				curr = curr->next;
			}
			curr->next = createNode(key, value);
		}
		return;
	};

	void Search(int key){
		int index = hashFunction(key);
		if (this->ht[index]==NULL){
			std::cout << "Key Not Found." << '\n';
			return;
		}
		LinkedListNode *curr = this->ht[index];
		while(curr!=NULL){
			if (curr->key==key) {
				std::cout << "Key Found with value " << curr->value << '\n';
				return;
			}
			curr = curr->next;
		}
		std::cout << "Key Not Found." << '\n';
		return;
	};

	void Delete(int key){
		int index = hashFunction(key);
		if (this->ht[index]==NULL){
			std::cout << "Key Not Found." << '\n';
			return;
		}
		LinkedListNode *curr = this->ht[index];
		if (curr->key==key) {
			std::cout << "Key Found with value " << curr->value << '\n';
			curr = NULL;
			return;
		}
		LinkedListNode *prev = curr;
		curr = curr->next;
		while(curr!=NULL){
			if (curr->key==key) {
				std::cout << "Key Found with value " << curr->value << '\n';
				prev->next = curr->next;
				return;
			}
			prev =  prev->next;
			curr = curr->next;
			return;
		}
		std::cout << "Key Not Found." << '\n';
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
	int c;
	while (1){
		std::cout << "Enter 1 for Insertion," << ' ' <<
		"2 for Search," << ' ' <<
		"3 for Deletion," << ' ' <<
		"4 for Exit." << '\n';
		std::cin>>c;
		switch (c) {
			case 1:
				std::cout<<"Enter Key"<<'\n';
				std::cin>>key;
				std::cout<<"Enter Value"<<'\n';
				std::cin>>value;
				ht.Insert(key, value);
				break;
			case 2:
				std::cout<<"Enter Key"<<'\n';
				std::cin>>key;
				ht.Search(key);
				break;
			case 3:
				std::cout<<"Enter Key"<<'\n';
				std::cin>>key;
				ht.Delete(key);
				break;
			case 4:
				exit(1);
			default:
			std::cout<<"Enter a value from 1 to 4"<<'\n';
		}
	}
	return 0;
}
