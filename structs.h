#ifndef STRUCTS_H
#define STRUCTS_H

#include <string>
using std::string;

struct Endereco {
    string logradouro;
    string complemento;
    string cep;
    string bairro;
    string cidade;
    string estado;
};

struct Cliente {
    int codigo;
    string nome;
    char tipo_pessoa;
    string cpf;
    string telefone;
    Endereco endereco;
};

struct Produto {
    int codigo;
    string nome;
    string fornecedor;
    string categoria;
    int quantidade;
    double valor_unitario;
};

struct identificador {
    string nome;
    string codigo;
};

#endif