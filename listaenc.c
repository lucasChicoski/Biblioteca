////ARQUIVO listaenc.c:

#include <stdio.h>
#include <stdlib.h>
#include "listaenc.h"
//#////#////#////#////#////#////#////#////#////#//ALUNO//#////#////#////#////#////#////#////#////#////#////#////#////#////#////#//
/* Inicia as variáveis da lista */
TLista* TLista_Cria(void) {
	TLista *pLista= (TLista*) malloc(sizeof(TLista));
	pLista->pCabeca=(TCelula*) malloc(sizeof(TCelula));
	pLista->pUltimo= pLista->pCabeca;
	pLista->pCabeca->pProx= NULL ;
	pLista->Tamanho = 0;
	return pLista;
}

/* Retorna se a lista é vazia */
int TLista_EhVazia(TLista*pLista) {
	return(pLista->pCabeca== pLista->pUltimo);
}

/* Insere um item no final da lista */
int TLista_InsereUltimo(TLista *pLista, TItem x) {
	pLista->pUltimo->pProx= (TCelula*) malloc(sizeof(TCelula));
	pLista->pUltimo= pLista->pUltimo->pProx;
	pLista->pUltimo->item = x;
	pLista->pUltimo->pProx= NULL ;
	pLista->Tamanho++;
}

int TLista_InserePrimeiro(TLista *pLista, TItem x) {
	TCelula *pAux = (TCelula*) malloc(sizeof(TCelula));
	pAux->item = x;
	pAux->pProx = pLista->pCabeca->pProx;
	pLista->pCabeca->pProx = pAux;
	pLista->Tamanho++;
}

int TLista_InserePosicao(TLista *pLista, TItem x , int pos) {
	if (pos >= pLista->Tamanho+1) {
		TLista_InsereUltimo(pLista,x);
		return 1;
	}
	TCelula *pAux = (TCelula*) malloc(sizeof(TCelula));
	pAux->item = x;
	TCelula *Elemento = pLista->pCabeca;
	int n = 0;
	while (Elemento != NULL && n < pos-1) {
		Elemento = Elemento->pProx;
		n++;
	}
	pAux->pProx = Elemento->pProx;
	Elemento->pProx = pAux;
	pLista->Tamanho++;
}

int TLista_RetiraPrimeiro (TLista *pLista) {
	if (TLista_EhVazia(pLista))
		return 0;
	TCelula *pAux;
	pAux = pLista->pCabeca->pProx ;
	pLista->pCabeca->pProx = pAux->pProx ;
	free(pAux);
	pLista->Tamanho--;
	if (pLista->Tamanho == 0) {
        pLista->pUltimo = pLista->pCabeca;
	}
	return 1;
}

int TLista_RetiraUltimo(TLista *pLista) {
	if (TLista_EhVazia(pLista))
		return 0;
	TCelula *Aux = pLista->pCabeca;
	int pos = 0;
	while(pos < pLista->Tamanho-1) {
		Aux = Aux->pProx;
		pos++;
	}
	free(pLista->pUltimo);
	Aux->pProx = NULL;
	pLista->pUltimo = Aux;
	pLista->Tamanho--;
	if (pLista->Tamanho == 0) {
        pLista->pUltimo = pLista->pCabeca;
	}
	return 1;
}

int TLista_RetiraPosicao(TLista *pLista, int pos){
	if (TLista_EhVazia(pLista))
		return 0;
	if (pos<=1) {
		TLista_RetiraPrimeiro(pLista);
		return 1;
	}
	if (pos>=pLista->Tamanho){
		TLista_RetiraUltimo(pLista);
		return 1;
	}
	TCelula *Aux = pLista->pCabeca;
	int n = 0;
	while(n < pos-1){
		Aux = Aux->pProx;
		n++;
	}
	TCelula *Elemento = Aux->pProx;
	Aux->pProx = Elemento->pProx;
	free(Elemento);
	pLista->Tamanho--;
	if (pLista->Tamanho == 0) {
        pLista->pUltimo = pLista->pCabeca;
	}
	return 1;	
}

int TLista_BuscaMatricula(TLista *pLista, int matricula){
	TCelula *Elemento = pLista->pCabeca->pProx;
	int pos = 1;
	while(Elemento!=NULL) {
		if (Elemento->item.matricula == matricula) {
			return pos;
		}
		Elemento = Elemento->pProx;
		pos++;
	}
	return 0;
}

void TLista_Imprime (TLista *pLista) {
	TCelula *Elemento;
	Elemento = pLista->pCabeca->pProx ;
	while (Elemento != NULL) {
		printf (" ---- MATRICULA DO ALUNO: %d ---- NOME DO ALUNO: %s\n\n\n", Elemento->item.matricula, Elemento->item.aluno);
		Elemento = Elemento->pProx;
	}
	printf("\n");

}
 // LIVRO//
 
 TListaL* TLista_CriaL(void){
 	TListaL *pListaL= (TListaL*) malloc(sizeof(TListaL));
	pListaL->pCabecaL=(TCelulaL*) malloc(sizeof(TCelulaL));
	pListaL->pUltimoL= pListaL->pCabecaL;
	pListaL->pCabecaL->pProxL= NULL ;
	pListaL->TamanhoL = 0;
	return pListaL;
 }
 
 int TLista_EhVaziaL(TListaL*pListaL) {
	return(pListaL->pCabecaL== pListaL->pUltimoL);
}
 
