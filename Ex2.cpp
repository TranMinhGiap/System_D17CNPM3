#include<bits/stdc++.h>
#include<ctime>
#include<random>
#include <conio.h>
#include<cstdlib>
#include<windows.h>
using namespace std;

void loop() {
    char ch;
    while (true) {
        ch = _getch();
        if (ch == 27) {
            cout << endl << "Successfull !";
            break;
        }
        cout << endl << "Your Enter : " << ch << endl;
    }
}


void Ex1(){
	time_t now = time(nullptr);
    tm* localTime = localtime(&now);
    char buffer[100];
    strftime(buffer, sizeof(buffer), "%d/%m/%Y", localTime);
    cout << "Day : " << buffer << endl;
}

void Ex2(){
	random_device rd; 
    mt19937 gen(rd()); 
    uniform_real_distribution<> dis_real(0.0, 1.0);
    double random_real = dis_real(gen);
    cout << "Random [0, 1]: " << random_real << endl;
} 

void Ex3(){
	Beep(1000, 500); 
}

void Ex4(){
	cout << endl << "Input char or ESC to break : ";
	loop();
}

void Ex5(){
	random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 1000); 

    priority_queue<int, vector<int>, greater<int>> q;

    while (true) {
        int num = dis(gen);
        q.push(num);
        if (q.size() > 3) {
            q.pop();
        }
        cout << "Max Present : ";
        priority_queue<int, vector<int>, greater<int>> tmp = q;
        while (!tmp.empty()) {
            cout << tmp.top() << endl;
            tmp.pop();
        }
        cout << endl;
        this_thread::sleep_for(chrono::seconds(1));
    }
}

void Ex6(){
	char ch;
    while(true) {
        if (_kbhit()) {
            ch = _getch();
            if (ch == 27) {
                cout << "ESC pressed, exiting..." << endl;
                break;
            } else {
                cout << "Hexa code of '" << ch << "' is: " << hex << (int)ch << endl;
            }
        }
    }
}

void Ex7(){
	int num;
    cout << "Enter an integer: ";
    cin >> num;
    cout << "Binary representation: ";
    for (int i = 31; i >= 0; i--) {
        cout << ((num >> i) & 1);
    }
    cout << endl;
}
void Ex8(){
	int num;
    cout << "Enter an integer: ";
    cin >> num;
    cout << "Hexadecimal : " << hex << num << endl;
}

int main(){
	Ex1();
	Ex2();
	Ex3();
	Ex4();
	Ex5();
	Ex6();
	Ex7();
	Ex8();
	return 0;
} 
