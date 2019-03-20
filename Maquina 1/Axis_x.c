// <editor-fold defaultstate="collapsed" desc="Valores que devem ser inseridos">
float stepbyrev_x = 200; //pulso por volta (datasheet)
float driver_u_step_x = 1; //divisao entre chave/pulso por volta
float Leadscrew_x = 9; //tipo de redutor
float Leadscrew_Pich_x = 150; //comprimento da polia (datasheet)
float Vmax_x = 600;//esse valor deve ser em mm por segundo 600
float Vmin_x = 200; //200
float Amax_x = 450; //esse valor deve ser em mm por segundoï¿½ 500
// </editor-fold>

// <editor-fold defaultstate="collapsed" desc="Valores calculo rampa">
float MMbyStep_x = 0;
int8 StepinAcc_x = 20;
float Fmax_x = 0;
float Fmin_x = 100;
int32 Ts_x[20];
int32 StepbyF_x[20];
int16 total_acc_step_x = 0;
// </editor-fold>

// <editor-fold defaultstate="collapsed" desc="Flags e Controles de Movimento">
signed int8 pos_inc_x = 0;
int8 ramp_sts_x = ramp_idle;
short run_flg_x = FALSE;
short rest_x = FALSE;
int16 step_no_x = 0;
int16 step_down_x = 0;
int16 move_x = 0;
int16 midpt_x = 0;
int32 step_acumulado_x = 0;
int atual_frequencia_x = 0;
int vel_x = 19;
// </editor-fold>

// <editor-fold defaultstate="collapsed" desc="Pinos Motor">
#DEFINE     i_limite_x            5
#DEFINE     s_limite_x            6
// </editor-fold>   

// <editor-fold defaultstate="collapsed" desc="Inicializa Motor">
void init_axis_x(){
    set_tris_d(0xf8);
    output_high(step_x);
    output_high(enable_x);
    output_high(dir_x);
    
    MMbyStep_x = Leadscrew_Pich_x/(stepbyrev_x*driver_u_step_x*Leadscrew_x);
    Fmax_x = Vmax_x/MMbyStep_x; //Valor de ferequencia adiquirido em hz
    //Fmin_x = Vmin_x/MMbyStep_x;
    
    float den = Amax_x*StepinAcc_x;
    float num = (Vmax_x - Vmin_x)*1000000;
    float TbyF = num/den;//tempo em us
    
    int i = 0;
    for(i = 1; i <=StepinAcc_x;i++)
    {
        Ts_x[i-1]=(1000000*StepinAcc_x)/(i*(Fmax_x-Fmin_x)+Fmin_x);
        StepbyF_x[i-1] = 2*TbyF/Ts_x[i-1];
        total_acc_step_x += StepbyF_x[i-1];
        Ts_x[i-1] = Ts_x[i-1]/(8*0.2*2);//Tempo/(prescale*ciclodemaquina*metadedociclo)
    }
}
// </editor-fold>

// <editor-fold defaultstate="collapsed" desc="Movimento Motor">
void motor_stop_x(){
    step_no_x = step_down_x;
    ramp_sts_x = ramp_down;
}

void motor_disable_x(){
    output_high(enable_x);
    disable_interrupts(INT_TIMER0);
}

void motor_run_x(int32 pos_new, int velocidade) { // set up to drive motor to pos_new (absolute step#)
    
    vel_x = velocidade;
    total_acc_step_x = 0;
    
    /*Obtem a Direção do motor*/
    if (pos_new < motor_pos_x) 
    {
        output_low(dir_x);
        move_x = motor_pos_x - pos_new;
        pos_inc_x = -1;
    } else if (pos_new != motor_pos_x) {
        output_high(dir_x);
        move_x = pos_new - motor_pos_x;
        pos_inc_x = 1;
    } else return;
    
    /*Calcula a quantidade de passos para chegar na velocidade desejada*/
    for(int j = 0; j <= velocidade;j++)
    {
        total_acc_step_x += StepbyF_x[j];
    }
    /*Define Formato da Rampa(Trapezio,triangulo ou constante)*/
    if (move_x > 2 * total_acc_step_x) {
        midpt_x = total_acc_step_x;
        step_down_x = move_x - total_acc_step_x;
    } 
    else
    {
        midpt_x = (move_x - 1) >> 1;
        step_down_x = midpt_x;
    }
    step_no_x = 0;
    step_acumulado_x = 0;
    atual_frequencia_x = 0;
    ramp_sts_x = ramp_up; // start ramp state-machine
    run_flg_x = TRUE;
    output_low(enable_x);
    setup_timer_0(T0_INTERNAL | T0_DIV_8);
    set_timer0(65535 - Ts_x[0]);
    enable_interrupts(INT_TIMER0);
}

