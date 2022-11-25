%Jeremy Love, Colin Casey, Joshua Noah
%Mahmoud 10 AM
%Portfolio Project

%We, Jeremy Love, Colin Casey, and Joshua Noah, certify that we have 
%   completed this assignment in an honest manner.

%This program will create the FormatNext5Dates function.

%This function will determine the next five dates and return them as a
%   matrix to the function call.

function [dates] = FormatNext5Dates()

%get current date information
    today = datestr(datetime('today'), 'yyyymmdd') ;
    year = str2num(string(extractBetween(today, 1, 4))) ;
    month = str2num(string(extractBetween(today, 5, 6))) ;
    day = str2num(string(extractBetween(today, 7, 8))) ;
    
%determine days in the month
    [monthDays] = FindMonthDays(year, month) ;
    
%format data information for next 5 days
    dates = strings(5) ;
    for i = 0: 1 : 5
        if(day > monthDays)
            if(month == 12)
                month = 1 ;
            else
                month = month + 1 ;
            end
            days = 1 - i ;
        end
        dates(i + 1) = datestr(datetime(year, month, day + i), 'mmmm_dd_yyyy') ;
    end
    dates = dates(:,1) ;