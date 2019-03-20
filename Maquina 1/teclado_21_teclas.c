#define		F1					10
#define		F2					11
#define     F3					12
#define		F4					13
#define     SETA_SUPERIOR   	14
#define     SETA_INFERIOR   	15 
#define		SETA_DIREITA    	16 
#define     SETA_ESQUERDA  	    17
#define     ESC					18
#define     ENTER				19	
#define     MENU				20

void Init_Keyboard(void){
	escreve_PCA9555(0X01,0X06,0Xff,0xf8);// programa bit 0,bit 1,bit 2  como saida e os demais como entrada
 	escreve_PCA9555(0X01,0X02,0X00,0X07);//coloca colunas em  high level
}
unsigned long int  Get_Key(void){	
	long int dado = 0x0000;
	int    coluna = 0x06;
    int    mascara = 0x7f;
	long int i;
	for (i = 0 ; i < 3 ; i++) {
    	coluna -= i;
		escreve_PCA9555(0X01,0X02,0X00,coluna);     // coloca coluna  em  low level
		dado =  le_PCA9555(0X01,0X00) >> 3;         // desloca bits
		dado &= mascara;  							// mascara bits
        dado = 127 - dado;                           
		if(dado != 0) {
            i = i << 8;
            dado |= i ;
            break;
		}		
	}		
    return(dado);
}
int Teclado(void) {
 // lê o teclado
 // se nenhuma tecla acionada retorna 0xff
 // se acionada retorna o codigo da tecla
   unsigned long int codigo_teclado = 0x0000;
   int key_code = 0x00;
   codigo_teclado = Get_Key();
   if(codigo_teclado == 0x00) return( key_code =0xff);	
	switch(codigo_teclado){
		case 320:key_code=0;
				break;
		case 8:	key_code=1;
				break;
		case 264:key_code=2;
				break;
		case 520:key_code=3;
				break;	
		case 16: key_code=4;
				break;
		case 272:key_code=5;
				break;
		case 528:key_code=6;
				break;
		case 32:key_code=7;
				break;
		case 288:key_code=8;
				break;
		case 544:key_code=9;
                break;
		case 1:	key_code=F1;
                break;
		case 513:key_code=F2;
                break;
		case 4:	key_code=F3;
                break;
		case 516:key_code=F4;
                break;
		case 64:key_code=ESC;
                break;
		case 576:key_code=ENTER;
                break;
		case 257:key_code=SETA_SUPERIOR ;
                break;
		case 2:	key_code=SETA_ESQUERDA ;
                break;
		case 514:key_code=SETA_DIREITA ;
                break;
		case 260:key_code=SETA_INFERIOR;
                break;
		case 258:key_code=MENU;
                break;
	    default:
				break;
	}
	return( key_code );
}
void espera_desacionar_teclas(void) {
  int key_code = 0x00;
  key_code = Teclado();
  while(key_code != 0xff){
    key_code = Teclado();
  }
}