#include <stdio.h>

#include <stdlib.h>

#include <conio.c>

#include <conio.h>

#include <windows.h>

#include <string.h>

#
define f 1# define fc 9# define fca# define qtdetxt 40# define qtdedig 15

struct not_goto {
  char nomeEmp[qtdetxt], enderecoEmp[qtdetxt], nomeRepresent[qtdetxt], cidadeEmp[qtdetxt], emailEmp[qtdetxt], produto[qtdetxt], cnpj[qtdedig];
  char preco[qtdedig];
  long int chavePrimaria;
  bool ativo; //true or false
  struct tel_emp {
    char tel[qtdedig], ddd[qtdedig];
  }
  telEmp;
}
dadosEmp;

FILE * database;

char resp;
int tst = 1;
char senha[] = {
  "ADM"
};
void janela(int cor, int fundo, int xmax, int xmin, int ymin, int ymax, int cor_clara, int cor_escura, char titulo[50], int cor_titulo_fundo, int cor_titulo_texto);
void painel(int xmax, int xmin, int ymax, int ymin, int cor);
void linha();
void caixalinhas();
void botao(int xmin, int xmax, int ymax, int ymin, int cor, int cor_clara, int cor_escura, int cor_fundo, char texto[50]);
void botaoselecionado(int xmin, int xmax, int ymax, int ymin, int cor, int cor_clara, int cor_escura, int cor_fundo, char texto[50]);
void abrir_arquivo(char[3]);
void limpa_linha(int, int, int, int, int, int);
void atalho_cadastro();
void moldura_superior();
void menu();
void submenu_superior();
void submenu_supOpcoes();
void buffmenu_superiorIn(int, int);
void buffmenu_superiorOut(int, int);
void mascara_cadastro();
void cadastro_botaoPress();
void cadastro_num();
void mascara_fundo();
void botao_cadastrar();
void botao_sair();
void botao_pressionadoCadastrar();
void botao_pressionadoSair();
void atalho_cadastro_selecionado();
void atribuir_chave_primaria();
void cliente_cadastro1();
void cliente_cadastro2();
void confirmacao_cadastro();
void confirmar_novoCadastro();
int isemail(char[qtdetxt], int, int, int);
void mostrar_dados();
void scant(char[qtdetxt], int, int, int);
int strcount(int, int, int, int);
void mascara_consulta_cod();
void botao_pesquisar();
void botao_pesquisar_pressionado();
void mascara_consulta_nome();
void inicio();
void isdigit2(char[qtdedig], int, int, int, int);
void istel(char[qtdedig], int, int, int, int);
void isvalue(char[qtdedig], int, int, int, int);
void consulta_codigo();
void botao_pesquisar_iluminado();
void mascara_login();
void consulta_nome();
void impressao_dados(int);
void consulta_geral();
void sobre();
void digitar_dados_aux();
void altercao();
void alteracao_dados();
void mascara_alteracao();
void mostra_masc_auxiliar();
void func_alt();
void mascara_exclusao();
void exclusao();
void lixeira_dados();
void mascara_reativar();
void mascara_loguin();
int login();

main() {
  inicio();
  Beep(500, 200); //som
  system("cls");
  system("color 3F"); //cor verdinha
  abrir_arquivo("ab+"); //uma funcao que fizemos
  do {
    clrscr(); //limpar a tela
    system("color 3F"); //cor verdinha
    moldura_superior(); //design	
    menu();
  } while (true);
}
// FUNÇÕES AUXILIARES PARA O DESIGN ----------------------------------------------------------------------
void janela(int cor, int fundo, int xmax, int xmin, int ymin, int ymax, int cor_clara, int cor_escura, char titulo[50], int cor_titulo_fundo, int cor_titulo_texto) {
  int x, y;
  for (x = xmin; x <= xmax; x++) {
    for (y = ymin; y <= ymax; y++) {
      gotoxy(x, y);
      textcolor(cor);
      printf("%c", 219);
    }
  }
  //sombra
  for (x = xmin + 1; x <= xmax + 1; x++) {
    gotoxy(x, ymax + 1);
    textbackground(fundo);
    textcolor(0);
    printf("%c", 219);
  }
  for (y = ymin + 1; y <= ymax; y++) {
    gotoxy(xmax + 1, y);
    textbackground(fundo);
    textcolor(0);
    printf("%c", 219);
  }
  //titulo
  for (x = xmin; x <= xmax; x++) {
    gotoxy(x, ymin);
    textcolor(cor_titulo_fundo);
    printf("%c", 219);
  }
  gotoxy(((80 - strlen(titulo)) / 2), ymin);
  textbackground(cor_titulo_fundo);
  textcolor(cor_titulo_texto);
  printf("%s", titulo);

}

void painel(int xmax, int xmin, int ymax, int ymin, int cor) {
  int x, y;
  for (x = xmin; x <= xmax; x++) {
    for (y = ymin; y <= ymax; y++) {
      gotoxy(x, y);
      textcolor(cor);
      printf("%c", 219);
    }
  }
}
void linha(int xmax, int xmin, int linha, int cor, int cor_de_fundo) {
  int x, y;
  for (x = xmin; x <= xmax; x++) {
    gotoxy(x, linha);
    textcolor(cor);
    textbackground(cor_de_fundo);
    printf("%c", 196);
  }
}
void caixalinha(int xmin, int xmax, int ymin, int ymax, int cor_clara, int cor_escura, int cor_fundo) {
  int x, y;
  for (x = xmin; x <= xmax; x++) {
    gotoxy(x, ymin);
    textbackground(cor_fundo);
    textcolor(cor_clara);
    printf("%c", 196);
    gotoxy(x, ymax);
    textbackground(cor_fundo);
    textcolor(cor_escura);
    printf("%c", 196);

  }
  for (y = ymin; y <= ymax; y++) {
    gotoxy(xmin, y);
    textbackground(cor_fundo);
    textcolor(cor_clara);
    printf("%c", 179);
    gotoxy(xmax, y);
    textbackground(cor_fundo);
    textcolor(cor_escura);
    printf("%c", 179);
  }
  gotoxy(xmin, ymin);
  textbackground(cor_fundo);
  textcolor(cor_clara);
  printf("%c", 218);
  gotoxy(xmin, ymax);
  textbackground(cor_fundo);
  textcolor(cor_clara);
  printf("%c", 192);
  gotoxy(xmax, ymax);
  textbackground(cor_fundo);
  textcolor(cor_escura);
  printf("%c", 217);
  gotoxy(xmax, ymin);
  textbackground(cor_fundo);
  textcolor(cor_escura);
  printf("%c", 191);

}

void botao(int xmin, int xmax, int ymax, int ymin, int cor, int cor_clara, int cor_escura, int cor_fundo, char texto[50]) {
  int x, y;
  for (x = xmin; x <= xmax; x++) {
    for (y = ymin; y <= ymax; y++) {
      gotoxy(x, y);
      textcolor(cor);
      printf("%c", 219);
    }
  }
  caixalinha(xmin, xmax, ymin, ymax, cor_clara, cor_escura, cor);
  for (x = xmin + 1; x <= xmax + 1; x++) {
    gotoxy(x, ymax + 1);
    textcolor(0);
    textbackground(cor_fundo);
    printf("%c", 223);

  }
  for (y = ymin + 1; y <= ymax; y++) {
    gotoxy(xmax + 1, y);
    textcolor(0);
    textbackground(cor_fundo);
    printf("%c", 219);
  }
  gotoxy(xmin + 1, ymax - 1);
  textcolor(15);
  textbackground(cor);
  printf("%s", texto);

}
void botaoselecionado(int xmin, int xmax, int ymax, int ymin, int cor, int cor_clara, int cor_escura, int cor_fundo, char texto[50]) {
  int x, y;
  for (x = xmin; x <= xmax; x++) {
    for (y = ymin; y <= ymax; y++) {
      gotoxy(x, y);
      textcolor(cor);
      printf("%c", 219);
    }
  }
  caixalinha(xmin, xmax, ymin, ymax, cor_clara, cor_escura, cor);
  for (x = xmin + 1; x <= xmax + 1; x++) {
    gotoxy(x, ymax + 1);
    textcolor(0);
    textbackground(cor_fundo);
    printf("%c", 223);

  }
  for (y = ymin + 1; y <= ymax; y++) {
    gotoxy(xmax + 1, y);
    textcolor(0);
    textbackground(cor_fundo);
    printf("%c", 219);
  }
  gotoxy(xmin + 1, ymax - 1);
  textcolor(15);
  textbackground(cor);
  printf("%s", texto);
}
//--------------------------------------------------------------------------------------------------------
void limpa_linha(int coluna, int linha, int num_linhas, int coluna_final, int back, int textc) {
  for (int x = 0; x < num_linhas; x++) {
    for (int i = coluna; i <= coluna_final; i++) {
      textbackground(back);
      textcolor(textc);
      gotoxy(i, linha + x);
      printf(" ");
    }
  }
  textcolor(BLACK);
  /*
  Sintaxe: limpa_linha(coluna, linha, total_linhas, coluna_final)
  Funciona como um clreol, mas adicionando um limite:
  Exemplo: limpa_linha(22,1,2,24)
  22 = coluna da limpeza inicial
  1 = linha desejada
  2 = quantidade de linhas (sera adicionado na linha 2 tbm
  24 = coluna que deverá ter o fim, ou seja, a limpeza vai apenas ate 24*/
}

void abrir_arquivo(char modo[3]) {
  if ((database = fopen("database.bin", modo)) == NULL) { //database-nome do arquivo-abre arquivo // modo que esta sendo aberto-binario// modo é 
    gotoxy(0, 0);
    printf("Erro na abertura do arquivo"); //oq esta sendo enviado para funcao rb+, ab+
    exit(1); //se der merda o prgrama fecha
  }
}

void atalho_cadastro() {
  int y, x, aux_login;
  for (x = 4; x <= 9; x++) {
    for (int i = 3; i < 6; i++) {
      gotoxy(x, i);
      textcolor(15);
      printf("%c", 219);
    }
  }
  for (x = 5; x <= 8; x++) {
    for (int i = 3; i < 5; i++) {
      gotoxy(x, i);
      textcolor(0);
      textbackground(15);
      printf("%c", 196);
    }
  }
  for (y = 4; y <= 6; y++) {
    gotoxy(4, y);
    textcolor(0);
    printf("%c", 179);
    gotoxy(8, y);
    textcolor(0);
    printf("%c", 179);
  }
  gotoxy(4, 3);
  textcolor(0);
  printf("%c", 218);
  gotoxy(8, 3);
  textcolor(0);
  printf("%c", 191);
  gotoxy(4, 5);
  textcolor(0);
  printf("%c", 192);
  gotoxy(8, 5);
  textcolor(0);
  printf("%c", 217);
  gotoxy(3, 6);
  textcolor(0);
  textbackground(3);
  printf("Cadastrar");
}

void moldura_superior() {
  //atalho_cadastro();
  for (int x = 1; x < 81; x++) {
    gotoxy(x, 23);
    textcolor(15);
    printf("%c", 219);
    gotoxy(x, 24);
    textcolor(15);
    printf("%c", 219);
    gotoxy(x, 25);
    textcolor(15);
    printf("%c", 219);
    gotoxy(x, 25);
    textcolor(0);
    textbackground(15);
    printf("%c", 196);
    gotoxy(x, 23);
    textcolor(7);
    printf("%c", 196);
  }
  for (int y = 23; y <= 25; y++) {
    gotoxy(1, y);
    textcolor(7);
    printf("%c", 179);
    gotoxy(80, y);
    textcolor(0);
    printf("%c", 179);
  }
  gotoxy(80, 23);
  textcolor(0);
  printf("%c", 191);
  gotoxy(1, 23);
  textcolor(7);
  printf("%c", 218);
  gotoxy(1, 25);
  textcolor(7);
  printf("%c", 192);
  gotoxy(80, 25);
  textcolor(0);
  printf("%c", 217);
}

