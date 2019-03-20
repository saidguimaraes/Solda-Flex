
#define menu_seleciona_maquina         1
#define menu_seleciona_tipo_debug      2
#define menu_seleciona_pontos          3
#define menu_valores_pontos            4
#define menu_manutencao                5
#define menu_debug_entrada_1           6
#define menu_debug_entrada_2           7
#define menu_debug_entrada_3           8
#define menu_debug_saidas              9
#define menu_debug_mecanismos_entrada 10
#define menu_debug_mecanismos_saida   11
#define menu_debug_limpeza            12
#define menu_debug_mov_maquina1       13


int flag_posicao_soldagem = 0;

void tela_movimentando_maquina_1_alimentador(void);
void tela_movimentando_maquina_1_home1(void);
void tela_movimentando_maquina_1_soldagem1(void);
void tela_movimentando_maquina_1_soldagem2(void);
void tela_movimentando_maquina_1_home2(void);
void tela_movimentando_maquina_1_dispensador(void);
void tela_esperando_maquina_2_alimentador(void);
void tela_esperando_maquina_2_home1(void);
void tela_esperando_maquina_2_soldagem1(void);
void tela_esperando_maquina_2_soldagem2(void);
void tela_esperando_maquina_2_home2(void);
void tela_esperando_maquina_2_dispensador(void);
void tela_boas_vindas (void);
void tela_iniciando_eixos(void);
void tela_principal(void);
void tela_seleciona_pontos(int);
void tela_valores_pontos(void);
void tela_seleciona_maquina (void);
void tela_seleciona_tipo_debug (void);
void tela_manutencao(void);
void tela_debug_entrada_1(void);
void tela_debug_entrada_2(void);
void tela_debug_entrada_2(void);
void tela_debug_saidas (void);
void tela_debug_mecanismos_entrada(void);
void tela_debug_mecanismos_saida(void);
void tela_debug_limpeza(void);
void tela_debug_mov_maquina1 (void);

void atualiza_tela_principal(void);
void atualiza_tela_seleciona_pontos(void);
void atualiza_tela_valores_pontos(void);
void atualiza_tela_seleciona_maquina(void);
void atualiza_tela_seleciona_tipo_debug (void);
void atualiza_tela_manutencao(void);
void atualiza_tela_debug_entrada_1(void);
void atualiza_tela_debug_entrada_2(void);
void atualiza_tela_debug_entrada_3(void);
void atualiza_tela_debug_saidas(void);
void atualiza_tela_debug_mecanismos_entrada(void);
void atualiza_tela_debug_mecanismos_saida(void);
void atualiza_tela_debug_limpeza(void);
void atualiza_tela_debug_mov_maquina1 (void);

