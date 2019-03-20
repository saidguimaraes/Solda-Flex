#include "menu_maq_1.h"

int contador_de_pontos = 0; //marca o ponto p1, p2 para buscar depois nas coordenadas
int pontos_no_modelo = 23;  //quantos pontos tem o modelo
int inicial = 0;            //inicio 1 e final 4 para imprimir no lcd
int final =3;
int ponteiro = 1;           //ajuda na impressao do ponteiro no lcd
int entradas[30];
int pos_maquina = 1;

// <editor-fold defaultstate="collapsed" desc="tela de movimentacao das maquinas">
void tela_movimentando_maquina_1_alimentador(){
    printf(lcd_putc, "\f"); //limpa display
    printf(lcd_putc, "MOVIMENTANDO MAQUINA 1\n\r");
    printf(lcd_putc, "PARA POSICAO\n\r");
    printf(lcd_putc, "ALIMENTADOR 1\n\r");
}

void tela_movimentando_maquina_1_home1(){
    printf(lcd_putc, "\f"); //limpa display
    printf(lcd_putc, "MOVIMENTANDO MAQUINA 1\n\r");
    printf(lcd_putc, "PARA POSICAO\n\r");
    printf(lcd_putc, "HOME 1\n\r");
}

void tela_movimentando_maquina_1_soldagem1(){
    printf(lcd_putc, "\f"); //limpa display
    printf(lcd_putc, "MOVIMENTANDO MAQUINA 1\n\r");
    printf(lcd_putc, "PARA POSICAO\n\r");
    printf(lcd_putc, "SOLDAGEM 1\n\r");
}

void tela_movimentando_maquina_1_soldagem2(){
    printf(lcd_putc, "\f"); //limpa display
    printf(lcd_putc, "MOVIMENTANDO MAQUINA 1\n\r");
    printf(lcd_putc, "PARA POSICAO\n\r");
    printf(lcd_putc, "SOLDAGEM 2\n\r");
}

void tela_movimentando_maquina_1_home2(){
    printf(lcd_putc, "\f"); //limpa display
    printf(lcd_putc, "MOVIMENTANDO MAQUINA 1\n\r");
    printf(lcd_putc, "PARA POSICAO\n\r");
    printf(lcd_putc, "HOME 2\n\r");
}

void tela_movimentando_maquina_1_dispensador(){
    printf(lcd_putc, "\f"); //limpa display
    printf(lcd_putc, "MOVIMENTANDO MAQUINA 1\n\r");
    printf(lcd_putc, "PARA POSICAO\n\r");
    printf(lcd_putc, "DISPENSADOR\n\r");
}

void tela_esperando_maquina_2_alimentador(){
    printf(lcd_putc, "\f"); //limpa display
    printf(lcd_putc, "ESPERANDO MAQUINA 2\n\r");
    printf(lcd_putc, "IR PARA POSICAO\n\r");
    printf(lcd_putc, "ALIMENTADOR\n\r");
}

void tela_esperando_maquina_2_home1(){
    printf(lcd_putc, "\f"); //limpa display
    printf(lcd_putc, "ESPERANDO MAQUINA 2\n\r");
    printf(lcd_putc, "IR PARA POSICAO\n\r");
    printf(lcd_putc, "HOME 1\n\r");
}

void tela_esperando_maquina_2_soldagem1(){
    printf(lcd_putc, "\f"); //limpa display
    printf(lcd_putc, "ESPERANDO MAQUINA 2\n\r");
    printf(lcd_putc, "IR PARA POSICAO\n\r");
    printf(lcd_putc, "SOLDAGEM 1\n\r");
}

void tela_esperando_maquina_2_soldagem2(){
    printf(lcd_putc, "\f"); //limpa display
    printf(lcd_putc, "ESPERANDO MAQUINA 2\n\r");
    printf(lcd_putc, "IR PARA POSICAO\n\r");
    printf(lcd_putc, "SOLDAGEM 2\n\r");
}

