height = int(input("Height: "))

while height < 1 or height > 8:
	height = int(input("Height: "))

else:
	for i in range(height):

		for c in range(height - i, 1, -1):
			print(" ", end="")

		for a in range(i + 1):
			print("#", end="") 

		print()

