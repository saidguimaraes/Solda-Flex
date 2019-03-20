#include "att_telas_2.h"

void atualiza_tela_principal(){
    switch (Teclado()){
        case MENU:
            printf(lcd_putc, "\f"); // limpa display
            printf(lcd_putc, "  CARREGANDO MODELO \n\r");
            ler_modelo_memoria(modelo);
            menu_atual = menu_seleciona_maquina;
            tela_seleciona_maquina();            
        break;
        case ENTER:
            printf(lcd_putc, "\f"); // limpa display
            printf(lcd_putc, "  CARREGANDO MODELO \n\r");
            ler_modelo_memoria(modelo);
            exit = TRUE;
            menu_atual = menu_programa_principal;
            tela_programa_principal();
        break;
        case SETA_SUPERIOR:
            if (modelo < 4){
                modelo ++;
            }
            menu_atual = menu_principal;
            tela_principal();
        break;
        case SETA_INFERIOR:
            if (modelo > 1){
                modelo --;
            }
            menu_atual = menu_principal;
            tela_principal();
        break;
    }
}

void atualiza_tela_seleciona_maquina(){
    switch (Teclado()){
        case F1:
            menu_atual = menu_manutencao_outra_maquina;
            tela_manutencao_outra_maquina();
        break;
        case F2:
            envia_maquina_para_posicao(ALIMENTADOR);         
            menu_atual = menu_edita_modelo;
            tela_edita_modelo();            
        break;
        case ESC:
            menu_atual = menu_principal;
            tela_principal();
        break;
    }
}
void atualiza_tela_manutencao_outra_maquina(){
    switch(Teclado()){
        case ESC:
            menu_atual = menu_confirmaManutencao;
            tela_confirmaManutencao();
        break;
    }
}
void atualiza_tela_edita_modelo(){
    switch (Teclado()){
        case F1:
            menu_atual = menu_seleciona_debug;
            tela_seleciona_debug();
        break;
        case F2:
            menu_atual = menu_excluir_modelo;
            tela_excluir_modelo();
        break;
        case ESC:
            envia_maquina_para_posicao(HOME1);
            menu_atual = menu_principal;
            tela_principal();
        break;
    }
}
void atualiza_tela_seleciona_debug (){
    switch(Teclado()){
        case F1:
            menu_atual = menu_seleciona_debug_2;
            tela_seleciona_debug_2();
        break;
        case F2:
            menu_atual = menu_seleciona_manutencao;
            tela_seleciona_manutencao();
        break;
        case ESC:
            menu_atual = menu_edita_modelo;
            tela_edita_modelo();
        break;
    }
}
void atualiza_tela_seleciona_debug_2 (){
    short int x;
    short int k = TRUE;
    short int b;
    switch(Teclado()){
        case F2:
            if (pontos_no_modelo > 0){
                b = le_Input(S_BANDEJA);
                if (b == 0){
                    liga_esteira();
                    x = le_Input(S_ESTEIRA);
                    while ((x == 0)&&(k == TRUE)){
                        printf(lcd_putc, "\f"); //limpa display
                        printf(lcd_putc, "   ESPERANDO PLACA   \n\r");
                        printf(lcd_putc, "     NA ESTEIRA     \n\r");
                        x = le_Input(S_ESTEIRA);
                        if (Teclado() == ESC){
                            k = FALSE;
                        }                   
                    }
                    if (k == TRUE){
                        desliga_esteira();
                        empurra_placa();
                        liga_pressor();
                        envia_maquina_para_posicao(HOME1);
                        menu_atual = menu_seleciona_pontos;
                        tela_seleciona_pontos();
                    } else {
                        desliga_esteira();
                        menu_atual = menu_seleciona_debug_2;
                        tela_seleciona_debug_2();
                    }
                } else {
                    liga_pressor();
                    envia_maquina_para_posicao(HOME1);
                    menu_atual = menu_seleciona_pontos;
                    tela_seleciona_pontos();
                }                              
            } else {
                printf(lcd_putc, "\f"); // limpa display
                printf(lcd_putc, " VERIFIQUE O NUMERO \n\r");
                printf(lcd_putc, " DE PONTOS NO MODELO\n\r");
                delay_ms(3000);
                menu_atual = menu_seleciona_debug_2;
                tela_seleciona_debug_2();
            }
        break;
        case F1:
            menu_atual = menu_edita_pontos_no_modelo;
            tela_edita_pontos_no_modelo();
        break;
        case ESC:
            menu_atual = menu_seleciona_debug;
            tela_seleciona_debug();
        break;
    }
}
void atualiza_tela_edita_pontos_no_modelo(){
    switch(Teclado()){
        case SETA_SUPERIOR:
            if (pontos_no_modelo < 20){
                pontos_no_modelo = pontos_no_modelo + 1;                
            }
            menu_atual = menu_edita_pontos_no_modelo;
            tela_edita_pontos_no_modelo();
        break;
        case SETA_INFERIOR:
            if (pontos_no_modelo > 0){
                pontos_no_modelo = pontos_no_modelo -1;
            }
            menu_atual = menu_edita_pontos_no_modelo;
            tela_edita_pontos_no_modelo();
        break;
        case ESC:
            menu_atual = menu_seleciona_debug_2;
            tela_seleciona_debug_2();
        break;
        case ENTER:
            printf(lcd_putc, "\f"); // limpa display
            printf(lcd_putc, "   GRAVANDO PONTOS  \n\r");
            escrever_pontos_no_modelo(modelo,pontos_no_modelo);
            ler_modelo_memoria(modelo);
            printf(lcd_putc, "\f"); // limpa display
            printf(lcd_putc, "PONTOS ATUALIZADOS\n\r");
            delay_ms(1000);
            menu_atual = menu_seleciona_debug_2;
            tela_seleciona_debug_2();
        break;
    }
}
void atualiza_tela_excluir_modelo(){
    switch (Teclado()){
        case ENTER:
            printf(lcd_putc, "\f"); // limpa display
            printf(lcd_putc, "  EXCLUINDO MODELO  \n\r");
            delay_ms(1000);
            excluir_modelo_memoria(modelo);
            ler_modelo_memoria(modelo);
            printf(lcd_putc, "\f"); // limpa display
            printf(lcd_putc, "   MODELO EXCUIDO   \n\r");
            delay_ms(1000);
            menu_atual = menu_edita_modelo;
            tela_edita_modelo();
        break;
        case ESC:
            menu_atual = menu_edita_modelo;
            tela_edita_modelo();
        break;
    }
}
void atualiza_tela_seleciona_pontos(){
    switch(Teclado()){
        case SETA_SUPERIOR:
            contador_lcd --;
            if  ((contador_lcd > 0)&&(contador_lcd < pontos_no_modelo)){
                if (ponteiro_lcd == 1){
                    inicial_lcd --;
                    final_lcd --;
                    ponteiro_lcd = 1;
                } else {
                    ponteiro_lcd --;
                }                
            } else {
                contador_lcd = 0;
                inicial_lcd = 0;
                final_lcd = 3;
                ponteiro_lcd = 1;
            }
            menu_atual = menu_seleciona_pontos;
            tela_seleciona_pontos();
        break;
        case SETA_INFERIOR:
            contador_lcd ++;
            if (contador_lcd < pontos_no_modelo){
                if (ponteiro_lcd == 4){
                    inicial_lcd ++;
                    final_lcd ++;
                    ponteiro_lcd = 4;
                } else {
                    ponteiro_lcd ++;
                }
            } else {
                contador_lcd = pontos_no_modelo-1;
            }
            menu_atual = menu_seleciona_pontos;
            tela_seleciona_pontos();
        break;
        case ENTER:
            ponteiro_lcd = 1;
            inicial_lcd = 0;
            final_lcd = 3;
            if ((contador_lcd >= 14)&&(modelo == 1)){
                contador_lcd ++;
            }
            motor_run_z(0, 19);
            while ((run_flg_z));
            if ((y[contador_lcd] > 0) && (x[contador_lcd]> 0)){                
                motor_run_x(x[contador_lcd],19);
                while ((run_flg_x));
                motor_run_y(y[contador_lcd],19);
                while ((run_flg_y));
                posicao_atual = SOLDAGEM;
                envia_posicao_para_outra_maquina(SOLDAGEM);
            } else {
                envia_maquina_para_posicao(SOLDAGEM);
                x[contador_lcd] = motor_pos_x;
                y[contador_lcd] = motor_pos_y;
                z[contador_lcd] = motor_pos_z;
            }
            menu_atual = menu_dados_ponto;
            tela_dados_ponto(contador_lcd);
        break;
        case ESC:
            envia_maquina_para_posicao(HOME1);
            envia_maquina_para_posicao(ALIMENTADOR);
            desliga_pressor();
            motor_run_z(0, 19);
            while ((run_flg_z));
            ponteiro_lcd = 1;
            inicial_lcd = 0;
            final_lcd = 3;
            contador_lcd = 0;
            menu_atual = menu_seleciona_debug;
            tela_seleciona_debug();
        break;
    }
}
void atualiza_tela_dados_ponto(){
    short int f;
    switch (Teclado()){
        case SETA_SUPERIOR:
            if (y[contador_lcd] > 0){
                y[contador_lcd] = y[contador_lcd] - incremento;
                if (y[contador_lcd] <= 0) {
                    motor_run_y(0,19);
                    while ((run_flg_y));
                } else {
                    motor_run_y(y[contador_lcd],19);
                    while ((run_flg_y));
                }            
            }
            menu_atual = menu_dados_ponto;
            tela_dados_ponto(contador_lcd);
        break;
        case SETA_INFERIOR:
            y[contador_lcd] = y[contador_lcd] + incremento;
            motor_run_y(y[contador_lcd],19);
            while ((run_flg_y));
            menu_atual = menu_dados_ponto;
            tela_dados_ponto(contador_lcd);
        break;
        case SETA_DIREITA:
            x[contador_lcd] = x[contador_lcd] + incremento;
            motor_run_x(x[contador_lcd],19);
            while ((run_flg_x));
            menu_atual = menu_dados_ponto;
            tela_dados_ponto(contador_lcd);
        break;
        case SETA_ESQUERDA:
            if (x[contador_lcd] > 0){
                x[contador_lcd] = x[contador_lcd] - incremento;
                if (x[contador_lcd] <= 0){
                    motor_run_x(0,19);
                    while ((run_flg_x));
                } else{
                    motor_run_x(x[contador_lcd],19);
                    while ((run_flg_x));
                }                
            }
            menu_atual = menu_dados_ponto;
            tela_dados_ponto(contador_lcd);
        break;
        case F2:
            if (z[contador_lcd] > 0){
                z[contador_lcd] = z[contador_lcd] -incremento;
                if (z[contador_lcd] <= 0){
                    motor_run_z(0,19);
                    while ((run_flg_z));
                } else {
                    motor_run_z(z[contador_lcd],19);
                    while ((run_flg_z));
                }
            }
            menu_atual = menu_dados_ponto;
            tela_dados_ponto(contador_lcd);
        break;
        case F4:       
            z[contador_lcd] = z[contador_lcd] +incremento;
            motor_run_z(z[contador_lcd],19);
            while ((run_flg_z));
            menu_atual = menu_dados_ponto;
            tela_dados_ponto(contador_lcd);
        break;
        case 1:
            switch (tipo[contador_lcd]){
                case 0:
                    tipo[contador_lcd] = 1;
                break;
                case 1:
                    tipo[contador_lcd] = 0;
                break;
            }
            menu_atual = menu_dados_ponto;
            tela_dados_ponto(contador_lcd);
        break;
        case 2:
            if (habilitado[contador_lcd] == TRUE){
                habilitado[contador_lcd] = FALSE;
            } else {
                habilitado[contador_lcd] = TRUE;
            }            
            menu_atual = menu_dados_ponto;
            tela_dados_ponto(contador_lcd);
        break;
        case 8:          
            sobe_ferros();
            desliga_pressor();
        break;
        case 0:
            sobe_ferros();
            if (numeroFerros[contador_lcd] == 0){
                desce_ferros(0);
            }
            if (numeroFerros[contador_lcd] == 1){
                desce_ferros(1);
            }
            if (numeroFerros[contador_lcd] == 2){
                desce_ferros(2);
            }
            if (numeroFerros[contador_lcd] == 3){
                desce_ferros(3);
            }
            liga_pressor();
        break;
        case 3:
            switch (numeroFerros[contador_lcd]){
                case 0:
                    numeroFerros[contador_lcd] = 1;
                break;
                case 1:
                    numeroFerros[contador_lcd] = 2;
                break;
                case 2:
                    numeroFerros[contador_lcd] = 3;
                break;
                case 3:
                    numeroFerros[contador_lcd] = 0;
                break;
            }            
            menu_atual = menu_dados_ponto;
            tela_dados_ponto(contador_lcd);
        break;
        case 4:
            switch (incremento){
                case 1:
                    incremento = 10;
                break;
                case 10:
                    incremento = 50;
                break;
                case 50:
                    incremento = 1;
                break;
            }            
            menu_atual = menu_dados_ponto;
            tela_dados_ponto(contador_lcd);
        break;
        case 5:
            switch (limpar[contador_lcd]){
                case 0:
                    limpar[contador_lcd] = 1;
                break;
                case 1:
                    limpar[contador_lcd] = 0;
                break;
            }            
            menu_atual = menu_dados_ponto;
            tela_dados_ponto(contador_lcd);
        break;
        case F1:
            if ((numeroFerros[contador_lcd] == 0)||(numeroFerros[contador_lcd] == 2)){
                t_solda[contador_lcd] = 0;
            }
            if ((numeroFerros[contador_lcd] == 0)||(numeroFerros[contador_lcd] == 1)){
                t_solda3[contador_lcd] = 0;
            }
            printf(lcd_putc, "\f"); // limpa display
            printf(lcd_putc, "   GRAVANDO PONTO   \n\r");
            delay_ms(2000);
            escrever_ponto_memoria(modelo,contador_lcd);
            printf(lcd_putc, "\f"); // limpa display
            printf(lcd_putc, "    PONTO GRAVADO   \n\r");
            delay_ms(2000);
            menu_atual = menu_seleciona_pontos;
            tela_seleciona_pontos();
            contador_lcd = 0;
            incremento = 1;
            motor_run_z(0, 19);
            while ((run_flg_z));
            sobe_ferros();
        break;
        case F3:            
            menu_atual = menu_dados_ponto_2;
            if (numeroFerros[contador_lcd] == 0){
                tela_dados_ponto_5(contador_lcd);
            }
            if (numeroFerros[contador_lcd] == 1){
                tela_dados_ponto_4(contador_lcd);
            }
            if (numeroFerros[contador_lcd] == 2){
                tela_dados_ponto_3(contador_lcd);
            }
            if (numeroFerros[contador_lcd] == 3){
                tela_dados_ponto_2(contador_lcd);
            }
            incremento = 1;
            motor_run_z(0, 19);
            while ((run_flg_z));
            sobe_ferros();
        break;
        case ESC:
            incremento = 1;
            contador_lcd = 0;
            motor_run_z(0, 19);
            while ((run_flg_z));
            sobe_ferros();
            menu_atual = menu_seleciona_pontos;
            tela_seleciona_pontos();
        break;
        case ENTER:
            incremento = 1;
            f = statusSolda();
            if (f == 1){
                soldar_teste(tipo[contador_lcd],contador_lcd);
            } else {
                printf(lcd_putc, "\f"); // limpa display
                printf(lcd_putc, "    SEM SOLDA NOS   \n\r");
                printf(lcd_putc, "    ALIMENTADORES   \n\r");
                delay_ms(1000);
            }
            motor_run_y(y[contador_lcd],19);
            while ((run_flg_y));
            motor_run_x(x[contador_lcd],19);
            while ((run_flg_x));
            menu_atual = menu_dados_ponto;
            tela_dados_ponto(contador_lcd);
        break; 
    }
}
void atualiza_tela_dados_ponto_2(){
    short f;
    switch (Teclado()){
        case 1:
            if (numeroFerros[contador_lcd] == 1){
                t_solda[contador_lcd] = t_solda[contador_lcd] + incremento;
                tela_dados_ponto_4(contador_lcd);
            }
            if (numeroFerros[contador_lcd] == 3){
                t_solda[contador_lcd] = t_solda[contador_lcd] + incremento;
                tela_dados_ponto_2(contador_lcd);
            }            
            menu_atual = menu_dados_ponto_2;
        break;
        case 4:
            if (numeroFerros[contador_lcd] == 1){
                if (t_solda[contador_lcd] > 0){
                    t_solda[contador_lcd] = t_solda[contador_lcd] - incremento;
                }
                tela_dados_ponto_4(contador_lcd);
            }
            if (numeroFerros[contador_lcd] == 3){
                if (t_solda[contador_lcd] > 0){
                    t_solda[contador_lcd] = t_solda[contador_lcd] - incremento;
                }
                tela_dados_ponto_2(contador_lcd);
            }            
            menu_atual = menu_dados_ponto_2;
        break;
        case 2:
            if (numeroFerros[contador_lcd] == 0){
                t_solda2[contador_lcd] = t_solda2[contador_lcd] + incremento;
                tela_dados_ponto_5(contador_lcd);
            }
            if (numeroFerros[contador_lcd] == 1){
                t_solda2[contador_lcd] = t_solda2[contador_lcd] + incremento;
                tela_dados_ponto_4(contador_lcd);
            }
            if (numeroFerros[contador_lcd] == 2){
                t_solda2[contador_lcd] = t_solda2[contador_lcd] + incremento;
                tela_dados_ponto_3(contador_lcd);
            }
            if (numeroFerros[contador_lcd] == 3){
                t_solda2[contador_lcd] = t_solda2[contador_lcd] + incremento;
                tela_dados_ponto_2(contador_lcd);
            }
            menu_atual = menu_dados_ponto_2;
        break;
        case 5:
            if (numeroFerros[contador_lcd] == 0){
                if (t_solda2[contador_lcd] > 0){
                    t_solda2[contador_lcd] = t_solda2[contador_lcd] - incremento;
                }
                tela_dados_ponto_5(contador_lcd);
            }
            if (numeroFerros[contador_lcd] == 1){
                if (t_solda2[contador_lcd] > 0){
                    t_solda2[contador_lcd] = t_solda2[contador_lcd] - incremento;
                }
                tela_dados_ponto_4(contador_lcd);
            }
            if (numeroFerros[contador_lcd] == 2){
                if (t_solda2[contador_lcd] > 0){
                    t_solda2[contador_lcd] = t_solda2[contador_lcd] - incremento;
                }
                tela_dados_ponto_3(contador_lcd);
            }
            if (numeroFerros[contador_lcd] == 3){
                if (t_solda2[contador_lcd] > 0){
                    t_solda2[contador_lcd] = t_solda2[contador_lcd] - incremento;
                }
                tela_dados_ponto_2(contador_lcd);
            }
            menu_atual = menu_dados_ponto_2;
        break;
        case 3:
            if (numeroFerros[contador_lcd] == 2){
                t_solda3[contador_lcd] = t_solda3[contador_lcd] + incremento;
                tela_dados_ponto_3(contador_lcd);
            }
            if (numeroFerros[contador_lcd] == 3){
                t_solda3[contador_lcd] = t_solda3[contador_lcd] + incremento;
                tela_dados_ponto_2(contador_lcd);
            }            
            menu_atual = menu_dados_ponto_2;
        break;
        case 6:
            if (numeroFerros[contador_lcd] == 2){
                if (t_solda3[contador_lcd] > 0){
                    t_solda3[contador_lcd] = t_solda3[contador_lcd] - incremento;
                }
                tela_dados_ponto_3(contador_lcd);
            }
            if (numeroFerros[contador_lcd] == 3){
                if (t_solda3[contador_lcd] > 0){
                    t_solda3[contador_lcd] = t_solda3[contador_lcd] - incremento;
                }
                tela_dados_ponto_2(contador_lcd);
            }            
            menu_atual = menu_dados_ponto_2;
        break;
        case 8:
            t_wait[contador_lcd] = t_wait[contador_lcd] + incremento;
            if (numeroFerros[contador_lcd] == 0){                
                tela_dados_ponto_5(contador_lcd);
            }
            if (numeroFerros[contador_lcd] == 1){                
                tela_dados_ponto_4(contador_lcd);
            }
            if (numeroFerros[contador_lcd] == 2){                
                tela_dados_ponto_3(contador_lcd);
            }
            if (numeroFerros[contador_lcd] == 3){                
                tela_dados_ponto_2(contador_lcd);
            }            
            menu_atual = menu_dados_ponto_2;
        break;
        case 0:
            if (t_wait[contador_lcd] > 0){
                t_wait[contador_lcd] = t_wait[contador_lcd] - incremento;
            }
            if (numeroFerros[contador_lcd] == 0){                
                tela_dados_ponto_5(contador_lcd);
            }
            if (numeroFerros[contador_lcd] == 1){                
                tela_dados_ponto_4(contador_lcd);
            }
            if (numeroFerros[contador_lcd] == 2){                
                tela_dados_ponto_3(contador_lcd);
            }
            if (numeroFerros[contador_lcd] == 3){                
                tela_dados_ponto_2(contador_lcd);
            }            
            menu_atual = menu_dados_ponto_2;
        break;
        case 7:
            switch (incremento){
                case 1:
                    incremento = 10;
                break;
                case 10:
                    incremento = 50;
                break;
                case 50:
                    incremento = 1;
                break;
            }            
            if (numeroFerros[contador_lcd] == 0){                
                tela_dados_ponto_5(contador_lcd);
            }
            if (numeroFerros[contador_lcd] == 1){                
                tela_dados_ponto_4(contador_lcd);
            }
            if (numeroFerros[contador_lcd] == 2){                
                tela_dados_ponto_3(contador_lcd);
            }
            if (numeroFerros[contador_lcd] == 3){                
                tela_dados_ponto_2(contador_lcd);
            }            
            menu_atual = menu_dados_ponto_2;
        break;
        case F3:
            menu_atual = menu_dados_ponto;
            tela_dados_ponto(contador_lcd);
            incremento = 1;
            motor_run_z(0, 19);
            while ((run_flg_z));
            sobe_ferros();
        break;
        case F1:
            if ((numeroFerros[contador_lcd] == 0)||(numeroFerros[contador_lcd] == 2)){
                t_solda[contador_lcd] = 0;
            }
            if ((numeroFerros[contador_lcd] == 0)||(numeroFerros[contador_lcd] == 1)){
                t_solda3[contador_lcd] = 0;
            }
            printf(lcd_putc, "\f"); // limpa display
            printf(lcd_putc, "   GRAVANDO PONTO   \n\r");
            delay_ms(1000);
            escrever_ponto_memoria(modelo,contador_lcd);
            printf(lcd_putc, "\f"); // limpa display
            printf(lcd_putc, "    PONTO GRAVADO   \n\r");
            delay_ms(1000);
            menu_atual = menu_seleciona_pontos;
            tela_seleciona_pontos();
            contador_lcd = 0;
            motor_run_z(0, 19);
            while ((run_flg_z));
            sobe_ferros();
        break;
        case ESC:
            incremento = 1;
            contador_lcd = 0;
            motor_run_z(0, 19);
            while ((run_flg_z));
            sobe_ferros();
            menu_atual = menu_seleciona_pontos;
            tela_seleciona_pontos();
        break;
        case ENTER:
            f = statusSolda();
            if (f == 1){
                soldar_teste(tipo[contador_lcd],contador_lcd);
            } else {
                printf(lcd_putc, "\f"); // limpa display
                printf(lcd_putc, "    SEM SOLDA NOS   \n\r");
                printf(lcd_putc, "    ALIMENTADORES   \n\r");
                delay_ms(1000);
            }
            motor_run_y(y[contador_lcd],19);
            while ((run_flg_y));
            motor_run_x(x[contador_lcd],19);
            while ((run_flg_x));
            if (numeroFerros[contador_lcd] == 0){
                tela_dados_ponto_5(contador_lcd);
            }
            if (numeroFerros[contador_lcd] == 1){
                tela_dados_ponto_4(contador_lcd);
            }
            if (numeroFerros[contador_lcd] == 2){
                tela_dados_ponto_3(contador_lcd);
            }
            if (numeroFerros[contador_lcd] == 3){
                tela_dados_ponto_2(contador_lcd);
            }
            menu_atual = menu_dados_ponto_2;            
        break; 
    }
}

