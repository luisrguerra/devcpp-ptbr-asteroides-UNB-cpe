////BSD License
///UNB University of Brasilia
////Made by Erick Nasareth and Luis Eduardo Ribeiro Guerra
#include <locale.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>
////habilitar mudar cor das letras
#include <conio.h>
#include <stdio.h>
#include <windows.h>  
//#include "mmsystem.h"
///gerenciar arquivos texto
#include <fstream>
//#include <cwchar>

////códigos para permitir mudar as cores de texto
enum DOS_COLORS {
    BLACK, BLUE, GREEN, CYAN, RED, MAGENTA, BROWN,
    LIGHT_GRAY, DARK_GRAY, LIGHT_BLUE, LIGHT_GREEN, LIGHT_CYAN,
    LIGHT_RED, LIGHT_MAGENTA, YELLOW, WHITE };
////códigos para permitir mudar as cores de texto
void textcolor (DOS_COLORS iColor){
    HANDLE hl = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO bufferInfo;
    BOOL b = GetConsoleScreenBufferInfo(hl, &bufferInfo);
    bufferInfo.wAttributes &= 0x00F0;
    SetConsoleTextAttribute (hl, bufferInfo.wAttributes |= iColor);
}
////códigos para permitir mudar as cores de texto
void textbackground (DOS_COLORS iColor){
    HANDLE hl = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO bufferInfo;
    BOOL b = GetConsoleScreenBufferInfo(hl, &bufferInfo);
    bufferInfo.wAttributes &= 0x000F;
    SetConsoleTextAttribute (hl, bufferInfo.wAttributes |= (iColor << 4));
}

using namespace std;

////variável que diz se é pra mostrar as telas iniciais ou não. na primeira rodada ele é mostrado
bool primeiravez = true;

////função para facilitar pular linhas
void pularlinha(int numerolinhas){
    for (int f = 0; f < numerolinhas; f++ ){
	cout << endl;
	}
}
/// tituloarte: "escrever" na tela, a tela inicial com letreiro 
void tituloarte(){
       cout << endl;
	   cout << "               _                 _     _           "<< endl;
	   cout << "     /\\       | |               (_)   | |          " << endl;
	   cout << "    /  \\   ___| |_ ___ _ __ ___  _  __| | ___  ___ " << endl;
	   cout << "   / /\\ \\ / __| __/ _ \\  __/ _ \\| |/ _  |/ _ \\/ __|" << endl;
	   cout << "  / ____ \\\\__ \\ |   __/ | | (_) | | (_| |  __/\\__ \\" << endl;
	   cout << " /_/    \\_\\___/\\__\\___|_|  \\___/|_|\\__ _|\\___ |___/" << endl;
	   cout << endl;
	   cout << "                      UNB 2019";
	   cout << endl;
	   cout << endl;	
}
//// intro1: "escrever" na tela luis & erick
void intro1(){
	   pularlinha(5);
	   cout << "                Luís Eduardo Guerra" << endl;
	   pularlinha(1);
	   cout << "                        &" << endl;
	   pularlinha(1);
	   cout << "                  Erick Nasareth";
}
//// intro2: "escrever" na tela apresentam
void intro2(){
	   pularlinha(7);
	   cout << "                    apresentam" << endl;
}
//// tutorial: "escrever" na tela turorial
void tutorial(){
	
	   cout << "Controles:" << endl;
	   cout << "  ____        ____        ____        ____ " << endl;
	   cout << " ||a ||      ||d ||      ||< ||      ||> ||" << endl;
	   cout << " ||__||      ||__||      ||__||      ||__||" << endl;
	   cout << " |/__\\|      |/__\\|      |/__\\|      |/__\\|" << endl;
	   cout << "esquerda    direita  ou esquerda    direita" << endl;
	   pularlinha(1);
	   cout << " __________________________ " << endl;
	   cout << "||                        ||" << endl;
	   cout << "||________________________||" << endl;
	   cout << "|/________________________\\|" << endl;
	   cout << "          atirar" << endl;
	   pularlinha(1);
	   cout << "    ^";
	   textcolor(LIGHT_CYAN);
	   cout << "        °";
	   textcolor(YELLOW);
	   cout << "     ø";
	   textcolor(WHITE);
	   textcolor(LIGHT_BLUE);
	   cout << "       o" << endl;
	   textcolor(WHITE);
	   cout << "asteroide  vida  poder  munição" << endl;
	   pularlinha(1);
	   cout << "O poder desacelera a velocidade da nave" << endl;
	   cout << "temporariamente" << endl;
	   pularlinha(1);
}
//// textopcoes: "escrever" na tela as opções após mostrar o  placar
void textopcoes(){
     cout << "Continuar [enter] Apagar Histórico de pontos [F1]" << endl;
     cout << "Reiniciar [F2]";
}
//// perdeu: "escrever" na tela que o jogador perdeu, de vermelho
void perdeu(){
    textcolor(LIGHT_RED);
    cout << "Você perdeu!";
    textcolor(WHITE);
}

