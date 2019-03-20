// <editor-fold defaultstate="collapsed" desc="Valores que devem ser inseridos">
float stepbyrev_z = 200;
float driver_u_step_z = 1; // caso o driver esteja em 400
float Leadscrew_z = 9; //redutor de voltas do motor
float Leadscrew_Pich_z = 150; //esse valor deve ser em mm/revoluï¿½ï¿½o
float Vmax_z = 600; //esse valor deve ser em mm por segundo
float Amax_z = 300; //esse valor deve ser em mm por segundoï
// </editor-fold>

// <editor-fold defaultstate="collapsed" desc="Valores calculo rampa">
float MMbyStep_z = 0;
int8 StepinAcc_z = 20;
float Fmax_z = 0;
int32 Ts_z[20];
int32 StepbyF_z[20];
int16 total_acc_step_z = 0;
// </editor-fold>

// <editor-fold defaultstate="collapsed" desc="Flags e Controles de Movimento">
signed int8 pos_inc_z = 0;
int8 ramp_sts_z = ramp_idle;
short run_flg_z = FALSE;
short rest_z = false;
int16 step_no_z = 0;
int16 step_down_z = 0;
int16 move_z = 0;
int16 midpt_z = 0;
int32 step_acumulado_z = 0;
int atual_frequencia_z = 0;
int vel_z = 19;
int16 max_posicao_z = 0;
// </editor-fold>

// <editor-fold defaultstate="collapsed" desc="Pinos Motor">
#DEFINE     i_limite_z            13
#DEFINE     s_limite_z            14

// </editor-fold>

// <editor-fold defaultstate="collapsed" desc="Inicializa Motor">
void init_axis_z() {
    set_tris_a(0x00);
    output_high(step_z);
    output_high(enable_z);
    output_high(dir_z);

    MMbyStep_z = Leadscrew_Pich_z / (stepbyrev_z * driver_u_step_z * Leadscrew_z);
    Fmax_z = Vmax_z / MMbyStep_z; //Valor de ferequencia adiquirido em hz

    float den = Amax_z*StepinAcc_z;
    float num = Vmax_z * 1000000;
    float TbyF = num / den; //tempo em us

    int i = 0;
    for (i = 1; i <= StepinAcc_z; i++) {
        Ts_z[i - 1] = (1000000 * StepinAcc_z) / (i * Fmax_z);
        StepbyF_z[i - 1] = 2 * TbyF / Ts_z[i - 1];
        total_acc_step_z += StepbyF_z[i - 1];
        Ts_z[i - 1] = Ts_z[i - 1] / (8 * 0.2 * 2); //Tempo/(prescale*ciclodemaquina*metadedociclo)
    }
}
// </editor-fold>

// <editor-fold defaultstate="collapsed" desc="Movimento Motor">
void motor_stop_z() {
    step_no_z = step_down_z;
    ramp_sts_z = ramp_down;
}

void motor_disable_z() {
    output_high(enable_z);
    disable_interrupts(INT_TIMER3);
}

void motor_run_z(int32 pos_new, int velocidade) { // set up to drive motor to pos_new (absolute step#)
    vel_z = velocidade;
    total_acc_step_z = 0;

    if (!run_flg_flip) {
        flgMove = TRUE;
        if (pos_new < motor_pos_z) // get dir_yection & #steps
        {
            output_low(dir_z);
            move_z = motor_pos_z - pos_new;
            pos_inc_z = -1;
        } else if (pos_new != motor_pos_z) {
            output_high(dir_z);
            move_z = pos_new - motor_pos_z;
            pos_inc_z = 1;
        } else return;

        for (int j = 0; j <= velocidade; j++) {
            total_acc_step_z += StepbyF_z[j];
        }

        if (move_z > 2 * total_acc_step_z) {
            midpt_z = total_acc_step_z;
            step_down_z = move_z - total_acc_step_z;
        } else {
            midpt_z = (move_z - 1) >> 1;
            step_down_z = midpt_z;
        }
        step_no_z = 0;
        step_acumulado_z = 0;
        atual_frequencia_z = 0;
        ramp_sts_z = ramp_up; // start ramp state-machine
        run_flg_z = TRUE;
        output_low(enable_z);
        setup_timer_3(T3_INTERNAL | T3_DIV_BY_8);
        set_timer3(65535 - Ts_z[0]);
        enable_interrupts(INT_TIMER3);
    }
}

