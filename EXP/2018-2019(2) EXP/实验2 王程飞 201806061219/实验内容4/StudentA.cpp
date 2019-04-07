#include "StudentA.h"

StudentA::StudentA(){
   name[0]='\0';
}

StudentA::StudentA(char *n)
{
	int i;
    for( i=0;n[i]!='\0';i++){
		name[i]=n[i];
	} 

	name[i]='\0';
}

char* StudentA::getName()
{
   return name;
}

void StudentA::changeName(char *n)
{
    int i;
    for(i=0;n[i]!='\0';i++){
		name[i]=n[i];
	}
    name[i]='\0';
}