void tela_esperando_maquina_2_home2(){
    printf(lcd_putc, "\f"); //limpa display
    printf(lcd_putc, "ESPERANDO MAQUINA 2\n\r");
    printf(lcd_putc, "IR PARA POSICAO\n\r");
    printf(lcd_putc, "HOME 2\n\r");
}

void tela_esperando_maquina_2_dispensador(){
    printf(lcd_putc, "\f"); //limpa display
    printf(lcd_putc, "ESPERANDO MAQUINA 2\n\r");
    printf(lcd_putc, "IR PARA POSICAO\n\r");
    printf(lcd_putc, "DISPENSADOR\n\r");
}
// </editor-fold>

void tela_seleciona_maquina() {    
    printf(lcd_putc, "\f"); // limpa display
    printf(lcd_putc, "SOLDADOR AUTOMATICO\n\r");
    printf(lcd_putc, "SELECIONAR MAQUINA\n\r");
    printf(lcd_putc, "F1: MAQUINA 1    \n\r");
    printf(lcd_putc, "F2: MAQUINA 2     \n\r");
    delay_ms(100);
}

void tela_seleciona_pontos(){
    printf(lcd_putc, "\f"); // limpa display
    printf(lcd_putc, "P%02u         ENT=EDIT\n\r",inicial);
    printf(lcd_putc, "P%02u         ESC=BACK\n\r",inicial+1);
    printf(lcd_putc, "P%02u                 \n\r", inicial+2);
    printf(lcd_putc, "P%02u       ",inicial+3);
    posiciona_cursor(ponteiro,5);
    printf(lcd_putc,"<-");
    delay_ms(70);
}

void tela_valores_pontos(){
    printf(lcd_putc, "\f"); // limpa display
    printf(lcd_putc, "X:%04Lu Y:%04Lu Z:%04Lu\n\r",contador_step_x,contador_step_y,contador_step_z);
    printf(lcd_putc, "TE1:%04Lu TS1:%04Lu\n\r",M1_TE_1[contador_de_pontos],M1_TS_1[contador_de_pontos]);
    printf(lcd_putc, "TE2:%04Lu\n\r",M1_TE_2[contador_de_pontos]);
    printf(lcd_putc, "ENT:TST   ESC:BACK");
    
    delay_ms(20);
}

void tela_manutencao () {
    printf(lcd_putc, "\f");
    printf(lcd_putc, "F1: DEBUG ENTRADAS\n\r");
    printf(lcd_putc, "F2:  DEBUG SAIDAS\n\r");
    delay_ms(100);
}

void tela_debug_entrada_1 (){
    printf(lcd_putc, "\f"); // limpa display
    printf(lcd_putc, "E00:%02u E01:%02u E02:%02u\n\r", entradas[0], entradas[1], entradas[2]);
    printf(lcd_putc, "E03:%02u E04:%02u E05:%02u\n\r", entradas[3], entradas[4], entradas[5]);
    printf(lcd_putc, "E06:%02u E07:%02u E08:%02u\n\r", entradas[6], entradas[7], entradas[8]);
    printf(lcd_putc, "E09:%02u E10:%02u E11:%02u\n\r", entradas[9], entradas[10], entradas[11]);
    delay_ms(100);
}

void tela_debug_entrada_2 (){
    printf(lcd_putc, "\f"); // limpa display
    printf(lcd_putc, "E12:%02u E13:%02u E14:%02u\n\r", entradas[12], entradas[13], entradas[14]);
    printf(lcd_putc, "E15:%02u E16:%02u E17:%02u\n\r", entradas[15], entradas[16], entradas[17]);
    printf(lcd_putc, "E18:%02u E19:%02u E20:%02u\n\r", entradas[18], entradas[19], entradas[20]);
    printf(lcd_putc, "E21:%02u E22:%02u E23:%02u\n\r", entradas[21], entradas[22], entradas[23]);
    delay_ms(100);
}

