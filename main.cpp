#include <iostream>
#include <string>
#include <vector>
#include <regex>
#include <ctime>
#include <fstream>

using namespace std;

/*Global variable to define how many ID's we can get*/
const int ID = 1000000;

int char_to_int(char c)
{
	return c - '0';
}

char int_to_char(int a)
{
	return a + '0';
}

struct Train;
//bool check_entering_data();

bool check_id(vector<Train>& data, int id);

int get_random_id();

string get_random_option();

string get_random_type();


/*All nessecary structures for data base*/
struct date
{
	int hour = 0;
	int minute = 0;
	int day = 0;
	int month = 0;
	int year = 0;
};

date get_random_arival_date(date depart);

date get_random_departure_date();

double get_random_popularity();

struct Train
{
	int id;
	int number_of_train;
	string option;
	string type;
	date depart;
	date arrive;
	double popularity;
	
	Train()
	{
		id = 0;
		number_of_train = 0;
		option = "";
		type= "";
		depart = {0, 0, 0, 0, 0,};
		arrive = { 0, 0, 0, 0, 0, };
		popularity = 0.0;
	}
	
	Train(vector<Train> data)
	{
		id = get_random_id();
		while (!check_id(data, id))
		{
			id = get_random_id();
		}
		number_of_train = data.size();
		option = get_random_option();
		type = get_random_type();
		depart = get_random_departure_date();
		arrive = get_random_arival_date(depart);
		popularity = get_random_popularity();
	}
};

void add_element(vector<Train>& data)
{
	Train new_element;
	string random;

	cout << "Choose <0> to enter the data or <1> to generate ID: ";
	cin >> random;
	while (cin)
	{
		if (random == "0")
		{
			cout << "Enter ID of train: ";
			cin >> new_element.id;
			cout << endl;
			//check
			break;
		}

		else if (random == "1")
		{

			new_element.id = get_random_id();
			while (!check_id(data, new_element.id))
			{
				new_element.id = get_random_id();
			}
			break;
		}

		else
		{
			cout << "Incorrect data!" << endl;
			cin >> random;
		}
	}

	new_element.number_of_train = data.size();

	cout << "Choose <0> to enter the data or <1> to generate option: ";
	cin >> random;
	while (cin)
	{
		if (random == "0")
		{
			cout << "Enter the option of train: ";
			cin >> new_element.option;
			cout << endl;
			//check
			break;
		}

		else if (random == "1")
		{
			new_element.option = get_random_option();
			//check
			break;
		}

		else
		{
			cout << "Incorrect data!" << endl;
			cin >> random;
		}
	}

	cout << "Choose <0> to enter the data or <1> to generate type: ";
	cin >> random;
	while (cin)
	{
		if (random == "0")
		{
			cout << "Choose one of the types of trains: " << endl;
			cout << "<0> - international;" << endl;
			cout << "<1> - rapid;" << endl;
			cout << "<2> - suburban;" << endl;
			cout << "<3> - conventional;" << endl;

			char enter;
			cin >> enter;

			switch (enter)
			{
			case '0': new_element.type = "international"; break;
			case '1': new_element.type = "rapid"; break;
			case '2': new_element.type = "suburban"; break;
			case '3': new_element.type = "conventional"; break;
			}
			cout << endl;
			//check
			break;
		}

		else if (random == "1")
		{
			new_element.type = get_random_type();
			//check
			break;
		}

		else
		{
			cout << "Incorrect data!" << endl;
			cin >> random;
		}
	}
	//

	while (cin)
	{
		if (random == "0")
		{
			cout << "Enter ID of train: ";
			cin >> new_element.id;
			cout << endl;
			//check
			break;
		}

		else if (random == "1")
		{
			new_element.id = get_random_id();
			//check
			break;
		}

		else
		{
			cout << "Incorrect data!" << endl;
			cin >> random;
		}
	}

	cout << "Choose <0> to enter the data or <1> to generate departure date: ";
	cin >> random;
	while (cin)
	{
		if (random == "0")
		{
			cout << "Enter the departure date of train" << endl;

			cout << "Year: ";
			cin >> new_element.depart.year;
			cout << endl;

			cout << "Month: ";
			cin >> new_element.depart.month;
			cout << endl;

			cout << "Day: ";
			cin >> new_element.depart.day;
			cout << endl;

			cout << "Hour: ";
			cin >> new_element.depart.hour;
			cout << endl;

			cout << "Minute: ";
			cin >> new_element.depart.minute;
			cout << endl;
			//check
			break;
		}

		else if (random == "1")
		{
			new_element.depart = get_random_departure_date();
			//check
			break;
		}

		else
		{
			cout << "Incorrect data!" << endl;
			cin >> random;
		}
	}

	cout << "Choose <0> to enter the data or <1> to generate arival date: ";
	cin >> random;
	while (cin)
	{
		if (random == "0")
		{
			cout << "Enter the arrival date of train" << endl;

			cout << "Year: ";
			cin >> new_element.arrive.year;
			cout << endl;

			cout << "Month: ";
			cin >> new_element.arrive.month;
			cout << endl;

			cout << "Day: ";
			cin >> new_element.arrive.day;
			cout << endl;

			cout << "Hour: ";
			cin >> new_element.arrive.hour;
			cout << endl;

			cout << "Minute: ";
			cin >> new_element.arrive.minute;
			cout << endl;
			cout << endl;
			//check
			break;
		}

		else if (random == "1")
		{
			new_element.arrive = get_random_arival_date(new_element.depart);
			//check
			break;
		}

		else
		{
			cout << "Incorrect data!" << endl;
			cin >> random;
		}
	}

	cout << "Choose <0> to enter the data or <1> to generate popularity: ";
	cin >> random;
	while (cin)
	{
		if (random == "0")
		{
			cout << "Enter the popularity of train: ";
			cin >> new_element.popularity;
			cout << endl;
			//check
			break;
		}

		else if (random == "1")
		{
			new_element.popularity = get_random_popularity();
			//check
			break;
		}

		else
		{
			cout << "Incorrect data!" << endl;
			cin >> random;
		}
	}

	data.push_back(new_element);
}