void menu() {
  int coluna = 3; // coluna inicial, CADASTRO
  int opcao = 1, x, y, aux_login;
  for (int x = 1; x <= 80; x++) {
    gotoxy(x, 1);
    textcolor(15);
    printf("%c", 219); //barra de menus branquinha 
  }
  gotoxy(2, 24);
  textcolor(0);
  textbackground(15);
  printf("[ENTER] SELECIONAR | [D] DIREITA | [A] ESQUERDA | [W] CIMA | [S] BAIXO");
  gotoxy(3, 1);
  printf(" CADASTRO ");
  gotoxy(16, 1);
  printf(" CONSULTA ");
  gotoxy(29, 1);
  printf(" ALTERACAO ");
  gotoxy(42, 1);
  printf(" EXCLUSAO ");
  gotoxy(55, 1);
  printf(" LIXEIRA ");
  gotoxy(68, 1);
  printf(" SAIR ");
  x = 3;
  y = 1;
  sobre();
  do { //esse do vai fazer com que o menu vire funcional, com as teclas do teclado
    // o submeno contem 6 opcoes, quando vc tecla para direita 'D' a sua variavel soma +1, ou seja, opcao++,se for para 
    //esquerda 'A' é a variavel -1, ou seja, opcao--;
    textcolor(15);
    textbackground(9);
    buffmenu_superiorIn(opcao, coluna);
    fflush(stdin); //Limpa do buff do teclado
    gotoxy(80, 24);
    do {
      resp = getch();
      //strlwr(resp);
    } while (resp != 'a' && resp != 'A' && resp != 's' && resp != 'S' && resp != 'D' && resp != 'd' && resp != 13);
    if (opcao == 2 && resp == 's') {
      submenu_superior();
    }
    textcolor(0);
    textbackground(15);
    buffmenu_superiorOut(opcao, coluna);
    if (resp == 77 || resp == 'd' || resp == 'D') {
      coluna += 13; // De cada opcao é de 13 espaços para chegar em outra opção
      if (coluna > 68) { //ultima coluna é 68 , SAIR->CADASTRO
        coluna = 3;
        opcao = 1;
      } else {
        opcao++;
      }
    }
    if (resp == 75 || resp == 'A' || resp == 'a') {
      coluna -= 13;
      if (coluna < 3) { //CADASTRO->SAIR
        coluna = 68;
        opcao = 6;
      } else {
        opcao--;
      }
    }
    if (opcao == 2) { //consulta
      submenu_supOpcoes();
    }
    if (opcao == 1 || opcao == 3) {
      limpa_linha(10, 2, 10, 35, 3, 0);
      sobre();
    }
  } while (resp != 13); //Enquanto tecla != de ENTER, 13 É ENTENDER DA TABELA ASCII
  switch (opcao) {
  case 1:
    do {
      mascara_cadastro();
      cliente_cadastro1();
      cadastro_botaoPress();
      mascara_fundo();
      cadastro_num();
    } while (tst == 1);
    return;
    break;
    //case 2:
  case 3:
    alteracao_dados();
    break;
  case 4:
    exclusao();
    break;
  case 5:
    mascara_loguin();
    aux_login = login();
    if (aux_login == 0)
      break;
    lixeira_dados();
    break;
  case 6:
    fclose(database);
    exit(1);
    break;
  }
}

void submenu_superior() {
  int opcao2 = 1, linha = 3;
  for (int y = 2; y <= 10; y++) {
    gotoxy(29, y);
    textcolor(0);
    printf("%c", 219);
  }
  for (int x = 11; x <= 29; x++) {
    gotoxy(x, 11);
    textbackground(1);
    textcolor(0);
    printf("%c", 219);
  }
  for (int y = 2; y <= 9; y++) {
    gotoxy(10, y);
    textbackground(15);
    textcolor(7);
    printf("%c", 179);
  }
  gotoxy(14, 10);
  textcolor(0);
  printf("%c", 192);
  for (int x = 11; x <= 28; x++) {
    gotoxy(x, 10);
    printf("%c", 196);
  }
  for (int y = 2; y <= 9; y++) {
    gotoxy(28, y);
    printf("%c", 179);
  }
  gotoxy(28, 10);
  printf("%c", 217);
  for (int x = 11; x <= 28; x++) {
    gotoxy(x, 2);
    textcolor(7);
    printf("%c", 196);
  }
  gotoxy(10, 2);
  textcolor(7);
  printf("%c", 218);
  gotoxy(28, 2);
  textcolor(0);
  printf("%c", 191);
  gotoxy(29, 8);
  textbackground(0);
  textcolor(8);
  printf("G");
  gotoxy(29, 9);
  textbackground(0);
  textcolor(8);
  printf("o");
  gotoxy(29, 10);
  textbackground(0);
  textcolor(8);
  printf("e");
  gotoxy(29, 5);
  textbackground(0);
  textcolor(8);
  printf("I");
  gotoxy(11, 11);
  textbackground(0);
  textcolor(8);
  printf("onsavel por desenvo");
  textbackground(15);
  if (resp == 's' || resp == 'S') {
    do {
      gotoxy(12, linha);
      textcolor(0);
      printf("%c", 175);
      Beep(500, 200);
      fflush(stdin);
      gotoxy(80, 24);
      resp = getch();
      gotoxy(12, linha);
      textcolor(15);
      printf("%c", 175);
      if (resp == 'w' || resp == 'W') {
        if (opcao2 == 6)
          linha -= 2;
        else
          linha -= 1;
        if (linha < 3) {
          linha = 9;
          opcao2 = 6;
        } else {
          opcao2--;
        }
      }
      if (resp == 's' || resp == 'S') {
        if (opcao2 == 5)
          linha += 2;
        else
          linha += 1;
        if (linha > 9) {
          linha = 3;
          opcao2 = 1;
        } else {
          opcao2++;
        }
      }
      if (resp == 'd' || resp == 'D' || resp == 'A' || resp == 'a') {
        opcao2 = 0;
        break;
        return;
      }
    } while (resp != 13);
    switch (opcao2) {
    case 1:
      mascara_consulta_cod();
      consulta_codigo();
      break;
    case 2:
      mascara_consulta_nome();
      consulta_nome();
      break;
    case 3:
      consulta_geral();
      break;
    case 4:
      break;
    case 5:
      break;
    }
  }
}

void submenu_supOpcoes() {
  int linha = 3;
  for (int x = 10; x <= 28; x++) {
    gotoxy(x, 2);
    textcolor(15);
    printf("%c", 219);
    gotoxy(x, 3);;
    printf("%c", 219);
    gotoxy(15, 3);
    textcolor(BLACK);
    printf("POR CODIGO");
    gotoxy(x, 4);
    textcolor(15);
    printf("%c", 219);
    gotoxy(15, 4);
    textcolor(BLACK);
    printf("POR NOME");
    gotoxy(x, 5);
    textcolor(15);
    printf("%c", 219);
    gotoxy(15, 5);
    textcolor(BLACK);
    printf("GERAL");
    gotoxy(x, 6);
    textcolor(15);
    printf("%c", 219);
    gotoxy(15, 6);
    textcolor(BLACK);
    printf("------");
    gotoxy(x, 7);
    textcolor(15);
    printf("%c", 219);
    gotoxy(15, 7);
    textcolor(BLACK);
    printf("------");
    gotoxy(x, 8);
    textcolor(15);
    printf("%c", 219);
    gotoxy(x, 8);
    textcolor(BLACK);
    printf("%c", 196);
    gotoxy(x, 9);
    textcolor(15);
    printf("%c", 219);
    gotoxy(15, 9);
    textcolor(BLACK);
    printf("------");
    gotoxy(x, 10);
    textcolor(15);
    printf("%c", 219);
  }
  submenu_superior();
}

void buffmenu_superiorIn(int opcao, int coluna) {
  if (opcao == 1) {
    gotoxy(coluna, 1);
    printf(" CADASTRO ");
    Beep(500, 200);
  } else if (opcao == 2) {
    gotoxy(coluna, 1);
    printf(" CONSULTA ");
    Beep(500, 200);
  } else if (opcao == 3) {
    gotoxy(coluna, 1);
    printf(" ALTERACAO ");
    Beep(500, 200);
  } else if (opcao == 4) {
    gotoxy(coluna, 1);
    printf(" EXCLUSAO ");
    Beep(500, 200);
  } else if (opcao == 5) {
    gotoxy(coluna, 1);
    printf(" LIXEIRA ");
    Beep(500, 200);
  } else {
    gotoxy(coluna, 1);
    printf(" SAIR ");
    Beep(500, 200);
  }
  /*Atua no menu superior. Ao mudar de opcao, tem a funcao de
  trocar de background, ou seja, de branco para azul escuro,
  aplicando um efeito de selecao*/
}

void buffmenu_superiorOut(int opcao, int coluna) {
  if (opcao == 1) {
    gotoxy(coluna, 1);
    printf(" CADASTRO ");
  } else if (opcao == 2) {
    gotoxy(coluna, 1);
    printf(" CONSULTA ");
  } else if (opcao == 3) {
    gotoxy(coluna, 1);
    printf(" ALTERACAO ");
  } else if (opcao == 4) {
    gotoxy(coluna, 1);
    printf(" EXCLUSAO ");
  } else if (opcao == 5) {
    gotoxy(coluna, 1);
    printf(" LIXEIRA ");
  } else {
    gotoxy(coluna, 1);
    printf(" SAIR ");
  }
  /*Atua como na buffmenu_superiorIn, porem ao inves de trocar
  de cor para azul escuro, volta a cor original (branca)*/
}

void mascara_fundo() {
  // x 5 até 79
  // y 4 até 20
  for (int x = 5; x <= 79; x++) {
    for (int y = 4; y <= 20; y++) {
      gotoxy(x, y);
      textcolor(f);
      printf("%c", 219);
    }
  }
  for (int y = 5; y <= 21; y++) {
    gotoxy(80, y);
    textcolor(0);
    printf("%c", 219);
  }
  for (int x = 6; x <= 80; x++) {
    gotoxy(x, 21);
    textcolor(0);
    printf("%c", 223);
  }
  for (int x = 6; x <= 78; x++) {
    gotoxy(x, 20);
    textbackground(f);
    textcolor(0);
    printf("%c", 196);
    gotoxy(x, 4);
    textbackground(f);
    textcolor(15);
    printf("%c", 196);
  }
  for (int y = 4; y <= 19; y++) {
    gotoxy(79, y);
    textbackground(f);
    textcolor(0);
    printf("%c", 179);
    gotoxy(5, y);
    textbackground(f);
    textcolor(15);
    printf("%c", 179);
  }
  gotoxy(79, 20);
  textbackground(f);
  textcolor(0);
  printf("%c", 217);
  gotoxy(79, 4);
  textbackground(f);
  textcolor(0);
  printf("%c", 191);
  gotoxy(5, 20);
  textbackground(f);
  textcolor(15);
  printf("%c", 192);
  gotoxy(5, 4);
  textbackground(f);
  textcolor(15);
  printf("%c", 218);
  //---------------------------------------------------------------
}

void mascara_cadastro() {
  // x 5 até 79
  // y 4 até 20
  janela(1, 3, 79, 5, 4, 20, 15, 0, "CADASTRO", 9, 15);
  caixalinha(4, 79, 5, 20, 15, 0, 1);
  //---------------------------------------------------------------
  botao(65, 75, 18, 16, 3, 15, 0, 1, "PROXIMO");
  gotoxy(7, 6);
  textcolor(15);
  textbackground(f);
  printf("Nome da Empresa.....: ");
  for (int x = 30; x <= 70; x++) {
    textcolor(15);
    gotoxy(x, 6);
    printf("%c", 219);
  }
  gotoxy(7, 8);
  textcolor(15);
  textbackground(f);
  printf("Endereco............: ");
  for (int x = 30; x <= 70; x++) {
    textcolor(15);
    gotoxy(x, 8);
    printf("%c", 219);
  }
  gotoxy(7, 10);
  textcolor(15);
  textbackground(f);
  printf("E-mail..............: ");
  for (int x = 30; x <= 70; x++) {
    textcolor(15);
    gotoxy(x, 10);
    printf("%c", 219);
  }
  gotoxy(7, 12);
  textcolor(15);
  textbackground(f);
  printf("Telefone............: ");
  for (int x = 30; x <= 43; x++) {
    textcolor(15);
    gotoxy(x, 12);
    printf("%c", 219);
  }
  textcolor(BLACK);
  textbackground(15); //gotoxy(30,12);printf("[  ]");
  gotoxy(30, 12);
  printf("(  )");
  gotoxy(7, 14);
  textcolor(15);
  textbackground(f);
  printf("Representante.......: ");
  for (int x = 30; x <= 70; x++) {
    textcolor(15);
    gotoxy(x, 14);
    printf("%c", 219);
  }
  gotoxy(7, 16);
  textcolor(15);
  textbackground(f);
  printf("CNPJ................: ");
  for (int x = 30; x <= 44; x++) {
    textcolor(15);
    gotoxy(x, 16);
    printf("%c", 219);
  }
  gotoxy(46, 16);
  textcolor(15);
  textbackground(f);
  printf("(14 digitos)");
  gotoxy(7, 18);
  textcolor(15);
  textbackground(f);
  printf("Cidade..............: ");
  for (int x = 30; x <= 63; x++) {
    textcolor(15);
    gotoxy(x, 18);
    printf("%c", 219);
  }
}