void tela_debug_entrada_3 (){
    printf(lcd_putc, "\f"); // limpa display
    printf(lcd_putc, "E24:%02u\n\r", entradas[24]);
    printf(lcd_putc, "E25:%02u\n\r", entradas[25]);
    printf(lcd_putc, "E26:%02u\n\r", entradas[26]);
    printf(lcd_putc, "E27:%02u\n\r", entradas[27]);
    delay_ms(100);
}

void tela_debug_saidas (){
    printf(lcd_putc, "\f"); // limpa display
    printf(lcd_putc, "MECA_DE_ENTRADA\n\r");
    printf(lcd_putc, "MECA_DE_SAIDA\n\r");
    printf(lcd_putc, "SOLDA_LIMPEZA\n\r");
    printf(lcd_putc, "MOV_DA_MAQUINA1\n\r");
    posiciona_cursor(ponteiro,19);
    printf(lcd_putc,"<-");
    delay_ms(100);
}

void tela_debug_mecanismos_entrada (){
    printf(lcd_putc, "\f"); // limpa display
    printf(lcd_putc, "ACIONA_ESTEIRA\n\r");
    printf(lcd_putc, "DEDOS_ENTRADA\n\r");
    printf(lcd_putc, "ALIMENTADOR_IDA\n\r");
    printf(lcd_putc, "ALIMENTADOR_VOLTA\n\r");
    posiciona_cursor(ponteiro,19);
    printf(lcd_putc,"<-");
    delay_ms(100);
}

void tela_debug_mecanismos_saida(){
    printf(lcd_putc, "\f"); // limpa display
    printf(lcd_putc, "PRESSOR_PLACA\n\r");
    printf(lcd_putc, "DEDOS_SAIDA\n\r");
    printf(lcd_putc, "DISPENSADOR_IDA\n\r");
    printf(lcd_putc, "DISPENSADOR_VOLTA\n\r");
    posiciona_cursor(ponteiro,19);
    printf(lcd_putc,"<-");
    delay_ms(100);
}

void tela_debug_limpeza(){
    printf(lcd_putc, "\f"); // limpa display
    printf(lcd_putc, "ALIMENTADORES\n\r");
    printf(lcd_putc, "LIMPAR BICOS\n\r");
    printf(lcd_putc, "FERRO 1\n\r");
    printf(lcd_putc, "FERRO 2\n\r");
    posiciona_cursor(ponteiro,19);
    printf(lcd_putc,"<-");
    delay_ms(100);
}

void tela_debug_mov_maquina1(){
    printf(lcd_putc, "\f"); // limpa display
    printf(lcd_putc, "POS_PEGAR_PLACA\n\r");
    printf(lcd_putc, "POS_DE_SOLDA\n\r");
    printf(lcd_putc, "POS_DISP_PLACA\n\r");
    posiciona_cursor(ponteiro,19);
    printf(lcd_putc,"<-");
    delay_ms(100);
}

// <editor-fold defaultstate="collapsed" desc="Void's de Atualização de telas">
void atualiza_tela_seleciona_maquina(void){
    desaciona_mecanismo_de_entrada();
    desaciona_mecanismo_de_saida();
    switch(Teclado())    {
        case F1:
            tela_seleciona_tipo_debug();
            menu_atual = menu_seleciona_tipo_debug;   
        break;
        case F2:
            tela_movimentando_maquina_1_home1();
            posicao_home_1 ();
//            enviar_posicao_outra_maquina(HOME2);
            tela_seleciona_tipo_debug();
            menu_atual = menu_seleciona_tipo_debug;           
            break;
        case ESC:
            tela_principal();
            menu_atual = menu_principal;
        break;
    }
}

