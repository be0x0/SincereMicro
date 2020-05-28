An attempt to create a hardware design for SHENZHEN IO's MCxxxx family of microcontrollers.
Current state: unstarted.

#MCxxxx Specification

##Basic Instructions:
`nop`
`mov R/I R`
`jmp L`
`slp R/I`
`slx P`

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

##Registers:
`acc`
`dat`
`p0, p1`
`x0, x1, x2, x3`

#Xbus Specification
