#include <stdio.h>
#include <malloc.h>

typedef struct Node
{
	int num;
	struct Node *next;
	
} JoseNode, *HNode;

int joseInit(HNode h)
{
	if(h == NULL) {	
		return -1;
	}

	h->next = h;
	return 0;
}

int joseInsert(HNode h, int pos, int x)
{
	HNode p = h;
	int i = 1;
	
	if(pos == 1) {
		p->num = x;
		p->next = p;
		return 0;
	}

	while(i < (pos - 1)) {
		p=p->next;
		i++;
	}

	JoseNode *q = (JoseNode *)malloc(sizeof(JoseNode));
	q->num = x;
	q->next = p->next;
	p->next = q;
	return 0;
}

int traverseList(HNode h)
{
	HNode p = h;

	printf("all the number of people:\n");
	while(p->next != h) {
		printf("%d ",p->num);
		p = p->next;
	}
	printf("%d ",p->num);//the last.
	return 0;
}

int joseDelete(HNode h, int n, int k)
{
	int i = 0;
	int j = 0;
	HNode p = h;
	HNode q;
	if(h == NULL)
		return -1;
	
	for (i = 0;i < n;i++)
	{
		for(j = 1;j<(k-1);j++)
		{
			p = p->next;
		}
		q = p->next;
		p->next = q->next;
		printf("out of game: #%d\n",q->num);
		
		free(q);
		p = p->next;
	}
	return 0;
}

int main(int argc, const char *argv[])
{
	int n,k,i;

	HNode h;
	h = (HNode)malloc(sizeof(JoseNode));
	if (h == NULL) {
		printf("malloc error!\n");
		return -1;
	}

	printf("Input how many people:\n");
	scanf("%d",&n);
	printf("Input out number:\n");
	scanf("%d",&k);
	
	joseInit(h);
	
	for(i = 1;i <= n;i++)
	{	
		joseInsert(h,i,i);
	}

	traverseList(h);

	if (k != 1) {
		joseDelete(h,n,k);//Core.
	}
	else {
		for(i = 1;i <= n;i++)
		{	
			printf("Out of game: #%d\n", i);
		}		
	}		
	return 0;
}

