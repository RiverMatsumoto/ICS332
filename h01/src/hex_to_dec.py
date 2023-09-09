b = [0x89,0x50,0x4e,0x47,0x0d,0x0a,0x1a,0x0a]
# for each byte in b, replace the character with the decimal representation
print('expected: 137 80 78 71 13 10 26 10')
print(list(map(lambda x: str(x), b)))