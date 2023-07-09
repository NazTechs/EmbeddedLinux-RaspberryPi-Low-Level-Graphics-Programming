#include <fcntl.h>
#include <linux/fb.h>
#include <sys/ioctl.h>
#include <sys/mman.h>
#include <unistd.h>
#include <iostream>
#include "RawGraphicClass.h"

// Function to open the framebuffer device and retrieve screen information
void openFramebuffer(int& fbfd, struct fb_var_screeninfo& vinfo, struct fb_fix_screeninfo& finfo, char*& fbp) {
    // Open the framebuffer device
    fbfd = open("/dev/fb0", O_RDWR);
    if (fbfd == -1) {
        std::cerr << "Error opening framebuffer device." << std::endl;
        exit(1);
    }

    // Get fixed screen information
    if (ioctl(fbfd, FBIOGET_FSCREENINFO, &finfo) == -1) {
        std::cerr << "Error getting fixed screen information." << std::endl;
        close(fbfd);
        exit(1);
    }

    // Get variable screen information
    if (ioctl(fbfd, FBIOGET_VSCREENINFO, &vinfo) == -1) {
        std::cerr << "Error getting variable screen information." << std::endl;
        close(fbfd);
        exit(1);
    }

    // Map the framebuffer into memory
    fbp = (char*)mmap(nullptr, finfo.smem_len, PROT_READ | PROT_WRITE, MAP_SHARED, fbfd, 0);
    if (fbp == MAP_FAILED) {
        std::cerr << "Error mapping framebuffer to memory." << std::endl;
        close(fbfd);
        exit(1);
    }
}

// Function to close the framebuffer device and unmap memory
void closeFramebuffer(int fbfd, char* fbp) {
    munmap(fbp, 0);
    close(fbfd);
}

int main() {
    int fbfd;                             // File descriptor for the framebuffer
    struct fb_var_screeninfo vinfo;       // Variable screen information
    struct fb_fix_screeninfo finfo;       // Fixed screen information
    char* fbp;                            // Framebuffer pointer

    openFramebuffer(fbfd, vinfo, finfo, fbp);

    // Create an instance of the RawGraphic class
    RawGraphic graphic(fbp, vinfo, finfo);

    // Set the properties and draw on the framebuffer
    int x = 100;
    int y = 50;
    int width = 800;
    int height = 500;
    unsigned int rectangleColor = COLOR_WHITE; 
    graphic.drawRectangle(x, y, width, height, rectangleColor);

    int centerX = 300;
    int centerY = 200;
    int radius = 100;
    unsigned int circleColor = COLOR_ORANGE;  
    graphic.drawCircle(centerX, centerY, radius, circleColor);

    int rotatedX = 400;
    int rotatedY = 300;
    int rotatedWidth = 150;
    int rotatedHeight = 100;
    float angle = 30.0;
    unsigned int rotatedRectangleColor = COLOR_PURPLE;  
    graphic.drawFilledRotatedRectangle(rotatedX, rotatedY, rotatedWidth, rotatedHeight, angle, rotatedRectangleColor);

    // Wait for a while to observe the drawn shapes
    //usleep(5000000);  // Sleep for 5 seconds

    closeFramebuffer(fbfd, fbp);

    return 0;
}