int TLista_InsereUltimoL(TListaL *pListaL, TItemL x){
	
	pListaL->pUltimoL->pProxL= (TCelulaL*) malloc(sizeof(TCelulaL));
	pListaL->pUltimoL= pListaL->pUltimoL->pProxL;
	pListaL->pUltimoL->itemL = x;
	pListaL->pUltimoL->pProxL= NULL ;
	pListaL->TamanhoL++;
}

int TLista_InserePrimeiroL(TListaL *pListaL, TItemL x) {
	TCelulaL *pAux = (TCelulaL*) malloc(sizeof(TCelulaL));
	pAux->itemL = x;
	pAux->pProxL = pListaL->pCabecaL->pProxL;
	pListaL->pCabecaL->pProxL = pAux;
	pListaL->TamanhoL++;
}

int TLista_InserePosicaoL(TListaL *pListaL, TItemL x , int pos) {
	if (pos >= pListaL->TamanhoL+1) {
		TLista_InsereUltimoL(pListaL,x);
		return 1;
	}
	TCelulaL *pAux = (TCelulaL*) malloc(sizeof(TCelulaL));
	pAux->itemL = x;
	TCelulaL *Elemento = pListaL->pCabecaL;
	int n = 0;
	while (Elemento != NULL && n < pos-1) {
		Elemento = Elemento->pProxL;
		n++;
	}
	pAux->pProxL = Elemento->pProxL;
	Elemento->pProxL = pAux;
	pListaL->TamanhoL++;
}

void TLista_ImprimeL( TListaL *pListaL){
		TCelulaL *Elemento;
	Elemento = pListaL->pCabecaL->pProxL ;
	while (Elemento != NULL) {
		printf (" ---- CÓDIGO DO LIVRO: %d\n ---- NOME DO AUTOR: %s\n ---- NOME DO LIVRO: %s\n\n\n", Elemento->itemL.codigo, Elemento->itemL.autor,Elemento->itemL.nome_livro);
		Elemento = Elemento->pProxL;
	}
	printf("\n");
}



int TLista_RetiraPrimeiroL(TListaL *pListaL){
	if (TLista_EhVaziaL(pListaL))
		return 0;
	TCelulaL *pAux;
	pAux = pListaL->pCabecaL->pProxL ;
	pListaL->pCabecaL->pProxL = pAux->pProxL ;
	free(pAux);
	pListaL->TamanhoL--;
	if (pListaL->TamanhoL == 0) {
        pListaL->pUltimoL = pListaL->pCabecaL;
	}
	return 1;
}
 
int TLista_RetiraUltimoL(TListaL *pListaL){
		if (TLista_EhVaziaL(pListaL))
		return 0;
	TCelulaL *Aux = pListaL->pCabecaL;
	int pos = 0;
	while(pos < pListaL->TamanhoL-1) {
		Aux = Aux->pProxL;
		pos++;
	}
	free(pListaL->pUltimoL);
	Aux->pProxL = NULL;
	pListaL->pUltimoL = Aux;
	pListaL->TamanhoL--;
	if (pListaL->TamanhoL == 0) {
        pListaL->pUltimoL = pListaL->pCabecaL;
	}
	return 1;
}


int TLista_RetiraPosicaoL(TListaL *pListaL, int pos){
	if (TLista_EhVaziaL(pListaL))
		return 0;
	if (pos<=1) {
		TLista_RetiraPrimeiroL(pListaL);
		return 1;
	}
	if (pos>=pListaL->TamanhoL){
		TLista_RetiraUltimoL(pListaL);
		return 1;
	}
	TCelulaL *Aux = pListaL->pCabecaL;
	int n = 0;
	while(n < pos-1){
		Aux = Aux->pProxL;
		n++;
	}
	TCelulaL *ElementoL = Aux->pProxL;
	Aux->pProxL = ElementoL->pProxL;
	free(ElementoL);
	pListaL->TamanhoL--;
	if (pListaL->TamanhoL == 0) {
        pListaL->pUltimoL = pListaL->pCabecaL;
	}
	return 1;	

}

int TLista_BuscaMatriculaL(TListaL *pListaL, int codigo){
	TCelulaL *Elemento = pListaL->pCabecaL->pProxL;
	int pos = 1;
	while(Elemento!=NULL) {
		if (Elemento->itemL.codigo == codigo) {
			return pos;
		}
		Elemento = Elemento->pProxL;
		pos++;
		
	}
	return 0;
}

//////////////////////////////////////////EMPRÉSTIMOS DE LIVROS/////////////////////////

