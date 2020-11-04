#!/usr/bin/python
import sys

# Import from files. 
from p5Dict import *
from p6Exec import *

# ***
# p6Driver.py
#       - Purpose:
#           This file defines dictionaries from p5Dict,
#           reads input file from arguement one,
#           checks each line for colon or non-label token being VAR command,
#           and then prints all variables as well as labels,
#           this file checks if in verbose flag is used or not,
#           then execute functions in p6Exec.py
#
# ***

# Global Values.
varTypeD = {}
varValueD = {}
labelD = {}

sBeep = {}
print(sys.argv, len(sys.argv))
# Check for too little Arguements.
if len(sys.argv) < 2:
    print ("ERROR: Invalid count of ARGS.\n")
    sys.exit(1)

# Open file for Read using latin-1 which pretty much opens anything.
file = open(sys.argv[1], "r", encoding='latin-1')

print("BEEP source code in " + sys.argv[1] + ":")

i = 0
while True:
    # Read file line by line.
    fileLine = file.readline()
    
    # Check if file is empty.
    if fileLine == "":
        break
    i += 1
    
    # rstrip new line character. 
    fileLine = fileLine.rstrip('\n')
    print("%*d, %s" %(3, i, fileLine))
    
    line = fileLine.lstrip()
    lBeep[i] = line
    
    lineTokens = line.split()
    if len(lineTokens) == 0:
        continue

    # Check for Label.
    if(lineTokens[0][-1] == ':'): 
        declareLabel(lineTokens, labelD, i)
        lineTokens = lineTokens[1:]

    # Check for Variable.
    if(lineTokens[0] == 'VAR'): 
        declareVar(lineTokens[1:], varTypeD, varValueD)

# Prints Variables.
printVariables(varTypeD, varValueD)

# Prints Labels.
printLabels(labelD)
# Closed File.
file.close()
# Print Exec Header.
print("execution begins...")

# Check for Verbose. 
if sys.argv[-1] == '-v':
    execBeep(sBeep, varValueD, varTypeD, labelD, True)
# No Verbose Statement.
else:
    execBeep(sBeep, varValueD, varTypeD, labelD)
