#include<stdio.h>
#include<stdlib.h>

//sparse matrix question with user input values
//row index and column index starts from 0

struct node{
	int val;
	int row_pos;
	int col_pos;
	struct node* next;
};

void create(struct node** start, int val, int row_index, int col_index){
	struct node *temp,*r;
	temp = *start;
	if(temp == NULL){
		temp = (struct node*) malloc(sizeof(struct node));
		temp->val = val;
		temp->row_pos = row_index;
		temp->col_pos = col_index;
		temp->next = NULL;
		*start = temp;
	}
	
	else{
		while(temp->next != NULL)
			temp = temp->next;
			r = (struct node*)  malloc(sizeof(struct node));
			r->val = val;
			r->row_pos = row_index;
			r->col_pos = col_index;
			r->next = NULL;
			temp->next = r;
		
	}
	
} 

void print(struct node* start){
	struct node *temp,*x,*y;
	temp = x = y = start;
printf("row index:\t");
while(temp != NULL){
	printf("%d ", temp->row_pos);
	temp = temp->next;
}
printf("\n");
printf("col index:\t");
while(x != NULL){
	printf("%d ", x->col_pos);
	x = x->next;
}
printf("\n");
printf("value :  \t");
while(y != NULL){
	printf("%d ", y->val);
	y = y->next;
}
printf("\n");

}


int main(){
	int a,b;
	 int i,j;
	printf("enter the dimensions of 2D matrix: \n");
	scanf("%d%d", &a,&b);
	int sparse[a][b];
	for(i=0;i<a;i++){
		for(j=0;j<b;j++){
			printf("enter the values: \n");
			scanf("%d", &sparse[i][j] );
		}
	}
	printf("\n");
	printf("the matrix of elements entered is as follows:\n");
	for(i=0;i<a;i++){
		for(j=0;j<b;j++){
			printf("%d", sparse[i][j]);
			printf("\t");
		}
		printf("\n");
	}	
	printf("\n\n");
   struct node* start = NULL;
  
   for(i=0;i<a;i++){
   	for(j=0;j<b;j++){
   		if(sparse[i][j] != 0){
   			create(&start,sparse[i][j],i,j);
		   }
		     
	   }
	 
   }
   print(start);
   
   printf("\n\n");
   

   return 0;
}