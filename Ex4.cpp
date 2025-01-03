#include<bits/stdc++.h>
#include <pthread.h>
#include <ctime>
#define COUNT 100
using namespace std;

int idx = 1;

void *fun_thread1(void *data)
{
    while(true){
        if(idx < 10){
            cout << endl << "dong : " << idx;
        }
        else{
            cout << endl << "dong : " << idx << " : ";
            ifstream file("E:/Exercise_6/System_Programming_D17CNPM3/txt.txt");
            if(!file.is_open()){
                cout << "Error: cannot open file 'vd.txt'" << endl;
                pthread_exit(NULL);
            }
            string line;
            while(getline(file, line)){
                cout << line << " ";
            }
            file.close();
            pthread_exit(NULL);
        }
        idx++;
    }
}

void *fun_thread2(void *data)
{
    while(true){
        if(idx < 20){
            cout << endl << "dong : " << idx;
        }
        else{
            cout << endl << "dong : " << idx << " : ";
            time_t now = time(nullptr);
            tm* localTime = localtime(&now);
            char buffer[100];
            strftime(buffer, sizeof(buffer), "%d/%m/%Y", localTime);
            cout << "Day : " << buffer << endl;
            pthread_exit(nullptr);
        }
        idx++;
    }
}

int main(int argc, char *argv[])
{
    int status;
    pthread_t thrd_1;
    pthread_t thrd_2;
    pthread_create(&thrd_1, NULL, fun_thread1, NULL);
    pthread_join(thrd_1, (void **)&status);
    pthread_create(&thrd_2, NULL, fun_thread2, NULL);
    pthread_join(thrd_2, (void **)&status);

    system("PAUSE");
    return 1;
}

