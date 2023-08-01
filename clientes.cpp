// clientes.cpp
#include "clientes.h"

void cadastrar_cliente(ofstream &output) {
    LimparTela();
    Cliente cliente;
    cout << "========== Cadastrar cliente ==========\n";
    menu_cadastro(cliente);
    guardar_cliente(output, cliente);
    cout << "Cadastro realizado com sucesso\n";
    Sleep();
}

void menu_cadastro(Cliente &c) {
    cout << "Código: ";
    cin >> c.codigo;

    while (cin.fail()) {
        limpar_buffer();
        cout << "Digite um código válido (sem letras, símbolos, etc.):";
        cin >> c.codigo;
    }

    cout << "Nome: ";
    limpar_buffer();
    getline(cin, c.nome);

    while (contemNumeros(c.nome)) {
        cout << "Digite um nome válido (sem números, símbolos, etc.): ";
        getline(cin, c.nome);
    }

    cout << "Tipo da Pessoa (F para física e J para jurídica): ";
    cin >> c.tipo_pessoa;

    while (c.tipo_pessoa != 'F' && 
           c.tipo_pessoa != 'f' && 
           c.tipo_pessoa != 'J' &&
           c.tipo_pessoa != 'j') {
        cout << "Digite um Tipo de Pessoa válido (F para física e J para jurídica): ";
        cin >> c.tipo_pessoa;
    }

    cout << "CPF: ";
    cin >> c.cpf;

    while (c.cpf.size() != 11 && contemLetras(c.cpf)) {
        cout << "Digite um CPF válido (apenas os 11 números numéricos): ";
        cin >> c.cpf;
    }

    cout << "Telefone: ";
    limpar_buffer();
    getline(cin, c.telefone);

    while (contemLetras(c.telefone)) {
        cout << "Digite um telefone válido (somente números): ";
        getline(cin, c.telefone);
    }

    cout << "\nEndereço do cliente\n\n";

    cout << "Logradouro: ";
    getline(cin, c.endereco.logradouro);

    cout << "Complemento: ";
    getline(cin, c.endereco.complemento);

    cout << "CEP: ";
    getline(cin, c.endereco.cep);

    while (contemLetras(c.endereco.cep) && c.endereco.cep.size() != 8) {
        cout << "Digite um CEP válido (apenas 8 dígitos numéricos): ";
        getline(cin, c.endereco.cep);
    }

    cout << "Bairro: ";
    getline(cin, c.endereco.bairro);

    while (contemNumeros(c.endereco.bairro)) {
        cout << "Digite um bairro válido (somente letras): ";
        getline(cin, c.endereco.bairro);
    }

    cout << "Cidade: ";
    getline(cin, c.endereco.cidade);

    while (contemNumeros(c.endereco.cidade)) {
        cout << "Digite um nome válido (somente letras): ";
        getline(cin, c.endereco.cidade);
    }

    cout << "Estado: ";
    getline(cin, c.endereco.estado);

    while (contemNumeros(c.endereco.estado)) {
        cout << "Digite um nome válido (somente letras): ";
        getline(cin, c.endereco.estado);
    }
}

void guardar_cliente(ofstream &output, const Cliente &c) {
    output << c.codigo << endl
           << c.nome << endl
           << c.tipo_pessoa << endl
           << c.cpf << endl
           << c.telefone << endl
           << c.endereco.logradouro << endl
           << c.endereco.complemento << endl
           << c.endereco.cep << endl
           << c.endereco.bairro << endl
           << c.endereco.cidade << endl
           << c.endereco.estado << endl
           << endl;
}

void listar_cliente(ifstream& input) {
    LimparTela();
    Cliente cliente;

    if(input.peek() == ifstream::traits_type::eof()) {
        cerr << "Nenhum cliente cadastrado\n";
        Sleep();
        return;
    }

    cout << "======== Cliente(s) Cadastrados ========\n";

    while(input >> cliente.codigo) {
        input.get();
        getline(input,cliente.nome,'\n');
        input >> cliente.tipo_pessoa;
        input.get();
        getline(input,cliente.cpf,'\n');
        getline(input,cliente.telefone,'\n');
        getline(input,cliente.endereco.logradouro,'\n');
        getline(input,cliente.endereco.complemento,'\n');
        getline(input,cliente.endereco.cep,'\n');
        getline(input,cliente.endereco.bairro,'\n');
        getline(input,cliente.endereco.cidade,'\n');
        getline(input,cliente.endereco.estado,'\n');

        exibir(cliente);
        cout << "========================================\n";
    }
    cout << endl;
    pausar();
}

