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
	int level_limit = 1; // 현재 레벨의 노드 수
	int level_count = 0; // 현재 레벨에서 출력된 노드 수

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
// 삭제 함수
element delete_max_heap(HeapType* h)
{
	int parent, child;
	element item, temp;

	item = h->heap[1];
	temp = h->heap[(h->heap_size)--];
	parent = 1;
	child = 2;
	while (child <= h->heap_size) {
		// 현재 노드의 자식노드 중 더 작은 자식노드를 찾는다.
		if ((child < h->heap_size) &&
			(h->heap[child].key) < h->heap[child + 1].key)
			child++;
		if (temp.key >= h->heap[child].key) break;
		// 한 단계 아래로 이동
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

	heap = create(); 	// 히프 생성
	init(heap);	// 초기화
	char menu = 0;
	printf("-----------------\n");
	printf("   i    : 노드 추가\n");
	printf("   d    : 노드 삭제\n");
	printf("   p    : 레벨별 출력\n");
	printf("   c    : 종료\n");
	printf("-----------------\n");

	while (menu != 'c') {
		printf("\n");
		printf("\n");
		printf("메뉴 입력: ");
		scanf_s(" %c", &menu);

		switch (menu) {

		case 'i':
			printf("추가할 값 입력:");
			scanf_s("%d", &ein);
			insert_max_heap(heap, ein);
			print_heap(heap);			
			break;
		case 'd':
			printf("삭제할 값 입력:");
			scanf_s("%d", &ede);
			delete_max_heap(heap);
			break;
		case 'p':
			printf("트리 레벨별 출력:\n");
			print_heap(heap);
			break;

		case 'c':
			printf("프로그램을 종료합니다.\n");
			break;
		default:
			printf("잘못된 메뉴 선택입니다. 다시 시도하세요.\n");
		}
	}
	
	free(heap);
	return 0;
}