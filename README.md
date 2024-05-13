# Patient-Queue-System
Objective: 

The objective of this C++ program is to simulate a patient queue system in a healthcare setting. The simulation involves three types of nurses, each specializing in wound care, adult patients, or children. The program tracks patient arrivals, assigns them to specific nurses when available, and simulates the time each patient spends with their respective nurse.

Components:

Patient Structure:
A Patient structure is defined to represent each patient. It includes information about the patient's speciality (wound, adult, or children) and the processing time, which represents the time the patient spends with the nurse.
Queue and Time Simulation:
Three separate queues are used to represent patients of different specialities (wound, adult, children).
The simulation runs for a specified time, and at each time step, there is a chance of a new patient arriving. If a new patient arrives, their speciality is assigned, and they are enqueued in the corresponding queue.
Patients are processed based on their arrival order. If a nurse is available, the next patient in the queue for that nurse is processed. The processing time is between 1 and 7 seconds.
Output Format:
The simulation results are presented in tabular format, where each row represents a time step and each column represents the count of patients in the queues for wound, adult, and children specialities.
The "Time count" column represents the simulation time.
For each speciality, the count of patients is displayed in the format "1 (time_left)" where "time_left" indicates the remaining time for the patient to be with the nurse.