void atualiza_tela_seleciona_tipo_debug (void){
    switch(Teclado())    {
        case F1:
            tela_seleciona_pontos();
            menu_atual = menu_seleciona_pontos; 
        break;
        case F2:
            tela_manutencao();
            menu_atual = menu_manutencao;
            break;
        case ESC:
//            int posicao_maquina_2 = ler_posicao_outra_maquina();
//            while (posicao_maquina_2 != HOME1){
                tela_esperando_maquina_2_home1();
//                posicao_maquina_2 = ler_posicao_outra_maquina();                
            }
//            home_maquina_1 ();
//            enviar_posicao_outra_maquina (ALIMENTADOR);
        break;
}

void atualiza_tela_seleciona_pontos(){
    switch (Teclado()) {
        case SETA_SUPERIOR:
            if (ponteiro == 1 && inicial == 0){ 
                ponteiro = 1;
            }
            if (ponteiro == 1 && inicial > 0){ 
                ponteiro = 1;
                inicial --;
                final --;
                contador_de_pontos --;
            }
            if(ponteiro > 1 && inicial == 0) {
                ponteiro --;
                contador_de_pontos--;
            }            
            if (ponteiro>1 && inicial >0){
                ponteiro --;
                contador_de_pontos --;
            }
            menu_atual = menu_seleciona_pontos;
            tela_seleciona_pontos();
            break; 
        case SETA_INFERIOR:
            contador_de_pontos++;
            if (inicial == 0 && contador_de_pontos <4){ 
                ponteiro ++;
            }            
            if (contador_de_pontos >= 4 && contador_de_pontos < pontos_no_modelo +1 ){
                if (ponteiro == 4){
                    inicial ++;
                    final ++;
                    ponteiro = 4;
                }else {
                    ponteiro ++;  
                }               
            }
            if (contador_de_pontos > pontos_no_modelo){
                contador_de_pontos = 17;
                ponteiro = 4;               
            }            
            menu_atual = menu_seleciona_pontos;
            tela_seleciona_pontos();
            break;
        
        case ENTER:
            if (flag_posicao_soldagem == 1){
                go_x_y( M1_posicao_x[contador_de_pontos],  M1_posicao_y[contador_de_pontos], velocity_x, velocity_y, 2000, 2000, 200, 200, true, true, false, false); 
            }
            if (flag_posicao_soldagem == 0){
                go_x_y_flip(0, 900, 1873, velocity_x, velocity_y, velocity_flip, 4000, 4000, 4000, 200, 200, 200, true, true, true);
                go_x_y(3700, 900, velocity_x, velocity_y, 2000, 2000, 200, 200, true, true, false, false); 
                go_x_y(3849, 4375, velocity_x, velocity_y, 2000, 2000, 200, 200, true, true, false, false);
                flag_posicao_soldagem = 1;
            }
            delay_ms(500);            
            tela_valores_pontos();    
            menu_atual = menu_valores_pontos; 
            break;
        
        case ESC:  
            ponteiro = 1;
            final = 3;
            inicial =0;
            contador_de_pontos = 0;            
            menu_atual = menu_seleciona_maquina;
            tela_seleciona_maquina();
            desaciona_saida(PRESSOR);
//            home_maquina_1();
            break;
        default:
            break;
    }     
}

