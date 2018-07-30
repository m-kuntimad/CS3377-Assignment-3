all:
	gcc a3p1Server.c -o Server1 -lpthread
	gcc a3p2Server.c -o Server2 -lpthread
	gcc a3p3Server.c -o Server3 -lpthread
	gcc a3p3Client1.c -o Client1
	gcc a3p3Client2.c -o Client2
	gcc a3p3Client3.c -o Client3