void add_element(vector<Train>& data, Train train)
{
	data.push_back(train);
}

void print_data(vector<Train>& data)
{
	for (size_t i = 0; i < data.size(); i++)
	{
		cout << "Train №" << i + 1 << endl;
		cout << "ID: " << data[i].id << endl;
		cout << "Number of train: " << data[i].number_of_train << endl;
		cout << "Option of train: " << data[i].option << endl;
		cout << "Type of train: " << data[i].type << endl;
		cout << "Departure date: " << data[i].depart.day << "." << data[i].depart.month << "." << data[i].depart.year << "	";
		cout << data[i].depart.hour << ":" << data[i].depart.minute << endl;
		cout << "Arrival date: " << data[i].arrive.day << "." << data[i].arrive.month << "." << data[i].arrive.year << "	";
		cout << data[i].arrive.hour << ":" << data[i].arrive.minute << endl;
		cout << "Popularity: " << data[i].popularity * 100 << "%" << endl;
		cout << endl;
	}
}

void print_data(vector<Train>& data, vector<int>& indexes)
{
	for (size_t i = 0; i < indexes.size(); i++)
	{
		cout << "Train №" << i + 1 << endl;
		cout << "ID: " << data[indexes[i]].id << endl;
		cout << "Number of train: " << data[indexes[i]].number_of_train << endl;
		cout << "Option of train: " << data[indexes[i]].option << endl;
		cout << "Type of train: " << data[indexes[i]].type << endl;
		cout << "Departure date: " << data[indexes[i]].depart.day << "." << data[indexes[i]].depart.month << "." << data[indexes[i]].depart.year << "	";
		cout << data[indexes[i]].depart.hour << ":" << data[indexes[i]].depart.minute << endl;
		cout << "Arrival date: " << data[indexes[i]].arrive.day << "." << data[indexes[i]].arrive.month << "." << data[indexes[i]].arrive.year << "	";
		cout << data[indexes[i]].arrive.hour << ":" << data[indexes[i]].arrive.minute << endl;
		cout << "Popularity: " << data[indexes[i]].popularity * 100 << "%" << endl;
		cout << endl;
	}
}

bool check_id(vector<Train>& data, int id)
{
	if (!data.empty())
	{
		for (size_t i = 0; i < data.size(); i++)
		{
			if (data[i].id == id)
			{
				return false;
			}
		}
		return true;
	}
	else
	{
		return true;
	}
}
//struct Station;

int get_random_id()
{
	//srand(time(NULL));
	return rand() * rand() % ID;
}
/*Functions for searching*/

