# EmbeddedLinux and Raspberry Pi Framebuffer Graphics Tutorials and Example
Welcome to the Raspberry Pi Framebuffer Graphics repository! This repository provides a collection of tutorials, examples, and code snippets to help you get started with low graphics development using the framebuffer on Raspberry Pi or other embedded Linux system.

## Features

- Learn the basics of framebuffer and its integration with Raspberry Pi
- Draw simple shapes like rectangles, circles, lines, and polygons directly on the screen
- Compatibility with various Raspberry Pi models and Linux distributions

## Getting Started

To get started with Raspberry Pi Framebuffer Graphics, follow these steps:

1. Connect your Raspberry Pi to a display to ensure you can see the graphical output.

2. If you are using a graphical desktop environment, switch to the console view by pressing `Alt + Ctrl + F2`. This will bring you to a virtual terminal without the graphical desktop environment.

3. Check if the framebuffer device (`/dev/fb0`) is available on your system by running the following command:
```shell
ls /dev/fb0```
