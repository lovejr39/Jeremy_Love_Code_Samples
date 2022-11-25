%Jeremy Love, Colin Casey, Joshua Noah
%Mahmoud 10 AM
%Portfolio Project

%We, Jeremy Love, Colin Casey, and Joshua Noah, certify that we have 
%   completed this assignment in an honest manner.

%This program will create the FormatLast14Dates function.

%This function will determine the last fourteen dates and return them as a
%   matrix to the function call.

function [dates] = FormatLast14Dates()

%get current date information
    today = datestr(datetime('today'), 'yyyymmdd') ;
    year = str2num(string(extractBetween(today, 1, 4))) ;
    month = str2num(string(extractBetween(today, 5, 6))) ;
    day = str2num(string(extractBetween(today, 7, 8))) ;

%backtrack 14 days
    day = day - 14 ;
    if(day < 1)
        month = month - 1 ;
        if(month < 1)
            year - 1 ;
        end
        [monthDays] = FindMonthDays(year, month) ;
        day = monthDays - abs(day) ;
    end
    
%format 14 dates
    dates = strings(14) ;
    for i = 0: 1 : 14
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