#include <string.h>
#include <stdio.h>

/*
int is_letter(char letra)
{
    if(letra > 64 && letra < 91)
    {
        return 1;
    }
    else
    {
        if(letra > 96 && letra < 123)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
} 
*/

void cifra_cesar_encrypt(char *mensagem, int deslocamento)
{
    int tamanho_mensagem = strlen(mensagem);
    for(int i = 0; i < tamanho_mensagem; i++)
    {
        mensagem[i] += deslocamento;
    }
}

void cifra_cesar_decrypt(char *mensagem, int deslocamento)
{
    int tamanho_mensagem = strlen(mensagem);
    for(int i = 0; i < tamanho_mensagem; i++)
    {
        mensagem[i] -= deslocamento;
    }
}

main()
{
    char mensagem[] = "IME-SEC";
    int deslocamento = 1;

    printf("Original: %s\n", mensagem);

    cifra_cesar_encrypt(mensagem,deslocamento);
    printf("Criptografado: %s\n", mensagem);
    
    cifra_cesar_decrypt(mensagem, deslocamento);
    printf("Descriptografado: %s\n", mensagem);

    return 0;
}