string get_random_option()
{
	//srand(time(NULL));
	string option;
	int length = rand() % 10 + 1;
	int begin = rand() % 2;
	
	string vowels = "qwrtpsdfghjklzxcvbnm";
	string consonants = "eyuioa";


	for (int i = 0; i < length; i++)
	{
		if (begin == 0)
		{
			int letter = rand() % vowels.length();
			option += vowels[letter];
			begin = 1;
		}

		else
		{
			int letter = rand() % consonants.length();
			option += consonants[letter];
			begin = 0;
		}
	}
	return option;
}

string get_random_type()
{
	//srand(time(NULL));
	string type;

	int i = rand() % 4;
	switch (i)
	{
	case 0: type = "international"; break;
	case 1: type = "rapid"; break;
	case 2: type = "suburban"; break;
	case 3: type = "conventional"; break;
	}
	return type;
}

date get_random_departure_date()
{
	//srand(time(NULL));
	date depart;
	
	depart.year = rand() % 5 + 2020;
	depart.month = rand() % 12 + 1;

	switch (depart.month)
	{
	case 1: depart.day = rand() % 31 + 1; break;
	case 2:
		if (depart.year % 4 == 0)
		{
			depart.day = rand() % 29 + 1;
		}

		else
		{
			depart.day = rand() % 28 + 1;
		} break;
	case 3: depart.day = rand() % 31 + 1; break;
	case 4: depart.day = rand() % 30 + 1; break;
	case 5: depart.day = rand() % 31 + 1; break;
	case 6: depart.day = rand() % 30 + 1; break;
	case 7: depart.day = rand() % 31 + 1; break;
	case 8: depart.day = rand() % 31 + 1; break;
	case 9: depart.day = rand() % 30 + 1; break;
	case 10: depart.day = rand() % 31 + 1; break;
	case 11: depart.day = rand() % 30 + 1; break;
	case 12: depart.day = rand() % 31 + 1; break;
	}

	depart.hour = rand() % 24;
	depart.minute = rand() % 60;

	return depart;
}

date get_random_arival_date(date depart)
{
	//srand(time(NULL));
	date arrive;
	
	bool year = 0;
	if (depart.month == 12)
	{
		year = rand() % 2;
	}

	arrive.year = depart.year + year;

	arrive.month = depart.month + rand() % 2;
	if (arrive.month == 13)
	{
		arrive.month = 1;
	}

	if (depart.month == arrive.month)
	{
		switch (arrive.month)
		{
		case 1: arrive.day = depart.day + rand() % (31 - depart.day + 1); break;
		case 2:
			if (arrive.year % 4 == 0)
			{
				arrive.day = depart.day + rand() % (29 - depart.day + 1);
			}

			else
			{
				arrive.day = depart.day + rand() % (28 - depart.day + 1);
			} break;
		case 3: arrive.day = depart.day + rand() % (31 - depart.day + 1); break;
		case 4: arrive.day = depart.day + rand() % (30 - depart.day + 1); break;
		case 5: arrive.day = depart.day + rand() % (31 - depart.day + 1); break;
		case 6: arrive.day = depart.day + rand() % (30 - depart.day + 1); break;
		case 7: arrive.day = depart.day + rand() % (31 - depart.day + 1); break;
		case 8: arrive.day = depart.day + rand() % (31 - depart.day + 1); break;
		case 9: arrive.day = depart.day + rand() % (30 - depart.day + 1); break;
		case 10: arrive.day = depart.day + rand() % (31 - depart.day + 1); break;
		case 11: arrive.day = depart.day + rand() % (30 - depart.day + 1); break;
		case 12: arrive.day = depart.day + rand() % (31 - depart.day + 1); break;
		}
	}
	else
	{
		switch (arrive.month)
		{
		case 1: arrive.day = rand() % 31 + 1; break;
		case 2:
			if (arrive.year % 4 == 0)
			{
				arrive.day = rand() % 29 + 1;
			}

			else
			{
				arrive.day = rand() % 28 + 1;
			} break;
		case 3: arrive.day = rand() % 31 + 1; break;
		case 4: arrive.day = rand() % 30 + 1; break;
		case 5: arrive.day = rand() % 31 + 1; break;
		case 6: arrive.day = rand() % 30 + 1; break;
		case 7: arrive.day = rand() % 31 + 1; break;
		case 8: arrive.day = rand() % 31 + 1; break;
		case 9: arrive.day = rand() % 30 + 1; break;
		case 10: arrive.day = rand() % 31 + 1; break;
		case 11: arrive.day = rand() % 30 + 1; break;
		case 12: arrive.day = rand() % 31 + 1; break;
		default: break;
		}
	}

	if (arrive.day == depart.day)
	{
		arrive.hour = depart.hour + rand() % (24 - depart.hour);
	}

	else
	{
		arrive.hour = rand() % 24;
	}


	if (arrive.hour == depart.hour)
	{
		arrive.minute = depart.minute + rand() % (60 - depart.minute);
	}

	else
	{
		arrive.minute = rand() % 60;
	}
	return arrive;
}

