An attempt to create a synthesizable verilog design for SHENZHEN IO's MCxxxx family of microcontrollers.

# Instruction format:
42 bit instructions. Arguments can be either registers or addresses. Arguments are 12 bits because numbers ranging from -999 to 999 need a minimum of 11 bits and we need a bit to say if it's a register or not.

Arguments could easily be made 11 bits by taking advantage of numbers >999 and <1024 and using them as register addresses but bits are cheap.

Conditional[2 bits] Instruction[4 bits] arg0[12 bits] arg1[12 bits] arg2 [12 bits]  
cond[41:40] inst[39:36] arg0[35:24] arg1[23:12] arg2[11:0]

Arg3 is only used in one instruction, and it's a secret instruction. Waste of 12 bits.

# Models

# MCxxxx Specification
## Instructions (16) (4 bits):
### Basic (5):
0x0 nop 		(nop)  
0x1 mov R/I R	(move 1st to 2nd)  
0x2 jmp L		(Compile L to 4b address)  
0x3 slp R/I	(sleep x time)  (TODO)  
0x4 slx P		(sleep until data on XBUS Pin)  (TODO)  
### ALU (6):
0x5 add R/I		(acc+=arg1) 
0x6 sub R/I		(acc-=arg1)  
0x7 mul R/I		(acc*=arg1)  
0x8 not			(acc=100 if acc=0, otherwise acc=0)  
0x9 dgt R/I		(acc=acc(arg1))  (TODO- putting off BCD decoder)  
0xA dst R/I R/I	(acc(arg1)=arg2)  (TODO- see above)  
### Test (4):
0xB teq R/I R/I	: Checks if arg1 == arg2  
0xC tgt R/I R/I	: Tests if arg1 > arg2  
0xD tlt R/I R/I : arg1 < arg2  
0xE tcp R/I R/I : + en if arg1 >, -en if arg1<, = disabled  
### Secret (1):  
0xF gen P R/I R/I (generates pulse)  

## Registers:
TODO: dereferencing.  
`null` [12b] [0x000] (TODO)  
`acc` [11b]  
`dat` [11b]  (TODO)  
`p0, p1` [7b]   (TODO)  
`x0, x1, x2, x3` [11b] (TODO)  
`PC` [4b] (Instruction pointer. Not user accessible.)  
`HIST` [14b] (Tracks which instructions have been executed. Not user accessible.)  

# Xbus Specification (from the datasheet)
XBus values are discrete data packets from -999 to 999, inclusive. XBus, however, is a synchronized protocol. Data over XBus pins is only transferred when there is both a reader attempting to read and a writer attempting to write. If a read or write is attempted without a corresponding operation on a connected device, the operation will block.

Haven't figured out a way to implement this yet. I think it would be neat to have it be a one-wire interface.
