#include "Staque.h"
#include <iostream>
using namespace std;
// კონსტრუქტორების, დესტრუქტორების და კლასის ფუნქციების იმპლემენტაცია
// 
// default კონსტრუქტორი
Staque::Staque() = default;
// კონსტრუქტორი(კოპირების)
Staque::Staque(Staque & secondList) {
	if (secondList.head == NULL) {
		head = NULL;
	}
	else
	{
		Staque* curr = secondList.head; 
		head = tail = new Staque;
		head->prev = NULL;
		head->data = curr->data;
		curr = curr->next;
		if (curr == NULL)
			head->next = NULL;
		else {
			Staque* curr2 = head; 
			while (curr != NULL) {
				curr2->next = new Staque;
				curr2->next->prev = curr2;
				curr2 = curr2->next;

				curr2->data = curr->data;
				curr = curr->next;
			}
			curr2->next = NULL;
			tail = curr2;
		}
	}
}
// დესტრუქტორი
Staque::~Staque() = default;
// ელემენტის ჩამატება
void Staque::add(Staque * *head_ref, int new_data) {
	// თუ ლუწია ვამატებ სიის წინ (ფუნცქიის ალგორითმის დრო არის O(1))
	if (new_data % 2 == 0) {
		// 1. გამოვუყოთ მეხისერება node - ს 
		Staque* new_node = new Staque();
		// 2. მივანიჭოთ გადმოცემული მნიშვნელობა */
		new_node->data = new_data;
		// 3. შემდეგი ახალი node - ი გავხადოთ სათავე(head) */
		new_node->next = (*head_ref);
		// 4. გადავანაცვლოთ head - დი იმისათვის რომ მიუთითს ახალ node - ზე */
		(*head_ref) = new_node;
	}
	else { // ფუნცქიის ალგორითმის შესრულების დრო არის O(n). სადაც n არის კვანძების რაოდენობა ბმულ სიაში.       
		// 1. გავანაწილოთ მეხსიერება Node - ისთვის
		Staque* new_node = new Staque();
		// ბოლო კვანძს მივანიჭოთ საწყისი კვანძის მისამართი
		Staque* last = *head_ref;
		// 2. მივანიჭოთ int მნიშნელობა new_node - ს
		new_node->data = new_data;
		// 3. მოცემული ახალი კვანძი უნდა გახდეს ბოლო ელმენეტი სიაში ამიტომ მისი შემდგომი უნდა იყოს NULL   
		new_node->next = NULL;
		// 4. თუ ბმული სია ცარიელია new_node გავხადოთ სათავე (Head)
		if (*head_ref == NULL) {
			*head_ref = new_node;
			return;
		}
		// 5. თუ ზემოთ მოყვანილი (მე -4) პირობა არ შესრულდა შევასრულოთ შემდეგი პირობა
		while (last->next != NULL) { // გადავა ბოლო Node - ამდე
			last = last->next;
		}
		// 6. შეცვალეთ ბოლო კვანძის შემდგომი 
		last->next = new_node;
		return;
	}
}
// ელემენტის ამოშლა
// head_ref --> პოინტერი სათავის(head - ის) node პოინტერზე.
// del --> პოინტერი node - ზე რომელიც უნდა წაიშალოს.
void Staque::remove(Staque * *head_ref, Staque * del) {
	// ვამოწმებთ გადმოცემულ პარამეტრებს
	if (*head_ref == NULL || del == NULL)
		return;
	// თუ node რომელიც უნდა წაიშალოს არის სათავე(head node)
	if (del->data % 2 == 0) {
		if (*head_ref == del)
			*head_ref = del->next;
		// ვანთავისუფლებთ მეხსიერებას
		free(del);
	}
	else {
		Staque* lastNode = del->next;
		del->next = NULL;
		// ვანთავისუფლებთ მეხსიერებას
		free(lastNode);
	}
}
// ელემენტის ძიება
bool Staque::search(Staque * head, const int number)const {
	Staque* current = head;
	while (current != NULL) {
		if (current->data == number)
			return true;
		current = current->next;
	}
	return false;
}
// არის თუ არა მასივი ცარიელი
bool Staque::isEmpty(Staque * head)const {
	if (head == NULL) return true;
	return false;
}
// ბმული სიის ბეჭდვა
void Staque::printList(Staque * node) {
	while (node != NULL) {
		cout << node->data << " ";
		node = node->next;
	}
}