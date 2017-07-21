typedef int DATA;
struct heapRoot;
#define MAX_HEAP_SIZE 100

struct heapRoot * createHeap(int MaxHeap);
void destroyHeap(struct heapRoot *h);

int insertHeap(struct heapRoot *h, DATA data);
DATA removeHeap(struct heapRoot *h);

DATA GetRoot(struct heapRoot *h);

int getSize(struct heapRoot *h);
DATA getiElement(struct heapRoot *h,int index);
