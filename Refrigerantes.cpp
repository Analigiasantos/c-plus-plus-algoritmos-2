/*
  Programa: Refrigerantes.cpp
  Descrição: Simula uma máquina de vendas de refrigerantes.
             Permite cadastrar até 5 refrigerantes, listar os disponíveis,
             realizar compras com cálculo de troco, atualizar o estoque
             e mostrar o total arrecadado ao final da execução.
*/

#include <iostream>
using namespace std;

struct refrigerante
{
    string nome;
    double preco;
    int quantidade;
};

int cadastrar_refrigerante(refrigerante refri[])
{

    int n;

    do
    {
        cout << "quantos refrigerantes você quer cadastrar? " << endl;
        cin >> n;
    } while (n > 5);

    for (int i = 0; i < n; i++)
    {

        cout << "qual o nome do " << i + 1 << "° refrigerante: " << endl;
        cin.ignore();
        getline(cin, refri[i].nome);

        do
        {
            cout << "qual o preço do refrigerante: " << endl;
            cin >> refri[i].preco;
            cout << "qual a quantidade desse refrigerante: " << endl;
            cin >> refri[i].quantidade;
        } while (refri[i].preco < 0 || refri[i].quantidade < 0);
    }

    return n;
}

void disponiveis(refrigerante refri[], int n)
{

    cout << "os refrigerantes disponiveis são: " << endl;
    for (int i = 0; i < n; i++)
    {
        if (refri[i].quantidade > 0)
        {
            cout << i << " - " << refri[i].nome << "   R$: " << refri[i].preco << endl;
        }
    }
}

int cliente_tipo(int n, refrigerante refri[])
{

    int refri_id;
    do
    {
        cout << "qual refrigerante você deseja? (número) " << endl;
        cin >> refri_id;
        if (refri[refri_id].quantidade == 0)
        {
            cout << refri[refri_id].nome << " esgotado!";
        }
    } while (refri_id < 0 || refri_id >= n || refri[refri_id].quantidade == 0);

    return refri_id;
}

void comprar_refri(refrigerante &refri, double &total_arrecadado)
{
    double valor_inserido;
    do
    {
        cout << "Insira o valor que você irá colocar na máquina (até R$ 10): ";
        cin >> valor_inserido;
    } while (valor_inserido < refri.preco || valor_inserido > 10);

    double troco = valor_inserido - refri.preco;
    cout << "Troco: R$ " << troco << endl;

    refri.quantidade--;
    total_arrecadado += refri.preco;
}

void conferir_estoque(refrigerante &refri)
{

    if (refri.quantidade == 0)
    {
        cout << "Refrigerante " << refri.nome << " esgotado!" << endl;
    }
}

int main()
{
    refrigerante refri[5];
    double total_arrecadado = 0;

    cout << "cadastrando os refrigerantes: " << endl;
    int n = cadastrar_refrigerante(refri);
    cout << endl;

    char continuar;
    do
    {
        disponiveis(refri, n);

        int tipo = cliente_tipo(n, refri);

        comprar_refri(refri[tipo], total_arrecadado);
        conferir_estoque(refri[tipo]);
        cout << "Deseja comprar outro refrigerante? (s/n): ";
        cin >> continuar;
    } while (continuar == 's' || continuar == 'S');

    cout << "Total arrecadado pela máquina: R$ " << total_arrecadado << endl;

    return 0;

}
