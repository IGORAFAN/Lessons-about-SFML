#pragma once

#include<chrono>
#include<iostream>
using namespace std;

class TimeOfWorkPrograms {
private:
	chrono::time_point<chrono::steady_clock> start;
	chrono::time_point<chrono::steady_clock> stop;
	chrono::duration<float> duration;
public:
	TimeOfWorkPrograms(){
		start = chrono::high_resolution_clock::now();
	}

	void showTime() {
		duration = stop - start;
		cout << " Time - " << duration.count() << endl;
	}

	~TimeOfWorkPrograms() {
		stop = chrono::high_resolution_clock::now();
		showTime();
	}
};