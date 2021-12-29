a = int(input("Enter the number"))
temp = a
temp1 = a
sum = 0
count = 0
while temp != 0:
    rem = temp % 10
    count = count + 1
while a != 0:
    rem = a % 10
    sum = sum + pow(rem,3)
    a = a / 10
if sum == temp1:
    print("Armstrong")
else:
    print("no")