void cadastro_botaoPress() { //botão pressionado da área de cadastro
  char resp;
  for (int x = 65; x <= 75; x++) {
    gotoxy(x, 16);
    textcolor(11);
    printf("%c", 219);
    gotoxy(x, 17);
    textcolor(11);
    printf("%c", 219);
    gotoxy(x, 18);
    textcolor(11);
    printf("%c", 219);
  }
  for (int x = 65; x <= 75; x++) {
    gotoxy(x, 18);
    textcolor(0);
    textbackground(11);
    printf("%c", 196);
    gotoxy(x, 16);
    textcolor(15);
    textbackground(11);
    printf("%c", 196);
  }
  gotoxy(75, 17);
  textcolor(0);
  textbackground(11);
  printf("%c", 179);
  gotoxy(65, 17);
  textcolor(15);
  textbackground(11);
  printf("%c", 179);
  gotoxy(75, 16);
  textcolor(0);
  textbackground(11);
  printf("%c", 191);
  gotoxy(75, 18);
  textcolor(0);
  textbackground(11);
  printf("%c", 217);
  gotoxy(65, 18);
  textcolor(15);
  textbackground(11);
  printf("%c", 192);
  gotoxy(65, 16);
  textcolor(15);
  textbackground(11);
  printf("%c", 218);
  gotoxy(66, 17);
  textcolor(15);
  textbackground(11);
  printf("PROXIMO");
  do {
    resp = getch();
  } while (resp != 13);
  if (resp == 13) { //13 = enter
    for (int x = 65; x <= 75; x++) {
      gotoxy(x, 16);
      textcolor(3);
      printf("%c", 219);
      gotoxy(x, 17);
      textcolor(3);
      printf("%c", 219);
      gotoxy(x, 18);
      textcolor(3);
      printf("%c", 219);
    }
    gotoxy(66, 17);
    textcolor(15);
    textbackground(3);
    printf("PROXIMO");
    for (int x = 65; x <= 75; x++) {
      gotoxy(x, 18);
      textcolor(15);
      printf("%c", 196);
      gotoxy(x, 16);
      textcolor(0);
      printf("%c", 196);
    }
    gotoxy(75, 17);
    textcolor(15);
    printf("%c", 179);
    gotoxy(65, 17);
    textcolor(0);
    printf("%c", 179);
    gotoxy(75, 16);
    textcolor(15);
    printf("%c", 191);
    gotoxy(75, 18);
    textcolor(15);
    printf("%c", 217);
    gotoxy(65, 18);
    textcolor(0);
    printf("%c", 192);
    gotoxy(65, 16);
    textcolor(0);
    printf("%c", 218);
    Sleep(1);

  }
}
void cadastro_num() {
  int x;
  gotoxy(7, 6);
  textcolor(15);
  textbackground(f);
  printf("Sistema.............: ");
  for (int x = 30; x <= 70; x++) {
    for (int i = 6; i < 7; i++) {
      textcolor(15);
      gotoxy(x, i);
      printf("%c", 219);
    }
  }
  gotoxy(7, 14);
  textcolor(15);
  textbackground(f);
  printf("Valor Produto.....R$: ");
  for (int x = 30; x <= 70; x++) {
    gotoxy(x, 14);
    printf("%c", 219);
  }
  for (int y = 8; y < 13; y++) {
    for (int x = 7; x < 40; x++) {
      textcolor(15);
      textbackground(15);
      gotoxy(x, y);
      printf("%c", 219);
    }
  }
  gotoxy(8, 8);
  textcolor(0);
  textbackground(15);
  printf("     Siglas para Sistemas");
  gotoxy(8, 9);
  textcolor(0);
  textbackground(15);
  printf("S.V1 - Sistema de vendas");
  gotoxy(8, 10);
  textcolor(0);
  textbackground(15);
  printf("S.G1 - Sistema de gerenciamento");
  gotoxy(8, 11);
  textcolor(0);
  textbackground(15);
  printf("S.C1 - Sistema de cadastros");
  gotoxy(8, 12);
  textcolor(0);
  textbackground(15);
  printf("S.Web - Website");
  botao_sair();
  botao_cadastrar();
  cliente_cadastro2();

  gotoxy(66, 17);
  textcolor(15);
  textbackground(11);
  printf("CADASTRAR");
  x = 2;
  char resp2;

  //char resp2;
  do {
    resp2 = getch();
    if (resp2 == 'a' || resp2 == 'A') {
      gotoxy(66, 17);
      textcolor(15);
      textbackground(3);
      printf("CADASTRAR");
      gotoxy(57, 17);
      textcolor(15);
      textbackground(11);
      printf("SAIR");
      x = 1;
    } else if (resp2 == 'd' || resp2 == 'D') {
      gotoxy(66, 17);
      textcolor(15);
      textbackground(11);
      printf("CADASTRAR");
      gotoxy(57, 17);
      textcolor(15);
      textbackground(3);
      printf("SAIR");
      x = 2;
    }
  } while (resp2 != 13);

  if (resp2 == 13) {
    if (x == 2) {
      for (int x = 65; x <= 75; x++) {
        for (int i = 16; i < 19; i++) {
          gotoxy(x, i);
          textcolor(3);
          printf("%c", 219);
        }
      }
      gotoxy(66, 17);
      textcolor(15);
      textbackground(3);
      printf("CADASTRAR");
      for (int x = 65; x <= 75; x++) {
        gotoxy(x, 18);
        textcolor(15);
        printf("%c", 196);
        gotoxy(x, 16);
        textcolor(0);
        printf("%c", 196);
      }
      gotoxy(75, 17);
      textcolor(15);
      printf("%c", 179);
      gotoxy(65, 17);
      textcolor(0);
      printf("%c", 179);
      gotoxy(75, 16);
      textcolor(15);
      printf("%c", 191);
      gotoxy(75, 18);
      textcolor(15);
      printf("%c", 217);
      gotoxy(65, 18);
      textcolor(0);
      printf("%c", 192);
      gotoxy(65, 16);
      textcolor(0);
      printf("%c", 218);
      Sleep(1);
      confirmacao_cadastro();
      confirmar_novoCadastro();
    }
    if (x == 1) {
      for (int x = 56; x <= 62; x++) {
        for (int i = 16; i < 19; i++) {
          gotoxy(x, i);
          textcolor(3);
          printf("%c", 219);
        }
      }
      gotoxy(57, 17);
      textcolor(15);
      textbackground(3);
      printf("SAIR");
      gotoxy(62, 17);
      textcolor(15);
      printf("%c", 179);
      gotoxy(56, 17);
      textcolor(0);
      printf("%c", 179);
      for (int x = 56; x <= 62; x++) {
        gotoxy(x, 16);
        textcolor(0);
        printf("%c", 196);
        gotoxy(x, 18);
        textcolor(15);
        printf("%c", 196);
      }
      gotoxy(62, 16);
      textcolor(15);
      printf("%c", 191);
      gotoxy(62, 18);
      textcolor(15);
      printf("%c", 217);
      gotoxy(56, 16);
      textcolor(0);
      printf("%c", 218);
      gotoxy(56, 18);
      textcolor(0);
      printf("%c", 192);
      Sleep(1);
      system("cls");

      moldura_superior();
      menu();
    }
  }
}

void botao_cadastrar() {
  for (int x = 65; x <= 75; x++) {
    textcolor(3);
    gotoxy(x, 16);
    printf("%c", 219);
    gotoxy(x, 17);
    printf("%c", 219);
    gotoxy(x, 18);
    printf("%c", 219);
  }
  gotoxy(66, 17);
  textcolor(15);
  textbackground(3);
  printf("CADASTRAR");
  for (int x = 65; x <= 75; x++) {
    gotoxy(x, 18);
    textcolor(0);
    printf("%c", 196);
    gotoxy(x, 16);
    textcolor(15);
    printf("%c", 196);
  }
  gotoxy(75, 17);
  textcolor(0);
  printf("%c", 179);
  gotoxy(65, 17);
  textcolor(15);
  printf("%c", 179);
  gotoxy(75, 16);
  textcolor(0);
  printf("%c", 191);
  gotoxy(75, 18);
  textcolor(0);
  printf("%c", 217);
  gotoxy(65, 18);
  textcolor(15);
  printf("%c", 192);
  gotoxy(65, 16);
  textcolor(15);
  printf("%c", 218);
  for (int x = 66; x <= 76; x++) {
    gotoxy(x, 19);
    textcolor(0);
    textbackground(1);
    printf("%c", 223);
  }
  for (int y = 17; y <= 18; y++) {
    gotoxy(76, y);
    textcolor(0);
    printf("%c", 219);
  }
}
void botao_sair() {
  for (int x = 56; x <= 62; x++) {
    for (int i = 16; i < 19; i++) {
      gotoxy(x, i);
      textcolor(3);
      printf("%c", 219);
    }
  }
  gotoxy(57, 17);
  textcolor(15);
  textbackground(3);
  printf("SAIR");
  gotoxy(62, 17);
  textcolor(0);
  printf("%c", 179);
  gotoxy(56, 17);
  textcolor(15);
  printf("%c", 179);
  for (int x = 56; x <= 62; x++) {
    gotoxy(x, 16);
    textcolor(15);
    printf("%c", 196);
    gotoxy(x, 18);
    textcolor(0);
    printf("%c", 196);
  }
  gotoxy(62, 16);
  textcolor(0);
  printf("%c", 191);
  gotoxy(62, 18);
  textcolor(0);
  printf("%c", 217);
  gotoxy(56, 16);
  textcolor(15);
  printf("%c", 218);
  gotoxy(56, 18);
  textcolor(15);
  printf("%c", 192);
  for (int x = 57; x <= 63; x++) {
    gotoxy(x, 19);
    textcolor(0);
    textbackground(1);
    printf("%c", 223);
  }
  for (int y = 17; y <= 18; y++) {
    gotoxy(63, y);
    textcolor(0);
    textbackground(1);
    printf("%c", 219);
  }
}
void botao_pressionadoCadastrar() {
  char resp;
  for (int x = 65; x <= 75; x++) {
    gotoxy(x, 16);
    textcolor(11);
    printf("%c", 219);
    gotoxy(x, 17);
    textcolor(11);
    printf("%c", 219);
    gotoxy(x, 18);
    textcolor(11);
    printf("%c", 219);
  }
  for (int x = 65; x <= 75; x++) {
    gotoxy(x, 18);
    textcolor(0);
    textbackground(11);
    printf("%c", 196);
    gotoxy(x, 16);
    textcolor(15);
    textbackground(11);
    printf("%c", 196);
  }
  gotoxy(75, 17);
  textcolor(0);
  textbackground(11);
  printf("%c", 179);
  gotoxy(65, 17);
  textcolor(15);
  textbackground(11);
  printf("%c", 179);
  gotoxy(75, 16);
  textcolor(0);
  textbackground(11);
  printf("%c", 191);
  gotoxy(75, 18);
  textcolor(0);
  textbackground(11);
  printf("%c", 217);
  gotoxy(65, 18);
  textcolor(15);
  textbackground(11);
  printf("%c", 192);
  gotoxy(65, 16);
  textcolor(15);
  textbackground(11);
  printf("%c", 218);
  gotoxy(66, 17);
  textcolor(15);
  textbackground(11);
  printf("CADASTRAR");
  resp = getch();
  if (resp == 13) { //13 = enter
    for (int x = 65; x <= 75; x++) {
      gotoxy(x, 16);
      textcolor(3);
      printf("%c", 219);
      gotoxy(x, 17);
      textcolor(3);
      printf("%c", 219);
      gotoxy(x, 18);
      textcolor(3);
      printf("%c", 219);
    }
    gotoxy(66, 17);
    textcolor(15);
    textbackground(3);
    printf("CADASTRAR");
    for (int x = 65; x <= 75; x++) {
      gotoxy(x, 18);
      textcolor(15);
      printf("%c", 196);
      gotoxy(x, 16);
      textcolor(0);
      printf("%c", 196);
    }
    gotoxy(75, 17);
    textcolor(15);
    printf("%c", 179);
    gotoxy(65, 17);
    textcolor(0);
    printf("%c", 179);
    gotoxy(75, 16);
    textcolor(15);
    printf("%c", 191);
    gotoxy(75, 18);
    textcolor(15);
    printf("%c", 217);
    gotoxy(65, 18);
    textcolor(0);
    printf("%c", 192);
    gotoxy(65, 16);
    textcolor(0);
    printf("%c", 218);
    Sleep(1);
  }
}

void atalho_cadastro_selecionado() {
  int y, x;
  for (x = 4; x <= 9; x++) {
    for (int i = 3; i < 8; i++) {
      gotoxy(x, i);
      textcolor(15);
      printf("%c", 219);
    }
  }
  for (x = 5; x <= 8; x++) {
    gotoxy(x, 3);
    textcolor(0);
    textbackground(15);
    printf("%c", 196);
    gotoxy(x, 7);
    textcolor(0);
    textbackground(15);
    printf("%c", 196);
    gotoxy(x, 5);
    textcolor(0);
    textbackground(15);
    printf("%c", 196);
    gotoxy(x, 4);
    textcolor(0);
    textbackground(15);
    printf("%c", 196);
    gotoxy(x, 6);
    textcolor(0);
    textbackground(15);
    printf("%c", 196);
  }
  //
  for (x = 3; x <= 10; x++) {
    gotoxy(x, 2);
    textcolor(7);
    printf("%c", 196);
    gotoxy(x, 8);
    textcolor(7);
    printf("%c", 196);
  }
  for (y = 5; y <= 8; y++) {
    gotoxy(3, y);
    textcolor(0);
    textbackground(7);
    printf("%c", 179);
    gotoxy(10, y);
    textcolor(0);
    textbackground(7);
    printf("%c", 179);
  }
  //
  for (y = 4; y <= 6; y++) {
    gotoxy(4, y);
    textcolor(0);
    printf("%c", 179);
    gotoxy(8, y);
    textcolor(0);
    printf("%c", 179);
  }
  gotoxy(4, 3);
  textcolor(0);
  printf("%c", 218);
  gotoxy(8, 3);
  textcolor(0);
  printf("%c", 191);
  gotoxy(4, 7);
  textcolor(0);
  printf("%c", 192);
  gotoxy(8, 7);
  textcolor(0);
  printf("%c", 217);
  gotoxy(9, 7);
  textcolor(0);
  printf("%c", 197);
  gotoxy(3, 8);
  textcolor(0);
  textbackground(3);
  printf("Cadastrar");
}

