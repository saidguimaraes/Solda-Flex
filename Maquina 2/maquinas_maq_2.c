void liga_pressor (void){
    aciona_saida(PRESSOR);
}
void desliga_pressor (void){
    desaciona_saida(PRESSOR);
}
void empurra_placa(void){
    short int b;
    short int c;
    b = le_Input(S_BANDEJA);
    while (b == 0){
        b = le_Input(S_BANDEJA);
        aciona_saida(DEDO_ENTRADA);
        aciona_saida(EMPURRADOR_ENTRADA_SOL_EMPURRA);
    }
    desaciona_saida(EMPURRADOR_ENTRADA_SOL_EMPURRA);
    c = le_Input(S_EMPURRADOR_IN_LS2);
    while (c == 0){
        c = le_Input(S_EMPURRADOR_IN_LS2);       
        aciona_saida(EMPURRADOR_ENTRADA_SOL_RETORNA);
    }
    desaciona_saida(DEDO_ENTRADA);
    desaciona_saida(EMPURRADOR_ENTRADA_SOL_RETORNA);
}
void dispensa_placa(void){
    short int b;
    short int c;
    b = le_Input(S_EMPURRADOR_OUT_LS1);
    while (b == 0){        
        aciona_saida(DEDO_SAIDA);
        aciona_saida(EMPURRADOR_SAIDA_SOL_EMPURRA);
        b = le_Input(S_EMPURRADOR_OUT_LS1);
    }
    desaciona_saida(EMPURRADOR_SAIDA_SOL_EMPURRA);
    c = le_Input(S_EMPURRADOR_OUT_LS2);
    while (c == 0){        
        c = le_Input(S_EMPURRADOR_OUT_LS2);
        aciona_saida(EMPURRADOR_SAIDA_SOL_RETORNA);
    }
    desaciona_saida(DEDO_SAIDA);
    desaciona_saida(EMPURRADOR_SAIDA_SOL_RETORNA);
}
void desce_ferros(int quantidade){
    if (quantidade == 0){
    }
    if (quantidade == 1){
        aciona_saida(FERRO_SOLDA1);
    }
    if (quantidade == 2){
        aciona_saida(FERRO_SOLDA2);
    }
    if (quantidade == 3){
        aciona_saida(FERRO_SOLDA1);
        aciona_saida(FERRO_SOLDA2);
    }
}
void sobe_ferros(void){
    desaciona_saida(FERRO_SOLDA1);
    desaciona_saida(FERRO_SOLDA2);
}
void liga_esteira(void){
    aciona_saida(RELE_ESTEIRA);
}
void desliga_esteira(void){
    desaciona_saida(RELE_ESTEIRA);
}
void limpa_bicos(long int tempo){
    aciona_saida(LIMPA_BICO1);
    aciona_saida(LIMPA_BICO2);
    delay_ms(tempo);
    desaciona_saida(LIMPA_BICO1);
    desaciona_saida(LIMPA_BICO2);    
}
void home_solenoides(void){
    desaciona_saida(DEDO_ENTRADA);
    desaciona_saida(DEDO_SAIDA);
    desaciona_saida(FERRO_SOLDA1);
    desaciona_saida(FERRO_SOLDA2);
    desaciona_saida(PRESSOR);
    desaciona_saida(LIMPA_BICO1);
    desaciona_saida(LIMPA_BICO2);
    
    aciona_saida(EMPURRADOR_ENTRADA_SOL_RETORNA);
    aciona_saida(EMPURRADOR_SAIDA_SOL_RETORNA);
    delay_ms(2500);
    desaciona_saida(EMPURRADOR_ENTRADA_SOL_RETORNA);
    desaciona_saida(EMPURRADOR_SAIDA_SOL_RETORNA);
}
int statusSolda(void){
    short int x;
    short int y;
    short int z;    
    x = le_Input(S_FIO_SOLDA1);
    y = le_Input(S_FIO_SOLDA2);
    z = le_Input(S_FIO_SOLDA3);
    if ((x==1)&&(y==1)&&(z==1)){
        return 1;
    } else {
        return 0;
    }
}
void ligar_alimentador_solda(int quantidade, long int tempo1, long int tempo2, long int tempo3){
    long int maior;
    long int medio;
    long int menor;
    switch(quantidade){
        case 0:
            aciona_saida(ALIMENTADOR2);
            delay_ms(tempo2);
            desaciona_saida(ALIMENTADOR2);
        break;
        case 1:
            if (tempo1 == tempo2){
                aciona_saida(ALIMENTADOR1);
                aciona_saida(ALIMENTADOR2);
                delay_ms(tempo1);
                desaciona_saida(ALIMENTADOR1);
                desaciona_saida(ALIMENTADOR2);
            } else {
                if (tempo1 > tempo2){
                    aciona_saida(ALIMENTADOR1);
                    aciona_saida(ALIMENTADOR2);
                    delay_ms(tempo2);
                    desaciona_saida(ALIMENTADOR2);
                    delay_ms(tempo1 - tempo2);
                    desaciona_saida(ALIMENTADOR1);
                } else {
                    aciona_saida(ALIMENTADOR1);
                    aciona_saida(ALIMENTADOR2);
                    delay_ms(tempo1);
                    desaciona_saida(ALIMENTADOR1);
                    delay_ms(tempo2 - tempo1);
                    desaciona_saida(ALIMENTADOR2);
                }
            }
        break;
        case 2:
            if (tempo2 == tempo3){
                aciona_saida(ALIMENTADOR2);
                aciona_saida(ALIMENTADOR3);
                delay_ms(tempo2);
                desaciona_saida(ALIMENTADOR2);
                desaciona_saida(ALIMENTADOR3);
            } else {
                if (tempo2 > tempo3){
                    aciona_saida(ALIMENTADOR2);
                    aciona_saida(ALIMENTADOR3);
                    delay_ms(tempo3);
                    desaciona_saida(ALIMENTADOR3);
                    delay_ms(tempo2 - tempo3);
                    desaciona_saida(ALIMENTADOR2);
                } else {
                    aciona_saida(ALIMENTADOR2);
                    aciona_saida(ALIMENTADOR3);
                    delay_ms(tempo2);
                    desaciona_saida(ALIMENTADOR2);
                    delay_ms(tempo3 - tempo2);
                    desaciona_saida(ALIMENTADOR3);
                }
            }
        break;
        case 3:
            if (tempo1>tempo2){
                if (tempo2>tempo3){
                    maior = tempo1;
                    medio = tempo2;
                    menor = tempo3;
                    aciona_saida(ALIMENTADOR1);
                    aciona_saida(ALIMENTADOR2);
                    aciona_saida(ALIMENTADOR3);
                    delay_ms(menor);
                    desaciona_saida(ALIMENTADOR3);
                    delay_ms(medio-menor);
                    desaciona_saida(ALIMENTADOR2);
                    delay_ms(maior-medio);
                    desaciona_saida(ALIMENTADOR1);
                } else {
                    if (tempo1 > tempo3) {
                        maior = tempo1;
                        medio = tempo3;
                        menor = tempo2;
                        aciona_saida(ALIMENTADOR1);
                        aciona_saida(ALIMENTADOR2);
                        aciona_saida(ALIMENTADOR3);
                        delay_ms(menor);
                        desaciona_saida(ALIMENTADOR2);
                        delay_ms(medio-menor);
                        desaciona_saida(ALIMENTADOR3);
                        delay_ms(maior-medio);
                        desaciona_saida(ALIMENTADOR1);
                    } else {
                        maior = tempo3;
                        medio = tempo1;
                        menor = tempo2;
                        aciona_saida(ALIMENTADOR1);
                        aciona_saida(ALIMENTADOR2);
                        aciona_saida(ALIMENTADOR3);
                        delay_ms(menor);
                        desaciona_saida(ALIMENTADOR2);
                        delay_ms(medio-menor);
                        desaciona_saida(ALIMENTADOR1);
                        delay_ms(maior-medio);
                        desaciona_saida(ALIMENTADOR3);
                    }
                }
            } else {
                if (tempo2>tempo3){
                    if (tempo1 > tempo3){
                        maior = tempo2;
                        medio = tempo1;
                        menor = tempo3;
                        aciona_saida(ALIMENTADOR1);
                        aciona_saida(ALIMENTADOR2);
                        aciona_saida(ALIMENTADOR3);
                        delay_ms(menor);
                        desaciona_saida(ALIMENTADOR3);
                        delay_ms(medio-menor);
                        desaciona_saida(ALIMENTADOR1);
                        delay_ms(maior-medio);
                        desaciona_saida(ALIMENTADOR2);
                    } else {
                        maior = tempo2;
                        medio = tempo3;
                        menor = tempo1;
                        aciona_saida(ALIMENTADOR1);
                        aciona_saida(ALIMENTADOR2);
                        aciona_saida(ALIMENTADOR3);
                        delay_ms(menor);
                        desaciona_saida(ALIMENTADOR1);
                        delay_ms(medio-menor);
                        desaciona_saida(ALIMENTADOR3);
                        delay_ms(maior-medio);
                        desaciona_saida(ALIMENTADOR2);
                    }
                } else {
                    maior = tempo3;
                    medio = tempo2;
                    menor = tempo1;
                    aciona_saida(ALIMENTADOR1);
                    aciona_saida(ALIMENTADOR2);
                    aciona_saida(ALIMENTADOR3);
                    delay_ms(menor);
                    desaciona_saida(ALIMENTADOR1);
                    delay_ms(medio-menor);
                    desaciona_saida(ALIMENTADOR2);
                    delay_ms(maior-medio);
                    desaciona_saida(ALIMENTADOR3);
                }
            }
        break;
    }
            
}

