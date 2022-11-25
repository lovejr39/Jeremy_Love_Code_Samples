%Jeremy Love, Colin Casey, Joshua Noah
%Mahmoud 10 AM
%Portfolio Project

%We, Jeremy Love, Colin Casey, and Joshua Noah, certify that we have 
%   completed this assignment in an honest manner.

%This program will create the CheckForReservation function.

%This function will read in a given file and check and see if a reservation
%   exists in that file. It will return the index of the reservation, -1 if
%   there is no reservation.

function [reservations, index] = CheckForReservation(name, IDnumber, filename)

%open filestream and read data
    fileID = fopen(filename) ;            
    data = fscanf(fileID, '%s') ;
    commas = strfind(data,",") ;

%format data
    reservations = strings(length(commas) / 3, 3) ;
    i = 0 ;
    for k = 1 : length(commas) / 3
        for m = 1 : 3
            if(i == 0)
                reservations(k, m) = string(extractBetween(data,1 , commas(i + 1) - 1)) ;
            else
                reservations(k, m) = string(extractBetween(data, commas(i) + 1, commas(i + 1) - 1)) ;
            end
            i = i + 1 ;
        end
        k = k + 1 ;
    end
    fclose(fileID) ;

%search for valid reservation
    index = -1 ;
    for i = 1 : length(reservations) - 1 ;
        if(reservations(i,1) == name && reservations(i,2) == string(IDnumber))
            index = i ;
            break ;
        end
    end