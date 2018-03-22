////
////  main.cpp
////  ForStudy
////
////  Created by Cao Bui on 16/03/2018.
////  Copyright © 2018 Thi Thao Tien. All rights reserved.
////  convert file 
//
//#include <iostream>
//#include <string>
//#include <fstream>
//#include <vector>
//#include <sstream>
//using namespace std;
//
//struct Quad {
//    vector<double> point0;
//    vector<double> point1;
//    vector<double> point2;
//    vector<double> point3;
//    
//};
//
//struct Triangle {
//    vector<double> point0;
//    vector<double> point1;
//    vector<double> point2;
//};
//
//Quad quadContainer[100] ;
//
//Triangle triangleContainer[100];
//
//int main(int argc, const char * argv[]) {
//    
//    string input_file_name("Quad.txt");
//    fstream quad;
//    string line("");
//    string form("");
//    double x(0.f), y(0.f), z(0.f);
//    int counter_Quad(0);
//    int counter_Array_Quad(0);
//    string output_file_names("Triangle.txt");
//    quad.open(input_file_name, ios::in);
//    fstream triagle;
//    while (!quad.eof()) {
//        getline(quad, line);
//        if (line == "Quad") {
//        }
//        else{
//            counter_Quad++;
//            istringstream output_string(line);
//            string a, b, c;
//            vector<double> point_output(NULL);
//            output_string >> a >> b >> c;
//            x= atof(a.c_str());
//            y= atof(b.c_str());
//            z= atof(c.c_str());
//            point_output.push_back(x);
//            point_output.push_back(y);
//            point_output.push_back(z);
//            
//            if (counter_Quad%4==1){
//                quadContainer[counter_Array_Quad].point0= point_output;
//            }
//            else if (counter_Quad%4==2){
//                quadContainer[counter_Array_Quad].point1= point_output;
//                
//            }
//            else if (counter_Quad%4==3){
//                quadContainer[counter_Array_Quad].point2= point_output;
//                
//            }
//            else if (counter_Quad%4==0){
//                counter_Array_Quad++;
//                quadContainer[counter_Array_Quad-1].point3= point_output;
//            }
//        }
//    }
//    quad.close();
//    int counter_array_tri(0);
//    for (int i(0); i<counter_Array_Quad; i++) {
//        Quad quad1 = quadContainer[i];
//        Triangle tri1= {quadContainer[i].point0, quadContainer[i].point1, quadContainer[i].point2};
//        Triangle tri2 = {quadContainer[i].point1, quadContainer[i].point2, quadContainer[i].point3};
//        triangleContainer[counter_array_tri]= tri1;
//        counter_array_tri+=2;
//        triangleContainer[--counter_array_tri]= tri2;
//    }
//    
//    triagle.open(output_file_names, ios::app);
//    triagle << "Triangle" << endl;
//    for (int i(0); i< counter_Array_Quad*2 ; i++) {
//        triagle << triangleContainer[i].point0[0] << " " << triangleContainer[i].point0[1] << " " << triangleContainer[i].point0[2] << endl;
//        triagle << triangleContainer[i].point1[0] << " " << triangleContainer[i].point1[1] << " " << triangleContainer[i].point1[2] << endl;
//        triagle << triangleContainer[i].point2[0] << " " << triangleContainer[i].point2[1] << " " << triangleContainer[i].point2[2] << endl;
//    }
//    triagle.close();
//    
//    return 0;
//}

/*
 struct Quad {
 vector<double> point0;
 vector<double> point1;
 vector<double> point2;
 vector<double> point3;
 
 };
 
 struct Triangle {
 vector<double> point0;
 vector<double> point1;
 vector<double> point2;
 };
 void fn_condition_for_reader(vector<double> point_output, Quad quadContainer[], int& counter_Quad, int& counter_Array_Quad){
 if (counter_Quad%4==1){
 quadContainer[counter_Array_Quad].point0= point_output;
 }
 else if (counter_Quad%4==2){
 quadContainer[counter_Array_Quad].point1= point_output;
 
 }
 else if (counter_Quad%4==3){
 quadContainer[counter_Array_Quad].point2= point_output;
 
 }
 else if (counter_Quad%4==0){
 counter_Array_Quad++;
 quadContainer[counter_Array_Quad-1].point3= point_output;
 }
 }
 void fn_reader(string input_file_name, Quad quadContainer[], int& counter_Quad, int& counter_Array_Quad){
 fstream file_reader;
 file_reader.open(input_file_name, ios::in);
 string data;
 while (!file_reader.eof()) {
 getline(file_reader, data);
 if (data == "Quad") {
 }
 else{
 counter_Quad++;
 istringstream output_string(data);
 string a, b, c;
 double x(0.f),y(0.f),z(0.f);
 vector<double> point_output(NULL);
 output_string >> a >> b >> c;
 x= atof(a.c_str());
 y= atof(b.c_str());
 z= atof(c.c_str());
 point_output.push_back(x);
 point_output.push_back(y);
 point_output.push_back(z);
 
 fn_condition_for_reader(point_output, quadContainer, counter_Quad, counter_Array_Quad);
 }
 
 }
 file_reader.close();
 };
 void fn_convert(int counter_Array_Quad, Quad quadContainer[], Triangle triangleContainer[]){
 int counter_array_tri(0);
 for (int i(0); i<counter_Array_Quad; i++) {
 Quad quad1 = quadContainer[i];
 Triangle tri1= {quadContainer[i].point0, quadContainer[i].point1, quadContainer[i].point2};
 Triangle tri2 = {quadContainer[i].point1, quadContainer[i].point2, quadContainer[i].point3};
 triangleContainer[counter_array_tri]= tri1;
 counter_array_tri+=2;
 triangleContainer[--counter_array_tri]= tri2;
 }
 
 }
 void fn_writer(string output_file_name, int counter_Array_Quad, Triangle triangleContainer[]){
 fstream file_writer;
 file_writer.open(output_file_name, ios::app);
 file_writer << "Triangle" << endl;
 for (int i(0); i< counter_Array_Quad*2 ; i++) {
 file_writer << triangleContainer[i].point0[0] << " " << triangleContainer[i].point0[1] << " " << triangleContainer[i].point0[2] << endl;
 file_writer << triangleContainer[i].point1[0] << " " << triangleContainer[i].point1[1] << " " << triangleContainer[i].point1[2] << endl;
 file_writer << triangleContainer[i].point2[0] << " " << triangleContainer[i].point2[1] << " " << triangleContainer[i].point2[2] << endl;
 }
 file_writer.close();
 }
 
 int main(int argc, const char * argv[]) {
 Quad quadContainer[100] ;
 Triangle triangleContainer[100];
 string input_file_name("Quad.txt");
 string output_file_name("Triangle.txt");
 int counter_Quad(0);
 int counter_Array_Quad(0);
 fn_reader(input_file_name, quadContainer, counter_Quad, counter_Array_Quad);
 fn_convert(counter_Array_Quad, quadContainer, triangleContainer);
 fn_writer(output_file_name, counter_Array_Quad, triangleContainer);
 
 return 0;
 }
 */
