#include <iostream>
#include <string>
using namespace std;

struct Endereco {
    string cidade;
    string estado;
    string cep;
};

struct conta_cliente {
    string nome;
    string cpf;
    Endereco endereco;
    string telefone;
    double saldo;
};

void add_conta(conta_cliente contas[], int &numContas) {
    
    conta_cliente nova_conta;
    
    if (numContas >= 10) {
        cout << "Número máximo de contas atingido!" << endl;
        return;
    }
   

    cout << "Nome completo: ";
    cin.ignore();
    getline(cin, nova_conta.nome);

    cout << "CPF: ";
    getline(cin, nova_conta.cpf);

    cout << "Cidade: ";
    getline(cin, nova_conta.endereco.cidade);

    cout << "Estado: ";
    getline(cin, nova_conta.endereco.estado);

    cout << "CEP: ";
    getline(cin, nova_conta.endereco.cep);

    cout << "Telefone: ";
    getline(cin, nova_conta.telefone);

    do {
        cout << "Saldo inicial: ";
        cin >> nova_conta.saldo;
        if (nova_conta.saldo < 0) {
            cout << "O saldo não pode ser negativo!" << endl;
        }
    } while (nova_conta.saldo < 0);

    contas[numContas++] = nova_conta;
    cout << "Conta adicionada" << endl;
}

void remover_conta(conta_cliente contas[], int &numContas, string cpf) {
    int indice = -1;
    for (int i = 0; i < numContas; i++) {
        if (contas[i].cpf == cpf) {
            indice = i;
            break;
        }
    }
    if (indice == -1) {
        cout << "Conta não encontrada" << endl;
        return;
    }

    for (int i = indice; i < numContas - 1; i++) {
        contas[i] = contas[i + 1];
    }
    numContas--;
    cout << "Conta removida " << endl;
}

void listar_contas(conta_cliente contas[], int numContas) {
    for (int i = 0; i < numContas; i++) {
        cout << "Nome: " << contas[i].nome << " | CPF: " << contas[i].cpf << endl;
    }
}

void imprimir_cliente(conta_cliente contas[], int numContas, string cpf) {
    for (int i = 0; i < numContas; i++) {
        if (contas[i].cpf == cpf) {
            cout << "Nome: " << contas[i].nome << endl;
            cout << "CPF: " << contas[i].cpf << endl;
            cout << "Cidade: " << contas[i].endereco.cidade << endl;
            cout << "Estado: " << contas[i].endereco.estado << endl;
            cout << "CEP: " << contas[i].endereco.cep << endl;
            cout << "Telefone: " << contas[i].telefone << endl;
            cout << "Saldo: " << contas[i].saldo << endl;
            return;
        }
    }
    cout << "Conta não encontrada " << endl;
}

void atualizar_conta(conta_cliente contas[], int numContas, string cpf) {
    for (int i = 0; i < numContas; i++) {
        if (contas[i].cpf == cpf) {
            cout << "Atualizando dados da conta de " << contas[i].nome << endl;
            cout << "Novo telefone: ";
            cin.ignore();
            getline(cin, contas[i].telefone);

            cout << "Novo saldo: ";
            cin >> contas[i].saldo;
            if (contas[i].saldo < 0) {
                cout << "Saldo não pode ser negativo! Atualização cancelada." << endl;
                return;
            }
            cout << "Dados atualizados " << endl;
            return;
        }
    }
    cout << "Conta não encontrada " << endl;
}

int main() {
    conta_cliente contas[10];
    int numContas = 0;
    int opcao;

    do {
        cout << "1 - Adicionar nova conta" << endl;
        cout << "2 - Remover conta existente" << endl;
        cout << "3 - Listar todas as contas" << endl;
        cout << "4 - Imprimir dados de um cliente específico" << endl;
        cout << "5 - Atualizar dados de uma conta" << endl;
        cout << "6 - Sair" << endl;
        cout << "Escolha uma opção: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                add_conta(contas, numContas);
                break;
            case 2: {
                string cpf;
                cout << "Digite o CPF da conta que você quer remover: ";
                cin.ignore();
                getline(cin, cpf);
                remover_conta(contas, numContas, cpf);
                break;
            }
            case 3:
                listar_contas(contas, numContas);
                break;
            case 4: {
                string cpf;
                cout << "Digite o CPF do cliente: ";
                cin.ignore();
                getline(cin, cpf);
                imprimir_cliente(contas, numContas, cpf);
                break;
            }
            case 5: {
                string cpf;
                cout << "Digite o CPF do cliente: ";
                cin.ignore();
                getline(cin, cpf);
                atualizar_conta(contas, numContas, cpf);
                break;
            }
            case 6:
                cout << "Fim" << endl;
                break;
            default:
                cout << "Opção inválida!" << endl;
                break;
        }

    } while (opcao != 6);

    return 0;
}