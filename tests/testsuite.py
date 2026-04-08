import os
import sys
import subprocess
from termcolor import colored

show_all = os.environ.get("ALL", "false").lower() == "true"
bin_path = "../src/wolf"
test_dir = "."

# Catégories pour le reporting
success_categories = {"valid"}

def run_command(args):
    """Use to get stdout, stderr and exit status of a command"""
    proc = subprocess.Popen(
        args,
        stdout=subprocess.PIPE,
        stderr=subprocess.PIPE,
        text=True
    )
    out, err = proc.communicate()
    return out, err, proc.returncode

def run_test(module, category, file, first):
    file_path = os.path.join(test_dir, module, category, file)
    
    w_out, w_err, w_code = run_command([bin_path, file_path])
    g_out, g_err, g_code = run_command(["gcc", "-fsyntax-only", file_path])

    w_err_clean = w_err.strip()
    g_err_clean = g_err.strip()

    diffs = []
    
    if (w_code != 0 and  g_code == 0) or (w_code == 0 and g_code != 0):
        diffs.append(f"Return code mismatch: Wolf={w_code} | GCC={g_code}")
    
    if (w_err_clean == "") != (g_err_clean == ""):
        w_status = "empty" if w_err_clean == "" else "NOT empty"
        g_status = "empty" if g_err_clean == "" else "NOT empty"
        diffs.append(f"Stderr presence mismatch: Wolf stderr is {w_status} | GCC stderr is {g_status}")

    success = len(diffs) == 0
    
    if not success:
        if first:
            print(colored(f"======= {module} =======\n", "yellow"))
        
        print(colored(f"[FAIL] {module}/{category}/{file}", "red"))
        
        for d in diffs:
            print(f"  - {d}")
            
        if w_err_clean:
            formatted_w = w_err_clean.replace("\n", "\n\t    ")
            print(f"    Wolf Stderr: {formatted_w}")
        if g_err_clean:
            formatted_g = g_err_clean.replace("\n", "\n\t    ")
            print(f"    GCC Stderr:  {formatted_g}")
            
    elif show_all:
        res_type = "BOTH_ERROR" if w_code != 0 or w_err_clean else "BOTH_OK"
        print(colored(f"[PASS] {module}/{category}/{file} ({res_type})", "green"))

    return success

def run_module(module):
    module_path = os.path.join(test_dir, module)
    total = 0
    passed = 0
    first = True

    if not os.path.isdir(module_path):
        return 0, 0

    categories = [d for d in os.listdir(module_path) if os.path.isdir(os.path.join(module_path, d))]

    for category in categories:
        path = os.path.join(module_path, category)
        files = [f for f in os.listdir(path) if f.endswith(".c")]

        for f in files:
            total += 1
            if run_test(module, category, f, first):
                passed += 1
            else:
                first = False
    return passed, total

def run_tests(modules):
    if not modules:
        modules = [m for m in os.listdir(test_dir) if os.path.isdir(os.path.join(test_dir, m))]
    
    total_tests = 0
    total_passed = 0
    results = {}

    for module in modules:
        if module == "__pycache__": continue
        passed, total = run_module(module)
        results[module] = (passed, total)
        total_tests += total
        total_passed += passed

    print(colored("\n======= RECAP =======", "yellow"))
    for module, (passed, total) in results.items():
        color = "green" if passed == total else "red"
        print(colored(f"{module.ljust(15)} {passed}/{total}", color))

    if total_tests > 0:
        ratio = (total_passed * 100) // total_tests
        print(colored(f"\nTotal: {total_passed}/{total_tests} ({ratio}%)", "cyan"))

if __name__ == "__main__":
    run_tests(sys.argv[1:])
