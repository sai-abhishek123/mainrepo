a=0
b=1
sum=0
i=0
c=int(input("Enter the range"))
print(a)
for i in range (1,c):
    sum=a+b
    b=a
    a=sum
    print(sum)  