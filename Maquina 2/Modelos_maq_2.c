long int tamPrograma = 358;

void ler_modelo_memoria(long int modeloSelecionado){
    long int i = 0;
    long int j = 0;
    long int endInicial = (modeloSelecionado - 1)* tamPrograma;
    pontos_no_modelo = read_ext_eeprom(endInicial);
    endInicial++;
    for(i = endInicial; i < (endInicial + tamPrograma) -1; i = i + 17)
    {
        if (i != 248){
            x[j] = make16(read_ext_eeprom(i),read_ext_eeprom(i+1));
            y[j] = make16(read_ext_eeprom(i+2),read_ext_eeprom(i+3));
            z[j] = make16(read_ext_eeprom(i+4),read_ext_eeprom(i+5));
            t_solda[j] = make16(read_ext_eeprom(i+6),read_ext_eeprom(i+7));
            t_wait[j] = make16(read_ext_eeprom(i+8),read_ext_eeprom(i+9));
            long int tipoHabilitado = read_ext_eeprom(i+10);
            tipo[j] = (tipoHabilitado & 0x06)>>1;
            habilitado[j] = tipoHabilitado & 0x01;
            numeroFerros[j] = read_ext_eeprom(i+11);
            t_solda2[j] = make16(read_ext_eeprom(i+12),read_ext_eeprom(i+13));
            t_solda3[j] = make16(read_ext_eeprom(i+14),read_ext_eeprom(i+15));
            limpar[j] = read_ext_eeprom(i+16);
            j++;
        }
    }
} //ler_modelo_memoria(modelo))
void escrever_ponto_memoria(long int modeloSelecionado, long int pontoSelecionado){
    long int endInicial = ((modeloSelecionado - 1)*tamPrograma) + (pontoSelecionado*17);
    write_ext_eeprom(endInicial+1,((x[pontoSelecionado]&0xff00)>>8));\
    write_ext_eeprom(endInicial+2,(x[pontoSelecionado]&0x00ff));
    write_ext_eeprom(endInicial+3,((y[pontoSelecionado]&0xff00)>>8));
    write_ext_eeprom(endInicial+4,(y[pontoSelecionado]&0x00ff));
    write_ext_eeprom(endInicial+5,((z[pontoSelecionado]&0xff00)>>8));
    write_ext_eeprom(endInicial+6,(z[pontoSelecionado]&0x00ff));
    write_ext_eeprom(endInicial+7,((t_solda[pontoSelecionado]&0xff00)>>8));
    write_ext_eeprom(endInicial+8,(t_solda[pontoSelecionado]&0x00ff));
    write_ext_eeprom(endInicial+9,((t_wait[pontoSelecionado]&0xff00)>>8));
    write_ext_eeprom(endInicial+10,(t_wait[pontoSelecionado]&0x00ff));
    write_ext_eeprom(endInicial+11,(tipo[pontoSelecionado]<<1)+habilitado[pontoSelecionado]);
    write_ext_eeprom(endInicial+12,(numeroFerros[pontoSelecionado]));
    write_ext_eeprom(endInicial+13,((t_solda2[pontoSelecionado]&0xff00)>>8));
    write_ext_eeprom(endInicial+14,(t_solda2[pontoSelecionado]&0x00ff));
    write_ext_eeprom(endInicial+15,((t_solda3[pontoSelecionado]&0xff00)>>8));
    write_ext_eeprom(endInicial+16,(t_solda3[pontoSelecionado]&0x00ff));
    write_ext_eeprom(endInicial+17,(limpar[pontoSelecionado]));
} //escrever_ponto_memoria(modelo,contador_lcd)
void excluir_modelo_memoria(long int modeloSelecionado){
    long int i = 0;
    long int endInicial = ((modeloSelecionado - 1)* tamPrograma);
    for (i = endInicial; i< ((endInicial)  + tamPrograma); i++){
        write_ext_eeprom(i,0);       
    }
} //excluir_modelo_memoria(modelo)
void escrever_pontos_no_modelo(long int modeloSelecionado,int quantidade_pontos){
    long int endInicial = ((modeloSelecionado - 1)*tamPrograma);
    write_ext_eeprom(endInicial,quantidade_pontos);
} //escrever_pontos_no_modelo(modelo,pontos_no_modelo)