void atualiza_tela_valores_pontos (){
    switch (Teclado()){
        case SETA_SUPERIOR:
            frente();
            one_step_y();
            M1_posicao_y[contador_de_pontos] -- ;           
            break;
        case SETA_INFERIOR:
            atras();
            one_step_y();
            M1_posicao_y[contador_de_pontos] ++ ;   
            break;
        case SETA_DIREITA:
            esquerda();
            one_step_x();
            M1_posicao_x[contador_de_pontos] ++ ;           
            break;
        case SETA_ESQUERDA:
            direita();
            one_step_x();
            M1_posicao_x[contador_de_pontos] -- ;            
            break;
        case F2:
            sobe();
            one_step_z();
            M1_posicao_z[contador_de_pontos] -- ;
            break;
        case F4:
            desce();
            one_step_z();
            M1_posicao_z[contador_de_pontos] ++ ;
            break;
        case 1:
            M1_TE_1[contador_de_pontos ] = M1_TE_1[contador_de_pontos ] + 10;
            break;
        case 4:
            M1_TE_1[contador_de_pontos ]= M1_TE_1[contador_de_pontos ] - 10;
            break;
        case 2:
            M1_TE_2[contador_de_pontos ]= M1_TE_2[contador_de_pontos ] + 10;
            break;
        case 5:
            M1_TE_2[contador_de_pontos ] = M1_TE_2[contador_de_pontos ] - 10;
            break;
        case 3:
            M1_TS_1[contador_de_pontos] = M1_TS_1[contador_de_pontos] +10;
            break;
        case 6:
            M1_TS_1[contador_de_pontos] = M1_TS_1[contador_de_pontos] -10;
            break;
        case 8:
            desaciona_saida(PRESSOR);  
            desaciona_ferros(contador_de_pontos);
            go_z(0, 3000);
            break;
        case 0:
            acionar_pressor();
            delay_ms(500);
            go_z(M1_posicao_z[contador_de_pontos], 3000);  
            ferros(contador_de_pontos);
            break;
        case 7:
            M1_SOLDA_TESTE(contador_de_pontos);
            break;
        case 9:
            go_z(0, 3000);
            desaciona_ferros(contador_de_pontos);
            break;
        case ENTER:
            aciona_saida(PRESSOR);
            if ((contador_de_pontos == 0) ||(contador_de_pontos == 2) || (contador_de_pontos == 8) || (contador_de_pontos == 10) || (contador_de_pontos == 16)|| (contador_de_pontos == 18)){
                M1_SOLDA_TRILHA_TESTE(contador_de_pontos);                
            } 
            else {
                M1_SOLDA_1(contador_de_pontos);                
            } 
            desaciona_saida(PRESSOR);
            go_x(4100,1);
            break;          
        case ESC:
            desaciona_ferros(contador_de_pontos);
            go_z(0, 3000);
            menu_atual = menu_seleciona_pontos;            
            inicial = 0;
            final = 3;
            contador_de_pontos = 0;
            ponteiro = 1;
            tela_seleciona_pontos();
            delay_ms(500);
            break;
    }
    if (menu_atual == menu_valores_pontos){
        tela_valores_pontos();
    }
}

void atualiza_tela_manutencao (){
    switch(Teclado())    {
        case F1: 
            menu_atual = menu_debug_entrada_1;
            tela_debug_entrada_1();
            break;
        case F2:
            menu_atual = menu_debug_saidas;
            tela_debug_saidas();
            break;
        case ESC:
            menu_atual = menu_seleciona_maquina;
            tela_seleciona_maquina();
        break;
    }
}

void atualiza_tela_debug_entrada_1(){
    while (Teclado() == 0xff ){
        for (int i=0; i<12; i++){
            if (le_Input(i) == true){
                entradas [i] = 1;
            } else {
                entradas [i] = 0;
            }
        }
        tela_debug_entrada_1();
    }
    switch(Teclado()){
        case SETA_INFERIOR: 
            menu_atual = menu_debug_entrada_2;
            tela_debug_entrada_2();
            break;        
        case ESC:
            menu_atual = menu_manutencao;
            tela_manutencao();
        break;
    }
}

void atualiza_tela_debug_entrada_2 () {
    while (Teclado () == 0xff ){
        for (int i=12; i<24; i++){
            if (le_Input(i) == true){
                entradas [i] = 1;
            } else {
                entradas [i] = 0;
            }
            tela_debug_entrada_2();
        }
    }
    switch(Teclado()){
        case SETA_SUPERIOR: 
            menu_atual = menu_debug_entrada_1;
            tela_debug_entrada_1();
            break;
        case SETA_INFERIOR: 
            menu_atual = menu_debug_entrada_3;
            tela_debug_entrada_3();
            break;
        case ESC:
            menu_atual = menu_manutencao;
            tela_manutencao();
        break;
    }
}