void proximo_valor_subida_x() {
    if (atual_frequencia_x == 0) {
        if (step_no_x == StepbyF_x[atual_frequencia_x]) {
            step_acumulado_x += StepbyF_x[atual_frequencia_x] + StepbyF_x[atual_frequencia_x + 1];
            atual_frequencia_x++;
            set_timer0(65535 - Ts_x[atual_frequencia_x]);
        } else {
            set_timer0(65535 - Ts_x[atual_frequencia_x]);
        }
    } else if (atual_frequencia_x == vel_x) {
        set_timer0(65535 - Ts_x[atual_frequencia_x]);
    } else {
        if (step_no_x == step_acumulado_x) {
            atual_frequencia_x++;
            step_acumulado_x += StepbyF_x[atual_frequencia_x];
            set_timer0(65535 - Ts_x[atual_frequencia_x]);
        } else {
            set_timer0(65535 - Ts_x[atual_frequencia_x]);
        }
        break;
    }
}

void proximo_valor_descida_x() {
    if (atual_frequencia_x == 0) {
        set_timer0(65535 - Ts_x[atual_frequencia_x]);
    } 
    else if (atual_frequencia_x == vel_x) {
        if (step_no_x == (step_down_x + StepbyF_x[atual_frequencia_x])) {
            step_acumulado_x = step_down_x + StepbyF_x[atual_frequencia_x] + StepbyF_x[atual_frequencia_x - 1];
            atual_frequencia_x--;
            set_timer0(65535 - Ts_x[atual_frequencia_x]);
        } else {
            set_timer0(65535 - Ts_x[atual_frequencia_x]);
        }
    } else {
        if (step_no_x == step_acumulado_x) {
            atual_frequencia_x--;
            step_acumulado_x += StepbyF_x[atual_frequencia_x];
            set_timer0(65535 - Ts_x[atual_frequencia_x]);
        } else {
            set_timer0(65535 - Ts_x[atual_frequencia_x]);
        }
    }
}

void movimenta_eixo_x() {
 
    switch (ramp_sts_x) {
        case ramp_up: // accel
            proximo_valor_subida_x();
            if (step_no_x == midpt_x) { // midpoint: decel
                if (move_x > 2 * total_acc_step_x)
                    ramp_sts_x = ramp_max;
                else
                    ramp_sts_x = ramp_down;
            }
            output_toggle(step_x);
            rest_x = ~rest_x;
            break;

        case ramp_down: // decel
            proximo_valor_descida_x();
            if (step_no_x == move_x)
                ramp_sts_x = ramp_last;
            output_toggle(step_x);
            rest_x = ~rest_x;
            break;

        case ramp_max: // constant speed
            proximo_valor_subida_x();
            if (step_no_x == step_down_x) // start decel
                ramp_sts_x = ramp_down;
            output_toggle(step_x);
            rest_x = ~rest_x;
            break;

        default: // last step: cleanup
            ramp_sts_x = ramp_idle;
            disable_interrupts(INT_TIMER0);
            run_flg_x = FALSE; // move_x complete
            break;
    } // switch (ramp_sts_x)
    if ((ramp_sts_x != ramp_idle)&&(ramp_sts_x != ramp_last)) {
        if (rest_x) {
            motor_pos_x += pos_inc_x;
            ++step_no_x;   
        }
    }
}

void umpasso_x(int16 descanco, short dir) {
    output_low(enable_x);
    if (dir) {
        output_high(dir_x);
        motor_pos_x++;
    } else {
        output_low(dir_x);
        motor_pos_x--;
    }
    output_high(step_x);
    delay_us(descanco);
    output_low(step_x);
    delay_us(descanco);
    
}

void zerar_x() {
    while(le_Input(i_limite_x)==1){
        delay_us(200);
        umpasso_x(600, TRUE);
    }
    while (le_Input(i_limite_x)==0){
        umpasso_x(900, FALSE);
        delay_us(200);
    }
    while(le_Input(i_limite_x)==1){
        delay_us(200);
        umpasso_x(1000, TRUE);
    }
    motor_pos_x = 0;
    output_high(enable_x);
}
// </editor-fold>