void atualiza_tela_faltaSolda(){
    short int x;
    switch (Teclado()){
        case ENTER:
            x = statusSolda();
            printf(lcd_putc, "\f"); // limpa display
            printf(lcd_putc, "  VERIFICANDO SOLDA \n\r");
            delay_ms(1000);
            if (x == 0){
                printf(lcd_putc, "\f"); // limpa display
                printf(lcd_putc, " VERIFIQUE NOVAMENTE\n\r");
                printf(lcd_putc, "       A SOLDA      \n\r");
                delay_ms(1000);
                menu_atual = menu_faltaSolda;
                tela_faltaSolda();
            } else {
                printf(lcd_putc, "\f"); // limpa display
                printf(lcd_putc, "      SOLDA OK      \n\r");
                delay_ms(1000);
                menu_atual = menu_principal;
                tela_principal();
            }          
        break;
    }
}

void atualiza_tela_confirmaManutencao (){
    switch (Teclado()){
        case ENTER:
            menu_atual = menu_seleciona_maquina;
            tela_seleciona_maquina();         
        break;
        case ESC:
            tela_manutencao_outra_maquina();
            menu_atual = menu_manutencao_outra_maquina;      
        break;
    }
}

void atualiza_tela_seleciona_manutencao(){
    switch(Teclado())    {
        case F1: 
            menu_atual = menu_debug_entrada_1;
            tela_debug_entrada_1();
        break;
        case F2:
            menu_atual = menu_debug_saida_1;
            tela_debug_saida_1();
        break;
        case ESC:
            menu_atual = menu_seleciona_debug;
            tela_seleciona_debug();
        break;
    }
}
void atualiza_tela_debug_entrada_1(){
    while (Teclado() == 0xff ){
        for (int i=0; i<9; i++){
            if (le_Input(i) == true){
                entradas [i] = 1;
            } else {
                entradas [i] = 0;
            }
        }
        tela_debug_entrada_1();
    }
    switch(Teclado()){
        case SETA_DIREITA: 
            menu_atual = menu_debug_entrada_2;
            tela_debug_entrada_2();
            break;        
        case ESC:
            menu_atual = menu_seleciona_manutencao;
            tela_seleciona_manutencao();
        break;
    }
}
void atualiza_tela_debug_entrada_2 () {
    while (Teclado () == 0xff ){
        for (int i=9; i<18; i++){
            if (le_Input(i) == true){
                entradas [i] = 1;
            } else {
                entradas [i] = 0;
            }
            tela_debug_entrada_2();
        }
    }
    switch(Teclado()){
        case SETA_ESQUERDA: 
            menu_atual = menu_debug_entrada_1;
            tela_debug_entrada_1();
            break;
        case SETA_DIREITA: 
            menu_atual = menu_debug_entrada_3;
            tela_debug_entrada_3();
            break;
        case ESC:
            menu_atual = menu_seleciona_manutencao;
            tela_seleciona_manutencao();
        break;
    }
}
void atualiza_tela_debug_entrada_3 (){
    while (Teclado() == 0xff){
        for (int i=18; i<28; i++){
            if (le_Input(i) == true){
                entradas [i] = 1;
            } else {
                entradas [i] = 0;
            }
        }
        tela_debug_entrada_3();
    }
    switch(Teclado()){
        case SETA_ESQUERDA: 
            menu_atual = menu_debug_entrada_2;
            tela_debug_entrada_2();
            break;
        case ESC:
            menu_atual = menu_seleciona_manutencao;
            tela_seleciona_manutencao();
        break;
    }
}
void atualiza_tela_debug_saida_1(){
    switch(Teclado()){
        case F1:
            switch(ponteiro_lcd){
                case 1:
                    aciona_saida(RELE_ESTEIRA);
                break;
                case 2:
                    aciona_saida(DEDO_ENTRADA);
                break;
                case 3:
                    aciona_saida(EMPURRADOR_ENTRADA_SOL_EMPURRA);
                    delay_ms(3000);
                    desaciona_saida(EMPURRADOR_ENTRADA_SOL_EMPURRA);
                break;
            }
            menu_atual = menu_debug_saida_1;
            tela_debug_saida_1();
        break;
        case F2:            
            switch(ponteiro_lcd){
                case 1:
                    desaciona_saida(RELE_ESTEIRA);
                break;
                case 2:
                    desaciona_saida(DEDO_ENTRADA);
                break;
                case 3:
                    aciona_saida(EMPURRADOR_ENTRADA_SOL_RETORNA);
                    delay_ms(3000);
                    desaciona_saida(EMPURRADOR_ENTRADA_SOL_RETORNA);
                break;
            }
            menu_atual = menu_debug_saida_1;
            tela_debug_saida_1();
        break;
        case SETA_DIREITA:
            ponteiro_lcd = 1;
            menu_atual = menu_debug_saida_2;
            tela_debug_saida_2();
        break;
        case SETA_SUPERIOR:
            if (ponteiro_lcd > 1){
                ponteiro_lcd --;
            }
            menu_atual = menu_debug_saida_1;
            tela_debug_saida_1();
        break;
        case SETA_INFERIOR:
            if (ponteiro_lcd < 3){
                ponteiro_lcd ++;
            }
            menu_atual = menu_debug_saida_1;
            tela_debug_saida_1();
        break;
        case ESC:
            home_solenoides();
            posicao_volta_manutencao();
            envia_maquina_para_posicao(ALIMENTADOR);
            ponteiro_lcd = 1;
            menu_atual = menu_seleciona_manutencao;
            tela_seleciona_manutencao();
        break;
    }
}
void atualiza_tela_debug_saida_2(){
    switch(Teclado()){
        case F1:
            switch(ponteiro_lcd){
                case 1:
                    aciona_saida(PRESSOR);
                break;
                case 2:
                    aciona_saida(DEDO_SAIDA);
                break;
                case 3:
                    aciona_saida(EMPURRADOR_SAIDA_SOL_EMPURRA);
                    delay_ms(3000);
                    desaciona_saida(EMPURRADOR_SAIDA_SOL_EMPURRA);
                break;
            }
            menu_atual = menu_debug_saida_2;
            tela_debug_saida_2();
        break;
        case F2:            
            switch(ponteiro_lcd){
                case 1:
                    desaciona_saida(PRESSOR);
                break;
                case 2:
                    desaciona_saida(DEDO_SAIDA);
                break;
                case 3:
                    aciona_saida(EMPURRADOR_SAIDA_SOL_RETORNA);
                    delay_ms(3000);
                    desaciona_saida(EMPURRADOR_SAIDA_SOL_RETORNA);
                break;
            }
            menu_atual = menu_debug_saida_2;
            tela_debug_saida_2();
        break;
        case SETA_DIREITA:
            ponteiro_lcd = 1;
            menu_atual = menu_debug_saida_3;
            tela_debug_saida_3();
        break;
        case SETA_ESQUERDA:
            ponteiro_lcd = 1;
            menu_atual = menu_debug_saida_1;
            tela_debug_saida_1();
        break;
        case SETA_SUPERIOR:
            if (ponteiro_lcd > 1){
                ponteiro_lcd --;
            }
            menu_atual = menu_debug_saida_2;
            tela_debug_saida_2();
        break;
        case SETA_INFERIOR:
            if (ponteiro_lcd < 3){
                ponteiro_lcd ++;
            }
            menu_atual = menu_debug_saida_2;
            tela_debug_saida_2();
        break;
        case ESC:
            home_solenoides();
            posicao_volta_manutencao();
            envia_maquina_para_posicao(ALIMENTADOR);
            ponteiro_lcd = 1;
            menu_atual = menu_seleciona_manutencao;
            tela_seleciona_manutencao();
        break;
    }
}
void atualiza_tela_debug_saida_3(){
    switch(Teclado()){
        case F1:
            switch(ponteiro_lcd){
                case 1:
                    aciona_saida(ALIMENTADOR1);
                    aciona_saida(ALIMENTADOR2);
                    aciona_saida(ALIMENTADOR3);
                break;
                case 2:
                    aciona_saida(LIMPA_BICO1);
                    aciona_saida(LIMPA_BICO2);
                break;
                case 3:
                    aciona_saida(FERRO_SOLDA1);
                    aciona_saida(FERRO_SOLDA2);
                break;
            }
            menu_atual = menu_debug_saida_3;
            tela_debug_saida_3();
        break;
        case F2:            
            switch(ponteiro_lcd){
                case 1:
                    desaciona_saida(ALIMENTADOR1);
                    desaciona_saida(ALIMENTADOR2);
                    desaciona_saida(ALIMENTADOR3);
                break;
                case 2:
                    desaciona_saida(LIMPA_BICO1);
                    desaciona_saida(LIMPA_BICO2);
                break;
                case 3:
                    desaciona_saida(FERRO_SOLDA1);
                    desaciona_saida(FERRO_SOLDA2);
                break;
            }
            menu_atual = menu_debug_saida_3;
            tela_debug_saida_3();
        break;
        case SETA_DIREITA:
            ponteiro_lcd = 1;
            menu_atual = menu_debug_saida_4;
            tela_debug_saida_4();
        break;
        case SETA_ESQUERDA:
            ponteiro_lcd = 1;
            menu_atual = menu_debug_saida_2;
            tela_debug_saida_2();
        break;
        case SETA_SUPERIOR:
            if (ponteiro_lcd > 1){
                ponteiro_lcd --;
            }
            menu_atual = menu_debug_saida_3;
            tela_debug_saida_3();
        break;
        case SETA_INFERIOR:
            if (ponteiro_lcd < 3){
                ponteiro_lcd ++;
            }
            menu_atual = menu_debug_saida_3;
            tela_debug_saida_3();
        break;
        case ESC:
            home_solenoides();
            posicao_volta_manutencao();
            envia_maquina_para_posicao(ALIMENTADOR);
            ponteiro_lcd = 1;
            menu_atual = menu_seleciona_manutencao;
            tela_seleciona_manutencao();
        break;
    }
}
void atualiza_tela_debug_saida_4(){
    signed long int posFlip;
    signed long int posX;
    signed long int posY;
    signed long int posZ;
    switch(Teclado()){
        case SETA_SUPERIOR:
            posY = motor_pos_y + incremento;
            if (posY >= 6110) {
                posY = 6110;
            } else {
                posY = motor_pos_y + incremento;
            }
            atras();
            motor_run_y(posY, 19);
            while ((run_flg_y));
            menu_atual = menu_debug_saida_4;
            tela_debug_saida_4();
        break;
        case SETA_INFERIOR:
            posY = motor_pos_y - incremento;
            if (posY >= 0) {
               posY = motor_pos_y - incremento;
            } else {
               posY = 0;
            }
            frente();
            motor_run_y(posY, 19);
            while ((run_flg_y));
            menu_atual = menu_debug_saida_4;
            tela_debug_saida_4();
        break;
        case SETA_DIREITA:
            posX = motor_pos_x - incremento;
            if (posX >= 0) {
                posX = motor_pos_x - incremento;                
            } else {
               posX = 0;
            }
            direita();
            motor_run_x(posX, 19);
            while ((run_flg_x));
            menu_atual = menu_debug_saida_4;
            tela_debug_saida_4();
        break;
        case SETA_ESQUERDA:
            posX = motor_pos_x + incremento;
            if (posX >= 4250) {
                posX = 4250;
            } else {
                posX = motor_pos_x + incremento;
            }
            esquerda();
            motor_run_x(posX, 19);
            while ((run_flg_x));
            menu_atual = menu_debug_saida_4;
            tela_debug_saida_4();
        break;
        case F2:
            posZ = motor_pos_z - incremento;
            if (posZ >= 0) {
                posZ = motor_pos_z - incremento;                
            } else {
               posZ = 0;
            }
            sobe();
            motor_run_z(posZ, 19);
            while ((run_flg_z));
            menu_atual = menu_debug_saida_4;
            tela_debug_saida_4();
        break;
        case F4:
            posZ = motor_pos_z + incremento;
            if (posZ >= 370) {
                posZ = 370;                
            } else {
               posZ = motor_pos_z + incremento;
            }
            desce();
            motor_run_z(posZ, 19);
            while ((run_flg_z));
            menu_atual = menu_debug_saida_4;
            tela_debug_saida_4();
        break;
        case 8:
            posFlip = motor_pos_flip + incremento;
            if (posFlip >= 2000) {
                posFlip = 2000;                
            } else {
               posFlip = motor_pos_flip + incremento;
            }
            motor_run_flip(posFlip, 19);
            while ((run_flg_flip));
            menu_atual = menu_debug_saida_4;
            tela_debug_saida_4();
        break;
        case 0:
            posFlip = motor_pos_flip - incremento;
            if (posFlip >= 0) {
                posFlip = motor_pos_flip - incremento;                               
            } else {
               posFlip = 0; 
            }
            motor_run_flip(posFlip, 19);
            while ((run_flg_flip));
            menu_atual = menu_debug_saida_4;
            tela_debug_saida_4();
        break;
        case 2:          
            sobe_ferros();
            desliga_pressor();
        break;
        case 5:
            desce_ferros(1);
            liga_pressor();
        break;
        case 9:
            switch (incremento){
                case 1:
                    incremento = 10;
                break;
                case 10:
                    incremento = 100;
                break;
                case 100:
                    incremento = 1;
                break;
            }            
            menu_atual = menu_debug_saida_4;
            tela_debug_saida_4();
        break;
        case ESC:
            incremento = 1;
            ponteiro_lcd = 1;
            menu_atual = menu_debug_saida_1;
            tela_debug_saida_1();
        break;
    }
}

