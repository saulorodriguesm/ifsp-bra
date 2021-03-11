#include <stdio.h>
#include <locale.h>

//authors : Saulo Rodrigues Martins(BP3008053) e Gabriel Souza(BP3007944)

int main(){
	setlocale(LC_ALL,"");
	//pra n�o bugar os caracteres brasileiros (ex: �)
	
	int menu1=0, menu2, menuAux, idade, salario, escolaridade, vagas[5] = {5,3,2,1,2}, idadeCheck = 0, sexoCheck = 0, salCheck = 0, escolaridadeCheck = 0, aceitar, aviso=0;
	char sexo;
    //declara��o de variaveis
    
    while(menu1 == 0){
    // la�o usado para conseguir voltar a este menu quando eu estiver em "outra" tela
        printf("MENU 1 \n \n");
	    printf("Deseja iniciar o programa? (0 - Sim / 1 - Nao) \n");
	    scanf("%d", &menu1);
	    
	    if(menu1 == 0){
	    //caso o usuario digite o valor 0 (SIM), a variavel menu1 receber� o valor 0, iniciando o la�o do menu2
	    menu2 = 0;
		}else{
		//caso o usuario digite o valor 1 (ou qualquer outro), o programa se encerrar�.
			menu2 = 1;
		}
	    	
		while(menu2 == 0){
		    system("cls"); // Limpa a tela 
	        printf("MENU 2 \n \n");
	        printf("0 - Cadastrar idade\n");
	        printf("1 - Cadastrar sexo\n");
	        printf("2 - Cadastrar pretens�o salarial\n");
	        printf("3 - Cadastrar nivel de escolaridade\n");
	        printf("4 - Buscar vagas\n");
	        printf("5 - Quantidade de vagas disponiveis\n");
	        printf("6 - Voltar ao menu anterior"); // Todas as op��es s�o listadas na tela do usuario
	    
		    printf("\n\nDigite a op��o desejada: \n");
		    scanf("%d", &menuAux);
		    // o programa receber� um dos valores e entrar� no menu desejado
	
      		if(menuAux !=0 && menuAux !=1 && menuAux !=2 && menuAux !=3 && menuAux !=4 && menuAux !=5 && menuAux !=6){
      		// caso o usuario digite um valor n�o incluso na lista de menus, o programa far� o devido alerta
		        printf("Voc� s� pode selecionar uma das op��es acima \n");
		    }
		
		    if(menuAux ==0){
			    printf("\nDigite sua idade: \n");
			    scanf("%d", &idade);
			    idadeCheck = 1; // a variavel idadeCheck � utilizada para no menu 4 verificar se todas as informa��es foram digitadas
		    }
		
		    if(menuAux ==1){
			    printf("\nDigite o seu sexo (m - masculino ou f - feminino): \n");
			    scanf("%s", &sexo);
			    sexoCheck = 1; // a variavel sexoCheck � utilizada para no menu 4 verificar se todas as informa��es foram digitadas
		    }
		
		    if(menuAux ==2){
			    printf("\nDigite sua pretens�o salarial: \n");
			    scanf("%d", &salario);
			    salCheck = 1; // a variavel salCheck � utilizada para no menu 4 verificar se todas as informa��es foram digitadas
		    }
		
	       	if(menuAux ==3){
		    	printf("\nQual o seu n�vel de escolaridade? \n");
		    	printf("0 - Fundamental completo  \n");
		    	printf("1 - Ensino m�dio completo \n");
		    	printf("2 - Superior completo     \n");
		    	scanf("%d", &escolaridade);
		    	escolaridadeCheck = 1; // a variavel escolaridadeCheck � utilizada para no menu 4 verificar se todas as informa��es foram digitadas
	    	}
			
		    if(menuAux ==4){
		       if(escolaridadeCheck == 0 || salCheck == 0 || idadeCheck == 0 || sexoCheck ==0 ){
		       // caso o usuario n�o tenha preenchido alguma das informa��es, o programa solicitara que ele retorne e fa�a isso (Utilizando as variaveis check)
			   printf("Voc� precisa preencher todas as informa��es");
			   }else{
			   	//caso estejam devidamente preenchidas 
	
			   	if(salario<=1500 && idade>=18 && sexo == 'f' && escolaridade > 0 && vagas[0]>0){
			   	//caso as informa��es digitadas batam com as requisi��es da vaga, ela ser� mostrada ao usuario
			   		printf("\nH� vagas de RECEPCIONISTA dispon�veis\ndeseja aceitar a vaga? (1 - Sim ou 2 - Nao)\n");
			   		scanf("%d", &aceitar);
			   		if(aceitar == 1){
			   		//caso o usuario aceite a vaga, a vaga em quest�o ter� uma vaga a menos para o pr�ximo usuario
			   	    vagas[0] = vagas[0] - 1;
			   	    aviso = 1;
			   	    //a variavel aviso recebe o valor 1, desta maneira, n�o entrar� no meu IF da linha 128 que mostra a mensagem "Sem vagas disponiveis"
				    }else{}
				}
				
				if(salario<=900 && 16 <= idade <= 20 && sexo == 'm' && escolaridade >= 0 && vagas[1]>0){
				    printf("\nH� vagas de AJUDANTE GERAL disponiveis\nDeseja aceitar a vaga? (1- Sim ou 2 - Nao)\n");
					scanf("%d", &aceitar);
					if(aceitar == 1){
				    vagas[1] = vagas[1] - 1;
				    aviso = 1;
					}else{}
				}
				
				if(salario<=4500 && idade >= 30 && escolaridade > 1 && vagas[2]>0){
				    printf("\nH� vagas de GERENTE DE RH disponiveis\nDeseja aceitar a vaga? (1- Sim ou 2 - Nao)\n");
					scanf("%d", &aceitar);
					if(aceitar == 1){
				    vagas[2] = vagas[2] - 1;
				    aviso = 1;
					}else{}
				}
				
				if(salario<=3500 && idade >= 25 && escolaridade > 1 && vagas[3]>0){
				    printf("\nH� vagas de ANALISTA DE SISTEMAS disponiveis\nDeseja aceitar a vaga? (1- Sim ou 2 - Nao)\n");
					scanf("%d", &aceitar);
					if(aceitar == 1){
				    vagas[3] = vagas[3] - 1;
				    aviso = 1;
					}else{}
				}
				if(salario<=1200 && 35 <= idade <= 50 && escolaridade >= 0 && vagas[4]>0){
				    printf("\nH� vagas de PORTEIRO disponiveis\nDeseja aceitar a vaga? (1- Sim ou 2 - Nao)\n");
					scanf("%d", &aceitar);
					if(aceitar == 1){
				    vagas[4] = vagas[4] - 1;
				    aviso = 1;
					}else{}
				}
				if(aviso == 0){
				//se n�o estiver de acordo com nenhuma vaga, a variavel aviso continuara recebendo o valor 0, por tanto a mensagem ser� exibida
					printf("N�o h� vagas disponiveis de acordo com suas informa��es");
				}
			    }//fim do else	   
	    	}
	    	
	    	if(menuAux ==5){
	    	//mostra as vagas disponiveis 
	    		printf("Recepcionista: %d\n", vagas[0]);
				printf("Ajudante geral: %d\n", vagas[1]);
	    		printf("Gerente de RH: %d\n", vagas[2]);
	    		printf("Analista de sistemas: %d\n", vagas[3]);
	    		printf("Porteiro: %d\n", vagas[4]);
	    	}
		
	    	if(menuAux ==6){
			    printf("Deseja voltar ao primeiro menu? (0 - Sim / 1 - N�o)");
		        scanf("%d", &menu1);
		        //caso o usuario queira voltar ao menu 1, a var menu1 receber� o valor 0 (Valor da condi��o while do menu1), enquanto o menu2 receber� o valor 1 para quebrar o la�o do segundo menu
		        menu2 = 1;
		        system("cls");
     		}
     		
     		//ao fim de todas as opera��es, antes do programa encerrar o usuario ter� a op��o de voltar a um dos menus para n�o perder suas informa��es digitadas. 
     		printf("\n\n\nVoltar ao Menu 1 (Digite 1)");
			printf("\nContinuar no Menu 2 (Digite 0)\n");
     		scanf("%d", &menu2);
     		if(menu2 != 0 && menu2 != 1){
     			printf("Apenas 0 ou 1");
     			printf("\nVoltar ao Menu 1 (Digite 1)");
				printf("\nContinuar no Menu 2 (Digite 0)\n");
     			scanf("%d", &menu2);
			 } 
			 system("cls");
     	
		}
	}
	
	return 0;
}
		
		
