#include <iostream>
#include <string.h>
#include <fstream>
#include <stdio.h>
using namespace std;

class Postscript {
private:
    ofstream s;
    char strokeColor[64];
    char fillColor[64];
    
public:
    Postscript(const char* str){
        s.open(str);
        
        strcpy(strokeColor, "1 1 1 setrgbcolor\n");
        strcpy(fillColor, "1 1 1 setrgbcolor\n");
    }
    
    ~Postscript(){
        s.close();
    }
    
    void line(int a, int b, int c, int d){
        char buffer[256];
        int size = sprintf(buffer, "%d %d moveto %d %d lineto stroke\n", a, b, c, d);
        s.write(buffer, size);
    }
    
    void setStrokeColor(int r, int g, int b){
        float red, green, blue;
        char buffer[256];
        
        red = r / 255.0;
        green = g / 255.0;
        blue= b / 255.0;
        
        sprintf(buffer, "%.2f %.2f %.2f setrgbcolor\n", red, green, blue);
        strcpy(strokeColor, buffer);
    }
    
    void setFillColor(int r, int g, int b){
        float red, green, blue;
        char buffer[256];
        
        red = r / 255.0;
        green = g / 255.0;
        blue= b / 255.0;
        
        sprintf(buffer, "%.2f %.2f %.2f setrgbcolor\n", red, green, blue);
        strcpy(fillColor, buffer);
    }
    
    void drawRect(float x, float y, float w, float h){
        char buffer[256];
        int size = sprintf(buffer, "%.2f %.2f moveto %.2f %.2f lineto %.2f %.2f lineto %.2f %.2f lineto closepath\n%sstroke\n", x, y, x+w, y, x+w, y+h, x, y+h, strokeColor);
        s.write(buffer, size);
    }
    
    void fillRect(float x, float y, float w, float h){
        char buffer[256];
        int size = sprintf(buffer, "%.2f %.2f moveto %.2f %.2f lineto %.2f %.2f lineto %.2f %.2f lineto closepath\n%sfill\n", x, y, x+w, y, x+w, y+h, x, y+h, fillColor);
        s.write(buffer, size);
    }
    
    void drawTriangle(float x1, float y1, float x2, float y2, float x3, float y3){
        char buffer[256];
        int size = sprintf(buffer, "%.2f %.2f moveto %.2f %.2f lineto %.2f %.2f lineto closepath\n%sstroke\n", x1, y1, x2, y2, x3, y3, strokeColor);
        s.write(buffer, size);
    }
    
    void fillTriangle(float x1, float y1, float x2, float y2, float x3, float y3){
        char buffer[256];
        int size = sprintf(buffer, "%.2f %.2f moveto %.2f %.2f lineto %.2f %.2f lineto closepath\n%sfill\n", x1, y1, x2, y2, x3, y3, fillColor);
        s.write(buffer, size);
    }
    
    void drawCircle(float x, float y, float r){
        char buffer[256];
        int size = sprintf(buffer, "%.2f %.2f %.2f 0 360 arc\n%sstroke\n", x, y, r, strokeColor);
        s.write(buffer, size);
    }
    
    void fillCircle(float x, float y, float r){
        char buffer[256];
        int size = sprintf(buffer, "%.2f %.2f %.2f 0 360 arc\n%sfill\n", x, y, r, fillColor);
        s.write(buffer, size);
    }
    
    void text(float x, float y, const char* str){
        unsigned int len = strlen(str);
        char buffer[256 + len];
        int size = sprintf(buffer, "/Times-Roman findfont 12 scalefont setfont newpath %.2f %.2f moveto (%s) %sshow\n", x, y, str, strokeColor);
        s.write(buffer, size);
    }
    
    void grid(float x1, float interval_x, float x2, float y1, float interval_y, float y2){
        char buffer1[256];
        char buffer2[256];
        char buffer3[256];
        char buffer4[256];
        
        int bins_x = int((x2 - x1) / interval_x);
        int bins_y =int((y2 - y1) / interval_y);
        
        int size1 = sprintf(buffer1, "/vline {%.2f %.2f moveto %.2f %.2f lineto stroke} def\n", x1, y1, x1, y2);
        s.write(buffer1, size1);
        int size2 = sprintf(buffer2, "gsave\nvline\n%d {%.2f 0 translate vline} repeat\ngrestore\n", bins_x, interval_x);
        s.write(buffer2, size2);
        
        int size3 = sprintf(buffer3, "/hline {%.2f %.2f moveto %.2f %.2f lineto stroke} def\n", x1, y1, x2, y1);
        s.write(buffer3, size3);
        int size4 = sprintf(buffer4, "gsave\nhline\n%d {0 %.2f translate hline} repeat\ngrestore\n", bins_y, interval_y);
        s.write(buffer4, size4);
    }
};

int main() {
    Postscript p("test.ps");
    
    int r = 255, g = 150, b = 0;
    
    p.line(30,0, 278,600);
    
    p.setStrokeColor(r, g, b);
    p.line(0,0, 300,400);
    
    p.setFillColor(150, 250, 0);
    p.drawRect(100, 200, 200, 200);
    p.fillRect(10, 20, 20, 20);

    p.drawTriangle(100, 100, 200, 100, 75, 89);
    p.fillTriangle(283, 232, 123, 98, 65, 15);
    p.drawCircle(200, 100, 60);
    p.fillCircle(200, 100, 60);
    p.text(100, 100, "my name is Yu Xia, nice to meet you. This is my postscript object.");
    p.grid(200, 50, 400, 300, 50, 500);
}

