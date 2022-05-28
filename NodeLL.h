/*
ESTRUTURA DE DADOS - ATIVIDADE DE APLICACAO 2
Henrique Machado Calderon 32130813
Henrique Magyarics Nellesen 32110901
Gabriel Santos de Oliveira Arruda 32107439
*/

// NodeLL.h
#ifndef __NODE_LL_H__
#define __NODE_LL_H__
#include "Paciente.h"

// Aqui mudamos para a lista armazenar objetos do tipo Paciente
typedef Paciente TIPO;
class NodeLL  // ll = linked List
{
public:
	NodeLL(){ id = Paciente(); prox = nullptr;	};
	NodeLL(TIPO id, NodeLL* prox){
			this->id = id;
			this->prox = prox;
	};
	~NodeLL();

	NodeLL *getProx() { return prox; };
	TIPO getId(){ return id; };
	
	void setProx(NodeLL *prox) { this->prox = prox; };
	void setId(TIPO id) { this->id = id;	};
	
private:
	TIPO id;
	NodeLL *prox;
};

#endif
