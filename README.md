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
ls /dev/fb0
```

You should see /dev/fb0 listed if the framebuffer device is present.

![image](https://github.com/soheil1156/EmbeddedLinux-RaspberryPi-Low-Level-Graphics-Programming/assets/24310606/23d37d1b-2477-4416-89b4-22b7cf4eac8b)

4. Install the necessary build tools on your Linux distribution. This can typically be done by running the following command:

```shell 
sudo apt-get install build-essential
```

This will install the required tools for compiling and building software on your system.

5. Clone this repository to your Raspberry Pi by running the following command:

```shell 
git clone https://github.com/Soheil1156/EmbeddedLinux-RaspberryPi-Low-Level-Graphics-Programming.git
```

This will create a local copy of the repository on your Raspberry Pi.

6. Navigate to the repository directory:

```shell 
cd EmbeddedLinux-RaspberryPi-Low-Level-Graphics-Programming
```

7. Build the software using the provided Makefile:

```shell 
make
```

This will compile the code and generate the executable.

8. Run the software:
```shell 
./graphic
```

You should see a graphical output on your connected display, similar to the frame shown in the image below.

<p align="center">
    <img src="https://github.com/soheil1156/EmbeddedLinux-RaspberryPi-Low-Level-Graphics-Programming/assets/24310606/7b92dc8c-abef-40ac-9fbc-d426945aab95" width="500">
</p>

## Contributing

Contributions to this repository are welcome! If you have any improvements, bug fixes, or additional examples, feel free to submit a pull request. Please ensure that your contributions align with the goal of the repository.

If you find any issues or have suggestions for new topics or improvements, please open an issue on the GitHub repository.

## License

This repository is licensed under the MIT License, allowing you to freely use the code for personal or commercial projects.

## Acknowledgements

We would like to express our gratitude to the open-source community for their contributions and support.

## Resources

- [Official Raspberry Pi Website](https://www.raspberrypi.org/)
- [Framebuffer Documentation](https://www.kernel.org/doc/html/v4.10/gpu/fbdev/index.html)

Enjoy exploring the world of Raspberry Pi framebuffer graphics!
