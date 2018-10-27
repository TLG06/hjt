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
	//1.�ж������Ƿ���ڽڵ�
	if(*ppHead == NULL)
	{
		//������  ��ͷָ��ָ�������Ľڵ�  ����β�ڵ�
		*ppHead = pNode;
	}
	else
	{
		//����  �õ�ǰβ�ڵ����һ��ָ�������Ľڵ�  ����β�ڵ�
		(*ppEnd)->pNext = pNode;
	}
	*ppEnd = pNode;
	
	return;
}

void InsertNode(Node **ppHead,Node **ppEnd,Node *pNode,int id)
{
	//1.ͷ����
	Node* pMark = *ppHead;
	if((*ppHead)->id == id)
	{
		pNode->pNext = *ppHead;//Ҫ����Ľڵ����һ��ָ��ͷ
		*ppHead = pNode;//ͷָ�����Ľڵ�
		return ;
	}
//2.�м����  ���ͣ��Ҫ����λ�õ�ǰһ���ڵ�
	while(pMark->pNext != NULL)
	{
		if(pMark->pNext->id == id)
		{	
			pNode->pNext = pMark->pNext;	//Ҫ����ڵ����һ��ָ������һ��
			pMark->pNext = pNode;			//��ǵ���һ��ָ��Ҫ����Ľڵ�
		
			return;
		}
		pMark = pMark->pNext;
	}
	//3.β���
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