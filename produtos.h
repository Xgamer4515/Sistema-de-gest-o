#ifndef PRODUTOS_H
#define PRODUTOS_H

#include "menus.h"

void exibir(const Produto&);
void menu_cadastro(Produto&);
void cadastrar_produto(ofstream&);
void guardar_produto(ofstream&, const Produto&);
void listar_produto(ifstream&);
void buscar_produto(ifstream&);
void atualizar_produto(ifstream&);
void excluir_produto(ifstream&);

#endif
