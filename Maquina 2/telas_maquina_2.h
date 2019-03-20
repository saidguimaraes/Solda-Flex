#define menu_principal                          0
#define menu_seleciona_maquina                  1
#define menu_seleciona_debug                    2
#define menu_seleciona_manutencao               3
#define menu_debug_entrada_1                    4
#define menu_debug_entrada_2                    5
#define menu_debug_entrada_3                    6
#define menu_manutencao_outra_maquina           7
#define menu_debug_saida_1                      8
#define menu_debug_saida_2                      9
#define menu_debug_saida_3                      10
#define menu_debug_saida_4                      11

#define menu_programa_principal                 12

#define menu_edita_modelo                       13
#define menu_excluir_modelo                     14
#define menu_seleciona_pontos                   15
#define menu_dados_ponto                        16
#define menu_edita_pontos_no_modelo             17
#define menu_dados_ponto_2                      18
#define menu_faltaSolda                         19
#define menu_seleciona_debug_2                  20
#define menu_confirmaManutencao                 21

void tela_apresentacao(void); //Tela que aparece quando liga a maquina
void tela_iniciando_maquina (void); //tela que aparece quando a maquina esta iniciando
void tela_movimentando_maquina (int posicao); //tela de movimentacao que aparece na maquina 2
void tela_esperando_mov_maquina(void); //tela esperando movimentacao da maquina
void tela_esperando_mov_outra_maquina (int posicao); //tela de espera de movimentacao da maquina 1
void tela_esperando_sair_posicao_outra_maquina(void); //tela de espera a outra maquina sair da posicao atual

void tela_principal(void); //tela principal
void tela_seleciona_maquina(void); // tela de selecao maquina 1 ou maquina 2
void tela_manutencao_outra_maquina(void); //tela de manutencao na outra maquina
void tela_edita_modelo (void); //tela que escolhe entre edicao e exclusao do modelo escolhido
void tela_seleciona_debug(void); //tela de selecao de debug: manutencao ou pontos
void tela_edita_pontos_no_modelo(void); //tela de edicao dos pontos no modelo
void tela_excluir_modelo(void); //tela que pergunta se voce quer realmente exlcuir o modelo
void tela_seleciona_pontos(void); //tela de escolha do ponto a ser editado
void tela_dados_ponto (void); //tela que mostra todos os dados do respectivo ponto da placa
void tela_dados_ponto_2 (void); //tela que mostra todos os dados do respectivo ponto da placa

void tela_faltaSolda(void); //tela que mostra a necessidade de verificacao dos alimentados de solda

void tela_seleciona_manutencao (void); //tela que mostra as opcoes sensores de entrada e atuadores de saida
void tela_debug_entrada_1 (void); //tela 1 de sensores da maquina
void tela_debug_entrada_2 (void); //tela 2 de sensores da maquina
void tela_debug_entrada_3 (void); //tela 3 de sensores da maquina
void tela_debug_saida_1(void); //tela que podemos acionar a esteira, pinos de entrada, e o alimentador de placa
void tela_debug_saida_2(void); //tela que podemos acionar o pressor da placa, pinos de saida e dispensador de placa
void tela_debug_saida_3(void); //tela que podemos acionar os alimentadores de solda, limpar os bicos e acionar os ferros
void tela_debug_saida_4(void); //tela que podemos realizar a movimentacao do eixo x, y, z e o flip individualmenta


void tela_programa_principal(void);//tela que aparece quando estamos no programa principal