#include "clientes.h"
#include "produtos.h"

int main() {
    #ifdef _WIN32
        ConfigurarAcentuacaoConsole();
    #endif

    menu_principal();
    char opcao;
    cin >> opcao;

    while (opcao != 'S' && opcao != 's') {
        switch (opcao) {
            case 'C':
            case 'c': {
                menu_cliente();
                break;
            }
            case 'P':
            case 'p': {
                menu_produto();
                break;  
            }
            default: {
                LimparTela();
                cerr << "\tOpção inválida\n";
                Sleep();
                break;
            }
        }
        menu_principal();
        cin >> opcao;
    }
}