#printing upto n without any space 
# n is input from user and is a integer

n = int(input('Enter an integer'))
if n>= 1 and n<=150:  
    for i in range(1,n+1):
        print(i,end="")