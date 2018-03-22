//
//  main.cpp
//  ForStudy
//
//  Created by Cao Bui on 16/03/2018.
//  Copyright © 2018 Thi Thao Tien. All rights reserved.
//
// Input file, output file, command line tool
/*
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int main(int argc, const char * argv[]) {
    if (argc != 3){
        cout << "You need to pass the two arguments of input and output files in order!" << endl;
        return 0;
    }
    string input_file_name = argv[1];
    cout << input_file_name << endl;
    string output_file_name = argv[2];
    cout << output_file_name << endl;
    
    
    //    string input_file_name = "/Users/caobui/Desktop/NoteUTT.txt";
    ifstream note_utt;
    note_utt.open(input_file_name,ios::in);
    vector<float> note_vector(NULL);
    float note_sum(0.f);
    string data("");
    float note_average(0.f);
    float note(0.f);
    while (!note_utt.eof()) {
        getline(note_utt,data);
        note= atof(data.c_str());
        note_vector.push_back(note);
    }
    note_utt.close();
    for (int i(0); i<note_vector.size(); i++) {
        cout << note_vector[i] << endl;
        note_sum+=note_vector[i];
    }
    note_average =note_sum/note_vector.size();
    cout << "noteAverage is : " << note_average << endl;
    
    //    string output_file_name = "/Users/caobui/Desktop/NoteUTT_Classed.txt";
    ofstream output_note_utt;
    output_note_utt.open(output_file_name, ios::out);
    output_note_utt << note_average << endl;
    for (int i(0); i<note_vector.size(); i++) {
        if (note_vector[i] >= note_average){
            string output_data = to_string(note_vector[i]) + " -> Pass";
            output_note_utt << output_data << endl;
        }
        else{
            string output_data = to_string(note_vector[i]) + " -> Rated";
            output_note_utt << output_data << endl;
        }
    }
    output_note_utt.close();
    
    return 0;
}
 */