void atribuir_chave_primaria() {
  int aux, ff;
  rewind(database); //aponta o ponteiro para o começo do arquivo
  do {
    ff = 0;
    while (fread( & dadosEmp, sizeof(dadosEmp), 1, database) == 1); //&&dadosEmp.chavePrimaria!=aux)
    //aux++;
    dadosEmp.chavePrimaria++;
    if (dadosEmp.chavePrimaria == aux && dadosEmp.ativo == false)
      ff = 1;
  } while (ff == 1);
  //percorre todo o arquivo atribuindo um codigo /UNICO/ para determinado cadastro
  //todos os cadastros deverão ser maiores que 4000
  //Ex: 4432
}

void cliente_cadastro1() {
  int m = 0;
  atribuir_chave_primaria();
  textcolor(0);
  textbackground(15);
  fflush(stdin);
  scant(dadosEmp.nomeEmp, 30, 6, 70); //gotoxy(30,6);gets(dadosEmp.nomeEmp);
  fflush(stdin);
  scant(dadosEmp.enderecoEmp, 30, 8, 70); //gotoxy(30,8);gets(dadosEmp.enderecoEmp);
  do {
    textbackground(15);
    gotoxy(30, 10);
    gets(dadosEmp.emailEmp);
    strlwr(dadosEmp.emailEmp);
    isemail(dadosEmp.emailEmp, 30, 10, 70);
    m = isemail(dadosEmp.emailEmp, 30, 10, 70);
  } while (m == 0);
  fflush(stdin);
  gotoxy(31, 12);
  istel(dadosEmp.telEmp.ddd, 2, 31, 12, 0);
  textcolor(BLACK);
  gotoxy(33, 12);
  printf(")");
  fflush(stdin);
  gotoxy(34, 12);
  istel(dadosEmp.telEmp.tel, 10, 34, 12, 0);
  fflush(stdin);
  scant(dadosEmp.nomeRepresent, 30, 14, 70);
  fflush(stdin);
  gotoxy(30, 16);
  isdigit2(dadosEmp.cnpj, 14, 30, 16, 0);
  fflush(stdin);
  scant(dadosEmp.cidadeEmp, 30, 18, 63);
  dadosEmp.ativo = true;
}

void cliente_cadastro2() {
  textcolor(0);
  textbackground(15);
  scant(dadosEmp.produto, 30, 6, 70);
  //limpa_linha(30,8,1,70,15,15);
  gotoxy(30, 8);
  isvalue(dadosEmp.preco, 15, 30, 14, 0);
  fflush(stdin);
}

int isemail(char a[40], int col, int lin, int fim) {
  int check = 0;
  int i;
  do {
    for (i = 0; i < strlen(dadosEmp.emailEmp); i++) {
      if (a[i] == '@') {
        check++;
        break;
      }
    }
    for (; i < strlen(dadosEmp.emailEmp); i++) {

      if (a[i] == '.') {
        check++;
        break;
      }
    }
    if (check != 2) {
      check = 0;
      limpa_linha(col, lin, 1, fim, 15, 15);
      textcolor(BLACK);
      return 0;
    } else
      return 1;
  } while (check != 2);
}

void confirmacao_cadastro() {
  /*Neste ponto deve ser colocado o design da tela de seleção de salvamento ou não*/
  int x, y;
  char tecla;
  int opcao = 1;
  // Design
  janela(3, 1, 56, 26, 6, 17, 15, 0, "CONFIRMAR CADASTRO?", 9, 15);
  caixalinha(26, 56, 7, 17, 15, 0, 3);
  botao(27, 32, 14, 12, 1, 15, 0, 3, "SIM");
  botao(45, 50, 14, 12, 4, 15, 0, 3, "NAO");
  x = 2;
  char resp2;
  //char resp2;
  botao(27, 32, 14, 12, 11, 15, 0, 3, "SIM");
  do {
    resp2 = getch();
    if (resp2 == 'a' || resp2 == 'A') {
      botao(27, 32, 14, 12, 11, 15, 0, 3, "SIM");
      botao(45, 50, 14, 12, 4, 15, 0, 3, "NAO");
      x = 2;
    } else if (resp2 == 'd' || resp2 == 'D') {
      botao(27, 32, 14, 12, 1, 15, 0, 3, "SIM");
      botao(45, 50, 14, 12, 12, 15, 0, 3, "NAO");
      x = 1;
    }
  } while (resp2 != 13);
  if (resp2 == 13) {
    if (x == 2) {
      botao(45, 50, 14, 12, 4, 0, 15, 3, "NAO");
      Sleep(1);
      if (fwrite( & dadosEmp, sizeof(dadosEmp), 1, database) != 1) {
        //Caso der erro, no caso é essa condição, tentar colocar o aviso dentro da janela central
        gotoxy(32, 7);
        printf("Erro na leitura de dados");
        gotoxy(32, 6);
        printf("Sistema finalizado por seguranca");
        exit(1);
      } else {
        //mostrar uma mensagem na tela que os dados foram salvos com sucesso
        //fflush(database); 
        gotoxy(27, 20);
        printf("Dados salvo com sucesso");
        //confirmar_novoCadastro();
        return;
      }
    } else if (x = 1) {
      botao(27, 32, 14, 12, 1, 0, 15, 3, "SIM");
      Sleep(1);
      return;
    }
  }
  return;
}
void confirmar_novoCadastro() {
  char resp2;
  int x = 2, y, resp = 2;
  janela(3, 1, 55, 25, 6, 17, 15, 0, "REALIZAR NOVO CADASTRO?", 9, 15);
  caixalinha(26, 54, 7, 16, 15, 0, 3);
  botao(27, 32, 14, 12, 1, 15, 0, 3, "SIM");
  botao(45, 50, 14, 12, 4, 15, 0, 3, "NAO");
  botao(27, 32, 14, 12, 9, 15, 0, 3, "SIM");
  do {
    resp2 = getch();
    if (resp2 == 'a' || resp2 == 'A') {
      botao(27, 32, 14, 12, 9, 15, 0, 3, "SIM");
      botao(45, 50, 14, 12, 4, 15, 0, 3, "NAO");
      resp = 2;
    } else if (resp2 == 'd' || resp2 == 'D') {
      botao(27, 32, 14, 12, 1, 15, 0, 3, "SIM");
      botao(45, 50, 14, 12, 12, 15, 0, 3, "NAO");
      resp = 1;
    }
  } while (resp2 != 13);
  if (resp2 == 13) {
    if (resp == 2) {
      botao(45, 50, 14, 12, 4, 0, 15, 3, "NAO");
      Sleep(1);
      tst = 1;
      return;
    } else if (resp = 1) {
      botao(27, 32, 14, 12, 1, 0, 15, 3, "SIM");
      Sleep(1);
      tst = 0;
      return;
    }
  }
}

//FUNÇÃO DE TESTE DE ARQUIVOS
void mostrar_dados() {
  clrscr();
  fclose(database);
  if ((database = fopen("database.bin", "rb")) == NULL) {
    gotoxy(18, 11);
    printf("Erro na abertura do arquivo");
    exit(1);
  } else {
    while (!feof(database)) {
      if (fread( & dadosEmp, sizeof(dadosEmp), 1, database) == 1 && dadosEmp.ativo == true) {
        clrscr();
        gotoxy(10, 8);
        printf("%d", dadosEmp.chavePrimaria);
        gotoxy(10, 9);
        puts(dadosEmp.nomeEmp);
        gotoxy(10, 10);
        printf("%s", dadosEmp.nomeRepresent);
        gotoxy(10, 11);
        printf("%s", dadosEmp.produto);
        gotoxy(10, 12);
        printf("%s", dadosEmp.emailEmp);
        gotoxy(10, 13);
        printf("%s", dadosEmp.cnpj);
        //gotoxy(18,8);puts(agenda.email);
        gotoxy(10, 14);
        printf("Pressione uma tecla para continuar...");
        fflush(stdin);
        getch();
      }
    }
    fclose(database);
  }
}

void scant(char str[qtdetxt], int col, int lin, int fim) { //função para ler strings já com consistencia
  int total = 0, result;
  do {
    total = 0;
    gotoxy(col, lin);
    gets(str);
    strupr(str); //deixar os caracteres digitados em maisculo
    while (str[total] != '\0') //verifica quantos caracteres tem 
      total++;
    if (total > 1 && (strcount(total, col, lin, fim)) == 1)
      return;
    limpa_linha(col, lin, 1, fim, 15, 15);
  } while (true);
}

int strcount(int total, int col, int lin, int fim) {
  int d, j, i = col;
  if ((total + col) > fim) {
    d = ((total + col) / 80) + 1;
    for (int j = 0; j < d; j++) {
      if (j % 2 == 0)
        i = col;
      else
        i = 1;
      for (i; i < 81; i++) {
        gotoxy(i, j + lin);
        textcolor(1);
        printf("%c", 219);
      }
      for (int x = 1; x < 5; x++) {
        if ((j + lin) == 6)
          gotoxy(x, (j + lin) + 1);
        else
          gotoxy(x, (j + lin));
        textcolor(3);
        printf("%c", 219);
      }
    }
    if (lin == 18) {

    }
    //reconstrução da borda
    for (int y = 5; y <= 21; y++) {
      gotoxy(80, y);
      textcolor(0);
      printf("%c", 219);
    }
    for (int x = 6; x <= 80; x++) {
      gotoxy(x, 21);
      textbackground(3);
      textcolor(0);
      printf("%c", 223);
    }
    for (int x = 6; x <= 78; x++) {
      gotoxy(x, 20);
      textbackground(f);
      textcolor(0);
      printf("%c", 196);
      gotoxy(x, 4);
      textbackground(f);
      textcolor(15);
      printf("%c", 196);
    }
    for (int y = 4; y <= 19; y++) {
      gotoxy(79, y);
      textbackground(f);
      textcolor(0);
      printf("%c", 179);
      gotoxy(5, y);
      textbackground(f);
      textcolor(15);
      printf("%c", 179);
    }
    return 0; // ta errado e tem que limpar os caracters que ultrapassou o campo definido.
  } else return 1; // tudo ok 
}
void mascara_consulta_cod() {
  // x 5 até 79
  // y 4 até 20
  for (int x = 5; x <= 79; x++) {
    for (int y = 4; y <= 20; y++) {
      gotoxy(x, y);
      textcolor(f);
      printf("%c", 219);
    }
  }
  for (int y = 5; y <= 21; y++) {
    gotoxy(80, y);
    textcolor(0);
    printf("%c", 219);
  }
  for (int x = 6; x <= 80; x++) {
    gotoxy(x, 21);
    textbackground(3);
    textcolor(0);
    printf("%c", 223);
  }
  for (int x = 6; x <= 78; x++) {
    gotoxy(x, 20);
    textbackground(f);
    textcolor(0);
    printf("%c", 196);
    gotoxy(x, 4);
    textbackground(f);
    textcolor(15);
    printf("%c", 196);
  }
  for (int y = 4; y <= 19; y++) {
    gotoxy(79, y);
    textbackground(f);
    textcolor(0);
    printf("%c", 179);
    gotoxy(5, y);
    textbackground(f);
    textcolor(15);
    printf("%c", 179);
  }
  gotoxy(79, 20);
  textbackground(f);
  textcolor(0);
  printf("%c", 217);
  gotoxy(79, 4);
  textbackground(f);
  textcolor(0);
  printf("%c", 191);
  gotoxy(5, 20);
  textbackground(f);
  textcolor(15);
  printf("%c", 192);
  gotoxy(5, 4);
  textbackground(f);
  textcolor(15);
  printf("%c", 218);
  //---------------------------------------------------------------
  gotoxy(18, 5);
  printf("________________CONSULTA POR CODIGO__________________");
  gotoxy(7, 7);
  printf("Codigo da empresa:");
  int x;
  for (x = 26; x <= 50; x++) {
    gotoxy(x, 7);
    textcolor(15);
    printf("%c", 219);
  }
  //----------------------------------------
  for (x = 7; x <= 78; x++) {
    for (int y = 11; y <= 19; y++) {
      gotoxy(x, y);
      textcolor(15);
      printf("%c", 219);
    }

  }
  textbackground(15);
  for (int x = 7; x <= 77; x++) {
    gotoxy(x, 19);
    textbackground(15);
    textcolor(0);
    printf("%c", 196);
    gotoxy(x, 11);
    textbackground(15);
    textcolor(7);
    printf("%c", 196);
  }
  for (int y = 11; y <= 18; y++) {
    gotoxy(78, y);
    textbackground(15);
    textcolor(0);
    printf("%c", 179);
    gotoxy(7, y);
    textbackground(15);
    textcolor(7);
    printf("%c", 179);
  }
  textbackground(15);
  gotoxy(78, 19);
  textcolor(0);
  printf("%c", 217);
  gotoxy(78, 11);
  textcolor(0);
  printf("%c", 191);
  gotoxy(7, 19);
  textcolor(7);
  printf("%c", 192);
  gotoxy(7, 11);
  textcolor(7);
  printf("%c", 218);
  //botao_pesquisar();
}