void atualiza_tela_debug_entrada_3 (){
    while (Teclado() == 0xff){
        for (int i=24; i<28; i++){
            if (le_Input(i) == true){
                entradas [i] = 1;
            } else {
                entradas [i] = 0;
            }
        }
        tela_debug_entrada_3();
    }
    switch(Teclado()){
        case SETA_SUPERIOR: 
            menu_atual = menu_debug_entrada_2;
            tela_debug_entrada_2();
            break;
        case ESC:
            menu_atual = menu_manutencao;
            tela_manutencao();
        break;
    }
}

void atualiza_tela_debug_saidas(){
    switch(Teclado()){
        case SETA_INFERIOR: 
            if (ponteiro < 4) {
                ponteiro ++;
            }
            tela_debug_saidas();
            break;
        case SETA_SUPERIOR:
            if (ponteiro > 1) {
                ponteiro --;
            }
            tela_debug_saidas();
        break;
        case ENTER:
            switch(ponteiro){
                case 1:
                    menu_atual = menu_debug_mecanismos_entrada;
                    ponteiro = 1;
                    tela_debug_mecanismos_entrada();
                    break;
                case 2:
                    menu_atual = menu_debug_mecanismos_saida;
                    ponteiro = 1;
                    tela_debug_mecanismos_saida();
                    break;
                case 3:
                    menu_atual = menu_debug_limpeza;
                    ponteiro = 1;
                    tela_debug_limpeza();
                break;
                case 4:
                    menu_atual = menu_debug_mov_maquina1;
                    ponteiro = 1;
                    tela_debug_mov_maquina1();
                break;
            }
        break;
        case ESC:
//            home_maquina_1();
            ponteiro = 1;
            menu_atual = menu_manutencao;
            tela_manutencao();
        break;
    }
}

void atualiza_tela_debug_mecanismos_entrada (){
    switch(Teclado()){
        case SETA_INFERIOR: 
            if (ponteiro < 4) {
                ponteiro ++;
            }
            tela_debug_mecanismos_entrada();
            break;
        case SETA_SUPERIOR:
            if (ponteiro > 1) {
                ponteiro --;
            }
            tela_debug_mecanismos_entrada();
        break;
        case F1:
            switch(ponteiro){
                case 1:
                    aciona_saida(RELE_ESTEIRA);
                    break;
                case 2:
                    aciona_saida(DEDO_ENTRADA);
                    break;
                case 3:
                    aciona_saida(EMPURRADOR_ENTRADA_SOL_EMPURRA);
                break;
                case 4:
                   aciona_saida(EMPURRADOR_ENTRADA_SOL_RETORNA);
                break;
            }
        tela_debug_mecanismos_entrada();
        break;
        case F2:
            switch(ponteiro){
                case 1:
                    desaciona_saida(RELE_ESTEIRA);
                    break;
                case 2:
                    desaciona_saida(DEDO_ENTRADA);
                    break;
                case 3:
                    desaciona_saida(EMPURRADOR_ENTRADA_SOL_EMPURRA);
                break;
                case 4:
                    desaciona_saida(EMPURRADOR_ENTRADA_SOL_RETORNA);
                break;
            }
        tela_debug_mecanismos_entrada();
        break;
        case ESC:
            ponteiro = 1;
            menu_atual = menu_debug_saidas;
            tela_debug_saidas();
        break;
    }
}

