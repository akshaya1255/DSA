#include<stdio.h>
#include<stdlib.h>
struct node{
	int coeff;
	int exp;
	struct node *link;
};
void print(struct node *head){
	if(head == NULL){
		printf("polynomial doesn't exist");
	}
	else{
		struct node* temp = head;
		while(temp != NULL){
			printf("(%dx^%d)", temp->coeff,temp->exp);
			
			temp = temp->link;
			if(temp != NULL){
				printf("+");
			}
				else{
					printf("\n");
				}
			}
		}
	}
	
//insertion of nodes acc to exponent
    struct node *insert(struct node *head, int co,int ex){
	struct node *temp;
	struct node *newp = malloc(sizeof(struct node));
	newp->coeff = co;
	newp->exp = ex;
	newp->link = NULL;
	if(head==NULL || ex>head->exp){
		newp->link = head;
		head = newp;
	}
	else{
		temp = head;
		while(temp->link != NULL && temp->exp >= ex)
		temp = temp->link;
		newp->link = temp->link;
		temp->link = newp;
	}
	return head;
}
//creation of the linked list
struct node* create(struct node* head){
	int n,i;
	int coeff;
	int exp;
	printf("enter the number of terms: ");
	scanf("%d", &n);
	for(i=0;i<n;i++){
		printf("enter the coefficient for term %d: ", i+1);
		scanf("%d", &coeff);
		printf("enter the exponenet for term %d: ", i+1);
		scanf("%d", &exp);
		head = insert(head,coeff,exp);
	}
	return head;
}
// polynomial modification
void modify(struct node* head) {
    if (head == NULL) {
        return;
    }
  struct node* current = head;
    
    while (current != NULL) {
    	struct node* runner = current->link;
        
        while (runner != NULL) {
            if (runner->exp == current->exp) {
                current->coeff += runner->coeff;
                struct node* term = runner;
                
                runner = runner->link;
                free(term);
            } else {
                runner = runner->link;
            }
        }
        current = current->link;
    }
}

/*
//addition
void addSameExponents(struct Node*head ) {

    if (head3 == NULL) {
        return;
    }
    
    struct Node* current = head3;
    while (current->next != NULL) {
        if (current->exponent == current->next->exponent) {
            current->coefficient += current->next->term.coefficient;
            struct Node* temp = current->next;
            current->next = current->next->next;
            free(temp);
        } else {
            current = current->next;
        }
    }
}              */
void  pol_multiply(struct node* head1, struct node* head2){
	struct node* p1 = head1;
	struct node* p2 = head2;
	struct node* head3 = NULL;
	if(head1 == NULL || head2 == NULL){
		printf("zero polynomial!!\n");
		return;
	}
	while(p1 != NULL){
		p2 = head2;
		while(p2 != NULL){
			head3 = insert(head3,p1->coeff * p2->coeff, p1->exp + p2->exp);
			p2 = p2->link;
		}
		p1 = p1->link;
	//	p2 = head2;
	}
	printf("first pol \t");
	print(head1);
	printf("\n");
	printf("second pol \t");
	print(head2);
	printf("\nresultant pol\t");
	print(head3);
	printf("\nmodified pol \t");
	modify(head3);
	
	print(head3);
}
int main(){
	
	struct node* head1 = NULL;
	struct node* head2 = NULL;
	printf("enter the first polynomial:\n");
	head1 = create(head1);
	printf("\nenter the second polynomial: \n");
	head2 = create(head2);
	
	pol_multiply(head1,head2);
	
	return 0;
	
}