void botao_pesquisar() {
  int x, y;
  char resp;

  for (x = 53; x <= 63; x++) {
    for (y = 7; y <= 9; y++) {
      gotoxy(x, y);
      textbackground(15);
      textcolor(3);
      printf("%c", 219);
    }
  }
  gotoxy(53, 7);
  textcolor(15);
  textbackground(3);
  printf("%c", 218);
  gotoxy(53, 8);
  textcolor(15);
  textbackground(3);
  printf("%c", 179);
  gotoxy(53, 9);
  textcolor(15);
  textbackground(3);
  printf("%c", 192);
  gotoxy(63, 7);
  textcolor(0);
  textbackground(3);
  printf("%c", 191);
  gotoxy(63, 8);
  textcolor(0);
  textbackground(3);
  printf("%c", 179);
  gotoxy(63, 9);
  textcolor(0);
  textbackground(3);
  printf("%c", 217);
  for (x = 54; x <= 62; x++) {
    gotoxy(x, 7);
    textcolor(15);
    textbackground(3);
    printf("%c", 196);
    gotoxy(x, 9);
    textcolor(0);
    textbackground(3);
    printf("%c", 196);
  }
  gotoxy(54, 8);
  textcolor(15);
  textbackground(3);
  printf("PESQUISAR");
  for (x = 54; x <= 64; x++) {
    gotoxy(x, 10);
    textbackground(1);
    textcolor(0);
    printf("%c", 223);
  }
  for (y = 8; y <= 9; y++) {
    gotoxy(64, y);
    textcolor(0);
    textbackground(2);
    printf("%c", 219);
  }
}
void botao_pesquisar_iluminado() {
  int x, y;
  gotoxy(53, 7);
  textcolor(15);
  textbackground(11);
  printf("%c", 218);
  gotoxy(53, 8);
  textcolor(15);
  textbackground(11);
  printf("%c", 179);
  gotoxy(53, 9);
  textcolor(15);
  textbackground(11);
  printf("%c", 192);
  gotoxy(63, 7);
  textcolor(0);
  textbackground(11);
  printf("%c", 191);
  gotoxy(63, 8);
  textcolor(0);
  textbackground(11);
  printf("%c", 179);
  gotoxy(63, 9);
  textcolor(0);
  textbackground(11);
  printf("%c", 217);
  for (x = 54; x <= 62; x++) {
    gotoxy(x, 7);
    textcolor(15);
    textbackground(11);
    printf("%c", 196);
    gotoxy(x, 9);
    textcolor(0);
    textbackground(11);
    printf("%c", 196);
  }
  for (x = 53; x <= 63; x++) {
    for (y = 7; y <= 9; y++) {
      gotoxy(x, y);
      textcolor(11);
      printf("%c", 219);
    }
  }
  gotoxy(53, 7);
  textcolor(0);
  textbackground(11);
  printf("%c", 218);
  gotoxy(53, 8);
  textcolor(0);
  textbackground(11);
  printf("%c", 179);
  gotoxy(53, 9);
  textcolor(0);
  textbackground(11);
  printf("%c", 192);
  gotoxy(63, 7);
  textcolor(15);
  textbackground(11);
  printf("%c", 191);
  gotoxy(63, 8);
  textcolor(15);
  textbackground(11);
  printf("%c", 179);
  gotoxy(63, 9);
  textcolor(15);
  textbackground(11);
  printf("%c", 217);
  for (x = 54; x <= 62; x++) {
    gotoxy(x, 7);
    textcolor(0);
    textbackground(11);
    printf("%c", 196);
    gotoxy(x, 9);
    textcolor(15);
    textbackground(11);
    printf("%c", 196);
  }
  gotoxy(54, 8);
  textcolor(15);
  textbackground(11);
  printf("PESQUISAR");
  for (x = 54; x <= 64; x++) {
    gotoxy(x, 10);
    textbackground(1);
    textcolor(0);
    printf("%c", 223);
  }
  for (y = 8; y <= 9; y++) {
    gotoxy(64, y);
    textcolor(0);
    textbackground(2);
    printf("%c", 219);
  }
}
void botao_pesquisar_pressionado() {
  int x, y;
  gotoxy(53, 7);
  textcolor(0);
  textbackground(11);
  printf("%c", 218);
  gotoxy(53, 8);
  textcolor(0);
  textbackground(11);
  printf("%c", 179);
  gotoxy(53, 9);
  textcolor(0);
  textbackground(11);
  printf("%c", 192);
  gotoxy(63, 7);
  textcolor(15);
  textbackground(11);
  printf("%c", 191);
  gotoxy(63, 8);
  textcolor(15);
  textbackground(11);
  printf("%c", 179);
  gotoxy(63, 9);
  textcolor(15);
  textbackground(11);
  printf("%c", 217);
  for (x = 54; x <= 62; x++) {
    gotoxy(x, 7);
    textcolor(0);
    textbackground(11);
    printf("%c", 196);
    gotoxy(x, 9);
    textcolor(15);
    textbackground(11);
    printf("%c", 196);
  }
  for (x = 53; x <= 63; x++) {
    for (y = 7; y <= 9; y++) {
      gotoxy(x, y);
      textcolor(11);
      printf("%c", 219);
    }
  }
  gotoxy(53, 7);
  textcolor(15);
  textbackground(11);
  printf("%c", 218);
  gotoxy(53, 8);
  textcolor(15);
  textbackground(11);
  printf("%c", 179);
  gotoxy(53, 9);
  textcolor(15);
  textbackground(11);
  printf("%c", 192);
  gotoxy(63, 7);
  textcolor(0);
  textbackground(11);
  printf("%c", 191);
  gotoxy(63, 8);
  textcolor(0);
  textbackground(11);
  printf("%c", 179);
  gotoxy(63, 9);
  textcolor(0);
  textbackground(11);
  printf("%c", 217);
  for (x = 54; x <= 62; x++) {
    gotoxy(x, 7);
    textcolor(15);
    textbackground(11);
    printf("%c", 196);
    gotoxy(x, 9);
    textcolor(0);
    textbackground(11);
    printf("%c", 196);
  }
  gotoxy(54, 8);
  textcolor(15);
  textbackground(11);
  printf("PESQUISAR");
  for (x = 54; x <= 64; x++) {
    gotoxy(x, 10);
    textbackground(1);
    textcolor(0);
    printf("%c", 223);
  }
  for (y = 8; y <= 9; y++) {
    gotoxy(64, y);
    textcolor(0);
    textbackground(2);
    printf("%c", 219);
  }
}
void mascara_consulta_nome() {
  // x 5 até 79
  // y 4 até 20
  for (int x = 5; x <= 79; x++) {
    for (int y = 4; y <= 20; y++) {
      gotoxy(x, y);
      textcolor(f);
      printf("%c", 219);
    }
  }
  for (int y = 5; y <= 21; y++) {
    gotoxy(80, y);
    textcolor(0);
    printf("%c", 219);
  }
  for (int x = 6; x <= 80; x++) {
    gotoxy(x, 21);
    textbackground(3);
    textcolor(0);
    printf("%c", 223);
  }
  for (int x = 6; x <= 78; x++) {
    gotoxy(x, 20);
    textbackground(f);
    textcolor(0);
    printf("%c", 196);
    gotoxy(x, 4);
    textbackground(f);
    textcolor(15);
    printf("%c", 196);
  }
  for (int y = 4; y <= 19; y++) {
    gotoxy(79, y);
    textbackground(f);
    textcolor(0);
    printf("%c", 179);
    gotoxy(5, y);
    textbackground(f);
    textcolor(15);
    printf("%c", 179);
  }
  gotoxy(79, 20);
  textbackground(f);
  textcolor(0);
  printf("%c", 217);
  gotoxy(79, 4);
  textbackground(f);
  textcolor(0);
  printf("%c", 191);
  gotoxy(5, 20);
  textbackground(f);
  textcolor(15);
  printf("%c", 192);
  gotoxy(5, 4);
  textbackground(f);
  textcolor(15);
  printf("%c", 218);
  //---------------------------------------------------------------
  gotoxy(18, 5);
  printf("________________CONSULTA POR NOME__________________");
  gotoxy(7, 7);
  printf("Nome da empresa:");
  int x;
  for (x = 26; x <= 50; x++) {
    gotoxy(x, 7);
    textcolor(15);
    printf("%c", 219);
  }
  //----------------------------------------
  for (x = 7; x <= 78; x++) {
    for (int y = 11; y <= 19; y++) {
      gotoxy(x, y);
      textcolor(15);
      printf("%c", 219);
    }

  }
  textbackground(15);
  for (int x = 7; x <= 77; x++) {
    gotoxy(x, 19);
    textbackground(15);
    textcolor(0);
    printf("%c", 196);
    gotoxy(x, 11);
    textbackground(15);
    textcolor(7);
    printf("%c", 196);
  }
  for (int y = 11; y <= 18; y++) {
    gotoxy(78, y);
    textbackground(15);
    textcolor(0);
    printf("%c", 179);
    gotoxy(7, y);
    textbackground(15);
    textcolor(7);
    printf("%c", 179);
  }
  textbackground(15);
  gotoxy(78, 19);
  textcolor(0);
  printf("%c", 217);
  gotoxy(78, 11);
  textcolor(0);
  printf("%c", 191);
  gotoxy(7, 19);
  textcolor(7);
  printf("%c", 192);
  gotoxy(7, 11);
  textcolor(7);
  printf("%c", 218);
  botao_pesquisar();
  //getche();
}

void inicio() {
  system("color 0F"); //trocar a cor do sistema "verdinho" // carregamento // entrada  
  int x, y;
  for (y = 5; y <= 15; y++) {
    gotoxy(20, y);
    textcolor(15);
    printf("%c", 219);
    gotoxy(21, y);
    textcolor(15);
    printf("%c", 219);
  }
  gotoxy(20, 17);
  textcolor(15);
  textbackground(0);
  printf("%c", 223);
  gotoxy(21, 17);
  textcolor(15);
  textbackground(0);
  printf("%c", 223);
  for (y = 5; y <= 15; y++) {
    gotoxy(25, y);
    textcolor(15);
    printf("%c", 219);
    gotoxy(26, y);
    textcolor(15);
    printf("%c", 219);
  }
  //
  for (x = 25; x <= 40; x++) {
    gotoxy(x, 5);
    textcolor(15);
    printf("%c", 219);
    gotoxy(x, 15);
    textcolor(15);
    printf("%c", 219);
  }
  for (y = 13; y <= 15; y++) {
    gotoxy(40, y);
    textcolor(15);
    printf("%c", 219);
    gotoxy(39, y);
    textcolor(15);
    printf("%c", 219);
  }
  for (x = 35; x <= 40; x++) {
    gotoxy(x, 12);
    textcolor(15);
    printf("%c", 219);
  }
  //
  for (x = 45; x <= 60; x++) {
    gotoxy(x, 5);
    textcolor(15);
    printf("%c", 219);
    gotoxy(x, 15);
    textcolor(15);
    printf("%c", 219);
  }
  for (y = 5; y <= 15; y++) {
    gotoxy(45, y);
    textcolor(15);
    printf("%c", 219);
    gotoxy(44, y);
    textcolor(15);
    printf("%c", 219);
  }
  for (y = 5; y <= 15; y++) {
    gotoxy(60, y);
    textcolor(15);
    printf("%c", 219);
    gotoxy(59, y);
    textcolor(15);
    printf("%c", 219);
  }
  //
  for (x = 65; x <= 80; x++) {
    gotoxy(x, 5);
    textcolor(15);
    printf("%c", 219);
  }
  for (y = 5; y <= 10; y++) {
    gotoxy(80, y);
    textcolor(15);
    printf("%c", 219);
    gotoxy(79, y);
    textcolor(15);
    printf("%c", 219);
  }
  for (x = 65; x <= 80; x++) {
    gotoxy(x, 10);
    textcolor(15);
    printf("%c", 219);
  }
  for (y = 10; y <= 15; y++) {
    gotoxy(65, y);
    textcolor(15);
    printf("%c", 219);
    gotoxy(66, y);
    textcolor(15);
    printf("%c", 219);
  }
  for (x = 65; x <= 80; x++) {
    gotoxy(x, 15);
    textcolor(15);
    printf("%c", 219);
  }
  gotoxy(20, 18);
  textcolor(9);
  printf("!GO2 - EMPRESARIAL - GERENCIAMENTO DE CLIENTES");
  gotoxy(33, 19);
  textcolor(12);
  printf("SISTEMAS EMPRESARIAIS INFORMATIZADOS");
  gotoxy(35, 25);
  textcolor(15);
  printf("@!GO2 TODOS OS DIREITOS RESERVADOS");
  for (x = 30; x <= 70; x++) {
    gotoxy(x, 20);
    textcolor(15);
    printf("%c", 219);
  }
  for (x = 30; x <= 70; x++) {
    gotoxy(x, 20);
    textcolor(3);
    printf("%c", 219);
    Sleep(100);
    if (x == 30) {
      gotoxy(40, 22);
      textcolor(10);
      printf("%c  Carregando Buffer", 223);

    }
    if (x == 35) {
      gotoxy(40, 22);
      clreol();
      textcolor(10);
      printf("%c  Carregando Banco de Dados", 223);

    }
    if (x == 40) {
      gotoxy(40, 22);
      clreol();
      textcolor(10);
      printf("%c  Carregando Interface Grafica", 223);

    }
    if (x == 45) {
      gotoxy(40, 22);
      clreol();
      textcolor(10);
      printf("%c  Conectando com o servidor", 223);

    }
    if (x == 50) {
      gotoxy(40, 22);
      clreol();
      textcolor(10);
      printf("%c  Carregando Cadastros Salvos", 223);

    }
    if (x == 55) {
      gotoxy(40, 22);
      clreol();
      textcolor(10);
      printf("%c  Verificando Validade da Memoria", 223);

    }
    if (x == 65) {
      gotoxy(40, 22);
      clreol();
      textcolor(10);
      printf("%c  Iniciando", 223);
    }
  }
}

