#include <stdio.h>
#include <stdlib.h>

struct ListNode {
	int val;
	struct ListNode *next;
};

struct ListNode *
append_node(struct ListNode **head, int number)
{
	struct listnode *beginning = malloc(sizeof(struct listnode)),
					*end = null;

	beginning->val = number;
	beginning->next =  null;

	if (!*head) *head = beginning;
	else {
		end = *head;
		while (end->next) end = end->next;
		end->next = beginning;
	}

	return *head;
}

struct ListNode *
addTwoNumbers(struct ListNode *l1, struct ListNode *l2) {
	int carried = 0; 
	struct ListNode *result = NULL;

	while (l1 || l2) {
		carried += (l1 ? l1->val : 0) + (l2 ? l2->val : 0);
		result = append_node(&result, carried % 10);
		carried /= 10;
		l1 = l1 ? l1->next : NULL;
		l2 = l2 ? l2->next : NULL;
	}
	if (carried != 0) result = append_node(&result, carried);

	return result;
}

void
free_list(struct ListNode *head)
{
	while (head) { struct ListNode *temp = head->next; free(head); head = temp; }
}

void
print_list(struct ListNode *head)
{
	printf("---------------------------------------------------------------\n");
	for (int i = 0; head; i++) {
		printf("[INFO] Element %d: %d\n", i, head->val);
		head = head->next;
	}
}

int
main(void)
{
	struct ListNode *l1 = NULL, *l2 = NULL;

	for (int i = 0; i < 3; i++) l1 = append_node(&l1, 9);
	for (int j = 0; j < 6; j++) l2 = append_node(&l2, 9);

	if (l1) print_list(l1);
	if (l2) print_list(l2);
	struct ListNode *result = addTwoNumbers(l1, l2);
	if (result) print_list(result);

	free_list(l1);
	free_list(l2);
	free_list(result);

	return 0;
}

/***************************************************************************
 * @brief Original approach
 * @description This failed as it didn't account for numbers of different
 * lengths and thus I ran into SIGSEGV for the testcase described below
 * @example l1: [9, 9, 9, 9]
 * @example l2: [9, 9, 9, 9, 9, 9]
 * @code
 * struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
 *     int carried = 0;
 *     struct ListNode *result = NULL;
 * 
 *     while(carried != 0 || l1 || l2) {
 *         carried += (l1 ? l1->val : 0) + (l2 ? l2->val : 0);
 *         result = append_node(&result, carried % 10);
 *         carried /= 10;
 *         l1 = l1 ? l1->next : NULL;
 *         l2 = l2 ? l2->next : NULL;
 *     }
 *
 *     return result;
 * }
 * @code
 ***************************************************************************/
