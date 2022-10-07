# We have populated the solutions for the 10 easiest problems for your support.
# Click on the SUBMIT button to make a submission to this problem.

#Note that it's python3 Code. Here, we are using input() instead of raw_input().
#You can check on your local machine the version of python by typing "python --version" in the terminal.

n,atm=map(float,input().split())
n=int(n)
if (n+0.5<=atm and n%5==0):
    print(float(atm-n-0.5))
else:
    print(float(atm))


