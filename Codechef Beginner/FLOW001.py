# You don't need to add/edit anything to the below solution. 
# Click on the SUBMIT button to solve your first problem on CodeChef.

#Read the number of test cases.
T = int(input())
for tc in range(T):
	# Read integers a and b.
	(a, b) = map(int, input().split(' '))
	
	ans = a + b
	print(ans)