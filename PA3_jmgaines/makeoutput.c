#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "maketmp.h"
#include "makeoutput.h"


void printAlphabetical(TreeNodePtr treePtr){
	if(treePtr != NULL){
		printAlphabetical(treePtr->left);
		fprintf(output, "%4d - %s\n", treePtr->count + 1, treePtr->word);
		printAlphabetical(treePtr->right);
	}
	free(malloc(sizeof(TreeNode)));
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
	fprintf(output, "----------\n%d words\n%d unique words\n", wc, unique_wc);
}//readWords

