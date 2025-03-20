#include <iostream>

#include "IntList.h"

using namespace std;

void IntList::removeOdds() {

	/* WORKS BUT IS META
	if (this->head == nullptr) {

		return;
	}

	if (this->head->next == nullptr) {

		if (this->head->value % 2 != 0) {

			delete this->head;

			this->head = nullptr;

		}

		return;
	}

	IntNode* prev = this->head;
	IntNode* curr = this->head->next;

	while (curr != nullptr) {

		cout << prev->value << endl;
		cout << curr->value << endl;

		if (prev == this->head && prev->value % 2 != 0) {

			if (prev->value % 2 != 0) {

				IntNode* tmp = this->head;

				prev = prev->next;
				curr = curr->next;
				
				this->head = prev;

				delete tmp;

				continue;
			}

			prev = prev->next;
			curr = prev->next;

			continue;

		}

		if (curr->value % 2 != 0) {

			IntNode* tmp = curr;

			prev->next = curr->next;

			curr = prev->next;

			delete tmp;

			continue;
		}

		prev = prev->next;
		curr = prev->next;

	}
	*/

	/* WORKS BUT IS STILL SLIGHTLY META */

	if (this->head == nullptr) {
		
		return;
	}

	if (this->head->next == nullptr) {
		
		if (this->head->value % 2 != 0) {
			
			delete this->head;

			this->head = nullptr;

		}

		return;
	}

	IntNode* prev = this->head;
	IntNode* curr = this->head->next;

	while (curr != nullptr) {

		if (prev == this->head) {

			if (prev->value % 2 != 0) {

				IntNode* tmp = this->head;

				prev = prev->next;
				curr = curr->next;
				
				this->head = prev;

				delete tmp;

				continue;
			}

			break;

		}

	}

	prev = this->head;
	curr = this->head->next;

	while (curr != nullptr) {

		if (curr->value % 2 != 0) {

			IntNode* tmp = curr;

			prev->next = curr->next;

			curr = prev->next;

			delete tmp;

			continue;
		}

		prev = prev->next;
		curr = prev->next;
	}

}