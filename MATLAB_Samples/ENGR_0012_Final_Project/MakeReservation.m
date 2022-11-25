%Jeremy Love, Colin Casey, Joshua Noah
%Mahmoud 10 AM
%Portfolio Project

%We, Jeremy Love, Colin Casey, and Joshua Noah, certify that we have 
%   completed this assignment in an honest manner.

%This program will create the MakeReservation function.

%This function will ask the user for thier information and the date they
%   would like to make a reservation for. It will then read the data in the
%   reservation file for the given date, alphabatize it, and write it back
%   to the file.

function [name] = MakeReservation()

%get user information
    [name, IDnumber] = GetInfo() ;
    
%ask for and validate which date for reservation
    dates = FormatNext5Dates() ;
    fprintf('\nWhich day would you like to make a reservation for?\n') ;
    for i = 1 : 1 : 5
        fprintf('   %d) %s\n', i, dates(i)) ;       
    end
    choice = Validate(input(''),5) ;

%check if there is a current reservation file for the selected date
    filename = dates(choice) + '.txt' ;
    if(isfile(filename)) %file exists
        %read in file
            fileID = fopen(filename) ;            
            data = fscanf(fileID, '%s') ;
            commas = strfind(data,",") ;

        %format data
            reservations = strings(length(commas) / 3 + 1, 3) ;
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
            
        %add reservation
            reservations(length(commas) / 3 + 1, 1) = name ;
            reservations(length(commas) / 3 + 1, 2) = string(IDnumber) ;
            reservations(length(commas) / 3 + 1, 3) = "Not-Checked-In" ;

        %alphabetize by name
            fullReservations = strings(length(commas) / 3 + 1) ;
            for i = 1 : length(commas) / 3 + 1
                for k = 1 : 3
                    fullReservations(i) = fullReservations(i) + reservations(i,k) + "," ;
                end
            end
            fullReservations = sort(fullReservations) ;

        %write back to file
            fileID = fopen(filename, 'w') ;
            for i = 1 : length(fullReservations)
                fprintf(fileID, '%s\r\n', fullReservations(i)) ;
            end
            fclose(fileID) ;
    else
        %write to file
            fileID = fopen(filename, 'w') ;
            fprintf(fileID, '%s,%s,%s,\r\n', name, string(IDnumber), "Not-Checked-In") ;
            fclose(fileID) ;
    end
    
%confirm reservation
    fprintf('\n%s, your reservation for %s has been confirmed.\n',name, dates(choice)) ;