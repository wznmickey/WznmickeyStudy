function ex1()
    while true    
        year=input('Please input one year:','s');
        l=strlength(year);
        flag=true;
        for i=1:l
            if year(i)<'0' || year(i)>'9'
                flag=false;
            end
        end
        if flag==true 
            check(str2num(year));
            return;
        end
        disp('Not a available datum');
    end
end
function check(x)
    if (mod(x,4)==0) && ((mod (x,400)==0)||mod(x,100)~=0)
        disp('A leap year');
    else
        disp('Not a leap year');
    end
end