




void  write ( char  dado)
{
	

	delay_us(30);
	escreve_PCA9555(0X00,0X02,0X00,dado);								//escreve_pcf8574(0x00,dado);
	delay_us(30);
	output_high (E);
	delay_us(30);
	output_low  (E) ;
	delay_us(30);



}


void  displayprog (int valor)
{
	output_low (RS);
	write      (valor);
}



void limpa_display (void)
{
 	displayprog (0x1);
	delay_ms(5);

}


void inicializa_display(void)
{

	escreve_PCA9555(0X00,0X06,0Xff,0x00);// programa lsb como saida e msb  como entrada
	escreve_PCA9555(0X00,0X02,0X00,0xff);
//    escreve_pcf8574(0x00,0Xff); //;output_b(0xff);				//	porta_display (0XFF);
	output_low(E);
	output_high(RS);
	delay_ms(15);
	displayprog(0x38);      // 2 linha / 5x7 /8 bit
	delay_ms(15);
	displayprog(0x0c);		// display aceso s/ cursor
	delay_ms(15);
	displayprog(0x06);      // escreve deslocando o cursor para direita
	delay_ms(15);
	lcdcoluna = 1;
	lcdlinha = 1;
}


void	posiciona_cursor (int linha,int coluna)
{

	lcdcoluna = coluna;
	lcdlinha  = linha;

	int	x;
	if (linha == 1)	x=(0x00 + coluna) - 1;
	if (linha == 2) x=(0x40 + coluna) - 1; 
    if (linha == 3) x=(0x14 + coluna) - 1;
	if (linha == 4) x=(0x54 + coluna) - 1;
	x =x | 0x80;
	displayprog (x);
	delay_us(100);
}


void display	(char  c)
{

	output_high (RS);
	write (c);

}



void lcd_putc( char c) {
	// \n nova linha muda o cursor para uma linha abaixo
    // \r retorno
    // \f limpa display


   switch (c) {
     case '\f'   : limpa_display();
                   lcdlinha = 1;
				   lcdcoluna= 1;
                   break;

     case '\n'   : posiciona_cursor(++lcdlinha,lcdcoluna); 
			       break;

     case '\r'   : posiciona_cursor(lcdlinha,1); 
                   break;

     default     : display(c);  
                   break;
   }
}



void Show_String(char matriz[])
{
	int result;
	int	a;
	char x1[21];

	strcpy (x1,matriz);
	result = strlen(x1);
	for (a=0;a < result;a++)
  {
	display(x1[a]);
  }
}
