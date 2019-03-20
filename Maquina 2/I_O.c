#define     IN0				0
#define     IN1				1
#define     IN2				2
#define     IN3				3
#define     IN4				4
#define     IN5				5
#define     IN6				6
#define     IN7				7
#define     IN8				8
#define     IN9				9
#define     IN10			10
#define     IN11			11
#define     IN12			12
#define     IN13			13
#define     IN14			14
#define     IN15			15
#define     IN16			16
#define     IN17			17
#define     IN18			18
#define     IN19			19
#define     IN20			20
#define     IN21			21	
#define     IN22			22
#define     IN23			23
#define     IN24			24
#define     IN25			25
#define     IN26    		26
#define     IN27	    	27
	
#define     S_DEDO_IN_LS1      	    IN0  	//SENSOR AVANÇO CILINRO  1		
#define     S_DEDO_IN_LS2      	    IN1	 	//SENSOR AVANÇO CILINDRO 2			
#define     S_EMPURRADOR_IN_LS1	    IN2	 	//NT
#define     S_EMPURRADOR_IN_LS2     IN3	 	//SENSOR RECUO  CLP1			
#define     S_PRESSOR_LS2           IN4	 	//SENSOR AVANCO
#define     S_X_DIREITA			    IN5	 	//LIMITE DIREITA			
#define     S_X_ESQUERDA		    IN6	 	//LIMITE ESQUERDA			
#define     S_Y_FRENTE   		    IN7  	//LIMITE FRENTE			
#define     S_Y_ATRAS               IN8  	//LIMITE ATRAS	
#define     S_Y_DIREITA_PROT  	    IN9  	//LIMITE DIREITA DA OUTRA PLACA			
#define     S_Y_ESQUERDA_PROT       IN10 	//LIMITE ESQUERDA DA OUTRA PLACA	
#define     S_ROTACAO_LS1           IN11 	//SENSOR LIMITE GIRO HORARIO			
#define     S_FERRO_SOLDA1          IN12 	//SENSOR FERRO DE SOLDA 1 			
#define     S_Z_TOP	    		    IN13 	//SENSOR LIMITE  SUPEIOR			
#define     S_Z_BOTTOM			    IN14 	//SENSOR LIMITE  INFERIOR			
#define     S_FERRO_SOLDA2          IN15 	//SENSOR FERRO DE SOLDA 2			
#define     S_DEDO_OUT_LS1		    IN16 	//SENSOR AVANÇO
#define     S_DEDO_OUT_LS2	        IN17 	//SENSOR AVANÇO
#define     S_EMPURRADOR_OUT_LS1    IN18 	//SENSOR AVANÇO 			
#define     S_EMPURRADOR_OUT_LS2    IN19 	//SENSOR recuo	
#define     SENSOR_BOARD   			IN20 	
#define     S_BANDEJA               IN21 	//SENSOR BANDEJA CLP1 & CLP2
#define     S_FIO_SOLDA1	        IN22 	//SENSOR FIO DE SOLDA 1
#define     S_FIO_SOLDA2	        IN23 	//SENSOR FIO DE SOLDA 2
#define     S_FIO_SOLDA3	        IN24 	//SENSOR FIO DE SOLDA 3
#define     S_ESTEIRA               IN25 	//SENSOR DESLIGA ESTEIRA
#define     RESERVADO2 				IN26 	
#define     RESERVADO3              IN27    //RESET
   	 
