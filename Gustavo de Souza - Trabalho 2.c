#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mapa.h"
#define max 100 

//================================================================================================================================================
//MAIN
main()
{
	int op;
	Cidade *lista[max]; //Cria um vetor do tipo Cidade.
	
	insereEntrada(lista); //Insere as cidades de entrada.
	ligaEntrada(lista); //Liga as cidades de entrada.
	
	while(op != 7) //Mostra menu.
	{
		system("cls");
		printf("MAPA RODOVIARIO\t\t BY: Gustavo de Souza UFSM\n\n");
		printf("|======MENU======|\n\n"
			   "1- Inserir nova cidade\n"
			   "2- Visualizar todas cidades\n"
			   "3- Visualizar cidades vizinhas\n"
			   "4- Ligar cidades\n"
			   "5- Alterar dados\n"
			   "6- Remover cidade ou caminho\n"
			   "7- Sair\n");
			   
		printf("\nInsira uma opcao: ");
		scanf("%d", &op);
		
		if(op == 1) //Inserir Cidades
		{
			system("cls");
    		char nome[20];
    		printf("Digite o nome da cidade: ");
    		fflush(stdin);
    		gets(nome);
    		
    		criarCidade(lista, nome); //Chama a funcao para criar a cidade;
		}
		else if(op == 2) //Visualizar Cidades.
		{
			imprimirCidades(lista);
		}
		else if(op == 3) //Visualizar Vizinhos.
		{
			system("cls");
 		    int chave;

    		imprimirCidades(lista); //Para ver todas cidades antes de escolher.

    		printf("\nInsira a chave da cidade: ");
    		scanf("%d", &chave);

	        imprimirVizinhos(lista, chave); //Chama a função para imprimir os vizinhos.
    	    system("pause");
        	system("cls");
		}
		else if(op == 4) //Ligar cidades criadas manualmente.
		{
			system("cls");
   			int origem, destino, distancia;

    		imprimirCidades(lista); //Para ver todas cidades antes de escolher.

    		printf("Digite o número da cidade de origem: ");
    		scanf("%d", &origem);

		    printf("\nDigite o número da cidade de destino: ");
		    scanf("%d", &destino);

		    printf("\nDigite a distancia: "); 
		    scanf("%d", &distancia);
		    
			ligarCaminhos(lista, origem, destino, distancia); //Chama a funcao para ligar as cidades;
		}
		else if(op == 5)
		{
			system("cls");
			int op;
			printf("1- Alterar nome\n"
				   "2- Alterar distancia\n");
				   getch();
			printf("\nInsira uma opcao: ");
			scanf("%d", &op);
			
			if(op == 1)
			{
				int chave;
				imprimirCidades(lista);
				
				printf("\nInsira a chave da cidade que deseja alterar: ");
				scanf("%d", &chave);
				
				editarNome(lista, chave);
			}
			else if(op == 2)
			{
				int chave;
				imprimirCidades(lista);
				
				printf("\nInsira a chave da cidade que deseja alterar: ");
				scanf("%d", &chave);
				
				editarDistancia(lista, chave);
			}
		}
		else if(op == 6)
		{
			system("cls");
			int op;
			printf("1- Remover cidade\n"
			       "2- Remover caminho\n");
			printf("Insira uma opcao: ");
			scanf("%d", &op);
			
			if(op == 1)
			{
				//Falta fazer;
			}
			else if(op == 2)
			{
				int chave, chave2;
				
				imprimirCidades(lista);
            	
				printf("\nInforme a chave da cidade para visualizar seus caminhos: ");
            	scanf("%d", &chave);
                
				imprimirVizinhos(lista, chave);
                
				printf("\nInforme a chave do caminho que deseja excluir: ");
                scanf("%d", &chave2);
				
				caminhos(lista, chave, chave2);
			}
		}
		else if(op == 7)
		{
			system("cls");
			printf("Programa finalizado!!!\n\n");
		}
	}
}


