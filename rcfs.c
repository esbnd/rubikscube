#include <stdio.h>

#define NAJDUZA_REC 50

typedef unsigned char byte;

char* recnik[] = { "napred", "desno", "gore", "pozadi", "levo", "ispod", 
					"crvena", "bela", "plava", "narandzasta", "zuta", "zelena" };

/* sema slaganja strana u tablicu 6x9
	0 napred
	1 desno
	2 gore
	3 pozadi
	4 levo
	5 ispod
*/

int ucitaj_kocku(char* ime_fajla, byte niz[6][9])
{
	FILE * fp = fopen(ime_fajla,"r");
	if(fp == NULL)
	{
		printf("Ne mogu da otvorim ulazni fajl. Kraj rada.");
		return -1;
	}

	char rec[NAJDUZA_REC];
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

		if(rec[0] == '/' && rec[1] == '/') //komentar
		{
			while(c != '\n')
				c=fgetc(fp);
			continue; //pocni ponovo novu rec ispocetka
		}
	
		for(k=0;k<12;k++)
			if(stricmp(rec,recnik[k]) == 0) break;
		
		if(k == 12)
		{
			printf("Naisao sam na rec koje nema u recniku: %s",rec);
			printf("\nRecnik je:");
			for(j=0;j<12;j++)
				printf("\n%s ",recnik[j]);
			fclose(fp);
			return -2;
		}
	
		if(k<6)
		{
			tekuca_strana=k;
			tekuce_polje_u_strani=0;
			i++;
		}
		else
			niz[tekuca_strana][tekuce_polje_u_strani++]=k;

	}while(i <= 6);

	fclose(fp);
	return 0;
}

int main()
{

	int i,j;
	byte ulaz[6][9],izlaz[6][9];

	ucitaj_kocku("ulaz.txt",ulaz);
	ucitaj_kocku("izlaz.txt",izlaz);

	printf("\n\n\nUlaz:");
	for(i=0;i<6;i++)
	{
		printf("\n");
		for(j=0;j<9;j++)
		{
			if((j % 3) == 0)
				printf("\n");

			printf("%d ",ulaz[i][j]);
		}
	}
	
	printf("\n\n\nIzlaz:");
	for(i=0;i<6;i++)
	{
		printf("\n");
		for(j=0;j<9;j++)
		{
			if((j % 3) == 0)
				printf("\n");

			printf("%d ",izlaz[i][j]);
		}
	}

	
	return 0;


}