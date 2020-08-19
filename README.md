# FdF :milky_way:
Want to create your own simple 3D world?\
Put in an ASCII map, 2Dto3D will take care of the rest. :metal:\
All of the features were implemented without any help from external libraries. :star:
<img width="2032" alt="Screen Shot 2020-08-19 at 11 37 48" src="https://user-images.githubusercontent.com/49394144/90598263-e8bec700-e21c-11ea-83e3-4ba13f73934f.png">
### Requirements
This project relies on MiniLibX and can be run only on MacOS.
### Installations
Run the following command in your terminal. You should see the window similar to the above screenshot.
```shell
cd ~/Downloads && git clone https://github.com/kabelt/FdF.git FdF && cd FdF && make && ./2Dto3D maps/Thailand.fdf
```
### Controls
| KEY           | Action        |
| ------------- |:-------------:|
| `W`           | move forward  |
| `S`           | move backward |
| `A`           | move to the left     |
| `D`           | move to the right    |
| `→`           | turn right    |
| `←`           | turn left     |
| `M`           | enable/disable minimap|
| `L`           | enable/disable shadow effect|
| `ESC`         | exit      |
### Features
- [x] Collision detection
- [x] [Sprites](https://en.wikipedia.org/wiki/Sprite_(computer_graphics))
- [x] Different wall texturing based on directions
- [x] Customizable wall/ceiling colors
- [x] Shadow effect based on distance
- [x] Minimap
### It's time to create you own world!
You can find the details about how .cub files works [here](subject/en.subject.pdf) on page 6-9.\
Then relaunch 2Dto3D with your map;
```shell
./2Dto3D <your_map>
```
### Acknowledgements
This project is part of 42 pedagogy originally named as Cub3D.
