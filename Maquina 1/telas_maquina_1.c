#include "telas_maquina_1.h"

void tela_apresentacao(){
    printf(lcd_putc, "\f"); //limpa display
    printf(lcd_putc, "        ICTS        \n\r");
    printf(lcd_putc, "  INSTITUTO CENTRO  \n\r");
    printf(lcd_putc, "    TECNOLOGIA EM   \n\r");
    printf(lcd_putc, "      SOFTWARE      \n\r");
}
void tela_iniciando_maquina(){
    printf(lcd_putc, "\f"); //limpa display
    printf(lcd_putc, "     INICIANDO     \n\r");
    printf(lcd_putc, "      BANDEJAS     \n\r");
}
void tela_movimentando_maquina (int posicao) {
    switch (posicao){
        case ALIMENTADOR:
            printf(lcd_putc, "\f"); //limpa display
            printf(lcd_putc, "MOVIMENTANDO BANDEJA\n\r");
            printf(lcd_putc, "    PARA POSICAO    \n\r");
            printf(lcd_putc, "     ALIMENTADOR    \n\r");
        break;
        case HOME1:
            printf(lcd_putc, "\f"); //limpa display
            printf(lcd_putc, "MOVIMENTANDO BANDEJA\n\r");
            printf(lcd_putc, "    PARA POSICAO    \n\r");
            printf(lcd_putc, "       HOME 1       \n\r");
        break;
        case SOLDAGEM:
            printf(lcd_putc, "\f"); //limpa display
            printf(lcd_putc, "MOVIMENTANDO BANDEJA\n\r");
            printf(lcd_putc, "    PARA POSICAO    \n\r");
            printf(lcd_putc, "      SOLDAGEM     \n\r");
        break;
        case HOME2:
            printf(lcd_putc, "\f"); //limpa display
            printf(lcd_putc, "MOVIMENTANDO BANDEJA\n\r");
            printf(lcd_putc, "    PARA POSICAO    \n\r");
            printf(lcd_putc, "       HOME 2       \n\r");
        break;
        case DISPENSADOR:
            printf(lcd_putc, "\f"); //limpa display
            printf(lcd_putc, "MOVIMENTANDO BANDEJA\n\r");
            printf(lcd_putc, "    PARA POSICAO    \n\r");
            printf(lcd_putc, "    DISPENSADOR     \n\r");
        break;
    }
}
void tela_esperando_mov_maquina(void) {
    printf(lcd_putc, "\f"); //limpa display
    printf(lcd_putc, "  ESPERANDO BANDEJA \n\r");
    printf(lcd_putc, "   IR PARA POSICAO  \n\r");
    printf(lcd_putc, "    PRE-REQUISITO   \n\r");
}
void tela_esperando_mov_outra_maquina(int posicao) {
    switch (posicao){
        case ALIMENTADOR:
            printf(lcd_putc, "\f"); //limpa display
            printf(lcd_putc, "   ESPERANDO OUTRA  \n\r");
            printf(lcd_putc, "       BANDEJA      \n\r");
            printf(lcd_putc, "   IR PARA POSICAO  \n\r");
            printf(lcd_putc, "     ALIMENTADOR    \n\r");
        case HOME1:
            printf(lcd_putc, "\f"); //limpa display
            printf(lcd_putc, "   ESPERANDO OUTRA  \n\r");
            printf(lcd_putc, "       BANDEJA      \n\r");
            printf(lcd_putc, "   IR PARA POSICAO  \n\r");
            printf(lcd_putc, "       HOME 1       \n\r");
        break;
        case SOLDAGEM:
            printf(lcd_putc, "\f"); //limpa display
            printf(lcd_putc, "   ESPERANDO OUTRA  \n\r");
            printf(lcd_putc, "       BANDEJA      \n\r");
            printf(lcd_putc, "   IR PARA POSICAO  \n\r");
            printf(lcd_putc, "     SOLDAGEM 1     \n\r");
        break;
        case HOME2:
            printf(lcd_putc, "\f"); //limpa display
            printf(lcd_putc, "   ESPERANDO OUTRA  \n\r");
            printf(lcd_putc, "       BANDEJA      \n\r");
            printf(lcd_putc, "   IR PARA POSICAO  \n\r");
            printf(lcd_putc, "       HOME 2       \n\r");
        break;
        case DISPENSADOR:
            printf(lcd_putc, "\f"); //limpa display
            printf(lcd_putc, "   ESPERANDO OUTRA  \n\r");
            printf(lcd_putc, "       BANDEJA      \n\r");
            printf(lcd_putc, "   IR PARA POSICAO  \n\r");
            printf(lcd_putc, "     DISPENSADOR    \n\r");
        break;
    }
}
void tela_esperando_sair_posicao_outra_maquina(void){
    printf(lcd_putc, "\f"); //limpa display
    printf(lcd_putc, "   ESPERANDO OUTRA  \n\r");
    printf(lcd_putc, "       BANDEJA      \n\r");
    printf(lcd_putc, "   SAIR DA POSICAO  \n\r");
    printf(lcd_putc, "        ATUAL       \n\r");
}