double get_random_popularity()
{
	//srand(time(NULL));
	double a = rand() % 200;
	a = a / 100;
	return a;
}

vector<int> findOption(vector<Train>& data, string name)
{
	vector<int> indexes;
	size_t length = name.length();

	for (size_t i = 0; i < data.size(); i++)
	{
		Train current = data[i];
		bool flag = true;

		for (size_t j = 0; j < length; j++)
		{
			if (name[j] != current.option[j])
			{
				flag = false;
				break;
			}
		}
		if (flag)
		{
			indexes.push_back(i);
		}
		flag = false;
	}
	return indexes;
}

vector<int> findNumber(vector<Train>& data, int number)
{
	vector<int> indexes;
	
	for (size_t i = 0; i < data.size(); i++)
	{
		Train current = data[i];
		
		if (current.number_of_train >= number)
		{
			indexes.push_back(i);
		}
	}
	return indexes;
}

vector<int> findPopularity(vector<Train>& data, double popularity)
{
	vector<int> indexes;

	for (size_t i = 0; i < data.size(); i++)
	{
		Train current = data[i];

		if (current.popularity <= popularity)
		{
			indexes.push_back(i);
		}
	}
	return indexes;
}

vector<int> findTime(vector<Train>& data, date date_min, date date_max)
{
	vector<int> indexes;

	for (size_t i = 0; i < data.size(); i++)
	{
		Train current = data[i];

		if (current.arrive.year > date_min.year && current.arrive.year < date_max.year)
		{
			indexes.push_back(i);
		}

		else if (current.arrive.year == date_min.year || current.arrive.year == date_max.year)
		{
			if (current.arrive.month > date_min.month && current.arrive.month < date_max.month)
			{
				indexes.push_back(i);
			}

			else if (current.arrive.month == date_min.month || current.arrive.month == date_max.month)
			{
				if (current.arrive.day > date_min.day && current.arrive.day < date_max.day)
				{
					indexes.push_back(i);
				}

				else if(current.arrive.day == date_min.day || current.arrive.day == date_max.day)
				{
					if (current.arrive.hour > date_min.hour && current.arrive.hour < date_max.hour)
					{
						indexes.push_back(i);
					}

					else if (current.arrive.hour == date_min.hour || current.arrive.hour == date_max.hour)
					{
						if (current.arrive.minute >= date_min.minute && current.arrive.minute <= date_max.minute)
						{
							indexes.push_back(i);
						}
					}
				}
			}
		}
	}
	return indexes;
}

/*
vector<int> findTrain(vector<Train> data, bool(*filter)(Train current)) 
{
	vector<int> indexes;
	for (int i = 0; i < data.size(); i++)
	{
		if (filter)
		{
			indexes.push_back(i);
		}
	}
}
*/
/*
vector<Train> basa
{
	{4, 4, "abc", "abc", {4, 5, 1, 2, 3}, {4, 5, 1, 2, 3}, 23.0},
	{4, 4, "abc", "abc", {4, 5, 1, 2, 3}, {4, 5, 1, 2, 3}, 23.0},
	{4, 4, "cba", "abc", {4, 5, 1, 2, 3}, {4, 5, 1, 2, 3}, 23.0},
	{4, 4, "asd", "abc", {4, 5, 1, 2, 3}, {4, 5, 1, 2, 3}, 23.0},
	{4, 4, "abc", "abc", {4, 5, 1, 2, 3}, {4, 5, 1, 2, 3}, 23.0}
};
*/
void write_data_to_text_file(string path,vector<Train>& data)
{
	ofstream file;
	file.open(path, ofstream::app);
	
	if (!file.is_open())
	{
		cout << "File isn't opened!" << endl;
	}
	else
	{
		for (size_t i = 0; i < data.size(); i++)
		{
			file << data[i].id << " ";
			file << data[i].number_of_train << " ";
			file << data[i].option << " ";
			file << data[i].type << " ";
			file << data[i].depart.day << "." << data[i].depart.month << "." << data[i].depart.year << " ";
			file << data[i].depart.hour << ":" << data[i].depart.minute << " ";
			file << data[i].arrive.day << "." << data[i].arrive.month << "." << data[i].arrive.year << " ";
			file << data[i].arrive.hour << ":" << data[i].arrive.minute << " ";
			file << data[i].popularity;
			file << endl;
		}
	}
	file.close();
}

