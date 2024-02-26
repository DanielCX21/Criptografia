#include <string.h>
#include <stdio.h>

int one_time_pad(char *mensagem, char *chave)
{
    int tamanho_mensagem = strlen(mensagem);

    int i;

    if(strlen(mensagem) > strlen(chave))
    {
        return -1;
    }
    else
    {
        for(i = 0; i < tamanho_mensagem; i++)
        {
            mensagem[i] = mensagem[i] ^ chave[i];
        }
        return i;
    }
}

main()
{
    char mensagem[] = "IME-SEC";
    char chave[] = "adlivjbfrvil";

    printf("Original: %s\n", mensagem);

    one_time_pad(mensagem, chave);
    printf("Criptografado: %s\n", mensagem);
    
    one_time_pad(mensagem, chave);
    printf("original de novo: %s", mensagem);

    return 0;
}