void exibir(const Cliente& c) {
    cout << "Código: " << c.codigo << endl;
    cout << "Nome: " << c.nome << endl;
    cout << "Tipo de pessoa: " << c.tipo_pessoa << endl;
    cout << "CPF: " << c.cpf << endl;
    cout << "Telefone: " << c.telefone << endl;
    cout << "Logradouro: " << c.endereco.logradouro << endl;
    cout << "Complemento: " << c.endereco.complemento << endl;
    cout << "CEP: " << c.endereco.cep << endl;
    cout << "Bairro: " << c.endereco.bairro << endl;
    cout << "Cidade: " << c.endereco.cidade << endl;
    cout << "Estado: " << c.endereco.estado << endl; 
}

void buscar_cliente(ifstream& input) {
    LimparTela();
    Cliente cliente;

    cout << "Digite o código ou nome do cliente: ";
    identificador id;
    string alpha_numerico;
    limpar_buffer();
    getline(cin,alpha_numerico);

    if(input.peek() == ifstream::traits_type::eof()) {
        cerr << "Nenhum cliente cadastrado\n";
        Sleep();
        return;
    }

    bool cliente_encontrado = false;

    while(input >> cliente.codigo && cliente_encontrado == false) {
        input.get();
        getline(input,cliente.nome,'\n');
        input >> cliente.tipo_pessoa;
        input.get();
        getline(input,cliente.cpf,'\n');
        getline(input,cliente.telefone,'\n');
        getline(input,cliente.endereco.logradouro,'\n');
        getline(input,cliente.endereco.complemento,'\n');
        getline(input,cliente.endereco.cep,'\n');
        getline(input,cliente.endereco.bairro,'\n');
        getline(input,cliente.endereco.cidade,'\n');
        getline(input,cliente.endereco.estado,'\n');

        id.nome = cliente.nome;
        id.codigo = to_string(cliente.codigo);

        if(id.nome == alpha_numerico || id.codigo == alpha_numerico) {
            cout << "Cliente encontrado com sucesso!\n";
            cliente_encontrado = true;
            exibir(cliente);
        }
    }

    if(!cliente_encontrado)
        cout << "Nenhum cliente informado com esse nome ou código fornecido\n";

    pausar();
}

void atualizar_cliente(ifstream& input) {
    LimparTela();
    Cliente cliente;

    cout << "Digite o código ou nome do cliente: ";
    identificador id;
    string alpha_numerico;
    limpar_buffer();
    getline(cin,alpha_numerico);

    ofstream arquivo("temp.txt");
    if (!arquivo.is_open()) {
        cerr << "Erro ao abrir o arquivo temp.txt na gravação\n";
        exit(1);
    }

    input.open("database.txt", ios_base::in);
    if (!input.is_open()) {
        cerr << "Erro ao abrir o arquivo database.txt na leitura\n";
        exit(1);
    }

    if(input.peek() == ifstream::traits_type::eof()) {
        cerr << "Nenhum cliente cadastrado\n";
        Sleep();
        return;
    }

    bool cliente_encontrado = false;

    while(input >> cliente.codigo && cliente_encontrado == false) {
        input.get();
        getline(input,cliente.nome,'\n');
        input >> cliente.tipo_pessoa;
        input.get();
        getline(input,cliente.cpf,'\n');
        getline(input,cliente.telefone,'\n');
        getline(input,cliente.endereco.logradouro,'\n');
        getline(input,cliente.endereco.complemento,'\n');
        getline(input,cliente.endereco.cep,'\n');
        getline(input,cliente.endereco.bairro,'\n');
        getline(input,cliente.endereco.cidade,'\n');
        getline(input,cliente.endereco.estado,'\n');

        id.nome = cliente.nome;
        id.codigo = to_string(cliente.codigo);

        if(id.nome == alpha_numerico || id.codigo == alpha_numerico) {
            cout << "Cliente encontrado!\n";
            cliente_encontrado = true;
            cout << "Digite as informações atulizadas do cliente\n";
            menu_cadastro(cliente);
            guardar_cliente(arquivo,cliente);
        }
        else {
            guardar_cliente(arquivo,cliente);    
        }        
    }

    while(input >> cliente.codigo) {
        input.get();
        getline(input,cliente.nome,'\n');
        input >> cliente.tipo_pessoa;
        input.get();
        getline(input,cliente.cpf,'\n');
        getline(input,cliente.telefone,'\n');
        getline(input,cliente.endereco.logradouro,'\n');
        getline(input,cliente.endereco.complemento,'\n');
        getline(input,cliente.endereco.cep,'\n');
        getline(input,cliente.endereco.bairro,'\n');
        getline(input,cliente.endereco.cidade,'\n');
        getline(input,cliente.endereco.estado,'\n');

        guardar_cliente(arquivo,cliente);
    }

    input.close();
    arquivo.close();

    if(!cliente_encontrado) {
        deletar_arquivo("temp.txt");
        cout << "Nenhum cliente informado com esse nome ou código fornecido\n";
    } else {
        deletar_arquivo("database.txt");
        renomear_arquivo("temp.txt","database.txt");
        cout << "Cliente atulizado com sucesso\n";
    }
    pausar();    
}

