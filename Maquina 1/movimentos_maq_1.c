int   flip_home(void) {
	int i;
    int erro=0;
	chopper_flip();
	delay_ms(50);	
	if(le_Input(S_ROTACAO_LS1) == true) {
		sentido_horario();
		delay_ms(50);
	    for(i=0;i<=140;i++) {							
		    one_step_flip();
			delay_us(4000);
		}
		sentido_antihorario();
		delay_ms(100);
	    while(le_Input(S_ROTACAO_LS1) == false) {				
            one_step_flip();
            delay_us(4000);
		}				
        for(i=0;i<=36;i++) {
            one_step_flip();
            delay_us(4000);
        }
        sentido_horario();
        delay_ms(50);		
	}else{			
        sentido_antihorario();
        delay_ms(50);
        while(le_Input(S_ROTACAO_LS1) == false){				
            one_step_flip();
            delay_us(2000);
        }				
        for(i=0;i<=36;i++) {
            one_step_flip();
            delay_us(4000);
        }
	}	 
    sentido_horario();
    delay_ms(50);
    for(i=0;i<=71;i++) {
        one_step_flip();
        delay_us(4000);
    }
    motor_pos_flip = 0;			
    return erro;
}
void  x_home_esquerda() {
	int i;
	chopper_x();
	delay_ms(50);	
	if(le_Input(S_X_ESQUERDA) == true) {
		direita();
		delay_ms(50);
        while(le_Input(S_X_ESQUERDA) == true) {
            one_step_x();
            delay_us(2000);
        }
        for(i=0;i<=40;i++) {
            one_step_x();
            delay_us(2000);
        }
		esquerda();
		delay_ms(50);
        while(le_Input(S_X_ESQUERDA) == false) {				
            one_step_x();
            delay_us(2000);
		}			
        for(i=0;i<=40;i++) {
            one_step_x();
            delay_us(2000);
        }
	}else{
        esquerda();
        delay_ms(50);
        while(le_Input(S_X_ESQUERDA) == false) {
            one_step_x();
            delay_us(2000);
        }				
        for(i=0;i<=40;i++) {
            one_step_x();
            delay_us(2000);
        }
	}	
    motor_pos_x = 0; 
    stop_x();			
}
void  y_home_frente(){
	int i;
	chopper_y();
	delay_ms(50);	
	if(le_Input(S_Y_FRENTE) == true) {
		atras();
		delay_ms(50);
        while(le_Input(S_Y_FRENTE) == true) {
            one_step_y();
            delay_us(2000);
        }
        for(i=0;i<=40;i++) { //para sair do histerese do sensor dando maior precisao
            one_step_y();
            delay_us(2000);
        }
		frente();
		delay_ms(50);
        while(le_Input(S_Y_FRENTE) == false){				
            one_step_y();
            delay_us(2000);
        }				
        for(i=0;i<=40;i++){
            one_step_y();
            delay_us(2000);
        }
	}else{
        frente();
        delay_ms(50);
        while(le_Input(S_Y_FRENTE) == false) {
            one_step_y();
            delay_us(2000);
        }				
        for(i=0;i<=40;i++) {
            one_step_y();
            delay_us(2000);
        }
	}	
    motor_pos_y = 0;  
    stop_y();			
}
void  y_home_atras() {
	int i;
	chopper_y();
	delay_ms(50);	
	if(le_Input(S_Y_ATRAS) == true) {
		frente();
		delay_ms(50);
        while(le_Input(S_Y_ATRAS) == true){
            one_step_y();
            delay_us(2000);
        }
        for(i=0;i<=40;i++){ //para sair do histerese do sensor dando maior precisao
            one_step_y();
            delay_us(2000);
        }
		atras();
		delay_ms(50);
        while(le_Input(S_Y_ATRAS) == false) {				
            one_step_y();
            delay_us(2000);
        }				
        for(i=0;i<=40;i++){
            one_step_y();
            delay_us(2000);
        }
	}else{
        atras();
        delay_ms(50);
        while(le_Input(S_Y_ATRAS) == false) {
            one_step_y();
            delay_us(2000);
        }
        for(i=0;i<=40;i++) {
            one_step_y();
            delay_us(2000);
        }
	}	
    motor_pos_y = 0;   
    stop_y();			
}
void  x_home_direita() { 
	int i;
	chopper_x();
	delay_ms(50);	
	if(le_Input(S_X_DIREITA) == true) {
		esquerda();
		delay_ms(50);
        while(le_Input(S_X_DIREITA) == true) {
            one_step_x();
            delay_us(2000);
        }
        for(i=0;i<=40;i++){ //para sair do histerese do sensor dando maior precisao
            one_step_x();
            delay_us(2000);
        }
		direita();
		delay_ms(50);
        while(le_Input(S_X_DIREITA) == false) {				
            one_step_x();
            delay_us(2000);
        }				
        for(i=0;i<=40;i++) {
            one_step_x();
            delay_us(2000);
        }
	}else{			
        direita();
        delay_ms(50);
        while(le_Input(S_X_DIREITA) == false) {
            one_step_x();
            delay_us(2000);
        }
        for(i=0;i<=40;i++) {
            one_step_x();
            delay_us(2000);
        }
	}
    motor_pos_x = 0;   
    stop_x();			
}
void  z_home() {
	int i;
	chopper_z();
	delay_ms(50);	
	if(le_Input(S_Z_TOP) == true) {
		desce();
		delay_ms(50);
        for(i=0;i<=50;i++){
            one_step_z();
            delay_us(2000);
        }
        sobe();
        delay_ms(50);
        while(le_Input(S_Z_TOP) == false) {				
            one_step_z();
            delay_us(2000);
        }				
        for(i=0;i<=18;i++){
            one_step_z();
            delay_us(2000);
        }
	}else{
        sobe();
        delay_ms(50);
        while(le_Input(S_Z_TOP) == false) {
            one_step_z();
            delay_us(2000);
        }
        for(i=0;i<=18;i++) {
            one_step_z();
            delay_us(2000);
        }
	}
    motor_pos_z = 0;   
	stop_z();			
}

