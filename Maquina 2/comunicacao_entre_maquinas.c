#include "comunicacao_entre_maquinas.h"

short int le_bit(int n_bit) {
    short int retorno;

    if (input(n_bit) == 1) {
        return retorno = 1;
        delay_us(30);
    }
    if (input(n_bit) == 0) {
        return retorno = 0;
        delay_us(30);
    }
}
int le_posicao_outra_maquina (void){
    int x = le_bit(H3);
    int y = le_bit(H4);
    int z = le_bit(H5);
    
    switch (z) {
        case 0:
            switch (y) {
                case 0:
                    switch (x) {
                        case 0:
                            posicao_maq = ALIMENTADOR;
                        break;
                        case 1:
                            posicao_maq = HOME1;
                        break;
                    }
                break;
                case 1:
                    switch (x) {
                        case 0:
                            posicao_maq = SOLDAGEM;
                        break;
                        case 1:
                            posicao_maq = HOME2;
                        break;
                    }
                break;                    
            }
        break;
        case 1:
            switch (y) {
                case 0:
                    switch (x) {
                        case 0:
                            posicao_maq = DISPENSADOR;
                        break;
                        case 1:
                            
                        break;
                    }
                break;
                case 1:
                    switch (x) {
                        case 0:
                            
                        break;
                        case 1:
                            
                        break;
                    }
                break; 
            }                
        break;
    }
    return posicao_maq;
}
void envia_posicao_para_outra_maquina (int n_posicao) {
    switch (n_posicao){
        case ALIMENTADOR:
            output_low(H0);
            output_low(H1);
            output_low(H2);
        break;
        case HOME1:
            output_high(H0);
            output_low (H1);
            output_low (H2);
        break;
        case SOLDAGEM:
            output_low (H0);
            output_high(H1);
            output_low (H2);
        break;
        case HOME2:
            output_high (H0);
            output_high(H1);
            output_low(H2);
        break;
        case DISPENSADOR:
            output_low (H0);
            output_low (H1);
            output_high(H2);
        break;
    }
}
