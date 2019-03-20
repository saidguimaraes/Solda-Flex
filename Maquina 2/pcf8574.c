short int ack;
int	lcdcoluna = 1;
int	lcdlinha  = 1;

void escreve_pcf8574(int dispositivo,int data) {
   i2c_start();
   ack=i2c_write(0x40 |(dispositivo << 1));
   ack=i2c_write(data);
   i2c_stop();
   ack=!ack;
}

int le_pcf8574(int dispositivo) {
    int data;
    i2c_start();
    i2c_write(0x41 |(dispositivo << 1));
    data=i2c_read(0);
    i2c_stop();
    ack=!ack;
    return(data);
}

int le_pcf8574A(int dispositivo) {
    int data;
    i2c_start();
    i2c_write(0x71 |(dispositivo << 1));
    data=i2c_read(0);
    i2c_stop();
    ack=!ack;
	return(data);
}

