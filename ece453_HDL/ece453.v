

/*

  Author:  Joe Krachey
  Date:  07/12/2018

*/


module ece453(
  // signals to connect to an Avalon clock source interface
  clk,
  reset,
  // signals to connect to an Avalon-MM slave interface
  slave_address,
  slave_read,
  slave_write,
  slave_readdata,
  slave_writedata,
  slave_byteenable,
  // Non-Avalon Interface IO
  gpio_inputs,
  gpio_outputs,
  irq_out
);

  //*******************************************************************
  // Module Interface
  //*******************************************************************
  input clk;
  input reset;
  
  // slave interface
  input [4:0] slave_address;
  input slave_read;
  input slave_write;
  output wire [31:0] slave_readdata;
  input [31:0] slave_writedata;
  input [3:0] slave_byteenable;


  input [31:0] gpio_inputs;
  output [31:0] gpio_outputs;
  output wire irq_out;

  //`include "ece453.vh"
  
  localparam	DEV_ID_ADDR	       = 5'b0000;      // 0xFF200000
  localparam	GPIO_IN_ADDR	    = 5'b0001;      // 0xFF200004
  localparam	GPIO_OUT_ADDR	    = 5'b0010;      // 0xFF200008
  localparam  CONTROL_ADDR        = 5'b0011;      // 0xFF20000C
  localparam  STEP_COUNT_ADDR     = 5'b0100;      // 0xFF200010
  localparam  STEP_PERIOD_ADDR    = 5'b0101;      // 0xFF200014
  localparam	IM_ADDR	          = 5'b0110;      // 0xFF200018
  localparam	IRQ_ADDR	          = 5'b0111;      // 0xFF20001C
  localparam  CONTROL_2_ADDR      = 5'b1000;      // 0xFF200020
  localparam  STEP_COUNT_2_ADDR   = 5'b1001;      // 0xFF200024
  localparam  STEP_PERIOD_2_ADDR  = 5'b1010;      // 0xFF200028
  localparam  E_MAGNET_ADDR       = 5'B1011;      // 0XFF20002C
  localparam  LED_ADDR            = 5'B1100;      // 0XFF200030
  localparam  BUTTON_ADDR         = 5'b1101;      // 0xff200034
  localparam  SWITCH_ADDR         = 5'b1110;      // 0XFF200038
  localparam  IRQ_STAT_ADDR       = 5'b1111;      // 0xff20003c   
  
  //*******************************************************************
  // Register Bit Definitions
  //*******************************************************************
  localparam CONTROL_RESET_N_BIT_NUM	= 0;
	localparam CONTROL_DIR_BIT_NUM		  = 1;
	localparam CONTROL_EN_N_BIT_NUM		  = 2;
	localparam CONTROL_SLEEP_N_BIT_NUM	= 3;
	localparam CONTROL_MODE_BIT_NUM	    = 4;

  //*******************************************************************
  // Register Masks
  //*******************************************************************
  localparam CONTROL_RESET_N_MASK		= (32'h1 << CONTROL_RESET_N_BIT_NUM);
	localparam CONTROL_DIR_MASK		    = (32'h1 << CONTROL_DIR_BIT_NUM);
	localparam CONTROL_EN_N_MASK		  = (32'h1 << CONTROL_EN_N_BIT_NUM);
	localparam CONTROL_SLEEP_N_MASK		= (32'h1 << CONTROL_SLEEP_N_BIT_NUM);
	localparam CONTROL_MODE_MASK		  = (32'h1 << CONTROL_MODE_BIT_NUM);

	localparam	ALL_BITS      = 32'hFFFFFFFF;

  //*******************************************************************
  // Register Set
  //*******************************************************************
  reg  [31:0] dev_id_r;
  reg  [31:0] gpio_in_r;
  reg  [31:0] gpio_out_r;
  reg  [31:0] control_r;
  reg  [31:0] control_2_r;
  
  // stepper motor 1
  reg  [31:0] step_count_r;
  reg  [31:0] step_period_r, step_period_ini_r;
  reg         step_r; 
  
  // stepper motor 2
  reg  [31:0] step_count_2_r;
  reg  [31:0] step_period_2_r, step_period_ini_2_r;
  reg         step_2_r;
  
  // stepper motor 1 interrupt
  reg  [31:0] im_r;
  reg  [31:0] irq_r;
  
  // electromagnet
  reg  e_magnet_r;
  
  // Button LEDS
  reg  [3:0] led_r;
  
  // push button value storage
  reg [7:0] button_r;
  
  
  // min/max switches value storage
  reg [3:0] switches_r;
  
  // status register to identify which motor the irq represents
  reg [31:0] irq_stat_r;
  

   //*******************************************************************
  // Wires/Reg
  //*******************************************************************
  wire [31:0] gpio_in;
  wire [31:0] gpio_out; 
  wire [31:0] control; 
  wire [31:0] control_2;
  
  // stepper motor 1
  wire [31:0] step_count_ini, step_count; 
  wire [31:0] step_period_ini, step_period; 
  
  // stepper motor 2
  wire [31:0] step_count_ini_2, step_count_2; 
  wire [31:0] step_period_ini_2, step_period_2; 
  
  // stepper motor 1 interrupt
  wire [31:0] im; 
  wire [31:0] irq; 
  wire [31:0] irq_2;
  
  // electro magnet
  wire e_magnet;
  
  // LED
  wire [3:0] led;
  
  //  min/max switches & push button value wire
  wire [7:0] button;
  
  //  min/max switches value wire
  wire [3:0] switches;
  
  //  irq status 
  wire [31:0] irq_stat;
  

  //*******************************************************************
  // Register Read Assignments
  //*******************************************************************
  assign slave_readdata = 
		( (slave_address == DEV_ID_ADDR ) && slave_read )      ? dev_id_r :
		( (slave_address == GPIO_IN_ADDR ) && slave_read )     ? gpio_in_r :
 		( (slave_address == GPIO_OUT_ADDR ) && slave_read )    ? gpio_out_r : 
		
 		( (slave_address == CONTROL_ADDR ) && slave_read )     ? control_r : 
 		( (slave_address == STEP_COUNT_ADDR ) && slave_read )  ? step_count_r : 
 		( (slave_address == STEP_PERIOD_ADDR ) && slave_read ) ? step_period_ini_r :
		
 		( (slave_address == CONTROL_2_ADDR ) && slave_read )     ? control_2_r : 
 		( (slave_address == STEP_COUNT_2_ADDR ) && slave_read )  ? step_count_2_r : 
 		( (slave_address == STEP_PERIOD_2_ADDR ) && slave_read ) ? step_period_ini_2_r :
         		
 		( (slave_address == IM_ADDR ) && slave_read )          ? im_r :
 		( (slave_address == IRQ_ADDR ) && slave_read )         ? irq_r : 
		
		( (slave_address == E_MAGNET_ADDR) && slave_read )     ? e_magnet_r :
		
		( (slave_address == LED_ADDR)    && slave_read )        ? led_r : 
		( (slave_address == BUTTON_ADDR)    && slave_read )     ? button_r : 
		( (slave_address == SWITCH_ADDR)    && slave_read )     ? switches_r : 
		
		( (slave_address == IRQ_STAT_ADDR) && slave_read )     ?  irq_stat_r : 32'h00000000;
		
		
  
  //*******************************************************************
  // Output Assignments
  //*******************************************************************
     
  // Output signals to external devices.
  assign gpio_outputs = {step_r, control_r[3:0], step_2_r, control_2_r[3:0], e_magnet_r, led_r[3:0], gpio_out_r[16:0]};  // Implemented according to page 4

  // Input signals for registers
  assign gpio_in            = ( (slave_address == GPIO_IN_ADDR )      && slave_write ) ? slave_writedata : gpio_in_r;
  assign control            = ( (slave_address == CONTROL_ADDR )      && slave_write ) ? slave_writedata :
                              ( step_count_r == 32'h0 && control[4]) ? {27'h0, control_r[4:3], 1'b1, control_r[1:0]} : control_r;
  
  assign mode               = control[4];
  assign en_n               = control[2]; 

  
  assign im                 = ( (slave_address == IM_ADDR )           && slave_write ) ? slave_writedata : im_r;

  assign irq                = ( (slave_address == IRQ_ADDR )          && slave_write && slave_writedata[0] == 1'b1) ? 1'b0 : 
  
									// Irq indicates either or both motor 1 and motor 2 finishing a countdown
			                  ( step_count_r == 1 && ( step_period_r == 0 && control_r[0] && mode && !en_n )) ? 1'b1 :
								   
									( step_count_2_r == 1 && ( step_period_2_r == 0 
									 && control_2_r[0] && control_2_r[4] && !control_2_r[2] )) ? 1'b1 : irq_r ;
									
									
  assign irq_out            = ( im_r == 1 ) ? irq_r : 1'b0;
				  

				  
  // stepper motor 1
  assign step_count         = ( (slave_address == STEP_COUNT_ADDR )   && slave_write && en_n ) ? slave_writedata : 
                              ( step_period_r == 0 && control_r[0] && mode && !en_n ) ? step_count_r - 1 : step_count_r;

  assign step_period_ini    = ( (slave_address == STEP_PERIOD_ADDR )  && slave_write ) ? slave_writedata : step_period_ini_r;

  assign step_period        = ( step_period_r == step_period_ini_r || ~control[0] ) ? 32'h0 : (step_period_r + 1);
  
  assign step               = ( step_period_r == step_period_ini_r / 2 ) ? ~step_r : step_r;
  
  
  // stepper motor 2
  assign control_2          = ( (slave_address == CONTROL_2_ADDR )      && slave_write ) ? slave_writedata :
                              ( step_count_2_r == 32'h0 && control_2[4]) ? {27'h0, control_2_r[4:3], 1'b1, control_2_r[1:0]} : control_2_r;
									
  assign mode_2             = control_2[4];
  assign en_n_2             = control_2[2]; 								
										
  assign step_count_2       = ( (slave_address == STEP_COUNT_2_ADDR )   && slave_write && en_n ) ? slave_writedata : 
                              ( step_period_2_r == 0 && control_2_r[0] && mode_2 && !en_n_2 ) ? step_count_2_r - 1 : step_count_2_r;

  assign step_period_ini_2  = ( (slave_address == STEP_PERIOD_2_ADDR )  && slave_write ) ? slave_writedata : step_period_ini_2_r;

  assign step_period_2      = ( step_period_2_r == step_period_ini_2_r || ~control_2[0] ) ? 32'h0 : (step_period_2_r + 1);

  // assign irq_out            = ( (im_r == 32'h00000001 && irq_r == 32'h00000001) ) ? 1'b1 : 1'b0;
  //assign gpio_out[31:21]    = 11'h000;
  assign step_2             = ( step_period_2_r == step_period_ini_2_r / 2 ) ? ~step_2_r : step_2_r;

  
  // electromagnet control
  assign e_magnet           = ( (slave_address == E_MAGNET_ADDR )      && slave_write ) ? slave_writedata : e_magnet_r;
  
  // led 0 control
  assign led                = ( (slave_address == LED_ADDR )      && slave_write ) ? slave_writedata : led_r;
  
  // push button and limit switch read
  assign button             =  gpio_inputs[3:0];
  
  // limit switch read
  assign switches           =  gpio_inputs[7:4];
  
  // logic for irq stat register
   
  assign x_motor_countdown_done =  // x-axis motor stopping countdown 
                               ( step_count_r == 1 && ( step_period_r == 0 && control_r[0] && mode && !en_n ));
										 
  assign y_motor_countdown_done =  // y-axis motor stopping countdown 
                               ( step_count_2_r == 1 && ( step_period_2_r == 0 
										   && control_2_r[0] && control_2_r[4] && !control_2_r[2] ));
 
 
  assign irq_stat           =  // user clearing irq status from software
									    ( (slave_address == IRQ_STAT_ADDR) && slave_write ) ? slave_writedata : 
  
										 // when either x/y motor gets done count-down stepping 
										 // update the irq status register
										( x_motor_countdown_done | y_motor_countdown_done ) ? {30'h0, y_motor_countdown_done, x_motor_countdown_done} : irq_stat_r;
   

  //*******************************************************************
  // Registers
  //*******************************************************************
  always @ (posedge clk or posedge reset)
  begin
    if (reset == 1) 
	begin
	  dev_id_r            <= 32'hECE45302;
	  gpio_in_r           <= 32'h00000000;
	  gpio_out_r          <= 32'h00000000;
	  control_r           <= 32'h00000000;
	  step_count_r        <= 32'h00000000;
	  step_period_r       <= 32'h00000000;
     step_period_ini_r   <= 32'h00000000;
     step_r              <= 1'b0;
	  im_r                <= 32'h00000000;
	  irq_r               <= 32'h00000000;
     control_2_r         <= 32'h00000000;
	  step_count_2_r      <= 32'h00000000;
	  step_period_2_r     <= 32'h00000000;
     step_period_ini_2_r <= 32'h00000000;
     step_2_r            <= 1'b0;
	  e_magnet_r          <= 32'h00000000;
	  led_r               <= 4'h0;
	  button_r            <= 8'h0;
	  switches_r          <= 4'h0;
	  irq_stat_r          <= 2'b0;
	  
	end
  
    else
	begin
	  dev_id_r           <= 32'hECE45302;
	  gpio_in_r          <= gpio_in;
	  gpio_out_r         <= gpio_out;
	  
	  // stepper motor 1
	  control_r          <= control;
	  step_period_r      <= step_period;
     step_period_ini_r  <= step_period_ini;
     step_count_r       <= step_count;
     step_r             <= step;
		  
	  // stepper motor 2
     control_2_r           <= control_2;
	  step_count_2_r        <= step_count_2;
	  step_period_2_r       <= step_period_2;
     step_period_ini_2_r   <= step_period_ini_2;
     step_2_r              <= step_2;
	 
	  irq_r              <= irq;
	  im_r               <= im;
	  
	  
	  // electromagnet
	  e_magnet_r         <= e_magnet;
	  
	  // led 0
	  led_r              <=  led;
	  
     // push button and limit switch
	  button_r           <=  button;
	  
	  
	  // limit switch
	  switches_r         <= switches;
	  
	  
	  // interrupt status
	  irq_stat_r         <= irq_stat;
	  
	end
  end
  
  //*******************************************************************
  // Instantiate instances of 7 Segment Decoder
  //*******************************************************************
  hex_to_7_seg h_2_7_decoder_0(.x(gpio_in[3:0]),  .z(gpio_out[6:0]));
  hex_to_7_seg h_2_7_decoder_1(.x(gpio_in[7:4]),  .z(gpio_out[13:7]));
  hex_to_7_seg h_2_7_decoder_2(.x(gpio_in[11:8]), .z(gpio_out[20:14]));
  
endmodule

  
  //*****************************************************************************
  //  
  //*****************************************************************************
  module hex_to_7_seg(
    input  [3:0]x,
    output reg [6:0]z
    );

    always @(*)      
      case (x)
		4'b0000 :      		//Hexadecimal 0
		  z = 7'h40;
		4'b0001 :    		//Hexadecimal 1
		  z = 7'h79  ;
		4'b0010 :  		// Hexadecimal 2
		  z = 7'h24 ; 
		4'b0011 : 		// Hexadecimal 3
		  z = 7'h30 ;
		4'b0100 :		// Hexadecimal 4
		  z = 7'h19 ;
		4'b0101 :		// Hexadecimal 5
		  z = 7'h12 ;  
		4'b0110 :		// Hexadecimal 6
		  z = 7'h02 ;
		4'b0111 :		// Hexadecimal 7
		  z = 7'h78;
		4'b1000 :     		//Hexadecimal 8
		  z = 7'h00;
		4'b1001 :       	//Hexadecimal 9
		  z = 7'h18 ;
		4'b1010 :  		// Hexadecimal A
		  z = 7'h08 ; 
		4'b1011 : 		// Hexadecimal B
		  z = 7'h03;
		4'b1100 :		// Hexadecimal C
		  z = 7'h86 ;
		4'b1101 :		// Hexadecimal D
		  z = 7'h21 ;
		4'b1110 :		// Hexadecimal E
		  z = 7'h06 ;
		4'b1111 :		// Hexadecimal F
		  z = 7'h0e ;
	  endcase
  endmodule