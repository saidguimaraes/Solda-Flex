// <editor-fold defaultstate="collapsed" desc="Valores que devem ser inseridos">
float stepbyrev_y = 200;
float driver_u_step_y = 1; // caso o driver esteja em 400
float Leadscrew_y = 9; //redutor de voltas do motor
float Leadscrew_Pich_y = 150; //esse valor deve ser em mm/revolu��o
float Vmax_y = 600; //esse valor deve ser em mm por segundo
float Vmin_y = 200;
float Amax_y = 450; //esse valor deve ser em mm por segundo�
// </editor-fold>

// <editor-fold defaultstate="collapsed" desc="Valores calculo rampa">
float MMbyStep_y = 0;
int8 StepinAcc_y = 20;
float Fmax_y = 0;
float Fmin_y = 100;
int32 Ts_y[20];
int32 StepbyF_y[20];
int16 total_acc_step_y = 0;
// </editor-fold>

// <editor-fold defaultstate="collapsed" desc="Flags e Controles de Movimento">
signed int8 pos_inc_y = 0;
int8 ramp_sts_y = ramp_idle;
short run_flg_y = FALSE;
short rest_y = FALSE;
short stop_yf = FALSE;
int16 step_no_y = 0;
int16 step_down_y = 0;
int16 move_y = 0;
int16 midpt_y = 0;
int32 step_acumulado_y = 0;
int atual_frequencia_y = 0;
int vel_y = 19;
int16 max_posicao_y=0;
// </editor-fold>

// <editor-fold defaultstate="collapsed" desc="Pinos Motor">

#DEFINE     i_limite_y            7
#DEFINE     s_limite_y            8

// </editor-fold>

// <editor-fold defaultstate="collapsed" desc="Inicializa Motor">
void init_axis_y() {
    set_tris_c(0xf8);
    output_high(step_y);
    output_high(enable_y);
    output_high(dir_y);

    MMbyStep_y = Leadscrew_Pich_y / (stepbyrev_y * driver_u_step_y * Leadscrew_y);
    Fmax_y = Vmax_y/MMbyStep_y; //Valor de ferequencia adiquirido em hz
    
    float den = Amax_y*StepinAcc_y;
    float num = (Vmax_y-Vmin_y)*1000000;
    float TbyF = num/den;//tempo em us
    
    int i = 0;
    for(i = 1; i <=StepinAcc_y;i++)
    {
        Ts_y[i-1]=(1000000*StepinAcc_y)/((i*(Fmax_y-Fmin_y)+Fmin_y));
        StepbyF_y[i-1] = 2*TbyF/Ts_y[i-1];
        total_acc_step_y += StepbyF_y[i-1];
        Ts_y[i-1] = Ts_y[i-1]/(8*0.2*2);//Tempo/(prescale*ciclodemaquina*metadedociclo)
    }
}
// </editor-fold>

// <editor-fold defaultstate="collapsed" desc="Movimento Motor">
void motor_stop_y(){
    step_no_y = step_down_y;
    ramp_sts_y = ramp_down;
}

void motor_disable_y(){
    output_high(enable_y);
    disable_interrupts(INT_TIMER1);
}

void motor_run_y(int32 pos_new, int velocidade) { // set up to drive motor to pos_new (absolute step#)
    vel_y = velocidade;
    total_acc_step_y = 0;
    
    if (pos_new < motor_pos_y) // get dir_yection & #steps
    {
        output_low(dir_y);
        move_y = motor_pos_y - pos_new;
        pos_inc_y = -1;
    } else if (pos_new != motor_pos_y) {
        output_high(dir_y);
        move_y = pos_new - motor_pos_y;
        pos_inc_y = 1;
    } else return;

    for(int j = 0; j <= velocidade;j++)
    {
        total_acc_step_y += StepbyF_y[j];
    }
    if (move_y > 2 * total_acc_step_y) {
        midpt_y = total_acc_step_y;
        step_down_y = move_y - total_acc_step_y;
    } 
    else
    {
        midpt_y = (move_y - 1) >> 1;
        step_down_y = midpt_y;
    }
    step_no_y = 0;
    step_acumulado_y = 0;
    atual_frequencia_y = 0;
    ramp_sts_y = ramp_up; // start ramp state-machine
    run_flg_y = TRUE;
    output_low(enable_y);
    setup_timer_1(T1_INTERNAL | T1_DIV_BY_8);
    set_timer1(65535 - Ts_y[0]);
    enable_interrupts(INT_TIMER1);
}

