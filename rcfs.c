#include <stdio.h>

#define NAJDUZA_REC 50

int main()
{

	FILE * fp = fopen("ulaz.txt","r");
	if(fp == NULL)
	{
		printf("Ne mogu da otvorim ulazni fajl. Kraj rada.");
		return -1;
	}

	/* sema slaganja strana u tablicu 6x9
	0 napred
	1 desno
	2 gore
	3 pozadi
	4 levo
	5 ispod
	*/
	int kocka[6][9], kockaStaro[6][9];
	char rec[NAJDUZA_REC];
	char* recnik[] = { "napred", "desno", "gore", "pozadi", "levo", "ispod", 
			"crvena", "bela", "plava", "narandzasta", "zuta", "zelena" };
	char c;
	int i=0,j,k;

	int tekuca_strana=0;
	int tekuce_polje_u_strani=0;
	c=fgetc(fp);
	do
	{
		/* skip spaces  */
		while(isspace(c) && !feof(fp))
			c=fgetc(fp);
		if(feof(fp))
			break;	
		
		/*read one word */
		for(j=0;!isspace(c) && j<NAJDUZA_REC && !feof(fp);j++)
		{
			rec[j] = c;
			c=fgetc(fp);	
		}
			
		rec[j]=0;

		printf("\nUcitano: \"%s\"",rec);
	
		for(k=0;k<12;k++)
			if(stricmp(rec,recnik[k]) == 0) break;
		
		if(k == 12)
		{
			printf("Naisao sam na rec koje nema u recniku: %s",rec);
			printf("\nRecnik je:");
			for(j=0;j<12;j++)
				printf("\n%s ",recnik[j]);
			return -2;
		}
	
		if(k<6)
		{
			tekuca_strana=k;
			tekuce_polje_u_strani=0;
			i++;
		}
		else
			kocka[tekuca_strana][tekuce_polje_u_strani++]=k;

	}while(i <= 6);

	for(i=0;i<6;i++)
	{
		printf("\n");
		for(j=0;j<9;j++)
		{
			if((j % 3) == 0)
				printf("\n");

			printf("%d ",kocka[i][j]);
		}
	}
	
	fclose(fp);
	return 0;


}