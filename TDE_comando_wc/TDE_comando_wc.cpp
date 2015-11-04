// TDE_comando_wc.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int main(int argc, char const *argv[])
{
	setlocale(LC_ALL, "");
	int ch;
	int total_char=0, total_palavras=0, total_linhas=0;
	FILE * arquivo;

	// Se não for passado o arquivo como parâmetro, mostrar erro
	if (argv[1] == NULL)
	{
		printf("É necessário passar um arquivo como parâmetro\n");
		return (-1);
	}

	// fopen_s não retorna o arquivo, por isso no "if", devemos usar o arquivo base para comparação
	fopen_s(&arquivo, argv[1], "r");
	if (arquivo == NULL)
	{
		printf("Não foi possível Abrir o Arquivo\n");
		return (-2);
	}

	// While que lê cada caracter do arquivo
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

