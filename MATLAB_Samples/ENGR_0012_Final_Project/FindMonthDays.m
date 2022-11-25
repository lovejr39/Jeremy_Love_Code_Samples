%Jeremy Love, Colin Casey, Joshua Noah
%Mahmoud 10 AM
%Portfolio Project

%We, Jeremy Love, Colin Casey, and Joshua Noah, certify that we have 
%   completed this assignment in an honest manner.

%This program will create the FindMonthDays function.

%This function will determine the number of days in a parameter month.

function [monthDays] = FindMonthDays(year, month)

%determine days in the month
    if((month <= 7 && rem(month, 2) == 1) || (month >= 8 && rem(month, 2) == 0)) %31 days
        monthDays = 31 ;
    elseif(month == 2) %feburary
        if(rem(year, 4) == 0) %leap year
            monthDays = 29 ;
        else %no lear year
            monthDays = 28 ;
        end
    else %30 days
        monthDays = 30 ;
    end