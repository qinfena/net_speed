app:speed.c apue.c
	gcc -g speed.c apue.c -o app

.PHONY:clean
clean:
	rm app