TListaE* TLista_CriaE(void) {
	TListaE *pListaE= (TListaE*) malloc(sizeof(TListaE));
	pListaE->pCabecaE=(TCelulaE*) malloc(sizeof(TCelulaE));
	pListaE->pUltimoE= pListaE->pCabecaE;
	pListaE->pCabecaE->pProxE= NULL ;
	pListaE->TamanhoE = 0;
	return pListaE;
}

/* Retorna se a lista é vazia */
int TLista_EhVaziaE(TListaE*pListaE) {
	return(pListaE->pCabecaE== pListaE->pUltimoE);
}

/* Insere um item no final da lista */
int TLista_InsereUltimoE(TListaE *pListaE, TItemE x) {
	pListaE->pUltimoE->pProxE= (TCelulaE*) malloc(sizeof(TCelulaE));
	pListaE->pUltimoE= pListaE->pUltimoE->pProxE;
	pListaE->pUltimoE->itemE = x;
	pListaE->pUltimoE->pProxE= NULL ;
	pListaE->TamanhoE++;
}

int TLista_InserePrimeiroE(TListaE *pListaE, TItemE x) {
	TCelulaE *pAux = (TCelulaE*) malloc(sizeof(TCelulaE));
	pAux->itemE = x;
	pAux->pProxE = pListaE->pCabecaE->pProxE;
	pListaE->pCabecaE->pProxE = pAux;
	pListaE->TamanhoE++;
}

int TLista_InserePosicaoE(TListaE *pListaE, TItemE x , int pos) {
	if (pos >= pListaE->TamanhoE+1) {
		TLista_InsereUltimoE(pListaE,x);
		return 1;
	}
	TCelulaE *pAux = (TCelulaE*) malloc(sizeof(TCelulaE));
	pAux->itemE = x;
	TCelulaE *Elemento = pListaE->pCabecaE;
	int n = 0;
	while (Elemento != NULL && n < pos-1) {
		Elemento = Elemento->pProxE;
		n++;
	}
	pAux->pProxE = Elemento->pProxE;
	Elemento->pProxE = pAux;
	pListaE->TamanhoE++;
}

int TLista_RetiraPrimeiroE (TListaE *pListaE) {
	if (TLista_EhVaziaE(pListaE))
		return 0;
	TCelulaE *pAux;
	pAux = pListaE->pCabecaE->pProxE ;
	pListaE->pCabecaE->pProxE = pAux->pProxE ;
	free(pAux);
	pListaE->TamanhoE--;
	if (pListaE->TamanhoE == 0) {
        pListaE->pUltimoE = pListaE->pCabecaE;
	}
	return 1;
}

int TLista_RetiraUltimoE(TListaE *pListaE) {
	if (TLista_EhVaziaE(pListaE))
		return 0;
	TCelulaE *Aux = pListaE->pCabecaE;
	int pos = 0;
	while(pos < pListaE->TamanhoE-1) {
		Aux = Aux->pProxE;
		pos++;
	}
	free(pListaE->pUltimoE);
	Aux->pProxE = NULL;
	pListaE->pUltimoE = Aux;
	pListaE->TamanhoE--;
	if (pListaE->TamanhoE == 0) {
        pListaE->pUltimoE = pListaE->pCabecaE;
	}
	return 1;
}

int TLista_RetiraPosicaoE(TListaE *pListaE, int pos){
	if (TLista_EhVaziaE(pListaE))
		return 0;
	if (pos<=1) {
		TLista_RetiraPrimeiroE(pListaE);
		return 1;
	}
	if (pos>=pListaE->TamanhoE){
		TLista_RetiraUltimoE(pListaE);
		return 1;
	}
	TCelulaE *Aux = pListaE->pCabecaE;
	int n = 0;
	while(n < pos-1){
		Aux = Aux->pProxE;
		n++;
	}
	TCelulaE *Elemento = Aux->pProxE;
	Aux->pProxE = Elemento->pProxE;
	free(Elemento);
	pListaE->TamanhoE--;
	if (pListaE->TamanhoE == 0) {
        pListaE->pUltimoE = pListaE->pCabecaE;
	}
	return 1;	
}

int TLista_BuscaMatriculaE(TListaE *pListaE, int matricula_aluno){
	TCelulaE *Elemento = pListaE->pCabecaE->pProxE;
	int pos = 1;
	while(Elemento!=NULL) {
		
		if (Elemento->itemE.matricula_aluno == matricula_aluno) {
			return pos;
		}
		Elemento = Elemento->pProxE;
		pos++;
	}
	return 0;
}

void TLista_ImprimeE (TListaE *pListaE) {
	TCelulaE *Elemento;
	Elemento = pListaE->pCabecaE->pProxE ;
	while (Elemento != NULL) {
		printf (" ---- CODIGO DO LIVRO: %d\n ----  MATRICULA DO ALUNO: %d\n ----  DATA DE DEVOLUÇÃO: %s\n\n\n",Elemento->itemE.codigo_livro,Elemento->itemE.matricula_aluno,Elemento->itemE.data);
		Elemento = Elemento->pProxE;
	}
	printf("\n");
}


