
//LISTA DE ALUNOS
typedef struct{
	char aluno[50];
	int matricula;
} TItem;

typedef struct celula{
	struct celula *pProx;
	TItem item;
} TCelula;

typedef struct{
	TCelula *pCabeca, *pUltimo;
	int Tamanho;
} TLista;

TLista* TLista_Cria(void);
int TLista_EhVazia(TLista *pLista);
int TLista_InserePrimeiro(TLista *pLista, TItem x);
int TLista_InserePosicao(TLista *pLista, TItem x , int pos);
int TLista_InsereUltimo(TLista *pLista, TItem x);
int TLista_RetiraPrimeiro(TLista *pLista);
int TLista_RetiraPosicao(TLista *pLista, int pos);
int TLista_RetiraUltimo(TLista *pLista);
int TLista_BuscaMatricula(TLista *pLista, int matricula);
void TLista_Imprime( TLista *pLista);

////////////////////////////////////////////////LISTA DE LIVROS////////////////////////////////////////////////////////////////////////

typedef struct{
	char autor[50];
	char nome_livro[50];
	int codigo;
} TItemL;

typedef struct celulaL{
	struct celulaL *pProxL;
	TItemL itemL;
} TCelulaL;

typedef struct{
	TCelulaL *pCabecaL, *pUltimoL;
	int TamanhoL;
} TListaL;

TListaL* TLista_CriaL(void);
int TLista_EhVaziaL(TListaL *pListaL);
int TLista_InserePrimeiroL(TListaL *pListaL, TItemL x);
int TLista_InserePosicaoL(TListaL *pListaL, TItemL x , int pos);
int TLista_InsereUltimoL(TListaL *pListaL, TItemL x);
int TLista_RetiraPrimeiroL(TListaL *pListaL);
int TLista_RetiraPosicaoL(TListaL *pListaL, int pos);
int TLista_RetiraUltimoL(TListaL *pListaL);
int TLista_BuscaMatriculaL(TListaL *pListaL, int codigo);
void TLista_ImprimeL( TListaL *pListaL);



///////////////////////////////EMPRÉSTIMOS DE LIVROS////////////////////////
typedef struct{
	char data[50];
	int matricula_aluno;
	int codigo_livro;
	
} TItemE;

typedef struct celulaE{
	struct celulaE *pProxE;
	TItemE itemE;
} TCelulaE;

typedef struct{
	TCelulaE *pCabecaE, *pUltimoE;
	int TamanhoE;
} TListaE;

TListaE* TLista_CriaE(void);
int TLista_EhVaziaE(TListaE *pListaE);
int TLista_InserePrimeiroE(TListaE *pListaE, TItemE x);
int TLista_InserePosicaoE(TListaE *pListaE, TItemE x , int pos);
int TLista_InsereUltimoE(TListaE *pListaE, TItemE x);
int TLista_RetiraPrimeiroE(TListaE *pListaE);
int TLista_RetiraPosicaoE(TListaE *pListaE, int pos);
int TLista_RetiraUltimoE(TListaE *pListaE);
int TLista_BuscaMatriculaE(TListaE *pListaE, int matricula_aluno);
void TLista_ImprimeE( TListaE *pListaE);

























