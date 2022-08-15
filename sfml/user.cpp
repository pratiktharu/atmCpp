#include "user.h"

void user::initVariables()
{
	//loading font...
	if (!this->font.loadFromFile("res/courier_new.ttf")) {
		cout << "Font can't be loaded...";
	}
}

user::user()
{
	this->initVariables();
}

void user::makeBuffer(string userName)
{
	//opening database file to read only...
	ifstream db("res/dbase.txt");	
	if (!db.is_open() ) {
		cout << "Couldn't open dbase.txt file" << endl;
		exit(1);
	}

	//opening buffer file to write...
	ofstream buf("res/buffer.txt");
	if (!buf.is_open()) {
		cout << "Couldn't open buffer.txt file" << endl;
		exit(1);
	}

	string line;

	while (!db.eof())
	{
		getline(db, line);	//reading from db...
		cout << " userName = " << userName<<endl;
		if (line.find(userName) != std::string::npos)
		{//if line contains user name then....
			buf << line;	//writing in db...
			break;
		}
	}
	cout << "line = " << line << endl;

	//closing files...
	db.close();
	buf.close();
}

bool user::authenticate(string pin)
{
	//opening buffer file to read only...
	ifstream buf("res/buffer.txt");
	if (!buf.is_open()) {
		cout << "Couldn't open buffer.txt file" << endl;
		exit(1);
	}

	string line;
	getline(buf, line);

	if (line.find(pin) != std::string::npos) 
	{//if line contains pin then...
		buf.close();
		return true;
	}
	buf.close();
	return false;
}

void user::showBalance()
{
	//opening buffer file to read only...
	ifstream buf("res/buffer.txt");
	if (!buf.is_open()) {
		cout << "Couldn't open buffer.txt file" << endl;
		exit(1);
	}

	buf >> this->amount; //this will give 1st wrd of buffer which is balance...
	
	this->balance.setFont(this->font);
	this->balance.setString(this->amount);
	this->balance.setPosition(610, 329);
	this->balance.setCharacterSize(40);
	this->balance.setFillColor(sf::Color::Green);
}

