#   ***
#       Global Variables to be imported to Driver file.
#   ***
varTypeD = {}
varValueD = {}
labelD = {}

#   ___
#   ***
#       def declareVar( tokenM, varTypeD, varValueD )
#   ...
#	- Purpose:
#           This is used to record type of variable in varTypeD and value in varValueD.
#   ...
#	- Parameters:
#           tokenM- Array that contains tokens from each line. 
#	    varTypeD- Dictionary of variable types.
#	    varValueD- Dictionary of variable values.
#   ...
#       - Return:
#           This will return populated dictionaries as well as uppercase values. 
#   ***
def declareVar( tokenM, varTypeD, varValueD ):
    
    # We make sure to uppercase values then save these values. 
    tokT = tokenM[0].upper()
    tokN = tokenM[1].upper()
    varTypeD[tokN] = tokT

    # Populate Dictionaries.
    if(len(tokenM) is 2):
        varValueD[tokN] = ""
    else:
        varValueD[tokN] = tokenM[-1]

#   ____
#   ***
#       def printVariables( varTypeD, varValueD )
#   ...
#       - Purpose:
#           Prints all varTypeD variables in ascending order by name.
#   ...
#       - Parameters:
#           varTypeD- The dictionary of variable types.
#           varValueD- The dictionary of variable values.
#   ...
#       - Return:
#           This will literally print our values. 
#   ***
def printVariables( varTypeD, varValueD ):
    
    # Print Variables.      
    print("Variables:")
    print( '\t{:>4} {:<12} {:8} {:<10}'.format( "", "Variable", "Type", "Value" ))

    # Sorted in ascending order.
    for i in sorted( varTypeD ):
        varValueD[i] = varValueD[i].strip('"')
        print( '\t{:>4} {:<12} {:8} {:<10}'.format( "", i, varTypeD[i], varValueD[i] ))
        
#
#   ____
#   ***
#	def declareLabel( tokenM, labelD, numLine )
#   ...
#   	- Purpose:
#	    Saves a labels into labelD (Dictionary).
#           Else throws error as well as informs user of line number. 
#   ...
#	- Parameters:
#	    tokenM: Array that contains tokens from a line.
#	    labelD: Dictionary of label line numbers.
#	    numLine: The line number of label.
#       - Return:
#           This Function will return uppercase values as well as populated dictionaries.
#   ***
def declareLabel( tokenM, labelD, numLine ):
    
    # We make sure to uppsercase values and save these values.
    tok = tokenM[0][:-1].upper()

    if(tok in labelD):
        print('***ERROR: label \'{}\' appears in multiple lines: {} and {}'.format( tok, labelD[tok], numLine ))

    # Assign Line Number. 
    labelD[tok] = numLine

#
#   ___
#   ***
#	def printLabels(labelD)
#   ...
#	- Purpose:
#	    Prints all labels in labelD in ascending order by name..
#   ...
#	- Parameters:
#	    labelD- Dictionary of line numbers from Label.
#   ...
#       - Return:
#           This Function will literally return printed values. 
#   ***
def printLabels(labelD):
    # Print Labels Information.
    print("Labels:")
    print( '\t{:>4} {:<12} {:8}'.format( "", "Label", "\tStatement" ))
    # Sort and print in ascending order. 
    for i in sorted(labelD):
        print( '\t{:>4} {:<12} {:8}'.format("", i, labelD[i] ))  

#
#
#
#   
