#include <18F4620.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h> 
#include "main.h"
#include "pcf8574.c"
#include "pca9555.c"
#include "display_maq.c" 
#include "24c64.c"
#include "teclado_21_teclas.c"
#include "stepper_motor.c"
#include "I_O.c"
#include "comunicacao_entre_maquinas.c"
#include "telas_maquina_2.c"
#include "Axis_x.c"
#include "Axis_y.c"
#include "Axis_z.c"
#include "Axis_flip.c"
#include "movimentos_maq_2.c"
#include "maquinas_maq_2.c"
#include "Modelos_maq_2.c"
#include "att_telas_2.c"

// <editor-fold defaultstate="collapsed" desc="Interrupçoes de Tempo">

#int_timer0

void trata_timer0(void) {
    movimenta_eixo_x();
}
#int_timer1

void trata_timer1(void) {
    movimenta_eixo_y();
}
#int_timer2

void trata_timer2(void) {//Timer responsavel por contar tempo de execução
    set_timer2(0xff);
    ciclo++;
}
#int_timer3

void trata_timer3(void) {
     if (flgMove){
        movimenta_eixo_z();
    } else {
        movimenta_eixo_flip();
    }  
}

// </editor-fold>

void main() {    
    // <editor-fold defaultstate="collapsed" desc="Inicialização saidas e entradas">
    setup_adc(ADC_OFF);
    setup_ccp1(CCP_OFF);
    setup_ccp2(CCP_OFF);
    enable_interrupts(GLOBAL);
    setup_psp(PSP_DISABLED);
    output_low(step_y);
    output_low(dir_y);
    output_low(enable_y);
    output_low(step_x);
    output_low(dir_x);
    output_high(enable_x);
    output_low(step_z);
    output_low(dir_z);
    output_high(enable_z);
    output_low(step_flip);
    output_low(dir_flip);
    output_low(enable_flip);
    setup_timer_2(T2_DIV_BY_16, 255, 16);
    enable_interrupts(INT_TIMER2);
    inicializa_display();
    Init_Keyboard();
    Init_Sensores_porta1();
    Init_saidas();
    desaciona_todas_saidas();
    init_ext_eeprom();
    // </editor-fold>
    tela_apresentacao();
    home_solenoides();
    tela_iniciando_maquina();
    init_axis_x();
    init_axis_y();
    init_axis_z();
    init_axis_flip();
    posicao_maquina_2_default();    
    tela_principal();    
    while(run_ok){
        if (ciclo % 15 == 0){
            switch(menu_atual){
                case menu_principal: 
                    atualiza_tela_principal();
                break; 
                case menu_seleciona_maquina:
                    atualiza_tela_seleciona_maquina();
                break;
                case menu_manutencao_outra_maquina:
                    atualiza_tela_manutencao_outra_maquina();
                break;
                case menu_confirmaManutencao:
                    atualiza_tela_confirmaManutencao();
                break;
                case menu_edita_modelo:
                    atualiza_tela_edita_modelo();
                break;
                case menu_seleciona_debug:
                    atualiza_tela_seleciona_debug();
                break;
                case menu_edita_pontos_no_modelo:
                    atualiza_tela_edita_pontos_no_modelo();
                break;
                case menu_seleciona_pontos:
                    atualiza_tela_seleciona_pontos();
                break;
                case menu_dados_ponto:
                    atualiza_tela_dados_ponto();
                break;
                case menu_dados_ponto_2:
                    atualiza_tela_dados_ponto_2();
                break;
                case menu_excluir_modelo:
                    atualiza_tela_excluir_modelo();
                break;
                case menu_faltaSolda:
                    atualiza_tela_faltaSolda();
                break;
                case menu_seleciona_debug_2:
                    atualiza_tela_seleciona_debug_2();
                break;
                case menu_seleciona_manutencao:
                    atualiza_tela_seleciona_manutencao();
                break;                
                case menu_debug_entrada_1:
                    atualiza_tela_debug_entrada_1();
                break;
                case menu_debug_entrada_2:
                    atualiza_tela_debug_entrada_2();
                break;
                case menu_debug_entrada_3:
                    atualiza_tela_debug_entrada_3();
                break;
                case menu_debug_saida_1:
                    atualiza_tela_debug_saida_1();
                break;
                case menu_debug_saida_2:
                    atualiza_tela_debug_saida_2();
                break;
                case menu_debug_saida_3:
                    atualiza_tela_debug_saida_3();
                break;
                case menu_debug_saida_4:
                    atualiza_tela_debug_saida_4();
                break;
                case menu_programa_principal:
                    programa_principal_teste();
                break;
            }
        }
    }    
}