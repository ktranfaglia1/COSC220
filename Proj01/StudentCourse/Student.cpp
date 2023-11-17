/* Kyle Tranfaglia
 * COSC220 - Project1 - Ex.2
 * 03/13/2023
 * Student Object Implementation
*/
#include "Student.h"

// Default Constructor
Student::Student() {
    id = 0;
    name = "";
    array = nullptr;
    courseAmount = 0;
    courseCapacity = 0;
}
// Destructor 
Student:: ~Student() {
    delete [] array;
}
// Constructor
Student::Student(int num, string nm) {
    id = num;
    name = nm;
    array = nullptr;
    courseAmount = 0;
    courseCapacity = 0;
}
// Copy constructor
Student::Student(const Student &obj) {
    id = obj.id;
    name = obj.name;
    courseAmount = obj.courseAmount;
    courseCapacity = obj.courseCapacity;

    array = new Course[courseCapacity]; // Dynamically allocates memory to object
    // Copies the elements of right object to indexes of left object
    for (int i = 0; i < courseAmount; i++)
        array[i] = obj.array[i];
}
// Function to add a course to the course pointer array and increases the size of the array if not enough memory is allocated
void Student::addCourse(Course c) {
    // Dynamically allocates memory for array if none exists
    if (courseCapacity == 0) {
        courseCapacity = 1;
        array = new Course[courseCapacity];
    }
    // Increases the capacity of the array by creating a new dynamically allocated array with double the size
    else if (courseAmount == courseCapacity) {
        courseCapacity *= 2;
        Course *biggerArray = new Course[courseCapacity]; // Creates dynamic memory array
		// For loop to transfer the old array to the new array by coping the elements until old array size and then filling the rest of the new array with 0s
		for (int i = 0; i < courseAmount; i++) {
			*(biggerArray + i) = *(array + i);
		} 
		delete [] array; // Frees to memeory set aside in heap for array to prevent memeory leak as the pointer will be moved away from this array
		array = biggerArray; // Moves pointer for .list to the newly created array of double the capacity
    }
    array[courseAmount++] = c; // Sets the index to the course and increments count
}
// Function to delete a course from the course array
void Student::deleteCourse(Course c) {
    int removeIndex = -1; // sets non index default value to index to remove
    // Loop to find course that matches what was specified to be removed and stores its index
    for (int i = 0; i < courseAmount; i++) {
        if (array[i].getCode() == c.getCode() && array[i].getName() == c.getName()) {
            removeIndex = i;
        }
    }
    // If a course was not identified to be deleted a message is provided, otherwise if the course to remove is the last
    // index, the size is simply decremented, or third, the array is reordered and the course to be deleted will be overwritten
    if (removeIndex == -1) {
        cout << "Could not indentify course in record...nothing was deleted" << endl;
    }
    else if (removeIndex == courseAmount -1) {
        courseAmount--;
    }
    else {
        // Overwrites the index to be removed with the next element and then repeats for the following index
        for (int i = removeIndex; i < courseAmount - 1; i++) {
            array[i] = array[i + 1];
        }
        courseAmount--;
    }
}
// Operator overload function for =
const Student Student::operator = (const Student &obj) {
    delete [] array;
    id = obj.id;
    name = obj.name;
    courseAmount = obj.courseAmount;
    courseCapacity = obj.courseCapacity;

    array = new Course[courseCapacity]; // Dynamically allocates memory to object
    // Copies the elements of right object to indexes of left object
    for (int i = 0; i < courseAmount; i++)
        array[i] = obj.array[i];

    return *this;
}
// Operator overload friend fucntion for << that provides a nice printed list of the student object while utilizing the << overload from the course class
ostream& operator << (ostream &strm, const Student &obj) {
    strm << "Id: " << obj.id << endl;
    strm << "Name: " << obj.name << endl;
    strm << "Courses Taken: " << obj.courseAmount << endl;
    // Captures each element of course array using ostream variable and utilizes the << overload from the course class
    for (int i = 0; i < obj.courseAmount; i++) 
        strm << obj.array[i];
    strm << endl;
    return strm;
}