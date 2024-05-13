// 18463339 Ndumezulu Ngwenya
#include <iostream>
#include <fstream>
#include <queue>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

// Define Patient structure
struct Patient {
    char type; // 'W' for wound, 'A' for adult, 'C' for children
    int timeSpent; // Time patient spends with nurse
};

// Function to simulate patient queue system
void simulate(const string& filename, int duration) {
    // Initialize queues for each nurse
    queue<Patient> woundQueue;
    queue<Patient> adultQueue;
    queue<Patient> childrenQueue;

    // Open file
    ifstream data(filename);
    if (!data.is_open()) {
        cout << "Error opening file!" << endl;
        return;
    }

    // Read data from file and enqueue patients
    string line;
    bool woundTimeSpentIsOne = false; // Flag for wound patients
    bool adultTimeSpentIsOne = false; // Flag for adult patients
    bool childrenTimeSpentIsOne = false; // Flag for children patients
    while (getline(data, line)) {
        char type;
        int arrivalTime, timeSpent;
        // Parse line
        sscanf(line.c_str(), "%d,%c,%d", &arrivalTime, &type, &timeSpent);
        // Create patient
        Patient patient = {type, timeSpent};
        // Enqueue patient based on type
        switch (type) {
            case 'W':
                woundQueue.push(patient);
                if (timeSpent == 1) {
                    woundTimeSpentIsOne = true; // Set the flag
                }
                break;
            case 'A':
                adultQueue.push(patient);
                if (timeSpent == 1) {
                    adultTimeSpentIsOne = true; // Set the flag
                }
                break;
            case 'C':
                childrenQueue.push(patient);
                if (timeSpent == 1) {
                    childrenTimeSpentIsOne = true; // Set the flag
                }
                break;
            default:
                cout << "Invalid patient type: " << type << endl;
                break;
        }
    }

    // Close file
    data.close();

    // Simulation loop
    cout << "Time count\tWound\tAdult\tChildren" << endl;
    for (int time = 0; time <= duration; ++time) {
        cout << "\t" << time << "\t";

        // Process wound patients
        if (!woundQueue.empty()) {
            if (!woundTimeSpentIsOne) {
                cout << "1(" << woundQueue.front().timeSpent << ")\t";
                if (--woundQueue.front().timeSpent <= 0) {
                    woundQueue.pop(); // Remove patient from queue if timeSpent reaches 0
                }
            } else {
                cout << "0\t"; // Output zero if time spent is 1 for a 'W' patient
            }
        } else {
            cout << "0\t";
        }

        // Process adult patients
        if (!adultQueue.empty()) {
            if (!adultTimeSpentIsOne) {
                cout << "1(" << adultQueue.front().timeSpent << ")\t";
                if (--adultQueue.front().timeSpent <= 0) {
                    adultQueue.pop(); // Remove patient from queue if timeSpent reaches 0
                }
            } else {
                cout << "0\t"; // Output zero if time spent is 1 for an 'A' patient
            }
        } else {
            cout << "0\t";
        }

        // Process children patients
        if (!childrenQueue.empty()) {
            if (!childrenTimeSpentIsOne) {
                cout << "1(" << childrenQueue.front().timeSpent << ")\t";
                if (--childrenQueue.front().timeSpent <= 0) {
                    childrenQueue.pop(); // Remove patient from queue if timeSpent reaches 0
                }
            } else {
                cout << "0\t"; // Output zero if time spent is 1 for a 'C' patient
            }
        } else {
            cout << "0\t";
        }

        cout << endl;
        // Reset the flags when encountering another patient of each type
        if (!woundQueue.empty() && woundQueue.front().type == 'W') {
            woundTimeSpentIsOne = false;
        }
        if (!adultQueue.empty() && adultQueue.front().type == 'A') {
            adultTimeSpentIsOne = false;
        }
        if (!childrenQueue.empty() && childrenQueue.front().type == 'C') {
            childrenTimeSpentIsOne = false;
        }
    }
}

int main() {
    srand(time(0));

    const string filename = "c:\\data\\dataclient.txt";
    int duration = 22;

    simulate(filename, duration);

    return 0;
}
