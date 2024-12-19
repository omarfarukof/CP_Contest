#!/usr/bin/env -S uv run

import os
import pycpptest as pct

# Veriable
match_char:bool = False

# Get the name of the Python file
build_dir = "build"
filename = os.path.basename(__file__)
dirname = os.path.dirname(__file__)
problem : str = pct.get_problem(filename)
build_problem : str = os.path.join(build_dir,problem)

# Extract test cases from cph file
cph_testcases = pct.get_test_cases_cph(problem)

my_testcases = [
    # ("Test_in_01" , "Test_out_01" ),
    # ("Test_in_02" , "Test_out_02" )
    ("3\n4 2\n6 1\n8 3\n", " "),
    ("7\n4 2\n6 1\n8 3\n9 3\n10 3\n11 3\n12 3\n", " "),
]

gen_testcases = []

def verify_output(input , run_output, expected_output, match_char=match_char)->bool:
    if match_char:
        return run_output == expected_output
    else:
        pct.col_print("Verifying Output With Verification Logic", color="yellow")
        # TODO: Write Verification Logic
        # INPUT:
        # 
        # 3     -> No_Test_Case
        # 4 2   -> n, k
        # 6 1   -> n, k
        # 8 3   -> n, k
        # 
        n_test:int = int(input.split("\n")[0])
        inputs = input.split("\n")[1:]
        n_list:list[int] = []
        k_list:list[int] = []
        for inp in inputs:
            if inp in [""," "]:
                continue
            n, k = inp.split(" ")
            n = int(n)
            k = int(k)
            n_list.append(n)
            k_list.append(k)
        run_outputs = run_output.split("\n")
        run_outputs = [x for x in run_outputs if x not in [""," "]]

        if ( n_test != len(n_list) and n_test != len(k_list) and n_test != len(run_outputs) ):
            pct.r_print("Error: Number of test cases not match")
            return False
        
        for i,n,k,arr in zip(range(n_test) , n_list , k_list , run_outputs):
            arr:list[int] = [int(x) for x in arr.split(" ") if x not in [""," "]]

            # Check if arr has all numbers from 1 to n
            if ( len(arr) != n ):
                pct.r_print("Error: Array length is not equal to n")
                return False
            if ( sorted(arr) != list(range(1,n+1)) ):
                pct.r_print("Error: Array does not have all numbers from 1 to n")
                return False

            # min_sum = 0
            # for j in range(n-k+1):
            #     min_sum += min(arr[j:k+1])
                
            # last_num = (int((n+1)/k)) * ((n+1)%k)
            # min_sum_bt = sum(range(1,int((n+1)/k))) * k + last_num
            # if ( min_sum != min_sum_bt ):
            #     pct.col_print("-"*20, color="yellow")
            #     pct.col_print(f"n: {n} , k: {k}", color="yellow")
            #     pct.col_print("arr : " + str(arr), color="yellow")
            #     pct.col_print(f"min_sum: {min_sum}", color="yellow")
            #     pct.col_print(f"min_sum_bt: {min_sum_bt}", color="yellow")
            #     pct.col_print("-"*20, color="yellow")
            #     pct.r_print("Error: Minimum sum of k elements is not equal to Result")
            #     return False
            # else:
            #     return True

            min_sum = 0
            # n = 4
            # k = 2
            # arr = [3, 1, 2, 4]
            for j in range(n-k+1):
                min_sum += min(arr[j:j+k])

            last_num = (int((n+1)/k)) * ((n+1)%k)
            min_sum_bt = (sum(range(1,int((n+1)/k))) * k) + last_num
            if ( min_sum != min_sum_bt ):
                pct.col_print("-"*20, color="yellow")
                pct.col_print(f"n: {n} , k: {k}", color="yellow")
                pct.col_print("arr : " + str(arr), color="yellow")
                pct.col_print(f"min_sum: {min_sum}", color="yellow")
                pct.col_print(f"min_sum_bt: {min_sum_bt}", color="yellow")
                pct.col_print("-"*20, color="yellow")
                pct.r_print("Error: Minimum sum of k elements is not equal to Result")
                return False
            else:
                return True


        # TODO: Write Verification Logic
        #         
        # return False

# Can Generate Test Cases with brute force
def gen_cases(n_cases:int=5 , gen_testcases:list[tuple[str, str]]=[]) -> list[tuple[str, str]]:
    # TODO: Generate test cases with brute force        
    # 
    # 
    return gen_testcases



## [ PyCpptest ] ==================================

def test_cases(test_in , test_out , build_problem , Test_Case_No=1, No_Cases=1)->bool:
    input = test_in
    run_output = pct.run_problem(input, build_problem)
    expected_output = test_out
    if verify_output(input, run_output, expected_output):
        pct.g_print(f"Passed CPH Test Case {Test_Case_No} of {No_Cases}")
        return True
    else:
        pct.output_failure_result(input , run_output , expected_output, Test_Case_No, No_Cases)
        return False

    
## [ Main ] (run from Script) ==================
if __name__ == "__main__":
    pct.center_print(" PyCpptest Start " , char="=")
    pct.compile(problem , build_dir)
    filepath = os.path.join(dirname,filename)

    print(cph_testcases)

    # CPH_TestCases
    pct.test_code(cph_testcases , build_problem , verify_output , Test_Name="CPH")

    # My_TestCases
    pct.test_code(my_testcases , build_problem , verify_output , Test_Name="MY")

    # Gen_TestCases
    gen_testcases = gen_cases(gen_testcases=[])
    pct.test_code(gen_testcases , build_problem , verify_output , Test_Name="GEN")

    if pct.DEBUG:
        pct.test_code(pct.DEBUG_testcases , build_problem , verify_output, benchmark=True , Test_Name="DEBUG")

