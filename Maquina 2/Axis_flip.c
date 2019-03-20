// <editor-fold defaultstate="collapsed" desc="Valores que devem ser inseridos">
float stepbyrev_flip = 200;
float driver_u_step_flip = 1; // caso o driver esteja em 400
float Leadscrew_flip = 9; //redutor de voltas do motor
float Leadscrew_Pich_flip = 150; //esse valor deve ser em mm/revoluï¿½ï¿½o
float Vmax_flip = 600; //esse valor deve ser em mm por segundo
float Amax_flip = 300; //esse valor deve ser em mm por segundoï
// </editor-fold>

// <editor-fold defaultstate="collapsed" desc="Valores calculo rampa">
float MMbyStep_flip = 0;
int8 StepinAcc_flip = 20;
float Fmax_flip = 0;
int32 Ts_flip[20];
int32 StepbyF_flip[20];
int16 total_acc_step_flip = 0;
// </editor-fold>

// <editor-fold defaultstate="collapsed" desc="Flags e Controles de Movimento">
signed int8 pos_inc_flip = 0;
int8 ramp_sts_flip = ramp_idle;
short rest_flip = false;
int16 step_no_flip = 0;
int16 step_down_flip = 0;
int16 move_flip = 0;
int16 midpt_flip = 0;
int32 step_acumulado_flip = 0;
int atual_frequencia_flip = 0;
int vel_flip = 19;
int16 max_posicao_flip = 0;
// </editor-fold>

// <editor-fold defaultstate="collapsed" desc="Pinos Motor">
#DEFINE     s_limite_flip            11
#DEFINE     i_limite_flip            11

// </editor-fold>

// <editor-fold defaultstate="collapsed" desc="Inicializa Motor">
void init_axis_flip() {
    set_tris_a(0x00);
    output_high(step_flip);
    output_high(enable_flip);
    output_high(dir_flip);

    MMbyStep_flip = Leadscrew_Pich_flip / (stepbyrev_flip * driver_u_step_flip * Leadscrew_flip);
    Fmax_flip = Vmax_flip / MMbyStep_flip; //Valor de ferequencia adiquirido em hz

    float den = Amax_flip*StepinAcc_flip;
    float num = Vmax_flip * 1000000;
    float TbyF = num / den; //tempo em us

    int i = 0;
    for (i = 1; i <= StepinAcc_flip; i++) {
        Ts_flip[i - 1] = (1000000 * StepinAcc_flip) / (i * Fmax_flip);
        StepbyF_flip[i - 1] = 2 * TbyF / Ts_flip[i - 1];
        total_acc_step_flip += StepbyF_flip[i - 1];
        Ts_flip[i - 1] = Ts_flip[i - 1] / (8 * 0.2 * 2); //Tempo/(prescale*ciclodemaquina*metadedociclo)
    }
}
// </editor-fold>

// <editor-fold defaultstate="collapsed" desc="Movimento Motor">
void motor_stop_flip() {
    step_no_flip = step_down_flip;
    ramp_sts_flip = ramp_down;
}

void motor_disable_flip() {
    output_high(enable_flip);
    disable_interrupts(INT_TIMER3);
}

void motor_run_flip(int32 pos_new, int velocidade) { // set up to drive motor to pos_new (absolute step#)
    vel_flip = velocidade;
    total_acc_step_flip = 0;

    if (!run_flg_z) {
        flgMove = FALSE;
        if (pos_new < motor_pos_flip) // get dir_yection & #steps
        {
            output_high(dir_flip);
            move_flip = motor_pos_flip - pos_new;
            pos_inc_flip = -1;
        } else if (pos_new != motor_pos_flip) {
            output_low(dir_flip);
            move_flip = pos_new - motor_pos_flip;
            pos_inc_flip = 1;
        } else return;

        for (int j = 0; j <= velocidade; j++) {
            total_acc_step_flip += StepbyF_flip[j];
        }
        
        if (move_flip > 2 * total_acc_step_flip) {
            midpt_flip = total_acc_step_flip;
            step_down_flip = move_flip - total_acc_step_flip;
        } else {
            midpt_flip = (move_flip - 1) >> 1;
            step_down_flip = midpt_flip;
        }
        step_no_flip = 0;
        step_acumulado_flip = 0;
        atual_frequencia_flip = 0;
        ramp_sts_flip = ramp_up; // start ramp state-machine
        run_flg_flip = TRUE;
        output_low(enable_flip);
        setup_timer_3(T3_INTERNAL | T3_DIV_BY_8);
        set_timer3(65535 - Ts_flip[0]);
        enable_interrupts(INT_TIMER3);
    }
}

