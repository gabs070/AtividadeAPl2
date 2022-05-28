/*
ESTRUTURA DE DADOS - ATIVIDADE DE APLICACAO 2
Henrique Machado Calderon 32130813
Henrique Magyarics Nellesen 32110901
Gabriel Santos de Oliveira Arruda 32107439
*/

#ifndef __PACIENTE_H__
#define __PACIENTE_H__

#include <string>
using namespace std;

class Paciente
{
public:
    // Atributos de "Paciente" definidos na documentacao
	int sexo;
	int tipo_paciente;
	int intubado;
	int pneumonia;
	int idade;
	int diabetes;
	int copd;
	int asma;
	int imunossupressao;
	int hipertensao;
	int outras_doencas;
	int cardiovascular;
	int obesidade;
	int icu;
	int teste_covid;
	int fumante;
	int outro_caso;
	int gravidez;
	int uci;
	int obito;
    // Construtor Customizado de paciente
	// Definicao no .cpp
	Paciente(int sexo, int tipo_paciente, int intubado, int pneumonia, int idade, int diabetes, int copd, int asma,
		int imunossupressao, int hipertensao, int outras_doencas, int cardiovascular, int obesidade, int icu,
		int teste_covid, int fumante, int outro_caso, int gravidez, int uci, int obito);
    // Construtor Vazio de paciente (para deixar todos atributos como padrao)
	// Definicao no .cpp
	Paciente();
	string pac_to_string();


};





#endif
