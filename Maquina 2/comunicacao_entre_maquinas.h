/* 
 * File:   comunicacao_entre_maquinas.h
 * Author: ictsam0100
 *
 * Created on 6 de Dezembro de 2018, 11:13
 */

int posicao_maq;
int n_posicao;
int n_bit;

short int le_bit(int n_bit); //lê bit especifico e verifica o valor "0 ou 1"
int ler_posicao_maquina_1 (void); //le os bits H3, H4 e H5 para verificar a posicao da maquina 1
void enviar_posicao_para_maquina_1 (int n_posicao); //aciona os outputs H0, H1 e H2 para enviar posicao para maquina 1   