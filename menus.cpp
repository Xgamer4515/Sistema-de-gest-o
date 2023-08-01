#include "clientes.h"
#include "produtos.h"

void menu_principal() {
    LimparTela();
    cout << "======== Menu de Gerenciamento ========\n";
    cout << "[C] - Gerenciar clientes\n";
    cout << "[P] - Gerenciar produtos\n";
    cout << "[E] - Gerenciar pedido\n";
    cout << "[S] - Sair\n";
    cout << "=======================================\n";
    cout << "Sua opção: ";
}

void menu_cliente() {
    LimparTela();
    cout << "========== Gerenciar cliente ===========\n";
    cout << "[C] - Cadastrar cliente\n";
    cout << "[L] - Listar cliente\n";
    cout << "[B] - Buscar cliente\n";
    cout << "[A] - Atualizar cliente\n";
    cout << "[E] - Excluir cliente\n";
    cout << "[S] - Sair\n"; 
    cout << "========================================\n";
    cout << "Sua opção: ";
    char opcao;
    cin >> opcao;

    ofstream fout;
    ifstream fin;

    abrir_arquivo(fout, fin, "database.txt");

    switch (opcao) {
        case 'C':
        case 'c': {
            cadastrar_cliente(fout);
            break;
        }
        case 'L':
        case 'l': {
            listar_cliente(fin);
            break;
        }
        case 'B':
        case 'b': {
            buscar_cliente(fin);
            break;
        }
        case 'A':
        case 'a': {
            fechar_arquivo(fout,fin);
            atualizar_cliente(fin);
            break;
        }
        case 'E':
        case 'e': {
            fechar_arquivo(fout,fin);
            excluir_cliente(fin);
            break;
        }
        case 'S':
        case 's': {
            fechar_arquivo(fout, fin);
            return;
        }
        default: {
            LimparTela();
            cerr << "\tOpção inválida\n";
            Sleep();
            break;
        }
    }

    fechar_arquivo(fout, fin);
}

void menu_produto() {
    LimparTela();
    cout << "========== Gerenciar produto ===========\n";
    cout << "[C] - Cadastrar produto\n";
    cout << "[L] - Listar produtos\n";
    cout << "[B] - Buscar produto\n";
    cout << "[A] - Atualizar produto\n";
    cout << "[E] - Excluir produto\n";
    cout << "[S] - Sair\n"; 
    cout << "========================================\n";
    cout << "Sua opção: ";
    char opcao;
    cin >> opcao;

    ofstream print;
    ifstream scan;

    abrir_arquivo(print, scan, "storage.txt");

    switch (opcao) {
        case 'C':
        case 'c': {
            cadastrar_produto(print);
            break;
        }
        case 'L':
        case 'l': {
            listar_produto(scan);
            break;
        }
        case 'B':
        case 'b': {
            buscar_produto(scan);
            break;
        }
        case 'A':
        case 'a': {
            fechar_arquivo(print,scan);
            atualizar_produto(scan);
            break;
        }
        case 'E':
        case 'e': {
            fechar_arquivo(print,scan);
            excluir_produto(scan);
            break;
        }
        case 'S':
        case 's': {
            fechar_arquivo(print, scan);
            return;
        }
        default: {
            LimparTela();
            cerr << "\tOpção inválida\n";
            Sleep();
            break;
        }
    }

    fechar_arquivo(print, scan);
}