void soldar_teste(int componente, int local){
    liga_pressor();
    if ((local == 14)&&(modelo == 1)){
        local++;
    }
    if ((y[local] > 700)&&(x[local] > 0)){
        desce_ferros(numeroFerros[local]);
        switch (componente){
            case 0:
                motor_run_y(y[local], 19);
                while ((run_flg_y));
                motor_run_x(x[local], 19);
                while ((run_flg_x));
                ligar_alimentador_solda(numeroFerros[local],t_solda[local],t_solda2[local],t_solda3[local]);
                motor_run_z(z[local], 19);
                while ((run_flg_z));
                delay_ms(t_wait[local]); 
                motor_run_z(0, 19);
                while ((run_flg_z));
                desce_ferros(3);
                aciona_saida(LIMPA_BICO1);
                aciona_saida(LIMPA_BICO2);
                delay_ms(200);
                desaciona_saida(LIMPA_BICO1);
                desaciona_saida(LIMPA_BICO2);
                sobe_ferros();
            break;
            case 1:
                motor_run_y(y[local], 19);
                while ((run_flg_y));
                motor_run_x(x[local], 19);
                while ((run_flg_x));
                ligar_alimentador_solda(numeroFerros[local],t_solda[local],t_solda2[local],t_solda3[local]);
                motor_run_z(z[local], 19);
                while ((run_flg_z));
                delay_ms(t_wait[local]);
                motor_run_z(z[local]-5, 19);
                while ((run_flg_z));
                motor_run_x(x[local]-21, 19);
                while ((run_flg_x));
                motor_run_z(z[local], 19);
                while ((run_flg_z));
                delay_ms(t_wait[local]);  
                motor_run_z(z[local]-5, 19);
                while ((run_flg_z));
                motor_run_x(x[local]-42, 19);
                while ((run_flg_x));
                motor_run_z(z[local], 19);
                while ((run_flg_z));
                delay_ms(t_wait[local]);
                motor_run_z(z[local]-5, 19);
                while ((run_flg_z));
                motor_run_x(x[local]+40, 19);
                while ((run_flg_x));
                motor_run_z(0, 19);
                while ((run_flg_z));
                desce_ferros(3);
                aciona_saida(LIMPA_BICO1);
                aciona_saida(LIMPA_BICO2);
                delay_ms(200);
                desaciona_saida(LIMPA_BICO1);
                desaciona_saida(LIMPA_BICO2);
                sobe_ferros();
            break;
        }
    }
    else {
        printf(lcd_putc, "\f"); //limpa display
        printf(lcd_putc, "  POSICAO IRREGULAR \n\r");
        printf(lcd_putc, "   X DEVE SER > 0   \n\r");
        printf(lcd_putc, "  Y DEVE SER > 700  \n\r");
        delay_ms(5000);
    }
    sobe_ferros();
} //void soldar_teste(tipo[contador_lcd], contador_lcd)
void soldar(void){
    liga_pressor();
    for(int i=0; i < pontos_no_modelo+1; i++){
        if ((i == 14)&&(modelo == 1)){
            i++;
        }
        if (habilitado[i] == TRUE) {
            switch (tipo[i]){
                case 0:
                    motor_run_y(y[i], 19);
                    while ((run_flg_y));
                    motor_run_x(x[i], 19);
                    while ((run_flg_x));
                    desce_ferros(numeroFerros[i]);
                    ligar_alimentador_solda(numeroFerros[i],t_solda[i],t_solda2[i],t_solda3[i]);
                    motor_run_z(z[i], 19);
                    while ((run_flg_z));
                    delay_ms(t_wait[i]);
                    if (limpar[i] == 1){
                        motor_run_z(0, 19);
                        while ((run_flg_z));
                        desce_ferros(3);
                        delay_ms(200);
                        aciona_saida(LIMPA_BICO1);
                        aciona_saida(LIMPA_BICO2);
                        delay_ms(125);
                        desaciona_saida(LIMPA_BICO1);
                        desaciona_saida(LIMPA_BICO2);
                        sobe_ferros();
                    } else {
                        motor_run_z(270, 19);
                        while ((run_flg_z));
                    }                  
                break;
                case 1:                    
                    motor_run_y(y[i], 19);
                    while ((run_flg_y));
                    motor_run_x(x[i], 19);
                    while ((run_flg_x));
                    desce_ferros(numeroFerros[i]);
                    ligar_alimentador_solda(numeroFerros[i],t_solda[i],t_solda2[i],t_solda3[i]);
                    motor_run_z(z[i], 19);
                    while ((run_flg_z));
                    delay_ms(t_wait[i]);
                    motor_run_z(z[i]-8, 19);
                    while ((run_flg_z));
                    motor_run_x(x[i]-21, 19);
                    while ((run_flg_x));
                    motor_run_z(z[i], 19);
                    while ((run_flg_z));
                    delay_ms(t_wait[i]);  
                    motor_run_z(z[i]-8, 19);
                    while ((run_flg_z));
                    motor_run_x(x[i]-42, 19);
                    while ((run_flg_x));
                    motor_run_z(z[i], 19);
                    while ((run_flg_z));
                    delay_ms(t_wait[i]);
                    motor_run_z(z[i]-8, 19);
                    while ((run_flg_y));
                    motor_run_x(x[i]+55, 19);
                    while ((run_flg_x || run_flg_z));
                    if (limpar[i] == 1){
                        motor_run_z(0, 19);
                        while ((run_flg_z));
                        desce_ferros(3);
                        delay_ms(200);
                        aciona_saida(LIMPA_BICO1);
                        aciona_saida(LIMPA_BICO2);
                        delay_ms(125);
                        desaciona_saida(LIMPA_BICO1);
                        desaciona_saida(LIMPA_BICO2);
                        sobe_ferros();
                    } else {
                        motor_run_z(270, 19);
                        while ((run_flg_z));
                    }            
                break;
            }
        }
        sobe_ferros();
    }
}