#!/usr/bin/env -S uv run
import re
from numpy._typing import NDArray
import pytest # noqa: F401
import subprocess
import os
import time
# import psutil
import pycpptest
import numpy as np
from scipy import stats

# Get the name of the Python file
build_dir = "build"
filename = os.path.basename(__file__)
dirname = os.path.dirname(__file__)
problem : str = pycpptest.get_problem(filename)
build_problem : str = os.path.join(build_dir,problem)

# Extract test cases from cph file
testcases = pycpptest.get_test_cases_cph(problem)

def run_problem(input: str  , build_problem=f"{build_problem}")->str:
    # with subprocess.Popen([f"./{build_problem}"], stdin=subprocess.PIPE, stdout=subprocess.PIPE) as process:
    #     output, _ = process.communicate(input=input.encode('utf-8'))
    #     output = output.decode('utf-8')
    start_time = time.time()
    out = subprocess.run([f"./{build_problem}"], input=input.encode('utf-8'), stdout=subprocess.PIPE)
    end_time = time.time()
    # out.pid
    b_print(f"\nTime Taken: {(end_time - start_time)*1000:.2f} ms\n")


    return out.stdout.decode('utf-8')
    # process = subprocess.check_output([f"./{build_problem}"], input=input.encode('utf-8')).decode('utf-8')
    # return subprocess.check_output([f"./{build_problem}"], input=input.encode('utf-8')).decode('utf-8')
def print_run_problem(input: str  , build_problem=f"{build_problem}")->None:
    print(run_problem(input , build_problem))

def mode(a:NDArray)->NDArray:
    values, counts = np.unique(a, return_counts=True)
    max_count = np.max(counts)
    m = values[counts == max_count] 
    return m

def check_mode(a:list[str], b:list[str])->bool:
    a_np = np.array(a , dtype=int)
    b_np = np.array(b , dtype=int)
    if a_np.size != b_np.size:
        r_print("A & B Size Mismatch")
        return False
    for i in range(a_np.size):
        if a_np[i] not in mode(b_np[:i+1]):
            r_print("Mode Mismatch")
            print(f"\tArray A: {a}\n\tArray B: {b}")
            r_print(f"Mode Mismatch at [Index {i}]")
            print(f"\tSub B: {b_np[:i+1]}")
            print(f"\tMode of B: {mode(b_np[:i+1])}\n\tMode A[{i}]: {a_np[i]}")
            return False
    return True

def r_print(text:str, console=True):
    if console:
        print(f"\033[91m {text} \033[0m")
    return (f"\033[91m {text} \033[0m")

def g_print(text:str , console=True):
    if console:
        print(f"\033[92m {text} \033[0m")
    return f"\033[92m {text} \033[0m"

def b_print(text:str , console=True):
    if console:
        print(f"\033[94m {text} \033[0m")
    return f"\033[94m {text} \033[0m"

def remove_empty(A:list[str])->list[str]:
    return [x for x in A if x not in [""," ","\n","\t"]]

## [ Pytest ] ==================================
@pytest.mark.parametrize("test_in , test_out" , testcases)
def test_cph_cases(test_in , test_out):
    # assert run_problem(test_in) == test_out
    B = run_problem(test_in)
    B = B.split("\n")
    # B = B[2::2]
    A = test_in.split("\n")
    A = A[2::2]
    A = remove_empty(A)
    B = remove_empty(B)
    if len(A) != len(B):
        r_print("\n Number of Test Mismatch: ")
        print("A: ",A)
        print("B: ", B)
        print("Length of A: ",len(A))
        print("Length of B: ",len(B))
        
        pytest.exit(r_print("[ Test Failed. ]", False))
    g_print("\n Running Test Cases: ")    
    for i in range(len(B)):
        g_print(f"\tRunning Test Case: {i+1}")
        if len(A[i].split(" ")) < i:
            print(f"\t Length of A[i] = {len(A[i].split(' '))} out of bound")
            pytest.exit(r_print("[ Test Failed. ]", False))
            
        if len(B[i].split(" ")) < i:
            print(f"\t Length of B[i] = {len(B[i].split(' '))} out of bound")
            pytest.exit(r_print("[ Test Failed. ]", False))
        a = remove_empty(A[i].split(" "))
        b = remove_empty(B[i].split(" "))
        if not check_mode( a, b ):
            r_print("Test Case Failed:")
            print(f"\tArray A: {A[i]}\n\tArray B: {B[i]}")
            # assert False
            pytest.exit(r_print("[ Test Failed. ]", False))
            # pytest.exit("\033[91m [ Test Failed. ] \033[0m")

    assert True




my_testcases = [
    # ("Test_in_01" , "Test_out_01" ),
    # ("Test_in_02" , "Test_out_02" )
]
@pytest.mark.parametrize("my_test_in , my_test_out" , my_testcases)
def test_my_cases(my_test_in, my_test_out):
    assert run_problem(my_test_in) == my_test_out

# Can Generate Test Cases with brute force
def gen_cases(n_cases:int=5 , gen_testcases:list[tuple[str, str]]=[]) -> list[tuple[str, str]]:
    # TODO: Generate test cases with brute force        
    # 
    # 
    return gen_testcases

@pytest.mark.parametrize("gen_test_in , gen_test_out" , gen_cases())
def test_gen_cases(gen_test_in , gen_test_out):
    assert run_problem(gen_test_in) == gen_test_out
    
    
## [ Main ] (run from Script) ==================
if __name__ == "__main__":
    pycpptest.compile(problem , build_dir)
    filepath = os.path.join(dirname,filename)
    os.system(f"pytest -s -vv {filepath}")