///// definirtamanhofonte: função para deixar a fonte maior e melhor de enchergar
void definirtamanhofonte(){
    CONSOLE_FONT_INFOEX cfi;
    cfi.cbSize = sizeof(cfi);
    cfi.nFont = 0;
	cfi.dwFontSize.X = 0;  
	cfi.dwFontSize.Y = 30;
	std::wcscpy(cfi.FaceName, L"Consolas"); 
	cfi.FontFamily = FF_DONTCARE;
    cfi.FontWeight = FW_NORMAL;
    SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);	
}

///// apagartela: função para limpar a tela do terminal 
void apagartela(){
	
	///substituto do system cls mais rápido para não dar glitch limpando a tela o tela muito rápido
	HANDLE hOut;
    COORD Position;

    hOut = GetStdHandle(STD_OUTPUT_HANDLE);

    Position.X = 0;
    Position.Y = 0;
    SetConsoleCursorPosition(hOut, Position);
}

//// definirtamanhojanela: função para deixar a janela com um tamanho pré definido 
void definirtamanhojanela(){

system("MODE 52, 20");

}

void ShowConsoleCursor(bool showFlag){ ////desabilita o cursor branco piscando do console
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_CURSOR_INFO     cursorInfo;

    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = showFlag; // set the cursor visibility
    SetConsoleCursorInfo(out, &cursorInfo);
}


