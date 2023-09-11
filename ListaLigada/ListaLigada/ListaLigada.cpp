#include <iostream>  
  using namespace std;  
  
  // definicao de tipo  
  struct NO {  
          int valor;  
          NO* prox;  
  };  
  
  NO* primeiro = NULL;
  
  // headers  
  void menu();  
  void inicializar();  
  void exibirQuantidadeElementos();  
  void exibirElementos();  
  void inserirElemento();  
  void excluirElemento();  
  void buscarElemento();  
  NO* posicaoElemento(int numero);  
  //--------------------------  
  
  
  int main()  
  {  
          menu();  
  }  
  
  void menu()  
  {  
          int op = 0;  
          while (op != 7) {  
                  system("cls"); // somente no windows  
                  cout << "Menu Lista Ligada";  
                  cout << endl << endl;  
                  cout << "1 - Inicializar Lista \n";  
                  cout << "2 - Exibir quantidade de elementos \n";  
                  cout << "3 - Exibir elementos \n";  
                  cout << "4 - Buscar elemento \n";  
                  cout << "5 - Inserir elemento \n";  
                  cout << "6 - Excluir elemento \n";  
                  cout << "7 - Sair \n\n";  
  
                  cout << "Opcao: ";  
                  cin >> op;  
  
                  switch (op)  
                  {  
                  case 1: inicializar();  
                          break;  
                  case 2: exibirQuantidadeElementos();  
                          break;  
                  case 3: exibirElementos();  
                          break;  
                  case 4: buscarElemento();  
                          break;  
                  case 5: inserirElemento();  
                          break;  
                  case 6: excluirElemento();  
                          break;  
  
                  case 7:  
                          return;  
                  default:  
                          break;  
                  }  
  
                  system("pause"); // somente no windows  
          }  
  }  
  
  void inicializar()  
  {  
  
          // se a lista jÃ¡ possuir elementos  
          // libera a memoria ocupada  
          NO* aux = primeiro;  
          while (aux != NULL) {  
                  NO* paraExcluir = aux;  
                  aux = aux->prox;  
                  free(paraExcluir);  
          }  
  
          primeiro = NULL;
          cout << "Lista inicializada \n";  
  
  }  
  
  void exibirQuantidadeElementos() {  
  
          int nElementos = 0;  
          NO* aux = primeiro;  
          while (aux != NULL) {  
                  nElementos++;  
                  aux = aux->prox;  
          }  
          cout << "Quantidade de elementos: " << nElementos << endl;  
  
  }  
  
  void exibirElementos()  
  {  
          if (primeiro == NULL) {  
                  cout << "Lista vazia \n";  
                  return;  
          }  
          else {  
                  cout << "Elementos: \n";  
                  NO* aux = primeiro;  
                  while (aux != NULL) {  
                          cout << aux->valor << endl;  
                          aux = aux->prox;  
                  }  
          }  
  }  
  
  void inserirElemento()  
  {       
          int Numero;
          cout << "Digite o elemento: \n";
          cin >> Numero;

          //aqui eu perguntei se nao ha nenhum elemento parecido na lista
          if(posicaoElemento(Numero)==NULL){
            // aloca memoria dinamicamente para o novo elemento  
            NO* novo = (NO*)malloc(sizeof(NO));  
            if (novo == NULL)  
            {  
                return;  
            }

            //insere o valor digitado no espaco alocado
            novo->valor=Numero;  
            novo->prox = NULL;
            //os novos valores sempre sao inseridos no final da lista
            //como o ultimo item nao vai apontar para uma proxima variavel
            //a propriedade prox deve ser nula (NULL)
            
            if (primeiro == NULL)  
            {  //caso a lista estivesse vazia
                  primeiro = novo;  
            }  
            else  
            { // procura o final da lista  
              NO* aux = primeiro;  
              while (aux->prox != NULL) {  
                          aux = aux->prox;  
                  }  
                  aux->prox = novo;  
            }
         }
         else{
             cout << "\nEsse valor ja esta na lista \n";
         }
  }  
  
  void excluirElemento() {  
      int NumExc; 
      bool IndiceZero=true; 
      bool apagou=false; 
      cout << "Digite o numero a ser excluido: "; 
      cin >> NumExc; 
      NO* EnderecoAtual = primeiro; //salvar o endereco do primeiro item
      NO* Anterior;
      if(posicaoElemento(NumExc)==NULL){
          cout << "Valor nao encontrado\n";
      }
      while(EnderecoAtual!=NULL&&posicaoElemento(NumExc)!=NULL){ 
          if(IndiceZero==true){
            //O IndiceZero existe apenas para verificar se eh a primeira ocorrencia do loop
              if(EnderecoAtual->valor==NumExc){ 
                  primeiro=EnderecoAtual->prox;
                //caso o primeiro item seja o que eu devo excluir
                //eu defino o segundo endereço como o primeiro endereço e apago o que tava antes
                  free(EnderecoAtual);
                  cout<<"\nSumiu?\n";
                  apagou=true; 
              } 
              else{
                  //eh nescessario salvar o enderco anterior para mudar o seu ponteiro
                  Anterior=EnderecoAtual; 
              } 
  
              IndiceZero=false; 
          } 
          else{
            //verificacao do segundo item em diante
              if(EnderecoAtual->valor==NumExc){ 
                  Anterior->prox=EnderecoAtual->prox;
                //alteracao do ponteiro do anterior para levar
                //ao endereco da sucessora a variavel atual
                  free(EnderecoAtual); 
                  apagou=true; 
              } 
              else{
                //caso nao seja que eu quero apagar
                //guardo esse endereco para usar depois
                  Anterior=EnderecoAtual; 
              } 
          } 
          if(apagou){
            //interromper o loop assim que apagar algum valor
              apagou=false; 
              break; 
          } 
          EnderecoAtual=EnderecoAtual->prox; 
      } 
  }  
  
  void buscarElemento(){
      int NumeroBusca;
      if(primeiro!=NULL){
          
         cout << "Digite o valor que procura: \n";
         cin >> NumeroBusca;
         if(posicaoElemento(NumeroBusca)!=NULL){
             cout <<"\nValor encontrado \n";
         }
         else{
             cout <<"\nEsse valor nao consta na lista \n";
         }
      }
      else{
          cout<<"\nLista vazia\n";
      }
  }
  
  
  
  // retorna um ponteiro para o elemento buscado  
  // ou NULL se o elemento nÃ£o estiver na lista  
  NO* posicaoElemento(int numero)  
  {  
          NO* aux = primeiro;  
          while (aux != NULL) {  
                  if (aux->valor == numero)  
                  {  
                          break;  
                  }  
                  aux = aux->prox;  
          }  
          return aux;  
  }

