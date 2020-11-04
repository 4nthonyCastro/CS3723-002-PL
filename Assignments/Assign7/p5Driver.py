#!/usr/bin/python
#   ***
#   ***
#       - Purpose:
#           This file imports defined functions from p5Dict,
#           reads input file from arguement one,
#           checks each line for colon or non-label token being VAR command,
#           and then prints all variables as well as labels.
#   ...
#       - Input: 
#           We start by reading input file from arguement one.
#   ...
#           Our first condition (IF-Statement) checks if our line begins with a token that ends with a colon. 
#           If this condition is true we declare each label by invoking declareLabel(...). 
#           Labels and their number line to be saved in the labelD dictionary as uppercase values..        
#   ...
#           Our second condition (IF-statement) checks if our initial non-label token is a VAR command.
#           If this condition is true we declare the variable by invoking declareVar(...).
#           Variables to be saved as uppercase values.  
#   ...
#       - Output:
#           Once program is finished we print all variables as well as labels using printVar & printLabels. 
#   ***
import re
import sys
from p5Dict import varTypeD, varValueD, labelD, declareVar, declareLabel, printVariables, printLabels      

# If less than required documents we throw error and exit. 
if len(sys.argv) < 2:
    print('ERROR: Invalid Number of Arguments!!\nUSAGE: [PYTHON] [INPUT]')
    sys.exit()

# Open file for reading. 
file = open( sys.argv[1], "r" )

# Print header of output.
print("BEEP source code in " + sys.argv[1] + ":")

i = 0
# Loop to read through file. 
while True:
    # Open file for reading.
    fileLine = file.readline()

    # Break at lines with null value.
    if fileLine == "":
        break
    i += 1

    # Remove end line characters. 
    fileLine = fileLine.rstrip('\n')

    # Print each line for output.
    print( "%*d. %s" %(3, i, fileLine))
    
    # Remove leading characters. 
    line = fileLine.lstrip()
    # Break up string and return line.
    lineToks = line.split()
    
    if len(lineToks) == 0:
      continue 

    # Condition utilized to check for Label. 
    if( lineToks[0][-1] == ':' ):
        declareLabel( lineToks, labelD, i )
        lineToks = lineToks[1:]
    # Coniditon utilized to check for Variable. 
    if( lineToks[0]=='VAR' ): 
        declareVar( lineToks[1:], varTypeD, varValueD )

# Print both Variables & Labels.
printVariables(varTypeD, varValueD)
printLabels(labelD)

# Closed file read.
file.close()
