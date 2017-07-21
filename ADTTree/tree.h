typedef int DATA;
typedef struct treeCDT *TreeADT;

TreeADT createTree();
void DestroyTree(TreeADT *rootADT);
int AVLInsert(TreeADT *rootADT, DATA data);
int AVLRemove(TreeADT *rootADT, DATA data);
void PrintAVLTree(TreeADT *rootADT);
