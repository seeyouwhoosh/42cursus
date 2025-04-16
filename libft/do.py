file = "ctype.c"
n = 0
list = ["ctype.c", "ogft.c", "stdlib.c", "string.c"]

types = ["int", "void", "char", ""]

for element in list:
    with open(element) as fp:
        for _ in range(13):
            fp.readline()
        for line in fp:
            if (line.split())[0] in types:
                fp.write()
            elif 