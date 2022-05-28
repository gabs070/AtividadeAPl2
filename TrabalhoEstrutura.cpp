/*
ESTRUTURA DE DADOS - ATIVIDADE DE APLICACAO 2
Henrique Machado Calderon 32130813
Henrique Magyarics Nellesen 32110901
Gabriel Santos de Oliveira Arruda 32107439
*/

#include <sstream>
#include <iostream>
#include <fstream>
#include "LinkedList.h"
#include "Paciente.h"
#include "pilhaClasse.h"

using namespace std;

Paciente criar_paciente(stringstream& paciente_stream)
{
	// Essa funcao eh simples: Ela vai criar um objeto de paciente a partir de uma linha capturada do arquivo, e retornar um objeto do paciente criado a partir dessa stream
	// Aqui definimos qual caractere eh o delimitador do nosso csv. Como eh um arquivo csv, o padrao eh utilizarmos uma virgula
	char delimitador = ',';
	// Aqui criamos uma string volatil que vai armazenar cada atributo
	string str_atributo;
	Pilha pilha_de_atributos = Pilha(); // Declaramos uma pilha que visa armazenar cada atributo

	while (getline(paciente_stream, str_atributo, delimitador)) // Nessa parte, a linha eh dividida pelo delimitador, fazendo com que separemos os atributos
	{
		pilha_de_atributos.push(stoi(str_atributo)); // Assim, para cada atributo, fazemos a adicao dele no topo da pilha
	}

	int obito = pilha_de_atributos.pop();
	int icu = pilha_de_atributos.pop();
	int teste_covid = pilha_de_atributos.pop();
	int outro_caso = pilha_de_atributos.pop();
	int fumante = pilha_de_atributos.pop();
	int icr = pilha_de_atributos.pop();
	int obesidade = pilha_de_atributos.pop();
	int cardiovascular = pilha_de_atributos.pop();
	int outras_doencas = pilha_de_atributos.pop();
	int hipertensao = pilha_de_atributos.pop();
	int imunossupressao = pilha_de_atributos.pop();
	int asma = pilha_de_atributos.pop();
	int copd = pilha_de_atributos.pop();
	int diabetes = pilha_de_atributos.pop();
	int gravidez = pilha_de_atributos.pop();
	int idade = pilha_de_atributos.pop();
	int pneumonia = pilha_de_atributos.pop();
	int intubado = pilha_de_atributos.pop();
	int tipo_paciente = pilha_de_atributos.pop();
	int sexo = pilha_de_atributos.pop();

	Paciente paciente = Paciente(sexo, tipo_paciente, intubado, pneumonia, idade, diabetes, copd, asma, imunossupressao, hipertensao, outras_doencas, cardiovascular
		, obesidade, icr, teste_covid, fumante, outro_caso, gravidez, icu, obito);
	return paciente;
}

LinkedList criar_e_preencher_lista()
{
	// Primeiramente criamos a lista
	LinkedList lista = LinkedList();
	// Fonte: https://www.delftstack.com/pt/howto/cpp/read-csv-file-in-cpp/
	// Essa variavel representa o arquivo que estamos tentando abrir
	ifstream input_file("./df_covid.csv");
	// Caso esse arquivo nao esteja aberto, entao tivemos um erro e devemos alertar o usuario do mesmo
	if (!input_file.is_open())
	{
		cout << "ERROR: ARQUIVO DF_COVID.CSV NAO ENCONTRADO";
		exit(1); // Saida com codigo 1 pois o programa nao funcionou como desejado (0 -> Saiu como esperado) , (1-> Nao saiu como esperado)
	}
	stringstream string_stream; // Aqui criamos uma stream de string, para podermos adicionar o conteudo do arquivo em uma variavel
	string_stream << input_file.rdbuf(); // Essa funcao rdbuff() faz exatamente o que desejamos (adiciona todo o conteudo do arquivo nesse stream criado)
	input_file.close(); // Agora ja podemos fechar o arquivo, pois ja lemos
	string paciente_string; // Declaramos uma string que vai armazenar o conteudo do buffer, mas em string
	string nome_atributos;  // Declaramos outra string que vai armazenar o nome dos atributos
	getline(string_stream, nome_atributos); // Nessa parte lemos a primeira linha, armazenamos os nomes dos atributos, e entao vamos para a proxima linha

	// Esse laco tem uma funcao simples: Seu objetivo eh capturar a proxima linha do arquivo e armazenar na variavel paciente_string, e depois ir para a proxima linha
	// Ele so vai parar quando nao tiver mais linhas para pular
	while (getline(string_stream, paciente_string))
	{
		stringstream conteudo_linha(paciente_string); // Aqui criamos uma stream que vai armazenar o conteudo da string, para pordermos seguir pro proximo passo, que so funciona ao manipular stream
		Paciente paciente = criar_paciente(conteudo_linha);
		lista.insertTail(paciente);
	}
	return lista;

}


void menu(LinkedList& lista)
{
	cout << "BEM VINDO AO ANALISADOR DE DADOS DE COVID!" << endl;
	cout << "<------------------------------------------------------>" << endl;
	cout << "Quais dados deseja consultar?" << endl;
	cout << "1- Numero total de fumantes com covid mortos." << endl;
	cout << "2- Numero total de asmaticos com covid mortos." << endl;
	cout << "3- Numero total de idosos (pessoas a partir de 60 anos) com covid mortos." << endl;
	cout << "4- Numero total de mortos com covid." << endl;
	cout << "5- Numero total de intubados com covid" << endl;
	cout << "0- Sair do programa" << endl;
	cout << "---> ";

	int opcao;
	cin >> opcao;
	cout << "RESULTADO: ";
	switch (opcao)
	{
	case 1:
		cout << "Total de fumantes com covid mortos: " << lista.total_de_fumantes_com_covid_mortos() << endl;
		break;
	case 2:
		cout << "Total de asmaticos com covid mortos: " << lista.total_de_asmaticos_com_covid_mortos() << endl;
		break;
	case 3:
		cout << "Total de idosos (a partir de 60 anos) com covid mortos: " << lista.total_de_idosos_com_covid_mortos() << endl;
		break;
	case 4:
		cout << "Total de mortos com covid: " << lista.total_de_mortos_com_covid() << endl;
		break;
	case 5:
		cout << "Total de intubados com covid: " << lista.total_de_intubados_com_covid() << endl;
		break;
	default:
		exit(0);
		break;
	}
}

int main()
{
	LinkedList lista = criar_e_preencher_lista();
	while (true)
	{
		menu(lista);
		int continuar;
		cout << "Digite algo para continuar: ";
		//system("pause");
		cin >> continuar;
		cin.clear();
		cout << endl << endl << endl;
		cout << "<------------------------------------------------------>" << endl;
	}
		
}


