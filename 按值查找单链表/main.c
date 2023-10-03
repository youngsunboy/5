#include <stdio.h>
#include <stdlib.h>

//定义一个类型的新名
typedef char datatype;
//单链表结构体
typedef struct node {
	datatype data;
	struct node* next;
}linklist;

linklist* CreatListR() {
	//带头结点的尾插法，返回单链表的头指针
	linklist* head, * p, * r;
	datatype ch;
	head = (linklist*)malloc(sizeof(linklist));//产生头结点
	head->next = NULL;
	r = head;//r指针指向头结点
	while ((ch = getchar()) != '\n') {
		p = (linklist*)malloc(sizeof(linklist));//生成新结点
		p->data = ch;//对结点的数据域进行赋值
		r->next = p;//新结点指向表尾
		r = p;//r指针指向新表尾
	}
	r->next = NULL;
	return head;
}

linklist* Locate(linklist* head, datatype key) {
	linklist* p = head->next;//p指向第一个结点
	while (p != NULL && p->data != key) {
		p = p->next;
	}
	return p;
}
//主函数
int main() {
	linklist* head = (linklist*)malloc(sizeof(linklist));
	linklist* p = (linklist*)malloc(sizeof(linklist));
	head = CreatListR();
	printf("请输入需要寻找的字符：");
	datatype ch = getchar();
	p = Locate(head, ch);
	if (p) {
		printf("找到了！\n");
	}
	else {
		printf("NULL!\n");
	}
	system("pause");
	return 0;
}