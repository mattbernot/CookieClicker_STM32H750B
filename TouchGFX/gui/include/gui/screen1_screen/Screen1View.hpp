#ifndef SCREEN1VIEW_HPP
#define SCREEN1VIEW_HPP

#include <gui_generated/screen1_screen/Screen1ViewBase.hpp>
#include <gui/screen1_screen/Screen1Presenter.hpp>

class Screen1View : public Screen1ViewBase
{
public:
    Screen1View();
    virtual ~Screen1View() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    virtual void cookieClicked();
    virtual void replay();
protected:

    uint16_t counter = 0;
    uint16_t progressLevel = 0;
    uint16_t level = 1;
    uint16_t cnt = 0;
    int16_t max = level * 10;
};

#endif // SCREEN1VIEW_HPP
