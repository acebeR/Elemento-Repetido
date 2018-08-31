#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/* 	Aluna: Rebeca
	Objetivo:Receba do usuário uma quantidade indefinida de números entre 0 e 9 e pare assim que ele repetir um número. 
	Depois apresente esse número e encerre o programa. */
	
//--------------------------- 
void apresentaNumero(char *numero,int qtdNumero);
int numeroRepetido(char *numeros, int qtdNumero);
void lerDoUsuario(char *numeros,char *msgTitulo,char *msgErro);
void lerValidaCaracter(char *msgTitulo,char *msgErro,char *caracter,char *opcoes);

//----------------------------

int main(int argc, char *argv[]) {
	
	char *numeros; 
	int repete = 0;
	int i = 0;
	char numeroAuxiliar;
	
	numeros = (char *) malloc(sizeof(char));  
	if(!numeros){
		printf("Não foi possivel alocar Memoria");
	}else{
		
		while(repete != 1){
		
			repete = numeroRepetido(numeros, i);
			if(repete != 1){
				
				lerDoUsuario(&numeroAuxiliar,"Digite um numero de 0-9: ","Numero invalido");
				printf("%c\n",numeroAuxiliar);//Para mostrar o numero que o usuário acaba de digitar
				
				numeros[i] = numeroAuxiliar; //Armazena o numero
				
				i++;
				numeros = (char*) realloc (numeros, i * sizeof(char)); 

			}
		
		}
	}

	
	apresentaNumero(numeros,i);
	free(numeros);
	
	
	
	return 0;
}


//-------------------- Funções ------------------

void apresentaNumero(char *numero,int qtdNumero){
	int i;
		printf("\n\n\n\t______Obrigada!!_____ \n");
		printf("\tNumero Digitado: ");
	for(i=0; i<qtdNumero; i++){
		printf("%c", numero[i]);
	}
}

int numeroRepetido(char *numeros, int qtdNumero){
	int i,j;
	for(i = 0;i < qtdNumero; i++){
		for(j = i+1; j < qtdNumero; j++){
			if(numeros[i] == numeros[j]){
				return 1;
			}
		}
	}
	return 0;
}

void lerDoUsuario(char *numeros,char *msgTitulo,char *msgErro){
	lerValidaCaracter(msgTitulo,msgErro,numeros,"0123456789");	
	
}

void lerValidaCaracter(char *msgTitulo,char *msgErro,char *caracter,char *opcoes)
{
	do
	{
		printf(msgTitulo);
		(*caracter) = toupper(getch());
		if(strchr(opcoes,*caracter) == 0)
		{
			printf(msgErro);
			getch();
			system("cls");
		}
	}while(strchr(opcoes,*caracter) == 0);
}
