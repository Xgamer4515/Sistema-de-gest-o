#ifndef CLIENTES_H
#define CLIENTES_H

#include "menus.h"
#include "structs.h"

void exibir(const Cliente&);
void menu_cadastro(Cliente&);
void cadastrar_cliente(ofstream&);
void guardar_cliente(ofstream&, const Cliente&);
void listar_cliente(ifstream&);
void buscar_cliente(ifstream&);
void atualizar_cliente(ifstream&);
void excluir_cliente(ifstream&);

#endif