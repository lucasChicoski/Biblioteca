#include <locale.h>
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include "listaenc.h"
#include <conio.c>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	setlocale(LC_ALL, "portuguese");

	//ALUNO
	TLista *lista;
	TItem nm;
	int posicao;
	lista = TLista_Cria();
	
	//LIVRO
	TListaL *listaL;
	TItemL LV;
	int posicaoL;
	listaL = TLista_CriaL();
	
	//EMPRÉSTIMO
	TListaE *listaE;
	TItemE EM;
	int posicaoE;
	listaE = TLista_CriaE();

	int p;
	
	int i,s;
	
	
do {
	
	int x,y;
	void gotoxy( int x, int y )
{

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(COORD){x,y
	});
}
	textcolor(GREEN);
	printf("\n\t\t\tDIGITE UMA OPÇÃO\n\n");
	//linha superior horizontal
	textcolor(RED);
	printf("\n\n   Opção 1: Inserir nome de aluno.\n   Opção 2: Remover nome de aluno.\n   Opção 3: imprimir lista de alunos.\n   Opção 4: adicionar livro à lista.\n   Opção 5: retirar livro da lista.\n   Opção 6: imprimir lista de livros.\n   Opção 7: Realizar empréstimo.\n   Opção 8: Imprimir lista de empréstimos.\n   Opção 9: Efetuar devolução de livro.\n\n\n");
	printf("\t\t OPçÂO:");
	
	//linha vertical esquerda
	for(x=4;x<16;x++){
		textcolor(YELLOW);
	gotoxy(0,x);
    printf("%c",180);
	}
	
	//linha horizontal superior
    for (x=0;x<50;x++){
    	gotoxy(x,4);
    printf("%c",180);
	}
	//linha horizontal inferior
	for (x=0;x<50;x++){
    	gotoxy(x,15);
    printf("%c",180);
	}
	
	for (x=4;x<16;x++){
    	gotoxy(50,x);
    printf("%c",180);
	}
	
		gotoxy(23,16);
     
	scanf("\t%d",&p);
	
	switch (p)
	{
		
		case 1 : // adicionar aluno
			
				printf("\n\tDIGITE A QUANTIDADE DE ALUNOS:\t");
				scanf("%d",&s);
				
				for(i=0;i<s;i++)
		{
			printf("\n\tDIGITE O NOME DO ALUNO:");
			fflush(stdin);
			gets(nm.aluno);
			printf("\n\tDIGITE A MATRICULA DO ALUNO:");
			scanf("%d",&nm.matricula);
			TLista_InsereUltimo(lista,nm);
			
		}
		system ("cls");
			
			break ;
		
		case 2 : // retirar aluno
		
			TLista_Imprime(lista);
			printf("\n Tamanho da Lista: %d", lista->Tamanho);
			int mat;
			printf("\n\n DIGITE A MATRICULA PARA RETIRAR UMA MATRICULA: ");
			scanf("%d", &mat);
			posicao = TLista_BuscaMatricula(lista,mat);
			if(posicao!=0){
			TLista_RetiraPosicao(lista,posicao);
		
			}
			else{
				printf("\n\nNão existe aluno com essa matricula");
			}
				printf("\n\n");
			//	TLista_RetiraPosicao(lista,posicao);
				TLista_Imprime(lista);
				printf("Tamanho da lista: %d", lista->Tamanho);
				printf("\n------------------------");
	
	
				
				if (TLista_EhVazia(lista))
					{
						printf("\n Lista vazia");
					} 
				else
					{
						printf("\n Lista na1 vazia");
					}
				
				system ("cls");
						
						break;
		
		case 3 : // imprimir lista de alunos
			printf("\n");
			TLista_Imprime(lista);
				if (TLista_EhVazia(lista))
					{
						printf("\n Lista vazia\n");
					} 
			system("pause");
			system("cls");
			break ;
		
		case 4 : // adicionar livro
			
		printf("\nDIGITE A QUANTIDADE DE LIVROS PARA SER ADICIONADAS NA LISTA DE LIVROS:");
		scanf("%d",&s);
		printf("\nDIGITE AS INFORMAÇÕES DOS LIVROS:\n");
		
		
		
		for (i=0;i<s;i++){
			
			printf("NOME DO LIVRO:");
			fflush(stdin);
			gets(LV.nome_livro);
			printf("NOME DO AUTOR:");
			gets(LV.autor);
			printf("CÓDIGO DO LIVRO:");
			fflush(stdin);
			scanf("%d",&LV.codigo);
			TLista_InsereUltimoL(listaL,LV);
		}
		 system("cls");
         break;
        
        case 6 :  //imprir lista de livros
        
        TLista_ImprimeL(listaL);
        	if (TLista_EhVaziaL(listaL))
					{
						printf("\n Lista vazia\n");
					} 
        system("pause");
		system("cls");
        break;
	
	   case 5 : // retirar livro
	   		TLista_ImprimeL(listaL);
			printf("\n Tamanho da Lista: %d", listaL->TamanhoL);
			int matL;
			printf("\n\n DIGITE O CÓDIGO PARA RETIRAR O LIVRO DA LISTA: ");
			scanf("%d", &matL);
			posicaoL = TLista_BuscaMatriculaL(listaL,matL);
			if(posicaoL!=0){
			TLista_RetiraPosicaoL(listaL,posicaoL);
		
			}
			else{
				printf("\n\nNão existe livro com este código");
			}
				printf("\n\n");
				TLista_ImprimeL(listaL);
				printf("Tamanho da lista: %d", listaL->TamanhoL);
				printf("\n------------------------");
	
	
				
				if (TLista_EhVaziaL(listaL))
					{
						printf("\n Lista vazia");
					} 
				else
					{
						printf("\n Lista na1 vazia");
					}
				
				system ("cls");
						
				
						
				break;
			
			case 7 : //REALIZAR EMPRESTIMO
		
			printf("DIGITE A MATRICULA DO ALUNO:\n");
			scanf("%d",&EM.matricula_aluno);
			TLista_BuscaMatricula(lista,mat);
			if(EM.matricula_aluno == nm.matricula){
				
				printf("aluno valido:\n\n");
			}
			
			else {
				printf("aluno invalido\n");
				system("pause");
				system("cls");
				break ;
				
			}
			
			printf("DIGITE O CÓDIGO DO LIVRO:\n");
			scanf("%d",&EM.codigo_livro);
			TLista_BuscaMatriculaL(listaL,matL);
			if(EM.codigo_livro == LV.codigo){
				printf("lviro valido\n\n");
			}
			
			else {
				
				printf("livro não existe:\n");
				break ; 
			}
			
			
			printf("DIGITE A DATA DE DEVOLUÇÃO:\n");
			fflush(stdin);
			gets(EM.data);
			TLista_InsereUltimoE(listaE,EM);
			
			printf("RESERVA EFETUADA COM SUCESSO!");
			
			system("cls");		
				break ;
				
			case 8 :
				
		TLista_ImprimeE(listaE);
			if (TLista_EhVaziaE(listaE))
					{
						printf("\n Lista vazia\n");
					} 
        system("pause");
		system("cls");
				break ;
				
			case 9 :
				
			TLista_ImprimeE(listaE);
			if (TLista_EhVaziaE(listaE))
					{
						printf("\n Lista vazia\n");
						system("pause");
						system("cls");
						break ;
					} 
			printf("\n Tamanho da Lista: %d", listaE->TamanhoE);
			int matE;
			printf("DIGITE O CÓDIGO:");
			scanf("%d", &matE);
			printf("\n\n DIGITE A MATRICULA: ");
			scanf("%d", &matE);
			posicao = TLista_BuscaMatriculaE(listaE,matE);
			if(posicao!=0){
			TLista_RetiraPosicaoE(listaE,posicaoE);
		
			}
			else{
				printf("\n\nNão existe aluno com essa matricula");
			}
				printf("\n\n");
			
				TLista_ImprimeE(listaE);
				printf("Tamanho da lista: %d\n", lista->Tamanho);
				printf("\n------------------------");
	
			    printf("DEVOLUÇÃO FEITA COM SUCESSO!\n");
			    system("pause");
			    system("cls");
			/*	
				if (TLista_EhVaziaE(listaE))
					{
						printf("\n Lista vazia");
						break ;
					} 
				else
					{
						printf("\n Lista na1 vazia");
					}
				
				system ("cls");
				*/
				break ;
		
	 }
	
}	
	while (p!=0);
	

	
	return 0;
}
