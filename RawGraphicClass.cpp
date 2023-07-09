#include "RawGraphicClass.h"

RawGraphic::RawGraphic(char* framebufferPtr, struct fb_var_screeninfo variableInfo, struct fb_fix_screeninfo fixedInfo)
    : fbp(framebufferPtr), vinfo(variableInfo), finfo(fixedInfo) {}

void RawGraphic::setPixel(int x, int y, unsigned int color) {
    int location = (x + vinfo.xoffset) * (vinfo.bits_per_pixel / 8) +
                    (y + vinfo.yoffset) * finfo.line_length;
    *((unsigned int*)(fbp + location)) = color;
}

void RawGraphic::drawRectangle(int x, int y, int width, int height, unsigned int color) {
    int startX = x;
    int endX = x + width;
    int startY = y;
    int endY = y + height;

    for (int yPos = startY; yPos < endY; yPos++) {
        for (int xPos = startX; xPos < endX; xPos++) {
            int location = (xPos + vinfo.xoffset) * (vinfo.bits_per_pixel / 8) +
                            (yPos + vinfo.yoffset) * finfo.line_length;
            *((unsigned int*)(fbp + location)) = color;
        }
    }
}

void RawGraphic::drawCircle(int centerX, int centerY, int radius, unsigned int color) {
    for (int yPos = centerY - radius; yPos <= centerY + radius; yPos++) {
        for (int xPos = centerX - radius; xPos <= centerX + radius; xPos++) {
            int distance = (xPos - centerX) * (xPos - centerX) + (yPos - centerY) * (yPos - centerY);
            if (distance <= radius * radius) {
                int location = (xPos + vinfo.xoffset) * (vinfo.bits_per_pixel / 8) +
                                (yPos + vinfo.yoffset) * finfo.line_length;
                *((unsigned int*)(fbp + location)) = color;
            }
        }
    }
}

void RawGraphic::drawFilledRotatedRectangle(int x, int y, int width, int height, float angle, unsigned int color) {
    int centerX = x + (width / 2);
    int centerY = y + (height / 2);
    float angleRad = angle * M_PI / 180.0;
    float halfWidth = width / 2.0;
    float halfHeight = height / 2.0;

    float topLeftX = centerX - halfWidth * cos(angleRad) - halfHeight * sin(angleRad);
    float topLeftY = centerY - halfWidth * sin(angleRad) + halfHeight * cos(angleRad);
    float topRightX = centerX + halfWidth * cos(angleRad) - halfHeight * sin(angleRad);
    float topRightY = centerY + halfWidth * sin(angleRad) + halfHeight * cos(angleRad);
    float bottomLeftX = centerX - halfWidth * cos(angleRad) + halfHeight * sin(angleRad);
    float bottomLeftY = centerY - halfWidth * sin(angleRad) - halfHeight * cos(angleRad);
    float bottomRightX = centerX + halfWidth * cos(angleRad) + halfHeight * sin(angleRad);
    float bottomRightY = centerY + halfWidth * sin(angleRad) - halfHeight * cos(angleRad);

    int minY = fmin(fmin(topLeftY, topRightY), fmin(bottomLeftY, bottomRightY));
    int maxY = fmax(fmax(topLeftY, topRightY), fmax(bottomLeftY, bottomRightY));

    for (int scanlineY = minY; scanlineY <= maxY; scanlineY++) {
        float leftX = interpolate(topLeftY, bottomLeftY, topLeftX, bottomLeftX, scanlineY);
        float rightX = interpolate(topRightY, bottomRightY, topRightX, bottomRightX, scanlineY);

        drawHorizontalLine(static_cast<int>(leftX), static_cast<int>(rightX), scanlineY, color);
    }
}

float RawGraphic::interpolate(float x1, float x2, float y1, float y2, float y) {
    return x1 + ((y - y1) / (y2 - y1)) * (x2 - x1);
}

void RawGraphic::drawHorizontalLine(int startX, int endX, int y, unsigned int color) {
    for (int xPos = startX; xPos <= endX; xPos++) {
        int location = (xPos + vinfo.xoffset) * (vinfo.bits_per_pixel / 8) +
                        (y + vinfo.yoffset) * finfo.line_length;
        *((unsigned int*)(fbp + location)) = color;
    }
}
