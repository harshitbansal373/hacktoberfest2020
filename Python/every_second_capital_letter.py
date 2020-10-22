def sarcasm(string):
	'''
	Converts every even indexed letter to uppercase and odd to lowercase
	making is look sarcastic
	>>> sarcasm('yeah like this would surely work')
	>>> yEaH LiKe tHiS WoUlD SuReLy wOrK
	'''
	return ''.join(c.lower() if not index % 2 else c for index, c in enumerate(string.upper()))


if __name__ == '__main__':
	print(sarcasm('yeah like this would surely work'))
