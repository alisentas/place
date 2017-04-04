all:
	gcc -o place -O2 -g `pkg-config --libs allegro-5 allegro_image-5` -lm main.c

run:
	./place
