function ex6()
    date=input('');
    d=date(1);
    m=date(2);
    y=date(3);
    if m<=2 
        y=y-1;
    end
    m=mod(m+10,12);
    if (m==0) 
        m=12;
    end
    c=fix(y/100);
    y=mod(y,100);
    week=1+mod((d+fix((13*m-1)/5)+y+fix(y/4)+fix(c/4)-2*c),7);
    switch week
        case 1
            disp('Sunday');
        case 2
            disp('Monday');
        case 3
            disp('Tuesday');
        case 4
            disp('Wednesday');
        case 5
            disp('Thursday');
        case 6
            disp('Friday');
        case 7
            disp('Saturday');
    end
end