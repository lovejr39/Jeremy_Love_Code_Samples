%Jeremy Love, Colin Casey, Joshua Noah
%Mahmoud 10 AM
%Portfolio Project

%We, Jeremy Love, Colin Casey, and Joshua Noah, certify that we have 
%   completed this assignment in an honest manner.

%This program will create the GetInfo function.

%This function will ask the user for thier name and ID number to be used to
%   search for and set reservation data.

function [name, IDnumber] = GetInfo()

%ask user for name
    fprintf("\n") ;
    name = input('Please enter your name: ', 's') ;
    name = erase(name, " ") ;
    
%ask user for student ID
    IDnumber = input('Please enter your ID number: ') ;
    
%validate ID number length
    while(strlength(num2str(IDnumber)) ~= 7)
        IDnumber = input('ERROR: ID numbers are 7 digits: ') ;
    end