void excluir_cliente(ifstream& input) {
    LimparTela();
    Cliente cliente;

    cout << "Digite o código ou nome do cliente: ";
    identificador id;
    string alpha_numerico;
    limpar_buffer();
    getline(cin,alpha_numerico);

    ofstream arquivo("temp.txt");
    if (!arquivo.is_open()) {
        cerr << "Erro ao abrir o arquivo temp.txt na gravação\n";
        exit(1);
    }

    input.open("database.txt", ios_base::in);
    if (!input.is_open()) {
        cerr << "Erro ao abrir o arquivo database.txt na leitura\n";
        exit(1);
    }

    if(input.peek() == ifstream::traits_type::eof()) {
        cerr << "Nenhum cliente cadastrado\n";
        Sleep();
        return;
    }

    bool cliente_encontrado = false;

    while(input >> cliente.codigo && cliente_encontrado == false) {
        input.get();
        getline(input,cliente.nome,'\n');
        input >> cliente.tipo_pessoa;
        input.get();
        getline(input,cliente.cpf,'\n');
        getline(input,cliente.telefone,'\n');
        getline(input,cliente.endereco.logradouro,'\n');
        getline(input,cliente.endereco.complemento,'\n');
        getline(input,cliente.endereco.cep,'\n');
        getline(input,cliente.endereco.bairro,'\n');
        getline(input,cliente.endereco.cidade,'\n');
        getline(input,cliente.endereco.estado,'\n');

        id.nome = cliente.nome;
        id.codigo = to_string(cliente.codigo);

        if(id.nome == alpha_numerico || id.codigo == alpha_numerico) {
            cout << "Cliente encontrado!\n";
            cliente_encontrado = true;
        }
        else {
            guardar_cliente(arquivo,cliente);    
        }        
    }

    while(input >> cliente.codigo) {
        input.get();
        getline(input,cliente.nome,'\n');
        input >> cliente.tipo_pessoa;
        input.get();
        getline(input,cliente.cpf,'\n');
        getline(input,cliente.telefone,'\n');
        getline(input,cliente.endereco.logradouro,'\n');
        getline(input,cliente.endereco.complemento,'\n');
        getline(input,cliente.endereco.cep,'\n');
        getline(input,cliente.endereco.bairro,'\n');
        getline(input,cliente.endereco.cidade,'\n');
        getline(input,cliente.endereco.estado,'\n');

        guardar_cliente(arquivo,cliente);
    }

    input.close();
    arquivo.close();

    if(!cliente_encontrado) {
        deletar_arquivo("temp.txt");
        cout << "Nenhum cliente informado com esse nome ou código fornecido\n";
    } else {
        deletar_arquivo("database.txt");
        renomear_arquivo("temp.txt","database.txt");
        cout << "Cliente excluído com sucesso\n";
    }
    pausar();
}