void proximo_valor_subida_flip() {
    if (atual_frequencia_flip == 0) {
        if (step_no_flip == StepbyF_flip[atual_frequencia_flip]) {
            step_acumulado_flip += StepbyF_flip[atual_frequencia_flip] + StepbyF_flip[atual_frequencia_flip + 1];
            atual_frequencia_flip++;
            set_timer3(65535 - Ts_flip[atual_frequencia_flip]);
        } else {
            set_timer3(65535 - Ts_flip[atual_frequencia_flip]);
        }
    } else if (atual_frequencia_flip == vel_flip) {
        set_timer3(65535 - Ts_flip[atual_frequencia_flip]);
    } else {
        if (step_no_flip == step_acumulado_flip) {
            atual_frequencia_flip++;
            step_acumulado_flip += StepbyF_flip[atual_frequencia_flip];
            set_timer3(65535 - Ts_flip[atual_frequencia_flip]);
        } else {
            set_timer3(65535 - Ts_flip[atual_frequencia_flip]);
        }
        break;
    }
}

void proximo_valor_descida_flip() {
    if (atual_frequencia_flip == 0) {
        set_timer3(65535 - Ts_flip[atual_frequencia_flip]);
    }
    else if (atual_frequencia_flip == vel_flip) {
        if (step_no_flip == (step_down_flip + StepbyF_flip[atual_frequencia_flip])) {
            step_acumulado_flip = step_down_flip + StepbyF_flip[atual_frequencia_flip] + StepbyF_flip[atual_frequencia_flip - 1];
            atual_frequencia_flip--;
            set_timer3(65535 - Ts_flip[atual_frequencia_flip]);
        } else {
            set_timer3(65535 - Ts_flip[atual_frequencia_flip]);
        }
    } else {
        if (step_no_flip == step_acumulado_flip) {
            atual_frequencia_flip--;
            step_acumulado_flip += StepbyF_flip[atual_frequencia_flip];
            set_timer3(65535 - Ts_flip[atual_frequencia_flip]);
        } else {
            set_timer3(65535 - Ts_flip[atual_frequencia_flip]);
        }
    }
}

void movimenta_eixo_flip() {

    switch (ramp_sts_flip) {
        case ramp_up: // accel
            output_toggle(step_flip);
            rest_flip = ~rest_flip;
            proximo_valor_subida_flip();
            if (step_no_flip == midpt_flip) { // midpoint: decel
                if (move_flip > 2 * total_acc_step_flip)
                    ramp_sts_flip = ramp_max;
                else
                    ramp_sts_flip = ramp_down;
            }
            break;

        case ramp_down: // decel
            output_toggle(step_flip);
            rest_flip = ~rest_flip;
            proximo_valor_descida_flip();
            if (step_no_flip == move_flip)
                ramp_sts_flip = ramp_last;
            break;

        case ramp_max: // constant speed
            output_toggle(step_flip);
            rest_flip = ~rest_flip;
            proximo_valor_subida_flip();
            if (step_no_flip == step_down_flip) // start decel
                ramp_sts_flip = ramp_down;
            break;

        default: // last step: cleanup
            ramp_sts_flip = ramp_idle;
            disable_interrupts(INT_TIMER3);
            run_flg_flip = FALSE; // move_z complete
            break;
    } // switch (ramp_sts_z)
    if (ramp_sts_flip != ramp_idle) {
        if (rest_flip) {
            motor_pos_flip += pos_inc_flip;
            ++step_no_flip;
        }
    }
}

void umpasso_flip(int16 descanco, short dir) {
    output_low(enable_flip);
    if (dir) {
        output_high(dir_flip);
        motor_pos_flip--;
    } else {
        output_low(dir_flip);
        motor_pos_flip++;
    }
    output_high(step_flip);
    delay_us(descanco);
    output_low(step_flip);
    delay_us(descanco);

}

void zerar_flip() {

    while (le_Input(s_limite_flip) == 1) {
        delay_us(200);
        umpasso_flip(600, FALSE);//600
    }
    while (le_Input(s_limite_flip) == 0) {
        delay_us(200);
        umpasso_flip(900, TRUE);//900
    }
    while (le_Input(s_limite_flip) == 1) {
        delay_us(200);
        umpasso_flip(1000, FALSE);//1000
    }
   // output_high(enable_z);
    motor_pos_flip = 0;
}

void medir_flip() {
    while (le_Input(i_limite_flip) == 0) {
        umpasso_flip(900, FALSE);
        delay_us(200);
    }
    while (le_Input(i_limite_flip) == 1) {
        umpasso_flip(900, TRUE);
        delay_us(200);
    }
    max_posicao_flip = motor_pos_flip;
    output_high(enable_flip);
    printf(lcd_putc, "%04Lu", max_posicao_flip);
}
// </editor-fold>