Train get_train_from_string(string str)
{
	Train train;
	//size_t length = str.length();
	size_t i = 0;

	while (str[i] != ' ')
	{
		train.id *= 10;
		train.id += char_to_int(str[i]);
		i++;
	}
	i++;

	while (str[i] != ' ')
	{
		train.number_of_train *= 10;
		train.number_of_train += char_to_int(str[i]);
		i++;
	}
	i++;

	while (str[i] != ' ')
	{
		train.option += str[i];
		i++;
	}
	i++;

	switch (str[i])
	{
	case 'i':
		train.type = "international";
		i += 14;
		break;
	case 'r':
		train.type = "rapid";
		i += 6;
		break;
	case 's':
		train.type = "suburban";
		i += 9;
		break;
	case 'c':
		train.type = "conventional";
		i += 13;
		break;
	}

	while (str[i] != '.')
	{
		train.depart.day *= 10;
		train.depart.day += char_to_int(str[i]);
		i++;
	}
	i++;

	while (str[i] != '.')
	{
		train.depart.month *= 10;
		train.depart.month += char_to_int(str[i]);
		i++;
	}
	i++;

	while (str[i] != ' ')
	{
		train.depart.year *= 10;
		train.depart.year += char_to_int(str[i]);
		i++;
	}
	i++;

	while (str[i] != ':')
	{
		train.depart.hour *= 10;
		train.depart.hour += char_to_int(str[i]);
		i++;
	}
	i++;

	while (str[i] != ' ')
	{
		train.depart.minute *= 10;
		train.depart.minute += char_to_int(str[i]);
		i++;
	}
	i++;
	
	while (str[i] != '.')
	{
		train.arrive.day *= 10;
		train.arrive.day += char_to_int(str[i]);
		i++;
	}
	i++;

	while (str[i] != '.')
	{
		train.arrive.month *= 10;
		train.arrive.month += char_to_int(str[i]);
		i++;
	}
	i++;

	while (str[i] != ' ')
	{
		train.arrive.year *= 10;
		train.arrive.year += char_to_int(str[i]);
		i++;
	}
	i++;

	while (str[i] != ':')
	{
		train.arrive.hour *= 10;
		train.arrive.hour += char_to_int(str[i]);
		i++;
	}
	i++;

	while (str[i] != ' ')
	{
		train.arrive.minute *= 10;
		train.arrive.minute += char_to_int(str[i]);
		i++;
	}
	i++;

	while (str[i] != '.')
	{
		train.popularity *= 10;
		train.popularity += char_to_int(str[i]);
		i++;
	}
	i++;

	double k = 0.1;
	while (i < str.length())
	{
		train.popularity += k * char_to_int(str[i]);
		k /= 10;
		i++;
	}
	return train;
}

void read_data_from_text_file(string path, vector<Train>& data)
{
	ifstream file;
	file.open(path);
	
	if (!file.is_open())
	{
		cout << "File isn't opened!" << endl;
	}
	else
	{
		string str;
		while (!file.eof())
		{
			str = "";
			getline(file, str);
			if (str.empty())
			{
				break;
			}
			data.push_back(get_train_from_string(str));
		}
	}

	file.close();
}

int main()
{
	srand(time(NULL));
	vector<Train> data1;

	
	for (int i = 0; i < 2000; i++)
	{
		Train element(data1);
		data1.push_back(element);
	}
	
	write_data_to_text_file("data.txt", data1);
	//read_data_from_text_file("data.txt", data1);
	//data1.push_back(get_train_from_string());
	//vector<int> indexes = findPopularity(data1, 1.0);
	//print_data(data1, indexes);
	//cout << endl;
	//print_data(data1);
	//cout << random;

}
