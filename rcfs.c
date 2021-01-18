#include <stdio.h>

#define NAJDUZA_REC 50

int main()
{

	FILE * fp = fopen("ulaz.txt","r");
	if(fp == NULL)
	{
		fprint("Ne mogu da otvorim ulazni fajl. Kraj rada.");
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

	for(int i=0; i<6;i++)
	{
		fgets(rec,NAJDUZA_REC,fp)
		if(feof(fp))
			break;
		
	}	
	
	fclose(fp);
	return 0;


}