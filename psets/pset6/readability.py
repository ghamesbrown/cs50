def main():
	text = input("Text: ")

	L = count_letter(text) * 100 / count_word(text)
	S = count_sent(text) * 100 / count_word(text,)

	index = int((0.0588 * L) - (0.296 * S) - 15.8)

	if index < 1:
		print("Before Grade 1")

	elif index >= 16: 
		print("Grade 16+")

	else:
		print(f"Grade {index}")


def count_word(text):
	word = 1
	for i in text:
		if i.isspace() == True:
			word+=1
	return word


def count_sent(text):
	sent = 0
	for i in text:
		if i == '.' or i == '!' or i == '?':
			sent+=1
	return sent


def count_letter(text):
	letter = 0
	for i in text:
		if i.isalpha() == True:
			letter+=1
	return letter


if __name__ == "__main__":
	main()
