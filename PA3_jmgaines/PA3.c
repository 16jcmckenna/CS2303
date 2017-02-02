/* Jonathan Gaines
	PA3		*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *input;

struct treeNode {
	char word[256];
	int count;
	struct treeNode *left, *right;
};

typedef struct treeNode TreeNode;
typedef TreeNode *TreeNodePtr;

int wc = 0;
int unique_wc = 0;

void printAlphabetical(TreeNodePtr treePtr){
	if(treePtr != NULL){
		printAlphabetical(treePtr->left);
		printf("%d - %s\n", treePtr->count + 1, treePtr->word);
		printAlphabetical(treePtr->right);
	}
}//printAlphabetical

void addBranch(TreeNodePtr *treePtr, char word[256]){
	TreeNode *temp = NULL;
	if(*treePtr == NULL){
		temp = (TreeNode *)malloc(sizeof(TreeNode));	
		temp->left = NULL;
		temp->right = NULL;
		strcpy(temp->word, word);
		*treePtr = temp;
		unique_wc++;
	} 
	else if(strcmp(word, (*treePtr)->word) < 0){
		addBranch(&((*treePtr)->left), word);
	} 
	else if(strcmp(word, (*treePtr)->word) > 0){
		addBranch(&((*treePtr)->right), word);
	}
	else if(strcmp(word, (*treePtr)->word) == 0){
		(*treePtr)->count++;
	}
}//addBranch

void readWords(FILE *f){
	char word[256];
	TreeNodePtr root = NULL;
	
	
	while(fscanf(f, "%255s", word) == 1){
		wc++;
		addBranch(&root, word);
	}

	printAlphabetical(root);
}//readWords

int main(int argc, char *argv[]){
	input	= fopen(argv[2], "r");

	readWords(input);
	
	printf("------\n%d words\n%d unique words\n", wc, unique_wc);

	fclose(input);
	return 0;
}//main


