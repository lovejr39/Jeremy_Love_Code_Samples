%Jeremy Love, Colin Casey, Joshua Noah
%Mahmoud 10 AM
%Portfolio Project

%We, Jeremy Love, Colin Casey, and Joshua Noah, certify that we have 
%   completed this assignment in an honest manner.

%This program will create the DisplayAttendance function.

%This function will display the number of people that visited the gym in
%   the last fourteen days via a bar graph.

function [] = DisplayAttendance()

%get the laste fourteen dates
    [dates] = FormatLast14Dates() ;
    
%count attendance for each day
    attendance = zeros(14,1) ;
    for i = 1 : length(dates)
        filename = dates(i) + ".txt" ;
        if(isfile(filename))
            %use CheckForReservation function to read in all reservations
                [reservations, index] = CheckForReservation("", "", filename) ;
                attendance(i) = length(reservations) ;
        end
    end

%replace underscors in dates array
    for i = 1 : length(dates)
        dates(i) = strrep(dates(i),"_"," ") ;
    end
    
%display figure
    figure ;

%display image
    subplot(1,2,1) ;
    image = imread("CampusRecreation.jpg") ;
    imshow(image) ;
    
%display bar graph
    subplot(1,2,2) ;
    X = categorical(dates) ;
    X = reordercats(X, dates) ;
    Y = attendance ;
    bar(X,Y) ;
    title("Daily Gym Attendance - Last 14 Days") ;
    xlabel("Date") ;
    ylabel("People") ;
    
    