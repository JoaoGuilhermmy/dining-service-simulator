#include <stdio.h>
#include <stdlib.h>
#include "Lista.h"
#include "Fila.h"

int main()
{
    Fila cozinha;
    No *cabeca = NULL;
    Pedido *pedidos = NULL;
    inicia_fila(&cozinha);
    int opcao;
    int mesa = 1;

    // While referente a primeira interação do usuario
    while (1)
    {
        limpa_tela();
        printf("\tBem Vindo ao restaurante IMD palace\n");
        printf("\n\t1 - Fazer pedido\n\t2 - Visualizar pedidos na cozinha\n\t3 - Sair\n");
        scanf("%d", &opcao);

        // Estrutura caso o usuario escolha fazer um pedido
        if (opcao == 1)
        {
            limpa_tela();

            // while para o escolher uma opção ate ele não quiser mais algo relacionado ao pedido.
            while (1)
            {
                int resposta;
                printf("\n\t1 - Escolher Entradas\n");
                printf("\n\t2 - Escolher Prato Principal\n");
                printf("\n\t3 - Escolher Sobremesas \n");
                printf("\n\t4 - Remover Prato\n");
                printf("\n\t0 - Finalizar pedido\n");
                printf("\n\tDigite o numero correspondente ao que voce deseja fazer.\n");
                scanf("%d", &resposta);
                limpa_tela();

                // condiçãoes para o usuario finalizar o pedido
                if (resposta == 0)
                {
                    No *atual = cabeca;
                    while (atual != NULL)
                    {
                        inserir_fila(&cozinha, atual->tipo, atual->valor, mesa);
                        atual = atual->proximo;
                    }
                    printf("\n\tPedido enviado para a cozinha com sucesso!\n");
                    espera(2);

                    while (cabeca != NULL)
                    {
                        No *temp = cabeca;
                        cabeca = cabeca->proximo;
                        free(temp);
                    }
                    mesa++;
                    break;
                }

                // condição para escolher as entradas
                else if (resposta == 1)
                {
                    int num;
                    int continuar = 1;
                    while (continuar == 1)
                    {
                        printf("\n\tEntradas:\n");
                        printf("\n\t1. Sopa de Cebola\n\t2. Salada Caesar\n\t3. Bruschetta\n\t4. Carpaccio de Carne\n\t5. Camarao ao Alho\n");
                        printf("\n\tDigite o numero correspondente ao que voce deseja pedir,Caso nao deseje nada, digite 0.\n");
                        scanf("%d", &num);

                        switch (num)
                        {
                        case 0:
                            continuar = 0;
                            break;
                        case 1:
                            printf("\n\tSopa de Cebola adicionada ao pedido\n");
                            inserir_pedido(&cabeca, ENTRADA, num);
                            printf("\n\tDeseja pedir outra entrada? (Sim = 1, Nao = 0)\n");
                            scanf("%d", &continuar);
                            break;
                        case 2:
                            printf("\n\tSalada Caesar adicionada ao pedido\n");
                            inserir_pedido(&cabeca, ENTRADA, num);
                            printf("\n\tDeseja pedir outra entrada? (Sim = 1, Nao = 0)\n");
                            scanf("%d", &continuar);
                            break;
                        case 3:
                            printf("\n\tBruschetta adicionada ao pedido\n");
                            inserir_pedido(&cabeca, ENTRADA, num);
                            printf("\n\tDeseja pedir outra entrada? (Sim = 1, Nao = 0)\n");
                            scanf("%d", &continuar);
                            break;
                        case 4:
                            printf("\n\tCarpaccio de Carne adicionada ao pedido\n");
                            inserir_pedido(&cabeca, ENTRADA, num);
                            printf("\n\tDeseja pedir outra entrada? (Sim = 1, Nao = 0)\n");
                            scanf("%d", &continuar);
                            break;
                        case 5:
                            printf("\n\tCamarao ao Alho adicionada ao pedido\n");
                            inserir_pedido(&cabeca, ENTRADA, num);
                            printf("\n\tDeseja pedir outra entrada? (Sim = 1, Nao = 0)\n");
                            scanf("%d", &continuar);
                            break;
                        default:
                            printf("Opaoo invalida, Nao foi possivel adicionar ao pedido\n");
                            espera(2);
                            break;
                        }
                        limpa_tela();
                    }
                }

                // condição para escolher os pratos principais
                else if (resposta == 2)
                {
                    int num;
                    int continuar = 1;

                    while (continuar == 1)
                    {
                        printf("\n\tPratos Principais:\n");
                        printf("\n\t1. Lasanha a Bolonhesa\n\t2. File Mignon com Fritas\n\t3. Frango Grelhado com Legumes\n\t4. Bacalhau a Gomes de Sa\n\t5. Risoto de Cogumelos\n");
                        printf("\n\tDigite o numero correspondente ao que voce deseja pedir, Caso nao deseje nada, digite 0\n");
                        scanf("%d", &num);

                        switch (num)
                        {
                        case 0:
                            continuar = 0;
                            break;
                        case 1:
                            printf("\n\tLasanha a Bolonhesa adicionada ao pedido\n");
                            inserir_pedido(&cabeca, PRINCIPAL, num);
                            printf("\n\tDeseja pedir outro prato principal? (Sim = 1, Nao = 0)\n");
                            scanf("%d", &continuar);
                            break;
                        case 2:
                            printf("\n\tFile Mignon com Fritas adicionada ao pedido\n");
                            inserir_pedido(&cabeca, PRINCIPAL, num);
                            printf("\n\tDeseja pedir outro prato principal? (Sim = 1, Nao = 0)\n");
                            scanf("%d", &continuar);
                            break;
                        case 3:
                            printf("\n\tFrango Grelhado com Legumes adicionada ao pedido\n");
                            inserir_pedido(&cabeca, PRINCIPAL, num);
                            printf("\n\tDeseja pedir outro prato principal? (Sim = 1, Nao = 0)\n");
                            scanf("%d", &continuar);
                            break;
                        case 4:
                            printf("\n\tBacalhau à Gomes de Sa adicionada ao pedido\n");
                            inserir_pedido(&cabeca, PRINCIPAL, num);
                            printf("\n\tDeseja pedir outro prato principal? (Sim = 1, Nao = 0)\n");
                            scanf("%d", &continuar);
                            break;
                        case 5:
                            printf("\n\tRisoto de Cogumelos adicionada ao pedido\n");
                            inserir_pedido(&cabeca, PRINCIPAL, num);
                            printf("\n\tDeseja pedir outro prato principal? (Sim = 1, Nao = 0)\n");
                            scanf("%d", &continuar);
                            break;
                        default:
                            printf("Opcao invalida, Nao foi possivel adicionar ao pedido\n");
                            break;
                        }
                        limpa_tela();
                    }
                }

                // condição para escolher as sobremesas
                else if (resposta == 3)
                {
                    int num;
                    int continuar = 1;

                    while (continuar == 1)
                    {
                        printf("\n\tSobremesas:\n");
                        printf("\n\t1.Tiramisu \n\t2. Cheesecake de Frutas Vermelhas\n\t3. Mousse de Chocolate\n\t4. Pudim de Leite\n\t5. Sorvete de Baunilha com Calda de Morango\n");
                        printf("\n\tDigite o numero correspondente ao que voce deseja pedir, Caso não deseje nada, digite 0\n");
                        scanf("%d", &num);

                        switch (num)
                        {
                        case 0:
                            continuar = 0;
                            break;
                        case 1:
                            printf("\n\tTiramisu adicionada ao pedido\n");
                            inserir_pedido(&cabeca, SOBREMESA, num);
                            printf("\n\tDeseja pedir outra sobremesa? (Sim = 1, Nao = 0)\n");
                            scanf("%d", &continuar);
                            break;
                        case 2:
                            printf("\n\tCheesecake de Frutas Vermelhas adicionada ao pedido\n");
                            inserir_pedido(&cabeca, SOBREMESA, num);
                            printf("\n\tDeseja pedir outra sobremesa? (Sim = 1, Nao = 0)\n");
                            scanf("%d", &continuar);
                            break;
                        case 3:
                            printf("\n\tMousse de Chocolate adicionada ao pedido\n");
                            inserir_pedido(&cabeca, SOBREMESA, num);
                            printf("\n\tDeseja pedir outra sobremesa? (Sim = 1, Nao = 0)\n");
                            scanf("%d", &continuar);
                            break;
                        case 4:
                            printf("\n\tPudim de Leite adicionada ao pedido\n");
                            inserir_pedido(&cabeca, SOBREMESA, num);
                            printf("\n\tDeseja pedir outra sobremesa? (Sim = 1, Nao = 0)\n");
                            scanf("%d", &continuar);
                            break;
                        case 5:
                            printf("\n\tSorvete de Baunilha com Calda de Morango adicionada ao pedido\n");
                            inserir_pedido(&cabeca, SOBREMESA, num);
                            printf("\n\tDeseja pedir outra sobremesa? (Sim = 1, Nao = 0)\n");
                            scanf("%d", &continuar);
                            break;
                        default:
                            printf("Opcao invalida! Nao foi possivel adicionar ao pedido\n");
                            espera(2);
                            break;
                        }
                        limpa_tela();
                    }
                }

                // condição para remover pratos
                else if (resposta == 4)
                {
                    if (cabeca == NULL)
                    {
                        printf("Nenhum prato foi pedido ainda!\n");
                        espera(2);
                        break;
                    }
                    int n;
                    int resposta;
                    printf("\nSeu pedido:\n");
                    imprime_pedidos(cabeca);
                    printf("\n\tQual tipo de prato deseja remover do seu pedido?\n");
                    printf("\n\t1. Entrada\n\t2. Principal\n\t3. Sobremesa\n");
                    scanf("%d", &resposta);
                    limpa_tela();

                    switch (resposta)
                    {
                    case 1:
                        imprime_pedidos(cabeca);
                        printf("\n\tQual o numero da entrada deseja remover do seu pedido?\n");
                        printf("\n\t1. Sopa de Cebola\n\t2. Salada Caesar\n\t3. Bruschetta\n\t4. Carpaccio de Carne\n\t5. Camarao ao Alho\n");
                        scanf("%d", &n);
                        if (n < 1 || n > 5)
                        {
                            printf("Opcao invalida!\n");
                            espera(2);
                            break;
                        }
                        else
                        {
                            printf("\n\tPrato removido com sucesso!\n");
                            espera(2);
                            remover_pedido(&cabeca, ENTRADA, n);
                            break;
                        }
                    case 2:
                        imprime_pedidos(cabeca);
                        printf("\n\tQual o numero do prato principal deseja remover do seu pedido?\n");
                        printf("\n\t1. Lasanha a Bolonhesa\n\t 2. File Mignon com Fritas\n\t3. Frango Grelhado com Legumes\n\t4. Bacalhau a Gomes de Sa\n\t5. Risoto de Cogumelos\n");
                        scanf("%d", &n);
                        if (n < 1 || n > 5)
                        {
                            printf("Opcao invalida!\n");
                            espera(2);
                            break;
                        }
                        else
                        {
                            printf("\n\tPrato removido com sucesso!\n");
                            espera(2);
                            remover_pedido(&cabeca, PRINCIPAL, n);
                            break;
                        }
                    case 3:
                        imprime_pedidos(cabeca);
                        printf("\n\tQual o numero da sobremesa deseja remover do seu pedido?\n");
                        printf("\n\t1. Tiramisu\n\t2. Cheesecake de Frutas Vermelhas\n\t3. Mousse de Chocolate\n\t4. Pudim de Leite\n\t5. Sorvete de Baunilha com Calda de Morango\n");
                        scanf("%d", &n);
                        if (n < 1 || n > 5)
                        {
                            printf("Opcao invalida!\n");
                            espera(2);
                            break;
                        }
                        else
                        {
                            printf("\n\tPrato removida com sucesso!\n");
                            espera(2);
                            remover_pedido(&cabeca, SOBREMESA, n);
                            break;
                        }
                    default:
                        printf("Opcao invalida! Digite uma opcao de tipo de prato valido. \n");
                        espera(2);
                        break;
                    }
                }

                // opção caso o usuario escolha uma opção invalida
                else
                {
                    printf("Opcao invalida!\n");
                    espera(2);
                }
                limpa_tela();
            }
        }

        // Imprime a lista de pedidos na cozinha
        else if (opcao == 2)
        {
            printf("\n\tLista de pedidos na cozinha:\n");
            imprime_fila(&cozinha);
            espera(5);
        }

        // Finaliza o programa
        else if (opcao == 3)
        {
            Pedido *pedido = remover_fila(&cozinha);
            if (pedido != NULL)
            {
                printf("Removido: Mesa %d\n", pedido->mesa);
                free(pedido); // Não se esqueça de liberar a memória
            }

            break;
        }

        // opção caso o usuario escolha uma opção invalida
        else
        {
            printf("Opcao invalida!\n");
            espera(2);
            limpa_tela();
        }
    }
    return 0;
}
