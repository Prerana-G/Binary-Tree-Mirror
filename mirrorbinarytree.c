#include <stdio.h>
#include <stdlib.h>

struct tree {
  int data;
  struct tree *left, *right;
};
typedef struct tree tnode;
tnode *root = NULL;

tnode *create() {
  tnode *nn;
  nn = (tnode *)malloc(sizeof(tnode));
  printf("Enter node value:");
  scanf("%d", &nn->data);
  nn->left = nn->right = NULL;
  return nn;
}

void insert_BST() {
  tnode *nn, *prev, *temp;
  nn = create();
  if (root == NULL)
    root = nn;
  else {
    temp = root;
    while (temp != NULL) {
      prev = temp;
      if (nn->data < temp->data)
        temp = temp->left;
      else
        temp = temp->right;
    }
    if (nn->data < prev->data)
      prev->left = nn;
    else
      prev->right = nn;
  }
}

void insert_BT()
{
	tnode *nn,*temp,*prev;
	char dir;
	nn=create();
	if(root==NULL)
		root=nn;
	else
	{
		temp=root;
		while(temp!=NULL)
		{
			prev=temp;
			printf("Enter direction (L or R):");
			scanf("%c",&dir);
			if(dir=='L')
				temp=temp->left;
			if(dir=='R')
				temp=temp->right;
			
		}
		if(dir=='L')
			prev->left=nn;
		if(dir=='R')
			prev->right=nn;
		
	}
}
tnode* deletekey(tnode *root,int key)
{
	tnode *temp;
	if(key>root->data)
		root->right=deletekey(root->right, key);
	else if(key<root->data)
		root->left=deletekey(root->left, key);
	else
	{
		if((root->right==NULL)&&(root->left==NULL))
		{
			free(root);
			root=NULL;
		}
		else if(root->right==NULL)
		{
			temp=root;
			root=root->left;
			free(temp);
		}
		else if(root->left==NULL)
		{
			temp=root;
			root=root->right;
			free(temp);
		}
		else
		{
			temp=root->right;
			while(temp->left!=NULL)
				temp=temp->left;
			root->data=temp->data;
			root->right=deletekey(root->right,temp->data);
		}
	}	
	return root;
}
	

void preorder(tnode *root) {
  if (root != NULL) {
    printf("%d\t", root->data);
    preorder(root->left);
    preorder(root->right);
  }
}

void inorder(tnode *root) {
  if (root != NULL) {
    inorder(root->left);
    printf("%d\t", root->data);
    inorder(root->right);
  }
}

void postorder(tnode *root) {
  if (root != NULL) {
    postorder(root->left);
    postorder(root->right);
    printf("%d\t", root->data);
  }
}

void search_bt() {
  tnode *temp;
  int key;
  printf("Enter the key to be searched:");
  scanf("%d", &key);
  temp = root;
  while (temp != NULL) {
    if (key == temp->data)
      printf("Key is present in the tree and is found.");
    else if (key < temp->data)
      temp = temp->left;
    else
      temp = temp->right;
  }
}

void mirror(tnode* root)
{
    if (root == NULL)
        return;
    else {
        if(root->left!=NULL && root->right!=NULL){
        tnode *temp;
        mirror(root->left);
        mirror(root->right);
        temp = root->left;
        root->left = root->right;
        root->right = temp;
        }
    }
}
void display(tnode *root,int h)
{
	int i;
	if(root!=NULL)
	{
		display(root->right,h+1);
		for(i=0;i<h;i++)
			printf("  ");
		printf("%d\n",root->data);
		display(root->left,h+1);
	}
}

int main() {
  int ch;
  printf("\n1.Insert 2.Preorder 3.Inorder 4.Postorder 5.search key 6.Mirror image 7.Display 8.Exit");
  while (1) {
    printf("\nEnter your choice:");
    scanf("%d", &ch);
    switch (ch) {
    case 1:
      insert_BT();
      break;
    case 2:
      preorder(root);
      break;
    case 3:
      inorder(root);
      break;
    case 4:
      postorder(root);
      break;
    case 5:
      search_bt();
      break;
    case 6: mirror(root);
    break;
    case 7:display(root,0); break;
    case 8:
      exit(0);
    default:
      printf("Invalid choice!\n");
    }
  }

  return 0;
}