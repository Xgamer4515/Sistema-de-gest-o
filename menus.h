#ifndef MENUS_H
#define MENUS_H

#include <iostream>
#include <fstream>
#include <cctype>
#include <chrono>
#include <thread>
#include <cstdio>
#include "structs.h"

using std::cin;
using std::cerr;
using std::cout;
using std::endl;
using std::string;
using std::ios_base;
using std::ofstream;
using std::ifstream;
using std::to_string;
using std::streamsize;
using std::numeric_limits;
using std::chrono::milliseconds;
using std::this_thread::sleep_for;

#ifdef _WIN32
#include <Windows.h>

inline void ConfigurarAcentuacaoConsole() {
    system("chcp 65001 > nul");
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
}
#endif

inline void LimparTela() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

inline void pausar() {
#ifdef _WIN32
    system("pause");
#else
    cout << "Pressione Enter para continuar...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
#endif
}

inline void deletar_arquivo(const char * arquivo) {
    if (remove(arquivo) == 0) {
        cout << "Arquivo excluído com sucesso!" << endl;
    } else {
        perror("Erro ao excluir o arquivo");
    }
}

inline void renomear_arquivo(const char * antigo_nome, const char * novo_nome) {
    if (rename(antigo_nome, novo_nome) == 0) {
        cout << "Arquivo renomeado com sucesso!" << endl;
    } else {
        perror("Erro ao renomear o arquivo");
    }
}

inline void abrir_arquivo(ofstream& output, ifstream& input, const string arquivo) {
    output.open(arquivo, ios_base::out | ios_base::app);
    if (!output.is_open()) {
        cerr << "Erro ao abrir o arquivo " << arquivo << " na gravação\n";
        exit(1);
    }

    input.open(arquivo, ios_base::in);
    if (!input.is_open()) {
        cerr << "Erro ao abrir o arquivo " << arquivo << " na leitura\n";
        exit(1);
    }
}

inline void limpar_buffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

inline void fechar_arquivo(ofstream& output, ifstream& input) {
    output.close();
    input.close();
}

inline bool contemLetras(const string& str) {
    for (char c : str)
        if (isalpha(c))
            return true;
    return false;
}

inline bool contemNumeros(const string& str) {
    for (char c : str)
        if (isdigit(c))
            return true;
    return false;
}

inline void Sleep() { sleep_for(milliseconds(1500)); }

void menu_produto();
void menu_principal();
void menu_cliente();

#endif