// definição das saidas de comandos
#define     DEDO_ENTRADA				     7  //OUT 0
#define     EMPURRADOR_ENTRADA_SOL_EMPURRA   6  //OUT 1
#define     EMPURRADOR_ENTRADA_SOL_RETORNA 	 5  //OUT 2
#define     PRESSOR						     4  //OUT 3
#define     FERRO_SOLDA1				     3  //OUT 4
#define     FERRO_SOLDA2				     2  //OUT 5
#define     DEDO_SAIDA					     1  //OUT 6
#define     EMPURRADOR_SAIDA_SOL_EMPURRA     0  //OUT 7
#define     EMPURRADOR_SAIDA_SOL_RETORNA     15 //OUT 8
#define     ALIMENTADOR1					 14 //OUT 9  RL2
#define     ALIMENTADOR2					 13 //OUT 10 RL3
#define     ALIMENTADOR3					 12	//OUT 11 RL4 
#define     LIMPADOR					     11	//OUT 12 RL5
#define     RELE_ESTEIRA                     10 //OUT 13 
#define     LIMPA_BICO1                       8 //OUT 15   
#define     LIMPA_BICO2                       9 //OUT 14 

short int le_Input(int input_number){
	short int retorno;
    long int  data_sensores  = 0x0000;
	int		  data_sensores2 = 0x00;	
	if(input_number < 16) {
	 	data_sensores = le_PCA9555(0X03,0X00);
		if(bit_test (data_sensores,input_number) == 0){
			delay_us(30);
			if(bit_test (data_sensores,input_number) == 0) return retorno = true;
			return  retorno = false;
		}
        else 
            return  retorno = false;
	}		
	if((input_number >= 16) && (input_number < 24)){
		data_sensores2 = le_pcf8574A(0x04);
		if(bit_test (data_sensores2,input_number - 16) == 0) {
			delay_us(30);
			if(bit_test (data_sensores2,input_number - 16) == 0) return retorno = true;
			return    retorno = false;
		}
        else {
            return  retorno = false;
        }
	}
	if((input_number >= 24) && (input_number <= 27)) {	
		switch(input_number) {
			case 24:
                if(input(in24_bit) == 0) {
                    delay_us(30);
                    if(input(in24_bit) == 0) {
                        return retorno	= true;		
                        return retorno	= false;	
                    }
                }
                else {	
                    return retorno	= false;
                }
            break;
			case 25:
                if(input(in25_bit) == 0){
                    delay_us(30);
                    if(input(in25_bit) == 0) {
                        return retorno	= true;		
                        return retorno	= false;	
                    }
                }else {	
                    return retorno	= false;
                }
            break;
			case 26:
                if(input(in26_bit) == 0){
                    delay_us(30);
                    if(input(in26_bit) == 0) {
                        return retorno	= true;		
                        return retorno	= false;	
                    }
                }else{ 	
                    return retorno	= false;
                }
            break;
			case 27:
                if(input(in27_bit) == 0) {
                    delay_us(30);
                    if(input(in27_bit) == 0) {
                        return retorno	= true;		
                        return retorno	= false;	
                    }
                }else{ 	
                    return retorno	= false;
                }
            break;
	 	}
	}
}
void aciona_saida(long int output_word){
	int valor_lsb;
	int valor_msb;
	bit_clear(buffer_saida,output_word);
	valor_lsb = make8(buffer_saida,0);  
	valor_msb = make8(buffer_saida,1);
	escreve_PCA9555(0x02,0x02,valor_msb,valor_lsb);
}
void desaciona_saida(long int output_word){
	int valor_lsb;
	int valor_msb;
	bit_set(buffer_saida,output_word);
	valor_lsb = make8(buffer_saida,0);  
	valor_msb = make8(buffer_saida,1);
	escreve_PCA9555(0x02,0x02,valor_msb,valor_lsb);
}
void desaciona_todas_saidas(void){
	int valor_lsb;
	int valor_msb;
	buffer_saida = 0x0ffff;
	valor_lsb = make8(buffer_saida,0);  
	valor_msb = make8(buffer_saida,1);
	escreve_PCA9555(0x02,0x02,valor_msb,valor_lsb);
}
void Init_Sensores_porta1(void){
	escreve_PCA9555(0X03,0X06,0Xff,0xff);	// programa bits entradas 
}
void Init_saidas(void){
	escreve_PCA9555(0X02,0X06,0X00,0x00);	// programa bits saidas //como saida e os demais como entrada    
}