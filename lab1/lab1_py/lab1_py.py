first = float(input("Enter first number: ")) #entering first number
second = float(input("Enter second number: ")) #entering second number
third = float(input("Enter third number: ")) #entering third number

geom_mean = pow(first * second * third, 1/3) #calculating geometric mean
fract_part = divmod(geom_mean, 1)[1] #separating fractional part

print("The fractional part of the geometric mean: ", fract_part) 
