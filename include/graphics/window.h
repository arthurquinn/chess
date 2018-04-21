#ifndef __WINDOW_H
#define __WINDOW_H


class Window {
private:
    const int SCREEN_WIDTH { 640 };
    const int SCREEN_HEIGHT { 480 };

public:
    Window() = default;
    virtual ~Window() = default;

    void test() const;
};



#endif
