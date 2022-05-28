/*
ESTRUTURA DE DADOS - ATIVIDADE DE APLICACAO 2
Henrique Machado Calderon 32130813
Henrique Magyarics Nellesen 32110901
Gabriel Santos de Oliveira Arruda 32107439
*/

#include <string>
#include <iostream>
#include "LinkedList.h"

LinkedList::LinkedList(){
	head = nullptr;
	tail = nullptr;
};
LinkedList::~LinkedList(){
	clear();
};

// Libera memória 
void LinkedList::clear(){
	NodeLL *pAnt, *pAnda = head;
	
	while(pAnda != nullptr){
		pAnt = pAnda;  // Libera o nó
		pAnda = pAnda->getProx();
		pAnt->setProx(nullptr);
		delete pAnt;
		pAnt = nullptr;
	}
	head = nullptr;	
}

bool LinkedList::isEmpty(){
	if (getHead() == nullptr) return true;
	else return false;
};

bool LinkedList::isFull(){
	NodeLL *aux = new NodeLL();
	
	if (aux == nullptr) return true;

	aux = nullptr;
	return false;
};

bool LinkedList::insertTail(TIPO id){
	NodeLL *aux, *pAnda;
    if (!isFull()){
      aux = new NodeLL(id, nullptr);
      if (isEmpty()){ // Lista está vazia
		head = aux;
		tail = aux;
      }else { // Insere no final e atualiza o ponteiro
        pAnda = tail;  // Ponteiro que anda até o final da lista 
        pAnda->setProx( aux );
		tail = aux;
      }
	  tamanho++;
	  return true;
    }
    else return false; // std::cout << "Overflow – Sem memória";
};
	

void LinkedList::print(){
	NodeLL *pAnda; 
    int i = 1;
    std::cout << "L: [ " ;
    pAnda = head;
    while (pAnda != nullptr) {
      std::cout << pAnda->getId().pac_to_string() << " ";
      pAnda = pAnda->getProx();
    }
    std::cout <<  "]\n";
}

// Consultas personalizadas para analise dos dados:
unsigned int LinkedList::total_de_fumantes_com_covid_mortos()
{
	NodeLL* pAnda = head;
	unsigned int contagem = 0;
	while (pAnda != nullptr) // Enquanto o ponteiro que anda for diferente de nulo (isto eh, nao chegar ao fim da lista)
	{
		TIPO paciente = pAnda->getId();
		bool condicao = paciente.fumante == 1 && paciente.teste_covid == 1 && paciente.obito == 1;
		if (condicao) contagem++;
		pAnda = pAnda->getProx();
	}
	return contagem;
}

unsigned int LinkedList::total_de_asmaticos_com_covid_mortos()
{
	NodeLL* pAnda = head;
	unsigned int contagem = 0;
	while (pAnda != nullptr) // Enquanto o ponteiro que anda for diferente de nulo (isto eh, nao chegar ao fim da lista)
	{
		TIPO paciente = pAnda->getId(); // Pega o paciente na posicao atual
		bool condicao = paciente.asma == 1 && paciente.teste_covid == 1 && paciente.obito == 1;
		if (condicao) contagem++; // Verifica se os dados do paciente batem com a condicao. Se bater, incrementar 1 do valor da contagem
		pAnda = pAnda->getProx();
	}
	return contagem;
}

unsigned int LinkedList::total_de_idosos_com_covid_mortos()
{
	NodeLL* pAnda = head;
	unsigned int contagem = 0;
	while (pAnda != nullptr) // Enquanto o ponteiro que anda for diferente de nulo (isto eh, nao chegar ao fim da lista)
	{
		TIPO paciente = pAnda->getId(); // Pega o paciente na posicao atual
		bool condicao = paciente.idade >= 60 && paciente.teste_covid == 1 && paciente.obito == 1;
		if (condicao) contagem++; // Verifica se os dados do paciente batem com a condicao. Se bater, incrementar 1 do valor da contagem
		pAnda = pAnda->getProx();
	}
	return contagem;
}

unsigned int LinkedList::total_de_mortos_com_covid()
{
	unsigned int teste = 0;
	NodeLL* pAnda = head;
	unsigned int contagem = 0;
	while (pAnda != nullptr) // Enquanto o ponteiro que anda for diferente de nulo (isto eh, nao chegar ao fim da lista)
	{
		TIPO paciente = pAnda->getId(); // Pega o paciente na posicao atual
		bool condicao = paciente.teste_covid == 1 && paciente.obito == 1;
		if (condicao) contagem++; // Verifica se os dados do paciente batem com a condicao. Se bater, incrementar 1 do valor da contagem
		teste++;
		pAnda = pAnda->getProx();
	}
	return contagem;
}

unsigned int LinkedList::total_de_intubados_com_covid()
{
	NodeLL* pAnda = head;
	unsigned int contagem = 0;
	while (pAnda != nullptr) // Enquanto o ponteiro que anda for diferente de nulo (isto eh, nao chegar ao fim da lista)
	{
		TIPO paciente = pAnda->getId(); // Pega o paciente na posicao atual
		bool condicao = paciente.intubado == 1 && paciente.teste_covid == 1;
		if (condicao) contagem++; // Verifica se os dados do paciente batem com a condicao. Se bater, incrementar 1 do valor da contagem
		pAnda = pAnda->getProx();
	}
	return contagem;
}
		

