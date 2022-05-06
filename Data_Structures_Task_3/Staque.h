#pragma once
// Staque - ს იმპლემენტაციისთვის გამოვიყენე ორმხრივად ბმული სია(Doubly Linked List)
class Staque {
private:
	int data;
	Staque* next;
	Staque* prev;
	// Copy კონსტრუქტორისთვის
	Staque* head;
	Staque* tail;
public:
	// getters
	Staque* getNext() {
		return next;
	}
	Staque* getPrev() {
		return prev;
	}

	// default კონსტრუქტორი
	Staque();

	// კონსტრუქტორი(კოპირების)
	Staque(Staque& secondList);

	// დესტრუქტორი
	~Staque();

	// ელემენტის ჩამატება
	void add(Staque** head_ref, int new_data);

	// ელემენტის ამოშლა
	void remove(Staque** head_ref, Staque* del);

	// ელემენტის ძიება
	bool search(Staque* head, const int number)const;

	// არის თუ არა მასივი ცარიელი
	bool isEmpty(Staque* head)const;

	// ბმული სიის ბეჭდვა
	void printList(Staque* node);
};