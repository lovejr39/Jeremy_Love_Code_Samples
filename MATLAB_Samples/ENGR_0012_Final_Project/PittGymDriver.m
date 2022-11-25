%Jeremy Love, Colin Casey, Joshua Noah
%Mahmoud 10 AM
%Portfolio Project

%We, Jeremy Love, Colin Casey, and Joshua Noah, certify that we have 
%   completed this assignment in an honest manner.

%This program will create an application that can be used to:
%   1) Make gym reservations
%   2) Check into the gym once a reservation has been made
%   3) Store and save attendance data for contact tracing purposes
%   4) Display attendance data for a given time frame

%This program will act as the main driver for the application, asking the 
%   user which app feature they would like to use, and calling the 
%   appropriate function. The program will repeat until the user exits.

%clear previous data
    clear ; 
    clc ;
    
%display welcome message
    disp('Welcome to the Pitt Gym!') ;

%declare variables
    choice = 0 ;
    nameGiven = false ;
    
%loop until exit
    while(choice ~= 5)
        
        %ask for and validate app selection
            fprintf('\nWhat would you like to do?\n') ;
            disp('   1) Make a Reservation') ;
            disp('   2) Check In') ;
            disp('   3) Contact Trace Gym Users') ;
            disp('   4) Display Attendence Data') ;
            disp('   5) Exit') ;
            choice = Validate(input(''), 5) ;
           
        %determine choice and validate
            switch choice
                case 1 %make reservation
                    nameGiven = true ;
                    name = MakeReservation() ;
                case 2 %check in
                    nameGiven = true ;
                    name = CheckIn() ;
                case 3 %contact trace
                    nameGiven = true ;
                    name = ContactTrace() ;
                case 4 %display data
                    DisplayAttendance() ;
                case 5 %display exit message
                    if(nameGiven)
                        fprintf('\nThanks for using the Pitt Gym Application %s!\n\n', name) ;
                    else
                        fprintf('\nThanks for using the Pitt Gym Application!\n\n') ;
                    end
            end
    end