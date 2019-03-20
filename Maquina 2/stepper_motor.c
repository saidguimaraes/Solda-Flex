#DEFINE     step_y			    pin_C2
#DEFINE     dir_y				pin_C1
#DEFINE     enable_y			pin_C0
#DEFINE     step_x 		        pin_D2
#DEFINE     dir_x				pin_D1
#DEFINE     enable_x			pin_D0
#DEFINE     step_z              pin_A5             
#DEFINE     dir_z               pin_A4
#DEFINE     enable_z            pin_A3
#DEFINE     step_flip           pin_E2
#DEFINE     dir_flip            pin_E1 
#DEFINE     enable_flip         pin_E0

long int buffer_saida;
signed int16 motor_pos_x;
signed int16 motor_pos_y;
signed int16 motor_pos_flip;
signed int16 motor_pos_z;
short int direita_flag;
short int esquerda_flag;
short int frente_flag;
short int atras_flag;
short int sobe_flag;
short int desce_flag;
short int sentido_horario_flag;
short int sentido_antihorario_flag;

void direita(void) {
    direita_flag = true;
    esquerda_flag = false;
    output_low(dir_x);
}
void esquerda(void) {
    direita_flag = false;
    esquerda_flag = true;
    output_high(dir_x);
}
void frente(void) {
    frente_flag = true;
    atras_flag = false;
    output_low(dir_y);
}
void atras(void) {
    frente_flag = false;
    atras_flag = true;
    output_high(dir_y);
}
void sentido_antihorario(void) {
    sentido_horario_flag = true;
    sentido_antihorario_flag = false;
    output_high(dir_flip);
}
void sentido_horario(void) {
    sentido_horario_flag = false;
    sentido_antihorario_flag = true;
    output_low(dir_flip);
}
void sobe(void) {
    sobe_flag = true;
    desce_flag = false;
    output_low(dir_z);
}
void desce(void) {
    sobe_flag = false;
    desce_flag = true;
    output_high(dir_z);
}

void one_step_x(void) {
    output_high(step_x);
    delay_us(10);
    output_low(step_x);
    if (esquerda_flag == true) {
        motor_pos_x++;
    } else {
        if (motor_pos_x != 0000){
            motor_pos_x--;
        }
    }
}
void one_step_y(void) {
    output_high(step_y);
    delay_us(10);
    output_low(step_y);
    if (atras_flag == true) {
        motor_pos_y++;
    } else {
        if (motor_pos_y != 0000){
            motor_pos_y--;
        }
    }
}
void one_step_flip(void) {
    output_high(step_flip);
    delay_us(10);
    output_low(step_flip);
    if (sentido_antihorario_flag == true){
        motor_pos_flip++;
    } else {
        if (motor_pos_flip > 0){
        motor_pos_flip--;
        }
    }
}
void one_step_z(void) {
    output_high(step_z);
    delay_us(10);
    output_low(step_z);
    if (desce_flag == true) {
        motor_pos_z++;
    } else {
        if (motor_pos_z != 0000){
            motor_pos_z--;
        }
    }
}

void chopper_x(void) {
    output_low(enable_x);
}
void chopper_y(void) {
    output_low(enable_y);
}
void chopper_flip(void) {
    output_low(enable_flip);
}
void chopper_z(void) {
    output_low(enable_z);
}
void stop_x(void) {
    output_low(enable_x);
}
void stop_y(void) {
    output_low(enable_y);
}
void stop_flip(void) {
    output_low(enable_flip);
}
void stop_z(void) {
    output_low(enable_z);
}