void proximo_valor_subida_z() {
    if (atual_frequencia_z == 0) {
        if (step_no_z == StepbyF_z[atual_frequencia_z]) {
            step_acumulado_z += StepbyF_z[atual_frequencia_z] + StepbyF_z[atual_frequencia_z + 1];
            atual_frequencia_z++;
            set_timer3(65535 - Ts_z[atual_frequencia_z]);
        } else {
            set_timer3(65535 - Ts_z[atual_frequencia_z]);
        }
    } else if (atual_frequencia_z == vel_z) {
        set_timer3(65535 - Ts_z[atual_frequencia_z]);
    } else {
        if (step_no_z == step_acumulado_z) {
            atual_frequencia_z++;
            step_acumulado_z += StepbyF_z[atual_frequencia_z];
            set_timer3(65535 - Ts_z[atual_frequencia_z]);
        } else {
            set_timer3(65535 - Ts_z[atual_frequencia_z]);
        }
        break;
    }
}

void proximo_valor_descida_z() {
    if (atual_frequencia_z == 0) {
        set_timer3(65535 - Ts_z[atual_frequencia_z]);
    }
    else if (atual_frequencia_z == vel_z) {
        if (step_no_z == (step_down_z + StepbyF_z[atual_frequencia_z])) {
            step_acumulado_z = step_down_z + StepbyF_z[atual_frequencia_z] + StepbyF_z[atual_frequencia_z - 1];
            atual_frequencia_z--;
            set_timer3(65535 - Ts_z[atual_frequencia_z]);
        } else {
            set_timer3(65535 - Ts_z[atual_frequencia_z]);
        }
    } else {
        if (step_no_z == step_acumulado_z) {
            atual_frequencia_z--;
            step_acumulado_z += StepbyF_z[atual_frequencia_z];
            set_timer3(65535 - Ts_z[atual_frequencia_z]);
        } else {
            set_timer3(65535 - Ts_z[atual_frequencia_z]);
        }
    }
}

void movimenta_eixo_z() {

    switch (ramp_sts_z) {
        case ramp_up: // accel
            output_toggle(step_z);
            rest_z = ~rest_z;
            proximo_valor_subida_z();
            if (step_no_z == midpt_z) { // midpoint: decel
                if (move_z > 2 * total_acc_step_z)
                    ramp_sts_z = ramp_max;
                else
                    ramp_sts_z = ramp_down;
            }
            break;

        case ramp_down: // decel
            output_toggle(step_z);
            rest_z = ~rest_z;
            proximo_valor_descida_z();
            if (step_no_z == move_z)
                ramp_sts_z = ramp_last;
            break;

        case ramp_max: // constant speed
            output_toggle(step_z);
            rest_z = ~rest_z;
            proximo_valor_subida_z();
            if (step_no_z == step_down_z) // start decel
                ramp_sts_z = ramp_down;
            break;

        default: // last step: cleanup
            ramp_sts_z = ramp_idle;
            disable_interrupts(INT_TIMER3);
            run_flg_z = FALSE; // move_z complete
            break;
    } // switch (ramp_sts_z)
    if (ramp_sts_z != ramp_idle) {
        if (rest_z) {
            motor_pos_z += pos_inc_z;
            ++step_no_z;
        }
    }
}

void umpasso_z(int16 descanco, short dir) {
    output_low(enable_z);
    if (dir) {
        output_high(dir_z);
        motor_pos_z--;
    } else {
        output_low(dir_z);
        motor_pos_z++;
    }
    output_high(step_z);
    delay_us(descanco);
    output_low(step_z);
    delay_us(descanco);

}

void zerar_z() {

    while (le_Input(s_limite_z) == 1) {
        delay_us(200);
        umpasso_z(600, FALSE);//600
    }
    while (le_Input(s_limite_z) == 0) {
        delay_us(200);
        umpasso_z(900, TRUE);//900
    }
    while (le_Input(s_limite_z) == 1) {
        delay_us(200);
        umpasso_z(1000, FALSE);//1000
    }
   // output_high(enable_z);
    motor_pos_z = 0;
}

void medir_z() {
    while (le_Input(i_limite_z) == 0) {
        umpasso_z(900, FALSE);
        delay_us(200);
    }
    while (le_Input(i_limite_z) == 1) {
        umpasso_z(900, TRUE);
        delay_us(200);
    }
    max_posicao_z = motor_pos_z;
    output_high(enable_z);
    printf(lcd_putc, "%04Lu", max_posicao_z);
}
// </editor-fold>