void proximo_valor_subida_y() {
    if (atual_frequencia_y == 0) {
        if (step_no_y == StepbyF_y[atual_frequencia_y]) {
            step_acumulado_y += StepbyF_y[atual_frequencia_y] + StepbyF_y[atual_frequencia_y + 1];
            atual_frequencia_y++;
            set_timer1(65535 - Ts_y[atual_frequencia_y]);
        } else {
            set_timer1(65535 - Ts_y[atual_frequencia_y]);
        }
    } else if (atual_frequencia_y == vel_y) {
        set_timer1(65535 - Ts_y[atual_frequencia_y]);
    } else {
        if (step_no_y == step_acumulado_y) {
            atual_frequencia_y++;
            step_acumulado_y += StepbyF_y[atual_frequencia_y];
            set_timer1(65535 - Ts_y[atual_frequencia_y]);
        } else {
            set_timer1(65535 - Ts_y[atual_frequencia_y]);
        }
        break;
    }
}

void proximo_valor_descida_y() {
    if (atual_frequencia_y == 0) {
        set_timer1(65535 - Ts_y[atual_frequencia_y]);
    } 
    else if (atual_frequencia_y == vel_y) {
        if (step_no_y == (step_down_y + StepbyF_y[atual_frequencia_y])) {
            step_acumulado_y = step_down_y + StepbyF_y[atual_frequencia_y] + StepbyF_y[atual_frequencia_y - 1];
            atual_frequencia_y--;
            set_timer1(65535 - Ts_y[atual_frequencia_y]);
        } else {
            set_timer1(65535 - Ts_y[atual_frequencia_y]);
        }
    } else {
        if (step_no_y == step_acumulado_y) {
            atual_frequencia_y--;
            step_acumulado_y += StepbyF_y[atual_frequencia_y];
            set_timer1(65535 - Ts_y[atual_frequencia_y]);
        } else {
            set_timer1(65535 - Ts_y[atual_frequencia_y]);
        }
    }
}

void movimenta_eixo_y() {
    
    switch (ramp_sts_y) {

        case ramp_up: // accel
            output_toggle(step_y);
            rest_y = ~rest_y;
            proximo_valor_subida_y();
            if (step_no_y == midpt_y) { // midpoint: decel
                if (move_y > 2 * total_acc_step_y)
                    ramp_sts_y = ramp_max;
                else
                    ramp_sts_y = ramp_down;
            }
            break;

        case ramp_down: // decel
            proximo_valor_descida_y();
            if (step_no_y == move_y)
                ramp_sts_y = ramp_last;
            output_toggle(step_y);
            rest_y = ~rest_y;
            break;

        case ramp_max: // constant speed
            proximo_valor_subida_y();
            if (step_no_y == step_down_y) // start decel
                ramp_sts_y = ramp_down;
            output_toggle(step_y);
            rest_y = ~rest_y;
            break;

        default: // last step: cleanup
            ramp_sts_y = ramp_idle;
            stop_yf = FALSE;
            disable_interrupts(INT_TIMER1);
            run_flg_y = FALSE; // move_y complete
            break;
    } // switch (ramp_sts_y)
    if (ramp_sts_y != ramp_idle) {
        if (rest_y) {
            motor_pos_y += pos_inc_y;
            ++step_no_y;
        }
    }
}

void umpasso_y(int16 descanco, short dir) {
    output_low(enable_y);
    if (dir) {
        output_high(dir_y);
        motor_pos_y--;
    } else {
        output_low(dir_y);
        motor_pos_y++;
    }
    output_high(step_y);
    delay_us(descanco);
    output_low(step_y);
    delay_us(descanco);
    //output_high(enable_y);
}

void zerar_y() {
    while(le_Input(i_limite_y)==1){
        umpasso_y(600, FALSE);
        delay_us(200);
    }
    while (le_Input(i_limite_y)==0){
        umpasso_y(900,TRUE);
        delay_us(200);
    }
    while(le_Input(i_limite_y)==1){
        umpasso_y(1000, FALSE);
        delay_us(200);
    }
    motor_pos_y = 0;
    output_high(enable_y);
}
void medir_y(){
    while (le_Input(s_limite_y)==0){
        umpasso_y(900,FALSE);
        delay_us(200);
    }
    while (le_Input(s_limite_y)==1){
        umpasso_y(900,TRUE);
        delay_us(200);
    }
    max_posicao_y = motor_pos_y;
    output_high(enable_y);
}
// </editor-fold>