int main () {
    
    ShowConsoleCursor(false);
	definirtamanhofonte();
	definirtamanhojanela();
	
	setlocale(LC_ALL,"Portuguese");
	textcolor(WHITE);
	textbackground(BLACK);
	/// run: runhabilita o jogo rodar
	bool run = true;
	srand (time(NULL));
	
	////tecla: variável que diz qual tecla foi prcionada
	char tecla;
	
	/////pontuacao: variável que diz qual é a pontuação
	int pontuacao = 0;
    
    
    /// variável usada para alguns efietos graficos, alternado entre true false cada vez que se limpa a tela 
	bool variacao = false;
	
    //dilatacaodotempoquantico: variável que é usado como temporizador para os asteroides descerem na tela, quando vale 1 os asteroides descem na tela.
	//quando o valor é zero o temporizador fica parado
	int dilatacaodotempoquantico = 0;
	
	/// dilatacaodotempoquanticomax: tempo para os asteroides descerem
	int dilatacaodotempoquanticomax = 7;
	
	//// vida: variável que define a vida
	int vida = 8;
	
	//// limitar tiros consecutivos
	int tirofoi = 0;
	
	/// parartempo: variável que é usado como temporizador da desaceleração do tempo
	int parartempo = 0;
	/// levoudano: variável que avisa se a nave levou dano, é usado para efeito de cor vermelha na nave, pisca uma vez
	bool levoudano = false;
	
	/// recebeuvida: variável que avisa se a nave recebeu vida, é usado para efeito de cor ciano(tipo azul claro)  na nave, pisca uma vez
	bool recebeuvida = false;
	/// recebeumunicao: variável que avisa se a nave recebeu munição, é usado para efeito de cor azul que dura até a munição ser usada
	bool recebeumunicao = false;
	
	//// municaochar; vidachar; parartempochar : variáveis que definem quais símbolos serão utilizados no jogo
	string municaochar = "o";
	string vidachar = "°";
	string parartempochar = "ø";
    
	//// tabuleiro:  matriz bidimencional que é utilizada para a armazenar a posição dos elementos
	string tabuleiro [12][12];
	 /// deixa os valores das posições com " "
     for (int t = 0; t <= 11; t++){
      for (int a = 0; a <= 11; a++){
		  tabuleiro [t][a] = " ";
      }
	 }
	 //// fim de (deixa os valores das posições com " ");
	
	/////adicina lateral na matriz, feita de "|" 
	for (int i = 1; i <= 11; i++){
		tabuleiro [i][0] = "|";
		tabuleiro [i][11] = "|";
	}
    ///// fim de (adicina lateral na matriz, feita de "|" );
    
    ///posiçao: varíavel entre -5 e 5  que define a posição da nave, quando em zero a nave está no centro. -5 a -1 esquerda. 1 a 5 direita.
	int posicao = 0; 
	
	/////menu inicial que aparece quando o jogo está na primeirra rodada
	if (primeiravez == true){
	   Sleep(600);
       intro1();
	   PlaySound("somintro.wav", NULL, SND_FILENAME | SND_NODEFAULT); ///C:\Users\Luís Eduardo\Documents\c++\Projeto Space Invaders\somintro.wav
	   Sleep(3500);
	   
	   system("cls");
	   
	   intro2();
	   PlaySound("somintro2.wav", NULL, SND_FILENAME | SND_NODEFAULT | SND_ASYNC); /// "SND_ASYNC" é uma flag que define para não para o programa quando toca o som
	   Sleep(2000);
	   system("cls");
	
	
	
	   tituloarte();
	   PlaySound("musicatitulo.wav", NULL, SND_FILENAME | SND_ASYNC | SND_LOOP | SND_NODEFAULT);
	   system("PAUSE");
	   PlaySound(NULL, NULL, 0);
	   system("cls");
	   
	   
	   tutorial();
	   system("PAUSE");
	   system("cls");
	   primeiravez = false;
	}
	
	while (run == true){
		
		/// parartempo: variável temporizadora do power up "parar tempo". qunado em "0" é inativa. apartir de "1" a cada limpeza de tela é adicionado +1 ao seu valor
		if (parartempo >= 1){ 
			parartempo = parartempo +1;
		}
		
		if (parartempo >= 100){ ////        definir o tempo limite do powerup "parar tempo"
			parartempo = 0; //// desativa o temporizador
			///// tocar som do power up ao finalizar o seu efeito
			PlaySound("parartempo.wav", NULL, SND_FILENAME | SND_NODEFAULT);
			/// dilatacaodotempoquanticomax: tempo para os asteroides descerem
			dilatacaodotempoquanticomax = 7; /// volta a velocidade dos asteroides para o padrão
		}
		
		
		//dilatacaodotempoquantico: variável que é usada como temporizador para os asteroides descerem na tela, quando vale 1 os asteroides descem na tela.
		dilatacaodotempoquantico = dilatacaodotempoquantico + 1; /// progredir o temporizador que move os asteroides
		if (dilatacaodotempoquantico >= dilatacaodotempoquanticomax ){ //// limite do temporizador
			dilatacaodotempoquantico = 0; //// retorna o temporizador para o início
		}
		
		
		
		//////mover projeteis
		for(int l=10; l>= 0; l--){ /// vertical. começa de cima pra baixo. ignorando a nave no final
   		 for(int c=1; c<11; c++){  /// horizontal. começa da esquerda para a direita. ignorando os "|" laterais
   			    
				if(tabuleiro [l][c]=="|" && tabuleiro [l +1][c]=="^"){ /// detectar a colisão do tiro com a nave
   				 tabuleiro [l+1][c]= " "; //// apaga a posição do asteroide
   				 tabuleiro [l][c]= " "; //// apaga a posição do tiro
   				 pontuacao = pontuacao +1; /// aumenta a pontuação do jogador
   				 PlaySound("destruir.wav", NULL, SND_FILENAME | SND_ASYNC | SND_NODEFAULT | SND_NOSTOP); /// toca o som de destruir o asteroide caso não tenha outro som tocando
   			    }
				if(tabuleiro [l][c] =="|" && tabuleiro [l][c] !="^"){  ///// caso a posição seja um tiro e não um asteroide 
   				 if (/* bloquar tiros para powerups*/tabuleiro [l+1][c] != vidachar && tabuleiro [l+1][c] != parartempochar && tabuleiro [l+1][c] != municaochar){
					tabuleiro [l+1][c]= "|"; ///// mover o tiro uma casa para cimq
					}
   				 tabuleiro [l][c]= " "; //// apagar o rastro do tiro
   			 }
   		 }
   	    }
   	    ////// fim de mover projeteis
		
	///checa primeiro se o teclado está prescionado para depois pegar tecla. caso não. o programa é pausado até se prescionar uma tecla
	if (kbhit() != 0) { //// se a alguma tecla estiver precionada
    tecla=getch(); ///// define a tecla para a tecla atula precionada
    }	
	///
	 
	/// teclas
	//a=97 &  direita 65
    //d= 100 & esquerda 68
    // espaço tecla 32
    
    ////limitar os tiros consecutivos
    ///// tirofoi: variável temporizadora do intervalo de tempo. desativada quando em zero
	if (tirofoi >= 2){ //// limitar o tempo de espera para que se posa dar outro tiro
    	tirofoi = 0; /// desativa o temporizador do intervaulo de tiros
	}
	
	///// faz funcionar o temporizador do intervalo de tiro
	if (tirofoi >= 1){ /// apartir do número 1 funciona
    	tirofoi = tirofoi + 1; 
	}
	///
	if (tecla == 32){
		/// atirar 
		if (tirofoi == 0){
			tirofoi = tirofoi + 1; //// ativar o movimento do tiro e faz ele seguir
			if (tabuleiro [1][6 + posicao] != vidachar && tabuleiro [1][6 + posicao] !=parartempochar && tabuleiro [1][6 + posicao] != municaochar && recebeumunicao != true){ ///tiro normal. se não tem nenhum power up no caminho
			tabuleiro [1][6 + posicao]='|'; //// declara o tiro na matriz de referência que depois será escrita na tela
			PlaySound("tiro.wav", NULL, SND_FILENAME | SND_ASYNC | SND_NODEFAULT | SND_NOSTOP ); ///// "SND_NOSTOP" inpede que o som sobrescreva outro. "SND_ASYNC" inpede que o som pause o programa
			}
			if (tabuleiro [1][6 + posicao] != vidachar && tabuleiro [1][6 + posicao] !=parartempochar && tabuleiro [1][6 + posicao] != municaochar && recebeumunicao == true){ // tiro de munição
			 for (int v = 1;  v <= 10; v++){///// cria tiros tiro consecutivos de uma vez só preenchendo a coluna inteira
				if (tabuleiro [v][6 + posicao] == "^"){///// checa se o tiro longo e consecutivo acertou asteroides e marca a pontuação
					pontuacao = pontuacao +1;
				}
				tabuleiro [v][6 + posicao]='|';
			 }
			recebeumunicao = false; /// volta o power da munição para desativado
			
			PlaySound("tiroforte.wav", NULL, SND_FILENAME | SND_ASYNC | SND_NODEFAULT );/// som do tiro de munição
			}
			
		}
		///         				
	}
	if (tecla == 97 || tecla == 65 || tecla == 75){//// movimenta a nave para a esquerda
		posicao--;
	}
	if (tecla == 100 || tecla == 68 || tecla == 77){///// movimenta a nave para a direita
		posicao++;
	}
    //// limitar o movinto da nave para não bugar
	if(posicao > 4){
		posicao =4;
	}
	if(posicao < -5){
		posicao =-5;
	}
	////
	///apagar rastro da nave
	if (posicao >= -4){
		tabuleiro [0][5 + posicao -1] = " ";
	}
	if (posicao <= 3){
		tabuleiro [0][7 + posicao +1] = " ";
	}
	

	
	
	////nave
	tabuleiro [0][5 + posicao] = "-";
	tabuleiro [0][6 + posicao] = "^";
	tabuleiro [0][7 + posicao] = "-";
	////
	tecla = 0;
	/// 
	
	// dano
    if (dilatacaodotempoquantico == 1 && (tabuleiro [1][5 + posicao] == "^" || tabuleiro [1][6 + posicao] == "^" || tabuleiro [1][7 + posicao] == "^" )){
    	vida = vida -1;
    	levoudano = true;
	}
	
	// municao
    if (dilatacaodotempoquantico == 1 && (tabuleiro [1][5 + posicao] == municaochar || tabuleiro [1][6 + posicao] == municaochar || tabuleiro [1][7 + posicao] == municaochar )){
    	recebeumunicao = true;
    	PlaySound("municao.wav", NULL, SND_FILENAME | SND_ASYNC | SND_NODEFAULT | SND_NOSTOP);
	}
	
	
	// vida
    if (dilatacaodotempoquantico == 1 && (tabuleiro [1][5 + posicao] == vidachar || tabuleiro [1][6 + posicao] == vidachar || tabuleiro [1][7 + posicao] == vidachar )){
    	vida = vida +1;
    	recebeuvida = true;
	}
	
	// powerup tempo
    if (dilatacaodotempoquantico == 1 && (tabuleiro [1][5 + posicao] == parartempochar || tabuleiro [1][6 + posicao] == parartempochar || tabuleiro [1][7 + posicao] == parartempochar )){
       dilatacaodotempoquanticomax = 28;
       parartempo = 1;
       PlaySound("parartempo.wav", NULL, SND_FILENAME |SND_NODEFAULT);
	}
	
	////mover naves(asteroides)
	if (dilatacaodotempoquantico == 1){
     for (int t = 1; t <= 10; t++){
      for (int a = 1; a <= 10; a++){
      	if ((tabuleiro [t +1][a] != "|" && tabuleiro [t][a] != "|" )||(tabuleiro [t +1][a] == vidachar && tabuleiro [t +1][a] != "|" && tabuleiro [t][a] == "|" ) || (tabuleiro [t +1][a] == municaochar && tabuleiro [t +1][a] != "|" && tabuleiro [t][a] == "|" ) || (tabuleiro [t +1][a] == parartempochar && tabuleiro [t +1][a] != "|" && tabuleiro [t][a] == "|" ) ){
		 tabuleiro [t][a] = tabuleiro [t +1][a];
	    }
      }
	 }
    }
    
    // gerar aleatoriamente naves(ou asteroides na última linha) ° º ® © ©
   if (dilatacaodotempoquantico == 1){
	for (int t = 0; t <= 9; t++){
	 int vari = 	rand() % 2;  // chances de aparecer as naves
	 tabuleiro [11][t +1] = " ";	
	 if ( vari == 0){
	  tabuleiro [11][t +1] = "^";	
	  }
	 vari = 	rand() % 50; ///chances de apareceu powerup de vida
	 if ( vari == 0){
	  tabuleiro [11][t +1] = vidachar;	
	 }
	 vari = 	rand() % 150; ///chances de apareceu powerup de tempo
	 if ( vari == 0){
	  tabuleiro [11][t +1] = parartempochar;	
	 }
	 vari = 	rand() % 150; ///chances de apareceu powerup de tempo
	 if ( vari == 0){
	  tabuleiro [11][t +1] = municaochar;	
	 }
	 
	}
   }
	    // fim de gerar aleatoriamente naves(ou asteroides na última linha)
    
	
	////codigos emojis
	
	// 1 emoji oco
	// 2 emoji
	// 3 coração
	// 4 cubo inclinado
	// 5 baralho
	// 6 baralho
	// 11 sínbolo homen
	// 12 sínbolo mulher
	// 14 nota musical
	// 15 estrela
	// 16 triangulo lado direito
	// 17 triangulo esquerdo
	// 18 simbolo expandir imagem
	// 19 duas exclamações
	// 22 _ grosso
	// 24 seta para cima
	// 25 seta para baixo
	// 26 seta para direita
	// 27 seta para esquerda
	//  28 \_
	// 30 triangulo para cima
	// 31 triangulo para baixo
	// 64 arroba
	// 127 para cima oca
	// 134 xadrez
	// 135 xadrez grosso
	//172 _| pra cima
	// 171 <<
	// 169 copyright
	//168 ..
	// 165 moeda y
	// 164 o corrente
	//161 ! pra baixo
	// 174 o right
	// 176 bola pequena
	// 177 + ou -
	// 187 >>
	// 173 - alto
	////renderização de quadros
	//system("cls");
	

	apagartela();

	
	
	
	for (int b = 12-1; b >= 0; b--){ ///b coluna da matriz
	    ///mudar cor da nave
	    for (int i = 0; i <= 12-1; i++){ /// i linha da matriz
	    if (b == 0){
	    	textcolor(LIGHT_GREEN);
	        
	        if (recebeumunicao == true ){
	        textcolor(LIGHT_BLUE);
			}
			if (recebeuvida == true && dilatacaodotempoquantico == 1 ){
	        textcolor(LIGHT_CYAN);
	        PlaySound("vida.wav", NULL, SND_FILENAME | SND_ASYNC | SND_NODEFAULT | SND_NOSTOP);
			}
			if (levoudano == true && dilatacaodotempoquantico == 1 ){
	        textcolor(LIGHT_RED);
	        PlaySound("dano.wav", NULL, SND_FILENAME | SND_ASYNC | SND_NODEFAULT | SND_NOSTOP);
			}
			
			
		}
		///deixar lateral colorida de vermelho
		if ((i == 11 && b != 0) || (i == 0 && b != 0))
		{
			textcolor(LIGHT_RED);
			if (parartempo >= 1)
			 {
			  textcolor(YELLOW);	
			 }
		}
		/// fim deixar lateral colorida
		//// deixar "|" colorido de ciano alternado com branco
		if ( tabuleiro [b] [i] == "|" && i != 0 && i != 11 && variacao == false){
			textcolor(LIGHT_CYAN);
		}
		//// fim deixar "\" colorido
		//
		//// deixar "©" colorido alternado de marron e amarelo
		if ( tabuleiro [b] [i] == parartempochar && variacao == false){
			textcolor(YELLOW);
		}
		if ( tabuleiro [b] [i] == parartempochar && variacao == true){
			textcolor(BROWN);
		}
		//// fim deixar "©" colorido alternado de marron e amarelo
		//// deixar "°" colorido alternado de magenta e ciano
		if ( tabuleiro [b] [i] == vidachar && variacao == false){
			textcolor(LIGHT_MAGENTA);
		}
		if ( tabuleiro [b] [i] == vidachar && variacao == true){
			textcolor(LIGHT_CYAN);
		}
		//// fim deixar "°" colorido
		//// deixar "o" colorido alternado de azul e ciano
		if ( tabuleiro [b] [i] == municaochar && variacao == false){
			textcolor(LIGHT_CYAN);
		}
		if ( tabuleiro [b] [i] == municaochar && variacao == true){
			textcolor(LIGHT_BLUE);
		}
		//// fim deixar "o" colorido
		cout << tabuleiro [b] [i];
		////tudo que mudou de cor tem que voltar a cor do terminal para branco depois de escrever se nãoo resto que for escrito vai ficar com a cor ateriormente declarada
		/// após deixar parartempochar colorido deixar o resto branco 
		if ( tabuleiro [b] [i] == parartempochar){
			textcolor(WHITE);
		}
		/// fim após deixar "©" colorido deixar o resto branco
		/// após deixar "°" colorido deixar o resto branco 
		if ( tabuleiro [b] [i] == vidachar){
			textcolor(WHITE);
		}
		/// fim após deixar "°" colorido deixar o resto branco
		/// após deixar "o" colorido deixar o resto branco 
		if ( tabuleiro [b] [i] == municaochar){
			textcolor(WHITE);
		}
		/// fim após deixar "o" colorido deixar o resto branco 
		//// deixar "|" branco
		if ( tabuleiro [b] [i] == "|" && i != 0 && i != 11 && variacao == false){
			textcolor(WHITE);
		}
		/// fim após deixar "\" colorido deixar o resto branco 
		//// após deixar lateral colorida deixar o resto branco
		if (i == 11 && b != 0){
			textcolor(WHITE);
		}
		if (i == 0 && b != 0){
			textcolor(WHITE);
		}
		//// fim após deixar lateral colorida deixar o resto branco
		////PLACAR DE PONTUAÇAO
		if (b == 11 && i == 11){
		cout << "Pontuação: ";
		textcolor(YELLOW);
		cout <<	pontuacao;
		textcolor(WHITE);
		}
		////FIM PLACAR DE PONTUAÇAO
		/////corações
		if (b == 10 && i == 11){
		cout << "Vida: ";
		textcolor(LIGHT_RED);
		cout << vida << "     ";
		textcolor(WHITE);
		}
		///// fim corações
		}
		////voltar a cor para branco nave
		if (b == 0){
	    	textcolor(WHITE);
		}
	   pularlinha(1);
    /////
	
	/// atualização de quadros
    }
    
    
    
    //deixar o jogo mais fácil
	if (vida <= 3 && parartempo < 1){
	 dilatacaodotempoquanticomax = 20; //// aumenta o tempo para os asteroides descerem
	}
	
	///declarar se o jogador perdeu e finalizar o jogo
	if (vida <= 0){
    	string nomejogador;
    	perdeu(); /// texto quando perde
    	cout << " Precione qualquer tecla para proseguir";
    	PlaySound("morte.wav", NULL, SND_FILENAME | SND_NODEFAULT);
    	
		
		textcolor(BLACK);
    	system("PAUSE");
    	textcolor(WHITE);
    	
		system("cls");
    	
		cout << endl << " Digite seu nome para salvar seu histórico" << endl;
		cout << " de pontuação:" << endl << endl;
    	cin >> nomejogador;
    	system("cls");
    	
		fstream meuarquivo("pontuacao.txt", /*escrever no final do arquivo*/ ios::out | ios::app);
    	
    	   cout << " Placar de pontuação" << endl << endl;
    	   
		   if (meuarquivo.is_open())
		   {
		   meuarquivo << nomejogador << endl; ///escreve no arquivo
		   meuarquivo << pontuacao << endl;
		   meuarquivo.close(); /// fecha o arquivo
		   }
		  
		  
		  ifstream meuarquivo2("pontuacao.txt"); ////abre o arquivo
          if (meuarquivo2.is_open())
          {
              bool corvar= false;
              string linha;
              
		      while (! meuarquivo2.eof() ) 
                    {
                    if (corvar == true){ ///variação de sim ou não que define se o texto vai ser branco ou amarelo. pontuação é amarelo
					   textcolor(YELLOW);
					   corvar = false;
					   }
					else
					   {
					   corvar = true;
					   }
                    getline (meuarquivo2,linha); ///pega as linhas do texto e passa para a variável linha                              
                    if (linha != ""){
                    	cout << " " << linha ;
						cout << endl;
					}
                    textcolor(WHITE);
                    }
              meuarquivo2.close(); //// fecha o arquivo
          }
          
        textopcoes(); //// escreve as opções 
        
		tecla = getch();
		if (tecla == 0){ ///detecta se alguma tecla "F" foi precionada
         tecla=getch();//// pega a tecla "f"alguma coisa
         }
        if (tecla == 59){  // f1
          ///apagar pontução
		  ofstream ofs;
          ofs.open("pontuacao.txt", ofstream::out | ofstream::trunc); ////ofstream::trunc apaga dados do arquivo
          ofs.close();
		  system("cls");
		  cout << "Histórico de pontos apagado";
		  Sleep(2000);
		  system("cls");
		  main();	
		}
		if (tecla == 13){   //enter  reinicia o jogo
          system("cls");
		  main(); //// executa denovo a função main dentro dela mesma	
		}
		if (tecla == 60){   //f2  reiniciar o jogo com o menu inicial
          system("cls");
          primeiravez = true;
		  main();	
		}
		
		///deixar o system pause preto
		textcolor(BLACK);
		system("PAUSE");
		system("cls");
		main();
	}

    
    //// apagar os últimos tiros, caso contrário, fica alguns tiros no final da tela travados
   		 for(int c=1; c<11; c++){
   			 if(tabuleiro [11][c]=="|"){
   			 	tabuleiro [11][c]= " ";
   			 }
   		 }
    ////fim de pagar os últimos tiros
    
    /// retornar levou dano à falso
    levoudano = false;
    ///
    
    /// retornar levou dano à falso
    recebeuvida = false;
    ///
    
	//// fazer funcionar a variação de uma vez sim,uma vez não
    if (variacao == false){
		variacao = true;
	}
	else{
		variacao = false;
	}
	/// FIM DE fazer funcionar a variação de uma vez sim,uma vez não
	
    Sleep(70);
    }
    /// fim do while run que roda o jogo
    
	
	textcolor(BLACK);
	textbackground(BLACK);
	}
	////Sleep(500);


	





