#include "produtos.h"

void cadastrar_produto(ofstream &output) {
    LimparTela();
    Produto produto;
    cout << "========== Cadastrar produto ==========\n";
    menu_cadastro(produto);
    guardar_produto(output, produto);
    cout << "Cadastro realizado com sucesso\n";
    Sleep();
}

void menu_cadastro(Produto &p) {
    cout << "Código: ";
    cin >> p.codigo;

    while (cin.fail()) {
        limpar_buffer();
        cout << "Digite um código válido (sem letras, símbolos, etc.):";
        cin >> p.codigo;
    }

    cout << "Nome: ";
    limpar_buffer();
    getline(cin, p.nome);

    while (contemNumeros(p.nome)) {
        cout << "Digite um nome válido (sem números, símbolos, etc.): ";
        getline(cin, p.nome);
    }

    cout << "Fornecedor: ";
    getline(cin, p.fornecedor);

    while (contemNumeros(p.fornecedor)) {
        cout << "Digite um fornecedor válido (sem números, símbolos, etc.): ";
        getline(cin, p.fornecedor);
    }

    cout << "Categoria: ";
    getline(cin, p.categoria);

    while (contemNumeros(p.categoria)) {
        cout << "Digite um categoria válido (sem números, símbolos, etc.): ";
        getline(cin, p.categoria);
    }

    cout << "Quantidade: ";
    cin >> p.quantidade;

    while (cin.fail()) {
        limpar_buffer();
        cout << "Digite uma quantidade válida (sem letras, símbolos, etc.):";
        cin >> p.quantidade;
    }

    cout << "Valor unitário: ";
    cin >> p.valor_unitario;

    while (cin.fail()) {
        limpar_buffer();
        cout << "Digite um código válido (sem letras, símbolos, etc.):";
        cin >> p.valor_unitario;
    }
}

void guardar_produto(ofstream &output, const Produto &p) {
    output << p.codigo << endl
           << p.nome << endl
           << p.fornecedor << endl
           << p.categoria << endl
           << p.quantidade << endl
           << p.valor_unitario << endl
           << endl;
}

void listar_produto(ifstream& input) {
    LimparTela();
    Produto produto;

    if (input.peek() == ifstream::traits_type::eof()) {
        cerr << "Nenhum produto cadastrado\n";
        Sleep();
        return;
    }

    cout << "======== Produto(s) Cadastrados ========\n";
    
    while (input >> produto.codigo) {
        input.get();
        getline(input, produto.nome, '\n');
        getline(input, produto.fornecedor, '\n');
        getline(input, produto.categoria, '\n');
        input >> produto.quantidade;
        input >> produto.valor_unitario;
        exibir(produto);
        cout << "========================================\n";
    }
    
    cout << endl;
    pausar();
}

void exibir(const Produto& p) {
    cout << "Código: " << p.codigo << endl;
    cout << "Nome: " << p.nome << endl;
    cout << "Fornecedor: " << p.fornecedor << endl;
    cout << "Categoria: " << p.categoria << endl;
    cout << "Quantidade: " << p.quantidade << endl;
    cout << "Valor unitário: " << p.valor_unitario << endl;
}

void buscar_produto(ifstream& input) {
    LimparTela();
    Produto produto;

    cout << "Digite o código ou nome do produto: ";
    identificador id;
    string alpha_numerico;
    limpar_buffer();
    getline(cin, alpha_numerico);

    if (input.peek() == ifstream::traits_type::eof()) {
        cerr << "Nenhum produto cadastrado\n";
        Sleep();
        return;
    }

    bool produto_encontrado = false;

    while (input >> produto.codigo && produto_encontrado == false) {
        input.get();
        getline(input, produto.nome, '\n');
        getline(input, produto.fornecedor, '\n');
        getline(input, produto.categoria, '\n');
        input >> produto.quantidade;
        input >> produto.valor_unitario;
        input.get();

        id.nome = produto.nome;
        id.codigo = to_string(produto.codigo);

        if (id.nome == alpha_numerico || id.codigo == alpha_numerico) {
            cout << "Produto encontrado com sucesso!\n";
            produto_encontrado = true;
            exibir(produto);
        }
    }

    if (!produto_encontrado)
        cout << "Nenhum produto informado com esse nome ou código fornecido\n";

    pausar();
}

