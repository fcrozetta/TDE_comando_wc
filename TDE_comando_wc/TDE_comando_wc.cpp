// TDE_comando_wc.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int main(int argc, char const *argv[])
{
	setlocale(LC_ALL, "");
	int ch;
	int total_char=0, total_palavras=0, total_linhas=0;
	FILE * arquivo;

	// Se n�o for passado o arquivo como par�metro, mostrar erro
	if (argv[1] == NULL)
	{
		printf("� necess�rio passar um arquivo como par�metro\n");
		return (-1);
	}

	// fopen_s n�o retorna o arquivo, por isso no "if", devemos usar o arquivo base para compara��o
	fopen_s(&arquivo, argv[1], "r");
	if (arquivo == NULL)
	{
		printf("N�o foi poss�vel Abrir o Arquivo\n");
		return (-2);
	}

	// While que l� cada caracter do arquivo
	while ((ch=fgetc(arquivo))!= EOF)
	{
		if (ch == ' ')
		{
			total_palavras++;
		}
		if (ch == '\n')
		{
			total_linhas++;
			total_palavras++;
		}
		else
		{
			total_char++;
		}
	}

	/* Adicionar ao final porque paramos antes do EOF */
	total_linhas++;
	total_palavras++;

	// Fechar o arquivo
	fclose(arquivo);

	// Mensagem final
	printf("Characteres: %d\nPalavras: %d\nLinhas:%d\n", total_char, total_palavras, total_linhas);
    return 0;
}

