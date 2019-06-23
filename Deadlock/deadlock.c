#include<stdio.h>
static int isvisited[9];
int i,j,np,nr;

int canprocess(int x[], int y[], int z[], int avail[])
{
	for(j=0; j<nr; j++)
	{
	if(x[j]>avail[j])
		return 0;
	}

	for(j=0; j<nr; j++)
	{
		avail[j] += y[j];
		y[j] = z[j] = 0;
	}

	return 1;
}

int safe(int request[3][3], int avail[3], int alloc[3][3], int claim[3][3])
{
	int count = 0;
	printf("\n State Sequence: ");
	while(count < np)
	{
		for(i=0; i < np; i++)
		{
			if((isvisited[i] == 0) && canprocess(request[i], alloc[i], claim[i], avail))
			{
				count++;
				isvisited[i] = 1;
				printf("P%d\t", i+1);
				break;
			}
		}
		if(i == np)
		return 0;
	}
	return 1;
}

int main()
{
	int alloc[3][3], claim[3][3], request[3][3], avail[3],r[3];

	printf("\nEnter # of processes: ");
	scanf("%d", &np);
	
	
	printf("Enter the # of resources: ");
	scanf("%d", &nr);
	
	for(i=0; i < nr; i++)
	{
		printf("\nTotal Amount of Resource R%d: " , i+1);
		scanf("%d", &r[i]);
	}
	
	printf("\nEnter the allocation matrix:");

	for(i=0; i < np; i++)
		for(j=0; j < nr; j++)
			scanf("%d",&alloc[i][j]);
	
	printf("\nEnter the claim matrix:");

	for(i=0; i < np; i++)
		for(j=0; j < nr; j++)
			scanf("%d",&claim[i][j]);

	for(i=0; i < np; i++)
		for(j=0; j < nr; j++)
			request[i][j] = claim[i][j]-alloc[i][j];

	for(j=0; j < nr; j++)
	{
		avail[j] = r[j];
		for(i = 0; i < np; i++)
		{
			avail[j]-=alloc[i][j];
		}
	}
	
	if(safe(request,avail,alloc,claim))
		printf("\n System is safe ");
	else
		printf("\n Unsafe ");

	return 0;
}
