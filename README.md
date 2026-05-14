so here we will type the main structure of the project.

# School Management System

A console-based School Management System developed in C using file handling (`.txt` files).

---

# 📌 Features

## 🔐 Login System
- Separate login for:
  - Admin
  - Teacher
  - Student
- Retry option for invalid login
- Back option to return to menu
- Password validation

---

# 👨‍💼 Admin Features

- Create Teacher
- Edit Teacher
- Delete Teacher

- Create Student
- Edit Student
- Delete Student

- Assign Subject to Teacher

- View All Teachers
- View All Students

- View Attendance
- View Grades

- Change Password

---

# 👨‍🏫 Teacher Features

- View Profile
- Edit Profile

- Add Grades
  - Only for assigned subject

- Take Attendance
  - Only for assigned subject

- Handle Reports
  - View student reports
  - Clear reports

- View Students
- View Attendance
- View Grades

- Change Password

---

# 👨‍🎓 Student Features

- View Profile
- Edit Profile

- View Grades
- View Attendance
  - Includes attendance percentage

- Send Report

- Change Password

---

# 📂 Project Structure

```txt
SchoolManagement/

│
├── main.c
├── login.c
├── admin.c
├── teacher.c
├── student.c
├── attendance.c
├── grades.c
├── reports.c
├── password.c
├── file.c
├── utility.c
│
├── login.h
├── admin.h
├── teacher.h
├── student.h
├── attendance.h
├── grades.h
├── reports.h
├── file.h
├── utility.h
│
├── data/
│     ├── admin.txt
│     ├── teachers.txt
│     ├── students.txt
│     ├── grades.txt
│     ├── attendance.txt
│     └── reports.txt
│
└── README.md
```

---

# ⚙️ Functions by File

## `main.c`

```c
void main();
```

---

## `login.c`

```c
int adminLogin();
int teacherLogin();
int studentLogin();

void loginMenu();

int validateAdmin(char username[], char password[]);
int validateTeacher(char username[], char password[]);
int validateStudent(char username[], char password[]);
```

---

## `admin.c`

```c
void adminMenu();

void createTeacher();
void editTeacher();
void deleteTeacher();

void createStudent();
void editStudent();
void deleteStudent();

void viewAllTeachers();
void viewAllStudents();

void viewAttendance();
void viewGrades();

void assignSubject();

void changeAdminPassword();
```

---

## `teacher.c`

```c
void teacherMenu();

void viewTeacherProfile();
void editTeacherProfile();

void addGrades();

void takeAttendance();

void handleReports();

void viewStudents();

void teacherViewAttendance();
void teacherViewGrades();

void changeTeacherPassword();
```

---

## `student.c`

```c
void studentMenu();

void viewStudentProfile();
void editStudentProfile();

void viewStudentGrades();
void viewStudentAttendance();

void sendReport();

void changeStudentPassword();
```

---

## `attendance.c`

```c
void markAttendance();

void saveAttendance();

void viewAttendanceByStudent();

float calculateAttendancePercentage();

void updateAttendance();
```

---

## `grades.c`

```c
void addGrade();

void saveGrade();

void editGrade();

void deleteGrade();

void viewGrades();

float calculateAverageGrade();
```

---

## `reports.c`

```c
void createReport();

void viewReports();

void clearReport();

void saveReport();
```

---

## `password.c`

```c
void changePassword();

int verifyOldPassword();

int validatePasswordStrength();
```

---

## `file.c`

```c
void saveTeacherData();
void loadTeacherData();

void saveStudentData();
void loadStudentData();

void appendData();

void deleteData();

void updateData();
```

---

## `utility.c`
this is for PratikGrx only

```c
void clearScreen();

void pauseScreen();

void printLine();

int generateID();

void loadingAnimation();

void invalidChoice();

void successMessage();
```

---