void atualiza_tela_debug_mecanismos_saida(){
    switch(Teclado()){
        case SETA_INFERIOR: 
            if (ponteiro < 4) {
                ponteiro ++;
            }
            tela_debug_mecanismos_saida();
            break;
        case SETA_SUPERIOR:
            if (ponteiro > 1) {
                ponteiro --;
            }
            tela_debug_mecanismos_saida();
        break;
        case F1:
            switch(ponteiro){
                case 1:
                    aciona_saida(PRESSOR);
                    break;
                case 2:
                    aciona_saida(DEDO_SAIDA);
                    break;
                case 3:
                    aciona_saida(EMPURRADOR_SAIDA_SOL_EMPURRA);
                break;
                case 4:
                   aciona_saida(EMPURRADOR_SAIDA_SOL_RETORNA);
                break;
            }
        tela_debug_mecanismos_saida();
        break;
        case F2:
            switch(ponteiro){
                case 1:
                    desaciona_saida(PRESSOR);
                    break;
                case 2:
                    desaciona_saida(DEDO_SAIDA);
                    break;
                case 3:
                    desaciona_saida(EMPURRADOR_SAIDA_SOL_EMPURRA);
                break;
                case 4:
                    desaciona_saida(EMPURRADOR_SAIDA_SOL_RETORNA);
                break;
            }
        tela_debug_mecanismos_saida();
        break;
        case ESC:
            ponteiro = 1;
            menu_atual = menu_debug_saidas;
            tela_debug_saidas();
        break;
    }
}

void atualiza_tela_debug_limpeza(){
    switch(Teclado()){
        case SETA_INFERIOR: 
            if (ponteiro < 4) {
                ponteiro ++;
            }
            tela_debug_limpeza();
            break;
        case SETA_SUPERIOR:
            if (ponteiro > 1) {
                ponteiro --;
            }
            tela_debug_limpeza();
        break;
        case F1:
            switch(ponteiro){
                case 1:
                    aciona_saida(ALIMENTADOR1);
                    aciona_saida(ALIMENTADOR3);
                    aciona_saida(ALIMENTADOR3);
                    break;
                case 2:
                    aciona_saida(LIMPA_BICO1);
                    aciona_saida(LIMPA_BICO2);
                    break;
                case 3:
                    aciona_saida(FERRO_SOLDA1);
                break;
                case 4:
                   aciona_saida(FERRO_SOLDA2);
                break;
            }
        tela_debug_limpeza();
        break;
        case F2:
            switch(ponteiro){
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
                break;
                case 4:
                    desaciona_saida(FERRO_SOLDA2);
                break;
            }
        tela_debug_limpeza();
        break;
        case ESC:
            ponteiro = 1;
            menu_atual = menu_debug_saidas;
            tela_debug_saidas();
        break;
    }
}

void atualiza_tela_debug_mov_maquina1(){    
    switch(Teclado()){
        case SETA_INFERIOR: 
            if (ponteiro < 3) {
                ponteiro ++;
            }
            tela_debug_mov_maquina1();
            break;
        case SETA_SUPERIOR:
            if (ponteiro > 1) {
                ponteiro --;
            }
            tela_debug_mov_maquina1();
        break;
        case ENTER:
            switch(ponteiro){
                case 1:                     
                    if (pos_maquina == 2){
//                        home_maquina_1();
                        pos_maquina = 1;
                    }
                    if (pos_maquina == 3){
                    //    home_maquina_1();
                        pos_maquina = 1;
                    }
                break;
                case 2:
                    if (pos_maquina == 1){
                        posicao_soldagem(MAQUINA1);
                        pos_maquina = 2;
                    }
                    if (pos_maquina == 3){
                    //    home_maquina_1();
                        posicao_soldagem(MAQUINA1);
                        pos_maquina = 2;
                    }
                    break;
                case 3:
                    if (pos_maquina == 1){
                        posicao_soldagem(MAQUINA1);
                        posicao_home_2(MAQUINA1);
                        posicao_dispensar_placa(MAQUINA1);
                        pos_maquina = 3;
                    }
                    if (pos_maquina == 2){
                        posicao_home_2(MAQUINA1);
                        posicao_dispensar_placa(MAQUINA1);
                        pos_maquina = 3;
                    }                        
                break;
            }
        tela_debug_mov_maquina1();
        break;
        case ESC:
            pos_maquina = 1;
            ponteiro = 1;
            //home_maquina_1();            
            menu_atual = menu_debug_saidas;
            tela_debug_saidas();
        break;
    }
}

// </editor-fold>