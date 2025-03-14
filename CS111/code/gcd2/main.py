def euclid_slow(a, b):

	if a == b:
		return a
	if a < b:
		tmp = a
		a = b
		b = tmp
	
	return euclid_slow(a - b, b)

def euclid_fast(a, b):
	
	if b == 0:
		return a
	if a == 0:
		return b	
	if a < b:
		tmp = a
		a = b
		b = tmp

	return euclid_fast(a % b, b)

def main():
	
	print(euclid_slow(1034, 222))
	print(euclid_fast(1034, 222))

if __name__ == "__main__":
	main()	
