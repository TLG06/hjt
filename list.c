#include <stdio.h>
#include <stdlib.h>

typedef struct NODE
{
	int id;
	char *name;
	char *tel;
	struct NODE *pNext;
}Node;
void DelNode(Node **ppHead,Node **ppEnd,int id);
void AddNode(Node **ppHead,Node **ppEnd,Node *pNode);
Node* GetNode(int id,char *name,char *tel);

void InsertNode(Node **ppHead,Node **ppEnd,Node *pNode,int id);

int main()
{

	Node *pHead = NULL;
	Node *pEnd = NULL;

	AddNode(&pHead,&pEnd,GetNode(1,"aa","110"));
	AddNode(&pHead,&pEnd,GetNode(2,"bb","111"));
	AddNode(&pHead,&pEnd,GetNode(3,"cc","112"));

	InsertNode(&pHead,&pEnd,GetNode(4,"dd","113"),5);
	DelNode(&pHead,&pEnd,1);
	while(pHead != NULL)
	{
		printf("%d\n",pHead->id);
		pHead = pHead->pNext;
	
	}
	return 0;
}

Node* GetNode(int id,char *name,char *tel)
{
	Node *pNode = (Node*)malloc(sizeof(Node));
	pNode->id = id;
	pNode->name = name;
	pNode->tel = tel;
	pNode->pNext = NULL;

	return pNode;
}

void AddNode(Node **ppHead,Node **ppEnd,Node *pNode)
{
	//1.判断链表是否存在节点
	if(*ppHead == NULL)
	{
		//不存在  让头指针指向新来的节点  更新尾节点
		*ppHead = pNode;
	}
	else
	{
		//存在  让当前尾节点的下一个指向新来的节点  更新尾节点
		(*ppEnd)->pNext = pNode;
	}
	*ppEnd = pNode;
	
	return;
}

void InsertNode(Node **ppHead,Node **ppEnd,Node *pNode,int id)
{
	//1.头插入
	Node* pMark = *ppHead;
	if((*ppHead)->id == id)
	{
		pNode->pNext = *ppHead;//要插入的节点的下一个指向头
		*ppHead = pNode;//头指向插入的节点
		return ;
	}
//2.中间插入  标记停在要插入位置的前一个节点
	while(pMark->pNext != NULL)
	{
		if(pMark->pNext->id == id)
		{	
			pNode->pNext = pMark->pNext;	//要插入节点的下一个指向标记下一个
			pMark->pNext = pNode;			//标记的下一个指向要插入的节点
		
			return;
		}
		pMark = pMark->pNext;
	}
	//3.尾添加
	(*ppEnd)->pNext = pNode;
	*ppEnd = pNode;
		
	return;
}
void DelNode(Node **ppHead,Node ** ppEnd,int id)
{
	Node *pMark = *ppHead;
	Node *pDel = NULL;
	if((*ppHead)->id == id)
	{
		pDel = *ppHead;
		*ppHead = (*ppHead)->pNext;
		free(pDel);
		pDel = NULL;
		return;
	}
	while(pMark->pNext != NULL)
	{
		if(pMark->pNext->id ==id)
		{
			pDel = pMark->pNext;
			pMark->pNext = pDel->pNext;
			free(pDel);
			pDel = NULL;
		
		if(pMark->pNext == NULL)
			*ppEnd = pMark;
		return;
		}
		pMark = pMark->pNext;
	}
}