void isdigit2(char str[qtdedig], int max, int col, int lin, int lin2) {
  char aux;
  do {
    limpa_linha(col, lin, 1, max + col, 15, 15);
    for (int i = 0; i < max; i++) {
      do {
        gotoxy(col + i, lin);
        printf(" ");
        str[i] = getche();
        if (isdigit(str[i]))
          break;
      } while (true);
    }
    gotoxy(14, lin2 + lin + 1);
    textcolor(15);
    textbackground(RED);
    printf("<BACKSPACE p/ corrigir - ENTER p/ continuar>");
    textcolor(0);
    textbackground(15);
    gotoxy(80, 24);
    do {
      aux = getch();
    } while (aux != 8 && aux != 13);
    limpa_linha(14, lin2 + lin + 1, 1, 14 + 44, f, f);
    textcolor(0);
    textbackground(15);
    if (aux == 13) return;
  } while (true);
  //textcolor(BLACK);gotoxy(33,lin);printf(")");
}

void istel(char str[qtdedig], int max, int col, int lin, int lin2) {
  int aux, aux2;
  do {
    limpa_linha(col, lin, 1, max + col, 15, 15);
    textcolor(0);
    if (lin2 == 0) {
      gotoxy(33, lin);
      printf(")");
    }
    for (int i = 0; i < max; i++) {
      do {
        gotoxy(col + i, lin);
        if (i == 5) {
          str[i] = '-';
          printf("-");
          break;
        } else {
          printf(" ");
          str[i] = getche();
          if (isdigit(str[i]))
            break;
          if (i == 7 && str[i] == 13)
            return;
        }
      } while (true);
    }
    gotoxy(14, lin2 + lin + 1);
    textcolor(15);
    textbackground(RED);
    printf("<BACKSPACE p/ corrigir - ENTER p/ continuar>");
    textcolor(0);
    textbackground(15);
    gotoxy(80, 24);
    do {
      aux = getch();
    } while (aux != 8 && aux != 13);
    limpa_linha(14, lin2 + lin + 1, 1, 14 + 44, f, f);
    textcolor(0);
    textbackground(15);
    if (aux == 13) return;
  } while (true);
}

void isvalue(char str[qtdedig], int max, int col, int lin, int lin2) {
  char aux;
  do {
    limpa_linha(col, lin, 1, max + col, 15, 15);
    textcolor(0);
    for (int i = 0; i < max; i++) {
      do {
        gotoxy(col + i, lin);
        printf(" ");
        str[i] = getche();
        if (i == 0 && str[i] == 0);
        else
        if (isdigit(str[i]) || str[i] == 44 || str[i] == 46)
          break;
        else if (i > 0 && str[i] == 13)
          break;
      } while (true);
      if (i > 0 && str[i] == 13)
        break;
    }
    gotoxy(14, lin2 + lin + 1);
    textcolor(15);
    textbackground(RED);
    printf("<BACKSPACE p/ corrigir - ENTER p/ continuar>");
    textcolor(0);
    textbackground(15);
    gotoxy(80, 24);
    do {
      aux = getch();
    } while (aux != 8 && aux != 13);
    limpa_linha(14, lin2 + lin + 1, 1, 14 + 44, f, f);
    textcolor(0);
    textbackground(15);
    if (aux == 13) return;
  } while (true);
}

void consulta_codigo() {
  int m, aux = 0;
  char teste;
  do {
    aux = 0;
    do {
      botao_pesquisar();
      textcolor(0);
      textbackground(15);
      do {
        limpa_linha(26, 7, 1, 50, 15, 15);
        textcolor(0);
        textbackground(15);
        gotoxy(26, 7);
        scanf("%d", & m);
      } while (m < 1 || m > 100);
      botao_pesquisar_iluminado();
      //teste=getch();
      //if(teste==13){
      botao_pesquisar_pressionado();
      break;
      //}
    } while (true);
    rewind(database);
    while (!feof(database)) { //enquanto nao estiver no final no arquivo, faco isso 
      if (fread( & dadosEmp, sizeof(dadosEmp), 1, database) == 1 && dadosEmp.chavePrimaria == m && dadosEmp.ativo == true) {
        impressao_dados(0);
        aux = 1;
      }
    }
    if (aux == 0) {
      textcolor(0);
      textbackground(15);
      gotoxy(20, 12);
      printf("CADASTRO NAO EXISTE");
    }
    textcolor(15);
    textbackground(RED);
    gotoxy(8, 22);
    printf("<ENTER p/ retornar ao menu - BACKSPACE p/ procurar novo cadastro>");
    textcolor(0);
    textbackground(15);
    gotoxy(80, 24);
    do {
      teste = getch();
    } while (teste != 8 && teste != 13);
    limpa_linha(8, 22, 1, 80, 3, 3);
    limpa_linha(8, 12, 7, 75, 15, 15);
    textcolor(0);
    textbackground(15);
    if (teste == 13) return;
  } while (true);
}

void mascara_login() {
  system("color 3F");
  int x, y;
  for (x = 35; x <= 45; x++) {
    for (y = 5; y <= 15; y++) {
      gotoxy(x, y);
      textcolor(7);
      printf("%c", 219);
    }
  }
}

void consulta_nome() {
  char str[qtdetxt], teste, aux2;
  int cont = 0, total = 0, aux = 0, x, y;
  textcolor(0);
  textbackground(15);
  gotoxy(7, 11);
  printf("|   EMPRESA   | REPRESENTANTE |   CIDADE   |   PRODUTO |   TELEFONE    |");

  do {
    for (y = 12; y <= 17; y++) {
      gotoxy(7, y);
      printf("%c", 179);
      gotoxy(21, y);
      printf("%c", 179);
      gotoxy(37, y);
      printf("%c", 179);
      gotoxy(50, y);
      printf("%c", 179);
      gotoxy(62, y);
      printf("%c", 179);

    }
    for (x = 7; x <= 77; x++) {
      gotoxy(x, 24);
      printf("%c", 196);
    }
    //aux2=0;
    aux = 0;
    total = 0;
    cont = 0;
    //for(int i=0;i<qtdetxt;i++)
    //	str2[i]=' ';
    textbackground(15);
    textcolor(0);
    limpa_linha(26, 7, 1, 50, 15, 0);
    gotoxy(26, 7);
    gets(str);
    while (str[total] != '\0')
      total++;
    strupr(str);

    rewind(database); //vai voltar no inicio do arquivo
    while (!feof(database)) {
      aux = 0;
      if (fread( & dadosEmp, sizeof(dadosEmp), 1, database) == 1 && dadosEmp.ativo == true) {
        strupr(dadosEmp.nomeEmp); //colocar para maíusculo
        if (strstr(dadosEmp.nomeEmp, str) != NULL) { //compara duas strings - NULL = LIXO
          textcolor(0);
          textbackground(15);
          gotoxy(10, 12 + cont);
          printf("%s ", dadosEmp.nomeEmp);
          gotoxy(24, 12 + cont);
          printf("%s ", dadosEmp.nomeRepresent);
          gotoxy(40, 12 + cont);
          printf("%s ", dadosEmp.cidadeEmp);
          gotoxy(51, 12 + cont);
          printf("%s ", dadosEmp.produto);
          gotoxy(63, 12 + cont);
          printf("(%s)%s ", dadosEmp.telEmp.ddd, dadosEmp.telEmp.tel);
          if (cont == 6) {
            limpa_linha(8, 22, 1, 80, 3, 3);
            textcolor(15);
            textbackground(RED);
            gotoxy(8, 22);
            printf("<Tecle algo para avancar a pagina>");
            getch();
            textcolor(0);
            textbackground(15);
            for (y = 12; y <= 17; y++) {
              gotoxy(7, y);
              printf("%c", 179);
              gotoxy(21, y);
              printf("%c", 179);
              gotoxy(37, y);
              printf("%c", 179);
              gotoxy(50, y);
              printf("%c", 179);
              gotoxy(62, y);
              printf("%c", 179);

            }
            for (x = 7; x <= 77; x++) {
              gotoxy(x, 24);
              printf("%c", 196);
            }
            limpa_linha(8, 22, 1, 80, 3, 3);
            limpa_linha(9, 12, 7, 76, 15, 15);
            cont = 0;

          }
          fflush(stdin);
          //getch();
          cont++; //para ir pulando linhas conforme a existência dos cadastros
        }
      }
    }
    if (cont == 0) {
      gotoxy(26, 15);
      textcolor(15);
      textbackground(0);
      printf("NENHUM CADASTRO ENCONTRADO");
    }
    textcolor(15);
    textbackground(RED);
    gotoxy(8, 22);
    printf("<ENTER p/ retornar ao menu - BACKSPACE p/ procurar novo cadastro>");
    textcolor(0);
    textbackground(15);
    gotoxy(80, 24);
    do {
      teste = getch();
    } while (teste != 8 && teste != 13);
    limpa_linha(8, 22, 1, 80, 3, 3);
    limpa_linha(9, 12, 7, 76, 15, 15);
    textcolor(0);
    textbackground(15);
    if (teste == 13) return;
  } while (true);
}

void impressao_dados(int cont) {
  textcolor(0);
  textbackground(15);
  gotoxy(8, 13 + cont);
  printf("Nome da Empresa: %s ", dadosEmp.nomeEmp);
  gotoxy(8, 14);
  printf("Endereco: %s ", dadosEmp.enderecoEmp);
  gotoxy(8, 15);
  printf("Email : %s", dadosEmp.emailEmp);
  gotoxy(8, 16);
  printf("Telefone: ( %s ) %s ", dadosEmp.telEmp.ddd, dadosEmp.telEmp.tel);
  gotoxy(8, 17);
  printf("Representante: %s ", dadosEmp.nomeRepresent);
  gotoxy(8, 18);
  printf("CNPJ : %s ", dadosEmp.cnpj);
  gotoxy(50, 13);
  printf("Cidade : %s ", dadosEmp.cidadeEmp);
  gotoxy(50, 14);
  printf("Produto: %s ", dadosEmp.produto);
  gotoxy(50, 15);
  printf("Valor do Produto : %s", dadosEmp.preco);
}

void consulta_geral() {
  int lin = 0, x, y;
  char aux;
  system("cls");
  system("color 3F");
  textcolor(15);
  textbackground(0);
  gotoxy(3, 2);
  printf("|COD |  EMPRESA   | REPRESENTANTE |   CIDADE   |   PRODUTO   |   TELEFONE    |");
  for (int i = 1; i < 81; i++) {
    gotoxy(i, 1);
    textcolor(15);
    textbackground(15);
    printf("%c", 219);
    gotoxy(i, 24);
    textcolor(15);
    textbackground(15);
    printf("%c", 219);
  }
  for (int j = 1; j < 25; j++) {
    gotoxy(1, j);
    textcolor(15);
    textbackground(15);
    printf("%c", 219);
    gotoxy(81, j);
    textcolor(15);
    textbackground(15);
    printf("%c", 219);
  }
  textbackground(0);
  textcolor(3);
  for (y = 2; y <= 24; y++) {
    gotoxy(8, y);
    printf("%c", 179);
    gotoxy(21, y);
    printf("%c", 179);
    gotoxy(37, y);
    printf("%c", 179);
    gotoxy(50, y);
    printf("%c", 179);
    gotoxy(64, y);
    printf("%c", 179);
    gotoxy(80, y);
    printf("%c", 179);
    gotoxy(2, y);
    printf("%c", 179);
  }
  for (x = 3; x <= 80; x++) {
    gotoxy(x, 24);
    printf("%c", 196);
  }
  gotoxy(8, 24);
  printf("%c", 193);
  gotoxy(21, 24);
  printf("%c", 193);
  gotoxy(37, 24);
  printf("%c", 193);
  gotoxy(50, 24);
  printf("%c", 193);
  gotoxy(64, 24);
  printf("%c", 193);
  gotoxy(80, 24);
  printf("%c", 193);

  gotoxy(3, 24);
  printf("%c", 192);
  do {
    rewind(database);
    while (!feof(database)) {
      if (fread( & dadosEmp, sizeof(dadosEmp), 1, database) == 1 && dadosEmp.ativo == true) {
        textcolor(0);
        textbackground(3);
        gotoxy(4, 3 + lin);
        printf("%li ", dadosEmp.chavePrimaria);
        gotoxy(9, 3 + lin);
        printf("%s ", dadosEmp.nomeEmp);
        gotoxy(23, 3 + lin);
        printf("%s ", dadosEmp.nomeRepresent);
        gotoxy(39, 3 + lin);
        printf("%s ", dadosEmp.cidadeEmp);
        gotoxy(52, 3 + lin);
        printf("%s ", dadosEmp.produto);
        gotoxy(65, 3 + lin);
        printf("(%s)%s ", dadosEmp.telEmp.ddd, dadosEmp.telEmp.tel);
        fflush(stdin);
        lin++; //vai pulando linhas
      }
      if (lin == 20) {
        lin = 0;
        textcolor(15);
        textbackground(RED);
        gotoxy(1, 25);
        printf("<BACKSPACE p/ retornar ao menu - ENTER p/ avancar a pagina>");
        textcolor(0);
        textbackground(15);
        gotoxy(80, 24);
        do {
          aux = getch();
        } while (aux != 8 && aux != 13);
        //limpa_linha(8,22,1,80,3,3);
        limpa_linha(3, 2, 22, 7, 3, 3);
        limpa_linha(9, 2, 22, 20, 3, 3);
        limpa_linha(22, 2, 22, 36, 3, 3);
        limpa_linha(38, 2, 22, 49, 3, 3);
        limpa_linha(51, 2, 22, 63, 3, 3);
        limpa_linha(65, 2, 22, 79, 3, 3);
        textcolor(0);
        textbackground(15);
        if (aux == 8) return;
      }
    }
    textcolor(15);
    textbackground(RED);
    gotoxy(1, 24);
    printf("<ENTER p/ retornar ao menu>");
    textcolor(0);
    textbackground(15);
    gotoxy(80, 24);
    do {
      aux = getch();
    } while (aux != 13);
    //limpa_linha(8,22,1,80,3,3);
    //limpa_linha(9,12,7,75,15,15);
    textcolor(0);
    textbackground(15);
    lin = 0;
    if (aux == 13) return;
  } while (true);
}