void tela_principal() {
    printf(lcd_putc, "\f"); // limpa display
    printf(lcd_putc, " SOLDADOR AUTOMATICO\n\r");
    printf(lcd_putc, "      MODELO:%02u   \n\r",modelo);
    printf(lcd_putc, "     MENU:EDITAR    \n\r");
    printf(lcd_putc, "  ENTER:AUTOMATICO  \n\r");
}
void tela_seleciona_maquina(){
    printf(lcd_putc, "\f");
    printf(lcd_putc, " SELECIONE A BANDEJA\n\r");
    printf(lcd_putc, "    F1: BANDEJA 1   \n\r");
    printf(lcd_putc, "    F2: BANDEJA 2   \n\r");
    printf(lcd_putc, "    ESC:BACK        \n\r");
}
void tela_manutencao_outra_maquina() {
    printf(lcd_putc, "\f"); // limpa display
    printf(lcd_putc, "     MANUTENCAO     \n\r");
    printf(lcd_putc, "      BANDEJA 2     \n\r");
    printf(lcd_putc, "                    \n\r");
    printf(lcd_putc, "      ESC:BACK      \n\r");
}
void tela_edita_modelo(){
    printf(lcd_putc, "\f");
    printf(lcd_putc, "    ESCOLHER ACAO   \n\r");
    printf(lcd_putc, "F1:EDITAR/MANUTENCAO\n\r");
    printf(lcd_putc, "F2:EXCLUI MODELO  \n\r");
    printf(lcd_putc, "ESC:BACK          \n\r");
}
void tela_seleciona_debug(){
    printf(lcd_putc, "\f"); // limpa display
    printf(lcd_putc, "  F1: EDITAR PONTOS \n\r");
    printf(lcd_putc, "  F2: MANUTENCAO    \n\r");
    printf(lcd_putc, "\n\r");
    printf(lcd_putc, "  ESC:BACK          \n\r");
}
void tela_seleciona_debug_2(){
    printf(lcd_putc, "\f"); // limpa display
    printf(lcd_putc, "   F1: N PONTOS     \n\r");
    printf(lcd_putc, "  F2: EDITAR PONTOS \n\r");
    printf(lcd_putc, "\n\r");
    printf(lcd_putc, "  ESC:BACK          \n\r");
}
void tela_edita_pontos_no_modelo(){
    printf(lcd_putc, "\f");
    printf(lcd_putc, "  NUMERO DE PONTOS  \n\r");
    printf(lcd_putc, "         %04Lu       \n\r",pontos_no_modelo);
    printf(lcd_putc, " ENTER:SAVE|ESC:BACK\n\r");
}
void tela_excluir_modelo(){
    printf(lcd_putc, "\f");
    printf(lcd_putc, "   DESEJA EXCLUIR   \n\r");
    printf(lcd_putc, "     O MODELO ?     \n\r");
    printf(lcd_putc, "      ENTER:OK      \n\r");
    printf(lcd_putc, "      ESC:BACK     \n\r");
}
void tela_seleciona_pontos(){
    printf(lcd_putc, "\f"); // limpa display
    printf(lcd_putc, "P%02u         ENT:EDIT\n\r",inicial_lcd);
    printf(lcd_putc, "P%02u         ESC:BACK\n\r",inicial_lcd+1);
    printf(lcd_putc, "P%02u                 \n\r",inicial_lcd+2);
    printf(lcd_putc, "P%02u                 \n\r",inicial_lcd+3);
    posiciona_cursor(ponteiro_lcd,5);
    printf(lcd_putc,"<");
}
void tela_dados_ponto (contador_lcd){
    printf(lcd_putc, "\f"); // limpa display
    printf(lcd_putc, "X:%04Lu T:%04Lu\n\r",x[contador_lcd],tipo[contador_lcd]);
    printf(lcd_putc, "Y:%04Lu H:%04Lu F:%04Lu\n\r",y[contador_lcd],habilitado[contador_lcd],numeroFerros[contador_lcd]);
    printf(lcd_putc, "Z:%04Lu I:%02u L:%04Lu\n\r",z[contador_lcd],incremento,limpar[contador_lcd]);
    printf(lcd_putc, "F1:GRAVA|F3:PROX\n\r");
} 
void tela_dados_ponto_2 (contador_lcd){
    printf(lcd_putc, "\f"); // limpa display
    printf(lcd_putc, "S1:%04Lu\n\r",t_solda[contador_lcd]);
    printf(lcd_putc, "S2:%04Lu E:%04Lu\n\r",t_solda2[contador_lcd],t_wait[contador_lcd]);
    printf(lcd_putc, "S3:%04Lu I:%02u\n\r",t_solda3[contador_lcd],incremento);
    printf(lcd_putc, "F1:REC|F3:BACK\n\r");
}
void tela_dados_ponto_3 (contador_lcd){
    printf(lcd_putc, "\f"); // limpa display
    printf(lcd_putc, "\n\r");
    printf(lcd_putc, "S2:%04Lu E:%04Lu\n\r",t_solda2[contador_lcd],t_wait[contador_lcd]);
    printf(lcd_putc, "S3:%04Lu I:%02u\n\r",t_solda3[contador_lcd],incremento);
    printf(lcd_putc, "F1:REC|F3:BACK\n\r");
}
void tela_dados_ponto_4 (contador_lcd){
    printf(lcd_putc, "\f"); // limpa display
    printf(lcd_putc, "S1:%04Lu\n\r",t_solda[contador_lcd]);
    printf(lcd_putc, "S2:%04Lu E:%04Lu\n\r",t_solda2[contador_lcd],t_wait[contador_lcd]);
    printf(lcd_putc, "       I:%02u\n\r",incremento);
    printf(lcd_putc, "F1:REC|F3:BACK\n\r");
}
void tela_dados_ponto_5 (contador_lcd){
    printf(lcd_putc, "\f"); // limpa display
    printf(lcd_putc, "\n\r");
    printf(lcd_putc, "S2:%04Lu E:%04Lu\n\r",t_solda2[contador_lcd],t_wait[contador_lcd]);
    printf(lcd_putc, "       I:%02u\n\r",incremento);
    printf(lcd_putc, "F1:REC|F3:BACK\n\r");
}

