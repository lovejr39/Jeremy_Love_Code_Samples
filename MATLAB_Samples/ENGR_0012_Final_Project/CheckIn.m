%Jeremy Love, Colin Casey, Joshua Noah
%Mahmoud 10 AM
%Portfolio Project

%We, Jeremy Love, Colin Casey, and Joshua Noah, certify that we have 
%   completed this assignment in an honest manner.

%This program will create the CheckIn function.

%This function will ask the user for thier information and scan today's
%   reservation file for the information. It will check them in if they
%   have a valid reservation.

function [name] = CheckIn()

%get user information
    [name, IDnumber] = GetInfo() ;
    
%get today's date information
    dates = FormatNext5Dates() ;
    filename = dates(1) + ".txt" ;
    [reservations, index] = CheckForReservation(name, IDnumber, filename) ;
       
%check in if valid
    if(index ~= -1)
        %check to see if already checked in
            if(reservations(index, 3) == "Checked-In")
                fprintf("\nYou are already checked in.\n") ;
            else
                reservations(index, 3) = "Checked-In" ;
            end
            
        %write back to file
            fileID = fopen(filename, 'w') ;
            for i = 1 : length(reservations)
                for k = 1 : 3
                    fprintf(fileID, '%s,', reservations(i,k)) ;
                end
                fprintf(fileID, '\r\n') ;
            end
            fclose(fileID) ;
    else
        fprintf("\nYou do not have a valid regristration for today.\n") ;
    end