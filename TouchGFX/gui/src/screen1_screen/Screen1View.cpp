#include <gui/screen1_screen/Screen1View.hpp>

int currentValue = 0;


Screen1View::Screen1View()
{

}

void Screen1View::setupScreen()
{
    Screen1ViewBase::setupScreen();
}

void Screen1View::tearDownScreen()
{
    Screen1ViewBase::tearDownScreen();
}

void Screen1View::cookieClicked()
{
    	counter++;
    	Unicode::snprintf(textArea1Buffer, TEXTAREA1_SIZE, "%d", counter);
    	textArea1.invalidate();


        currentValue = boxProgress1.getValue();
        max = level * 10;

        int nextValue = cnt+1;
        boxProgress1.setValue(nextValue);

        if (currentValue == max)
        {
        	level++;
        	boxProgress1.setValue(0);
        	boxProgress1.setRange(0, level*10);
        	cnt = 0;

        	Unicode::snprintf(textLevelBuffer, TEXTLEVEL_SIZE, "%d", level);
        	textLevel.invalidate();
        	boxProgress1.invalidate();

        }


        if(level >= 10)
        {
        	textLevel.setVisible(false);
        	boxProgress1.setVisible(false);
        	textArea1.setVisible(false);
        	background.setVisible(false);
        	cookieButton.setVisible(false);

        	winBackground.setVisible(true);
        	winText.setVisible(true);
        	replayButton.setVisible(true);

        	winBackground.invalidate();
        	winText.invalidate();
        	replayButton.invalidate();

        }


        cnt++;
}


void Screen1View::replay()
{

	cnt = 0;
	max = 0;
	level = 1;
	counter = 0;

	boxProgress1.setValue(0);
	boxProgress1.setRange(0, level*10);

	Unicode::snprintf(textArea1Buffer, TEXTAREA1_SIZE, "%d", counter);
	Unicode::snprintf(textLevelBuffer, TEXTLEVEL_SIZE, "%d", level);




	winBackground.setVisible(false);
	winText.setVisible(false);
	replayButton.setVisible(false);


	textLevel.setVisible(true);
	boxProgress1.setVisible(true);
	textArea1.setVisible(true);
	background.setVisible(true);
	cookieButton.setVisible(true);

	textLevel.invalidate();
	boxProgress1.invalidate();
	textArea1.invalidate();
	background.invalidate();
	cookieButton.invalidate();


}


