#include<stdio.h>
#include<stdlib.h>
struct Node{
	int data;
	struct Node*next;
	struct Node*prev;
};
struct Node*createNode(int data){
	struct Node*newNode=
	(struct Node*)malloc(sizeof(struct Node));
	newNode->data=data;
	newNode->next=NULL;
	newNode->prev=NULL;
	return newNode;
}
void forwardTraversal(struct Node*head){
	struct Node*curr = head;
	while (curr !=NULL){
		printf("%d",curr->data);
		curr=curr->next;
	}
	printf("\n");
}
void backwardTraversal(struct Node*tail){
	struct Node*curr=tail;
	while(curr !=NULL){
		printf("%d",curr->data);
		curr=curr->prev;
	}
	printf("\n");
}
int main(){
	struct Node* head =createNode(10);
	struct Node* second =createNode(20);
	struct Node* third =createNode(30);
	struct Node* fourth =createNode(40);
	struct Node* fifth =createNode(50);
	struct Node* sixth =createNode(60);
	struct Node* seventh =createNode(70);
	
	
	head->next =second;
	second->prev=head;
	second->next=third;
	third->prev =second;
	third->next =fourth;
	fourth->prev =third;
	fourth->next =fifth;
	fifth->prev =fourth;
	fifth->next =sixth;
	sixth->prev =fifth;
	sixth->next =seventh;
	seventh->prev =sixth;
	
	printf("Forward Traversal: \n");
	forwardTraversal(head);
	
	printf("Backward Traversal: \n");
	backwardTraversal(seventh);
	
	free(head);
	free(second);
	free(third);
	free(fourth);
	free(fifth);
	free(sixth);
	free(seventh);
	
	return 0;
}
