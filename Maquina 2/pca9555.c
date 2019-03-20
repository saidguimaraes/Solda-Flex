void escreve_PCA9555(int dispositivo,int comando,int data1,int data2) {
   i2c_start();
   ack=i2c_write(0x40 |(dispositivo << 1));
   ack=i2c_write(comando);
   ack=i2c_write(data2);
   ack=i2c_write(data1);
   i2c_stop();
   ack=!ack;
}  

unsigned long  int le_PCA9555(int dispositivo,int comando) {    
   unsigned long int data1 = 0x0000; 
   int data2= 0x00;
   i2c_start(); 	
   ack=i2c_write(0x40 |(dispositivo << 1)); 
   ack=i2c_write(comando);
   i2c_start();
   ack=i2c_write(0x41 |(dispositivo << 1));
   data2=i2c_read(1);            // acknoledgment
   data1=i2c_read(0) << 8;      // no  acknoledgment
   i2c_stop();
   ack=!ack;
   data1|=data2;
   return(data1);
}    