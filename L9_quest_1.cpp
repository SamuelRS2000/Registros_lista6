
/*
Lista9 - REGISTROS
QUESTÃO 2
Autor: Samuel Rodrigues dos Santos
Data: 26/06/2024
*/

#include <iostream>
#include <vector>         //Para armazenar os ramais
#include <string>         //Para manilpular strings
#include <regex>          //Usar expressões regular , para facilitar o teste das condições

using namespace std ;

struct Ramais{
    string num_ramal;
    string Categoria;
    string Setor;
    string Edifi_loc;
    string Sala;
    string Respon_ramal;
    string Respon_atest;
};

//Imprime os dados do ramais
void mostrar_ramal(const Ramais& ramal){
      cout << "Ramal: "<< ramal.num_ramal << endl;
      cout << "Categoria: "<< ramal.Categoria << endl;
      cout << "Setor: "<< ramal.Setor << endl;
      cout << "Edifício: "<< ramal.Edifi_loc << endl;
      cout << "Sala: "<< ramal.Sala << endl;
      cout << "Responsável pelo ramal: "<< ramal.Respon_ramal << endl;
      cout << "Responsável pelo atesto: "<< ramal.Respon_atest << endl;
      cout << endl << endl;
}


string selecionar_opcao(){
    // pega a opção selecionada pelo usuario
    string opcao;
    getline(cin, opcao);

    for(char c : opcao){
        if (!isdigit(c))
        {
            return "-1";
        }

    }

   return opcao;
}

vector<Ramais> vec_ramais; // Vetor que vai receber os ramais

//Checa se não existem o novo ramal, com os mesmo parametros (paremetros pesquisados) de um ramal ja cadrastrado

bool ramal_duplicado(Ramais& ramal_new){
    for (int i = 0; i < vec_ramais.size(); i++){
        Ramais& ramal = vec_ramais.at(i);
        // Comparando cada um dos itens do antigos ramais com os ja existe
        if(ramal_new.num_ramal == ramal.num_ramal)
            return true;
        else if(ramal_new.Setor == ramal.Setor)
            return true;
        else if( ramal_new.Edifi_loc == ramal.Edifi_loc)
            return true;
        else if( ramal_new.Respon_ramal == ramal.Respon_ramal)
            return true;
        else if(ramal_new.Respon_atest == ramal.Respon_atest)
            return true;

    }
    return false; //Ramal é novo
}
bool validar_num_ramal(string num_ramal){
    int num_ramal_int  = stoi(num_ramal);
    if(num_ramal_int >= 1000 && num_ramal_int <= 2999)
        return true;
    else return false;
}
bool validar_Categoria(string Categoria){
    int Categoria_int  = stoi(Categoria);
    if(Categoria_int >= 0 && Categoria_int <= 6)
        return true;
    else return false;
}
bool validar_Setor(string Setor){
    regex condicao(R"([a-zA-Z\s]+)"); // Letras maisculas de a até z e A até Z .
    return regex_match(Setor,condicao);
}
bool validar_edificio(string Edificio){
    if(Edificio == "500" || Edificio == "505") return true;
    else return false;
}
bool validar_Sala(string Sala){
    regex condicao(R"(\d{3})"); // Numeros
    return regex_match(Sala,condicao);
}
bool validar_nome(const string& nome){
    regex padrao_nome(R"([a-zA-Z\s]+)");
    // define que podem ser usadas letras maisculas (A-Z) e minusculas (a-z)
    return regex_match(nome, padrao_nome);
}

void adicionar_ramal(Ramais& ramal){
      //-------Numero do ramal
      cout << "Insira o numero do ramal(de 1000 até 2999)" << endl;
      ramal.num_ramal = selecionar_opcao();
      //Validando
      while(!validar_num_ramal(ramal.num_ramal) && (ramal.num_ramal == "-1")){
        cout << "Numero do ramal incorreto \nTente novamente" << endl;
        ramal.num_ramal = selecionar_opcao();
      }

      //-------Categoria
      cout << "Insira a categoria, sendo : " << endl;
      cout << "Categoria 0: não faz ligação." << endl;
      cout << "Categoria 1: ligação interna." << endl;
      cout << "Categoria 2: logação local (fixo)." << endl;
      cout << "Categoria 3: ligação local (fixo e celular)." << endl;
      cout << "Categoria 4: ligação local (fixo) e DDD (fixo)." << endl;
      cout << "Categoria 5: ligação local (fixo e celular) e DDD (fixo e celular)." << endl;
      cout << "Categoria 6: ligação local (fixo e celular), DDD (fixo e celular) e DDI." << endl;
      ramal.Categoria = selecionar_opcao();
      //Validando
      while(!validar_Categoria(ramal.Categoria) && (ramal.Categoria == "-1") ){
        cout << "Categoria incorreta \nTente novamente" << endl;
        ramal.Categoria = selecionar_opcao();
      }

      //-------Setor
      cout << "Insira o Setor do ramal (SIGLA do departamento)" << endl;
      getline(cin,ramal.Setor);
      //Validando
      while(!validar_Setor(ramal.Setor)){
        cout << "Setor incorreto \nTente novamente" << endl;
        getline(cin,ramal.Setor);
      }

      //-------Edificio de localização
      cout << "Insira o edificio (500 ou 505)" << endl;
      cout << "500 - sede\n505 - SEPN 505 Assa" << endl;
      getline(cin,ramal.Edifi_loc);
      //Validando
      while(!validar_edificio(ramal.Edifi_loc)){
        cout << "Edificio errado \nTente novamente" << endl;
        getline(cin,ramal.Edifi_loc);
      }

      //------Sala
      cout << "Insira o numero da sala no padrão:" << endl;
      cout << "abb - a = numero do andar, bb = numero da sala" << endl;
      ramal.Sala = selecionar_opcao();
      //Validando
      while(!validar_Sala(ramal.Sala)  && (ramal.Sala == "-1")){
        cout << "Numero da sala errado \nTente novamente" << endl;
        ramal.Sala = selecionar_opcao();
      }

       //------RESPONSÁVEL PELO RAMAL
      cout << "Insira o nome reponsavel pelo ramal" << endl;
      getline(cin,ramal.Respon_ramal);
      //Validando
      while(!validar_nome(ramal.Respon_ramal)){
        cout << "Nome invalido \nTente novamente" << endl;
        getline(cin,ramal.Respon_ramal);
      }

      //------RESPONSÁVEL PELO ATESTE DE CONTA TELEFÔNICA
      cout << "Insira o nome reponsavel pelo atestado da conta telefônica" << endl;
      getline(cin,ramal.Respon_atest);
      //Validando
      while(!validar_nome(ramal.Respon_atest)){
        cout << "Nome invalido \nTente novamente" << endl;
        getline(cin,ramal.Respon_atest);
      }
      if (!vec_ramais.empty())
          if(ramal_duplicado(ramal)) {
            cout << "Ramal com itens duplicados"<< endl;
            return;}
      //Por fim adicionando a vetor com os ramais
      vec_ramais.push_back(ramal);
      cout << endl << "______________ INFORMAÇÔES GERAIS DO RAMAL________________"<<endl;
      mostrar_ramal(ramal);
}

// Imprime todos os ramais
void mostrar_todos_ramais(){
      for (int i = 0; i < vec_ramais.size(); i++)
      {
          // ciclo de repetição de 0 até o tamanho total da agenda
          const Ramais& ramal = vec_ramais.at(i);
          mostrar_ramal(ramal);
      }
}

int main (){
      while(true){
        Ramais ramal;
        adicionar_ramal(ramal);
      }
           
      return 0;
}
