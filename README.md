# place
[/r/place](http://reddit.com/r/place) animated

You can use this program to animated any part of /r/place, but first you should install `Allegro 5` library and download and extract [diffs.bin.zip](http://abra.me/place/diffs.bin.zip) to the project folder.

Change the lines from 6 to 9
````
#define START_X     0
#define START_Y     0
#define PIXEL_WIDTH 1
#define SPEED 500
````

and then

````sh
make
make run
````

While watching, press space to stop and c to continue.

Special thanks to [/u/mncke](https://www.reddit.com/user/mncke) for diff archive.
