function ex3()
    [num,snum]=getnum();
    zero_flag=0;
    if (num<0) %negative number
        [zero_flag]=checkflag(zero_flag);
        fprintf('negative');
        num=-num;
    end
    if (num==0)
        [zero_flag]=checkflag(zero_flag);
        fprintf("zero");
        return;
    end
    printnum(num,zero_flag,snum);
end
function [num,snum]=getnum()
    snum=input('PLEASE INPUT A NUM x (abs(x)<=999,999,999 and allow decimal) : ','s');
    [num,check]=str2num(snum);
    if (check==0 || abs(num)>999999999)
        disp('ERROR: NOT A NUM or ABS TOO LARGE');
        num=getnum();%Recursion
    end
end
function printnum(x,zero_flag,snum)
    if (x<1) 
        [zero_flag]=checkflag(zero_flag);
        fprintf('zero dot');
        print_digit(snum,zero_flag);
        return;
    end
    high_flag=true;% flag whether "and" is needed
    million_num=fix(x/1000000);
    if (million_num>0)
        [zero_flag,high_flag]=hun_print(million_num,zero_flag,high_flag);
        fprintf(' million');
    end
    thousand_num=fix(mod(fix(x/1000),1000));
    if (thousand_num>0)
        [zero_flag,high_flag]=hun_print(thousand_num,zero_flag,high_flag);
        fprintf(' thousand');
    end
    lowest_num=fix(mod(x,1000));
    if (lowest_num>0)
        [zero_flag,high_flag]=hun_print(lowest_num,zero_flag,high_flag);
    end
    if (x-fix(x)~=0) % decimal part
        fprintf(' dot');
        print_digit(snum,zero_flag);
    end
end
function [zero_flag]=checkflag(zero_flag)% check whether there are a space
    if zero_flag==1 
        fprintf(' ');
    end
    zero_flag=1;
end
function [zero_flag,high_flag]=hun_print(x,zero_flag,high_flag)   
    ONE=["one","two","three","four","five","six","seven","eight","nine","ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen"];
    TEN=["ten","twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety"];
    if x>=100;
        [zero_flag]=print_09(num2str(fix(x/100)), zero_flag);
        fprintf(' hundred');
    end
    
    % check and
    if (mod(x,100)~=0 && high_flag==false && x<100)
        fprintf(' and');
    end
    if (mod(x,100)~=0 && x>=100 )
        fprintf(' and');
    end
    
    % check x00-x99
    high_flag=false;
    if (mod(x,100)~=0)
        [zero_flag]=checkflag(zero_flag);
        if mod(x,100)<=19
            fprintf(ONE(mod(x,100)));
        end
        if mod(x,100)>=20
            fprintf(TEN(fix(mod(x,100)/10)));
            fprintf(' ');
            if mod(x,10)>0
                fprintf(ONE(mod(x,10)));
            end
        end
    end   
end
function print_digit(snum,zero_flag)
    l=length(snum);
    for i=1:l
        %check decimal part
        if snum(i)=='.'
            break;
        end
    end
    for j=i+1:l
        [zero_flag]=print_09(snum(j),zero_flag);
    end
end
function [zero_flag]=print_09(x,zero_flag)
    % print decimal part
    [zero_flag]=checkflag(zero_flag);
    switch x
            case '0'
                fprintf('zero');
            case '1'
                fprintf('one');
            case '2'
                fprintf('two');
            case '3'
                fprintf('three');
            case '4'
                fprintf('four');
            case '5'
                fprintf('five');
            case '6'
                fprintf('six');
            case '7'
                fprintf('seven');
            case '8'
                fprintf('eight');
            case '9'
                fprintf('nine');
        end
end