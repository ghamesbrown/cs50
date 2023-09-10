import sys, csv

if len(sys.argv) != 3:
	sys.exit("Usage: python dna.py data.csv sequence.txt")

with open(sys.argv[2]) as txt:
	dna = txt.read()


with open(sys.argv[1]) as csvf:
	reader = csv.DictReader(csvf)
	strr = reader.fieldnames[1:]
	strr_c = {}

	for st in strr:
		index = 0
		ls = 0
		csq = 0

		while index < len(dna):
			cs = dna[index:index + len(st)]

			if cs == st:
				csq += 1
				index += len(st)

			else:
				if csq > ls:
					ls = csq
					
				csq = 0
				index += 1

		strr_c[st] = ls

	for person in reader:
		name = person['name'] 
		is_found = True

		for st in strr:
			if int(person[st]) != strr_c[st]:
				is_found = False
				break

		if is_found:
			print(name)
			sys.exit(0)

	print("No Match!")

	dna.close
