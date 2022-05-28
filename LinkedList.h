/*
ESTRUTURA DE DADOS - ATIVIDADE DE APLICACAO 2
Henrique Machado Calderon 32130813
Henrique Magyarics Nellesen 32110901
Gabriel Santos de Oliveira Arruda 32107439
*/

// LinkedList.h
#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__

#include "NodeLL.h"
#include <string>

class LinkedList{
	private:
		NodeLL *head;
		NodeLL *tail;
		unsigned int tamanho;
	public:	
		LinkedList();
		~LinkedList();
		bool isEmpty();
		bool isFull();
		bool insertTail(TIPO id);
		void clear();
		void print();	
		
		unsigned int getTamanho() { return tamanho; }
		NodeLL* getHead(void){ return head; };
		void setHead(NodeLL *head) { this->head = head;	}

		// Consultas personalizadas para analise dos dados:
		unsigned int total_de_fumantes_com_covid_mortos();
		unsigned int total_de_asmaticos_com_covid_mortos();
		unsigned int total_de_idosos_com_covid_mortos(); // Idade >= 60 anos
		unsigned int total_de_mortos_com_covid();
		unsigned int total_de_intubados_com_covid();
};

#endif
