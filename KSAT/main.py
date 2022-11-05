import re
import random

def num_variables(formula):
    return re.findall("[A-Z]", formula)


def determine_n(formula):
    return len(set(num_variables(formula)))


def check_valid(formula):
    formula_match = re.match("\(.*?\)(a\(.*?\))*", formula)
    clauses = formula_match.group().split("a")
    k = clauses[0].count("o") + 1
    return(True,k)

def check_getn(formula):
    (passed, returned) = check_valid(formula)
    if not passed:
        return (passed,returned)
    return (returned, determine_n(formula))

def assign(formula):
    variables = list(set(num_variables(formula)))
    values = {}
    for var in variables:
        values[var] = random.choice([False,True])
    return values
    
def check_clause(clause, values):
    variables = num_variables(clause)

    for var in variables:
        var_val = values[var]

        if clause[clause.index(var) - 1] == "n":
            if  not var_val:
                return True
        else:
            if var_val:
                return True
    return False

def check_solution(formula, values):
    clauses = formula.split("a")
    failed = []
    satisfied = True

    for index, clause in enumerate(clauses):

        if not check_clause(clause, values):
            satisfied = False
            failed.append(index)

    return (satisfied, failed)
"""
input: a formula in -CNF with variables
If the formula is satisfied by the actual
assignment: stop and accept
"""
def schoning_algo(formula,lines):
    
    (k, n) = check_getn(formula)
    count = 0
    if not k:
        return (False,n)
    values = assign(formula)
    newFile.write("Original Instance: "+ str(values) +"\n\n")   
    for index in range(3 * n):
        count += 1        
        satisfied, failed = check_solution(formula, values)
        newFile.write("*********************************************** iteration no."+str(count)+"\n")
        if satisfied:
            newFile.write("**********************************************"+"\n")
            newFile.write("**********************************************"+"\n")
            newFile.write("SATISFACTORY PROPOSAL: "+instance+"\n")
            newFile.write("**********************************************"+"\n")
            newFile.write("**********************************************"+"\n")
            return (values, count)
        else:             
            selection = random.choice(failed)
            false_clause = formula.split("a")[selection]            
            newFile.write("Satisfactory clauses: "+ str(91-len(false_clause)) +"\n")   
            newFile.write("Unsatisfactory clauses: "+ str(len(false_clause)) +"\n")  
            
            var_to_change = random.choice(num_variables(false_clause))            
            values[var_to_change] = False if values[var_to_change]  else True
            newFile.write("-Clausule to change: [" + str(lines[selection]) + "]\n")
            newFile.write("-Variable to change: " +str(var_to_change) + " --> " + str(values[var_to_change]) + "\n" )
            newFile.write("New Instance: "+ str(values) +"\n\n") 
            
    newFile.write("**********************************************"+"\n")
    newFile.write("**********************************************"+"\n")
    newFile.write("NO SOLUTION FOR THIS INSTANCE\n")
    newFile.write("**********************************************"+"\n")
    newFile.write("**********************************************"+"\n")
    return

    
def processTxt(lines):
    letters = ["A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T"]
    string = ""
    for clausule in lines:
        if (clausule != (lines[len(lines)-1])):
            instance = []
            union_str = ")a("
            rowString = "("
            values = clausule.split(" ")
            x1 = (int)(values[0])
            x2 = (int)(values[1])
            x3 = (int)(values[2])       
        
            if(x1<0):
                ln = letters[abs(x1)-1]
                rowString += "n"+ln+"o"
            else:
                ln = letters[abs(x1)-1]
                rowString += ln+"o"        
            if(x2<0):
                ln = letters[abs(x2)-1]
                rowString += "n"+ln+"o"
            else:
                ln = letters[abs(x2)-1]
                rowString += ln+"o"
            if(x3<0):
                ln = letters[abs(x3)-1]
                rowString += "n"+ln+")a"
            else:
                ln = letters[abs(x2)-1]
                rowString += ln+")a"
            string+=rowString  
        else:
            rowString = "("
            values = clausule.split(" ")
            x1 = (int)(values[0])
            x2 = (int)(values[1])
            x3 = (int)(values[2])       
        
            if(x1<0):
                ln = letters[abs(x1)-1]
                rowString += "n"+ln+"o"
            else:
                ln = letters[abs(x1)-1]
                rowString += ln+"o"        
            if(x2<0):
                ln = letters[abs(x2)-1]
                rowString += "n"+ln+"o"
            else:
                ln = letters[abs(x2)-1]
                rowString += ln+"o"
            if(x3<0):
                ln = letters[abs(x3)-1]
                rowString += "n"+ln+")"
            else:
                ln = letters[abs(x2)-1]
                rowString += ln+")"
            string+=rowString
    schoning_algo(string,lines)
        

def main():

    """04_Instance_3SAT_example.txt"""
    input_file_name = str(input("Select your instance, for example 04_Instance_3SAT_example.txt\n""Enter the file name to use as CNF input: " ))
    output_file_name = str(input("Enter the file name to save the CNF output: "))
    content = open(input_file_name,'r').read()
    lines = content.split("\n")   
    line1 = lines[0]
    line2 = lines[1]
    clausules = (line2.split(" "))[3]
    variables = (line2.split(" "))[2]
    
    lines.remove("")
    lines.remove(line2)
    lines.remove(line1)
    
    global newFile 
    newFile = open(output_file_name, "w+")
    newFile.write("SCHONING ALGORITHM FOR 3K-SAT SOLUTION\n")
    newFile.write("Keys: {'A': 1, 'B': 2, 'C': 3, 'D': 4, 'E': 5, 'F': 6, 'G': 7, 'H': 8, 'I': 9, 'J': 10, 'K': 11, 'L': 12, 'M': 13, 'N': 14, 'O': 15, 'P': 16, 'Q': 17, 'R': 18, 'S': 19, 'T': 20}\n\n")
    
    
    processTxt(lines)
    
    newFile.close()
    
main()
