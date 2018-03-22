//
//  main.cpp
//  ForStudy
//
//  Created by Cao Bui on 16/03/2018.
//  Copyright © 2018 Thi Thao Tien. All rights reserved.
//  Convert file using function

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
using namespace std;



struct Student{
    int id_student;
    string lastname;
    string forename;
    float math_score;
    float physic_score;
    float chemistry_score;
};
void fn_writer(string file_name, Student student_container[], int& number_student_in_tab){
    fstream output_student;
    output_student.open(file_name, ios::app);
    //output_student << "Id_Student" << " " << "Lastname" << " " << "Forename" <<" " << "Math"<< " "<< "Physic" <<" "<< "Chemistry" << endl;
    for (int i(0); i<number_student_in_tab; i++) {
        output_student << student_container[i].id_student << " " << student_container[i].lastname << " " << student_container[i].forename << " " << student_container[i].math_score<< " " << student_container[i].physic_score<< " " << student_container[i].chemistry_score << endl;
    }
};
void search_student_byID(Student list_student[], int& number_student_in_list_origin, int id_student){
    int id_in_tab(0);
    bool is_exist(false);
    for (int i(0); i< number_student_in_list_origin; i++) {
        if (list_student[i].id_student==id_student) {
            id_in_tab = i;
            is_exist=true;
            break;
        }
    }
    if(is_exist){
        cout << "ID :" << list_student[id_in_tab].id_student << endl;
        cout << "Lastname :" << list_student[id_in_tab].lastname << endl;
        cout << "Forename :" << list_student[id_in_tab].forename << endl;
        cout << "Math score :" << list_student[id_in_tab].math_score<< endl;
        cout << "Physic score :" << list_student[id_in_tab].physic_score<< endl;
        cout << "Chemistry score :" << list_student[id_in_tab].chemistry_score << endl;
    }else{
        cout << "Your id does not exist!" << endl;
    }
};
void search_student_by_lastname(Student list_student[], int& number_student_in_list_origin, string lastname){
    int number_existant(0);
    Student array_student_found[5];
    bool is_exist(false);
    for (int i(0); i< number_student_in_list_origin; i++) {
        if (list_student[i].lastname==lastname) {
            array_student_found[number_existant]=list_student[i];
            is_exist=true;
            number_existant++;
        }
    }
    if(is_exist){
        for (int i(0); i< number_existant; i++) {
            cout << "ID :" << array_student_found[i].id_student << endl;
            cout << "Lastname :" << array_student_found[i].lastname << endl;
            cout << "Forename :" << array_student_found[i].forename << endl;
            cout << "Math score :" << array_student_found[i].math_score<< endl;
            cout << "Physic score :" << array_student_found[i].physic_score<< endl;
            cout << "Chemistry score :" << array_student_found[i].chemistry_score << endl;
        }
    }else{
        cout << "This lastname does not exist!" << endl;
    }

    
};
void fn_insert(){};
bool fn_verify_is_int(string input_student){
    bool is_int(true);
    for (int i(0); i< input_student.length(); i++) {
        if (!isdigit(input_student[i])) {
            is_int = false;
        }
    }
    return is_int;
}
void test_id(string input_student, Student student_container[], int& number_student){
    while (!fn_verify_is_int(input_student)) {
        cout << "The id is a number, please refill :" << endl;
        getline(cin, input_student);
    }
    int input(0);
    input = atoi(input_student.c_str());
    student_container[number_student].id_student= input;
};
bool fn_verify_is_float(string input_student){
    bool is_float(true);
    for (int i(0); i< input_student.length(); i++) {
        if (!isdigit(input_student[i])) {
            if (input_student[i]!='.') {
                is_float= false;
            }
        }
    }
    return is_float;
};
float test_score(string input_student){
    while (!fn_verify_is_float(input_student) || atof(input_student.c_str()) < 0 || atof(input_student.c_str()) >20) {
        cout << "The score is a number, higher than 0 and lower than 20, please refill :" << endl;
        getline(cin, input_student);
    }
    float input(0.f);
    input = atof(input_student.c_str());
    cout << input << endl;
    return input;
};
// Utiliser référence, au lieu de passer direct value de string
void fn_read_file(const string& file_name, Student list_student[], int& number_student_in_list_origin){
    fstream file_to_read;
    file_to_read.open(file_name, ios::in);
    while (!file_to_read.eof()) {
        string data("");
        int id(0);
        string lastname(""), forename("");
        float math_score(0.f), physic_score(0.f), chemistry_score(0.f);
        getline(file_to_read, data);
        istringstream info_student(data);
        info_student >> id >> lastname >> forename >> math_score >> physic_score >> chemistry_score;
        list_student[number_student_in_list_origin].id_student=id;
        list_student[number_student_in_list_origin].lastname= lastname;
        list_student[number_student_in_list_origin].forename=forename;
        list_student[number_student_in_list_origin].math_score=math_score;
        list_student[number_student_in_list_origin].physic_score=physic_score;
        list_student[number_student_in_list_origin].chemistry_score=chemistry_score;
        number_student_in_list_origin++;
    }
};
void fn_print_list_student(Student list_student[], int& number_student_in_list_origin){
    for (int i(0); i< number_student_in_list_origin; i++ ) {
        cout << "ID :" << list_student[i].id_student << endl;
        cout << "Lastname :" << list_student[i].lastname << endl;
        cout << "Forename :" << list_student[i].forename << endl;
        cout << "Math score :" << list_student[i].math_score<< endl;
        cout << "Physic score :" << list_student[i].physic_score<< endl;
        cout << "Chemistry score :" << list_student[i].chemistry_score << endl;
    }
};
int main(int argc, const char * argv[]) {
    string file_name("Resultat_Student.txt");
    //Student* student_container = (*) malloc(10*sizeof(Student));
    Student student_container[10];
    Student list_student[10];
    int number_student_in_tab(0);
    int number_student_in_list_origin(0);
    string choice("");
    string option1("");
    cout << "You want to insert data? Y for yes, N for No" << endl;
    getline(cin, choice);
    while (choice=="Y") {
        //Student newStudent;
        string input_student;
        cout << "Enter id of the student, please! :" << endl;
        getline(cin, input_student);
        test_id(input_student, student_container, number_student_in_tab);
        cout << "Enter LASTNAME of the student, please! :" << endl;
        getline(cin, student_container[number_student_in_tab].lastname);
        cout << "Enter FORENAME of the student, please! :" << endl;
        getline(cin, student_container[number_student_in_tab].forename);
        cout << "Enter MATH SCORE of the student, please! :" << endl;
        getline(cin, input_student);
        student_container[number_student_in_tab].math_score = test_score(input_student);
        cout << "Enter PHYSIC SCORE of the student, please! :" << endl;
        getline(cin, input_student);
        student_container[number_student_in_tab].physic_score = test_score(input_student);
        cout << "Enter CHEMISTRY SCORE of the student, please! :" << endl;
        getline(cin, input_student);
        student_container[number_student_in_tab].chemistry_score = test_score(input_student);
        //student_container[--number_student]= newStudent;
        number_student_in_tab++;
        cout << "You want to continue to insert? Y for yes, N for No" << endl;
        getline(cin, choice);
        
    }
    fn_writer(file_name, student_container, number_student_in_tab);
    cout << "You want to read the document then press 1" <<  endl;
    cout << "you're looking for a student then press 2" << endl;
    getline(cin, option1);
    if (option1=="1") {
        fn_read_file(file_name, list_student, number_student_in_list_origin);
        fn_print_list_student(list_student, number_student_in_list_origin);
    }
    else if (option1=="2"){
        string option2("");
        cout << "You want to search by ID then press 1" << endl;
        cout << "You want to search by LASTNAME then press 2" << endl;
        getline(cin, option2);
        if (option2=="1") {
            string id_string("");
            cout << "Enter the id of student" << endl;
            getline(cin, id_string);
            int id_int = atoi(id_string.c_str());
            fn_read_file(file_name, list_student, number_student_in_list_origin);
            search_student_byID(list_student, number_student_in_list_origin, id_int);

        }
        else if(option2=="2"){
            string lastname_string("");
            cout << "Enter the LASTNAME of student" << endl;
            getline(cin, lastname_string);
            fn_read_file(file_name, list_student, number_student_in_list_origin);
            search_student_by_lastname(list_student, number_student_in_list_origin, lastname_string);

        }
    }
    
    return 0;
    }
