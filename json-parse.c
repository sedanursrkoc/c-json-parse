#include<stdio.h>
#include <regex.h>  
#include <string.h>      
#include <stdlib.h>

char line[100];


typedef struct {
  int kelimeSayisi;
  int sayacKelime;
  int sayacKey;
  char kelime[500][500];
  char  key[500][500];
} giris;

int oku(giris* dizi) {


	int sayac = 0;
	dizi->sayacKelime = 0;
	dizi->sayacKey = 0;


	FILE *file = fopen("json-string.txt", "r");
	if(!file) {
	    printf("Could not open file. Exiting application. Bye");

	}
	while(fscanf(file, "%s", line) != EOF) {
	    fscanf(file,"%[^ \n\t\r]s",line); //Get text
	    char * token = strtok(line, "\"");
	 
            if(sayac % 2 == 0 && (!strstr(line, "{") && !strstr(line, "}"))){
		strcpy(dizi->key[dizi->sayacKey], token); 
		dizi->sayacKey = dizi->sayacKey + 1;
	    }
	    else if(!strstr(line, "{") && !strstr(line, "}")){
		strcpy(dizi->kelime[dizi->sayacKelime], token); 
		dizi->sayacKelime = dizi->sayacKelime + 1;
	    }
	    else 
		// do nothing

	dizi->kelimeSayisi = sayac;
	sayac = sayac + 1;
	    
	}

	return 1;


}


int main()
{
	giris* dizi;
	dizi = (giris *)malloc(sizeof(giris));
	oku(dizi);
	for(int j =0; j < dizi->kelimeSayisi/2; j++ ){
		printf("kelime: %s\t",dizi->kelime[j]);
		printf("key: %s\n",dizi->key[j]);}
}
