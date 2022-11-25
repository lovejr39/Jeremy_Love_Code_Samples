%Jeremy Love, Colin Casey, Joshua Noah
%Mahmoud 10 AM
%Portfolio Project

%We, Jeremy Love, Colin Casey, and Joshua Noah, certify that we have 
%   completed this assignment in an honest manner.

%This program will create the ContactTrace function.

%This function will ask the user for an individual's information and then
%   report the other gym users that may have come intact with this
%   individual over the past 2 weeks.

function [name] = ContactTrace()

%get user information
    [name, IDnumber] = GetInfo() ;
    
%get last 14 daays
    [dates] = FormatLast14Dates() ;
    
%check for reservation files for each date
    header = true ;
    for i = 1 : length(dates)
        filename = dates(i) + ".txt" ;
        if(isfile(filename))
            %check for attentance
                [reservations, index] = CheckForReservation(name, IDnumber, filename) ;
                if(index ~= -1 && reservations(index, 3) ~= "Not-Checked-In")
                    if(header)
                        fprintf("\nThe following individuals may have come in contact with %s:", name) ;
                        header = false ;
                    end
                    fprintf("\n\t%s:",dates(i)) ;
                    for k = 1 : length(reservations)
                        %check for own reservation and no-shows
                            if(k ~= index  && reservations(k,3) ~= "Not-Checked-In")
                                fprintf("\n\t\t%s: %s",reservations(k,1), reservations(k,2)) ;
                            end
                    end
                end
        end
    end
    if(header)
        fprintf("\nThere is no potential exposure for %s.\n", name) ;
    end