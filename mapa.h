//Struct para cidade, tendo o nome, grau, e um ponteiro para Caminho;
typedef struct cidade
{
	char nome[50];
	int grau;
	struct caminho *vizinhos[10]; // Ponteiro para até 10 vizinhos;
}Cidade;

//Struct para caminho com ponteiro para struct cidade;
typedef struct caminho
{
	struct cidade *vizinho; //Ponteiro para vizinhos.
	int distancia;
}Caminho;

//================================================================================================================================================
//FUNÇÕES
int numCidades = 0; //Definido numero de cidades 0

// Funcao para criar as cidades.
void criarCidade(Cidade *lista[], char nome[]) //Recebe o vetor e o nome da cidade.
{
    Cidade *novo = (Cidade*) malloc(sizeof(Cidade)); //Aloca espaço
    strcpy(novo->nome, nome); //Copia o nome recebido para o novo->nome
    novo->grau = 0; //Define como 0 o grau da cidade inicialmente sem vizinhos;
    lista[numCidades] = novo; //A lista na posicao 0 inicialmente, recebe o novo com as informações;
    numCidades++; //incrementa o numero de cidades, logo a proxima inserção sera na posição 1;
}

//Insere as cidades padroes informadas no enunciado.
void insereEntrada(Cidade *lista[])
{
    criarCidade(lista, "Alegrete"); //Cada cidade inserida no vetor possui uma posicao, usada como chave.
    criarCidade(lista, "Bage"); //1 
    criarCidade(lista, "Cruz Alta"); //2
    criarCidade(lista, "Passo Fundo"); //3 
    criarCidade(lista, "Pelotas"); //...
    criarCidade(lista, "Porto Alegre");
    criarCidade(lista, "Santiago");
    criarCidade(lista, "Santa Maria");
    criarCidade(lista, "Sao Borja");
    criarCidade(lista, "Sao Gabriel");
}

//Funcao para ligar os caminhos.
void ligaEntrada(Cidade *lista[])
{
	//Para ligar a funcao recebe a cidade da posição 3 e a da 5 além da distancia.
    ligarCaminhos(lista, 3, 5, 289); //lista[3] = Passo Fundo e lista[5] = POA
    ligarCaminhos(lista, 5, 4, 261);
    ligarCaminhos(lista, 4, 1, 189);
    ligarCaminhos(lista, 1, 9, 268);
    ligarCaminhos(lista, 9, 0, 204);
    ligarCaminhos(lista, 0, 8, 315);
    ligarCaminhos(lista, 8, 6, 141);
    ligarCaminhos(lista, 6, 2, 242);
    ligarCaminhos(lista, 2, 3, 149);
    ligarCaminhos(lista, 2, 7, 134);
    ligarCaminhos(lista, 7, 6, 152);
    ligarCaminhos(lista, 7, 0, 258);
    ligarCaminhos(lista, 7, 9, 182);
    ligarCaminhos(lista, 7, 1, 239);
    ligarCaminhos(lista, 7, 5, 291);
    ligarCaminhos(lista, 5, 1, 377);
}

//Funcao para imprimir todas as cidades.
void imprimirCidades(Cidade *lista[])
{
    system("cls");
	printf("Chave \t Cidade \t Grau\n\n");
    int i;
	for(i=0; i<numCidades; i++) //Varre o vetor até chegar no numero de cidades cadastradas.
	{
        printf("%d \t %s \t  %d\n", i, lista[i]->nome, lista[i]->grau);
    }
    printf("\n");
    getch();
}

// Funcao para criar o caminho.
Caminho *criarCaminho(Cidade *lista[], int destino, int distancia)
{
    Caminho *novo = (Caminho*)malloc(sizeof(Caminho)); //Aloca um espaço.
    novo->vizinho = lista[destino]; //Novo aponta pra vizinho é igual a lista na posicao destino.
    novo->distancia = distancia; //Novo aponta pra distancia é igual a distancia recebida.
    return novo; //Retorna o novo.
}

