An attempt to create a hardware design for SHENZHEN IO's MCxxxx family of microcontrollers.


#MCxxxx Specification

##Basic Instructions:
`nop` (TODO)
`mov R/I R` (TODO)
`jmp L` (TODO)
`slp R/I` (TODO)
`slx P` (TODO)

##Arithmetic Instructions:
`add R/I`
`sub R/I`
`mul R/I`
`not `
`dgt R/I`
`dst R/I R/I`

##Test Instructions:
`teq R/I R/I`
`tgt R/I R/I`
`tlt R/I R/I`
`tcp R/I R/I`

##Secret Instructions (Spoiler):
`gen P X Y`

##Conditionals:
\+
\-
@ (Secret- activates only on first run)

##Registers:
`acc`
`dat`
`p0, p1`
`x0, x1, x2, x3`

#Xbus Specification
This is going to be hard to implement, especially on the physical layer. Will do everything else first.
