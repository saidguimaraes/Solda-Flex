#fuses HS,NOWDT,PROTECT,NOLVP,NODEBUG,MCLR
#use delay(clock=20000000)
#use i2c(master,sda = pin_C4,scl = pin_C3,force_hw)

#use 		standard_io(a)
#use 		standard_io(b)
#use 		standard_io(c)
#use 		standard_io(d)
#use 		standard_io(e)


#DEFINE   	RS    pin_B5			
#DEFINE	  	E	  pin_A0


#DEFINE		EEPROM_SCL	    	pin_C3
#DEFINE 	EEPROM_SDA		    pin_C4


#DEFINE     in24_bit			pin_B0
#DEFINE     in25_bit			pin_B1
#DEFINE     in26_bit			pin_B3
#DEFINE     in27_bit			pin_B4

#DEFINE     H0					pin_D7
#DEFINE     H1					pin_D6
#DEFINE     H2					pin_D5
#DEFINE     H3					pin_D4
#DEFINE     H4					pin_C7	
#DEFINE     H5					pin_C6

#DEFINE ALIMENTADOR        0 // 000         
#DEFINE HOME1              1 // 001
#DEFINE SOLDAGEM           3 // 010
#DEFINE HOME2              4 // 011
#DEFINE DISPENSADOR        5 // 100

#define ramp_idle 0
#define ramp_up   1
#define ramp_max  2
#define ramp_down 3
#define ramp_last 4

int menu_atual = 0;
short int entradas[27];

int ponteiro_lcd = 1;
int inicial_lcd = 0;
int final_lcd = 3;
int contador_lcd = 0;
signed int incremento = 1;

int posicao_atual;
int posicao_futura;
int posicao_outra_maquina;
int32 ciclo;
short run_ok = 1;
short exit = TRUE;
short flgMove = TRUE;
short run_flg_flip = FALSE;

int modelo = 1;
signed long int x[21] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
signed long int y[21]  = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
signed long int z[21]  = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
long int t_solda[21]  = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
long int t_wait[21]  = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
long int tipo[21]  = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
long int pontos_no_modelo = 0;
long int habilitado[21] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
long int numeroFerros[21]  = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
long int t_solda2[21]  = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
long int t_solda3[21]  = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
long int limpar[21]  = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