void atualizar_produto(ifstream& input) {
    LimparTela();
    Produto produto;

    cout << "Digite o código ou nome do produto: ";
    identificador id;
    string alpha_numerico;
    limpar_buffer();
    getline(cin, alpha_numerico);

    ofstream arquivo("temp.txt");
    if (!arquivo.is_open()) {
        cerr << "Erro ao abrir o arquivo temp.txt na gravação\n";
        exit(1);
    }

    input.open("storage.txt", ios_base::in);
    if (!input.is_open()) {
        cerr << "Erro ao abrir o arquivo storage.txt na leitura\n";
        exit(1);
    }

    if (input.peek() == ifstream::traits_type::eof()) {
        cerr << "Nenhum produto cadastrado\n";
        Sleep();
        return;
    }

    bool produto_encontrado = false;

    while (input >> produto.codigo && produto_encontrado == false) {
        input.get();
        getline(input, produto.nome, '\n');
        getline(input, produto.fornecedor, '\n');
        getline(input, produto.categoria, '\n');
        input >> produto.quantidade;
        input >> produto.valor_unitario;
        input.get();

        id.nome = produto.nome;
        id.codigo = to_string(produto.codigo);

        if (id.nome == alpha_numerico || id.codigo == alpha_numerico) {
            cout << "Produto encontrado!\n";
            produto_encontrado = true;
            cout << "Digite as informações atualizadas do produto\n";
            menu_cadastro(produto);
            guardar_produto(arquivo, produto);
        } else {
            guardar_produto(arquivo, produto);
        }
    }

    while (input >> produto.codigo) {
        input.get();
        getline(input, produto.nome, '\n');
        input >> produto.fornecedor;
        input.get();
        getline(input, produto.categoria, '\n');
        input >> produto.quantidade;
        input >> produto.valor_unitario;
        input.get();

        guardar_produto(arquivo, produto);
    }

    input.close();
    arquivo.close();

    if (!produto_encontrado) {
        deletar_arquivo("temp.txt");
        cout << "Nenhum produto informado com esse nome ou código fornecido\n";
    } else {
        deletar_arquivo("storage.txt");
        renomear_arquivo("temp.txt", "storage.txt");
        cout << "Produto atualizado com sucesso\n";
    }
    pausar();
}

void excluir_produto(ifstream& input) {
    LimparTela();
    Produto produto;

    cout << "Digite o código ou nome do produto: ";
    identificador id;
    string alpha_numerico;
    limpar_buffer();
    getline(cin, alpha_numerico);

    ofstream arquivo("temp.txt");
    if (!arquivo.is_open()) {
        cerr << "Erro ao abrir o arquivo temp.txt na gravação\n";
        exit(1);
    }

    input.open("storage.txt", ios_base::in);
    if (!input.is_open()) {
        cerr << "Erro ao abrir o arquivo storage.txt na leitura\n";
        exit(1);
    }

    if (input.peek() == ifstream::traits_type::eof()) {
        cerr << "Nenhum produto cadastrado\n";
        Sleep();
        return;
    }

    bool produto_encontrado = false;

    while (input >> produto.codigo && produto_encontrado == false) {
        input.get();
        getline(input, produto.nome, '\n');
        input >> produto.fornecedor;
        input.get();
        getline(input, produto.categoria, '\n');
        input >> produto.quantidade;
        input >> produto.valor_unitario;
        input.get();

        id.nome = produto.nome;
        id.codigo = to_string(produto.codigo);

        if (id.nome == alpha_numerico || id.codigo == alpha_numerico) {
            cout << "Produto encontrado!\n";
            produto_encontrado = true;
        } else {
            guardar_produto(arquivo, produto);
        }
    }

    while (input >> produto.codigo) {
        input.get();
        getline(input, produto.nome, '\n');
        getline(input, produto.fornecedor, '\n');
        getline(input, produto.categoria, '\n');
        input >> produto.quantidade;
        input >> produto.valor_unitario;
        input.get();

        guardar_produto(arquivo, produto);
    }

    input.close();
    arquivo.close();

    if (!produto_encontrado) {
        deletar_arquivo("temp.txt");
        cout << "Nenhum produto informado com esse nome ou código fornecido\n";
    } else {
        deletar_arquivo("storage.txt");
        renomear_arquivo("temp.txt", "storage.txt");
        cout << "Produto excluído com sucesso\n";
    }
    pausar();
}