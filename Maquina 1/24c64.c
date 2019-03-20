void write_ext_eeprom(long int address,long int data) {

   disable_interrupts(GLOBAL);
   i2c_start();
   ack=i2c_write(0xa0);
   ack=i2c_write(address >> 8);
   ack=i2c_write(address);
   ack=i2c_write(data);
   i2c_stop();
   ack=!ack;
   delay_ms(5);
   enable_interrupts(GLOBAL);

}
long int read_ext_eeprom(long int address) {
   long int data;

   disable_interrupts(GLOBAL);
   i2c_start();
   i2c_write(0xa0);
   i2c_write(address >> 8);
   i2c_write(address);
   i2c_start();
   i2c_write(0xa1);
   data=i2c_read(0);
   i2c_stop();
   ack=!ack;
   delay_ms(5);
   enable_interrupts(GLOBAL);

   return(data);

}
void init_ext_eeprom() {
	int a;

    output_float(EEPROM_SCL);
    output_float(EEPROM_SDA);

	write_ext_eeprom(0x00ff,0xAA);
	if (ack == false)
	{
	limpa_display();
	posiciona_cursor(1,1);
	display("erro de escrita ");
	posiciona_cursor(2,1);
	display("   EEPROM       ");
	while(true){}
	}
	
	delay_ms(5);	

	a = read_ext_eeprom(0x00ff);
	if (a != 0xAA)
	{
	limpa_display();
	posiciona_cursor(1,1);
	display("erro de leitura  ");
	posiciona_cursor(2,1);
	display("     EEPROM      ");
	while(true){}
	}


    





}