void sobre() {
  textcolor(1);
  textbackground(1);
  for (int x = 4; x <= 75; x++) {
    for (int y = 5; y < 21; y++) {
      gotoxy(x, y);
      printf("%c", 219);
    }
  }
  textcolor(15);
  textbackground(1);
  gotoxy(7, 5);
  printf("      Colegio Tecnico Industrial 'Prof. Isaac Portal Roldan'");
  gotoxy(7, 6);
  printf("Versao do programa: 2.0  -  Data: %s       Hora: %s", __DATE__, __TIME__); // pega o dia e o horario do computador
  gotoxy(7, 8);
  printf("Os alunos Caio Lucas, Gabriel, Gisele e Marianne sao socios do ");
  gotoxy(7, 9);
  printf("sistema empresarial !go2, tem como principal objetivo agradar");
  gotoxy(7, 10);
  printf("da melhor forma possivel seus clientes. A empresa !go2 e ");
  gotoxy(7, 11);
  printf("responsavel por desenvolver programas atendendo todos os ");
  gotoxy(7, 12);
  printf("desejos dos clientes, trazendo solucoes para o seu negocio.");
  gotoxy(7, 14);
  printf("Informacoes de desenvolvimento:");
  gotoxy(7, 15);
  printf("Linhas de codigo: 2344         Qtde de caracteres usados: 71581");
  gotoxy(7, 16);
  printf("Qtde de funcoes utilizadas: 59   Agradecimento: Prof Ariane Scarelli");
  gotoxy(7, 17);
  printf("Objetivo do projeto: Ajudar, desenvolver, promover conhecimento na");
  gotoxy(7, 18);
  printf("na area de informatica, visando um prospero futuro como analista");
  gotoxy(7, 19);
  printf("e desenvolvedor de sistemas.  ");
}

void alteracao_dados() {
  not_goto backup_dados;
  int gabriel, opcao;
  long int mari;
  long posicao;
  char lj, teste;
  //rewind(database);
  fclose(database);
  abrir_arquivo("rb+");
  mascara_alteracao();
  textcolor(15);
  textbackground(8);
  do {
    botao(64, 73, 21, 19, 4, 15, 0, 1, "CANCELAR");
    botao(6, 14, 21, 19, 3, 15, 0, 1, "ALTERAR");
    //limpa_linha(6,8,12,73,15,15);
    rewind(database);
    limpa_linha(10, 18, 1, 73, 15, 15);
    textbackground(RED);
    textcolor(15);
    gotoxy(17, 18);
    printf("Pesquise o codigo <0> caso deseja voltar ao menu");
    textcolor(0);
    textbackground(15);
    do {
      //limpa_linha(6,23,1,73,15,15);
      gotoxy(24, 5);
      printf("                                      "); //limpa o espaço do código
      gotoxy(24, 5);
      scanf("%ld", & mari);
      if (mari == 0)
        return;
    } while (mari < 1 || mari > 100);
    textbackground(8);
    textcolor(15);
    gabriel = 0; //flag
    do {
      if (fread( & dadosEmp, sizeof(dadosEmp), 1, database) == 1 && dadosEmp.chavePrimaria == mari && dadosEmp.ativo == true) {
        gabriel = 1;
        //mostrar_dados();
        posicao = ftell(database); //salva a posição do ponteiro
        mostra_masc_auxiliar();
        backup_dados = dadosEmp; //backup dos dados - segunda struct é igual a primeira
        limpa_linha(10, 18, 1, 73, 15, 15);
        textbackground(RED);
        textcolor(15);
        gotoxy(17, 18);
        printf("<ENTER> para alterar / <BACKSPACE> para voltar");
        do {
          lj = getch();
          if (lj == 8)
            break;
        } while (lj != 13);
        if (lj == 8)
          break;
        func_alt();
        if (dadosEmp.nomeEmp[0] == '\0')
          strcpy(dadosEmp.nomeEmp, backup_dados.nomeEmp);
        if (dadosEmp.enderecoEmp[0] == '\0')
          strcpy(dadosEmp.enderecoEmp, backup_dados.enderecoEmp);
        if (dadosEmp.emailEmp[0] == '\0')
          strcpy(dadosEmp.emailEmp, backup_dados.emailEmp);
        if (dadosEmp.telEmp.ddd[0] == '\0')
          strcpy(dadosEmp.telEmp.ddd, backup_dados.telEmp.ddd);
        if (dadosEmp.telEmp.tel[0] == '\0')
          strcpy(dadosEmp.telEmp.tel, backup_dados.telEmp.tel);
        if (dadosEmp.nomeEmp[0] == '\0')
          strcpy(dadosEmp.nomeEmp, backup_dados.nomeEmp);
        if (dadosEmp.nomeRepresent[0] == '\0')
          strcpy(dadosEmp.nomeRepresent, backup_dados.nomeRepresent);
        if (dadosEmp.cnpj[0] == '\0')
          strcpy(dadosEmp.cnpj, backup_dados.cnpj);
        if (dadosEmp.produto[0] == '\0')
          strcpy(dadosEmp.produto, backup_dados.produto);
        limpa_linha(8, 18, 1, 75, 15, 15);
        textbackground(RED);
        textcolor(15);
        //gotoxy(10,18);printf("<ENTER> para salvar / <BACKSPACE> para discartar");
        bool salvar = true;
        botao(6, 14, 21, 19, 11, 15, 0, 1, "ALTERAR");
        do {
          gotoxy(80, 24);
          lj = getch();
          if (lj == 'D' || lj == 'd') {
            salvar = false;
            botao(6, 14, 21, 19, 3, 15, 0, 1, "ALTERAR");
            botao(64, 73, 21, 19, 12, 15, 0, 1, "CANCELAR");
          } else if (lj == 'A' || lj == 'a') {
            salvar = true;
            botao(6, 14, 21, 19, 11, 15, 0, 1, "ALTERAR");
            botao(64, 73, 21, 19, 4, 15, 0, 1, "CANCELAR");
          }
          //lj = getch();
          else if (lj == 13 && salvar == false) {
            botao(64, 73, 21, 19, 4, 0, 15, 1, "CANCELAR");

            break;
          } else if (lj == 13 && salvar == true) {
            botao(6, 14, 21, 19, 3, 0, 15, 1, "ALTERAR");
            Sleep(30);
            fseek(database, posicao - (sizeof(dadosEmp)), SEEK_SET);
            fwrite( & dadosEmp, sizeof(dadosEmp), 1, database);
            fflush(database);
            limpa_linha(4, 7, 12, 77, 4, 4);
            textbackground(15);
            textcolor(0);
            gotoxy(9, 12);
            printf("CODIGO SALVO COM SUCESSO, PRESSIONE ALGUMA TECLA PARA CONTINUAR");
            getch();
            break;
          }
        } while (true);
      }
    } while (!gabriel && !feof(database));
    if (gabriel == 0) {
      limpa_linha(4, 7, 12, 77, 15, 15);
      textbackground(RED);
      textcolor(15);
      gotoxy(10, 10);
      printf("Codigo nao encontrado");
      getch();
    }
    limpa_linha(4, 7, 12, 77, 15, 15);
  } while (true);
}

void mascara_alteracao() {
  janela(1, 3, 78, 3, 3, 22, 15, 8, "ALTERACAO", 9, 15);
  caixalinha(3, 78, 4, 22, 15, 8, 1);
  linha(79, 4, 23, 8, 0);
  painel(77, 4, 18, 7, 15);
  gotoxy(5, 5);
  textbackground(1);
  textcolor(15);
  printf("Digite o codigo: ");
  painel(75, 24, 5, 5, 15);
  botao(6, 14, 21, 19, 3, 15, 0, 1, "ALTERAR");
  botao(64, 73, 21, 19, 4, 15, 0, 1, "CANCELAR");

}

void mostra_masc_auxiliar() {
  //gotoxy(10,8);printf("%d",dadosEmp.chavePrimaria);	
  textbackground(15);
  textcolor(0);
  gotoxy(10, 8);
  printf("Empresa: %s", dadosEmp.nomeEmp);
  gotoxy(10, 9);
  printf("Endereco: %s", dadosEmp.enderecoEmp);
  gotoxy(10, 10);
  printf("E-mail: %s", dadosEmp.emailEmp);
  gotoxy(10, 11);
  printf("Telefone: (%s)%s", dadosEmp.telEmp.ddd, dadosEmp.telEmp.tel);
  gotoxy(10, 12);
  printf("Representante: %s", dadosEmp.nomeRepresent);
  gotoxy(10, 13);
  printf("CNPJ: %s", dadosEmp.cnpj);
  gotoxy(10, 14);
  printf("Cidade: %s", dadosEmp.cidadeEmp);
  gotoxy(10, 15);
  printf("Sistema: %s", dadosEmp.produto);
  gotoxy(10, 16);
  printf("Valor: R$%s", dadosEmp.preco);
  //gotoxy(10,18);printf("Pressione uma tecla para continuar...");
  fflush(stdin);
  //getch();
}

