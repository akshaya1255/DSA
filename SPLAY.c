#include<stdio.h>
#include<stdlib.h>
struct node
{
	int key;
	struct node *left, *right;
};

void insert(int x, struct node *root){
    if(root == NULL) {
        (root) = (struct node*)malloc(sizeof(struct node));
        (*root)->key=x;
        ((*root) -> left) = ((*root) -> right) = NULL;
    }else{
        if((*root)->key>x)
        insert(x, &((*root)->left));
        else
        insert(x,&((*root)->right));
    }
}

struct node *rightRotate(struct node *x)
{
	struct node *y = x->left;
	x->left = y->right;
	y->right = x;
	return y;
}

struct node *leftRotate(struct node *x)
{
	struct node *y = x->right;
	x->right = y->left;
	y->left = x;
	return y;
}

struct node *splay(struct node *root, int key)
{
	if (root == NULL || root->key == key)
		return root;

	if (root->key > key)
	{
		if (root->left == NULL) return root;

		if (root->left->key > key)
		{
            printf("zig - zig rotation - ");
			root->left->left = splay(root->left->left, key);

			root = rightRotate(root);
		}
		else if (root->left->key < key)
		{
            printf("zig - zag rotation - ");
			root->left->right = splay(root->left->right, key);

			if (root->left->right != NULL)
				root->left = leftRotate(root->left);
		}

		return (root->left == NULL)? root: rightRotate(root);
	}
	else
	{
		
		if (root->right == NULL) return root;

		
		if (root->right->key > key)
		{
            printf("zag-zig rotation - ");
			root->right->left = splay(root->right->left, key);

			if (root->right->left != NULL)
				root->right = rightRotate(root->right);
		}
		else if (root->right->key < key)
		{
            printf("zag-zag rotation - ");
			root->right->right = splay(root->right->right, key);
			root = leftRotate(root);
		}

		return (root->right == NULL)? root: leftRotate(root);
	}
}

struct node *search(struct node *root, int key)
{
	return splay(root, key);
}

void preOrder(struct node *root)
{
	if (root != NULL)
	{
		printf("%d ", root->key);
		preOrder(root->left);
		preOrder(root->right);
	}
}

int main()
{
 struct node *root = NULL;
 int size;
 printf("enter the no of elements\n");
 scanf("%d",size);
 for(int i = 0 ;i < size ; i++)
 {
    int n;
    printf("enter the value\n");
        scanf("%d",&n);
        insert(n, &root);
    
 }
 int val;
 printf("enter the element you want to search\n");
 scanf("%d",&val);
	root = search(root, val);
	printf("Preorder traversal of the modified Splay tree is \n");
	preOrder(root);
	return 0;
}