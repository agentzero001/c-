#include <iostream>
#include <thread>

using namespace std;

static bool finished = false;

void DoWork() {

    cout << "Thread id=" << this_thread::get_id() << endl;

    while (!finished)
    {
        cout << "working...\n";
        this_thread::sleep_for(1s);
    }
}

int main() { 
    thread worker(DoWork);

    cin.get();
    finished = true;
    worker.join();
    cout << "finished"  << endl;
    cout << "Thread id=" << this_thread::get_id() << endl;
    cin.get();

    return 0;
}