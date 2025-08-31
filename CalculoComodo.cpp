#include <iostream>
using namespace std;
double calcular_litros_tinta(double areatotal)
{
    double quantidadetinta = areatotal / 10;
    return quantidadetinta;
}
double horastrabalhadas(double areatotal)
{
    double htrabalhada = (areatotal / 10) * 8;
    return htrabalhada;
}
double custott(double quantidadetinta, double precotinta)
{
    double custotinta = quantidadetinta * precotinta;
    return custotinta;
}
double calcularcustotrabalho(double htrabalhadas, double precohora = 25)
{
    double custotrabalho = htrabalhadas * precohora;
    return custotrabalho;
}
double calcularcustototal(double custotinta, double custotrabalho)
{
    double custototal = custotinta + custotrabalho;
    return custototal;
}
int num_comodos()
{
    int comodos;
    do
    {
        cout << "qual o número de comodos a serem pintados:" << endl;
        cin >> comodos;
        if (comodos < 1)
        {
            cout << "valor inválido.";
        }
    } while (comodos < 0 || comodos == 0);
    return comodos;
}
double valor_litro()
{
    double precotintalitro;
    do
    {
        cout << "qual o valor da tinta por litro?" << endl;
        cin >> precotintalitro;
    } while (precotintalitro < 10);

    return precotintalitro;
}

int main()
{
    double metragem, area, areatotal;

    int numcomodos = num_comodos();

    for (int i = 0; i < numcomodos; i++){
        do
        {
            cout << "qual a metragem da parede do " << i << " comodo?" << endl;
            cin >> metragem;
            area = metragem * metragem;
            areatotal += area;
        } while (metragem < 0 || metragem == 0);
    }

    double quantidade_tinta = calcular_litros_tinta(areatotal);
    cout << "a quantidade de litro de tinta necessarias é:" << quantidade_tinta << endl;

    double valorlitro = valor_litro();

    double htrabalhadas = horastrabalhadas(areatotal);
    cout << "as horas de trabalho necessarias é de:" << htrabalhadas << endl;

    double custotinta = custott(quantidade_tinta, valorlitro);
    cout << "o custo da linta é de:" << custotinta << " reais." << endl;

    double custotrabalho = calcularcustotrabalho(htrabalhadas);
    cout << "o custo do trabalho é de:" << custotrabalho << " reais" << endl;

    double custototal = calcularcustotrabalho(custotinta, custotrabalho);
    cout << "o custo total é de:" << custototal << endl;

    return 0;
}