void tela_faltaSolda(){
    printf(lcd_putc, "\f"); // limpa display
    printf(lcd_putc, "      VERIFIQUE     \n\r");
    printf(lcd_putc, "  OS ALIMENTADORES  \n\r");
    printf(lcd_putc, "      DE SOLDA      \n\r");
    printf(lcd_putc, "      ENTER:OK      \n\r");
}

void tela_confirmaManutencao(){
    printf(lcd_putc, "\f"); // limpa display
    printf(lcd_putc, "MANUTENCAO BANDEJA 2\n\r");
    printf(lcd_putc, "   JA FINALIZADA ?  \n\r");
    printf(lcd_putc, "      ENTER:OK      \n\r");
    printf(lcd_putc, "       ESC:NO       \n\r");
}

void tela_seleciona_manutencao(){
    printf(lcd_putc, "\f");
    printf(lcd_putc, " F1: DEBUG ENTRADAS \n\r");
    printf(lcd_putc, " F2:  DEBUG SAIDAS  \n\r");
    printf(lcd_putc, "                    \n\r");
    printf(lcd_putc, "      ESC:BACK      \n\r");
}
void tela_debug_entrada_1 (){
    printf(lcd_putc, "\f"); // limpa display
    printf(lcd_putc, "E00:%02u E01:%02u E02:%02u\n\r", entradas[0], entradas[1], entradas[2]);
    printf(lcd_putc, "E03:%02u E04:%02u E05:%02u\n\r", entradas[3], entradas[4], entradas[5]);
    printf(lcd_putc, "E06:%02u E07:%02u E08:%02u\n\r", entradas[6], entradas[7], entradas[8]);    
    printf(lcd_putc, "   >:PROX|ESC:BACK  \n\r");
}
void tela_debug_entrada_2 (){
    printf(lcd_putc, "\f"); // limpa display
    printf(lcd_putc, "E09:%02u E10:%02u E11:%02u\n\r", entradas[9], entradas[10], entradas[11]);
    printf(lcd_putc, "E12:%02u E13:%02u E14:%02u\n\r", entradas[12], entradas[13], entradas[14]);
    printf(lcd_putc, "E15:%02u E16:%02u E17:%02u\n\r", entradas[15], entradas[16], entradas[17]);    
    printf(lcd_putc, "  <|>:PROX|ESC:BACK \n\r");
}
void tela_debug_entrada_3 (){
    printf(lcd_putc, "\f"); // limpa display
    printf(lcd_putc, "E18:%02u E19:%02u E20:%02u\n\r", entradas[18], entradas[19], entradas[20]);
    printf(lcd_putc, "E21:%02u E22:%02u E23:%02u\n\r", entradas[21], entradas[22], entradas[23]);
    printf(lcd_putc, "E24:%02u E25:%02u E26:%02u\n\r", entradas[24], entradas[25], entradas[26]);
    printf(lcd_putc, "E27:%02u <:ANT|ESC:BACK\n\r", entradas[27]);
}
void tela_debug_saida_1 (){
    printf(lcd_putc, "\f");
    printf(lcd_putc, "ESTEIRA             \n\r");
    printf(lcd_putc, "DEDOS ENTRADA       \n\r");
    printf(lcd_putc, "ALIMENTADOR_PLACA   \n\r");
    printf(lcd_putc, "F1:ON|F2:OF|ESC:BACK\n\r");
    posiciona_cursor(ponteiro_lcd,19);
    printf(lcd_putc,"<");
}
void tela_debug_saida_2 (){
    printf(lcd_putc, "\f");
    printf(lcd_putc, "PRESSOR             \n\r");
    printf(lcd_putc, "DEDOS_SAIDA         \n\r");
    printf(lcd_putc, "DISPENSADOR_PLACA   \n\r");
    printf(lcd_putc, "F1:ON|F2:OF|ESC:BACK\n\r");
    posiciona_cursor(ponteiro_lcd,19);
    printf(lcd_putc,"<");
}
void tela_debug_saida_3 (){
    printf(lcd_putc, "\f");
    printf(lcd_putc, "ALIMENTADOR_SOLDA   \n\r");
    printf(lcd_putc, "LIMPADOR_BICO       \n\r");
    printf(lcd_putc, "FERROS_DE_SOLDA     \n\r");
    printf(lcd_putc, "F1:ON|F2:OF|ESC:BACK\n\r");
    posiciona_cursor(ponteiro_lcd,19);
    printf(lcd_putc,"<");
}
void tela_debug_saida_4(){
    printf(lcd_putc, "\f"); // limpa display
    printf(lcd_putc, "   X:%04Lu  Y:%04Lu  \n\r",motor_pos_x,motor_pos_y);
    printf(lcd_putc, "   Z:%04Lu  F:%04Lu  \n\r",motor_pos_z,motor_pos_flip);
    printf(lcd_putc, "       INC:%2u     \n\r",incremento);
    printf(lcd_putc, "       ESC:BACK      \n\r");
}

void tela_programa_principal(){
    printf(lcd_putc, "\f"); // limpa display
    printf(lcd_putc, " EXECUTANDO PROGRAMA\n\r");
    printf(lcd_putc, "     MODELO:%02u    \n\r",modelo);
    printf(lcd_putc, "                    \n\r");
    printf(lcd_putc, "      ESC:STOP      \n\r");
}