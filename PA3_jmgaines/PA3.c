/* Jonathan Gaines
	PA3		*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *output, *tmp;

struct treeNode {
	char word[256];
	int count;
	struct treeNode *left, *right;
};

typedef struct treeNode TreeNode;
typedef TreeNode *TreeNodePtr;

int wc = 0;
int unique_wc = 0;

void printInit(FILE *f){
	char word[256];
	while(fscanf(f, "%255s", word) == 1){
		fprintf(tmp, "%s \n", word);
	}
}//printInit

void printAlphabetical(TreeNodePtr treePtr){
	if(treePtr != NULL){
		printAlphabetical(treePtr->left);
		fprintf(output, "%d - %s\n", treePtr->count + 1, treePtr->word);
		printAlphabetical(treePtr->right);
	}
}//printAlphabetical

void addBranch(TreeNodePtr *treePtr, char word[256]){
	TreeNode *temp = NULL;
	if(*treePtr == NULL){
		temp = (TreeNode *)malloc(sizeof(TreeNode));	
		temp->left = NULL;
		temp->right = NULL;
		temp->count = 0;
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
	fprintf(output, "------\n%d words\n%d unique words\n", wc, unique_wc);
}//readWords

int main(int argc, char *argv[]){
	output = fopen(argv[1], "w+");
	tmp = fopen("tmp.txt", "w+");

	for(int i = 2; i < argc; i++){
		FILE *input;
		input	= fopen(argv[i], "r");
		printInit(input);
		fclose(input);
	}
	fclose(tmp);
	tmp = fopen("tmp.txt", "r");

	readWords(tmp);
	
	fclose(output);
	fclose(tmp);
	remove("tmp.txt");
	return 0;
}//main