//Funcao para ligar os caminhos
void ligarCaminhos(Cidade *lista[], int origem, int destino, int distancia)
{
    lista[origem]->vizinhos[lista[origem]->grau] = criarCaminho(lista, destino, distancia);
    lista[origem]->grau++; //Incrementa o grau da cidade de origem.

    lista[destino]->vizinhos[lista[destino]->grau] = criarCaminho(lista, origem, distancia);
    lista[destino]->grau++; //Incrementa o grau da cidade de destino.
}

//Funcao para imprimir as cidades vizinhas.
void imprimirVizinhos(Cidade *lista[], int chave)
{
    printf("\nResultado para cidades vizinhas de %s\n", lista[chave]->nome);

    printf("\nChave \t Cidade \t\t Distancia(KM)\n\n");
    int i;
	for(i=0; i<lista[chave]->grau; i++)
	{
        printf("%d \t %s \t\t %d\n", i, lista[chave]->vizinhos[i]->vizinho->nome, lista[chave]->vizinhos[i]->distancia);
    }
    printf("\n");
}

//Funcao para editar o nome da cidade selecionada;
//Recebe a lista e o indice da cidade desejada.
void editarNome(Cidade *lista[], int chave)
{
	char nome[20];
    printf("Digite o novo nome: ");
    fflush(stdin);
    gets(nome);
    //Copia o novo nome para a lista no indice da cidade recebida;
	strcpy(lista[chave]->nome, nome);
}

//Funcao para editar a distancia entre cidades.
void editarDistancia (Cidade *lista[], int chave)
{
	int chave2, dist;
	imprimirVizinhos(lista, chave);
	printf("\nInforme a chave da cidade de destino: ");
	scanf("%d", &chave2);
	printf("\nInforme a nova distancia: ");
	scanf("%d", &dist);
	
	//Atualiza a distancia entre a cidade de origem e a de destino.
	lista[chave]->vizinhos[chave2]->distancia = dist;
}

//Funcao para remover caminho
void caminhos(Cidade *lista[], int chaveOrigem, int cidadeRemover){

    char nome[20], nome2[20];

    strcpy(nome, lista[chaveOrigem]->nome); //Copia o nome da cidade da lista, para a variavel
    strcpy(nome2, lista[chaveOrigem]->vizinhos[cidadeRemover]->vizinho->nome); //Copia o nome da cidade da lista de visinhos para a variavel.

    removerCaminho(lista, chaveOrigem, nome2); //Chama funcao para remover o caminho da cidade de origem.
    cidadeRemover = buscaCidade(lista, nome2); //Busca a cidade e retorna a posicao dela.
    removerCaminho(lista, cidadeRemover, nome); //Chama a funcao para remover caminho da cidade vizinha.
}

//Funcao para remover o caminho
void removerCaminho(Cidade *lista[], int chaveOrigem, char nomeRemover[20])
{
    int i, j;

    for(i=0; i<lista[chaveOrigem]->grau; i++) //Percorre o vetor até o numero de graus de uma cidade.
	{
        if(strcmp(nomeRemover, lista[chaveOrigem]->vizinhos[i]->vizinho->nome) == 0) //Compara o nome que da cidade que quer remover com o nome da lista de vizinhos.
		{ 
            j = i; //
             while(j < lista[chaveOrigem]->grau)
			{
                lista[chaveOrigem]->vizinhos[j] = lista[chaveOrigem]->vizinhos[j+1]; //Avança a posicao de vizinhos no vetor.
                j++; //Incrementa o j.
            }
            lista[chaveOrigem]->grau--; //Decrementa o grau da cidade.
        }
    }
}

//Funcao para buscar cidade.
int buscaCidade(Cidade *lista[], char nome[20])
{
    int i;
	for(i=0; i<numCidades; i++)
	{
        if(strcmp(nome, lista[i]->nome) == 0)
		{
            return i;
        }
    }
}
