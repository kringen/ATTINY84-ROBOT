#define output_low(port,pin) port &= ~(1<<pin)
#define output_high(port,pin) port |= (1<<pin)
#define set_input(portdir,pin) portdir &= ~(1<<pin)
#define set_output(portdir,pin) portdir |= (1<<pin)
// Left Motor Definitions
#define mRight1_Reg DDRA
#define mRight2_Reg DDRA
#define mRight1_Port PORTA
#define mRight2_Port PORTA
#define mRight1_Bit PA5
#define mRight2_Bit PA6
// Right Motor Definitions
#define mLeft1_Reg DDRA
#define mLeft2_Reg DDRB
#define mLeft1_Port PORTA
#define mLeft2_Port PORTB
#define mLeft1_Bit PA7
#define mLeft2_Bit PB2

#define rightIR 1
#define leftIR 2
