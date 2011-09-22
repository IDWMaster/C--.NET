#ifndef WINDOW_H
#define WINDOW_H


class Window
{
    public:
        Window();
        virtual ~Window();
        Window(const Window& other);
        Window& operator=(const Window& other);
    protected:
    private:
};

#endif // WINDOW_H
