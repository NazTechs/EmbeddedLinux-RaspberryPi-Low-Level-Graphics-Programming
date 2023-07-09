#ifndef RAW_GRAPHIC_H
#define RAW_GRAPHIC_H

#include <linux/fb.h>
#include <cmath>

#define COLOR_BLACK      0x0000
#define COLOR_WHITE      0xFFFF
#define COLOR_RED        0xF800
#define COLOR_GREEN      0x07E0
#define COLOR_BLUE       0x001F
#define COLOR_CYAN       0x07FF
#define COLOR_MAGENTA    0xF81F
#define COLOR_YELLOW     0xFFE0
#define COLOR_ORANGE     0xFC00
#define COLOR_PURPLE     0x8010
#define COLOR_PINK       0xFE19
#define COLOR_LIME       0x07E3
#define COLOR_TEAL       0x0410
#define COLOR_AQUA       0x0FF0
#define COLOR_SILVER     0xC618
#define COLOR_GRAY       0x8410

class RawGraphic {
private:
    char* fbp;
    struct fb_var_screeninfo vinfo;
    struct fb_fix_screeninfo finfo;

public:
    RawGraphic(char* framebufferPtr, struct fb_var_screeninfo variableInfo, struct fb_fix_screeninfo fixedInfo);
    void setPixel(int x, int y, unsigned int color);
    void drawRectangle(int x, int y, int width, int height, unsigned int color);
    void drawCircle(int centerX, int centerY, int radius, unsigned int color);
    void drawFilledRotatedRectangle(int x, int y, int width, int height, float angle, unsigned int color);

private:
    float interpolate(float x1, float x2, float y1, float y2, float y);
    void drawHorizontalLine(int startX, int endX, int y, unsigned int color);
};

#endif  // RAW_GRAPHIC_H