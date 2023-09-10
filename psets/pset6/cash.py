while True:
	change = float(input("Change: "))

	if change > 0.00:

		change = round(change * 100)
		coin = 0

		while change >= 25:
			change -= 25;
			coin+=1
	
		while change >= 10:
			change -= 10;
			coin+=1
	
		while change >= 5:
			change -= 5;
			coin+=1
	
		while change >= 1:
			change -= 1;
			coin+=1
	
		print(f"{coin} is required");

	break



