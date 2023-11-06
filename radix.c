#include<stdio.h>
#include<stdlib.h>
// RDAIX SORT...
struct node{
	int data;
	struct node* link;
};
void create(struct node *head, struct node *temp,int n){
    
    int i;
        for(i=0;i<n-1;i++){
        struct node *current= (struct node *)malloc(sizeof(struct node));
        printf(" enter the data value of num %d:\n",i+2);
        scanf("%d", &current->data);
        current->link = NULL;
        temp->link= current;
        temp = temp->link;
    
	}
}
void print(struct node *head){
    struct node *ptr;
    ptr = head;
    if(head==NULL){
        printf("linked list is empty\n");
    }
    else{
        while(ptr != NULL){
            printf("%d\t", ptr->data);
            ptr=ptr->link;
        }
    }
    
}
int find_greatest(struct node* head, int g, int high){
	g = head->data;
	struct node* ptr = (struct node*)malloc(sizeof(struct node));
	ptr = head;
	while(ptr->link != NULL){
		if(ptr->data < ptr->link->data){
			g = ptr->link->data;
		}
		
		ptr = ptr->link;
	}
	printf("\n the greatest of all the numbers is: %d", g);
	high = g;
	return 0;
}
int main(){
	int n;
	int g;
	int large;
	printf("enter the number of values that has to be sorted: ");
	scanf("%d", &n);
	struct node* head = (struct node*)malloc(sizeof(struct node));
	printf("\n enter the value of first num: ");
	scanf("%d", &head->data);
	head->link = NULL;
	struct node* temp;
	temp = head;
	create(head,temp,n);
	printf("\n Unsorted list of numbers:\t");
	print(head);
	printf("\n");
	
	
	find_greatest(head, g, large);
	printf("\n%d", large);
	return 0;
}