void func_alt() {
  char opcao;
  int op, lin = 8, col = 47;
  int m;
  limpa_linha(10, 18, 1, 73, 15, 15);
  textbackground(RED);
  textcolor(15);
  gotoxy(8, 18);
  printf("<W/S> p/ navegacao - <ENTER> p/ selecionar - <BACKSPACE> p/ encerrar");
  //limpa_linha(28,8,10,77,15,15);
  gotoxy(60, 11);
  printf("(  )");
  textbackground(15);
  textcolor(0);
  gotoxy(50, 8);
  printf("Empresa: ");
  gotoxy(50, 9);
  printf("Endereco: ");
  gotoxy(50, 10);
  printf("E-mail: ");
  gotoxy(50, 11);
  printf("Telefone: (  ) ");
  gotoxy(50, 12);
  printf("Representante: ");
  gotoxy(50, 13);
  printf("CNPJ: ");
  gotoxy(50, 14);
  printf("Cidade: ");
  gotoxy(50, 15);
  printf("Sistema: ");
  gotoxy(50, 16);
  printf("Valor: R$");

  ///////////
  do {
    //lin=8;
    //op=0;
    do {
      textcolor(0);
      textbackground(15);
      gotoxy(col, lin);
      printf("%c", 175);
      gotoxy(81, 24);
      do {
        opcao = getch();
        if (opcao == 8)
          return;
        if (opcao == 13)
          break;
      } while (opcao != 'W' && opcao != 'S' && opcao != 's' && opcao != 'w');
      if (opcao == 13)
        break;
      gotoxy(col, lin);
      printf(" ");
      if (opcao == 'W' || opcao == 'w') {
        op--;
        lin--;
        if (op < 0) {
          op = 8;
          lin = 16;
        }
      } else if (opcao == 'S' || opcao == 's') {
        op++;
        lin++;
        if (op > 8) {
          op = 0;
          lin = 8;
        }
      }
      //gotoxy(col-1,8);printf("%d",op);
    } while (true);
    switch (op) {
    case 0:
      //gotoxy(59,8);gets(dadosEmp.nomeEmp);
      scant(dadosEmp.nomeEmp, 59, 8, 75);
      break;
    case 1:
      //gotoxy(60,9);gets(dadosEmp.enderecoEmp);
      scant(dadosEmp.enderecoEmp, 59, 9, 75);
      break;
    case 2:
      do {
        textbackground(15);
        gotoxy(59, 10);
        gets(dadosEmp.emailEmp);
        strlwr(dadosEmp.emailEmp); //minúsculo
        isemail(dadosEmp.emailEmp, 59, 10, 75);
        m = isemail(dadosEmp.emailEmp, 59, 10, 75);
      } while (m == 0);
      break;
    case 3:
      limpa_linha(8, 18, 1, 75, 15, 15);
      istel(dadosEmp.telEmp.ddd, 2, 61, 11, 6);
      limpa_linha(10, 18, 1, 73, 15, 15);
      textbackground(RED);
      textcolor(15);
      textcolor(BLACK);
      textbackground(15);
      gotoxy(63, 11);
      printf(")");
      limpa_linha(10, 18, 1, 73, 15, 15);
      textbackground(RED);
      textcolor(15);
      gotoxy(8, 18);
      printf("<W/S> p/ navegacao - <ENTER> p/ selecionar - <BACKSPACE> p/ encerrar");
      limpa_linha(8, 18, 1, 75, 15, 15);
      istel(dadosEmp.telEmp.tel, 10, 65, 11, 6);
      limpa_linha(10, 18, 1, 73, 15, 15);
      textbackground(RED);
      textcolor(15);
      gotoxy(8, 18);
      printf("<W/S> p/ navegacao - <ENTER> p/ selecionar - <BACKSPACE> p/ encerrar");
      break;
    case 4:
      //gotoxy(65,12);gets(dadosEmp.nomeRepresent);
      scant(dadosEmp.nomeRepresent, 65, 12, 75);
      break;
    case 5:
      limpa_linha(8, 18, 1, 75, 15, 15);
      isdigit2(dadosEmp.cnpj, 14, 56, 13, 4);
      limpa_linha(10, 18, 1, 73, 15, 15);
      textbackground(RED);
      textcolor(15);
      gotoxy(8, 18);
      printf("<W/S> p/ navegacao - <ENTER> p/ selecionar - <BACKSPACE> p/ encerrar");
      break;
    case 6:
      //gotoxy(58,14);gets(dadosEmp.cidadeEmp);
      scant(dadosEmp.cidadeEmp, 58, 14, 75);
      break;
    case 7:
      //gotoxy(59,15);gets(dadosEmp.produto);
      scant(dadosEmp.produto, 59, 15, 75);
      break;
    case 8:
      limpa_linha(8, 18, 1, 75, 15, 15);
      isvalue(dadosEmp.preco, 15, 60, 16, 1);
      limpa_linha(10, 18, 1, 73, 15, 15);
      textbackground(RED);
      textcolor(15);
      gotoxy(8, 18);
      printf("<W/S> p/ navegacao - <ENTER> p/ selecionar - <BACKSPACE> p/ encerrar");
      break;
    }
    textbackground(15);
    gotoxy(col, lin);
    printf(" ");
  } while (true);
}

void mascara_exclusao() {
  janela(1, 3, 78, 3, 3, 22, 15, 8, "EXCLUSAO", 9, 15);
  caixalinha(3, 78, 4, 22, 15, 8, 1);
  linha(79, 4, 23, 8, 0);
  painel(77, 4, 18, 7, 15);
  gotoxy(5, 5);
  textbackground(1);
  textcolor(15);
  printf("Digite o codigo: ");
  painel(75, 24, 5, 5, 15);
  botao(6, 14, 21, 19, 3, 15, 0, 1, "EXCLUIR");
  botao(64, 73, 21, 19, 4, 15, 0, 1, "CANCELAR");
}

void exclusao() {
  long int codigo;
  int flag, posicao;
  char teste;
  fclose(database);
  abrir_arquivo("rb+");
  mascara_exclusao();
  do {
    rewind(database);
    limpa_linha(10, 18, 1, 73, 15, 15);
    limpa_linha(4, 7, 12, 77, 15, 15);
    textbackground(RED);
    textcolor(15);
    gotoxy(17, 18);
    printf("Pesquise o codigo <0> caso deseja voltar ao menu");
    textcolor(0);
    textbackground(15);
    do {
      gotoxy(24, 5);
      printf("                            ");
      gotoxy(24, 5);
      scanf("%ld", & codigo);
      if (codigo == 0)
        return;
    } while (codigo < 1 || codigo > 100);
    flag = 0;
    do {
      if (fread( & dadosEmp, sizeof(dadosEmp), 1, database) == 1 && dadosEmp.chavePrimaria == codigo && dadosEmp.ativo == true) {
        flag = 1;
        //mostrar_dados();
        posicao = ftell(database);
        mostra_masc_auxiliar();
        textbackground(RED);
        textcolor(15);
        gotoxy(17, 18);
        printf("<ENTER> para confirmar / <BACKSPACE> para voltar");
        do {
          teste = getch();
          if (teste == 8)
            break;
        } while (teste != 13);
        if (teste == 8)
          break;
        bool ativo_aux;
        gotoxy(30, 21);
        textbackground(12);
        printf("Deseja mesmo excluir?");
        botao(6, 14, 21, 19, 11, 15, 0, 1, "EXCLUIR");
        do {
          teste = getch();
          if (teste == 'd' || teste == 'D') {
            botao(6, 14, 21, 19, 3, 15, 0, 1, "EXCLUIR");
            botao(64, 73, 21, 19, 12, 15, 0, 1, "CANCELAR");
            ativo_aux = true;
          } else if (teste == 'a' || teste == 'A') {
            botao(6, 14, 21, 19, 11, 15, 0, 1, "EXCLUIR");
            botao(64, 73, 21, 19, 4, 15, 0, 1, "CANCELAR");
            ativo_aux = false;
          }
          if (teste == 13 && ativo_aux == true) {

            botao(64, 73, 21, 19, 4, 15, 0, 1, "CANCELAR");
            system("cls");
            system("color 3F");
            menu();
          } else if (teste == 13 && ativo_aux == false) {

            botao(6, 14, 21, 19, 11, 15, 0, 1, "EXCLUIR");
            //fseek (fp,fposicao-(sizeof(agenda)),SEEK_SET)
            fseek(database, posicao - (sizeof(dadosEmp)), SEEK_SET);
            dadosEmp.ativo = false;
            fwrite( & dadosEmp, sizeof(dadosEmp), 1, database); //vai sobrepor as alterações
            fflush(database);
            break;

          }
        } while (true);
      }
    } while (!flag && !feof(database));
  } while (true);
}

void lixeira_dados() {

  int jup;
  long int rest;
  long posicao;
  char lj, teste;
  rewind(database); //primeira posicao
  fclose(database);
  abrir_arquivo("rb+");
  mascara_reativar();
  textcolor(15);
  textbackground(8);
  do {
    botao(64, 73, 21, 19, 4, 15, 0, 1, "CANCELAR");
    botao(6, 16, 21, 19, 3, 15, 0, 1, "RESTAURAR");
    rewind(database);
    limpa_linha(10, 18, 1, 73, 15, 15);
    textbackground(RED);
    textcolor(15);
    gotoxy(17, 18);
    printf("Pesquise o codigo <0> caso deseja voltar ao menu");
    textcolor(0);
    textbackground(15);
    do {
      //para o usuario digitar o codigo para reativacao
      gotoxy(24, 5);
      printf("                            ");
      gotoxy(24, 5);
      scanf("%ld", & rest);
      if (rest == 0)
        return;
    } while (rest < 1 || rest > 99);
    textbackground(8);
    textcolor(15);
    jup = 0;
    do {

      if (fread( & dadosEmp, sizeof(dadosEmp), 1, database) == 1 && dadosEmp.chavePrimaria == rest && dadosEmp.ativo == false) {
        jup = 1;
        mostra_masc_auxiliar();
        posicao = ftell(database);
        limpa_linha(10, 18, 1, 73, 15, 15);
        textbackground(RED);
        textcolor(15);
        gotoxy(17, 18);
        printf("<ENTER> para confirmar / <BACKSPACE> para voltar");
        do {
          teste = getch();
          if (teste == 8)
            break;
        } while (teste != 13);
        if (teste == 8)
          break;
        bool ativo_aux;
        gotoxy(30, 21);
        textbackground(12);
        printf("Deseja Reativar?");
        botao(6, 16, 21, 19, 11, 15, 0, 1, "RESTAURAR");
        do {
          teste = getch();
          if (teste == 'd' || teste == 'D') {
            botao(6, 16, 21, 19, 3, 15, 0, 1, "RESTAURAR");
            botao(64, 73, 21, 19, 12, 15, 0, 1, "CANCELAR");
            ativo_aux = true;
          } else if (teste == 'a' || teste == 'A') {
            botao(6, 16, 21, 19, 11, 15, 0, 1, "RESTAURAR");
            botao(64, 73, 21, 19, 4, 15, 0, 1, "CANCELAR");
            ativo_aux = false;
          }
          if (teste == 13 && ativo_aux == true) {

            botao(64, 73, 21, 19, 4, 0, 15, 1, "CANCELAR");
            system("cls");
            system("color 3F");
            menu();
          } else if (teste == 13 && ativo_aux == false) {

            botao(6, 16, 21, 19, 3, 0, 15, 1, "RESTAURAR");
            //fseek (fp,fposicao-(sizeof(agenda)),SEEK_SET)
            fseek(database, posicao - (sizeof(dadosEmp)), SEEK_SET);
            dadosEmp.ativo = true;
            fwrite( & dadosEmp, sizeof(dadosEmp), 1, database);
            fflush(database);
            break;

          }
        } while (true);

      }
    } while (!jup && !feof(database));
    if (jup == 0) {
      limpa_linha(4, 7, 12, 77, 15, 15);
      textbackground(RED);
      textcolor(15);
      gotoxy(10, 10);
      printf("Codigo nao encontrado ou nao foi excluido");
      getch();
    }
    limpa_linha(4, 7, 12, 77, 15, 15);
  } while (true);
}
void mascara_reativar() {
  janela(1, 3, 78, 3, 3, 22, 15, 8, "LIXEIRA", 9, 15);
  caixalinha(3, 78, 4, 22, 15, 8, 1);
  linha(79, 4, 23, 8, 0);
  painel(77, 4, 18, 7, 15);
  gotoxy(5, 5);
  textbackground(1);
  textcolor(15);
  printf("Digite o codigo: ");
  painel(75, 24, 5, 5, 15);
  botao(6, 16, 21, 19, 3, 15, 0, 1, "RESTAURAR");
  botao(64, 73, 21, 19, 4, 15, 0, 1, "CANCELAR");

}
void mascara_loguin() {
  janela(3, 15, 55, 15, 5, 15, 15, 0, "LOGIN", 11, 0);
  caixalinha(15, 55, 6, 15, 15, 0, 3);
  painel(54, 22, 8, 8, 15);
  gotoxy(16, 8);
  textcolor(15);
  textbackground(3);
  printf("SENHA:");
  botao(16, 23, 13, 11, 1, 15, 0, 3, "ENTRAR");
  botao(43, 52, 13, 11, 4, 15, 0, 3, "CANCELAR");
  gotoxy(16, 16);
  textcolor(8);
  textbackground(0);
  printf("uncoes utilizadas: 43          versao do ");
  gotoxy(56, 8);
  textcolor(8);
  textbackground(0);
  printf("s");
  gotoxy(56, 9);
  textcolor(8);
  textbackground(0);
  printf("t");
  gotoxy(56, 10);
  textcolor(8);
  textbackground(0);
  printf("s");
  gotoxy(56, 11);
  textcolor(8);
  textbackground(0);
  printf("o");
}

int login() {
  char senha_aux[3], aux;
  int flag;
  bool ativo_aux;
  strcpy(senha, "ADM");
  do {
    flag = 0;
    limpa_linha(22, 8, 1, 52, 15, 15);
    for (int y = 0; y < 3; y++) {
      gotoxy(22 + y, 8);
      senha_aux[y] = getch(); //para ler um caracter sem dar enteder
      strupr(senha_aux);
      gotoxy(22 + y, 8);
      printf("*");
      if (senha_aux[y] == senha[y]) {
        flag++;
        //botao(16,23,13,11,11,15,0,3,"ENTRAR");
      }
    }
    botao(16, 23, 13, 11, 11, 15, 0, 3, "ENTRAR");
    do {
      aux = getch();
      if (aux == 'd' || aux == 'D') {
        botao(16, 23, 13, 11, 1, 15, 0, 3, "ENTRAR");
        botao(43, 52, 13, 11, 12, 15, 0, 3, "CANCELAR");
        ativo_aux = true;
      } else if (aux == 'a' || aux == 'A') {
        botao(16, 23, 13, 11, 11, 15, 0, 3, "ENTRAR");
        botao(43, 52, 13, 11, 4, 15, 0, 3, "CANCELAR");
        ativo_aux = false;
      }
      if (aux == 13 && ativo_aux == true) {
        botao(43, 52, 13, 11, 4, 0, 15, 3, "CANCELAR");
        return 0;
      } else if (aux == 13 && ativo_aux == false) {
        botao(16, 23, 13, 11, 1, 0, 15, 3, "ENTRAR");
        if (flag == 3) return 1;
        else break;
      }
    } while (true);
  } while (true);
}