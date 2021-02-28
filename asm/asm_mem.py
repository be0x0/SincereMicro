#!/usr/bin/python

# New assembly- compiles to bytecode loaded into verilog 

import sys
import re

def instArgC(aInst):
    lookup = {
        "nop" : 0,
        "mov" : 2,
        "jmp" : 1,
        "slp" : 1,
        "slx" : 1,
        "add" : 1,
        "sub" : 1,
        "mul" : 1,
        "not" : 0,
        "dgt" : 1,
        "dst" : 2,
        "teq" : 2,
        "tgt" : 2,
        "tlt" : 2,
        "tcp" : 2,
        "gen" : 3
    }
    return lookup.get(aInst, 9)

def regToAddr(aReg):
    lookup = {
        "null" : 0x800,
        "acc" : 0x801,
        "dat" : 0x802,
        "p0" : 0x803,
        "p1" : 0x804,
        "x0" : 0x805,
        "x1" : 0x806,
        "x2" : 0x807,
        "x3" : 0x808
    }
    return lookup.get(aReg, aReg)

def labelToAddr(aLabel):
    return labels.get(aLabel)

def condToHex(aCond):
    lookup = {
        "0" : "00",
        "-" : "01" ,
        "+" : "10",
        "@" : "11"
    }
    return lookup.get(aCond, "00")

def instToHex(aInst):
    lookup = {
        "nop" : "0000",
        "mov" : "0001",
        "jmp" : "0010",
        "slp" : "0011",
        "slx" : "0100",
        "add" : "0101",
        "sub" : "0110",
        "mul" : "0111",
        "not" : "1000",
        "dgt" : "1001",
        "dst" : "1010",
        "teq" : "1011",
        "tgt" : "1100",
        "tlt" : "1101",
        "tcp" : "1110",
        "gen" : "1111"
    }
    return lookup.get(aInst, "0000")

def argToHex(aArg):
    ## If it's a register, leave it alone (TODO)
    return "12'd" + str(aArg)

'''
# Check arguments
if (len(sys.argv) != 2):
    print("Syntax: asm.py <input file> <output file>")
'''
lines = []
mem = []

# Open input file
with open(sys.argv[1]) as infile:
    for line in infile:
        line = line.strip()
        lines.append(line)

# Remove comments (TODO)

# Parse labels
labels = {}
addr = 0
for line in lines:
    line = line.strip()
    label = re.findall("\w{1,25}(?=:)", line)  
    if(len(label) > 0):
        labels[label[0]] = addr
    addr+=1

# Remove labels to continue parsing
tmp_lines = []
for line in lines:
    line = re.sub("\w{1,25}:","", line, count=1)
    line = line.strip()
    tmp_lines.append(line)
lines = tmp_lines


addr = 0
# Split into lists

with open(sys.argv[2], 'rw') as ofile:
    for line in lines:
        # Check for and remove conditional
        cond = re.findall('^(@|\+|-)', line)
        cond = cond[0] if (cond != []) else 0
        line = re.sub('^(@|\+|-)', '', line, count=1)

        # Split line conditional, instruction, and arguments
        tmp = line.split()

        # replace missing instructions with nop
        if (tmp == []):
            tmp = ["nop"]

        # Initialize dictionary
        argDict = { "cond" : cond,
            "inst" : tmp[0],
            "a1" : 0,
            "a2" : 0,
            "a3" : 0,
        }

        # check number of args
        if((len(tmp)-1) != instArgC(tmp[0])):
            print("Incorrect arg count!")
            quit()

        # Add arguments
        if(len(tmp) >= 2):
            argDict["a1"] = tmp[1]
        if(len(tmp) >= 3):
            argDict["a2"] = tmp[2]
        if(len(tmp) >= 4):
            argDict["a3"] = tmp[3]

        # Replace registers with addresses
        argDict["a1"] = regToAddr(argDict["a1"])
        argDict["a2"] = regToAddr(argDict["a2"])
        argDict["a3"] = regToAddr(argDict["a3"])

        # Replace labels with addresses
        if(argDict["inst"] == "jmp"):
            argDict["a1"] = labelToAddr(argDict["a1"])

        addrStr = str(addr)
        cond = condToHex(argDict["cond"])
        inst = instToHex(argDict["inst"])
        a1 = argToHex(argDict["a1"])
        a2 = argToHex(argDict["a2"])
        a3 = argToHex(argDict["a3"])

        # Example output
        #mem[0] = {2'h0,4'h1,12'd150,12'h801,12'b0}; //Set acc to 150
        print("mem[" + addrStr + "] = {" + cond + "," + inst + "," + a1 + "," \
            + a2 + "," + a3 + "};")
        
        mem.append(argDict)

        addr = addr + 1



'''
# Check for missing instruction
addr=0
for line in mem:
    if len(line) < 2:
        print("Missing instruction in line " + addr)
    addr += 1

# Check for incorrect number of arguments
##TODO
for line in mem:
    inst = line[1]
    if((inst == "nop") | (inst == "not")):
        print(inst)

for line in mem:
    inst = line[1]

print(mem)
print(labels)

'''