void programa_principal_teste(){
    int i = 0;
    short x;
    short y;
    short f;
    short b;
    int sair;
    while (exit){
        switch (i){
            case 0:
                f = statusSolda();
                if (f == 0){
                    sair = 1;
                } else {
                    sair = 0;
                }
                i++;
            break;
            case 1:
                envia_maquina_para_posicao(ALIMENTADOR);
                if (Teclado() == ESC){
                    printf(lcd_putc, "\f"); //limpa display
                    printf(lcd_putc, "REINICIO DO PROGRAMA\n\r");
                    printf(lcd_putc, "   AO FIM DO CICLO  \n\r");
                    delay_ms(2000);
                    sair = 1;
                    envia_maquina_para_posicao(HOME1);
                }
                i++;                               
            break;
            case 2:
                b = le_Input(S_BANDEJA);
                if (b == 0){
                    liga_esteira();
                    i++; 
                } else {
                    liga_pressor();
                    i = 5;
                }                
            break;
            case 3:
                x = le_Input(S_ESTEIRA);
                while ((x == 0)&&(exit == 1)){
                    printf(lcd_putc, "\f"); //limpa display
                    printf(lcd_putc, "   ESPERANDO PLACA   \n\r");
                    printf(lcd_putc, "     NA ESTEIRA     \n\r");                    
                    x = le_Input(S_ESTEIRA);
                    if (Teclado() == ESC){
                        printf(lcd_putc, "\f"); //limpa display
                        printf(lcd_putc, "REINICIO DO PROGRAMA\n\r");
                        printf(lcd_putc, "   AO FIM DO CICLO  \n\r");
                        delay_ms(2000);
                        sair = 1;
                        exit = FALSE;
                    }
                }
                if (exit == 1){
                    desliga_esteira();
                    empurra_placa();
                    i++;
                } else {
                    desliga_esteira();
                }                                
            break;
            case 4:
                y = le_Input(S_BANDEJA);
                while ((y == 0)&&(exit ==1)){
                    printf(lcd_putc, "\f"); //limpa display
                    printf(lcd_putc, "      SEM PLACA     \n\r");
                    printf(lcd_putc, "     NA BANDEJA     \n\r");                 
                    y = le_Input(S_BANDEJA);
                    if (Teclado() == ESC){
                        printf(lcd_putc, "\f"); //limpa display
                        printf(lcd_putc, "REINICIO DO PROGRAMA\n\r");
                        printf(lcd_putc, "   AO FIM DO CICLO  \n\r");
                        delay_ms(2000);
                        exit = FALSE;
                        sair = 1;
                    }
                }
                if (exit == 1){
                    liga_pressor();
                    i++;
                } else {
                    desliga_pressor();
                }                
            break;
            case 5:
                envia_maquina_para_posicao(HOME1);
                if (Teclado() == ESC){
                    printf(lcd_putc, "\f"); //limpa display
                    printf(lcd_putc, "REINICIO DO PROGRAMA\n\r");
                    printf(lcd_putc, "   AO FIM DO CICLO  \n\r");
                    delay_ms(2000);
                    sair = 1;
                    desliga_pressor();
                }
                i++;
            break; 
            case 6:
                envia_maquina_para_posicao(SOLDAGEM);
                if (Teclado() == ESC){
                    printf(lcd_putc, "\f"); //limpa display
                    printf(lcd_putc, "REINICIO DO PROGRAMA\n\r");
                    printf(lcd_putc, "   AO FIM DO CICLO  \n\r");
                    delay_ms(2000);
                    sair = 1;
                    envia_maquina_para_posicao(HOME1);
                    desliga_pressor();
                }
                i++;
            break;
            case 7:
                soldar();
                motor_run_x(500, 19);
                while ((run_flg_x));
                motor_run_y(2450, 19);
                while ((run_flg_y));
                if (Teclado() == ESC){
                    sair = 1;
                }
                i++;
            break;
            case 8:
                envia_maquina_para_posicao(HOME2);
                if (Teclado() == ESC){
                    printf(lcd_putc, "\f"); //limpa display
                    printf(lcd_putc, "REINICIO DO PROGRAMA\n\r");
                    printf(lcd_putc, "   AO FIM DO CICLO  \n\r");
                    delay_ms(1000);
                    sair = 1;
                }
                i++;
            break;
            case 9:
                envia_maquina_para_posicao(DISPENSADOR);
                if (Teclado() == ESC){
                    printf(lcd_putc, "\f"); //limpa display
                    printf(lcd_putc, "REINICIO DO PROGRAMA\n\r");
                    printf(lcd_putc, "   AO FIM DO CICLO  \n\r");
                    delay_ms(1000);
                    sair = 1;
                }
                i++;
            break;
            case 10:
                desliga_pressor();
                dispensa_placa();
                if (Teclado() == ESC){
                    printf(lcd_putc, "\f"); //limpa display
                    printf(lcd_putc, "REINICIO DO PROGRAMA\n\r");
                    printf(lcd_putc, "   AO FIM DO CICLO  \n\r");
                    delay_ms(1000);
                    sair = 1;
                }
                i++;
            break;
            case 11:
                //envia_maquina_para_posicao(HOME2);
                //if (Teclado() == ESC){
                //    printf(lcd_putc, "\f"); //limpa display
                //    printf(lcd_putc, "REINICIO DO PROGRAMA\n\r");
                //    printf(lcd_putc, "   AO FIM DO CICLO  \n\r");
                //    delay_ms(2000);
                //    sair = 1;
                //}
                i++;
            break;
            case 12:
                //envia_maquina_para_posicao(LIMPEZA);
                //limpa_bicos(2000);
                //if (Teclado() == ESC){
                //    printf(lcd_putc, "\f"); //limpa display
                //    printf(lcd_putc, "REINICIO DO PROGRAMA\n\r");
                //    printf(lcd_putc, "   AO FIM DO CICLO  \n\r");
                //    delay_ms(2000);
                //    sair = 1;
                //}
                i++;
            break;
            case 13:
                //envia_maquina_para_posicao(LIMPEZA_2);
                //limpa_bicos(2000);
                //if (Teclado() == ESC){
                //    printf(lcd_putc, "\f"); //limpa display
                //    printf(lcd_putc, "REINICIO DO PROGRAMA\n\r");
                //    printf(lcd_putc, "   AO FIM DO CICLO  \n\r");
                //    delay_ms(2000);
                //    sair = 1;
                //}
                i++;
            break;
            case 14:
                envia_maquina_para_posicao(ALIMENTADOR);
                if (Teclado() == ESC){
                    printf(lcd_putc, "\f"); //limpa display
                    printf(lcd_putc, "REINICIO DO PROGRAMA\n\r");
                    printf(lcd_putc, "   AO FIM DO CICLO  \n\r");
                    delay_ms(1000);
                    sair = 1;
                }
                i++;
            break;
        }
        if (((i==15)||(i<7))&&(sair == 1)){
            envia_maquina_para_posicao(HOME1);
            exit = FALSE;
        } else{
            if ((i==15)&&(sair ==0)){
                i =0;
            }
            if ((i==11)&&(sair ==1)){
                envia_maquina_para_posicao(HOME2);
                envia_maquina_para_posicao(HOME1);
                exit = FALSE;
            }
        }
    }
    if ((i == 1)&&(exit == FALSE)){
        menu_atual = menu_faltaSolda;
        tela_faltaSolda();
    } else {
       menu_atual = menu_principal;
       tela_principal(); 
    }    
}