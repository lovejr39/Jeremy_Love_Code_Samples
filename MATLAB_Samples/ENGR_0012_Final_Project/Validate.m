%Jeremy Love, Colin Casey, Joshua Noah
%Mahmoud 10 AM
%Portfolio Project

%We, Jeremy Love, Colin Casey, and Joshua Noah, certify that we have 
%   completed this assignment in an honest manner.

%This program will create the validate function.

%This function will validate a number range of 1 to a parameter maximum.
%   This will typically be used to validate a menu selection.

function [num] = Validate (num, maxVal)

%loop until valid input
    while(num < 1 || num > maxVal)
        num = input('ERROR: Enter a value between 1 and ' + string(maxVal) + ': ') ;
    end