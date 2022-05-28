/*
ESTRUTURA DE DADOS - ATIVIDADE DE APLICACAO 2
Henrique Machado Calderon 32130813
Henrique Magyarics Nellesen 32110901
Gabriel Santos de Oliveira Arruda 32107439
*/

#include "Paciente.h"

// Construtor de Paciente

Paciente::Paciente(int sexo, int tipo_paciente, int intubado, int pneumonia, int idade, int diabetes, int copd, int asma, int imunossupressao, 
	int hipertensao, int outras_doencas, int cardiovascular, int obesidade, int icu, int teste_covid, int fumante, int outro_caso, int gravidez, int uci, int obito)
{
	this->sexo = sexo;
	this->tipo_paciente = tipo_paciente;
	this->intubado = intubado;
	this->pneumonia = pneumonia;
	this->idade = idade;
	this->diabetes = diabetes;
	this->copd = copd;
	this->asma = asma;
	this->imunossupressao = imunossupressao;
	this->hipertensao = hipertensao;
	this->outras_doencas = outras_doencas;
	this->cardiovascular = cardiovascular;
	this->obesidade = obesidade;
	this->icu = icu;
	this->teste_covid = teste_covid;
	this->fumante = fumante;
	this->outro_caso = outro_caso;
	this->gravidez = gravidez;
	this->uci = uci;
	this->obito = obito;
}

// Construtor Vazio de paciente (para deixar todos atributos como padrao)
Paciente::Paciente()
{
}
// Conversao do tipo paciente para string
string Paciente::pac_to_string()
{
	string paciente_string;
	// Aqui concatenamos cada atributo para formar a string que a funcao vai retornar
	paciente_string = to_string(sexo) + "," + to_string(tipo_paciente) +"," + to_string(intubado) + "," + to_string(pneumonia) + "," + to_string(idade) +
		"," + to_string(diabetes) + "," + to_string(copd) + "," + to_string(asma) + "," + to_string(imunossupressao) + "," + to_string(hipertensao) +
		"," + to_string(outras_doencas) + "," + to_string(cardiovascular) + "," + to_string(obesidade) + "," + to_string(icu) + "," + to_string(teste_covid) +
		"," + to_string(fumante) + "," + to_string(outro_caso) + "," + to_string(gravidez) + "," + to_string(uci) + "," + to_string(obito);
	return paciente_string;
}
