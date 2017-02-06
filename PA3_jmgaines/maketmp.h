#ifndef MAKETMP_H_INCLUDED
#define MAKETMP_H_INCLUDED

FILE *output, *tmp;

struct treeNode {
	char word[256];
	int count;
	struct treeNode *left, *right;
};

typedef struct treeNode TreeNode;
typedef TreeNode *TreeNodePtr;

int wc;
int unique_wc;
char word[256];

void printInit(FILE *f);

void tmp2out(void);

void removePunc(char arr[256]);

#endif