void envia_maquina_para_posicao(int posicao_futura){
    motor_run_z(0, 19);
    while ((run_flg_z));
    switch (posicao_futura){
        case ALIMENTADOR:
            if(posicao_atual != ALIMENTADOR){            
                while ((posicao_atual == SOLDAGEM)||(posicao_atual == HOME2)){
                    tela_esperando_mov_maquina();                
                }
                posicao_outra_maquina = le_posicao_outra_maquina();
                while ((posicao_outra_maquina == ALIMENTADOR)){
                    tela_esperando_sair_posicao_outra_maquina();
                    posicao_outra_maquina = le_posicao_outra_maquina();
                }
                if (posicao_atual == DISPENSADOR){                    
                    tela_movimentando_maquina(ALIMENTADOR);
                    motor_run_y(700, 19);
                    while ((run_flg_y));
                    envia_posicao_para_outra_maquina(ALIMENTADOR);
                    motor_run_flip(0, 19);
                    while ((run_flg_flip));
                    motor_run_y(0, 19);
                    while ((run_flg_y));
                    motor_run_x(50, 19);
                    while ((run_flg_x));
                }
                if (posicao_atual == HOME1){
                    envia_posicao_para_outra_maquina(ALIMENTADOR);
                    tela_movimentando_maquina(ALIMENTADOR);
                    motor_run_x(0, 19);
                    while ((run_flg_x));
                    motor_run_flip(0, 19);
                    while ((run_flg_flip));
                    motor_run_y(0, 19);
                    while ((run_flg_y));
                    motor_run_x(50, 19);
                    while ((run_flg_x));                   
                }
                posicao_atual = ALIMENTADOR;
            }
        break;
        case HOME1:
            if(posicao_atual != HOME1){            
                while (posicao_atual == DISPENSADOR){
                    tela_esperando_mov_maquina();                
                }
                if (posicao_atual == SOLDAGEM){
                    tela_movimentando_maquina(HOME1);
                    motor_run_y(800, 19);
                    while ((run_flg_y));
                    motor_run_x(3835, 19);
                    while ((run_flg_x));
                    envia_posicao_para_outra_maquina(HOME1);                   
                }
                if (posicao_atual == HOME2){
                    tela_movimentando_maquina(HOME1);
                    motor_run_x(3835, 19);
                    while ((run_flg_x));
                    motor_run_y(800, 19);
                    while ((run_flg_y));
                    motor_run_x(3835, 19);
                    while ((run_flg_x));
                    envia_posicao_para_outra_maquina(HOME1);                   
                }
                if (posicao_atual == ALIMENTADOR){
                    tela_movimentando_maquina(HOME1);
                    motor_run_y(800, 19);
                    while ((run_flg_y));
                    motor_run_flip(1869, 19);
                    while ((run_flg_flip));
                    motor_run_x(3835, 19);
                    while ((run_flg_x));
                    envia_posicao_para_outra_maquina(HOME1);                   
                }
                posicao_atual = HOME1;
            }
        break;
        case SOLDAGEM:
            if(posicao_atual != SOLDAGEM){
                while ((posicao_atual == DISPENSADOR)||(posicao_atual == HOME2)){
                    tela_esperando_mov_maquina();                
                }
                if (posicao_atual == HOME1){
                    tela_movimentando_maquina(SOLDAGEM);
                    motor_run_x(3835, 19);
                    while ((run_flg_x));
                    motor_run_y(2540, 19);
                    while ((run_flg_y));
                    envia_posicao_para_outra_maquina(SOLDAGEM);                   
                }
                if (posicao_atual == ALIMENTADOR){
                    tela_movimentando_maquina(SOLDAGEM);
                    motor_run_y(800, 19);
                    while ((run_flg_y));
                    motor_run_flip(1869, 19);
                    while ((run_flg_flip));
                    motor_run_x(3835, 19);
                    while ((run_flg_x));
                    envia_posicao_para_outra_maquina(SOLDAGEM);
                    motor_run_y(2540, 19);
                    while ((run_flg_y));                   
                }
                posicao_atual = SOLDAGEM;
            }
        break;
        case HOME2:
            if(posicao_atual != HOME2){
                while ((posicao_atual == ALIMENTADOR)){
                    tela_esperando_mov_maquina();                
                }
                if (posicao_atual == DISPENSADOR){
                    tela_movimentando_maquina(HOME2);
                    motor_run_y(5500, 19);
                    while ((run_flg_y));
                    motor_run_x(3835, 19);
                    while ((run_flg_x));
                    envia_posicao_para_outra_maquina(HOME2);                   
                }
                if (posicao_atual == SOLDAGEM){
                    tela_movimentando_maquina(HOME2);
                    motor_run_y(5500, 19);
                    while ((run_flg_y));
                    motor_run_x(3835, 19);
                    while ((run_flg_x));
                    envia_posicao_para_outra_maquina(HOME2);                   
                }
                if (posicao_atual == HOME1){
                    tela_movimentando_maquina(HOME2);
                    motor_run_x(3835, 19);
                    while ((run_flg_x));
                    motor_run_y(5500, 19);
                    while ((run_flg_y));
                    motor_run_x(3835, 19);
                    while ((run_flg_x));
                    envia_posicao_para_outra_maquina(HOME2);                   
                }
                posicao_atual = HOME2;
            }
        break;
        case DISPENSADOR:
            if(posicao_atual != DISPENSADOR){
                while (posicao_atual != HOME2){
                    tela_esperando_mov_maquina();                
                }
                envia_posicao_para_outra_maquina(DISPENSADOR);
                if (posicao_atual == HOME2){   
                    posicao_outra_maquina = le_posicao_outra_maquina();
                    while ((posicao_outra_maquina == DISPENSADOR)){
                        tela_esperando_sair_posicao_outra_maquina();
                        posicao_outra_maquina = le_posicao_outra_maquina();
                    }
                    tela_movimentando_maquina(DISPENSADOR);
                    motor_run_x(0, 19);
                    while ((run_flg_x));
                    motor_run_y(6110, 19);
                    while ((run_flg_y));                   
                }
                posicao_atual = DISPENSADOR;
            }
        break;
    }
}
void posicao_maquina_1_default(void) {
    envia_posicao_para_outra_maquina(ALIMENTADOR);
    tela_movimentando_maquina(ALIMENTADOR);
    long int i = 0;
    z_home();
    if (le_Input(S_Y_ATRAS) == true) {
        y_home_atras();
        x_home_esquerda();
        y_home_frente();
        
    } else {
        if (le_Input(S_Y_FRENTE) == true) {

            y_home_frente();
            x_home_esquerda();
        } else {
            x_home_esquerda();
            y_home_frente();
        }
    }
    posicao_atual = HOME1;
    envia_posicao_para_outra_maquina(HOME1);
    posicao_outra_maquina = le_posicao_outra_maquina();
    while ((posicao_outra_maquina != ALIMENTADOR)){
        posicao_outra_maquina = le_posicao_outra_maquina();
    }
    posicao_outra_maquina = le_posicao_outra_maquina();
    while ((posicao_outra_maquina != HOME1)){
        posicao_outra_maquina = le_posicao_outra_maquina();
    }
    x_home_direita();
    flip_home();
    chopper_y();
    frente();
    delay_ms(50);
    for (i = 0; i < 700; i++) {
        one_step_y();
        delay_us(2000);
    }
    chopper_x();
    esquerda();
    delay_ms(50);    
    motor_pos_x = 0x0000;
    motor_pos_y = 0x0000;
    motor_pos_flip = 0x0000;
    motor_pos_z = 0x0000;
    motor_run_x(50, 19);
    posicao_atual = ALIMENTADOR;
    envia_posicao_para_outra_maquina(ALIMENTADOR);
}
void posicao_volta_manutencao(void) {
    tela_movimentando_maquina(ALIMENTADOR);
    long int i = 0;
    z_home();
    if (le_Input(S_Y_ATRAS) == true) {
        y_home_atras();
        x_home_esquerda();
        y_home_frente();
        
    } else {
        if (le_Input(S_Y_FRENTE) == true) {

            y_home_frente();
            x_home_esquerda();
        } else {
            x_home_esquerda();
            y_home_frente();
        }
    }
    x_home_direita();
    flip_home();
    chopper_y();
    frente();
    delay_ms(50);
    for (i = 0; i < 700; i++) {
        one_step_y();
        delay_us(2000);
    }
    chopper_x();
    esquerda();
    delay_ms(50);    
    motor_pos_x = 0x0000;
    motor_pos_y = 0x0000;
    motor_pos_flip = 0x0000;
    motor_pos_z = 0x0000;
    motor_run_x(50, 19);
    posicao_atual = ALIMENTADOR;
    envia_posicao_para_outra_maquina(ALIMENTADOR);
}