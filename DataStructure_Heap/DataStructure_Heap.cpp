#include<stdio.h>
#include<stdlib.h>
#define MAX_ELEMENT 200

typedef struct {
	int key;
} element;
typedef struct {
	element heap[MAX_ELEMENT];
	int heap_size;
} HeapType;

HeapType* create() {
	return (HeapType*)malloc(sizeof(HeapType));
}
void init(HeapType* h) {
	h->heap_size = 0;
}

void insert_max_heap(HeapType* h, element item) {
	int i;
	i = ++(h->heap_size);

	while ((i != 1) && (item.key > h->heap[i / 2].key)) {
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	}
	h->heap[i] = item;
}

void print_heap(HeapType* h) {
	int i, level = 1;
	int level_limit = 1; // ���� ������ ��� ��
	int level_count = 0; // ���� �������� ��µ� ��� ��

	for (i = 1; i <= h->heap_size; i++) {
		if (level_count == level_limit) {
			printf("\nLevel %d: ", level);
			level_limit *= 2;
			level_count = 0;
			level++;
		}
		printf("%d ", h->heap[i].key);
		level_count++;
	}
	printf("\n");
}
// ���� �Լ�
element delete_max_heap(HeapType* h)
{
	int parent, child;
	element item, temp;

	item = h->heap[1];
	temp = h->heap[(h->heap_size)--];
	parent = 1;
	child = 2;
	while (child <= h->heap_size) {
		// ���� ����� �ڽĳ�� �� �� ���� �ڽĳ�带 ã�´�.
		if ((child < h->heap_size) &&
			(h->heap[child].key) < h->heap[child + 1].key)
			child++;
		if (temp.key >= h->heap[child].key) break;
		// �� �ܰ� �Ʒ��� �̵�
		h->heap[parent] = h->heap[child];
		parent = child;
		child *= 2;
	}
	h->heap[parent] = temp;
	return item;
}


int main(void)
{
	element e1 = { 90 }, e2 = { 89 }, e3 = { 70 }, e4 = { 36 }, e5 = { 75 }, e6 = { 63 }, e7 = { 65 }, e8 = { 21 }, e9 = { 18 }, e10 = { 15 };
	element ein, ede;
	HeapType* heap;

	heap = create(); 	// ���� ����
	init(heap);	// �ʱ�ȭ
	char menu = 0;
	printf("-----------------\n");
	printf("   i    : ��� �߰�\n");
	printf("   d    : ��� ����\n");
	printf("   p    : ������ ���\n");
	printf("   c    : ����\n");
	printf("-----------------\n");

	while (menu != 'c') {
		printf("\n");
		printf("\n");
		printf("�޴� �Է�: ");
		scanf_s(" %c", &menu);

		switch (menu) {

		case 'i':
			printf("�߰��� �� �Է�:");
			scanf_s("%d", &ein);
			insert_max_heap(heap, ein);
			print_heap(heap);			
			break;
		case 'd':
			printf("������ �� �Է�:");
			scanf_s("%d", &ede);
			delete_max_heap(heap);
			break;
		case 'p':
			printf("Ʈ�� ������ ���:\n");
			print_heap(heap);
			break;

		case 'c':
			printf("���α׷��� �����մϴ�.\n");
			break;
		default:
			printf("�߸��� �޴� �����Դϴ�. �ٽ� �õ��ϼ���.\n");
		}
	}
	
	free(heap);
	return 0;
}