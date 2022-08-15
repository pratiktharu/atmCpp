#pragma once
#include<iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include<fstream>

using namespace sf;
using namespace std;

class user
{
protected:
	//text and font for pin password...
	Font font;		Text balance;
	string amount;

private:
	void initVariables();

public:
	user();

	//selecting user in screen0...
	void makeBuffer(string userName);

	//authentication...
	bool authenticate(string pin);

	//show balance...
	void showBalance();
};

